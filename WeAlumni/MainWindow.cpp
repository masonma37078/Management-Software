#include "MainWindow.h"
#include <vector>
/*
 * MainWindow.h
 *
 * This file implements all sub-functions required in the MainWindow.
 *
 * @author: Hang Yuan
 * Revised: 3/27/20
 *          4/8/20 add member MainWindow functions
 *          4/12/20 add staff MainWindow and auth control for staff and member
 *          4/15/20 bug fix
 *          4/21/20 Added OPT MainWindow Part(Xiangdong Che)
 *          5/1/20 ui & auth update record & order
 *          5/02/20 Changed layout of OPT part(Xiangdong Che)
 *          5/2/20 Treasury MainWindow (Yiyun Zheng)
 */

using namespace System;

/*
 * SetAllPanelInvisible
 * This method will change all property Visible of all panels into false
 * @param None
 * @return None
 */
void WeAlumni::MainWindow::SetAllPanelInvisible() {
    pan_member->Visible = false;
    pan_staff->Visible = false;
    pan_record->Visible = false;
    pan_OPT->Visible = false;
    pan_order->Visible = false;
    pan_treasury->Visible = false;
    pan_myInfo->Visible = false;
}

/*
* Initialize
* This method will try to initialize database.
* @param none
* @return none
*/
Void WeAlumni::MainWindow::Initialize() {
    try {
        database = gcnew Database(Database::DatabaseType::Data);
    }
    catch (System::Exception^ exception) {
        mem_lbl_error->Text = exception->Message;
        mem_lbl_error->ForeColor = System::Drawing::Color::Red;
    }
    mem_UpdateDataGridView(MEM_SELECT_ALL);
    mem_GeneralInformation();
    mem_CheckAuth();
    stf_GeneralInformation();
    stf_UpdateDataGridView(STF_SELECT_ALL);
    stf_CheckAuth();
    Rec_GeneralInformation();
    Rec_UpdateDataGridView(REC_SELECT_ALL);
    Rec_CheckAuth();
    ord_UpdateDataGridView(ORD_SELECT_ALL);
    ord_GeneralInformation();
    ord_CheckAuth();
    OPT_UpdateDataGridView(OPT_SELECT_ALL);
    OPT_GeneralInformation();
    OPT_CheckAuth();
    Tre_CheckDB();
    Tre_GeneralInformation();
    min_GeneralInformation();
}

/*
 *  Member
 */
 /*
 * mem_btn_Search_Click
 *
 * This method will try to search from Record table for the record of this member.
 * Then update record to DataGridView1
 */
Void WeAlumni::MainWindow::mem_btn_Search_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ id = mem_txt_Id->Text;
    String^ status = mem_cmb_Status->Text;
    String^ type = mem_cmb_Type->Text;
    String^ name = mem_txt_Name->Text;
    String^ gender = mem_txt_Gender->Text;
    String^ careerStatus = mem_cmb_CareerStatus->Text;
    String^ major = mem_txt_Major->Text;
    String^ searchAuth = mem_cmb_SearchAuth->Text;
    String^ cmd = "SELECT Member.Id AS '��Ա���', Member.Status AS '��Ա״̬'," +
        " Member.Type AS '��Ա����'," + " Member.Name AS '����'," +
        " Member.Gender AS '�Ա�'," + "Member.Email AS 'Email'" +
        "FROM Member WHERE ";
    String^ cmd2 = "";

    std::vector<int> vec;
    if (id->Length)           vec.push_back(0);
    if (status->Length)       vec.push_back(1);
    if (type->Length)         vec.push_back(2);
    if (name->Length)         vec.push_back(3);
    if (gender->Length)       vec.push_back(4);
    if (careerStatus->Length) vec.push_back(5);
    if (major->Length)        vec.push_back(6);
    if (searchAuth->Length)   vec.push_back(7);
    if (vec.size() == 0) {
        mem_lbl_error->ForeColor = System::Drawing::Color::Red;
        mem_lbl_error->Text = "���޴���";
        mem_lbl_error->Visible = true;
        mem_dataGridView1->DataSource = nullptr;
        return;
    }

    bool flag = false;
    for (auto i : vec) {
        if (vec.size() != 1 && flag) cmd2 += " AND ";
        switch (i) {
        case 0: cmd2 += "Member.Id = " + Convert::ToInt32(id); break;
        case 1: cmd2 += "Member.Status = '" + status + "' "; break;
        case 2: cmd2 += "Member.Type = '" + type + "' "; break;
        case 3: cmd2 += "Member.Name = '" + name + "' "; break;
        case 4: cmd2 += "Member.Gender = '" + gender + "' "; break;
        case 5: cmd2 += "Member.CareerStatus = '" + careerStatus + "' "; break;
        case 6: cmd2 += "Member.Major1 = '" + major + "' " +
            "OR Member.Major2 = '" + major + "' "; break;
        case 7: cmd2 += "Member.SearchAuth = '" + searchAuth + "' "; break;
        }
        flag = true;
    }
    cmd += cmd2 + " ORDER BY Member.Id ASC;";
    mem_UpdateDataGridView(cmd);
    mem_GeneralInformation();
}

/*
* mem_btn_Clear_Click
*
* When click button "Clear", this method clear up every TextBox or ComboBox of the search engine and UpdateDataGridView.
*/
Void WeAlumni::MainWindow::mem_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e) {
    mem_txt_Id->Text = "";
    mem_txt_Gender->Text = "";
    mem_txt_Major->Text = "";
    mem_txt_Name->Text = "";
    mem_cmb_CareerStatus->Text = "";
    mem_cmb_SearchAuth->Text = "";
    mem_cmb_Status->Text = "";
    mem_cmb_Type->Text = "";
    mem_lbl_error->Visible = false;
    mem_UpdateDataGridView(MEM_SELECT_ALL);
    mem_GeneralInformation();
}

/*
* mem_btn_Add_Click
*
* When click button "Add", a new window MemAddPage will be called up.
*/
Void WeAlumni::MainWindow::mem_btn_Add_Click(System::Object^ sender, System::EventArgs^ e) {
    MemAddPage^ map = gcnew MemAddPage(_pui);
    map->ShowDialog();
    mem_UpdateDataGridView(MEM_SELECT_ALL);
    mem_GeneralInformation();
}

/*
 * mem_dataGridView1_CellDoubleClick
 * by double clicking specific row of mem_dataGridView1, a corresponding Record Info page will show up.
 */
Void WeAlumni::MainWindow::mem_dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    MemInfoPage^ mip = gcnew MemInfoPage(Convert::ToInt32(mem_dataGridView1->CurrentRow->Cells[0]->Value), _pui);
    mip->ShowDialog();
    mem_UpdateDataGridView(MEM_SELECT_ALL);
    mem_GeneralInformation();
}

/*
 * mem_CheckAuth()
 * Check mem Auth. If Level == 1, user can't see the member mainWindow.
 * If Lever == 2, user can't add/import information.
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::mem_CheckAuth() {
    if (_Auth == PublicUserInfo::Auth::Level_1) {
        tsm_member->Visible = false;
        pan_member->Visible = false;
    }
    else if (_Auth == PublicUserInfo::Auth::Level_2) {
        mem_btn_Add->Visible = false;
        mem_btn_Import->Visible = false;
    }
}

/*
 * mem_UpdateDataGridView(String^ command)
 * update member data grid view.
 * @param String^ command
 * @return None
 */
Void WeAlumni::MainWindow::mem_UpdateDataGridView(String^ command) {
    BindingSource^ bSource = gcnew BindingSource();
    int status1 = -1;

    try {
        status1 = database->ReadDataAdapter(command);
    }
    catch (Exception^ exception) {
        mem_lbl_error->ForeColor = System::Drawing::Color::Red;
        mem_lbl_error->Text = exception->Message;
        mem_lbl_error->Visible = true;
        return;
    }

    if (status1 > 0) {
        mem_lbl_error->Visible = false;
        bSource->DataSource = database->dataTable;
        mem_dataGridView1->DataSource = bSource;
    }
    else {
        mem_lbl_error->ForeColor = System::Drawing::Color::Red;
        mem_lbl_error->Text = "���޴���";
        mem_lbl_error->Visible = true;
        mem_dataGridView1->DataSource = nullptr;
    }
}

/*
 * mem_GeneralInformation()
 * Show general information of member
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::mem_GeneralInformation() {
    int status = -1;
    String^ cmd = "SELECT COUNT(Id) FROM Member;";

    try {
        status = database->ReadData(cmd);
    }
    catch (Exception^ exception) {
        mem_lbl_error->Text = exception->Message;
        mem_lbl_error->Visible = true;
        return;
    }

    if (status > 0) {
        mem_lbl_Count->Text = database->dataReader->GetInt32(0).ToString();
    }
    else {
        mem_lbl_error->Text = "�޷���������";
        mem_lbl_error->Visible = true;
    }
    database->dataReader->Close();
}

Void WeAlumni::MainWindow::mem_btn_Import_Click(System::Object^ sender, System::EventArgs^ e) {

}

/*
 *  Staff
 */

 /*
  * stf_CheckAuth()
  * Check staff Auth. If Level < 3, user can't add/import information.
  * @param None
  * @return None
  */
Void WeAlumni::MainWindow::stf_CheckAuth() {
    if (_Auth == PublicUserInfo::Auth::Level_1 || _Auth == PublicUserInfo::Auth::Level_2) {
        stf_btn_Add->Enabled = false;
    }
}

/*
 * stf_btn_Search_Click()
 * This method will try to search from Member table and Staff table of this member.
 * Then update record to stf_dataGridView
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::stf_btn_Search_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ Id = stf_txt_Id->Text;
    String^ Name = stf_txt_Name->Text;
    String^ Dept = stf_cmb_Dept->Text;
    String^ Auth = stf_cmb_Auth->Text;

    String^ command = "SELECT Staff.MemId    AS 'ID', " +
        "Member.Name    As '����', " +
        "Member.Gender  AS '�Ա�', " +
        "Member.Email   AS 'Email', " +
        "Staff.Dept     As '���ڲ���', " +
        "Staff.Position As 'ְλְ��', " +
        "Staff.Auth     As 'Ȩ�޵ȼ�' " +
        "FROM   Member, Staff " +
        "WHERE Staff.MemId = Member.Id AND ";
    BindingSource^ bSource = gcnew BindingSource();
    String^ cmd2 = "";

    std::vector<int> vec;
    if (Id->Length)           vec.push_back(0);
    if (Name->Length)         vec.push_back(1);
    if (Dept->Length)         vec.push_back(2);
    if (Auth->Length)         vec.push_back(3);
    if (vec.size() == 0) {
        mem_UpdateDataGridView(STF_SELECT_ALL);
        stf_dataGridView->DataSource = nullptr;
        stf_lbl_Error->Visible = true;
        stf_lbl_Error->Text = "�Ҳ�������";
        return;
    }

    bool flag = false;
    for (auto i : vec) {
        if (vec.size() != 1 && flag) cmd2 += " AND ";
        switch (i) {
        case 0: cmd2 += "Staff.MemId = '" + Id + "' "; break;
        case 1: cmd2 += "Member.Name = '" + Name + "' "; break;
        case 2: cmd2 += "Staff.Dept = '" + Dept + "' "; break;
        case 3: cmd2 += "Staff.Auth = '" + Auth + "' "; break;
        }
        flag = true;
    }
    command += cmd2 + " ORDER BY Staff.MemId ASC;";
    stf_UpdateDataGridView(command);
    stf_GeneralInformation();
}

/*
 * stf_btn_Add_Click
 * When click button "Add", a new window StfAddPage will be called up.
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::stf_btn_Add_Click(System::Object^ sender, System::EventArgs^ e) {
    StfAddPage^ add = gcnew StfAddPage(_pui);
    add->ShowDialog();
    stf_UpdateDataGridView(STF_SELECT_ALL);
    stf_GeneralInformation();
}

/*
 * stf_btn_Clear_Click
 * When click button "Clear", this method clear up every TextBox or ComboBox of the search engine and UpdateDataGridView.
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::stf_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e) {
    stf_dataGridView->DataSource = nullptr;
    stf_txt_Id->Text = "";
    stf_txt_Name->Text = "";
    stf_cmb_Dept->Text = "";
    stf_cmb_Auth->Text = "";
    stf_UpdateDataGridView(STF_SELECT_ALL);
    stf_GeneralInformation();
}

/*
 * stf_dataGridView_CellContentClick
 * by double clicking specific row of stf_dataGridView, a corresponding Record Info page will show up.
 */
Void WeAlumni::MainWindow::stf_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    StfInfoPage^ mip = gcnew StfInfoPage(Convert::ToInt32(stf_dataGridView->CurrentRow->Cells[0]->Value), _pui);
    mip->ShowDialog();
    stf_UpdateDataGridView(STF_SELECT_ALL);
    stf_GeneralInformation();
}

/*
 * stf_GeneralInformation()
 * Show general information of staff
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::stf_GeneralInformation() {
    int status = -1;
    String^ count = "SELECT COUNT(MemId) FROM Staff;";
    try {
        status = database->ReadData(count);
    }
    catch (Exception^ exception) {
        stf_lbl_Error->Text = exception->Message;
        stf_lbl_Error->Visible = true;
        return;
    }
    if (status > 0) {
        stf_lbl_Count->Text = database->dataReader->GetInt32(0).ToString();
    }
    else {
        stf_lbl_Error->Text = "�Ҳ�������";
        stf_lbl_Error->Visible = true;
    }
    database->dataReader->Close();
}
/*
 * stf_UpdateDataGridView(String^ command)
 * update staff data grid view.
 * @param String^ command
 * @return None
 */
Void WeAlumni::MainWindow::stf_UpdateDataGridView(String^ command) {
    BindingSource^ bSource = gcnew BindingSource();
    int status1 = -1;

    try {
        status1 = database->ReadDataAdapter(command);
    }
    catch (Exception^ exception) {
        stf_lbl_Error->ForeColor = System::Drawing::Color::Red;
        stf_lbl_Error->Text = exception->Message;
        stf_lbl_Error->Visible = true;
        return;
    }

    if (status1 > 0) {
        stf_lbl_Error->Visible = false;
        bSource->DataSource = database->dataTable;
        stf_dataGridView->DataSource = bSource;
    }
    else {
        stf_dataGridView->DataSource = nullptr;
        stf_lbl_Error->Visible = true;
        stf_lbl_Error->ForeColor = System::Drawing::Color::Red;
        stf_lbl_Error->Text = "�Ҳ�������";
    }
}

/*
 *  Order
 */

 /*
  * ord_CheckAuth()
  * Check order Auth. If Level == 1 or 2, user can't see the order mainWindow.
  * @param None
  * @return None
  */
Void WeAlumni::MainWindow::ord_CheckAuth() {
    if (_Auth == PublicUserInfo::Auth::Level_1 || _Auth == PublicUserInfo::Auth::Level_2) {
        tsm_order->Visible = false;
        pan_order->Visible = false;
    }
}

/*
* ord_btn_Search_Click
*
* This method will try to search from Record table for the record of this order
* and related info from member and item.
* Then update record to ord_DataGridView
*/
Void WeAlumni::MainWindow::ord_btn_Search_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ o_id = ord_txt_ordId->Text;
    String^ status = ord_cmb_Status->Text;
    String^ m_id = ord_txt_memId->Text;
    String^ m_name = ord_txt_memName->Text;
    String^ i_id = ord_txt_itmId->Text;
    String^ i_name = ord_txt_itmName->Text;
    String^ cmd = "SELECT Orders.Id AS 'OrderId', Orders.Status AS 'Status'," +
        " Orders.Time AS 'Time'," + " Member.Name AS 'MemName'," +
        " Member.Email AS 'Email'," + "Item.Name AS 'ItmName'," +
        " Orders.Amount AS 'Amount'," + "Item.Price AS 'ItmPrice'," +
        " Orders.Comment AS 'Comment'" +
        "FROM Orders, Member, Item WHERE Orders.MemId = Member.Id AND Orders.ItemId = Item.Id AND ";
    String^ cmd2 = "";

    std::vector<int> vec;
    if (o_id->Length)           vec.push_back(0);
    if (status->Length)       vec.push_back(1);
    if (m_id->Length)         vec.push_back(2);
    if (m_name->Length)         vec.push_back(3);
    if (i_id->Length)       vec.push_back(4);
    if (i_name->Length) vec.push_back(5);
    if (vec.size() == 0) {
        ord_lbl_Error->ForeColor = System::Drawing::Color::Red;
        ord_lbl_Error->Text = "CANNOT FIND ORDER";
        ord_lbl_Error->Visible = true;
        ord_dataGridView->DataSource = nullptr;
        return;
    }

    bool flag = false;
    for (auto i : vec) {
        if (vec.size() != 1 && flag) cmd2 += " AND ";
        switch (i) {
        case 0: cmd2 += "Orders.Id = " + Convert::ToInt32(o_id); break;
        case 1: cmd2 += "Orders.Status = '" + status + "' "; break;
        case 2: cmd2 += "Member.Id = " + Convert::ToInt32(m_id); break;
        case 3: cmd2 += "Member.Name = '" + m_name + "' "; break;
        case 4: cmd2 += "Item.Id = " + Convert::ToInt32(i_id); break;
        case 5: cmd2 += "Item.Name = '" + i_name + "' "; break;
        }
        flag = true;
    }
    cmd += cmd2 + " ORDER BY Orders.Id ASC;";
    ord_UpdateDataGridView(cmd);
    ord_GeneralInformation();
}

/*
* ord_btn_Clear_Click
*
* When click button "Clear", this method clear up every TextBox or ComboBox of the search engine and UpdateDataGridView.
*/
Void WeAlumni::MainWindow::ord_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e) {
    ord_txt_ordId->Text = "";
    ord_cmb_Status->Text = "";
    ord_txt_memId->Text = "";
    ord_txt_memName->Text = "";
    ord_txt_itmId->Text = "";
    ord_txt_itmName->Text = "";
    ord_lbl_Error->Visible = false;
    ord_UpdateDataGridView(ORD_SELECT_ALL);
    ord_GeneralInformation();
}

/*
* ord_btn_Add_Click
*
* When click button "Add", a new window OrdAddPage will be called up.
*/
Void WeAlumni::MainWindow::ord_btn_Add_Click(System::Object^ sender, System::EventArgs^ e) {
    OrdAddPage^ oap = gcnew OrdAddPage(_pui);
    oap->ShowDialog();
    ord_UpdateDataGridView(ORD_SELECT_ALL);
    ord_GeneralInformation();
}

/*
 * ord_dataGridView_CellDoubleClick
 * by double clicking specific row of ord_dataGridView, a corresponding OrdInfoPage will show up.
 */
Void WeAlumni::MainWindow::ord_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    OrdInfoPage^ oip = gcnew OrdInfoPage(_pui, Convert::ToInt32(ord_dataGridView->CurrentRow->Cells[0]->Value));
    oip->ShowDialog();
    ord_UpdateDataGridView(ORD_SELECT_ALL);
    ord_GeneralInformation();
}

/*
 * ord_UpdateDataGridView(String^ command)
 * update order data grid view.
 * @param String^ command
 * @return None
 */
Void WeAlumni::MainWindow::ord_UpdateDataGridView(String^ command) {
    BindingSource^ bSource = gcnew BindingSource();
    int status = -1;

    try {
        status = database->ReadDataAdapter(command);
    }
    catch (Exception^ exception) {
        ord_lbl_Error->ForeColor = System::Drawing::Color::Red;
        ord_lbl_Error->Text = exception->Message;
        ord_lbl_Error->Visible = true;
        return;
    }

    if (status > 0) {
        ord_lbl_Error->Visible = false;
        bSource->DataSource = database->dataTable;
        ord_dataGridView->DataSource = bSource;
    }
    else {
        ord_lbl_Error->ForeColor = System::Drawing::Color::Red;
        ord_lbl_Error->Text = "CANNOT FIND ORDER";
        ord_lbl_Error->Visible = true;
        ord_dataGridView->DataSource = nullptr;
    }
}

/*
 * ord_GeneralInformation()
 * Show general information of order
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::ord_GeneralInformation() {
    int status = -1;
    String^ cmd = "SELECT COUNT(Id) FROM Orders;";

    try {
        status = database->ReadData(cmd);
    }
    catch (Exception^ exception) {
        ord_lbl_Error->Text = exception->Message;
        ord_lbl_Error->Visible = true;
        return;
    }

    if (status > 0) {
        ord_lbl_Count->Text = database->dataReader->GetInt32(0).ToString();
    }
    else {
        ord_lbl_Error->Text = "Can't find data";
        ord_lbl_Error->Visible = true;
    }
    database->dataReader->Close();
}

/*
 *  Record
 */

 /*
  * Rec_CheckAuth()
  * Check order Auth. If Level == 1 2, 3, user can't see the record mainWindow.
  * @param None
  * @return None
  */
Void WeAlumni::MainWindow::Rec_CheckAuth() {
    if (_Auth == PublicUserInfo::Auth::Level_1 || _Auth == PublicUserInfo::Auth::Level_2 || _Auth == PublicUserInfo::Auth::Level_3) {
        tsm_record->Visible = false;
        pan_record->Visible = false;
    }
}
/*
* Rec_btn_Search_Click
*
* This method will try to search from Record table for the record of this record
* Then update record to rec_DataGridView
*/
Void WeAlumni::MainWindow::Rec_btn_Search_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ recId = Rec_txt_RecId->Text;
    String^ stfId = Rec_txt_StfId->Text;
    String^ name = Rec_txt_MemName->Text;
    String^ dept = Rec_txt_department->Text;
    String^ cmd = "SELECT Record.Id AS 'ID', Record.Time AS '登记时间'," +
        " Record.StfId AS '员工编号'," + " Record.Memname AS '员工姓名'," +
        " Staff.Dept AS '所在部�?," + "Staff.Position AS '职位职务'," +
        " Record.Action AS '操作内容'" + "FROM Record, Staff WHERE Record.MemId = Staff.MemId AND ";
    String^ cmd1 = "";

    std::vector<int> vec;
    if (recId->Length)           vec.push_back(0);
    if (stfId->Length)           vec.push_back(1);
    if (name->Length)            vec.push_back(2);
    if (dept->Length)            vec.push_back(3);
    if (vec.size() == 0) {
        Rec_lbl_Error->ForeColor = System::Drawing::Color::Red;
        Rec_lbl_Error->Text = "未找到记�?;
        Rec_lbl_Error->Visible = true;
        Rec_dataGridView->DataSource = nullptr;
        return;
    }

    bool flag = false;
    for (auto i : vec) {
        if (vec.size() != 1 && flag) cmd1 += " AND ";
        switch (i) {
        case 0: cmd1 += "Record.Id = '" + Convert::ToInt32(recId) + "' "; break;
        case 1: cmd1 += "Record.StfId = '" + Convert::ToInt32(stfId) + "' "; break;
        case 2: cmd1 += "Record.MemName = '" + name + "' "; break;
        case 3: cmd1 += "Staff.Dept = '" + dept + "' "; break;
        }
        flag = true;
    }
    cmd += cmd1 + " ORDER BY Record.Id ASC;";
    Rec_UpdateDataGridView(cmd);
    Rec_GeneralInformation();
}

/*
* rec_btn_Clear_Click
*
* When click button "Clear", this method clear up every TextBox or ComboBox of the search engine and UpdateDataGridView.
*/
Void WeAlumni::MainWindow::Rec_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e) {
    Rec_txt_RecId->Text = "";
    Rec_txt_department->Text = "";
    Rec_txt_StfId->Text = "";
    Rec_txt_MemName->Text = "";
    Rec_lbl_Error->Visible = false;
    Rec_UpdateDataGridView(REC_SELECT_ALL);
    Rec_GeneralInformation();
}

/*
 * Rec_dataGridView_CellDoubleClick
 * by double clicking specific row of recc_dataGridView, a corresponding RecInfoPage will show up.
 */
Void WeAlumni::MainWindow::Rec_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    RecInfoPage^ rip = gcnew RecInfoPage(Convert::ToInt32(Rec_dataGridView->CurrentRow->Cells[0]->Value), _pui);
    rip->ShowDialog();
    Rec_UpdateDataGridView(REC_SELECT_ALL);
    Rec_GeneralInformation();
}

/*
 * Rec_UpdateDataGridView(String^ command)
 * update rec data grid view.
 * @param String^ command
 * @return None
 */
Void WeAlumni::MainWindow::Rec_UpdateDataGridView(String^ command) {
    BindingSource^ bSource = gcnew BindingSource();
    int status = -1;

    try {
        status = database->ReadDataAdapter(command);
    }
    catch (Exception^ exception) {
        Rec_lbl_Error->ForeColor = System::Drawing::Color::Red;
        Rec_lbl_Error->Text = exception->Message;
        Rec_lbl_Error->Visible = true;
        return;
    }
    if (status > 0) {
        Rec_lbl_Error->Visible = false;
        bSource->DataSource = database->dataTable;
        Rec_dataGridView->DataSource = bSource;
    }
    else {
        Rec_lbl_Error->ForeColor = System::Drawing::Color::Red;
        Rec_lbl_Error->Text = "未找到记�?;
        Rec_lbl_Error->Visible = true;
        Rec_dataGridView->DataSource = nullptr;
    }
}

/*
 * Rec_GeneralInformation()
 * Show general information of record
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::Rec_GeneralInformation() {
    int status = -1;
    String^ cmd = "SELECT COUNT(Id) FROM Record;";

    try {
        status = database->ReadData(cmd);
    }
    catch (Exception^ exception) {
        Rec_lbl_Error->Text = exception->Message;
        Rec_lbl_Error->Visible = true;
        return;
    }

    if (status > 0) {
        rec_lbl_Count->Text = database->dataReader->GetInt32(0).ToString();
    }
    else {
        Rec_lbl_Error->Text = "无相关数�?;
        Rec_lbl_Error->Visible = true;
    }
    database->dataReader->Close();
}

/*
 *
 *  OPT
 *
 */

 /*
  * OPT_UpdateDataGridView()
  * Update DataGridView
  * @param None
  * @return None
  */
Void WeAlumni::MainWindow::OPT_UpdateDataGridView(String^ command) {
    BindingSource^ bSource = gcnew BindingSource();
    int status = -1;

    try {
        status = database->ReadDataAdapter(command);
    }
    catch (Exception^ exception) {
        OPT_lbl_error->ForeColor = System::Drawing::Color::Red;
        OPT_lbl_error->Text = exception->Message;
        OPT_lbl_error->Visible = true;
        return;
    }

    if (status > 0) {
        OPT_lbl_error->Visible = false;
        bSource->DataSource = database->dataTable;
        OPT_dataGridView->DataSource = bSource;
    }
    else {
        OPT_lbl_error->ForeColor = System::Drawing::Color::Red;
        OPT_lbl_error->Text = "CANNOT FIND OPT";
        OPT_lbl_error->Visible = true;
        OPT_dataGridView->DataSource = nullptr;
    }
}

/*
 * OPT_btn_Search_Click()
 * Search data with provided info
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::OPT_btn_Search_Click(System::Object^ sender, System::EventArgs^ e) {
    OPT_lbl_Prompt_default->Visible = false;
    String^ OPTId = OPT_txt_OPTId->Text;
    String^ Status = OPT_cmb_Status->Text;
    String^ MemId = OPT_txt_MemId->Text;
    String^ MemName = OPT_txt_MemName->Text;
    String^ CardNumber = OPT_txt_CardNumber->Text;

    String^ command = "SELECT OPT.Id                                                        AS 'OPT编号', " +
        "OPT.Status                                                    AS '状�?, " +
        "(SELECT Member.Name FROM Member WHERE Member.Id = OPT.MemId)  AS '成员姓名', " +
        "(SELECT Member.Name FROM Member " +
        "INNER JOIN Staff INNER JOIN OPT " +
        "WHERE Member.Id = Staff.MemId AND Staff.MemId = OPT.StfId)    AS '员工姓名', " +
        "OPT.StartDate                                                 AS '开始日�?, " +
        "OPT.EndDate                                                   AS '结束日期', " +
        "OPT.Title                                                     AS '头衔', " +
        "OPT.Position                                                  AS '职位' " +
        "FROM OPT INNER JOIN Member WHERE ";
    String^ command2 = "";

    std::vector<int> vec;
    if (OPTId->Length)         vec.push_back(0);
    if (Status->Length)        vec.push_back(1);
    if (MemId->Length)         vec.push_back(2);
    if (MemName->Length)       vec.push_back(3);
    if (CardNumber->Length)    vec.push_back(4);
    if (vec.size() == 0) {
        OPT_UpdateDataGridView(OPT_SELECT_ALL);
        OPT_lbl_Prompt_default->Visible = true;
        return;
    }

    bool flag = false;
    for (auto i : vec) {



        if (vec.size() != 1 && flag) command2 += " AND ";
        switch (i) {
        case 0: command2 += "OPT.MemId = Member.Id AND OPT.Id = '" + OPTId + "' "; break;
        case 1: command2 += "OPT.MemId = Member.Id AND OPT.Status = '" + Status + "' "; break;
        case 2: command2 += "OPT.MemId = Member.Id AND Member.Id = '" + MemId + "' "; break;
        case 3: command2 += "OPT.MemId = Member.Id AND Member.Name = '" + MemName + "' "; break;
        case 4: command2 += "OPT.MemId = Member.Id AND OPT.CardNumber = '" + CardNumber + "' "; break;
        }
        flag = true;
    }

    command += command2 + " ORDER BY OPT.Id ASC;";
    OPT_UpdateDataGridView(command);
    OPT_GeneralInformation();
}

/*
 * OPT_btn_Clear_Click()
 * Reset all textboxs and DataGridView
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::OPT_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e) {
    OPT_lbl_Prompt_default->Visible = true;
    OPT_txt_OPTId->Text = "";
    OPT_cmb_Status->Text = "";
    OPT_txt_MemId->Text = "";
    OPT_txt_MemName->Text = "";
    OPT_txt_CardNumber->Text = "";
    OPT_UpdateDataGridView(OPT_SELECT_ALL);
    OPT_GeneralInformation();
}

/*
 * OPT_dataGridView_CellDoubleClick()
 * Open OPT InfoPage when double click a row
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::OPT_dataGridView_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    OPTInfoPage^ page = gcnew OPTInfoPage(Convert::ToInt32(OPT_dataGridView->CurrentRow->Cells[0]->Value), _pui);
    page->ShowDialog();
    OPT_UpdateDataGridView(OPT_SELECT_ALL);
    OPT_GeneralInformation();
}

/*
 * OPT_btn_New_Click()
 * Open OPT AddPage for adding new OPT file
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::OPT_btn_New_Click(System::Object^ sender, System::EventArgs^ e) {
    OPTAddPage^ page = gcnew OPTAddPage(_pui);
    page->ShowDialog();
    OPT_UpdateDataGridView(OPT_SELECT_ALL);
    OPT_GeneralInformation();
}

/*
 * OPT_GeneralInformation()
 * Provide total number of rows in DataGridView
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::OPT_GeneralInformation() {
    int^ count = OPT_dataGridView->RowCount;
    if (Convert::ToInt32(count) == 0) {
        OPT_lbl_Count->Text = "0";
    }
    else {
        OPT_lbl_Count->Text = Convert::ToString(OPT_dataGridView->RowCount - 1);
    }
}

/*
 * OPT_CheckAuth()
 * Check auth of current user
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::OPT_CheckAuth() {
    if (_Auth == PublicUserInfo::Auth::Level_1 || _Auth == PublicUserInfo::Auth::Level_2) {
        tsm_OPT->Visible = false;
        pan_OPT->Visible = false;
    }
}

/*
 *  System
 */

 /*
  *   tmsi_ChangeUserInfo_Click()
  *   Show change username/password page
  *   @param None
  *   @return None
  */
Void WeAlumni::MainWindow::tmsi_ChangeUserInfo_Click(System::Object^ sender, System::EventArgs^ e) {
    SysChangeUserInfoPage^ page = gcnew SysChangeUserInfoPage(_pui);
    page->ShowDialog();
}

/*
 *   tsmi_VersionInfo_Click()
 *   Show version information
 *   @param None
 *   @return None
 */
Void WeAlumni::MainWindow::tsmi_VersionInfo_Click(System::Object^ sender, System::EventArgs^ e) {
    SysInfoPage^ page = gcnew SysInfoPage();
    page->ShowDialog();
}

/*
 *
 *  Treasury
 *
 */

 /*
  * Tre_UpdateDataGridView()
  * Update DataGridView
  * @param None
  * @return None
  */
Void WeAlumni::MainWindow::Tre_UpdateDataGridView(String^ command) {
    BindingSource^ bSource = gcnew BindingSource();
    int status = -1;

    try {
        status = _TreDB->ReadDataAdapter(command);
    }
    catch (Exception^ exception) {
        tre_lbl_error->ForeColor = System::Drawing::Color::Red;
        tre_lbl_error->Text = exception->Message;
        tre_lbl_error->Visible = true;
        return;
    }

    if (status > 0) {
        tre_lbl_error->Visible = false;
        bSource->DataSource = _TreDB->dataTable;
        tre_dataGridView->DataSource = bSource;
    }
    else {
        tre_lbl_error->ForeColor = System::Drawing::Color::Red;
        tre_lbl_error->Text = "�޿ɲ�ѯ�Ĳ�����Ϣ";
        tre_lbl_error->Visible = true;
        tre_dataGridView->DataSource = nullptr;
    }
}

/*
 * Tre_btn_Search_Click()
 * Search data with provided info
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::Tre_btn_Search_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ TreId = tre_txt_treId->Text;
    String^ TreType = tre_cmb_type->Text;

    String^ command = "SELECT Treasury.Id AS '������', " +
        "Treasury.StfName AS '��Ա����', " +
        "Treasury.Time AS '�Ǽ�ʱ��', " +
        "Treasury.type AS '����', " +
        "Treasury.Amount AS '���', " +
        "Treasury.Comment AS '��ע' " +
        "FROM Treasury WHERE ";
    String^ command2 = "";

    std::vector<int> vec;
    if (TreId->Length)         vec.push_back(0);
    if (TreType->Length)        vec.push_back(1);
    if (vec.size() == 0) {
        Tre_CheckAuth();
        Tre_GeneralInformation();
        return;
    }

    bool flag = false;
    for (auto i : vec) {
        if (vec.size() != 1 && flag) command2 += " AND ";
        switch (i) {
        case 0: command2 += "Treasury.Id = '" + TreId + "' "; break;
        case 1: command2 += "Treasury.type = '" + TreType + "' "; break;
        }
        flag = true;
    }

    if (!_Auth.Equals(PublicUserInfo::Auth::Level_5)) {
        command2 += " AND Treasury.StfId = " + Convert::ToString(_pui->GetId());
    }
    command += command2 + " ORDER BY Treasury.Id ASC;";

    Tre_UpdateDataGridView(command);
    Tre_GeneralInformation();
}

/*
 * Tre_btn_Clear_Click()
 * Reset all textboxs and DataGridView
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::Tre_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e) {
    tre_txt_treId->Text = "";
    tre_cmb_type->Text = "";
    Tre_CheckAuth();
    Tre_GeneralInformation();
}

/*
 * Tre_dataGridView_CellDoubleClick()
 * Open Treasury InfoPage when double click a row
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::Tre_dataGridView_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

    TreInfoPage^ page = gcnew TreInfoPage(_pui, Convert::ToInt32(tre_dataGridView->CurrentRow->Cells[0]->Value));
    page->ShowDialog();
    Tre_CheckAuth();
    Tre_GeneralInformation();

}

/*
 * Tre_btn_New_Click()
 * Open OPT AddPage for adding new Treasury record
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::Tre_btn_New_Click(System::Object^ sender, System::EventArgs^ e) {
    TreAddPage^ page = gcnew TreAddPage(_pui);
    page->ShowDialog();
    Tre_CheckAuth();
    Tre_GeneralInformation();

}

/*
 * Tre_GeneralInformation()
 * Provide total number of rows in DataGridView
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::Tre_GeneralInformation() {
    int^ count = tre_dataGridView->RowCount;
    if (Convert::ToInt32(count) == 0) {
        tre_lbl_count->Text = "0";
    }
    else {
        tre_lbl_count->Text = Convert::ToString(tre_dataGridView->RowCount - 1);
    }
}

/*
 * Tre_CheckAuth
 * Show Data Depend on Authority
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::Tre_CheckAuth() {
    if (_Auth.Equals(PublicUserInfo::Auth::Level_5)) {
        Tre_UpdateDataGridView(TRE_LEVEL5);
    }
    else {
        String^ cmd = TRE_Normal + Convert::ToString(_pui->GetId()) + " ORDER BY Treasury.Id ASC;";
        Tre_UpdateDataGridView(cmd);
    }
}


/*
 * Tre_CheckDB()
 * Check threasury Data base
 * @param None
 * @return None
 */
void WeAlumni::MainWindow::Tre_CheckDB() {
    if (DatabasePrecheck::TrePrecheck()) {
        _TreDB = gcnew Database(Database::DatabaseType::Treasury);
        Tre_CheckAuth();
    }
    else {
        tre_lbl_error->Text = "�����޷���ȡ���ݿ⣬�����µ������ݿ���˳�.";
        tre_lbl_error->ForeColor = System::Drawing::Color::Red;

    }
}

/*
 * My Info
 */
void WeAlumni::MainWindow::min_EnableChange() {
    min_lbl_warning->Visible = false;
    min_btn_accept->Visible = true;
    min_btn_cancel->Visible = true;
    min_txt_address1->ReadOnly = false;
    min_txt_address2->ReadOnly = false;
    min_txt_city->ReadOnly = false;
    min_txt_country->ReadOnly = false;
    min_txt_degree->ReadOnly = false;
    min_txt_email->ReadOnly = false;
    min_txt_endtime->ReadOnly = false;
    min_txt_major1->ReadOnly = false;
    min_txt_major2->ReadOnly = false;
    min_txt_phone->ReadOnly = false;
    min_txt_postal->ReadOnly = false;
    min_txt_program->ReadOnly = false;
    min_txt_stdId->ReadOnly = false;
    min_txt_wechat->ReadOnly = false;
}

void WeAlumni::MainWindow::min_DisableChange() {
    min_btn_accept->Visible = false;
    min_btn_cancel->Visible = false;
    min_txt_address1->ReadOnly = true;
    min_txt_address2->ReadOnly = true;
    min_txt_city->ReadOnly = true;
    min_txt_country->ReadOnly = true;
    min_txt_degree->ReadOnly = true;
    min_txt_email->ReadOnly = true;
    min_txt_endtime->ReadOnly = true;
    min_txt_major1->ReadOnly = true;
    min_txt_major2->ReadOnly = true;
    min_txt_phone->ReadOnly = true;
    min_txt_postal->ReadOnly = true;
    min_txt_program->ReadOnly = true;
    min_txt_stdId->ReadOnly = true;
    min_txt_wechat->ReadOnly = true;
}

void WeAlumni::MainWindow::min_GeneralInformation() {
    String^ command = "SELECT * FROM Member, Staff " +
        "WHERE Member.Id = " + _pui->GetId() + " AND Staff.MemId = Member.Id";
    try {
        database->ReadData(command);
    }
    catch (Exception^) {
        min_lbl_warning->Text = "�޷���ȡ�û�����";
        min_btn_changeInfo->Enabled = false;
        return;
    }
    min_lbl_Id->Text = Convert::ToString(_pui->GetId());
    min_lbl_name->Text = _pui->GetName();
    min_lbl_auth->Text = _pui->GetAuthName();
    min_lbl_dept->Text = database->dataReader[25]->ToString();
    min_lbl_position->Text = database->dataReader[26]->ToString();
    min_lbl_gender->Text = database->dataReader[4]->ToString();
    min_lbl_birth->Text = database->dataReader[5]->ToString();
    min_txt_address1->Text = database->dataReader[10]->ToString();
    min_txt_address2->Text = database->dataReader[11]->ToString();
    min_txt_city->Text = database->dataReader[12]->ToString();
    min_txt_country->Text = database->dataReader[9]->ToString();
    min_txt_degree->Text = database->dataReader[17]->ToString();
    min_txt_email->Text = database->dataReader[6]->ToString();
    min_txt_endtime->Text = database->dataReader[16]->ToString();
    min_txt_major1->Text = database->dataReader[18]->ToString();
    min_txt_major2->Text = database->dataReader[19]->ToString();
    min_txt_phone->Text = database->dataReader[7]->ToString();
    min_txt_postal->Text = database->dataReader[13]->ToString();
    min_txt_program->Text = database->dataReader[15]->ToString();
    min_txt_stdId->Text = database->dataReader[14]->ToString();
    min_txt_wechat->Text = database->dataReader[8]->ToString();
}

Void WeAlumni::MainWindow::min_btn_accept_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ command = "UPDATE Member " +
        "SET Email = '" + min_txt_email->Text +
        "',Phone = '" + min_txt_phone->Text +
        "',Wechat= '" + min_txt_wechat->Text +
        "',Country= '" + min_txt_country->Text +
        "',Address1= '" + min_txt_address1->Text +
        "',Address2= '" + min_txt_address2->Text +
        "',City= '" + min_txt_city->Text +
        "',Postal= '" + min_txt_postal->Text +
        "',StdId= '" + min_txt_stdId->Text +
        "',Program= '" + min_txt_program->Text +
        "',EndDate= '" + min_txt_endtime->Text +
        "',Degree= '" + min_txt_degree->Text +
        "',Major1= '" + min_txt_major1->Text +
        "',Major2= '" + min_txt_major2->Text +
        "' WHERE Id = " + _pui->GetId();
    try {
        database->UpdateData(command);
    }
    catch (Exception^ e) {
        min_lbl_warning->Visible = true;
        min_lbl_warning->ForeColor = Color::Red;
        min_lbl_warning->Text = e->Message;//"��������ʧ�ܣ�";
        min_DisableChange();
        min_btn_changeInfo->Enabled = false;
        min_GeneralInformation();
        return;
    }
}

Void WeAlumni::MainWindow::min_btn_cancel_Click(System::Object^ sender, System::EventArgs^ e) {
    min_DisableChange();
    min_GeneralInformation();
}

Void WeAlumni::MainWindow::min_btn_changeInfo_Click(System::Object^ sender, System::EventArgs^ e) {
    min_EnableChange();
}