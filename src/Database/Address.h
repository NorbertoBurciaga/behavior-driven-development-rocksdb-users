/*
 * Address.h
 *
 *  Created on: Aug 3, 2018
 *      Author: Norberto Burciaga
 */

#ifndef SRC_DATABASE_ADDRESS_H_
#define SRC_DATABASE_ADDRESS_H_

#include "Table.h"

class Address: public Table {
	int id;
	int userId;
	string address;
	string city;
	string state;
	string country;
public:
	Address(TransactionDB* db, string tablename);
	virtual ~Address();
	const string& getAddress() const;
	void setAddress(const string& address);
	const string& getCity() const;
	void setCity(const string& city);
	const string& getCountry() const;
	void setCountry(const string& country);
	int getId() const;
	void setId(int id);
	const string& getState() const;
	void setState(const string& state);
	int getUserId() const;
	void setUserId(int userId);
	string getKey(string field);
	rocksdb::Status put();
};

#endif /* SRC_DATABASE_ADDRESS_H_ */
