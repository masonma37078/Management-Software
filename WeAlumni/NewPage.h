#pragma once
#include <Windows.h>
#include "Database.h"

/*
 * NewPage.h
 *
 * This file have basic Database interaction actions.
 *
 * @author: Hang Yuan
 * Revised: 3/21/20
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
	/// Summary for NewPage
	/// </summary>
	public ref class NewPage : public System::Windows::Forms::Form
	{
	public:
		NewPage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			database = gcnew Database(Database::DatabaseType::Admin);
			UpdateDataGridView();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NewPage()
		{
			if (components)
			{
				delete components;
			}

			if (database)
			{
				delete database;
			}
		}
	private: System::Windows::Forms::Button^ btn_VerifyPassword;
	private: System::Windows::Forms::Label^ lbl_passwordVerify;
	private: System::Windows::Forms::TextBox^ txt_password;
	private: System::Windows::Forms::DataGridView^ dgv_ShowPassword;
	private: System::Windows::Forms::Button^ btn_SetPassword;
	private: System::Windows::Forms::Label^ lbl_DBError;
	private: System::Windows::Forms::Label^ lbl_prompt_username;
	private: System::Windows::Forms::Label^ lbl_prompt_password;
	private: System::Windows::Forms::TextBox^ txt_username;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_VerifyPassword = (gcnew System::Windows::Forms::Button());
			this->lbl_passwordVerify = (gcnew System::Windows::Forms::Label());
			this->txt_password = (gcnew System::Windows::Forms::TextBox());
			this->dgv_ShowPassword = (gcnew System::Windows::Forms::DataGridView());
			this->btn_SetPassword = (gcnew System::Windows::Forms::Button());
			this->lbl_DBError = (gcnew System::Windows::Forms::Label());
			this->lbl_prompt_username = (gcnew System::Windows::Forms::Label());
			this->lbl_prompt_password = (gcnew System::Windows::Forms::Label());
			this->txt_username = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_ShowPassword))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_VerifyPassword
			// 
			this->btn_VerifyPassword->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_VerifyPassword->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_VerifyPassword->Location = System::Drawing::Point(122, 150);
			this->btn_VerifyPassword->Name = L"btn_VerifyPassword";
			this->btn_VerifyPassword->Size = System::Drawing::Size(113, 48);
			this->btn_VerifyPassword->TabIndex = 0;
			this->btn_VerifyPassword->Text = L"验证密码";
			this->btn_VerifyPassword->UseVisualStyleBackColor = true;
			this->btn_VerifyPassword->Click += gcnew System::EventHandler(this, &NewPage::btn_VerifyPassword_Click);
			// 
			// lbl_passwordVerify
			// 
			this->lbl_passwordVerify->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_passwordVerify->AutoSize = true;
			this->lbl_passwordVerify->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_passwordVerify->Location = System::Drawing::Point(265, 164);
			this->lbl_passwordVerify->Name = L"lbl_passwordVerify";
			this->lbl_passwordVerify->Size = System::Drawing::Size(149, 20);
			this->lbl_passwordVerify->TabIndex = 1;
			this->lbl_passwordVerify->Text = L"验证结果：正确";
			this->lbl_passwordVerify->Visible = false;
			// 
			// txt_password
			// 
			this->txt_password->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_password->Location = System::Drawing::Point(122, 110);
			this->txt_password->Name = L"txt_password";
			this->txt_password->Size = System::Drawing::Size(177, 25);
			this->txt_password->TabIndex = 2;
			// 
			// dgv_ShowPassword
			// 
			this->dgv_ShowPassword->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_ShowPassword->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->dgv_ShowPassword->Location = System::Drawing::Point(0, 242);
			this->dgv_ShowPassword->Name = L"dgv_ShowPassword";
			this->dgv_ShowPassword->RowHeadersWidth = 51;
			this->dgv_ShowPassword->RowTemplate->Height = 27;
			this->dgv_ShowPassword->Size = System::Drawing::Size(635, 220);
			this->dgv_ShowPassword->TabIndex = 3;
			// 
			// btn_SetPassword
			// 
			this->btn_SetPassword->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_SetPassword->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_SetPassword->Location = System::Drawing::Point(386, 81);
			this->btn_SetPassword->Name = L"btn_SetPassword";
			this->btn_SetPassword->Size = System::Drawing::Size(113, 47);
			this->btn_SetPassword->TabIndex = 4;
			this->btn_SetPassword->Text = L"设置密码";
			this->btn_SetPassword->UseVisualStyleBackColor = true;
			this->btn_SetPassword->Click += gcnew System::EventHandler(this, &NewPage::btn_SetPassword_Click);
			// 
			// lbl_DBError
			// 
			this->lbl_DBError->AutoSize = true;
			this->lbl_DBError->Font = (gcnew System::Drawing::Font(L"SimSun", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_DBError->Location = System::Drawing::Point(118, 337);
			this->lbl_DBError->Name = L"lbl_DBError";
			this->lbl_DBError->Size = System::Drawing::Size(199, 19);
			this->lbl_DBError->TabIndex = 5;
			this->lbl_DBError->Text = L"数据库错误，错误码：";
			this->lbl_DBError->Visible = false;
			// 
			// lbl_prompt_username
			// 
			this->lbl_prompt_username->AutoSize = true;
			this->lbl_prompt_username->Location = System::Drawing::Point(38, 69);
			this->lbl_prompt_username->Name = L"lbl_prompt_username";
			this->lbl_prompt_username->Size = System::Drawing::Size(52, 15);
			this->lbl_prompt_username->TabIndex = 6;
			this->lbl_prompt_username->Text = L"用户名";
			// 
			// lbl_prompt_password
			// 
			this->lbl_prompt_password->AutoSize = true;
			this->lbl_prompt_password->Location = System::Drawing::Point(38, 113);
			this->lbl_prompt_password->Name = L"lbl_prompt_password";
			this->lbl_prompt_password->Size = System::Drawing::Size(37, 15);
			this->lbl_prompt_password->TabIndex = 7;
			this->lbl_prompt_password->Text = L"密码";
			// 
			// txt_username
			// 
			this->txt_username->Location = System::Drawing::Point(122, 66);
			this->txt_username->Name = L"txt_username";
			this->txt_username->Size = System::Drawing::Size(177, 25);
			this->txt_username->TabIndex = 8;
			// 
			// NewPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(635, 462);
			this->Controls->Add(this->txt_username);
			this->Controls->Add(this->lbl_prompt_password);
			this->Controls->Add(this->lbl_prompt_username);
			this->Controls->Add(this->lbl_DBError);
			this->Controls->Add(this->btn_SetPassword);
			this->Controls->Add(this->dgv_ShowPassword);
			this->Controls->Add(this->txt_password);
			this->Controls->Add(this->lbl_passwordVerify);
			this->Controls->Add(this->btn_VerifyPassword);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"NewPage";
			this->Text = L"数据显示页面";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_ShowPassword))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		bool DBHasPassword;
		Database^ database;
		bool VerifyPassword(String^ username, String^ inputPassword);
		bool SetPassword(String^ username, String^ newPassword);
		Void btn_SetPassword_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_VerifyPassword_Click(System::Object^ sender, System::EventArgs^ e);
		Void UpdateDataGridView();
};
}
