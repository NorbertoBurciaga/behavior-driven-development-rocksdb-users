#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>
#include "rocksdb/db.h"
#include "User.h"
#include "Address.h"

using cucumber::ScenarioScope;
using namespace std;

class ApplicationContext {
public:
	string databasename;
	TransactionDB* db;
	User *user;
	Address *address;
	string currentTable;
};

GIVEN("^\"([^\"]*)\" as the name of the database$") {
	ScenarioScope<ApplicationContext> context;

	cout << "----------> GIVEN: <-------------------------------" << endl;

	REGEX_PARAM(string, databasename);
	context->databasename = databasename;

}


WHEN("^\"([^\"]*)\" are required to be stored into the database$") {
	ScenarioScope<ApplicationContext> context;

	cout << "----------> WHEN: <-------------------------------" << endl;

	REGEX_PARAM(string, tablename);

	context->currentTable = tablename;

//open the database
	TransactionDBOptions txn_db_options;
	rocksdb::Options options;
	options.create_if_missing = true;
	rocksdb::Status status = TransactionDB::Open(options, txn_db_options, context->databasename, &(context->db));
	context->user = new User(context->db,"users");
	context->address = new Address(context->db,"addresses");
	if (!status.ok()) std::cerr << status.ToString() << std::endl;
	assert(status.ok());

}


THEN("^should insert the following users into the database$") {
	ScenarioScope<ApplicationContext> context;
	string key;
	rocksdb::Status s;

	cout << "----------> THEN USERS: <-------------------------------" << endl;

	TABLE_PARAM(usersParam);

	const table_hashes_type & users = usersParam.hashes();
	for (table_hashes_type::const_iterator ait = users.begin(); ait != users.end(); ++ait) {

		//insert User
		context->user->setId(atoi(ait->at("Id").c_str()));
		context->user->setEmail(ait->at("Email"));
		context->user->setLastname(ait->at("Lastname"));
		context->user->setFirstname(ait->at("Firstname"));
		context->user->setYear(atoi(ait->at("Year").c_str()));
		s = context->user->put();
		assert(s.ok());
	}

	//iterate the database
	rocksdb::Iterator* it = context->db->NewIterator(rocksdb::ReadOptions());
	for (it->SeekToFirst(); it->Valid(); it->Next()) {
		cout << "----------> From Database: " << it->key().ToString() << ": " << it->value().ToString() << endl;
	}
	delete it;

	delete context->db;
}


THEN("^should insert the following addresses into the database$") {
	ScenarioScope<ApplicationContext> context;
  string key;
  rocksdb::Status s;

	cout << "----------> THEN ADDRESSES: <-------------------------------" << endl;

  TABLE_PARAM(addressesParam);

  const table_hashes_type & addresses = addressesParam.hashes();
  for (table_hashes_type::const_iterator ait = addresses.begin(); ait != addresses.end(); ++ait) {

	//insert Address
	context->address->setId(atoi(ait->at("Id").c_str()));
	context->address->setUserId(atoi(ait->at("UserId").c_str()));
	context->address->setAddress(ait->at("Address"));
	context->address->setCity(ait->at("City"));
	context->address->setState(ait->at("State"));
	context->address->setCountry(ait->at("Country"));
	s = context->address->put();
	assert(s.ok());
/*    //insert Address
    key = context->currentTable + ":" + ait->at("Id") + ":" + ait->at("UserId") + ":Address";
    s = context->db->Put(rocksdb::WriteOptions(), key, ait->at("Address"));
    assert(s.ok());

    //insert City
    key = context->currentTable + ":" + ait->at("Id") + ":" + ait->at("UserId") + ":City";
    s = context->db->Put(rocksdb::WriteOptions(), key, ait->at("City"));
    assert(s.ok());

    //insert State
    key = context->currentTable + ":" + ait->at("Id") + ":" + ait->at("UserId") + ":State";
    s = context->db->Put(rocksdb::WriteOptions(), key, ait->at("State"));
    assert(s.ok());

    //insert Country
    key = context->currentTable + ":" + ait->at("Id") + ":" + ait->at("UserId") + ":Country";
    s = context->db->Put(rocksdb::WriteOptions(), key, ait->at("Country"));
    assert(s.ok());*/
  }

  //iterate the database
  rocksdb::Iterator* it = context->db->NewIterator(rocksdb::ReadOptions());
  for (it->SeekToFirst(); it->Valid(); it->Next()) {
    cout << "----------> From Database: " << it->key().ToString() << ": " << it->value().ToString() << endl;
  }
  delete it;

	delete context->db;
}

