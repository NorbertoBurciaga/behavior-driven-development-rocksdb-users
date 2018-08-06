/*
 * User.h
 *
 *  Created on: Jul 30, 2018
 *      Author: Norberto Burciaga
 */

#ifndef SRC_DATABASE_USER_H_
#define SRC_DATABASE_USER_H_

#include "Table.h"

class User: public Table {
	int id;
	string email;
	string lastname;
	string firstname;
	int year;
public:
	User(TransactionDB* db, string tablename);
	virtual ~User();
	int getId() const;
	void setId(int id);
	const string& getEmail() const;
	void setEmail(const string& email);
	const string& getFirstname() const;
	void setFirstname(const string& firstname);
	const string& getLastname() const;
	void setLastname(const string& lastname);
	int getYear() const;
	void setYear(int year);
	const string& getTablename() const;
	void setTablename(const string& tablename);
	string getKey(string field);
	rocksdb::Status put();
};

#endif /* SRC_DATABASE_USER_H_ */
