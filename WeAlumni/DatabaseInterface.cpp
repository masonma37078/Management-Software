#include "DatabaseInterface.h"

/*
 * DatabaseInterface.h
 *
 * This file defined all Database interfaces, includes:
 *   ReadData
 *   ReaedAdapter
 *   InsertData
 *   UPdateData
 *
 * @author: Hang Yuan
 * Revised: 3/21/20
 *
 */

/*
 * ReadData
 * This method will try to read the Database as the command given.
 * @param String^ command that will be executed
                  "SELECT [* or COLUMN_NAME] FROM [TABLE_NAME] WHERE [CONDITION(s)];"
                  "SELECT [COLUMN_NAME] AS [NEW_NAME] FROM [TABLE_NAME] WHERE [CONDITION(s)];"
 * @return int -1 if nothing is read or catch an exception
 *             # of rows read if the execution is successful
 */
int WeAlumni::DatabaseInterface::ReadData(String^ cmd) {
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
 *                "SELECT [COLUMN_NAME] AS [NEW_NAME] FROM [TABLE_NAME] WHERE [CONDITION(s)];"
 * @return int -1 if catch an exception
 *             # of rows read if the execution is successful
 */
int WeAlumni::DatabaseInterface::ReadDataAdapter(String^ cmd) {
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
int WeAlumni::DatabaseInterface::InsertData(String^ cmd) {
    if (dataReader && !dataReader->IsClosed) dataReader->Close();
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
 * InsertData
 * This method will try to insert data into the Database as the command given.
 * @param String^ command that will be executed
 *                "UPDATE [TABLE_NAME] SET [COLUMN_NAME] = [DATA], [COLUMN_NAME] = [DATA}, ... WHERE [CONDITION];"
 * @return int -1 if catch an exception
 *             # of rows that are successfully updated 
 */
int WeAlumni::DatabaseInterface::UpdateData(String^ cmd) {
    if (dataReader && !dataReader->IsClosed) dataReader->Close();
    int rowupdated = -1;
    try {
        command->CommandText = cmd;
        rowupdated = command->ExecuteNonQuery();
    }
    catch (SQLiteException^) {
        // Leave empty
    }
    return rowupdated;
}