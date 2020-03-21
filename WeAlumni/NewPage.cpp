#include "NewPage.h"

/*
 * NewPage.cpp
 *
 * This file have basic Database interaction actions.
 *
 * @author: Hang Yuan
 * Revised: 3/21/20
 *
 */

using namespace System;

/*
 * GetPassword
 * This method will try to read password from the current database.
 * @param String^ inputPassword
 * @return bool true if inputPassword matches the database record
 *              false if otherwise
 */
bool WeAlumni::NewPage::VerifyPassword(String^ inputPassword) {
    String^ targetPassword = "DEFAULT : NOT_A_PASSWORD";
    String^ command = "SELECT * FROM Admin;";
    if (database->ReadData(command) > 0) {
        targetPassword = database->dataReader->GetString(0);
    }

    return targetPassword == inputPassword;
}

/*
 * SetPassword
 * This method will try to update new password into the current database.
 * @param String^ newPassword
 * @return bool true if insertion is successful
 *              false if otherwise
 */
bool WeAlumni::NewPage::SetPassword(String^ newPassword) {
    bool status = false;
    String^ command;

    if (DBHasPassword)
        command = "UPDATE Admin SET Password = '" + newPassword + "';";
    else
        command = "INSERT INTO Admin VALUES ('" + newPassword + "');";

    if (database->UpdateData(command) > 0) {
        status = true;
    }
    return status;
}

/*
 * btn_SetPassword_Click
 * Clicking this button will trigger a method SetPassword.
 * @param None
 * @return None
 */
Void WeAlumni::NewPage::btn_SetPassword_Click(System::Object^ sender, System::EventArgs^ e) {
    lbl_passwordVerify->Visible = true;
    lbl_passwordVerify->ForeColor = Color::Red;
    if (txt_password->TextLength < 6) {
        lbl_passwordVerify->Text = "ÉèÖÃÃÜÂë£ºÊ§°Ü, ²»×ã6Î»Êý×Ö";
        return;
    }
    
    if (SetPassword(txt_password->Text)) {
        lbl_passwordVerify->ForeColor = Color::Green;
        lbl_passwordVerify->Text = "ÉèÖÃÃÜÂë£º³É¹¦";
        UpdateDataGridView();
    }
    else {
        lbl_passwordVerify->Text = "ÉèÖÃÃÜÂë£ºÊ§°Ü";
    }
}

/*
 * btn_VerifyPassword_Click
 * Clicking this button will trigger a method GetPassword and set lbl_passwordVerify properly.
 * @param None
 * @return None
 */
Void WeAlumni::NewPage::btn_VerifyPassword_Click(System::Object^ sender, System::EventArgs^ e) {
    lbl_passwordVerify->Visible = true;
    lbl_passwordVerify->ForeColor = Color::Red;
    if (txt_password->TextLength == 0) {
        lbl_passwordVerify->Text = "ÇëÊäÈëÃÜÂë£¨²»ÉÙÓÚ6Î»£©";
    }
    else if (VerifyPassword(txt_password->Text)) {
        lbl_passwordVerify->ForeColor = Color::Green;
        lbl_passwordVerify->Text = "ÃÜÂëÕýÈ·";
    }
    else {
        lbl_passwordVerify->Text = "ÃÜÂë´íÎó";
    }
}

/*
 * UpdateDataGridView
 * This method will update the info for the dgv_ShowPassword.
 * @param None
 * @return None
 */
Void WeAlumni::NewPage::UpdateDataGridView() {
    String^ command = "SELECT Password AS 'ÃÜÂë' FROM Admin;";
    BindingSource^ bSource = gcnew BindingSource();
    int status = database->ReadDataAdapter(command);
    if (status == -1) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "Êý¾Ý¿â´íÎó£¬´íÎóÂë£º " + GetLastError();
        DBHasPassword = false;
    }
    else if (status == 0) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "Êý¾Ý¿âÎÞÊý¾Ý";
        DBHasPassword = false;
    }
    else {
        lbl_DBError->Visible = false;
        bSource->DataSource = database->dataTable;
        dgv_ShowPassword->DataSource = bSource;
        DBHasPassword = true;
    }
}