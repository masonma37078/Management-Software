#include "Database.h"

/*
 * Database.cpp
 *
 * This file implements all Database interfaces.
 *
 * @author: Hang Yuan
 * Revised: 3/23/20
 *
 */

/*
 * GetDatabasePassword
 * This method will offer the corresponding password based on DatabaseType
 * @param None
 * @return String^ the password of target database
 */
System::String^ WeAlumni::Database::GetDatabasePassword() {
    if (_databaseType == DatabaseType::Admin) {
        return DB_ADMIN_PASSWORD;
    }
    else if (_databaseType == DatabaseType::Data) {
        return DB_DATA_PASSWORD;
    }
    else {
        return DB_TREASURY_PASSWORD;
    }
}

/*
 * GetDatabaseName
 * This method will offer the name of database file by DatabaseType
 * @param None
 * @return String^ the name of current database
 */
System::String^ WeAlumni::Database::GetDatabaseName() {
    if (_databaseType == DatabaseType::Admin) {
        return DB_ADMIN_NAME;
    }
    else if (_databaseType == DatabaseType::Data) {
        return DB_DATA_NAME;
    }
    else {
        return DB_TREASURY_NAME;
    }
}

/*
 * CheckDatabaseFileExistence
 * This method will check if the database file exists in the destinated location
 * @param None
 * @return bool true if the file exists
 *              false if not
 */
bool WeAlumni::Database::CheckDatabaseFileExistence() {
    return System::IO::File::Exists(GetDatabaseName());
}

/*
 * GetConnectionString
 * This method will offer ConnectionString for DatabaseConnection to open a database file.
 * @param None
 * @return String^ the ConnectionString
 */
System::String^ WeAlumni::Database::GetConnectionString() {
    String^ connectionString = "Data Source = " + GetDatabaseName() + "; " +
                               "Password = " + GetDatabasePassword() + "; " +
                               "Read Only = " + _readOnly;
    return connectionString;
}

/*
 * Initialize
 * This method will CheckDatabaseFileExistence first. If it goes well, it will open the database connection.
 * @param None
 * @return None
 * @exception customized exception or SQLiteException
 */
void WeAlumni::Database::Initialize() {
    if (!CheckDatabaseFileExistence()) {
        throw gcnew Exception("此数据库不存在或不在指定位置：" + GetDatabaseName());
    }

    try {
        database = gcnew SQLiteConnection(GetConnectionString());
        database->Open();
        command = database->CreateCommand();
    }
    catch (SQLiteException^ exception) {
        throw exception;
    }
}

/*
 * GetTableName
 * This method will offer the corrsponding table name by the given DatabaseTable
 * @param DatabaseTable type of the database table
 * @return String^ table name
 */
System::String^ WeAlumni::Database::GetTableName(DatabaseTable tableType) {
    String^ tableName;
    switch (tableType) {
    case DatabaseTable::Member:
        tableName = "Member"; break;
    case DatabaseTable::Staff:
        tableName = "Staff"; break;
    case DatabaseTable::Record:
        tableName = "Record"; break;
    case DatabaseTable::OPT:
        tableName = "OPT"; break;
    case DatabaseTable::Log:
        tableName = "Log"; break;
    case DatabaseTable::Item:
        tableName = "Item"; break;
    case DatabaseTable::Orders:
        tableName = "Orders"; break;
    case DatabaseTable::Treasury:
        tableName = "Treasury"; break;
    }
    return tableName;
}

/*
 * CreateDatabaseFile
 * This method will create a new Database file, with password set in.
 * @param None
 * @return bool true if successfully create the file
 *              false if not
 */
bool WeAlumni::Database::CreateDatabaseFile() {
    bool success = false;
    try {
        String^ databaseName = GetDatabaseName();
        SQLiteConnection::CreateFile(databaseName);
        database = gcnew SQLiteConnection("Data Source = " + databaseName);
        database->SetPassword(GetDatabasePassword());
        database->Open();
        command = database->CreateCommand();
        if (_databaseType == DatabaseType::Admin) {
            command->CommandText = CREATE_ADMIN_TBL;
            command->ExecuteNonQuery();
        }
        else if (_databaseType == DatabaseType::Data) {
            command->CommandText = CREATE_MEMBER_TBL + 
                                   CREATE_STAFF_TBL +
                                   CREATE_RECORD_TBL +
                                   CREATE_OPT_TBL + 
                                   CREATE_LOG_TBL + 
                                   CREATE_ITEM_TBL + 
                                   CREATE_ORDERS_TBL;
            command->ExecuteNonQuery();
        }
        else {
            command->CommandText = CREATE_TREASURY_TBL;
            command->ExecuteNonQuery();
        }
        success = true;
    }
    catch (SQLiteException^) {
        // Leave empty
    }
    finally {
        delete database;
    }
    return success;
}

/*
 * GetNextId
 * This method will offer you the next available Id value to be inserted
 * @param DatabaseTable
 * @return int next available Id in the corresponding database table
 */
int WeAlumni::Database::GetNextId(DatabaseTable tableName) {
    String^ command = "SELECT MAX(Id) FROM " + GetTableName(tableName) + ";";
    ReadData(command);
    String^ nextId = dataReader[0]->ToString();
    dataReader->Close();
    if (nextId == "" || nextId == "NULL") {
        return 0;
    }
    return Int32::Parse(nextId) + 1;
}

/*
 * GetSystemTime
 * This method will offer the current time of system
 * @param None
 * @return String^ current system time
 */
System::String^ WeAlumni::Database::GetSystemTime() {
    DateTime^ curTime = gcnew DateTime();
    curTime = curTime->Now;
    return curTime->ToString();
}

/*
 * ReadData
 * This method will try to read the Database as the command given.
 * @param String^ command that will be executed
                  "SELECT [* or COLUMN_NAME] FROM [TABLE_NAME] WHERE [CONDITION(s)];"
                  "SELECT [COLUMN_NAME] AS '[NEW_NAME]' FROM [TABLE_NAME] WHERE [CONDITION(s)];"
 * @return int -1 if catch an exception
 *             # of rows read if the execution is successful
 */
int WeAlumni::Database::ReadData(String^ cmd) {
    if (dataReader && !dataReader->IsClosed) dataReader->Close();
    command->CommandText = cmd;
    int rowRead = -1;
    try {
        dataReader = command->ExecuteReader();
        if (dataReader->Read()) {
            rowRead = dataReader->StepCount;
        }
    }
    catch (SQLiteException^) {
        // Leave empty
    }
    return rowRead;
}

/*
 * ReadDataAdapter
 * This method will try to read the Database as the command given.
 * @param String^ command that will be executed
 *                "SELECT [* or COLUMN_NAME] FROM [TABLE_NAME] WHERE [CONDITION(s)];"
 *                "SELECT [COLUMN_NAME] AS '[NEW_NAME]' FROM [TABLE_NAME] WHERE [CONDITION(s)];"
 * @return int -1 if catch an exception
 *             # of rows read if the execution is successful
 */
int WeAlumni::Database::ReadDataAdapter(String^ cmd) {
    if (dataReader && !dataReader->IsClosed) dataReader->Close();
	command->CommandText = cmd;
    int rowRead = -1;
	try {
		dataAdapter = gcnew SQLiteDataAdapter();
		dataAdapter->SelectCommand = command;
		dataTable = gcnew DataTable();
		dataAdapter->Fill(dataTable);
        rowRead = dataTable->Rows->Count;
	}
	catch (SQLiteException^) {
        // Leave empty
	}
    return rowRead;
}

/*
 * InsertData
 * This method will try to insert data into the Database as the command given.
 * @param String^ command that will be executed
 *                "INSERT INTO [TABLE_NAME] VALUES ([DATA],[DATA],...);"
 *                "INSERT INTO [TABLE_NAME]([COLUMN_NAME], [COLUMN_NAME],...) VALUES ([DATA],[DATA],...);"
 * @return int -1 if catch an exception
 *             # of rows that are successfully inserted 
 */
int WeAlumni::Database::InsertData(String^ cmd) {
    int rowInserted = -1;
    try {
        command->CommandText = cmd;
        rowInserted = command->ExecuteNonQuery();
    }
    catch (SQLiteException^) {
        // Leave empty
    }
    return rowInserted;
}

/*
 * UpdateData
 * This method will try to update data into the Database as the command given.
 * @param String^ command that will be executed
 *                "UPDATE [TABLE_NAME] SET [COLUMN_NAME] = [DATA], [COLUMN_NAME] = [DATA}, ... WHERE [CONDITION];"
 * @return int -1 if catch an exception
 *             # of rows that are successfully updated 
 */
int WeAlumni::Database::UpdateData(String^ cmd) {
    int rowUpdated = -1;
    try {
        command->CommandText = cmd;
        rowUpdated = command->ExecuteNonQuery();
    }
    catch (SQLiteException^) {
        // Leave empty
    }
    return rowUpdated;
}

/*
 * DeleteDataData
 * This method will try to remove data from the Database as the command given.
 * @param String^ command that will be executed
 *                "DELETE FROM [TABLE_NAME] WHERE [CONDITION];"
 * @return int -1 if catch an exception
 *             # of rows that are successfully deleted
 */
int WeAlumni::Database::DeleteData(String^ cmd) {
    int rowDeleted = -1;
    try {
        command->CommandText = cmd;
        rowDeleted = command->ExecuteNonQuery();
    }
    catch (SQLiteException^) {
        // Leave empty
    }
    return rowDeleted;
}