#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>
#include "rocksdb/db.h"

using cucumber::ScenarioScope;
using namespace std;

class ApplicationContext {
public:
	string databasename;
	rocksdb::DB* db;
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
  rocksdb::Options options;
  options.create_if_missing = true;
  rocksdb::Status status = rocksdb::DB::Open(options, context->databasename, &(context->db));

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

		//insert Email
		key = context->currentTable + ":" + ait->at("Id") + ":Email";
		s = context->db->Put(rocksdb::WriteOptions(), key, ait->at("Email"));
		assert(s.ok());

		//insert Last name
		key = context->currentTable + ":" + ait->at("Id") + ":Lastname";
		s = context->db->Put(rocksdb::WriteOptions(), key, ait->at("Lastname"));
		assert(s.ok());

		//insert First name
		key = context->currentTable + ":" + ait->at("Id") + ":Firstname";
		s = context->db->Put(rocksdb::WriteOptions(), key, ait->at("Firstname"));
		assert(s.ok());

		//insert Year
		key = context->currentTable + ":" + ait->at("Id") + ":Year";
		s = context->db->Put(rocksdb::WriteOptions(), key, ait->at("Year"));
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

