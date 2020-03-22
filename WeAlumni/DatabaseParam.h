#pragma once

/*
 * DatabaseParam.h
 *
 * This file defined all shared strings that should be shared by all other source files.
 * Almost all source header files should include this file.
 * 
 * @author: Hang Yuan
 * Revised: 3/21/20
 *
 */

#ifndef DB_PARAM
#define DB_PARAM

#define DB_NAME "data.db"
#define DB_PATH "Data Source=" + DB_NAME

#define CREATE_ADMIN_TBL "CREATE TABLE IF NOT EXISTS Admin ( Username INT UNIQUE, Password INT );"

#endif