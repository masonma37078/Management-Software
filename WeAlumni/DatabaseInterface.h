#pragma once
#include "DatabaseParam.h"

/*
 * DatabaseInterface.h
 *
 * This file defined all Database interfaces, include:
 *   Read
 *   Write
 *   Update
 *
 * @author: Hang Yuan
 * Revised: 3/21/20
 *
 */

namespace WeAlumni {
    using namespace System;
    using namespace System::Data;
    using namespace System::Data::SQLite;

    public ref class DatabaseInterface
    {
    public:
        DatabaseInterface(void)
        {
            try {
                database = gcnew SQLiteConnection(DB_PATH);
                database->Open();
                command = database->CreateCommand();
                UpdateData(CREATE_ADMIN_TBL);
            }
            catch (SQLiteException^ exception) {
                throw exception;
            }
        }

    protected:
        ~DatabaseInterface()
        {
            if (dataReader) dataReader->Close();
            if (database) database->Close();
            delete (IDisposable^)dataReader;
            delete (IDisposable^)dataAdapter;
            delete (IDisposable^)database;
        }

    public:
        SQLiteDataReader^ dataReader;
        SQLiteDataAdapter^ dataAdapter;
        DataTable^ dataTable;

    private:
        SQLiteConnection^ database;
        SQLiteCommand^ command;

    public:
        int ReadData(String^ cmd);
        int ReadDataAdapter(String^ cmd);
        int InsertData(String^ cmd);
        int UpdateData(String^ cmd);
    };
}