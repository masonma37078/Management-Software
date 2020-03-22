#pragma once

/*
 * DatabaseParam.h
 *
 * This file defined all shared strings that should be shared by all other source files.
 * Almost all source header files should include this file.
 * 
 * @author: Hang Yuan
 * Revised: 3/22/20 Add new database commands
 *          3/21/20 Init
 *
 */

#ifndef DB_PARAM
#define DB_PARAM

#define DB_NAME "data.db"
#define DB_PATH "Data Source=" + DB_NAME

#define CREATE_ADMIN_TBL "CREATE TABLE IF NOT EXISTS Admin ( Username INT UNIQUE, Password INT, Auth INT );"
#define CREATE_MEMBER_TBL "CREATE TABLE IF NOT EXISTS Member( Id TEXT PRIMARY KEY, Status TEXT, Type TEXT, Gender TEXT, Birth TEXT, Email TEXT, Phone TEXT, Wechat TEXT, Country TEXT, Address1 TEXT, Address2 TEXT, City TEXT, Postal TEXT, StdId TEXT, Program TEXT, EndDate TEXT, Degree TEXT, Major1 TEXT, Major2 TEXT, Career TEXT, Company TEXT, Position TEXT, SearchAuth TEXT );"
#define CREATE_STAFF_TBL "CREATE TABLE IF NOT EXISTS Staff ( Id TEXT PRIMARY KEY, MemId TEXT, Dept TEXT, Position TEXT, Auth TEXT, FOREIGN KEY(MemId) REFERENCES Member(Id) );"
#define CREATE_RECORD_TBL "CREATE TABLE IF NOT EXISTS Record ( Id TEXT PRIMARY KEY, StfId TEXT, MemId TEXT, Date TEXT, Action TEXT, FOREIGN KEY(StfId) REFERENCES Staff(Id) );"
#define CREATE_OPT_TBL "CREATE TABLE IF NOT EXISTS OPT( MemId TEXT, StfId TEXT, StartDate TEXT, EndData TEXT, Title TEXT, Position TEXT, CardNo TEXT, CardStartDate TEXT, CardEndDate TEXT, FOREIGN KEY(MemId) REFERENCES Member(Id), FOREIGN KEY(StfId) REFERENCES Staff(Id) );"
#define CREATE_LOG_TBL "CREATE TABLE IF NOT EXISTS Log ( Id TEXT PRIMARY KEY, StfId TEXT, Action TEXT, FOREIGN KEY(StfId) REFERENCES Staff(Id) );"

#endif