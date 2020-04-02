#pragma once
#include "Database.h"

/*
 * MemInfoPage.h
 *
 * This file have basic Member Information page interaction actions.
 *
 * @author: Jiaying Hou
 * Revised: 3/26/20
 *
 */

namespace WeAlumni {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MemInfoPage
	/// </summary>
	public ref class MemInfoPage : public System::Windows::Forms::Form
	{
	public:
		MemInfoPage(int inputMemId)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			_id = inputMemId;
			try {
				database = gcnew Database(Database::DatabaseType::Data);
				Initialize();
			}
			catch (System::Exception^ exception) {
				lbl_error->Text = exception->Message;
				lbl_error->ForeColor = System::Drawing::Color::Red;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MemInfoPage()
		{
			if (components)
			{
				delete components;
			}
			if (database) {
				database->~Database();
			}
		}
	private: System::Windows::Forms::Label^ lbl_Prompt_PgTitle;
	private: System::Windows::Forms::Label^ lbl_Prompt_Id;
	private: System::Windows::Forms::Label^ lbl_Prompt_Status;
	private: System::Windows::Forms::TextBox^ txt_Status;
	private: System::Windows::Forms::Label^ lbl_Prompt_Type;
	private: System::Windows::Forms::TextBox^ txt_Type;
	private: System::Windows::Forms::Label^ lbl_Prompt_Name;
	private: System::Windows::Forms::TextBox^ txt_Name;
	private: System::Windows::Forms::Label^ lbl_Prompt_Gender;
	private: System::Windows::Forms::TextBox^ txt_Gender;
	private: System::Windows::Forms::Label^ lbl_Prompt_Birth;
	private: System::Windows::Forms::TextBox^ txt_Birth;
	private: System::Windows::Forms::Label^ lbl_Prompt_Email;
	private: System::Windows::Forms::TextBox^ txt_Email;
	private: System::Windows::Forms::Label^ lbl_Prompt_Phone;
	private: System::Windows::Forms::TextBox^ txt_Phone;
	private: System::Windows::Forms::Label^ lbl_Prompt_Wechat;
	private: System::Windows::Forms::TextBox^ txt_Wechat;
	private: System::Windows::Forms::Label^ lbl_Prompt_Country;
	private: System::Windows::Forms::TextBox^ txt_Country;
	private: System::Windows::Forms::Label^ lbl_Prompt_Address1;
	private: System::Windows::Forms::TextBox^ txt_Address1;
	private: System::Windows::Forms::Label^ lbl_Prompt_Address2;
	private: System::Windows::Forms::TextBox^ txt_Address2;
	private: System::Windows::Forms::Label^ lbl_Prompt_City;
	private: System::Windows::Forms::TextBox^ txt_City;
	private: System::Windows::Forms::Label^ lbl_Prompt_Postal;
	private: System::Windows::Forms::TextBox^ txt_Postal;
	private: System::Windows::Forms::Label^ lbl_Prompt_StdId;
	private: System::Windows::Forms::TextBox^ txt_StdId;
	private: System::Windows::Forms::Label^ lbl_Prompt_Program;
	private: System::Windows::Forms::TextBox^ txt_Program;
	private: System::Windows::Forms::Label^ lbl_Prompt_EndDate;
	private: System::Windows::Forms::TextBox^ txt_EndDate;
	private: System::Windows::Forms::Label^ lbl_Prompt_Degree;
	private: System::Windows::Forms::TextBox^ txt_Degree;
	private: System::Windows::Forms::Label^ lbl_Prompt_Major1;
	private: System::Windows::Forms::TextBox^ txt_Major1;
	private: System::Windows::Forms::Label^ lbl_Prompt_Major2;
	private: System::Windows::Forms::TextBox^ txt_Major2;
	private: System::Windows::Forms::Label^ lbl_Prompt_CareerStatus;
	private: System::Windows::Forms::TextBox^ txt_CareerStatus;
	private: System::Windows::Forms::Label^ lbl_Prompt_Company;
	private: System::Windows::Forms::TextBox^ txt_Company;
	private: System::Windows::Forms::Label^ lbl_Prompt_Position;
	private: System::Windows::Forms::TextBox^ txt_Position;
	private: System::Windows::Forms::Label^ lbl_Prompt_SearchAuth;
	private: System::Windows::Forms::TextBox^ txt_SearchAuth;
	private: System::Windows::Forms::Button^ btn_ChangeInfo;
	private: System::Windows::Forms::Label^ lbl_Id;
	private: System::Windows::Forms::Label^ lbl_Status;
	private: System::Windows::Forms::Label^ lbl_Type;
	private: System::Windows::Forms::Label^ lbl_Name;
	private: System::Windows::Forms::Label^ lbl_Gender;
	private: System::Windows::Forms::Label^ lbl_Birth;
	private: System::Windows::Forms::Label^ lbl_Email;
	private: System::Windows::Forms::Label^ lbl_Phone;
	private: System::Windows::Forms::Label^ lbl_Wechat;
	private: System::Windows::Forms::Label^ lbl_StdId;
	private: System::Windows::Forms::Label^ lbl_Country;
	private: System::Windows::Forms::Label^ lbl_Address1;
	private: System::Windows::Forms::Label^ lbl_Address2;
	private: System::Windows::Forms::Label^ lbl_City;
	private: System::Windows::Forms::Label^ lbl_Postal;
	private: System::Windows::Forms::Label^ lbl_Program;
	private: System::Windows::Forms::Label^ lbl_EndDate;
	private: System::Windows::Forms::Label^ lbl_Degree;
	private: System::Windows::Forms::Label^ lbl_Major1;
	private: System::Windows::Forms::Label^ lbl_Major2;
	private: System::Windows::Forms::Label^ lbl_CareerStatus;
	private: System::Windows::Forms::Label^ lbl_Company;
	private: System::Windows::Forms::Label^ lbl_Position;
	private: System::Windows::Forms::Label^ lbl_SearchAuth;
	private: System::Windows::Forms::Button^ btn_Delete;
	private: System::Windows::Forms::Label^ lbl_error;
	private: System::Windows::Forms::Button^ btn_ShwPrcssActn;
	private: System::Windows::Forms::Button^ btn_DeleteAccept;
	private: System::Windows::Forms::Button^ btn_DeleteCancel;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btn_ChangeInfoAccept;
	private: System::Windows::Forms::Button^ btn_ChangeInfoCancel;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbl_Prompt_PgTitle = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Id = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Status = (gcnew System::Windows::Forms::Label());
			this->txt_Status = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Type = (gcnew System::Windows::Forms::Label());
			this->txt_Type = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Name = (gcnew System::Windows::Forms::Label());
			this->txt_Name = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Gender = (gcnew System::Windows::Forms::Label());
			this->txt_Gender = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Birth = (gcnew System::Windows::Forms::Label());
			this->txt_Birth = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Email = (gcnew System::Windows::Forms::Label());
			this->txt_Email = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Phone = (gcnew System::Windows::Forms::Label());
			this->txt_Phone = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Wechat = (gcnew System::Windows::Forms::Label());
			this->txt_Wechat = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Country = (gcnew System::Windows::Forms::Label());
			this->txt_Country = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Address1 = (gcnew System::Windows::Forms::Label());
			this->txt_Address1 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Address2 = (gcnew System::Windows::Forms::Label());
			this->txt_Address2 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_City = (gcnew System::Windows::Forms::Label());
			this->txt_City = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Postal = (gcnew System::Windows::Forms::Label());
			this->txt_Postal = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_StdId = (gcnew System::Windows::Forms::Label());
			this->txt_StdId = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Program = (gcnew System::Windows::Forms::Label());
			this->txt_Program = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_EndDate = (gcnew System::Windows::Forms::Label());
			this->txt_EndDate = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Degree = (gcnew System::Windows::Forms::Label());
			this->txt_Degree = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Major1 = (gcnew System::Windows::Forms::Label());
			this->txt_Major1 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Major2 = (gcnew System::Windows::Forms::Label());
			this->txt_Major2 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_CareerStatus = (gcnew System::Windows::Forms::Label());
			this->txt_CareerStatus = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Company = (gcnew System::Windows::Forms::Label());
			this->txt_Company = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Position = (gcnew System::Windows::Forms::Label());
			this->txt_Position = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_SearchAuth = (gcnew System::Windows::Forms::Label());
			this->txt_SearchAuth = (gcnew System::Windows::Forms::TextBox());
			this->btn_ChangeInfo = (gcnew System::Windows::Forms::Button());
			this->lbl_Id = (gcnew System::Windows::Forms::Label());
			this->lbl_Status = (gcnew System::Windows::Forms::Label());
			this->lbl_Type = (gcnew System::Windows::Forms::Label());
			this->lbl_Name = (gcnew System::Windows::Forms::Label());
			this->lbl_Gender = (gcnew System::Windows::Forms::Label());
			this->lbl_Birth = (gcnew System::Windows::Forms::Label());
			this->lbl_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_Phone = (gcnew System::Windows::Forms::Label());
			this->lbl_Wechat = (gcnew System::Windows::Forms::Label());
			this->lbl_StdId = (gcnew System::Windows::Forms::Label());
			this->lbl_Country = (gcnew System::Windows::Forms::Label());
			this->lbl_Address1 = (gcnew System::Windows::Forms::Label());
			this->lbl_Address2 = (gcnew System::Windows::Forms::Label());
			this->lbl_City = (gcnew System::Windows::Forms::Label());
			this->lbl_Postal = (gcnew System::Windows::Forms::Label());
			this->lbl_Program = (gcnew System::Windows::Forms::Label());
			this->lbl_EndDate = (gcnew System::Windows::Forms::Label());
			this->lbl_Degree = (gcnew System::Windows::Forms::Label());
			this->lbl_Major1 = (gcnew System::Windows::Forms::Label());
			this->lbl_Major2 = (gcnew System::Windows::Forms::Label());
			this->lbl_CareerStatus = (gcnew System::Windows::Forms::Label());
			this->lbl_Company = (gcnew System::Windows::Forms::Label());
			this->lbl_Position = (gcnew System::Windows::Forms::Label());
			this->lbl_SearchAuth = (gcnew System::Windows::Forms::Label());
			this->btn_Delete = (gcnew System::Windows::Forms::Button());
			this->lbl_error = (gcnew System::Windows::Forms::Label());
			this->btn_ShwPrcssActn = (gcnew System::Windows::Forms::Button());
			this->btn_DeleteAccept = (gcnew System::Windows::Forms::Button());
			this->btn_DeleteCancel = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btn_ChangeInfoAccept = (gcnew System::Windows::Forms::Button());
			this->btn_ChangeInfoCancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_Prompt_PgTitle
			// 
			this->lbl_Prompt_PgTitle->AutoSize = true;
			this->lbl_Prompt_PgTitle->Location = System::Drawing::Point(317, 9);
			this->lbl_Prompt_PgTitle->Name = L"lbl_Prompt_PgTitle";
			this->lbl_Prompt_PgTitle->Size = System::Drawing::Size(128, 13);
			this->lbl_Prompt_PgTitle->TabIndex = 0;
			this->lbl_Prompt_PgTitle->Text = L"Member Information Page";
			// 
			// lbl_Prompt_Id
			// 
			this->lbl_Prompt_Id->AutoSize = true;
			this->lbl_Prompt_Id->Location = System::Drawing::Point(32, 55);
			this->lbl_Prompt_Id->Name = L"lbl_Prompt_Id";
			this->lbl_Prompt_Id->Size = System::Drawing::Size(16, 13);
			this->lbl_Prompt_Id->TabIndex = 1;
			this->lbl_Prompt_Id->Text = L"Id";
			// 
			// lbl_Prompt_Status
			// 
			this->lbl_Prompt_Status->AutoSize = true;
			this->lbl_Prompt_Status->Location = System::Drawing::Point(186, 55);
			this->lbl_Prompt_Status->Name = L"lbl_Prompt_Status";
			this->lbl_Prompt_Status->Size = System::Drawing::Size(37, 13);
			this->lbl_Prompt_Status->TabIndex = 2;
			this->lbl_Prompt_Status->Text = L"Status";
			// 
			// txt_Status
			// 
			this->txt_Status->Location = System::Drawing::Point(229, 52);
			this->txt_Status->Name = L"txt_Status";
			this->txt_Status->Size = System::Drawing::Size(97, 20);
			this->txt_Status->TabIndex = 4;
			this->txt_Status->Visible = false;
			// 
			// lbl_Prompt_Type
			// 
			this->lbl_Prompt_Type->AutoSize = true;
			this->lbl_Prompt_Type->Location = System::Drawing::Point(355, 52);
			this->lbl_Prompt_Type->Name = L"lbl_Prompt_Type";
			this->lbl_Prompt_Type->Size = System::Drawing::Size(31, 13);
			this->lbl_Prompt_Type->TabIndex = 5;
			this->lbl_Prompt_Type->Text = L"Type";
			// 
			// txt_Type
			// 
			this->txt_Type->Location = System::Drawing::Point(389, 49);
			this->txt_Type->Name = L"txt_Type";
			this->txt_Type->Size = System::Drawing::Size(97, 20);
			this->txt_Type->TabIndex = 4;
			this->txt_Type->Visible = false;
			// 
			// lbl_Prompt_Name
			// 
			this->lbl_Prompt_Name->AutoSize = true;
			this->lbl_Prompt_Name->Location = System::Drawing::Point(504, 55);
			this->lbl_Prompt_Name->Name = L"lbl_Prompt_Name";
			this->lbl_Prompt_Name->Size = System::Drawing::Size(35, 13);
			this->lbl_Prompt_Name->TabIndex = 6;
			this->lbl_Prompt_Name->Text = L"Name";
			// 
			// txt_Name
			// 
			this->txt_Name->Location = System::Drawing::Point(545, 48);
			this->txt_Name->Name = L"txt_Name";
			this->txt_Name->Size = System::Drawing::Size(97, 20);
			this->txt_Name->TabIndex = 4;
			this->txt_Name->Visible = false;
			// 
			// lbl_Prompt_Gender
			// 
			this->lbl_Prompt_Gender->AutoSize = true;
			this->lbl_Prompt_Gender->Location = System::Drawing::Point(653, 55);
			this->lbl_Prompt_Gender->Name = L"lbl_Prompt_Gender";
			this->lbl_Prompt_Gender->Size = System::Drawing::Size(42, 13);
			this->lbl_Prompt_Gender->TabIndex = 7;
			this->lbl_Prompt_Gender->Text = L"Gender";
			// 
			// txt_Gender
			// 
			this->txt_Gender->Location = System::Drawing::Point(696, 49);
			this->txt_Gender->Name = L"txt_Gender";
			this->txt_Gender->Size = System::Drawing::Size(63, 20);
			this->txt_Gender->TabIndex = 4;
			this->txt_Gender->Visible = false;
			// 
			// lbl_Prompt_Birth
			// 
			this->lbl_Prompt_Birth->AutoSize = true;
			this->lbl_Prompt_Birth->Location = System::Drawing::Point(32, 101);
			this->lbl_Prompt_Birth->Name = L"lbl_Prompt_Birth";
			this->lbl_Prompt_Birth->Size = System::Drawing::Size(28, 13);
			this->lbl_Prompt_Birth->TabIndex = 8;
			this->lbl_Prompt_Birth->Text = L"Birth";
			// 
			// txt_Birth
			// 
			this->txt_Birth->Location = System::Drawing::Point(66, 98);
			this->txt_Birth->Name = L"txt_Birth";
			this->txt_Birth->Size = System::Drawing::Size(97, 20);
			this->txt_Birth->TabIndex = 4;
			this->txt_Birth->Visible = false;
			// 
			// lbl_Prompt_Email
			// 
			this->lbl_Prompt_Email->AutoSize = true;
			this->lbl_Prompt_Email->Location = System::Drawing::Point(191, 101);
			this->lbl_Prompt_Email->Name = L"lbl_Prompt_Email";
			this->lbl_Prompt_Email->Size = System::Drawing::Size(32, 13);
			this->lbl_Prompt_Email->TabIndex = 9;
			this->lbl_Prompt_Email->Text = L"Email";
			// 
			// txt_Email
			// 
			this->txt_Email->Location = System::Drawing::Point(232, 98);
			this->txt_Email->Name = L"txt_Email";
			this->txt_Email->Size = System::Drawing::Size(97, 20);
			this->txt_Email->TabIndex = 4;
			this->txt_Email->Visible = false;
			// 
			// lbl_Prompt_Phone
			// 
			this->lbl_Prompt_Phone->AutoSize = true;
			this->lbl_Prompt_Phone->Location = System::Drawing::Point(348, 101);
			this->lbl_Prompt_Phone->Name = L"lbl_Prompt_Phone";
			this->lbl_Prompt_Phone->Size = System::Drawing::Size(38, 13);
			this->lbl_Prompt_Phone->TabIndex = 10;
			this->lbl_Prompt_Phone->Text = L"Phone";
			// 
			// txt_Phone
			// 
			this->txt_Phone->Location = System::Drawing::Point(389, 98);
			this->txt_Phone->Name = L"txt_Phone";
			this->txt_Phone->Size = System::Drawing::Size(97, 20);
			this->txt_Phone->TabIndex = 4;
			this->txt_Phone->Visible = false;
			// 
			// lbl_Prompt_Wechat
			// 
			this->lbl_Prompt_Wechat->AutoSize = true;
			this->lbl_Prompt_Wechat->Location = System::Drawing::Point(494, 101);
			this->lbl_Prompt_Wechat->Name = L"lbl_Prompt_Wechat";
			this->lbl_Prompt_Wechat->Size = System::Drawing::Size(45, 13);
			this->lbl_Prompt_Wechat->TabIndex = 11;
			this->lbl_Prompt_Wechat->Text = L"Wechat";
			// 
			// txt_Wechat
			// 
			this->txt_Wechat->Location = System::Drawing::Point(545, 98);
			this->txt_Wechat->Name = L"txt_Wechat";
			this->txt_Wechat->Size = System::Drawing::Size(97, 20);
			this->txt_Wechat->TabIndex = 4;
			this->txt_Wechat->Visible = false;
			// 
			// lbl_Prompt_Country
			// 
			this->lbl_Prompt_Country->AutoSize = true;
			this->lbl_Prompt_Country->Location = System::Drawing::Point(17, 140);
			this->lbl_Prompt_Country->Name = L"lbl_Prompt_Country";
			this->lbl_Prompt_Country->Size = System::Drawing::Size(43, 13);
			this->lbl_Prompt_Country->TabIndex = 12;
			this->lbl_Prompt_Country->Text = L"Country";
			// 
			// txt_Country
			// 
			this->txt_Country->Location = System::Drawing::Point(66, 137);
			this->txt_Country->Name = L"txt_Country";
			this->txt_Country->Size = System::Drawing::Size(97, 20);
			this->txt_Country->TabIndex = 4;
			this->txt_Country->Visible = false;
			// 
			// lbl_Prompt_Address1
			// 
			this->lbl_Prompt_Address1->AutoSize = true;
			this->lbl_Prompt_Address1->Location = System::Drawing::Point(172, 140);
			this->lbl_Prompt_Address1->Name = L"lbl_Prompt_Address1";
			this->lbl_Prompt_Address1->Size = System::Drawing::Size(51, 13);
			this->lbl_Prompt_Address1->TabIndex = 17;
			this->lbl_Prompt_Address1->Text = L"Address1";
			// 
			// txt_Address1
			// 
			this->txt_Address1->Location = System::Drawing::Point(229, 137);
			this->txt_Address1->Name = L"txt_Address1";
			this->txt_Address1->Size = System::Drawing::Size(97, 20);
			this->txt_Address1->TabIndex = 4;
			this->txt_Address1->Visible = false;
			// 
			// lbl_Prompt_Address2
			// 
			this->lbl_Prompt_Address2->AutoSize = true;
			this->lbl_Prompt_Address2->Location = System::Drawing::Point(335, 140);
			this->lbl_Prompt_Address2->Name = L"lbl_Prompt_Address2";
			this->lbl_Prompt_Address2->Size = System::Drawing::Size(51, 13);
			this->lbl_Prompt_Address2->TabIndex = 16;
			this->lbl_Prompt_Address2->Text = L"Address2";
			// 
			// txt_Address2
			// 
			this->txt_Address2->Location = System::Drawing::Point(389, 137);
			this->txt_Address2->Name = L"txt_Address2";
			this->txt_Address2->Size = System::Drawing::Size(97, 20);
			this->txt_Address2->TabIndex = 4;
			this->txt_Address2->Visible = false;
			// 
			// lbl_Prompt_City
			// 
			this->lbl_Prompt_City->AutoSize = true;
			this->lbl_Prompt_City->Location = System::Drawing::Point(515, 140);
			this->lbl_Prompt_City->Name = L"lbl_Prompt_City";
			this->lbl_Prompt_City->Size = System::Drawing::Size(24, 13);
			this->lbl_Prompt_City->TabIndex = 15;
			this->lbl_Prompt_City->Text = L"City";
			// 
			// txt_City
			// 
			this->txt_City->Location = System::Drawing::Point(545, 137);
			this->txt_City->Name = L"txt_City";
			this->txt_City->Size = System::Drawing::Size(97, 20);
			this->txt_City->TabIndex = 4;
			this->txt_City->Visible = false;
			// 
			// lbl_Prompt_Postal
			// 
			this->lbl_Prompt_Postal->AutoSize = true;
			this->lbl_Prompt_Postal->Location = System::Drawing::Point(653, 140);
			this->lbl_Prompt_Postal->Name = L"lbl_Prompt_Postal";
			this->lbl_Prompt_Postal->Size = System::Drawing::Size(36, 13);
			this->lbl_Prompt_Postal->TabIndex = 14;
			this->lbl_Prompt_Postal->Text = L"Postal";
			// 
			// txt_Postal
			// 
			this->txt_Postal->Location = System::Drawing::Point(686, 137);
			this->txt_Postal->Name = L"txt_Postal";
			this->txt_Postal->Size = System::Drawing::Size(97, 20);
			this->txt_Postal->TabIndex = 4;
			this->txt_Postal->Visible = false;
			// 
			// lbl_Prompt_StdId
			// 
			this->lbl_Prompt_StdId->AutoSize = true;
			this->lbl_Prompt_StdId->Location = System::Drawing::Point(648, 101);
			this->lbl_Prompt_StdId->Name = L"lbl_Prompt_StdId";
			this->lbl_Prompt_StdId->Size = System::Drawing::Size(32, 13);
			this->lbl_Prompt_StdId->TabIndex = 13;
			this->lbl_Prompt_StdId->Text = L"StdId";
			// 
			// txt_StdId
			// 
			this->txt_StdId->Location = System::Drawing::Point(686, 98);
			this->txt_StdId->Name = L"txt_StdId";
			this->txt_StdId->Size = System::Drawing::Size(97, 20);
			this->txt_StdId->TabIndex = 4;
			this->txt_StdId->Visible = false;
			// 
			// lbl_Prompt_Program
			// 
			this->lbl_Prompt_Program->AutoSize = true;
			this->lbl_Prompt_Program->Location = System::Drawing::Point(17, 174);
			this->lbl_Prompt_Program->Name = L"lbl_Prompt_Program";
			this->lbl_Prompt_Program->Size = System::Drawing::Size(46, 13);
			this->lbl_Prompt_Program->TabIndex = 22;
			this->lbl_Prompt_Program->Text = L"Program";
			// 
			// txt_Program
			// 
			this->txt_Program->Location = System::Drawing::Point(66, 171);
			this->txt_Program->Name = L"txt_Program";
			this->txt_Program->Size = System::Drawing::Size(97, 20);
			this->txt_Program->TabIndex = 4;
			this->txt_Program->Visible = false;
			// 
			// lbl_Prompt_EndDate
			// 
			this->lbl_Prompt_EndDate->AutoSize = true;
			this->lbl_Prompt_EndDate->Location = System::Drawing::Point(174, 177);
			this->lbl_Prompt_EndDate->Name = L"lbl_Prompt_EndDate";
			this->lbl_Prompt_EndDate->Size = System::Drawing::Size(49, 13);
			this->lbl_Prompt_EndDate->TabIndex = 21;
			this->lbl_Prompt_EndDate->Text = L"EndDate";
			// 
			// txt_EndDate
			// 
			this->txt_EndDate->Location = System::Drawing::Point(229, 174);
			this->txt_EndDate->Name = L"txt_EndDate";
			this->txt_EndDate->Size = System::Drawing::Size(97, 20);
			this->txt_EndDate->TabIndex = 4;
			this->txt_EndDate->Visible = false;
			// 
			// lbl_Prompt_Degree
			// 
			this->lbl_Prompt_Degree->AutoSize = true;
			this->lbl_Prompt_Degree->Location = System::Drawing::Point(344, 177);
			this->lbl_Prompt_Degree->Name = L"lbl_Prompt_Degree";
			this->lbl_Prompt_Degree->Size = System::Drawing::Size(42, 13);
			this->lbl_Prompt_Degree->TabIndex = 20;
			this->lbl_Prompt_Degree->Text = L"Degree";
			// 
			// txt_Degree
			// 
			this->txt_Degree->Location = System::Drawing::Point(389, 174);
			this->txt_Degree->Name = L"txt_Degree";
			this->txt_Degree->Size = System::Drawing::Size(97, 20);
			this->txt_Degree->TabIndex = 4;
			this->txt_Degree->Visible = false;
			// 
			// lbl_Prompt_Major1
			// 
			this->lbl_Prompt_Major1->AutoSize = true;
			this->lbl_Prompt_Major1->Location = System::Drawing::Point(504, 177);
			this->lbl_Prompt_Major1->Name = L"lbl_Prompt_Major1";
			this->lbl_Prompt_Major1->Size = System::Drawing::Size(39, 13);
			this->lbl_Prompt_Major1->TabIndex = 19;
			this->lbl_Prompt_Major1->Text = L"Major1";
			// 
			// txt_Major1
			// 
			this->txt_Major1->Location = System::Drawing::Point(545, 174);
			this->txt_Major1->Name = L"txt_Major1";
			this->txt_Major1->Size = System::Drawing::Size(97, 20);
			this->txt_Major1->TabIndex = 4;
			this->txt_Major1->Visible = false;
			// 
			// lbl_Prompt_Major2
			// 
			this->lbl_Prompt_Major2->AutoSize = true;
			this->lbl_Prompt_Major2->Location = System::Drawing::Point(648, 174);
			this->lbl_Prompt_Major2->Name = L"lbl_Prompt_Major2";
			this->lbl_Prompt_Major2->Size = System::Drawing::Size(39, 13);
			this->lbl_Prompt_Major2->TabIndex = 18;
			this->lbl_Prompt_Major2->Text = L"Major2";
			// 
			// txt_Major2
			// 
			this->txt_Major2->Location = System::Drawing::Point(686, 177);
			this->txt_Major2->Name = L"txt_Major2";
			this->txt_Major2->Size = System::Drawing::Size(97, 20);
			this->txt_Major2->TabIndex = 4;
			this->txt_Major2->Visible = false;
			// 
			// lbl_Prompt_CareerStatus
			// 
			this->lbl_Prompt_CareerStatus->AutoSize = true;
			this->lbl_Prompt_CareerStatus->Location = System::Drawing::Point(12, 212);
			this->lbl_Prompt_CareerStatus->Name = L"lbl_Prompt_CareerStatus";
			this->lbl_Prompt_CareerStatus->Size = System::Drawing::Size(71, 13);
			this->lbl_Prompt_CareerStatus->TabIndex = 26;
			this->lbl_Prompt_CareerStatus->Text = L"Career Status";
			// 
			// txt_CareerStatus
			// 
			this->txt_CareerStatus->Location = System::Drawing::Point(89, 209);
			this->txt_CareerStatus->Name = L"txt_CareerStatus";
			this->txt_CareerStatus->Size = System::Drawing::Size(97, 20);
			this->txt_CareerStatus->TabIndex = 4;
			this->txt_CareerStatus->Visible = false;
			// 
			// lbl_Prompt_Company
			// 
			this->lbl_Prompt_Company->AutoSize = true;
			this->lbl_Prompt_Company->Location = System::Drawing::Point(199, 212);
			this->lbl_Prompt_Company->Name = L"lbl_Prompt_Company";
			this->lbl_Prompt_Company->Size = System::Drawing::Size(51, 13);
			this->lbl_Prompt_Company->TabIndex = 25;
			this->lbl_Prompt_Company->Text = L"Company";
			// 
			// txt_Company
			// 
			this->txt_Company->Location = System::Drawing::Point(256, 209);
			this->txt_Company->Name = L"txt_Company";
			this->txt_Company->Size = System::Drawing::Size(97, 20);
			this->txt_Company->TabIndex = 4;
			this->txt_Company->Visible = false;
			// 
			// lbl_Prompt_Position
			// 
			this->lbl_Prompt_Position->AutoSize = true;
			this->lbl_Prompt_Position->Location = System::Drawing::Point(376, 209);
			this->lbl_Prompt_Position->Name = L"lbl_Prompt_Position";
			this->lbl_Prompt_Position->Size = System::Drawing::Size(44, 13);
			this->lbl_Prompt_Position->TabIndex = 24;
			this->lbl_Prompt_Position->Text = L"Position";
			// 
			// txt_Position
			// 
			this->txt_Position->Location = System::Drawing::Point(426, 206);
			this->txt_Position->Name = L"txt_Position";
			this->txt_Position->Size = System::Drawing::Size(97, 20);
			this->txt_Position->TabIndex = 4;
			this->txt_Position->Visible = false;
			// 
			// lbl_Prompt_SearchAuth
			// 
			this->lbl_Prompt_SearchAuth->AutoSize = true;
			this->lbl_Prompt_SearchAuth->Location = System::Drawing::Point(542, 205);
			this->lbl_Prompt_SearchAuth->Name = L"lbl_Prompt_SearchAuth";
			this->lbl_Prompt_SearchAuth->Size = System::Drawing::Size(63, 13);
			this->lbl_Prompt_SearchAuth->TabIndex = 23;
			this->lbl_Prompt_SearchAuth->Text = L"SearchAuth";
			// 
			// txt_SearchAuth
			// 
			this->txt_SearchAuth->Location = System::Drawing::Point(611, 205);
			this->txt_SearchAuth->Name = L"txt_SearchAuth";
			this->txt_SearchAuth->Size = System::Drawing::Size(97, 20);
			this->txt_SearchAuth->TabIndex = 4;
			this->txt_SearchAuth->Visible = false;
			// 
			// btn_ChangeInfo
			// 
			this->btn_ChangeInfo->Location = System::Drawing::Point(667, 262);
			this->btn_ChangeInfo->Name = L"btn_ChangeInfo";
			this->btn_ChangeInfo->Size = System::Drawing::Size(67, 62);
			this->btn_ChangeInfo->TabIndex = 27;
			this->btn_ChangeInfo->Text = L"Change Info";
			this->btn_ChangeInfo->UseVisualStyleBackColor = true;
			this->btn_ChangeInfo->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_ChangeInfo_Click);
			// 
			// lbl_Id
			// 
			this->lbl_Id->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Id->AutoSize = true;
			this->lbl_Id->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbl_Id->Location = System::Drawing::Point(69, 55);
			this->lbl_Id->Name = L"lbl_Id";
			this->lbl_Id->Size = System::Drawing::Size(10, 13);
			this->lbl_Id->TabIndex = 29;
			this->lbl_Id->Text = L"-";
			// 
			// lbl_Status
			// 
			this->lbl_Status->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Status->AutoSize = true;
			this->lbl_Status->Location = System::Drawing::Point(229, 55);
			this->lbl_Status->Name = L"lbl_Status";
			this->lbl_Status->Size = System::Drawing::Size(10, 13);
			this->lbl_Status->TabIndex = 30;
			this->lbl_Status->Text = L"-";
			// 
			// lbl_Type
			// 
			this->lbl_Type->AutoSize = true;
			this->lbl_Type->Location = System::Drawing::Point(392, 55);
			this->lbl_Type->Name = L"lbl_Type";
			this->lbl_Type->Size = System::Drawing::Size(10, 13);
			this->lbl_Type->TabIndex = 32;
			this->lbl_Type->Text = L"-";
			// 
			// lbl_Name
			// 
			this->lbl_Name->AutoSize = true;
			this->lbl_Name->Location = System::Drawing::Point(545, 55);
			this->lbl_Name->Name = L"lbl_Name";
			this->lbl_Name->Size = System::Drawing::Size(10, 13);
			this->lbl_Name->TabIndex = 31;
			this->lbl_Name->Text = L"-";
			// 
			// lbl_Gender
			// 
			this->lbl_Gender->AutoSize = true;
			this->lbl_Gender->Location = System::Drawing::Point(701, 55);
			this->lbl_Gender->Name = L"lbl_Gender";
			this->lbl_Gender->Size = System::Drawing::Size(10, 13);
			this->lbl_Gender->TabIndex = 34;
			this->lbl_Gender->Text = L"-";
			// 
			// lbl_Birth
			// 
			this->lbl_Birth->AutoSize = true;
			this->lbl_Birth->Location = System::Drawing::Point(69, 101);
			this->lbl_Birth->Name = L"lbl_Birth";
			this->lbl_Birth->Size = System::Drawing::Size(10, 13);
			this->lbl_Birth->TabIndex = 33;
			this->lbl_Birth->Text = L"-";
			// 
			// lbl_Email
			// 
			this->lbl_Email->AutoSize = true;
			this->lbl_Email->Location = System::Drawing::Point(229, 101);
			this->lbl_Email->Name = L"lbl_Email";
			this->lbl_Email->Size = System::Drawing::Size(10, 13);
			this->lbl_Email->TabIndex = 36;
			this->lbl_Email->Text = L"-";
			// 
			// lbl_Phone
			// 
			this->lbl_Phone->AutoSize = true;
			this->lbl_Phone->Location = System::Drawing::Point(396, 101);
			this->lbl_Phone->Name = L"lbl_Phone";
			this->lbl_Phone->Size = System::Drawing::Size(10, 13);
			this->lbl_Phone->TabIndex = 35;
			this->lbl_Phone->Text = L"-";
			// 
			// lbl_Wechat
			// 
			this->lbl_Wechat->AutoSize = true;
			this->lbl_Wechat->Location = System::Drawing::Point(545, 101);
			this->lbl_Wechat->Name = L"lbl_Wechat";
			this->lbl_Wechat->Size = System::Drawing::Size(10, 13);
			this->lbl_Wechat->TabIndex = 37;
			this->lbl_Wechat->Text = L"-";
			// 
			// lbl_StdId
			// 
			this->lbl_StdId->AutoSize = true;
			this->lbl_StdId->Location = System::Drawing::Point(693, 101);
			this->lbl_StdId->Name = L"lbl_StdId";
			this->lbl_StdId->Size = System::Drawing::Size(10, 13);
			this->lbl_StdId->TabIndex = 39;
			this->lbl_StdId->Text = L"-";
			// 
			// lbl_Country
			// 
			this->lbl_Country->AutoSize = true;
			this->lbl_Country->Location = System::Drawing::Point(69, 140);
			this->lbl_Country->Name = L"lbl_Country";
			this->lbl_Country->Size = System::Drawing::Size(10, 13);
			this->lbl_Country->TabIndex = 38;
			this->lbl_Country->Text = L"-";
			// 
			// lbl_Address1
			// 
			this->lbl_Address1->AutoSize = true;
			this->lbl_Address1->Location = System::Drawing::Point(229, 140);
			this->lbl_Address1->Name = L"lbl_Address1";
			this->lbl_Address1->Size = System::Drawing::Size(10, 13);
			this->lbl_Address1->TabIndex = 42;
			this->lbl_Address1->Text = L"-";
			// 
			// lbl_Address2
			// 
			this->lbl_Address2->AutoSize = true;
			this->lbl_Address2->Location = System::Drawing::Point(396, 140);
			this->lbl_Address2->Name = L"lbl_Address2";
			this->lbl_Address2->Size = System::Drawing::Size(10, 13);
			this->lbl_Address2->TabIndex = 41;
			this->lbl_Address2->Text = L"-";
			// 
			// lbl_City
			// 
			this->lbl_City->AutoSize = true;
			this->lbl_City->Location = System::Drawing::Point(545, 140);
			this->lbl_City->Name = L"lbl_City";
			this->lbl_City->Size = System::Drawing::Size(10, 13);
			this->lbl_City->TabIndex = 40;
			this->lbl_City->Text = L"-";
			// 
			// lbl_Postal
			// 
			this->lbl_Postal->AutoSize = true;
			this->lbl_Postal->Location = System::Drawing::Point(693, 140);
			this->lbl_Postal->Name = L"lbl_Postal";
			this->lbl_Postal->Size = System::Drawing::Size(10, 13);
			this->lbl_Postal->TabIndex = 43;
			this->lbl_Postal->Text = L"-";
			// 
			// lbl_Program
			// 
			this->lbl_Program->AutoSize = true;
			this->lbl_Program->Location = System::Drawing::Point(69, 177);
			this->lbl_Program->Name = L"lbl_Program";
			this->lbl_Program->Size = System::Drawing::Size(10, 13);
			this->lbl_Program->TabIndex = 44;
			this->lbl_Program->Text = L"-";
			// 
			// lbl_EndDate
			// 
			this->lbl_EndDate->AutoSize = true;
			this->lbl_EndDate->Location = System::Drawing::Point(229, 178);
			this->lbl_EndDate->Name = L"lbl_EndDate";
			this->lbl_EndDate->Size = System::Drawing::Size(10, 13);
			this->lbl_EndDate->TabIndex = 46;
			this->lbl_EndDate->Text = L"-";
			// 
			// lbl_Degree
			// 
			this->lbl_Degree->AutoSize = true;
			this->lbl_Degree->Location = System::Drawing::Point(392, 178);
			this->lbl_Degree->Name = L"lbl_Degree";
			this->lbl_Degree->Size = System::Drawing::Size(10, 13);
			this->lbl_Degree->TabIndex = 45;
			this->lbl_Degree->Text = L"-";
			// 
			// lbl_Major1
			// 
			this->lbl_Major1->AutoSize = true;
			this->lbl_Major1->Location = System::Drawing::Point(549, 178);
			this->lbl_Major1->Name = L"lbl_Major1";
			this->lbl_Major1->Size = System::Drawing::Size(10, 13);
			this->lbl_Major1->TabIndex = 48;
			this->lbl_Major1->Text = L"-";
			// 
			// lbl_Major2
			// 
			this->lbl_Major2->AutoSize = true;
			this->lbl_Major2->Location = System::Drawing::Point(683, 177);
			this->lbl_Major2->Name = L"lbl_Major2";
			this->lbl_Major2->Size = System::Drawing::Size(10, 13);
			this->lbl_Major2->TabIndex = 47;
			this->lbl_Major2->Text = L"-";
			// 
			// lbl_CareerStatus
			// 
			this->lbl_CareerStatus->AutoSize = true;
			this->lbl_CareerStatus->Location = System::Drawing::Point(89, 212);
			this->lbl_CareerStatus->Name = L"lbl_CareerStatus";
			this->lbl_CareerStatus->Size = System::Drawing::Size(10, 13);
			this->lbl_CareerStatus->TabIndex = 49;
			this->lbl_CareerStatus->Text = L"-";
			// 
			// lbl_Company
			// 
			this->lbl_Company->AutoSize = true;
			this->lbl_Company->Location = System::Drawing::Point(256, 212);
			this->lbl_Company->Name = L"lbl_Company";
			this->lbl_Company->Size = System::Drawing::Size(10, 13);
			this->lbl_Company->TabIndex = 50;
			this->lbl_Company->Text = L"-";
			// 
			// lbl_Position
			// 
			this->lbl_Position->AutoSize = true;
			this->lbl_Position->Location = System::Drawing::Point(435, 208);
			this->lbl_Position->Name = L"lbl_Position";
			this->lbl_Position->Size = System::Drawing::Size(10, 13);
			this->lbl_Position->TabIndex = 51;
			this->lbl_Position->Text = L"-";
			// 
			// lbl_SearchAuth
			// 
			this->lbl_SearchAuth->AutoSize = true;
			this->lbl_SearchAuth->Location = System::Drawing::Point(611, 205);
			this->lbl_SearchAuth->Name = L"lbl_SearchAuth";
			this->lbl_SearchAuth->Size = System::Drawing::Size(10, 13);
			this->lbl_SearchAuth->TabIndex = 52;
			this->lbl_SearchAuth->Text = L"-";
			// 
			// btn_Delete
			// 
			this->btn_Delete->Location = System::Drawing::Point(579, 264);
			this->btn_Delete->Name = L"btn_Delete";
			this->btn_Delete->Size = System::Drawing::Size(63, 60);
			this->btn_Delete->TabIndex = 53;
			this->btn_Delete->Text = L"Delete Member";
			this->btn_Delete->UseVisualStyleBackColor = true;
			this->btn_Delete->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_Delete_Click);
			// 
			// lbl_error
			// 
			this->lbl_error->AutoSize = true;
			this->lbl_error->ForeColor = System::Drawing::Color::Red;
			this->lbl_error->Location = System::Drawing::Point(492, 246);
			this->lbl_error->Name = L"lbl_error";
			this->lbl_error->Size = System::Drawing::Size(47, 13);
			this->lbl_error->TabIndex = 54;
			this->lbl_error->Text = L"Warning";
			this->lbl_error->Visible = false;
			// 
			// btn_ShwPrcssActn
			// 
			this->btn_ShwPrcssActn->Location = System::Drawing::Point(494, 264);
			this->btn_ShwPrcssActn->Name = L"btn_ShwPrcssActn";
			this->btn_ShwPrcssActn->Size = System::Drawing::Size(61, 60);
			this->btn_ShwPrcssActn->TabIndex = 55;
			this->btn_ShwPrcssActn->Text = L"Show Process Action";
			this->btn_ShwPrcssActn->UseVisualStyleBackColor = true;
			this->btn_ShwPrcssActn->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_ShwPrcssActn_Click);
			// 
			// btn_DeleteAccept
			// 
			this->btn_DeleteAccept->Location = System::Drawing::Point(358, 262);
			this->btn_DeleteAccept->Name = L"btn_DeleteAccept";
			this->btn_DeleteAccept->Size = System::Drawing::Size(75, 23);
			this->btn_DeleteAccept->TabIndex = 59;
			this->btn_DeleteAccept->Text = L"Accept";
			this->btn_DeleteAccept->UseVisualStyleBackColor = true;
			this->btn_DeleteAccept->Visible = false;
			this->btn_DeleteAccept->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_DeleteAccept_Click);
			// 
			// btn_DeleteCancel
			// 
			this->btn_DeleteCancel->Location = System::Drawing::Point(358, 291);
			this->btn_DeleteCancel->Name = L"btn_DeleteCancel";
			this->btn_DeleteCancel->Size = System::Drawing::Size(75, 23);
			this->btn_DeleteCancel->TabIndex = 60;
			this->btn_DeleteCancel->Text = L"Cancel";
			this->btn_DeleteCancel->UseVisualStyleBackColor = true;
			this->btn_DeleteCancel->Visible = false;
			this->btn_DeleteCancel->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_DeleteCancel_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 402);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(762, 151);
			this->dataGridView1->TabIndex = 61;
			// 
			// btn_ChangeInfoAccept
			// 
			this->btn_ChangeInfoAccept->Location = System::Drawing::Point(259, 262);
			this->btn_ChangeInfoAccept->Name = L"btn_ChangeInfoAccept";
			this->btn_ChangeInfoAccept->Size = System::Drawing::Size(75, 23);
			this->btn_ChangeInfoAccept->TabIndex = 62;
			this->btn_ChangeInfoAccept->Text = L"Accept";
			this->btn_ChangeInfoAccept->UseVisualStyleBackColor = true;
			this->btn_ChangeInfoAccept->Visible = false;
			this->btn_ChangeInfoAccept->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_ChangeInfoAccept_Click);
			// 
			// btn_ChangeInfoCancel
			// 
			this->btn_ChangeInfoCancel->Location = System::Drawing::Point(259, 291);
			this->btn_ChangeInfoCancel->Name = L"btn_ChangeInfoCancel";
			this->btn_ChangeInfoCancel->Size = System::Drawing::Size(75, 23);
			this->btn_ChangeInfoCancel->TabIndex = 63;
			this->btn_ChangeInfoCancel->Text = L"Cancel";
			this->btn_ChangeInfoCancel->UseVisualStyleBackColor = true;
			this->btn_ChangeInfoCancel->Visible = false;
			this->btn_ChangeInfoCancel->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_ChangeInfoCancel_Click);
			// 
			// MemInfoPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 565);
			this->Controls->Add(this->btn_ChangeInfoCancel);
			this->Controls->Add(this->btn_ChangeInfoAccept);
			this->Controls->Add(this->txt_SearchAuth);
			this->Controls->Add(this->txt_Major2);
			this->Controls->Add(this->txt_Postal);
			this->Controls->Add(this->txt_StdId);
			this->Controls->Add(this->txt_Gender);
			this->Controls->Add(this->txt_Major1);
			this->Controls->Add(this->txt_City);
			this->Controls->Add(this->txt_Wechat);
			this->Controls->Add(this->txt_Name);
			this->Controls->Add(this->txt_Degree);
			this->Controls->Add(this->txt_Address2);
			this->Controls->Add(this->txt_Phone);
			this->Controls->Add(this->txt_Email);
			this->Controls->Add(this->txt_Address1);
			this->Controls->Add(this->txt_EndDate);
			this->Controls->Add(this->txt_Position);
			this->Controls->Add(this->txt_Company);
			this->Controls->Add(this->txt_CareerStatus);
			this->Controls->Add(this->txt_Program);
			this->Controls->Add(this->txt_Country);
			this->Controls->Add(this->txt_Birth);
			this->Controls->Add(this->txt_Type);
			this->Controls->Add(this->txt_Status);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btn_DeleteCancel);
			this->Controls->Add(this->btn_DeleteAccept);
			this->Controls->Add(this->btn_ShwPrcssActn);
			this->Controls->Add(this->lbl_error);
			this->Controls->Add(this->btn_Delete);
			this->Controls->Add(this->lbl_SearchAuth);
			this->Controls->Add(this->lbl_Position);
			this->Controls->Add(this->lbl_Company);
			this->Controls->Add(this->lbl_CareerStatus);
			this->Controls->Add(this->lbl_Major1);
			this->Controls->Add(this->lbl_Major2);
			this->Controls->Add(this->lbl_EndDate);
			this->Controls->Add(this->lbl_Degree);
			this->Controls->Add(this->lbl_Program);
			this->Controls->Add(this->lbl_Postal);
			this->Controls->Add(this->lbl_Address1);
			this->Controls->Add(this->lbl_Address2);
			this->Controls->Add(this->lbl_City);
			this->Controls->Add(this->lbl_StdId);
			this->Controls->Add(this->lbl_Country);
			this->Controls->Add(this->lbl_Wechat);
			this->Controls->Add(this->lbl_Email);
			this->Controls->Add(this->lbl_Phone);
			this->Controls->Add(this->lbl_Gender);
			this->Controls->Add(this->lbl_Birth);
			this->Controls->Add(this->lbl_Type);
			this->Controls->Add(this->lbl_Name);
			this->Controls->Add(this->lbl_Status);
			this->Controls->Add(this->lbl_Id);
			this->Controls->Add(this->btn_ChangeInfo);
			this->Controls->Add(this->lbl_Prompt_SearchAuth);
			this->Controls->Add(this->lbl_Prompt_Position);
			this->Controls->Add(this->lbl_Prompt_Company);
			this->Controls->Add(this->lbl_Prompt_CareerStatus);
			this->Controls->Add(this->lbl_Prompt_Major2);
			this->Controls->Add(this->lbl_Prompt_Major1);
			this->Controls->Add(this->lbl_Prompt_Degree);
			this->Controls->Add(this->lbl_Prompt_EndDate);
			this->Controls->Add(this->lbl_Prompt_Program);
			this->Controls->Add(this->lbl_Prompt_StdId);
			this->Controls->Add(this->lbl_Prompt_Postal);
			this->Controls->Add(this->lbl_Prompt_City);
			this->Controls->Add(this->lbl_Prompt_Address2);
			this->Controls->Add(this->lbl_Prompt_Address1);
			this->Controls->Add(this->lbl_Prompt_Country);
			this->Controls->Add(this->lbl_Prompt_Wechat);
			this->Controls->Add(this->lbl_Prompt_Phone);
			this->Controls->Add(this->lbl_Prompt_Email);
			this->Controls->Add(this->lbl_Prompt_Birth);
			this->Controls->Add(this->lbl_Prompt_Gender);
			this->Controls->Add(this->lbl_Prompt_Name);
			this->Controls->Add(this->lbl_Prompt_Type);
			this->Controls->Add(this->lbl_Prompt_Status);
			this->Controls->Add(this->lbl_Prompt_Id);
			this->Controls->Add(this->lbl_Prompt_PgTitle);
			this->Name = L"MemInfoPage";
			this->Text = L"Member Info Page";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		int _id;
		Database^ database;
		
	private:
		Void Initialize();
		Void UpdateInfo();
		Void btn_ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Delete_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_ShwPrcssActn_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_ChangeInfoAccept_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_ChangeInfoCancel_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_DeleteAccept_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_DeleteCancel_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
