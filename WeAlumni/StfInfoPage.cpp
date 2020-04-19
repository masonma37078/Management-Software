#include "StfInfoPage.h"

/*
 * StfInfoPage.cpp
 *
 * This file implements all StfInfoPage interfaces.
 *
 * @author: Rui Jia
 * Revised: 4/12/20
 *          4/15/20 add DeleteRecord();
 *          4/18/20 change English text to Chinese; change some buttons
 *
 */

using namespace System;

/*
 * Initialize()
 * Pre-initialize all staff's info
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::Initialize() {
    try {
        _database = gcnew Database(Database::DatabaseType::Data);
    }
    catch (System::Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }
    UpdateInfo();
    CheckAuth();
}

/*
 * CheckAuth()
 * Check User Auth.
 * Level 1 & Level 2: PR
 * Level 3: PR/W
 * Level 4 & Level 5: F
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::CheckAuth() {
    if (_Auth == PublicUserInfo::Auth::Level_1 || _Auth == PublicUserInfo::Auth::Level_2 || _Auth == PublicUserInfo::Auth::Level_3) {
        AuthInvisible();
    }
    if (_Auth == PublicUserInfo::Auth::Level_3) {
        btn_ChangeInfo->Visible = true;
        btn_DeleteInfo->Visible = true;
    }
}

/*
 * AuthInvisible()
 * Set part of information invisible.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::AuthInvisible() {
    lbl_Gender->Visible = false;
    lbl_Birth->Visible = false;
    lbl_Phone->Visible = false;
    lbl_Wechat->Visible = false;
    btn_ChangeInfo->Visible = false;
    btn_DeleteInfo->Visible = false;
}

/*
 * UpdateInfo()
 * This method read from Staff table for the info of this Staff.
 * Then update info to according labels.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::UpdateInfo() {
    lbl_Error->Visible = false;
    lbl_Error_Data->Visible = false;

    int status = -1;
    String^ cmd = "SELECT * FROM Staff WHERE MemId = '" + _MemId + "';";
    try {
        status = _database->ReadData(cmd);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }

    if (status > 0) {
        lbl_MemId->Text = _database->dataReader->GetInt32(0).ToString();
        lbl_Dept->Text = _database->dataReader->GetString(1);
        lbl_Posi->Text = _database->dataReader->GetString(2);
        lbl_Auth->Text = _database->dataReader->GetString(3);

        cmb_Dept->Text = lbl_Dept->Text;
        cmb_Posi->Text = lbl_Posi->Text;
        cmb_Auth->Text = lbl_Auth->Text;
    }
    else {
        lbl_Error->Text = "������";
        lbl_Error->Visible = true;
        btn_ChangeInfo->Enabled = false;
        btn_DeleteInfo->Enabled = false;
    }

    int status2 = -1;
    String^ cmd2 = "SELECT * FROM Member WHERE Id = '" + _MemId + "';";
    try {
        status2 = _database->ReadData(cmd2);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }

    if (status > 0 && status2 > 0) {
        lbl_Name->Text = _database->dataReader->GetString(3);
        lbl_Gender->Text = _database->dataReader->GetString(4);
        lbl_Birth->Text = _database->dataReader->GetString(5);
        lbl_Email->Text = _database->dataReader->GetString(6);
        lbl_Phone->Text = _database->dataReader->GetString(7);
        lbl_Wechat->Text = _database->dataReader->GetString(8);
        UpdateDataGridView();
    }
    else {
        lbl_Error->Text = "������";
        lbl_Error->Visible = true;
        btn_ChangeInfo->Enabled = false;
        btn_DeleteInfo->Enabled = false;
    }
}

/*
 * ChangeTxtVisible()
 * Set all comboboxs visible.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::ChangeTxtVisible() {
    cmb_Dept->Visible = true;
    cmb_Posi->Visible = true;
    cmb_Auth->Visible = true;
}

/*
 * ChangeTxtInVisible()
 * Set all comboboxs invisible.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::ChangeTxtInvisible() {
    cmb_Dept->Visible = false;
    cmb_Posi->Visible = false;
    cmb_Auth->Visible = false;
}

/*
 * ChangeLabelVisible()
 * Set all labels visible.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::ChangeLabelVisible() {
    lbl_Dept->Visible = true;
    lbl_Posi->Visible = true;
    lbl_Auth->Visible = true;
}

/*
 * ChangeTxtVisible()
 * Set all labels invisible.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::ChangeLabelInvisible() {
    lbl_Dept->Visible = false;
    lbl_Posi->Visible = false;
    lbl_Auth->Visible = false;
}

/*
 * btn_ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e)
 * When click button "�༭��Ϣ", multiple TextBoxes will be visible to collect changed info.
 * When click button "�������", go to btn_Accept_Click() to update database.
 * When click button "ȷ��ɾ��", go to btn_DeleteInfo_Click() to delete information.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::btn_ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e) {
    lbl_Error->Visible = false;
    if (btn_ChangeInfo->Text == "�༭��Ϣ") {
        ChangeTxtVisible();
        ChangeLabelInvisible();
        btn_ChangeInfo->Text = "�������";
        btn_DeleteInfo->Text = "ȡ��";
    }
    else if (btn_ChangeInfo->Text == "�������") {
        btn_Accept_Click();
        btn_ChangeInfo->Text = "�༭��Ϣ";
        btn_DeleteInfo->Text = "ɾ����Ϣ";
    }
    else {
        btn_DeleteInfo_Click();
    }
}

/*
 * btn_Accpet_Click()
 * This method will trigger a Database update execution.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::btn_Accept_Click() {
    int status = -1;
    String^ command = "UPDATE Staff " +
        "SET    Dept = '" + cmb_Dept->Text + "', " +
        "Position = '" + cmb_Posi->Text + "', " +
        "Auth = '" + cmb_Auth->Text + "' " +
        "WHERE  MemId = '" + _MemId + "';";
    try {
        status = _database->UpdateData(command);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }

    int status2 = 0;
    int MemId = Int32::Parse(lbl_MemId->Text);
    String^ action = " �޸ĳ�Ա " + MemId + " ��Ϣ: ";
    if (status > 0) {
        if (lbl_Dept->Text != cmb_Dept->Text) {
            status2++;
            action += "���ڲ���";
        }
        if (lbl_Posi->Text != cmb_Posi->Text) {
            if (status2 != 0) {
                action += ", ";
            }
            action += "ְ��ְλ";
            status2++;
        }
        if (lbl_Auth->Text != cmb_Auth->Text) {
            if (status2 != 0) {
                action += ", ";
            }
            action += "Ȩ�޵ȼ�";
        }

        UpdateInfo();
        ChangeTxtInvisible();
        ChangeLabelVisible();
        UpdateDataGridView();
        lbl_Error->Text = "���³ɹ���";
        lbl_Error->ForeColor = Color::Green;
        lbl_Error->Visible = true;

        if (status2 != 0) {
            WeAlumni::Database::Log(_StfId, action);
        }
    }
    else {
        lbl_Error->Text = "���󣬸���ʧ��";
        lbl_Error->Visible = true;
    }

}

/*
 * btn_DeleteInfo_Click(System::Object^ sender, System::EventArgs^ e)
 * When click button "ɾ����Ϣ", then two buttons show up.
 * When click button "ȡ��", reset the value of TextBoxes.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::btn_DeleteInfo_Click(System::Object^ sender, System::EventArgs^ e) {
    lbl_Error->Visible = false;

    if (btn_DeleteInfo->Text == "ɾ����Ϣ") {
        btn_ChangeInfo->Text = "ȷ��ɾ��";
        btn_DeleteInfo->Text = "ȡ��";
    }
    else {
        btn_ChangeInfo->Text = "�༭��Ϣ";
        btn_DeleteInfo->Text = "ɾ����Ϣ";
        ChangeTxtInvisible();
        ChangeLabelVisible();
    }
}

/*
 * btn_Delete_Click()
 * This method will trigger a delete command.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::btn_DeleteInfo_Click() {
    int status = -1;
    String^ command = "DELETE FROM Staff WHERE MemId = '" + _MemId + "';";
    try {
        status = _database->DeleteData(command);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        return;
    }

    if (status > 0) {
        WeAlumni::Database::Log(_StfId, "Deleted Member");
        this->Close();
    }
    else {
        lbl_Error->Text = "����ɾ��ʧ��";
        lbl_Error->Visible = true;
    }
}

/*
 * UpdateDataGridView()
 * This method will update the info for the dgv_Staff.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::UpdateDataGridView() {
    int status = -1;
    String^ command = "SELECT Record.Id      AS '��¼���', " +
        "Record.Time    As '�Ǽ�ʱ��', " +
        "Record.MemId   AS '��Ա���', " +
        "Record.MemName AS '��Ա����', " +
        "Record.Action  AS '��������' " +
        "FROM   Record WHERE Record.MemId = '" + _MemId + "' ORDER BY Record.Id ASC;";
    BindingSource^ bSource = gcnew BindingSource();
    try {
        status = _database->ReadDataAdapter(command);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }

    if (status > 0) {
        bSource->DataSource = _database->dataTable;
        dgv_Staff->DataSource = bSource;
    }
    else {
        lbl_Error_Data->Visible = true;
    }
}

/*
 * dgv_Staff_CellContentClick()
 * by double clicking specific row of dgv_Staff, a corresponding Record Info page will show up.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::dgv_Staff_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    RecInfoPage^ recInfoPage = gcnew RecInfoPage(Convert::ToInt32(dgv_Staff->CurrentRow->Cells[0]->Value));
    recInfoPage->ShowDialog();
}


