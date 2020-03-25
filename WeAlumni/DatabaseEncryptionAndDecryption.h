#pragma once
#include "Database.h"
#include "DatabaseParam.h"

namespace WeAlumni {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DatabaseEncryptionAndDecryption
	/// </summary>
	public ref class DatabaseEncryptionAndDecryption : public System::Windows::Forms::Form
	{
	public:
		DatabaseEncryptionAndDecryption(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DatabaseEncryptionAndDecryption()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_encrpyt;
	private: System::Windows::Forms::Label^ lbl_title;
	private: System::Windows::Forms::Button^ btn_decrypt;
	private: System::Windows::Forms::Button^ btn_close;
	private: System::Windows::Forms::Label^ lbl_resultPrompt;
	private: System::Windows::Forms::RadioButton^ rbtn_adminDB;
	private: System::Windows::Forms::RadioButton^ rbtn_dataDB;
	private: System::Windows::Forms::RadioButton^ rbtn_treasuryDB;
	private: System::Windows::Forms::Label^ lbl_result;



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
			this->btn_encrpyt = (gcnew System::Windows::Forms::Button());
			this->lbl_title = (gcnew System::Windows::Forms::Label());
			this->btn_decrypt = (gcnew System::Windows::Forms::Button());
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->lbl_resultPrompt = (gcnew System::Windows::Forms::Label());
			this->rbtn_adminDB = (gcnew System::Windows::Forms::RadioButton());
			this->rbtn_dataDB = (gcnew System::Windows::Forms::RadioButton());
			this->rbtn_treasuryDB = (gcnew System::Windows::Forms::RadioButton());
			this->lbl_result = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_encrpyt
			// 
			this->btn_encrpyt->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_encrpyt->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_encrpyt->Location = System::Drawing::Point(22, 260);
			this->btn_encrpyt->Name = L"btn_encrpyt";
			this->btn_encrpyt->Size = System::Drawing::Size(108, 37);
			this->btn_encrpyt->TabIndex = 0;
			this->btn_encrpyt->Text = L"Encrypt";
			this->btn_encrpyt->UseVisualStyleBackColor = true;
			this->btn_encrpyt->Click += gcnew System::EventHandler(this, &DatabaseEncryptionAndDecryption::btn_encrpyt_Click);
			// 
			// lbl_title
			// 
			this->lbl_title->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_title->AutoSize = true;
			this->lbl_title->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_title->Location = System::Drawing::Point(30, 39);
			this->lbl_title->Name = L"lbl_title";
			this->lbl_title->Size = System::Drawing::Size(318, 17);
			this->lbl_title->TabIndex = 1;
			this->lbl_title->Text = L"Please select the database file";
			// 
			// btn_decrypt
			// 
			this->btn_decrypt->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_decrypt->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_decrypt->Location = System::Drawing::Point(161, 260);
			this->btn_decrypt->Name = L"btn_decrypt";
			this->btn_decrypt->Size = System::Drawing::Size(108, 37);
			this->btn_decrypt->TabIndex = 2;
			this->btn_decrypt->Text = L"Decrypt";
			this->btn_decrypt->UseVisualStyleBackColor = true;
			this->btn_decrypt->Click += gcnew System::EventHandler(this, &DatabaseEncryptionAndDecryption::btn_decrypt_Click);
			// 
			// btn_close
			// 
			this->btn_close->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_close->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_close->Location = System::Drawing::Point(304, 260);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(108, 37);
			this->btn_close->TabIndex = 3;
			this->btn_close->Text = L"Close";
			this->btn_close->UseVisualStyleBackColor = true;
			this->btn_close->Click += gcnew System::EventHandler(this, &DatabaseEncryptionAndDecryption::btn_close_Click);
			// 
			// lbl_resultPrompt
			// 
			this->lbl_resultPrompt->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_resultPrompt->AutoSize = true;
			this->lbl_resultPrompt->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_resultPrompt->Location = System::Drawing::Point(22, 222);
			this->lbl_resultPrompt->Name = L"lbl_resultPrompt";
			this->lbl_resultPrompt->Size = System::Drawing::Size(78, 17);
			this->lbl_resultPrompt->TabIndex = 4;
			this->lbl_resultPrompt->Text = L"Result:";
			// 
			// rbtn_adminDB
			// 
			this->rbtn_adminDB->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->rbtn_adminDB->AutoSize = true;
			this->rbtn_adminDB->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->rbtn_adminDB->Location = System::Drawing::Point(127, 89);
			this->rbtn_adminDB->Name = L"rbtn_adminDB";
			this->rbtn_adminDB->Size = System::Drawing::Size(109, 21);
			this->rbtn_adminDB->TabIndex = 5;
			this->rbtn_adminDB->TabStop = true;
			this->rbtn_adminDB->Text = L"Admin.db";
			this->rbtn_adminDB->UseVisualStyleBackColor = true;
			// 
			// rbtn_dataDB
			// 
			this->rbtn_dataDB->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->rbtn_dataDB->AutoSize = true;
			this->rbtn_dataDB->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->rbtn_dataDB->Location = System::Drawing::Point(127, 127);
			this->rbtn_dataDB->Name = L"rbtn_dataDB";
			this->rbtn_dataDB->Size = System::Drawing::Size(99, 21);
			this->rbtn_dataDB->TabIndex = 6;
			this->rbtn_dataDB->TabStop = true;
			this->rbtn_dataDB->Text = L"Data.db";
			this->rbtn_dataDB->UseVisualStyleBackColor = true;
			// 
			// rbtn_treasuryDB
			// 
			this->rbtn_treasuryDB->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->rbtn_treasuryDB->AutoSize = true;
			this->rbtn_treasuryDB->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->rbtn_treasuryDB->Location = System::Drawing::Point(127, 168);
			this->rbtn_treasuryDB->Name = L"rbtn_treasuryDB";
			this->rbtn_treasuryDB->Size = System::Drawing::Size(139, 21);
			this->rbtn_treasuryDB->TabIndex = 7;
			this->rbtn_treasuryDB->TabStop = true;
			this->rbtn_treasuryDB->Text = L"Treasury.db";
			this->rbtn_treasuryDB->UseVisualStyleBackColor = true;
			// 
			// lbl_result
			// 
			this->lbl_result->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_result->AutoSize = true;
			this->lbl_result->Font = (gcnew System::Drawing::Font(L"SimSun", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_result->Location = System::Drawing::Point(115, 224);
			this->lbl_result->Name = L"lbl_result";
			this->lbl_result->Size = System::Drawing::Size(151, 15);
			this->lbl_result->TabIndex = 8;
			this->lbl_result->Text = L"Wait for command";
			// 
			// DatabaseEncryptionAndDecryption
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(432, 322);
			this->Controls->Add(this->lbl_result);
			this->Controls->Add(this->rbtn_treasuryDB);
			this->Controls->Add(this->rbtn_dataDB);
			this->Controls->Add(this->rbtn_adminDB);
			this->Controls->Add(this->lbl_resultPrompt);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->btn_decrypt);
			this->Controls->Add(this->lbl_title);
			this->Controls->Add(this->btn_encrpyt);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"DatabaseEncryptionAndDecryption";
			this->Text = L"DatabaseEncryptionAndDecryption";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		String^ GetDatabaseName();
		String^ GetDatabasePassword();
		bool SetDatabasePassword();
		bool RemoveDatabasePassword();
		Void btn_encrpyt_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_decrypt_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_close_Click(System::Object^ sender, System::EventArgs^ e);
};
}
