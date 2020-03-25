#include "DatabaseEncryptionAndDecryption.h"

/*
 * DatabaseEncryptionAndDecryption.cpp
 *
 * This file can encrypt or decrypt designated database file.
 *
 * @author: Hang Yuan
 * Revised: 3/23/20
 *
 */

using namespace System::Data::SQLite;

/*
 * GetDatabaseName
 * This method will offer the database name selected.
 * @param None
 * @return String^ database name selected
 */
System::String^ WeAlumni::DatabaseEncryptionAndDecryption::GetDatabaseName() {
    if (rbtn_adminDB->Checked) {
        return DB_ADMIN_NAME;
    }
    else if (rbtn_dataDB->Checked) {
        return DB_DATA_NAME;
    }
    else if (rbtn_treasuryDB->Checked) {
        return DB_TREASURY_NAME;
    }
    else {
        return "";
    }
}

/*
 * GetDatabasePassword
 * This method will offer the corresponding password based on DatabaseType
 * @param None
 * @return String^ the password of target database
 */
System::String^ WeAlumni::DatabaseEncryptionAndDecryption::GetDatabasePassword() {
    if (rbtn_adminDB->Checked) {
        return DB_ADMIN_PASSWORD;
    }
    else if (rbtn_dataDB->Checked) {
        return DB_DATA_PASSWORD;
    }
    else if (rbtn_treasuryDB->Checked) {
        return DB_TREASURY_PASSWORD;
    }
    else {
        return "";
    }
}

/*
 * SetDatabasePassword
 * This method will set password for target database file.
 * @param None
 * @return true if setting is successful
 *         false if not
 */
bool WeAlumni::DatabaseEncryptionAndDecryption::SetDatabasePassword() {
    bool success = false;
    SQLiteConnection^ database;
    String^ DataSource = GetDatabaseName();
    if (DataSource->Length == 0) {
        lbl_result->Text = "Didn't select an database";
        lbl_result->ForeColor = Color::Red;
        return success;
    }
    DataSource = "Data Source = " + DataSource;

    try {
        database = gcnew SQLiteConnection(DataSource);
        database->Open();
        database->ChangePassword(GetDatabasePassword());
        database->Close();
        success = true;
    }
    catch (Exception^ exception) {
        lbl_result->Text = exception->Message;
        lbl_result->ForeColor = Color::Red;
    }
    finally {
        delete database;
    }

    return success;
}

/*
 * RemoveDatabasePassword
 * This method will remove password from target database file.
 * @param None
 * @return true if removing is successful
 *         false if not
 */
bool WeAlumni::DatabaseEncryptionAndDecryption::RemoveDatabasePassword() {
    bool success = false;
    SQLiteConnection^ database;
    String^ DataSource = GetDatabaseName();
    if (DataSource->Length == 0) {
        lbl_result->Text = "Didn't select an database";
        lbl_result->ForeColor = Color::Red;
        return success;
    }
    DataSource = "Data Source = " + DataSource + "; password = " + GetDatabasePassword();

    try {
        database = gcnew SQLiteConnection(DataSource);
        database->Open();
        database->ChangePassword("");
        database->Close();
        success = true;
    }
    catch (Exception^ exception) {
        lbl_result->Text = exception->Message;
        lbl_result->ForeColor = Color::Red;
    }
    finally {
        delete database;
    }

    return success;
}

/*
 * btn_encrpyt_Click
 * This method will encrypt the database file selected.
 */
System::Void WeAlumni::DatabaseEncryptionAndDecryption::btn_encrpyt_Click(System::Object^ sender, System::EventArgs^ e) {
    if (SetDatabasePassword()) {
        lbl_result->Text = "Encrypt " + GetDatabaseName() + " successfully";
        lbl_result->ForeColor = Color::Green;
    }
}

/*
 * btn_decrypt_Click
 * This method will decrypt the database file selected.
 */
System::Void WeAlumni::DatabaseEncryptionAndDecryption::btn_decrypt_Click(System::Object^ sender, System::EventArgs^ e) {
    if (RemoveDatabasePassword()) {
        lbl_result->Text = "Decrypt " + GetDatabaseName() + " successfully";
        lbl_result->ForeColor = Color::Green;
    }
}

/*
 * btn_close_Click
 * This method will close this page.
 */
System::Void WeAlumni::DatabaseEncryptionAndDecryption::btn_close_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Close();
}