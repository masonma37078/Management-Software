#include "Log.h"

/*
 * Log.cpp
 *
 * This file implements all interfaces for inserting log file.
 *
 * @author: Hang Yuan
 * Revised: 3/26/20
 *
 */

using namespace System;

/*
 * Initialize
 * This method will create the database interface.
 * @param None
 * @return None
 * @exception SQLiteException
 */
void WeAlumni::Log::Initialize() {
    try {
        _database = gcnew Database(Database::DatabaseType::Data);
    }
    catch (SQLiteException^ exception) {
        throw exception;
    }
}

/*
 * AddLog
 * This method will trigger a InsertData method to add new Log into the Log table
 * @param None
 * @return bool true if insertion is successful
 *              false if fail
 */
bool WeAlumni::Log::AddLog(String^ stfId, String^ action) {
    String^ command = "INSERT INTO Log VALUES(" + _database->GetNextId(Database::DatabaseTable::Log) + ", " + 
                                                  _database->GetSystemTime() + ", " +
                                                  stfId + ", " +
                                                  action + ");";
    if (-1 == _database->InsertData(command)) {
        return false;
    }
    return true;
}