/*
 * Table.h
 *
 *  Created on: Jul 30, 2018
 *      Author: Norberto Burciaga
 */

#ifndef SRC_DATABASE_TABLE_H_
#define SRC_DATABASE_TABLE_H_

#include <iostream>
#include "rocksdb/db.h"
#include "rocksdb/utilities/transaction.h"
#include "rocksdb/utilities/transaction_db.h"

using namespace std;
using namespace rocksdb;

class Table {
protected:
	TransactionDB* db;
	Transaction* txn;
	string tablename;
public:
	Table();
	virtual ~Table();
	virtual string getKey(string field);
};

#endif /* SRC_DATABASE_TABLE_H_ */
