#include "StarterPage.h"
#include "MainWindow.h"
/*
 * StarterPage.cpp
 *
 * This file includes two basic functions: button_click and lable_change.
 *
 * @author: Hang Yuan
 * Revised: 3/23/20
 *
 */

/*
 * DatabaseInitialize
 * This method will setup three database files: Admin.db, Data.db, Treasury.db
 * @param None
 * @return None
 * @exception SQLiteException or Customized Exception
 */
System::Void WeAlumni::StarterPage::DatabaseInitialize() {
    // Admin.db
    Database^ database = gcnew Database();
    database->SetDatabaseType(Database::DatabaseType::Admin);
    if (!database->CheckDatabaseFileExistence()) {
        if (!database->CreateDatabaseFile()) {
            throw gcnew Exception("Create new Admin.db database file FAILED.");
        }
    }

    // Data.db
    database = gcnew Database();
    database->SetDatabaseType(Database::DatabaseType::Data);
    if (!database->CheckDatabaseFileExistence()) {
        if (!database->CreateDatabaseFile()) {
            throw gcnew Exception("Create new Data.db database file FAILED.");
        }
    }

    // Treasury.db
    database = gcnew Database();
    database->SetDatabaseType(Database::DatabaseType::Treasury);
    if (!database->CheckDatabaseFileExistence()) {
        if (!database->CreateDatabaseFile()) {
            throw gcnew Exception("Create new Treasury.db database file FAILED.");
        }
    }
}

/*
 * btn_ChangeLable_Click
 * This method changed the color and text content of Label : lbl_Title
 * @param None
 * @return None
 */
System::Void WeAlumni::StarterPage::btn_ChangeLabel_Click(System::Object^ sender, System::EventArgs^ e) {
    if (_font == Lbl_Font::blue) {
        lbl_Title->ForeColor = Color::Red;
        lbl_Title->Text = "Change label color: Red";
        _font = Lbl_Font::red;
    }
    else {
        lbl_Title->ForeColor = Color::Blue;
        lbl_Title->Text = "Change label color: Blue";
        _font = Lbl_Font::blue;
    }
}

/*
 * btn_JumpAnotherPage_Click
 * This method start a new page: 
 * @param None
 * @return None
 */
System::Void WeAlumni::StarterPage::btn_JumpAnotherPage_Click(System::Object^ sender, System::EventArgs^ e) {
    // Your page should be initialized here.
    MainWindow^ mw = gcnew MainWindow();
    mw->Show();
}