#pragma once
#include "Database.h"

/*
 * StfInfoPage.h
 *
 * This file have basic Staff Information interaction actions.
 *
 * @author: Rui Jia
 * Revised: 4/1/20
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
	/// Summary for StfInfoPage
	/// </summary>
	public ref class StfInfoPage : public System::Windows::Forms::Form
	{
	public:
		StfInfoPage(int^ InputStfId)
		{
			InitializeComponent();
			_MemId = InputStfId;
			try {
				_database = gcnew Database(Database::DatabaseType::Data);
				Initialize();
			}
			catch (System::Exception^ exception) {
				lbl_error->Text = exception->Message;
				lbl_error->Visible = true;
				return;
			}
			UpdateDataGridView();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StfInfoPage()
		{
			if (components)
			{
				delete components;
			}

			if (_database)
			{
				delete _database;
			}
		}

	private: System::Windows::Forms::Label^ lbl_Prompt_StfInfoPage;
	private: System::Windows::Forms::Label^ lbl_Prompt_MemId;
	private: System::Windows::Forms::Label^ lbl_Prompt_Name;
	private: System::Windows::Forms::Label^ lbl_Prompt_Birth;
	private: System::Windows::Forms::Label^ lbl_Prompt_Email;
	private: System::Windows::Forms::Label^ lbl_Prompt_Gender;
	private: System::Windows::Forms::Label^ lbl_Prompt_Phone;
	private: System::Windows::Forms::Label^ lbl_Prompt_Wechat;
	private: System::Windows::Forms::Label^ lbl_Prompt_Dept;
	private: System::Windows::Forms::Label^ lbl_Prompt_Posi;
	private: System::Windows::Forms::Label^ lbl_Prompt_Auth;
	private: System::Windows::Forms::Button^ btn_ChangeInfo;
	private: System::Windows::Forms::Button^ btn_DeleteInfo;
	private: System::Windows::Forms::Button^ btn_Accpet;
	private: System::Windows::Forms::Button^ btn_AddRecord;
	private: System::Windows::Forms::Button^ btn_Cancle;
	private: System::Windows::Forms::Label^ lbl_MemId;
	private: System::Windows::Forms::Label^ lbl_Name;
	private: System::Windows::Forms::Label^ lbl_Gender;
	private: System::Windows::Forms::Label^ lbl_Birth;
	private: System::Windows::Forms::Label^ lbl_Email;
	private: System::Windows::Forms::Label^ lbl_Phone;
	private: System::Windows::Forms::Label^ lbl_Wechat;
	private: System::Windows::Forms::Label^ lbl_Dept;
	private: System::Windows::Forms::Label^ lbl_Posi;
	private: System::Windows::Forms::Label^ lbl_Auth;
	private: System::Windows::Forms::Button^ btn_Delete;
	private: System::Windows::Forms::Button^ btn_Close;
	private: System::Windows::Forms::Label^ lbl_Prompt_dgvStaff;
	private: System::Windows::Forms::Label^ lbl_error;
	private: System::Windows::Forms::DataGridView^ dgv_Staff;
	private: System::Windows::Forms::Label^ lbl_success;
	private: System::Windows::Forms::ComboBox^ cmb_Dept;
	private: System::Windows::Forms::ComboBox^ cmb_Posi;
	private: System::Windows::Forms::ComboBox^ cmb_Auth;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfId;
	private: System::Windows::Forms::Label^ lbl_StfId;
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
			this->lbl_Prompt_StfInfoPage = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_MemId = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Name = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Birth = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Email = (gcnew System::Windows::Forms::Label());
			this->btn_ChangeInfo = (gcnew System::Windows::Forms::Button());
			this->btn_DeleteInfo = (gcnew System::Windows::Forms::Button());
			this->btn_Accpet = (gcnew System::Windows::Forms::Button());
			this->lbl_Prompt_Gender = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Phone = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Wechat = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Dept = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Posi = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Auth = (gcnew System::Windows::Forms::Label());
			this->btn_AddRecord = (gcnew System::Windows::Forms::Button());
			this->btn_Cancle = (gcnew System::Windows::Forms::Button());
			this->lbl_MemId = (gcnew System::Windows::Forms::Label());
			this->lbl_Name = (gcnew System::Windows::Forms::Label());
			this->lbl_Gender = (gcnew System::Windows::Forms::Label());
			this->lbl_Birth = (gcnew System::Windows::Forms::Label());
			this->lbl_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_Phone = (gcnew System::Windows::Forms::Label());
			this->lbl_Wechat = (gcnew System::Windows::Forms::Label());
			this->lbl_Dept = (gcnew System::Windows::Forms::Label());
			this->lbl_Posi = (gcnew System::Windows::Forms::Label());
			this->lbl_Auth = (gcnew System::Windows::Forms::Label());
			this->btn_Delete = (gcnew System::Windows::Forms::Button());
			this->btn_Close = (gcnew System::Windows::Forms::Button());
			this->lbl_Prompt_dgvStaff = (gcnew System::Windows::Forms::Label());
			this->lbl_error = (gcnew System::Windows::Forms::Label());
			this->dgv_Staff = (gcnew System::Windows::Forms::DataGridView());
			this->lbl_success = (gcnew System::Windows::Forms::Label());
			this->cmb_Dept = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_Posi = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_Auth = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_Prompt_StfId = (gcnew System::Windows::Forms::Label());
			this->lbl_StfId = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_Staff))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_Prompt_StfInfoPage
			// 
			this->lbl_Prompt_StfInfoPage->AutoSize = true;
			this->lbl_Prompt_StfInfoPage->Location = System::Drawing::Point(516, 28);
			this->lbl_Prompt_StfInfoPage->Name = L"lbl_Prompt_StfInfoPage";
			this->lbl_Prompt_StfInfoPage->Size = System::Drawing::Size(183, 15);
			this->lbl_Prompt_StfInfoPage->TabIndex = 22;
			this->lbl_Prompt_StfInfoPage->Text = L"Staff Information Page";
			// 
			// lbl_Prompt_MemId
			// 
			this->lbl_Prompt_MemId->AutoSize = true;
			this->lbl_Prompt_MemId->Location = System::Drawing::Point(287, 74);
			this->lbl_Prompt_MemId->Name = L"lbl_Prompt_MemId";
			this->lbl_Prompt_MemId->Size = System::Drawing::Size(79, 15);
			this->lbl_Prompt_MemId->TabIndex = 24;
			this->lbl_Prompt_MemId->Text = L"Member ID";
			// 
			// lbl_Prompt_Name
			// 
			this->lbl_Prompt_Name->AutoSize = true;
			this->lbl_Prompt_Name->Location = System::Drawing::Point(548, 74);
			this->lbl_Prompt_Name->Name = L"lbl_Prompt_Name";
			this->lbl_Prompt_Name->Size = System::Drawing::Size(39, 15);
			this->lbl_Prompt_Name->TabIndex = 25;
			this->lbl_Prompt_Name->Text = L"Name";
			// 
			// lbl_Prompt_Birth
			// 
			this->lbl_Prompt_Birth->AutoSize = true;
			this->lbl_Prompt_Birth->Location = System::Drawing::Point(28, 125);
			this->lbl_Prompt_Birth->Name = L"lbl_Prompt_Birth";
			this->lbl_Prompt_Birth->Size = System::Drawing::Size(71, 15);
			this->lbl_Prompt_Birth->TabIndex = 26;
			this->lbl_Prompt_Birth->Text = L"Birthday";
			// 
			// lbl_Prompt_Email
			// 
			this->lbl_Prompt_Email->AutoSize = true;
			this->lbl_Prompt_Email->Location = System::Drawing::Point(319, 125);
			this->lbl_Prompt_Email->Name = L"lbl_Prompt_Email";
			this->lbl_Prompt_Email->Size = System::Drawing::Size(47, 15);
			this->lbl_Prompt_Email->TabIndex = 27;
			this->lbl_Prompt_Email->Text = L"Email";
			// 
			// btn_ChangeInfo
			// 
			this->btn_ChangeInfo->Location = System::Drawing::Point(145, 232);
			this->btn_ChangeInfo->Name = L"btn_ChangeInfo";
			this->btn_ChangeInfo->Size = System::Drawing::Size(158, 44);
			this->btn_ChangeInfo->TabIndex = 28;
			this->btn_ChangeInfo->Text = L"Edit Information";
			this->btn_ChangeInfo->UseVisualStyleBackColor = true;
			this->btn_ChangeInfo->Click += gcnew System::EventHandler(this, &StfInfoPage::ChangeInfo_Click);
			// 
			// btn_DeleteInfo
			// 
			this->btn_DeleteInfo->Location = System::Drawing::Point(481, 232);
			this->btn_DeleteInfo->Name = L"btn_DeleteInfo";
			this->btn_DeleteInfo->Size = System::Drawing::Size(136, 44);
			this->btn_DeleteInfo->TabIndex = 29;
			this->btn_DeleteInfo->Text = L"Delete Information";
			this->btn_DeleteInfo->UseVisualStyleBackColor = true;
			this->btn_DeleteInfo->Click += gcnew System::EventHandler(this, &StfInfoPage::DeleteInfo_Click);
			// 
			// btn_Accpet
			// 
			this->btn_Accpet->Location = System::Drawing::Point(228, 342);
			this->btn_Accpet->Name = L"btn_Accpet";
			this->btn_Accpet->Size = System::Drawing::Size(75, 23);
			this->btn_Accpet->TabIndex = 30;
			this->btn_Accpet->Text = L"Accept";
			this->btn_Accpet->UseVisualStyleBackColor = true;
			this->btn_Accpet->Visible = false;
			this->btn_Accpet->Click += gcnew System::EventHandler(this, &StfInfoPage::AcceptButton_Click);
			// 
			// lbl_Prompt_Gender
			// 
			this->lbl_Prompt_Gender->AutoSize = true;
			this->lbl_Prompt_Gender->Location = System::Drawing::Point(747, 74);
			this->lbl_Prompt_Gender->Name = L"lbl_Prompt_Gender";
			this->lbl_Prompt_Gender->Size = System::Drawing::Size(55, 15);
			this->lbl_Prompt_Gender->TabIndex = 31;
			this->lbl_Prompt_Gender->Text = L"Gender";
			// 
			// lbl_Prompt_Phone
			// 
			this->lbl_Prompt_Phone->AutoSize = true;
			this->lbl_Prompt_Phone->Location = System::Drawing::Point(548, 125);
			this->lbl_Prompt_Phone->Name = L"lbl_Prompt_Phone";
			this->lbl_Prompt_Phone->Size = System::Drawing::Size(47, 15);
			this->lbl_Prompt_Phone->TabIndex = 33;
			this->lbl_Prompt_Phone->Text = L"Phone";
			// 
			// lbl_Prompt_Wechat
			// 
			this->lbl_Prompt_Wechat->AutoSize = true;
			this->lbl_Prompt_Wechat->Location = System::Drawing::Point(747, 125);
			this->lbl_Prompt_Wechat->Name = L"lbl_Prompt_Wechat";
			this->lbl_Prompt_Wechat->Size = System::Drawing::Size(55, 15);
			this->lbl_Prompt_Wechat->TabIndex = 35;
			this->lbl_Prompt_Wechat->Text = L"Wechat";
			// 
			// lbl_Prompt_Dept
			// 
			this->lbl_Prompt_Dept->AutoSize = true;
			this->lbl_Prompt_Dept->Location = System::Drawing::Point(28, 177);
			this->lbl_Prompt_Dept->Name = L"lbl_Prompt_Dept";
			this->lbl_Prompt_Dept->Size = System::Drawing::Size(87, 15);
			this->lbl_Prompt_Dept->TabIndex = 37;
			this->lbl_Prompt_Dept->Text = L"Department";
			// 
			// lbl_Prompt_Posi
			// 
			this->lbl_Prompt_Posi->AutoSize = true;
			this->lbl_Prompt_Posi->Location = System::Drawing::Point(449, 177);
			this->lbl_Prompt_Posi->Name = L"lbl_Prompt_Posi";
			this->lbl_Prompt_Posi->Size = System::Drawing::Size(71, 15);
			this->lbl_Prompt_Posi->TabIndex = 39;
			this->lbl_Prompt_Posi->Text = L"Position";
			// 
			// lbl_Prompt_Auth
			// 
			this->lbl_Prompt_Auth->AutoSize = true;
			this->lbl_Prompt_Auth->Location = System::Drawing::Point(725, 177);
			this->lbl_Prompt_Auth->Name = L"lbl_Prompt_Auth";
			this->lbl_Prompt_Auth->Size = System::Drawing::Size(39, 15);
			this->lbl_Prompt_Auth->TabIndex = 41;
			this->lbl_Prompt_Auth->Text = L"Auth";
			// 
			// btn_AddRecord
			// 
			this->btn_AddRecord->Location = System::Drawing::Point(766, 232);
			this->btn_AddRecord->Name = L"btn_AddRecord";
			this->btn_AddRecord->Size = System::Drawing::Size(136, 44);
			this->btn_AddRecord->TabIndex = 42;
			this->btn_AddRecord->Text = L"Add New Record";
			this->btn_AddRecord->UseVisualStyleBackColor = true;
			this->btn_AddRecord->Click += gcnew System::EventHandler(this, &StfInfoPage::AddNewRecord);
			// 
			// btn_Cancle
			// 
			this->btn_Cancle->Location = System::Drawing::Point(827, 342);
			this->btn_Cancle->Name = L"btn_Cancle";
			this->btn_Cancle->Size = System::Drawing::Size(75, 23);
			this->btn_Cancle->TabIndex = 43;
			this->btn_Cancle->Text = L"Cancle";
			this->btn_Cancle->UseVisualStyleBackColor = true;
			this->btn_Cancle->Visible = false;
			this->btn_Cancle->Click += gcnew System::EventHandler(this, &StfInfoPage::CancelButton_Click);
			// 
			// lbl_MemId
			// 
			this->lbl_MemId->AutoSize = true;
			this->lbl_MemId->Location = System::Drawing::Point(401, 74);
			this->lbl_MemId->Name = L"lbl_MemId";
			this->lbl_MemId->Size = System::Drawing::Size(119, 15);
			this->lbl_MemId->TabIndex = 47;
			this->lbl_MemId->Text = L"No Information";
			// 
			// lbl_Name
			// 
			this->lbl_Name->AutoSize = true;
			this->lbl_Name->Location = System::Drawing::Point(606, 74);
			this->lbl_Name->Name = L"lbl_Name";
			this->lbl_Name->Size = System::Drawing::Size(119, 15);
			this->lbl_Name->TabIndex = 48;
			this->lbl_Name->Text = L"No Information";
			// 
			// lbl_Gender
			// 
			this->lbl_Gender->AutoSize = true;
			this->lbl_Gender->Location = System::Drawing::Point(816, 74);
			this->lbl_Gender->Name = L"lbl_Gender";
			this->lbl_Gender->Size = System::Drawing::Size(119, 15);
			this->lbl_Gender->TabIndex = 49;
			this->lbl_Gender->Text = L"No Information";
			// 
			// lbl_Birth
			// 
			this->lbl_Birth->AutoSize = true;
			this->lbl_Birth->Location = System::Drawing::Point(137, 125);
			this->lbl_Birth->Name = L"lbl_Birth";
			this->lbl_Birth->Size = System::Drawing::Size(119, 15);
			this->lbl_Birth->TabIndex = 50;
			this->lbl_Birth->Text = L"No Information";
			// 
			// lbl_Email
			// 
			this->lbl_Email->AutoSize = true;
			this->lbl_Email->Location = System::Drawing::Point(401, 125);
			this->lbl_Email->Name = L"lbl_Email";
			this->lbl_Email->Size = System::Drawing::Size(119, 15);
			this->lbl_Email->TabIndex = 51;
			this->lbl_Email->Text = L"No Information";
			// 
			// lbl_Phone
			// 
			this->lbl_Phone->AutoSize = true;
			this->lbl_Phone->Location = System::Drawing::Point(606, 125);
			this->lbl_Phone->Name = L"lbl_Phone";
			this->lbl_Phone->Size = System::Drawing::Size(119, 15);
			this->lbl_Phone->TabIndex = 52;
			this->lbl_Phone->Text = L"No Information";
			// 
			// lbl_Wechat
			// 
			this->lbl_Wechat->AutoSize = true;
			this->lbl_Wechat->Location = System::Drawing::Point(816, 125);
			this->lbl_Wechat->Name = L"lbl_Wechat";
			this->lbl_Wechat->Size = System::Drawing::Size(119, 15);
			this->lbl_Wechat->TabIndex = 53;
			this->lbl_Wechat->Text = L"No Information";
			// 
			// lbl_Dept
			// 
			this->lbl_Dept->AutoSize = true;
			this->lbl_Dept->Location = System::Drawing::Point(142, 177);
			this->lbl_Dept->Name = L"lbl_Dept";
			this->lbl_Dept->Size = System::Drawing::Size(119, 15);
			this->lbl_Dept->TabIndex = 54;
			this->lbl_Dept->Text = L"No Information";
			// 
			// lbl_Posi
			// 
			this->lbl_Posi->AutoSize = true;
			this->lbl_Posi->Location = System::Drawing::Point(548, 177);
			this->lbl_Posi->Name = L"lbl_Posi";
			this->lbl_Posi->Size = System::Drawing::Size(119, 15);
			this->lbl_Posi->TabIndex = 55;
			this->lbl_Posi->Text = L"No Information";
			// 
			// lbl_Auth
			// 
			this->lbl_Auth->AutoSize = true;
			this->lbl_Auth->Location = System::Drawing::Point(816, 177);
			this->lbl_Auth->Name = L"lbl_Auth";
			this->lbl_Auth->Size = System::Drawing::Size(119, 15);
			this->lbl_Auth->TabIndex = 56;
			this->lbl_Auth->Text = L"No Information";
			// 
			// btn_Delete
			// 
			this->btn_Delete->Location = System::Drawing::Point(228, 295);
			this->btn_Delete->Name = L"btn_Delete";
			this->btn_Delete->Size = System::Drawing::Size(75, 23);
			this->btn_Delete->TabIndex = 57;
			this->btn_Delete->Text = L"Delete";
			this->btn_Delete->UseVisualStyleBackColor = true;
			this->btn_Delete->Visible = false;
			this->btn_Delete->Click += gcnew System::EventHandler(this, &StfInfoPage::DeleteAcceptButton_Click);
			// 
			// btn_Close
			// 
			this->btn_Close->Location = System::Drawing::Point(827, 291);
			this->btn_Close->Name = L"btn_Close";
			this->btn_Close->Size = System::Drawing::Size(75, 23);
			this->btn_Close->TabIndex = 58;
			this->btn_Close->Text = L"Close";
			this->btn_Close->UseVisualStyleBackColor = true;
			this->btn_Close->Visible = false;
			this->btn_Close->Click += gcnew System::EventHandler(this, &StfInfoPage::DeleteCancelButton_Click);
			// 
			// lbl_Prompt_dgvStaff
			// 
			this->lbl_Prompt_dgvStaff->AutoSize = true;
			this->lbl_Prompt_dgvStaff->Location = System::Drawing::Point(548, 388);
			this->lbl_Prompt_dgvStaff->Name = L"lbl_Prompt_dgvStaff";
			this->lbl_Prompt_dgvStaff->Size = System::Drawing::Size(79, 15);
			this->lbl_Prompt_dgvStaff->TabIndex = 59;
			this->lbl_Prompt_dgvStaff->Text = L"Data Area";
			// 
			// lbl_error
			// 
			this->lbl_error->AutoSize = true;
			this->lbl_error->ForeColor = System::Drawing::Color::Red;
			this->lbl_error->Location = System::Drawing::Point(478, 299);
			this->lbl_error->Name = L"lbl_error";
			this->lbl_error->Size = System::Drawing::Size(47, 15);
			this->lbl_error->TabIndex = 70;
			this->lbl_error->Text = L"Error";
			this->lbl_error->Visible = false;
			// 
			// dgv_Staff
			// 
			this->dgv_Staff->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_Staff->Location = System::Drawing::Point(2, 424);
			this->dgv_Staff->Name = L"dgv_Staff";
			this->dgv_Staff->RowHeadersWidth = 51;
			this->dgv_Staff->RowTemplate->Height = 27;
			this->dgv_Staff->Size = System::Drawing::Size(1071, 150);
			this->dgv_Staff->TabIndex = 71;
			// 
			// lbl_success
			// 
			this->lbl_success->AutoSize = true;
			this->lbl_success->ForeColor = System::Drawing::Color::Green;
			this->lbl_success->Location = System::Drawing::Point(478, 346);
			this->lbl_success->Name = L"lbl_success";
			this->lbl_success->Size = System::Drawing::Size(95, 15);
			this->lbl_success->TabIndex = 72;
			this->lbl_success->Text = L"Successful!";
			this->lbl_success->Visible = false;
			// 
			// cmb_Dept
			// 
			this->cmb_Dept->FormattingEnabled = true;
			this->cmb_Dept->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"General Administration", L"Information Technology Support",
					L"Career Development Support"
			});
			this->cmb_Dept->Location = System::Drawing::Point(140, 174);
			this->cmb_Dept->Name = L"cmb_Dept";
			this->cmb_Dept->Size = System::Drawing::Size(243, 23);
			this->cmb_Dept->TabIndex = 73;
			this->cmb_Dept->Visible = false;
			// 
			// cmb_Posi
			// 
			this->cmb_Posi->FormattingEnabled = true;
			this->cmb_Posi->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Director", L"Manager", L"Staff" });
			this->cmb_Posi->Location = System::Drawing::Point(526, 174);
			this->cmb_Posi->Name = L"cmb_Posi";
			this->cmb_Posi->Size = System::Drawing::Size(185, 23);
			this->cmb_Posi->TabIndex = 74;
			this->cmb_Posi->Visible = false;
			// 
			// cmb_Auth
			// 
			this->cmb_Auth->FormattingEnabled = true;
			this->cmb_Auth->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Level 1", L"Level 2", L"Level 3", L"Level 4",
					L"Level 5"
			});
			this->cmb_Auth->Location = System::Drawing::Point(783, 174);
			this->cmb_Auth->Name = L"cmb_Auth";
			this->cmb_Auth->Size = System::Drawing::Size(185, 23);
			this->cmb_Auth->TabIndex = 75;
			this->cmb_Auth->Visible = false;
			// 
			// lbl_Prompt_StfId
			// 
			this->lbl_Prompt_StfId->AutoSize = true;
			this->lbl_Prompt_StfId->Location = System::Drawing::Point(28, 74);
			this->lbl_Prompt_StfId->Name = L"lbl_Prompt_StfId";
			this->lbl_Prompt_StfId->Size = System::Drawing::Size(71, 15);
			this->lbl_Prompt_StfId->TabIndex = 76;
			this->lbl_Prompt_StfId->Text = L"Staff ID";
			// 
			// lbl_StfId
			// 
			this->lbl_StfId->AutoSize = true;
			this->lbl_StfId->Location = System::Drawing::Point(137, 74);
			this->lbl_StfId->Name = L"lbl_StfId";
			this->lbl_StfId->Size = System::Drawing::Size(119, 15);
			this->lbl_StfId->TabIndex = 77;
			this->lbl_StfId->Text = L"No Information";
			// 
			// StfInfoPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1096, 603);
			this->Controls->Add(this->lbl_StfId);
			this->Controls->Add(this->lbl_Prompt_StfId);
			this->Controls->Add(this->cmb_Auth);
			this->Controls->Add(this->cmb_Posi);
			this->Controls->Add(this->cmb_Dept);
			this->Controls->Add(this->lbl_success);
			this->Controls->Add(this->dgv_Staff);
			this->Controls->Add(this->lbl_error);
			this->Controls->Add(this->lbl_Prompt_dgvStaff);
			this->Controls->Add(this->btn_Close);
			this->Controls->Add(this->btn_Delete);
			this->Controls->Add(this->lbl_Auth);
			this->Controls->Add(this->lbl_Posi);
			this->Controls->Add(this->lbl_Dept);
			this->Controls->Add(this->lbl_Wechat);
			this->Controls->Add(this->lbl_Phone);
			this->Controls->Add(this->lbl_Email);
			this->Controls->Add(this->lbl_Birth);
			this->Controls->Add(this->lbl_Gender);
			this->Controls->Add(this->lbl_Name);
			this->Controls->Add(this->lbl_MemId);
			this->Controls->Add(this->btn_Cancle);
			this->Controls->Add(this->btn_AddRecord);
			this->Controls->Add(this->lbl_Prompt_Auth);
			this->Controls->Add(this->lbl_Prompt_Posi);
			this->Controls->Add(this->lbl_Prompt_Dept);
			this->Controls->Add(this->lbl_Prompt_Wechat);
			this->Controls->Add(this->lbl_Prompt_Phone);
			this->Controls->Add(this->lbl_Prompt_Gender);
			this->Controls->Add(this->btn_Accpet);
			this->Controls->Add(this->btn_DeleteInfo);
			this->Controls->Add(this->btn_ChangeInfo);
			this->Controls->Add(this->lbl_Prompt_Email);
			this->Controls->Add(this->lbl_Prompt_Birth);
			this->Controls->Add(this->lbl_Prompt_Name);
			this->Controls->Add(this->lbl_Prompt_MemId);
			this->Controls->Add(this->lbl_Prompt_StfInfoPage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"StfInfoPage";
			this->Text = L"Staff Information Page";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_Staff))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private:
		int^ _MemId;
		int _StfId;
		Database^ _database;
	
	private:
		Void UpdateInfo();
		Void Initialize();
		Void ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e);
		Void AcceptButton_Click(System::Object^ sender, System::EventArgs^ e);
		Void CancelButton_Click(System::Object^ sender, System::EventArgs^ e);
		Void DeleteInfo_Click(System::Object^ sender, System::EventArgs^ e);
		Void DeleteAcceptButton_Click(System::Object^ sender, System::EventArgs^ e);
		Void DeleteCancelButton_Click(System::Object^ sender, System::EventArgs^ e);
		Void AddNewRecord(System::Object^ sender, System::EventArgs^ e);
		Void UpdateDataGridView();
		Void ChangeTxtVisible();
		Void ChangeTxtInvisible();
		Void ChangeLabelVisible();
		Void ChangeLabelInvisible();
	};
}
