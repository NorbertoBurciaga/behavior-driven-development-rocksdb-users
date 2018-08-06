/*
 * User.cpp
 *
 *  Created on: Jul 30, 2018
 *      Author: Norberto Burciaga
 */

#include "User.h"

using namespace std;

User::User(TransactionDB* db, string tablename) {
	this->db = db;
	this->id = 0;
	this->year = 0;
	this->tablename = tablename;
}

int User::getId() const {
	return id;
}

void User::setId(int id) {
	this->id = id;
}

const string& User::getEmail() const {
	return email;
}

void User::setEmail(const string& email) {
	this->email = email;
}

const string& User::getFirstname() const {
	return firstname;
}

void User::setFirstname(const string& firstname) {
	this->firstname = firstname;
}

const string& User::getLastname() const {
	return lastname;
}

void User::setLastname(const string& lastname) {
	this->lastname = lastname;
}

int User::getYear() const {
	return year;
}

void User::setYear(int year) {
	this->year = year;
}

User::~User() {
	delete txn;
}

const string& User::getTablename() const {
	return tablename;
}

void User::setTablename(const string& tablename) {
	this->tablename = tablename;
}

string User::getKey(string field) {
	return this->tablename + ":" + std::to_string(this->id) + ":" + field;
}

rocksdb::Status User::put() {
	this->txn = this->db->BeginTransaction(rocksdb::WriteOptions());
		this->txn->Put(this->getKey("email"), this->email);
		this->txn->Put(this->getKey("lastname"), this->lastname);
		this->txn->Put(this->getKey("firstname"), this->firstname);
		this->txn->Put(this->getKey("year"), std::to_string(this->year));
	rocksdb::Status s = txn->Commit();
	return(s);
}
