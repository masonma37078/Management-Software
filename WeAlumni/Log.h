#pragma once
#include "Database.h"

/*
 * Log.h
 *
 * This file contains all interfaces for inserting log file.
 *
 * @author: Hang Yuan
 * Revised: 3/26/20
 *
 */

namespace WeAlumni {
    using namespace System;
    using namespace System::Data;
    using namespace System::Data::SQLite;
    
    public ref class Log
    {
    public:
        Log() {
            Initialize();
        }
    protected:
        ~Log() {
            _database->~Database();
        }

    private:
        Database^ _database;
        void Initialize();

    public:
        bool AddLog(String^ stfId, String^ action);
    };
}