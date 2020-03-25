#pragma once
#include "DatabaseParam.h"

/*
 * Database.h
 *
 * This file defined all Database interfaces.
 *
 * @author: Hang Yuan
 * Revised: 3/23/20
 *
 */

namespace WeAlumni {
    using namespace System;
    using namespace System::Data;
    using namespace System::Data::SQLite;

    public ref class Database
    {
    public:
        enum class DatabaseType
        {
            Admin,
            Data,
            Treasury
        };

        Database(void) {

        }

        Database(DatabaseType type)
        {
            _databaseType = type;
            Initialize();
        }

        Database(DatabaseType type, bool readOnly)
        {
            _databaseType = type;
            _readOnly = readOnly;
            Initialize();
        }

    protected:
        ~Database()
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
        DatabaseType _databaseType;
        bool _readOnly = false;
        SQLiteConnection^ database;
        SQLiteCommand^ command;

    private:
        String^ GetDatabasePassword();
        String^ GetDatabaseName();
        String^ GetConnectionString();
        void Initialize();

    public:
        void SetDatabaseType(DatabaseType type) { _databaseType = type; };
        bool CreateDatabaseFile();
        bool CheckDatabaseFileExistence();
        int ReadData(String^ cmd);
        int ReadDataAdapter(String^ cmd);
        int InsertData(String^ cmd);
        int UpdateData(String^ cmd);
    };
}