#pragma once
#include "Database.h"
#include "TreInfoPage.h"

/*
 * TreAddPage.h
 *
 * This file includes suppot insert new record to treasury database.
 *
 * @author: Yiyun Zheng
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

	public ref class TreAddPage : public System::Windows::Forms::Form
	{
	public:
		TreAddPage(String^ OId)
		{
			InitializeComponent();
			OrderId = OId;
			UpdateInfo(OrderId);
		}

	protected:
		~TreAddPage()
		{
			if (components)
			{
				delete components;
			}
			if (_TreDB) {
				_TreDB->~Database();
			}
		}
	private: System::Windows::Forms::Label^ lbl_Prompt_Title;
	private: System::Windows::Forms::Label^ lbl_Prompt_Time;
	private: System::Windows::Forms::Label^ lbl_Prompt_Id;
	private: System::Windows::Forms::Label^ lbl_Prompt_Comment;
	private: System::Windows::Forms::Label^ lbl_Prompt_Amount;
	private: System::Windows::Forms::Label^ lbl_Prompt_Type;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfId;

	private: System::Windows::Forms::ComboBox^ cmb_Type;

	private: System::Windows::Forms::RichTextBox^ txt_Comment;
	private: System::Windows::Forms::TextBox^ txt_Time;
	private: System::Windows::Forms::TextBox^ txt_Amount;

	private: System::Windows::Forms::Button^ btn_Confirm;
	private: System::Windows::Forms::Button^ btn_Cancel;

	private: System::Windows::Forms::Label^ lbl_Id;
	private: System::Windows::Forms::Label^ lbl_Error;
	private: System::Windows::Forms::Label^ lbl_StfId;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbl_Prompt_Title = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Time = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Id = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Comment = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Amount = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Type = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StfId = (gcnew System::Windows::Forms::Label());
			this->lbl_Id = (gcnew System::Windows::Forms::Label());
			this->lbl_StfId = (gcnew System::Windows::Forms::Label());
			this->cmb_Type = (gcnew System::Windows::Forms::ComboBox());
			this->txt_Comment = (gcnew System::Windows::Forms::RichTextBox());
			this->txt_Time = (gcnew System::Windows::Forms::TextBox());
			this->txt_Amount = (gcnew System::Windows::Forms::TextBox());
			this->btn_Confirm = (gcnew System::Windows::Forms::Button());
			this->btn_Cancel = (gcnew System::Windows::Forms::Button());
			this->lbl_Error = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_Prompt_Title
			// 
			this->lbl_Prompt_Title->AutoSize = true;
			this->lbl_Prompt_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Title->Location = System::Drawing::Point(625, 129);
			this->lbl_Prompt_Title->Name = L"lbl_Prompt_Title";
			this->lbl_Prompt_Title->Size = System::Drawing::Size(254, 48);
			this->lbl_Prompt_Title->TabIndex = 0;
			this->lbl_Prompt_Title->Text = L"TreAddPage";
			// 
			// lbl_Prompt_Time
			// 
			this->lbl_Prompt_Time->AutoSize = true;
			this->lbl_Prompt_Time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Time->Location = System::Drawing::Point(817, 290);
			this->lbl_Prompt_Time->Name = L"lbl_Prompt_Time";
			this->lbl_Prompt_Time->Size = System::Drawing::Size(97, 40);
			this->lbl_Prompt_Time->TabIndex = 2;
			this->lbl_Prompt_Time->Text = L"Time";
			// 
			// lbl_Prompt_Id
			// 
			this->lbl_Prompt_Id->AutoSize = true;
			this->lbl_Prompt_Id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Id->Location = System::Drawing::Point(219, 290);
			this->lbl_Prompt_Id->Name = L"lbl_Prompt_Id";
			this->lbl_Prompt_Id->Size = System::Drawing::Size(52, 40);
			this->lbl_Prompt_Id->TabIndex = 3;
			this->lbl_Prompt_Id->Text = L"ID";
			// 
			// lbl_Prompt_Comment
			// 
			this->lbl_Prompt_Comment->AutoSize = true;
			this->lbl_Prompt_Comment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Comment->Location = System::Drawing::Point(219, 752);
			this->lbl_Prompt_Comment->Name = L"lbl_Prompt_Comment";
			this->lbl_Prompt_Comment->Size = System::Drawing::Size(173, 40);
			this->lbl_Prompt_Comment->TabIndex = 4;
			this->lbl_Prompt_Comment->Text = L"Comment";
			// 
			// lbl_Prompt_Amount
			// 
			this->lbl_Prompt_Amount->AutoSize = true;
			this->lbl_Prompt_Amount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Amount->Location = System::Drawing::Point(817, 445);
			this->lbl_Prompt_Amount->Name = L"lbl_Prompt_Amount";
			this->lbl_Prompt_Amount->Size = System::Drawing::Size(141, 40);
			this->lbl_Prompt_Amount->TabIndex = 5;
			this->lbl_Prompt_Amount->Text = L"Amount";
			// 
			// lbl_Prompt_Type
			// 
			this->lbl_Prompt_Type->AutoSize = true;
			this->lbl_Prompt_Type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Type->Location = System::Drawing::Point(219, 577);
			this->lbl_Prompt_Type->Name = L"lbl_Prompt_Type";
			this->lbl_Prompt_Type->Size = System::Drawing::Size(97, 40);
			this->lbl_Prompt_Type->TabIndex = 6;
			this->lbl_Prompt_Type->Text = L"Type";
			// 
			// lbl_Prompt_StfId
			// 
			this->lbl_Prompt_StfId->AutoSize = true;
			this->lbl_Prompt_StfId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_StfId->Location = System::Drawing::Point(219, 445);
			this->lbl_Prompt_StfId->Name = L"lbl_Prompt_StfId";
			this->lbl_Prompt_StfId->Size = System::Drawing::Size(136, 40);
			this->lbl_Prompt_StfId->TabIndex = 7;
			this->lbl_Prompt_StfId->Text = L"Staff ID";
			// 
			// lbl_Id
			// 
			this->lbl_Id->AutoSize = true;
			this->lbl_Id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Id->Location = System::Drawing::Point(467, 290);
			this->lbl_Id->Name = L"lbl_Id";
			this->lbl_Id->Size = System::Drawing::Size(77, 40);
			this->lbl_Id->TabIndex = 8;
			this->lbl_Id->Text = L"N/A";
			// 
			// lbl_StfId
			// 
			this->lbl_StfId->AutoSize = true;
			this->lbl_StfId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_StfId->Location = System::Drawing::Point(467, 445);
			this->lbl_StfId->Name = L"lbl_StfId";
			this->lbl_StfId->Size = System::Drawing::Size(77, 40);
			this->lbl_StfId->TabIndex = 11;
			this->lbl_StfId->Text = L"N/A";
			// 
			// cmb_Type
			// 
			this->cmb_Type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmb_Type->FormattingEnabled = true;
			this->cmb_Type->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Donation ", L"Selling ", L"Purchase ", L"Other" });
			this->cmb_Type->Location = System::Drawing::Point(460, 569);
			this->cmb_Type->Name = L"cmb_Type";
			this->cmb_Type->Size = System::Drawing::Size(285, 48);
			this->cmb_Type->TabIndex = 13;
			// 
			// txt_Comment
			// 
			this->txt_Comment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Comment->Location = System::Drawing::Point(226, 844);
			this->txt_Comment->Name = L"txt_Comment";
			this->txt_Comment->Size = System::Drawing::Size(1023, 288);
			this->txt_Comment->TabIndex = 14;
			this->txt_Comment->Text = L"";
			// 
			// txt_Time
			// 
			this->txt_Time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Time->Location = System::Drawing::Point(1050, 282);
			this->txt_Time->Name = L"txt_Time";
			this->txt_Time->Size = System::Drawing::Size(199, 48);
			this->txt_Time->TabIndex = 15;
			// 
			// txt_Amount
			// 
			this->txt_Amount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Amount->Location = System::Drawing::Point(1050, 437);
			this->txt_Amount->Name = L"txt_Amount";
			this->txt_Amount->Size = System::Drawing::Size(199, 48);
			this->txt_Amount->TabIndex = 16;
			// 
			// btn_Confirm
			// 
			this->btn_Confirm->Location = System::Drawing::Point(386, 1232);
			this->btn_Confirm->Name = L"btn_Confirm";
			this->btn_Confirm->Size = System::Drawing::Size(199, 103);
			this->btn_Confirm->TabIndex = 17;
			this->btn_Confirm->Text = L"Confirm";
			this->btn_Confirm->UseVisualStyleBackColor = true;
			this->btn_Confirm->Click += gcnew System::EventHandler(this, &TreAddPage::btn_Confirm_Click);
			// 
			// btn_Cancel
			// 
			this->btn_Cancel->Location = System::Drawing::Point(824, 1232);
			this->btn_Cancel->Name = L"btn_Cancel";
			this->btn_Cancel->Size = System::Drawing::Size(199, 103);
			this->btn_Cancel->TabIndex = 18;
			this->btn_Cancel->Text = L"Cancel";
			this->btn_Cancel->UseVisualStyleBackColor = true;
			this->btn_Cancel->Click += gcnew System::EventHandler(this, &TreAddPage::btn_Cancel_Click);
			// 
			// lbl_Error
			// 
			this->lbl_Error->AutoSize = true;
			this->lbl_Error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Error->Location = System::Drawing::Point(681, 741);
			this->lbl_Error->Name = L"lbl_Error";
			this->lbl_Error->Size = System::Drawing::Size(0, 40);
			this->lbl_Error->TabIndex = 19;
			// 
			// TreAddPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1412, 1400);
			this->Controls->Add(this->lbl_Error);
			this->Controls->Add(this->btn_Cancel);
			this->Controls->Add(this->btn_Confirm);
			this->Controls->Add(this->txt_Amount);
			this->Controls->Add(this->txt_Time);
			this->Controls->Add(this->txt_Comment);
			this->Controls->Add(this->cmb_Type);
			this->Controls->Add(this->lbl_StfId);
			this->Controls->Add(this->lbl_Id);
			this->Controls->Add(this->lbl_Prompt_StfId);
			this->Controls->Add(this->lbl_Prompt_Type);
			this->Controls->Add(this->lbl_Prompt_Amount);
			this->Controls->Add(this->lbl_Prompt_Comment);
			this->Controls->Add(this->lbl_Prompt_Id);
			this->Controls->Add(this->lbl_Prompt_Time);
			this->Controls->Add(this->lbl_Prompt_Title);
			this->Name = L"TreAddPage";
			this->Text = L"TreAddPage";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Void UpdateInfo(String^ OrderId);
		Void SetBoxReadOnly();

	private:
		String^ OrderId;
		Database^ _TreDB = gcnew Database(Database::DatabaseType::Treasury);

	private:
		System::Void btn_Confirm_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
