#include "DatabasePrecheck.h"

/*
 * DatabasePrecheck.h
 *
 * This file provide method to do DB precheck
 *
 * @author: Xiangdong Che, Yiyun ZHeng
 * Revised: 04/09/20
  *         04/11/20 Add check treasury database
 *
 */

 /*
  * CheckAdmin
  * This method check existence of admin.db
  * @param None
  * @return true if exsit
  *		    false if not exist
  */
bool WeAlumni::DatabasePrecheck::CheckAdmin() {
    String^ fileName = "admin.db";
    return System::IO::File::Exists(fileName);
}

/*
 * CheckData
 * This method check existence of data.db
 * @param None
 * @return true if exsit
 *		   false if not exist
 */
bool WeAlumni::DatabasePrecheck::CheckData() {
    String^ fileName = "data.db";
    return System::IO::File::Exists(fileName);
}


/*
 * CheckTre
 * This method check existence of treasury.db
 * @param None
 * @return true if exsit
 *		   false if not exist
 */
bool WeAlumni::DatabasePrecheck::CheckTre() {
    String^ fileName = "treasury.db";
    return System::IO::File::Exists(fileName);
}

/*
 * Startcheck
 * This method start check process
 * @param None
 * @return None
 *
 */
void WeAlumni::DatabasePrecheck::StartPrecheck() {
    DatabasePrecheckPrompt^ admin_page = gcnew DatabasePrecheckPrompt(DatabasePrecheckPrompt::DatabaseType::admin);
    DatabasePrecheckPrompt^ data_page = gcnew DatabasePrecheckPrompt(DatabasePrecheckPrompt::DatabaseType::data);
    
    bool status = false;
    while (status == false) {
        if (admin_page->exitStatus == false) {
            admin_page->ShowDialog();
        }
        else {
            return;
        }
        status = admin_page->exitStatus;
    }
    admin_page->~DatabasePrecheckPrompt();
    
    while (CheckData() == false) {
        if (data_page->exitStatus == false) {
            data_page->ShowDialog();
        }
        else {
            return;
        }
        status = admin_page->exitStatus;
    }
    data_page->~DatabasePrecheckPrompt();

   
}

/*
 * TrePreCheck
 * This method treasury precheck process
 * @param None
 * @return None
 *
 */
bool WeAlumni::DatabasePrecheck::TrePrecheck() {
    DatabasePrecheckPrompt^ tre_page = gcnew DatabasePrecheckPrompt(DatabasePrecheckPrompt::DatabaseType::treasury);
    bool status = false;
    while (CheckTre() == false) {
        if (tre_page->exitStatus == false) {
            tre_page->ShowDialog();
        }
        else {
            return false;
        }
        status = tre_page->exitStatus;
    }
    return true;
    tre_page->~DatabasePrecheckPrompt();
}

