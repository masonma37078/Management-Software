#pragma once
#include "NewPage.h"

/*
 * StarterPage.h
 *
 * This file includes two basic functions: button_click and lable_change.
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
	/// Summary for StarterPage
	/// </summary>
	public ref class StarterPage : public System::Windows::Forms::Form
	{
	public:
		StarterPage(void)
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
		~StarterPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_JumpAnotherPage;
	protected:
	private: System::Windows::Forms::Button^ btn_ChangeLabel;
	private: System::Windows::Forms::Label^ lbl_Title;

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
			this->btn_JumpAnotherPage = (gcnew System::Windows::Forms::Button());
			this->btn_ChangeLabel = (gcnew System::Windows::Forms::Button());
			this->lbl_Title = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_JumpAnotherPage
			// 
			this->btn_JumpAnotherPage->Font = (gcnew System::Drawing::Font(L"SimSun", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_JumpAnotherPage->Location = System::Drawing::Point(210, 312);
			this->btn_JumpAnotherPage->Name = L"btn_JumpAnotherPage";
			this->btn_JumpAnotherPage->Size = System::Drawing::Size(214, 68);
			this->btn_JumpAnotherPage->TabIndex = 0;
			this->btn_JumpAnotherPage->Text = L"点击跳转页面";
			this->btn_JumpAnotherPage->UseVisualStyleBackColor = true;
			this->btn_JumpAnotherPage->Click += gcnew System::EventHandler(this, &StarterPage::btn_JumpAnotherPage_Click);
			// 
			// btn_ChangeLabel
			// 
			this->btn_ChangeLabel->Font = (gcnew System::Drawing::Font(L"SimSun", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_ChangeLabel->Location = System::Drawing::Point(210, 196);
			this->btn_ChangeLabel->Name = L"btn_ChangeLabel";
			this->btn_ChangeLabel->Size = System::Drawing::Size(214, 68);
			this->btn_ChangeLabel->TabIndex = 1;
			this->btn_ChangeLabel->Text = L"更改标签";
			this->btn_ChangeLabel->UseVisualStyleBackColor = true;
			this->btn_ChangeLabel->Click += gcnew System::EventHandler(this, &StarterPage::btn_ChangeLabel_Click);
			// 
			// lbl_Title
			// 
			this->lbl_Title->AutoSize = true;
			this->lbl_Title->Font = (gcnew System::Drawing::Font(L"SimSun", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Title->ForeColor = System::Drawing::Color::Blue;
			this->lbl_Title->Location = System::Drawing::Point(221, 101);
			this->lbl_Title->Name = L"lbl_Title";
			this->lbl_Title->Size = System::Drawing::Size(185, 22);
			this->lbl_Title->TabIndex = 2;
			this->lbl_Title->Text = L"UCSC-中国校友会";
			// 
			// StarterPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(636, 432);
			this->Controls->Add(this->lbl_Title);
			this->Controls->Add(this->btn_ChangeLabel);
			this->Controls->Add(this->btn_JumpAnotherPage);
			this->Name = L"StarterPage";
			this->Text = L"UCSC-CAA校友管理系统";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		enum class Lbl_Font {
			red,
			blue
		};
		Lbl_Font _font = Lbl_Font::blue;
		Void btn_ChangeLabel_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_JumpAnotherPage_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
