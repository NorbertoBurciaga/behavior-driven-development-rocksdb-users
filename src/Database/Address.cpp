/*
 * Address.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: norberto
 */

#include "Address.h"

Address::Address(TransactionDB* db, string tablename) {
	this->db = db;
	this->id = 0;
	this->userId = 0;
	this->tablename = tablename;
}

const string& Address::getAddress() const {
	return address;
}

void Address::setAddress(const string& address) {
	this->address = address;
}

const string& Address::getCity() const {
	return city;
}

void Address::setCity(const string& city) {
	this->city = city;
}

const string& Address::getCountry() const {
	return country;
}

void Address::setCountry(const string& country) {
	this->country = country;
}

int Address::getId() const {
	return id;
}

void Address::setId(int id) {
	this->id = id;
}

const string& Address::getState() const {
	return state;
}

void Address::setState(const string& state) {
	this->state = state;
}

int Address::getUserId() const {
	return userId;
}

void Address::setUserId(int userId) {
	this->userId = userId;
}

Address::~Address() {
	delete txn;
}

string Address::getKey(string field) {
	return this->tablename + ":" + to_string(this->id) + ":" + to_string(this->userId) + ":" + field;
}

rocksdb::Status Address::put() {
	this->txn = this->db->BeginTransaction(rocksdb::WriteOptions());
		this->txn->Put(this->getKey("address"), this->address);
		this->txn->Put(this->getKey("city"), this->city);
		this->txn->Put(this->getKey("state"), this->state);
		this->txn->Put(this->getKey("country"), this->country);
	rocksdb::Status s = txn->Commit();
	return(s);
}
