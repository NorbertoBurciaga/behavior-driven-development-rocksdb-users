#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>
#include "rocksdb/db.h"

using cucumber::ScenarioScope;
using namespace std;

typedef int id_type;
typedef string field_type;
typedef string value_type;

class UserFieldValue {
	typedef map<pair<id_type, field_type>, value_type> user_field_value_type;
	user_field_value_type userFieldValue;
public:
	string databasename;
	rocksdb::DB* db;

	void addUserFieldValue(const id_type id, const field_type field, const value_type value) {
		userFieldValue[make_pair(id, field)] = value;
	}

	void listUserFieldValues() {
		id_type previous_id = 0;

		user_field_value_type::iterator it = userFieldValue.begin();
		while(it != userFieldValue.end()) {
			pair<id_type, field_type> key = it->first;
			value_type value = it->second;
//			cout << "| " << key.first << "	| " << key.second << "	| " << value << "	|" << endl;
			if (key.first != previous_id) {
				cout << endl << "| ";
				previous_id = key.first;
			}
			cout << value << "	|";
			it++;
		}
	}
};



GIVEN("^\"([^\"]*)\" as the name of the database$") {
	ScenarioScope<UserFieldValue> context;

	REGEX_PARAM(string, databasename);
	context->databasename = databasename;

	cout << databasename << endl;
}


WHEN("^the application starts$") {
	ScenarioScope<UserFieldValue> context;

	//open the database
	rocksdb::Options options;
	options.create_if_missing = true;
	rocksdb::Status status = rocksdb::DB::Open(options, context->databasename, &(context->db));

	if (!status.ok()) std::cerr << status.ToString() << std::endl;
	assert(status.ok());
}


THEN("^it should construct the key using id/field and insert the key/value pair into the \"([^\"]*)\" table$") {
	ScenarioScope<UserFieldValue> context;

	REGEX_PARAM(string, tablename);

	TABLE_PARAM(usersParam);

	cout << "Table: " << tablename  << endl;

	const table_hashes_type & users = usersParam.hashes();
	for (table_hashes_type::const_iterator ait = users.begin(); ait != users.end(); ++ait) {
		string idString(ait->at("Id"));
		const id_type id = ::cucumber::internal::fromString<id_type>(idString);

		field_type field(ait->at("Field"));

		value_type value(ait->at("Value"));

		context->addUserFieldValue(id, field, value);
	}

	context->listUserFieldValues();
}

