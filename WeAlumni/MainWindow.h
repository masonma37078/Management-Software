#pragma once
#include "Database.h"
#include "MemInfoPage.h"
#include "MemAddPage.h"
#include "StfInfoPage.h"
#include "StfAddPage.h"
#include "OrdInfoPage.h"
#include "OrdAddPage.h"
#define MEM_SELECT_ALL "SELECT Member.Id AS 'MemberId', Member.Status AS 'MemberStatus', Member.Type AS 'MemberType', Member.Name AS 'MemberName', Member.Gender AS 'MemberGender', Member.Email AS 'MemberEmail' FROM Member ORDER BY Id ASC"
#define STF_SELECT_ALL "SELECT Staff.MemId AS 'ID', Member.Name As 'Name', Member.Gender AS 'Gender', Member.Email AS 'Email', Staff.Dept As 'Department', Staff.Position As 'Position', Staff.Auth As 'Auth' FROM Member, Staff WHERE Staff.MemId = Member.Id ORDER BY Staff.MemId ASC"
#define ORD_SELECT_ALL "SELECT Orders.Id AS 'OrderId', Orders.Status As 'Status', Orders.Time AS 'Time', Member.Name AS 'MemName', Member.Email As 'Email', Item.Name As 'ItmName', Orders.Amount As 'Amount', Item.Price As 'ItmPrice', Orders.Comment As 'Comment' FROM Orders, Member, Item WHERE Orders.MemId = Member.Id AND Orders.ItemId = Item.Id ORDER BY Member.Id ASC"

/*
 * MainWindow.h
 *
 * This file initializes the MainWindow's UI and declares the sub-functions required.
 *
 * @author: Hang Yuan
 * Revised: 3/27/20
 *          4/8/20 add member MainWindow
 *          4/12/20 add staff MainWindow and auth control for staff and member
 *          4/15/20 bug fix
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
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Initialize();
		}
		MainWindow(PublicUserInfo^ pui) {
			InitializeComponent();
			_pui = pui;
			_Auth = pui->GetAuth();
			Initialize();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
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

	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer1;
	private: System::Windows::Forms::MenuStrip^ ms_systemOptions;
	private: System::Windows::Forms::MenuStrip^ ms_panelOptions;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_system;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_database;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_help;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_member;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_staff;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_record;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_OPT;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_order;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_treasury;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_myInfo;
	private: System::Windows::Forms::Panel^ pan_member;
	private: System::Windows::Forms::Panel^ pan_staff;
	private: System::Windows::Forms::Panel^ pan_record;
	private: System::Windows::Forms::Panel^ pan_OPT;
	private: System::Windows::Forms::Panel^ pan_order;
	private: System::Windows::Forms::Panel^ pan_treasury;
	private: System::Windows::Forms::TextBox^ mem_txt_Gender;
	private: System::Windows::Forms::TextBox^ mem_txt_Name;
	private: System::Windows::Forms::TextBox^ mem_txt_Major;
	private: System::Windows::Forms::TextBox^ mem_txt_Id;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_SearchAuth;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Major;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_CareerStatus;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Gender;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Name;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Type;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Status;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Id;
	private: System::Windows::Forms::ComboBox^ mem_cmb_SearchAuth;
	private: System::Windows::Forms::ComboBox^ mem_cmb_Type;
	private: System::Windows::Forms::ComboBox^ mem_cmb_Status;
	private: System::Windows::Forms::DataGridView^ mem_dataGridView1;
	private: System::Windows::Forms::Button^ mem_btn_Import;
	private: System::Windows::Forms::Button^ mem_btn_Add;
	private: System::Windows::Forms::Button^ mem_btn_Clear;
	private: System::Windows::Forms::Button^ mem_btn_Search;
	private: System::Windows::Forms::ComboBox^ mem_cmb_CareerStatus;
	private: System::Windows::Forms::Label^ mem_lbl_error;
	private: System::Windows::Forms::Button^ stf_btn_Add;
	private: System::Windows::Forms::Button^ stf_btn_Clear;
	private: System::Windows::Forms::Button^ stf_btn_Search;
	private: System::Windows::Forms::TextBox^ stf_txt_Name;
	private: System::Windows::Forms::TextBox^ stf_txt_Id;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Auth;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Dept;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Name;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Id;
	private: System::Windows::Forms::ComboBox^ stf_cmb_Auth;
	private: System::Windows::Forms::ComboBox^ stf_cmb_Dept;
	private: System::Windows::Forms::Label^ stf_lbl_Error;
	private: System::Windows::Forms::Label^ mem_Prompt_Result;
	private: System::Windows::Forms::Label^ mem_Prompt_ViewInfo;
	private: System::Windows::Forms::Label^ mem_Prompt_PgInfo;
	private: System::Windows::Forms::Splitter^ mem_splitter2;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Total;
	private: System::Windows::Forms::Label^ stf_lbl_Count;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Count;
	private: System::Windows::Forms::Splitter^ stf_splitter1;
	private: System::Windows::Forms::DataGridView^ stf_dataGridView;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_SearchResult;
	private: System::Windows::Forms::Splitter^ stf_splitter3;
	private: System::Windows::Forms::Splitter^ stf_splitter2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ mem_lbl_Count;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_ordId;
	private: System::Windows::Forms::TextBox^ ord_txt_ordId;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_Status;
	private: System::Windows::Forms::ComboBox^ ord_cmb_Status;
	private: System::Windows::Forms::TextBox^ ord_txt_memId;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_memId;
	private: System::Windows::Forms::TextBox^ ord_txt_itmName;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_itmName;
	private: System::Windows::Forms::TextBox^ ord_txt_itmId;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_itmId;
	private: System::Windows::Forms::TextBox^ ord_txt_memName;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_memName;
	private: System::Windows::Forms::DataGridView^ ord_dataGridView;
	private: System::Windows::Forms::Splitter^ ord_splitter;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_SearchResult;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_Count;
	private: System::Windows::Forms::Label^ ord_lbl_Count;
	private: System::Windows::Forms::Button^ ord_btn_Search;
	private: System::Windows::Forms::Button^ ord_btn_Clear;
	private: System::Windows::Forms::Button^ ord_btn_Add;
	private: System::Windows::Forms::Splitter^ ord_splitter_Error;
	private: System::Windows::Forms::Label^ ord_lbl_Error;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_ViewInfo;

	private: System::Windows::Forms::Panel^ pan_myInfo;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
			   this->pan_order = (gcnew System::Windows::Forms::Panel());
			   this->ord_lbl_Prompt_ViewInfo = (gcnew System::Windows::Forms::Label());
			   this->ord_lbl_Error = (gcnew System::Windows::Forms::Label());
			   this->ord_splitter_Error = (gcnew System::Windows::Forms::Splitter());
			   this->ord_btn_Add = (gcnew System::Windows::Forms::Button());
			   this->ord_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->ord_btn_Search = (gcnew System::Windows::Forms::Button());
			   this->ord_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->ord_lbl_Prompt_Count = (gcnew System::Windows::Forms::Label());
			   this->ord_lbl_Prompt_SearchResult = (gcnew System::Windows::Forms::Label());
			   this->ord_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->ord_txt_itmName = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_itmName = (gcnew System::Windows::Forms::Label());
			   this->ord_txt_itmId = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_itmId = (gcnew System::Windows::Forms::Label());
			   this->ord_txt_memName = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_memName = (gcnew System::Windows::Forms::Label());
			   this->ord_txt_memId = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_memId = (gcnew System::Windows::Forms::Label());
			   this->ord_cmb_Status = (gcnew System::Windows::Forms::ComboBox());
			   this->ord_lbl_Prompt_Status = (gcnew System::Windows::Forms::Label());
			   this->ord_txt_ordId = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_ordId = (gcnew System::Windows::Forms::Label());
			   this->ord_splitter = (gcnew System::Windows::Forms::Splitter());
			   this->pan_member = (gcnew System::Windows::Forms::Panel());
			   this->mem_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Total = (gcnew System::Windows::Forms::Label());
			   this->mem_Prompt_PgInfo = (gcnew System::Windows::Forms::Label());
			   this->mem_Prompt_ViewInfo = (gcnew System::Windows::Forms::Label());
			   this->mem_Prompt_Result = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_error = (gcnew System::Windows::Forms::Label());
			   this->mem_btn_Import = (gcnew System::Windows::Forms::Button());
			   this->mem_btn_Add = (gcnew System::Windows::Forms::Button());
			   this->mem_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->mem_btn_Search = (gcnew System::Windows::Forms::Button());
			   this->mem_cmb_CareerStatus = (gcnew System::Windows::Forms::ComboBox());
			   this->mem_dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->mem_cmb_SearchAuth = (gcnew System::Windows::Forms::ComboBox());
			   this->mem_cmb_Type = (gcnew System::Windows::Forms::ComboBox());
			   this->mem_cmb_Status = (gcnew System::Windows::Forms::ComboBox());
			   this->mem_txt_Gender = (gcnew System::Windows::Forms::TextBox());
			   this->mem_txt_Name = (gcnew System::Windows::Forms::TextBox());
			   this->mem_txt_Major = (gcnew System::Windows::Forms::TextBox());
			   this->mem_txt_Id = (gcnew System::Windows::Forms::TextBox());
			   this->mem_lbl_Prompt_SearchAuth = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Major = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_CareerStatus = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Gender = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Name = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Type = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Status = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Id = (gcnew System::Windows::Forms::Label());
			   this->mem_splitter2 = (gcnew System::Windows::Forms::Splitter());
			   this->pan_staff = (gcnew System::Windows::Forms::Panel());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_SearchResult = (gcnew System::Windows::Forms::Label());
			   this->stf_splitter3 = (gcnew System::Windows::Forms::Splitter());
			   this->stf_splitter2 = (gcnew System::Windows::Forms::Splitter());
			   this->stf_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->stf_splitter1 = (gcnew System::Windows::Forms::Splitter());
			   this->stf_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_Count = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Error = (gcnew System::Windows::Forms::Label());
			   this->stf_cmb_Auth = (gcnew System::Windows::Forms::ComboBox());
			   this->stf_cmb_Dept = (gcnew System::Windows::Forms::ComboBox());
			   this->stf_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->stf_btn_Search = (gcnew System::Windows::Forms::Button());
			   this->stf_txt_Name = (gcnew System::Windows::Forms::TextBox());
			   this->stf_txt_Id = (gcnew System::Windows::Forms::TextBox());
			   this->stf_lbl_Prompt_Auth = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_Dept = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_Name = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_Id = (gcnew System::Windows::Forms::Label());
			   this->stf_btn_Add = (gcnew System::Windows::Forms::Button());
			   this->pan_record = (gcnew System::Windows::Forms::Panel());
			   this->pan_OPT = (gcnew System::Windows::Forms::Panel());
			   this->pan_treasury = (gcnew System::Windows::Forms::Panel());
			   this->pan_myInfo = (gcnew System::Windows::Forms::Panel());
			   this->ms_panelOptions = (gcnew System::Windows::Forms::MenuStrip());
			   this->tsm_member = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_staff = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_record = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_OPT = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_order = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_treasury = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_myInfo = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ms_systemOptions = (gcnew System::Windows::Forms::MenuStrip());
			   this->tsm_system = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_database = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_help = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolStripContainer1->ContentPanel->SuspendLayout();
			   this->toolStripContainer1->LeftToolStripPanel->SuspendLayout();
			   this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
			   this->toolStripContainer1->SuspendLayout();
			   this->pan_order->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ord_dataGridView))->BeginInit();
			   this->pan_member->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mem_dataGridView1))->BeginInit();
			   this->pan_staff->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stf_dataGridView))->BeginInit();
			   this->ms_panelOptions->SuspendLayout();
			   this->ms_systemOptions->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // toolStripContainer1
			   // 
			   // 
			   // toolStripContainer1.ContentPanel
			   // 
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_order);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_member);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_staff);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_record);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_OPT);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_treasury);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_myInfo);
			   this->toolStripContainer1->ContentPanel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(1359, 784);
			   this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			   // 
			   // toolStripContainer1.LeftToolStripPanel
			   // 
			   this->toolStripContainer1->LeftToolStripPanel->Controls->Add(this->ms_panelOptions);
			   this->toolStripContainer1->Location = System::Drawing::Point(0, 0);
			   this->toolStripContainer1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->toolStripContainer1->Name = L"toolStripContainer1";
			   this->toolStripContainer1->Size = System::Drawing::Size(1509, 812);
			   this->toolStripContainer1->TabIndex = 0;
			   this->toolStripContainer1->Text = L"toolStripContainer1";
			   // 
			   // toolStripContainer1.TopToolStripPanel
			   // 
			   this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->ms_systemOptions);
			   // 
			   // pan_order
			   // 
			   this->pan_order->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_ViewInfo);
			   this->pan_order->Controls->Add(this->ord_lbl_Error);
			   this->pan_order->Controls->Add(this->ord_splitter_Error);
			   this->pan_order->Controls->Add(this->ord_btn_Add);
			   this->pan_order->Controls->Add(this->ord_btn_Clear);
			   this->pan_order->Controls->Add(this->ord_btn_Search);
			   this->pan_order->Controls->Add(this->ord_lbl_Count);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_Count);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_SearchResult);
			   this->pan_order->Controls->Add(this->ord_dataGridView);
			   this->pan_order->Controls->Add(this->ord_txt_itmName);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_itmName);
			   this->pan_order->Controls->Add(this->ord_txt_itmId);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_itmId);
			   this->pan_order->Controls->Add(this->ord_txt_memName);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_memName);
			   this->pan_order->Controls->Add(this->ord_txt_memId);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_memId);
			   this->pan_order->Controls->Add(this->ord_cmb_Status);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_Status);
			   this->pan_order->Controls->Add(this->ord_txt_ordId);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_ordId);
			   this->pan_order->Controls->Add(this->ord_splitter);
			   this->pan_order->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_order->Location = System::Drawing::Point(0, 0);
			   this->pan_order->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_order->Name = L"pan_order";
			   this->pan_order->Size = System::Drawing::Size(1359, 784);
			   this->pan_order->TabIndex = 2;
			   // 
			   // ord_lbl_Prompt_ViewInfo
			   // 
			   this->ord_lbl_Prompt_ViewInfo->AutoSize = true;
			   this->ord_lbl_Prompt_ViewInfo->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Prompt_ViewInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_ViewInfo->Location = System::Drawing::Point(1002, 483);
			   this->ord_lbl_Prompt_ViewInfo->Name = L"ord_lbl_Prompt_ViewInfo";
			   this->ord_lbl_Prompt_ViewInfo->Size = System::Drawing::Size(172, 25);
			   this->ord_lbl_Prompt_ViewInfo->TabIndex = 22;
			   this->ord_lbl_Prompt_ViewInfo->Text = L"��ʾ����Ĭ����Ϣ";
			   // 
			   // ord_lbl_Error
			   // 
			   this->ord_lbl_Error->AutoSize = true;
			   this->ord_lbl_Error->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Error->ForeColor = System::Drawing::Color::Red;
			   this->ord_lbl_Error->Location = System::Drawing::Point(638, 385);
			   this->ord_lbl_Error->Name = L"ord_lbl_Error";
			   this->ord_lbl_Error->Size = System::Drawing::Size(96, 25);
			   this->ord_lbl_Error->TabIndex = 21;
			   this->ord_lbl_Error->Text = L"�˴�����";
			   // 
			   // ord_splitter_Error
			   // 
			   this->ord_splitter_Error->BackColor = System::Drawing::Color::DarkOrange;
			   this->ord_splitter_Error->Cursor = System::Windows::Forms::Cursors::HSplit;
			   this->ord_splitter_Error->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->ord_splitter_Error->Enabled = false;
			   this->ord_splitter_Error->Location = System::Drawing::Point(0, 347);
			   this->ord_splitter_Error->Name = L"ord_splitter_Error";
			   this->ord_splitter_Error->Size = System::Drawing::Size(1359, 91);
			   this->ord_splitter_Error->TabIndex = 20;
			   this->ord_splitter_Error->TabStop = false;
			   // 
			   // ord_btn_Add
			   // 
			   this->ord_btn_Add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_btn_Add->Location = System::Drawing::Point(846, 211);
			   this->ord_btn_Add->Name = L"ord_btn_Add";
			   this->ord_btn_Add->Size = System::Drawing::Size(100, 46);
			   this->ord_btn_Add->TabIndex = 19;
			   this->ord_btn_Add->Text = L"���";
			   this->ord_btn_Add->UseVisualStyleBackColor = true;
			   this->ord_btn_Add->Click += gcnew System::EventHandler(this, &MainWindow::ord_btn_Add_Click);
			   // 
			   // ord_btn_Clear
			   // 
			   this->ord_btn_Clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_btn_Clear->Location = System::Drawing::Point(846, 143);
			   this->ord_btn_Clear->Name = L"ord_btn_Clear";
			   this->ord_btn_Clear->Size = System::Drawing::Size(100, 46);
			   this->ord_btn_Clear->TabIndex = 18;
			   this->ord_btn_Clear->Text = L"���";
			   this->ord_btn_Clear->UseVisualStyleBackColor = true;
			   this->ord_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::ord_btn_Clear_Click);
			   // 
			   // ord_btn_Search
			   // 
			   this->ord_btn_Search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_btn_Search->Location = System::Drawing::Point(846, 77);
			   this->ord_btn_Search->Name = L"ord_btn_Search";
			   this->ord_btn_Search->Size = System::Drawing::Size(100, 46);
			   this->ord_btn_Search->TabIndex = 17;
			   this->ord_btn_Search->Text = L"��ѯ";
			   this->ord_btn_Search->UseVisualStyleBackColor = true;
			   this->ord_btn_Search->Click += gcnew System::EventHandler(this, &MainWindow::ord_btn_Search_Click);
			   // 
			   // ord_lbl_Count
			   // 
			   this->ord_lbl_Count->AutoSize = true;
			   this->ord_lbl_Count->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Count->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Count->Location = System::Drawing::Point(180, 483);
			   this->ord_lbl_Count->Name = L"ord_lbl_Count";
			   this->ord_lbl_Count->Size = System::Drawing::Size(46, 25);
			   this->ord_lbl_Count->TabIndex = 16;
			   this->ord_lbl_Count->Text = L"N/A";
			   // 
			   // ord_lbl_Prompt_Count
			   // 
			   this->ord_lbl_Prompt_Count->AutoSize = true;
			   this->ord_lbl_Prompt_Count->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Prompt_Count->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_Count->Location = System::Drawing::Point(81, 483);
			   this->ord_lbl_Prompt_Count->Name = L"ord_lbl_Prompt_Count";
			   this->ord_lbl_Prompt_Count->Size = System::Drawing::Size(75, 25);
			   this->ord_lbl_Prompt_Count->TabIndex = 15;
			   this->ord_lbl_Prompt_Count->Text = L"�ܼƣ�";
			   // 
			   // ord_lbl_Prompt_SearchResult
			   // 
			   this->ord_lbl_Prompt_SearchResult->AutoSize = true;
			   this->ord_lbl_Prompt_SearchResult->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Prompt_SearchResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_SearchResult->Location = System::Drawing::Point(593, 470);
			   this->ord_lbl_Prompt_SearchResult->Name = L"ord_lbl_Prompt_SearchResult";
			   this->ord_lbl_Prompt_SearchResult->Size = System::Drawing::Size(153, 38);
			   this->ord_lbl_Prompt_SearchResult->TabIndex = 14;
			   this->ord_lbl_Prompt_SearchResult->Text = L"�������";
			   // 
			   // ord_dataGridView
			   // 
			   this->ord_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->ord_dataGridView->Location = System::Drawing::Point(86, 536);
			   this->ord_dataGridView->Name = L"ord_dataGridView";
			   this->ord_dataGridView->RowHeadersWidth = 51;
			   this->ord_dataGridView->RowTemplate->Height = 24;
			   this->ord_dataGridView->Size = System::Drawing::Size(1186, 222);
			   this->ord_dataGridView->TabIndex = 12;
			   this->ord_dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::ord_dataGridView_CellContentClick);
			   // 
			   // ord_txt_itmName
			   // 
			   this->ord_txt_itmName->Location = System::Drawing::Point(555, 215);
			   this->ord_txt_itmName->Name = L"ord_txt_itmName";
			   this->ord_txt_itmName->Size = System::Drawing::Size(121, 22);
			   this->ord_txt_itmName->TabIndex = 11;
			   // 
			   // ord_lbl_Prompt_itmName
			   // 
			   this->ord_lbl_Prompt_itmName->AutoSize = true;
			   this->ord_lbl_Prompt_itmName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_itmName->Location = System::Drawing::Point(393, 211);
			   this->ord_lbl_Prompt_itmName->Name = L"ord_lbl_Prompt_itmName";
			   this->ord_lbl_Prompt_itmName->Size = System::Drawing::Size(96, 25);
			   this->ord_lbl_Prompt_itmName->TabIndex = 10;
			   this->ord_lbl_Prompt_itmName->Text = L"��Ʒ����";
			   // 
			   // ord_txt_itmId
			   // 
			   this->ord_txt_itmId->Location = System::Drawing::Point(226, 213);
			   this->ord_txt_itmId->Name = L"ord_txt_itmId";
			   this->ord_txt_itmId->Size = System::Drawing::Size(121, 22);
			   this->ord_txt_itmId->TabIndex = 9;
			   // 
			   // ord_lbl_Prompt_itmId
			   // 
			   this->ord_lbl_Prompt_itmId->AutoSize = true;
			   this->ord_lbl_Prompt_itmId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_itmId->Location = System::Drawing::Point(89, 210);
			   this->ord_lbl_Prompt_itmId->Name = L"ord_lbl_Prompt_itmId";
			   this->ord_lbl_Prompt_itmId->Size = System::Drawing::Size(96, 25);
			   this->ord_lbl_Prompt_itmId->TabIndex = 8;
			   this->ord_lbl_Prompt_itmId->Text = L"��Ʒ���";
			   // 
			   // ord_txt_memName
			   // 
			   this->ord_txt_memName->Location = System::Drawing::Point(555, 148);
			   this->ord_txt_memName->Name = L"ord_txt_memName";
			   this->ord_txt_memName->Size = System::Drawing::Size(121, 22);
			   this->ord_txt_memName->TabIndex = 7;
			   // 
			   // ord_lbl_Prompt_memName
			   // 
			   this->ord_lbl_Prompt_memName->AutoSize = true;
			   this->ord_lbl_Prompt_memName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_memName->Location = System::Drawing::Point(393, 144);
			   this->ord_lbl_Prompt_memName->Name = L"ord_lbl_Prompt_memName";
			   this->ord_lbl_Prompt_memName->Size = System::Drawing::Size(96, 25);
			   this->ord_lbl_Prompt_memName->TabIndex = 6;
			   this->ord_lbl_Prompt_memName->Text = L"��Ա����";
			   // 
			   // ord_txt_memId
			   // 
			   this->ord_txt_memId->Location = System::Drawing::Point(226, 144);
			   this->ord_txt_memId->Name = L"ord_txt_memId";
			   this->ord_txt_memId->Size = System::Drawing::Size(121, 22);
			   this->ord_txt_memId->TabIndex = 5;
			   // 
			   // ord_lbl_Prompt_memId
			   // 
			   this->ord_lbl_Prompt_memId->AutoSize = true;
			   this->ord_lbl_Prompt_memId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_memId->Location = System::Drawing::Point(89, 141);
			   this->ord_lbl_Prompt_memId->Name = L"ord_lbl_Prompt_memId";
			   this->ord_lbl_Prompt_memId->Size = System::Drawing::Size(96, 25);
			   this->ord_lbl_Prompt_memId->TabIndex = 4;
			   this->ord_lbl_Prompt_memId->Text = L"��Ա���";
			   // 
			   // ord_cmb_Status
			   // 
			   this->ord_cmb_Status->FormattingEnabled = true;
			   this->ord_cmb_Status->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Active", L"InvalidComplete", L"In process" });
			   this->ord_cmb_Status->Location = System::Drawing::Point(555, 77);
			   this->ord_cmb_Status->Name = L"ord_cmb_Status";
			   this->ord_cmb_Status->Size = System::Drawing::Size(121, 24);
			   this->ord_cmb_Status->TabIndex = 3;
			   // 
			   // ord_lbl_Prompt_Status
			   // 
			   this->ord_lbl_Prompt_Status->AutoSize = true;
			   this->ord_lbl_Prompt_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_Status->Location = System::Drawing::Point(393, 77);
			   this->ord_lbl_Prompt_Status->Name = L"ord_lbl_Prompt_Status";
			   this->ord_lbl_Prompt_Status->Size = System::Drawing::Size(96, 25);
			   this->ord_lbl_Prompt_Status->TabIndex = 2;
			   this->ord_lbl_Prompt_Status->Text = L"����״̬";
			   // 
			   // ord_txt_ordId
			   // 
			   this->ord_txt_ordId->Location = System::Drawing::Point(226, 77);
			   this->ord_txt_ordId->Name = L"ord_txt_ordId";
			   this->ord_txt_ordId->Size = System::Drawing::Size(121, 22);
			   this->ord_txt_ordId->TabIndex = 1;
			   // 
			   // ord_lbl_Prompt_ordId
			   // 
			   this->ord_lbl_Prompt_ordId->AutoSize = true;
			   this->ord_lbl_Prompt_ordId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_ordId->Location = System::Drawing::Point(90, 77);
			   this->ord_lbl_Prompt_ordId->Name = L"ord_lbl_Prompt_ordId";
			   this->ord_lbl_Prompt_ordId->Size = System::Drawing::Size(96, 25);
			   this->ord_lbl_Prompt_ordId->TabIndex = 0;
			   this->ord_lbl_Prompt_ordId->Text = L"�������";
			   // 
			   // ord_splitter
			   // 
			   this->ord_splitter->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->ord_splitter->Cursor = System::Windows::Forms::Cursors::HSplit;
			   this->ord_splitter->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->ord_splitter->Enabled = false;
			   this->ord_splitter->Location = System::Drawing::Point(0, 438);
			   this->ord_splitter->Name = L"ord_splitter";
			   this->ord_splitter->Size = System::Drawing::Size(1359, 346);
			   this->ord_splitter->TabIndex = 13;
			   this->ord_splitter->TabStop = false;
			   // 
			   // pan_member
			   // 
			   this->pan_member->Controls->Add(this->mem_lbl_Count);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Total);
			   this->pan_member->Controls->Add(this->mem_Prompt_PgInfo);
			   this->pan_member->Controls->Add(this->mem_Prompt_ViewInfo);
			   this->pan_member->Controls->Add(this->mem_Prompt_Result);
			   this->pan_member->Controls->Add(this->mem_lbl_error);
			   this->pan_member->Controls->Add(this->mem_btn_Import);
			   this->pan_member->Controls->Add(this->mem_btn_Add);
			   this->pan_member->Controls->Add(this->mem_btn_Clear);
			   this->pan_member->Controls->Add(this->mem_btn_Search);
			   this->pan_member->Controls->Add(this->mem_cmb_CareerStatus);
			   this->pan_member->Controls->Add(this->mem_dataGridView1);
			   this->pan_member->Controls->Add(this->mem_cmb_SearchAuth);
			   this->pan_member->Controls->Add(this->mem_cmb_Type);
			   this->pan_member->Controls->Add(this->mem_cmb_Status);
			   this->pan_member->Controls->Add(this->mem_txt_Gender);
			   this->pan_member->Controls->Add(this->mem_txt_Name);
			   this->pan_member->Controls->Add(this->mem_txt_Major);
			   this->pan_member->Controls->Add(this->mem_txt_Id);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_SearchAuth);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Major);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_CareerStatus);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Gender);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Name);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Type);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Status);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Id);
			   this->pan_member->Controls->Add(this->mem_splitter2);
			   this->pan_member->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_member->Location = System::Drawing::Point(0, 0);
			   this->pan_member->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_member->Name = L"pan_member";
			   this->pan_member->Size = System::Drawing::Size(1359, 784);
			   this->pan_member->TabIndex = 6;
			   // 
			   // mem_lbl_Count
			   // 
			   this->mem_lbl_Count->AccessibleDescription = L"";
			   this->mem_lbl_Count->AutoSize = true;
			   this->mem_lbl_Count->Location = System::Drawing::Point(115, 347);
			   this->mem_lbl_Count->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_lbl_Count->Name = L"mem_lbl_Count";
			   this->mem_lbl_Count->Size = System::Drawing::Size(16, 17);
			   this->mem_lbl_Count->TabIndex = 70;
			   this->mem_lbl_Count->Text = L"0";
			   // 
			   // mem_lbl_Prompt_Total
			   // 
			   this->mem_lbl_Prompt_Total->AccessibleDescription = L"";
			   this->mem_lbl_Prompt_Total->AutoSize = true;
			   this->mem_lbl_Prompt_Total->Location = System::Drawing::Point(61, 347);
			   this->mem_lbl_Prompt_Total->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_lbl_Prompt_Total->Name = L"mem_lbl_Prompt_Total";
			   this->mem_lbl_Prompt_Total->Size = System::Drawing::Size(44, 17);
			   this->mem_lbl_Prompt_Total->TabIndex = 69;
			   this->mem_lbl_Prompt_Total->Text = L"Total:";
			   // 
			   // mem_Prompt_PgInfo
			   // 
			   this->mem_Prompt_PgInfo->AccessibleDescription = L"";
			   this->mem_Prompt_PgInfo->AutoSize = true;
			   this->mem_Prompt_PgInfo->Location = System::Drawing::Point(40, 247);
			   this->mem_Prompt_PgInfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_Prompt_PgInfo->Name = L"mem_Prompt_PgInfo";
			   this->mem_Prompt_PgInfo->Size = System::Drawing::Size(728, 17);
			   this->mem_Prompt_PgInfo->TabIndex = 67;
			   this->mem_Prompt_PgInfo->Text = L"The data is accurately queried and there are no necessary items. Please provide a"
				   L"s much information as possible.";
			   // 
			   // mem_Prompt_ViewInfo
			   // 
			   this->mem_Prompt_ViewInfo->AutoSize = true;
			   this->mem_Prompt_ViewInfo->Location = System::Drawing::Point(869, 356);
			   this->mem_Prompt_ViewInfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_Prompt_ViewInfo->Name = L"mem_Prompt_ViewInfo";
			   this->mem_Prompt_ViewInfo->Size = System::Drawing::Size(257, 17);
			   this->mem_Prompt_ViewInfo->TabIndex = 24;
			   this->mem_Prompt_ViewInfo->Text = L"All member info will be shown by default";
			   // 
			   // mem_Prompt_Result
			   // 
			   this->mem_Prompt_Result->AutoSize = true;
			   this->mem_Prompt_Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->mem_Prompt_Result->Location = System::Drawing::Point(593, 347);
			   this->mem_Prompt_Result->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_Prompt_Result->Name = L"mem_Prompt_Result";
			   this->mem_Prompt_Result->Size = System::Drawing::Size(147, 25);
			   this->mem_Prompt_Result->TabIndex = 23;
			   this->mem_Prompt_Result->Text = L"Search Result";
			   // 
			   // mem_lbl_error
			   // 
			   this->mem_lbl_error->AutoSize = true;
			   this->mem_lbl_error->ForeColor = System::Drawing::Color::Red;
			   this->mem_lbl_error->Location = System::Drawing::Point(640, 572);
			   this->mem_lbl_error->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_lbl_error->Name = L"mem_lbl_error";
			   this->mem_lbl_error->Size = System::Drawing::Size(40, 17);
			   this->mem_lbl_error->TabIndex = 22;
			   this->mem_lbl_error->Text = L"Error";
			   this->mem_lbl_error->Visible = false;
			   // 
			   // mem_btn_Import
			   // 
			   this->mem_btn_Import->Location = System::Drawing::Point(1057, 271);
			   this->mem_btn_Import->Margin = System::Windows::Forms::Padding(4);
			   this->mem_btn_Import->Name = L"mem_btn_Import";
			   this->mem_btn_Import->Size = System::Drawing::Size(93, 34);
			   this->mem_btn_Import->TabIndex = 21;
			   this->mem_btn_Import->Text = L"Import";
			   this->mem_btn_Import->UseVisualStyleBackColor = true;
			   this->mem_btn_Import->Click += gcnew System::EventHandler(this, &MainWindow::mem_btn_Import_Click);
			   // 
			   // mem_btn_Add
			   // 
			   this->mem_btn_Add->Location = System::Drawing::Point(1057, 199);
			   this->mem_btn_Add->Margin = System::Windows::Forms::Padding(4);
			   this->mem_btn_Add->Name = L"mem_btn_Add";
			   this->mem_btn_Add->Size = System::Drawing::Size(93, 34);
			   this->mem_btn_Add->TabIndex = 20;
			   this->mem_btn_Add->Text = L"Add";
			   this->mem_btn_Add->UseVisualStyleBackColor = true;
			   this->mem_btn_Add->Click += gcnew System::EventHandler(this, &MainWindow::mem_btn_Add_Click);
			   // 
			   // mem_btn_Clear
			   // 
			   this->mem_btn_Clear->Location = System::Drawing::Point(1057, 124);
			   this->mem_btn_Clear->Margin = System::Windows::Forms::Padding(4);
			   this->mem_btn_Clear->Name = L"mem_btn_Clear";
			   this->mem_btn_Clear->Size = System::Drawing::Size(93, 34);
			   this->mem_btn_Clear->TabIndex = 19;
			   this->mem_btn_Clear->Text = L"Clear";
			   this->mem_btn_Clear->UseVisualStyleBackColor = true;
			   this->mem_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::mem_btn_Clear_Click);
			   // 
			   // mem_btn_Search
			   // 
			   this->mem_btn_Search->Location = System::Drawing::Point(1057, 52);
			   this->mem_btn_Search->Margin = System::Windows::Forms::Padding(4);
			   this->mem_btn_Search->Name = L"mem_btn_Search";
			   this->mem_btn_Search->Size = System::Drawing::Size(93, 34);
			   this->mem_btn_Search->TabIndex = 18;
			   this->mem_btn_Search->Text = L"Search";
			   this->mem_btn_Search->UseVisualStyleBackColor = true;
			   this->mem_btn_Search->Click += gcnew System::EventHandler(this, &MainWindow::mem_btn_Search_Click);
			   // 
			   // mem_cmb_CareerStatus
			   // 
			   this->mem_cmb_CareerStatus->FormattingEnabled = true;
			   this->mem_cmb_CareerStatus->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				   L"GradProgram", L"Unemployed", L"Employed",
					   L"StartBusiness"
			   });
			   this->mem_cmb_CareerStatus->Location = System::Drawing::Point(160, 139);
			   this->mem_cmb_CareerStatus->Margin = System::Windows::Forms::Padding(4);
			   this->mem_cmb_CareerStatus->Name = L"mem_cmb_CareerStatus";
			   this->mem_cmb_CareerStatus->Size = System::Drawing::Size(137, 24);
			   this->mem_cmb_CareerStatus->TabIndex = 17;
			   // 
			   // mem_dataGridView1
			   // 
			   this->mem_dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->mem_dataGridView1->Location = System::Drawing::Point(0, 375);
			   this->mem_dataGridView1->Margin = System::Windows::Forms::Padding(4);
			   this->mem_dataGridView1->Name = L"mem_dataGridView1";
			   this->mem_dataGridView1->RowHeadersWidth = 51;
			   this->mem_dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->mem_dataGridView1->Size = System::Drawing::Size(1309, 407);
			   this->mem_dataGridView1->TabIndex = 16;
			   this->mem_dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::mem_dataGridView1_CellContentClick);
			   // 
			   // mem_cmb_SearchAuth
			   // 
			   this->mem_cmb_SearchAuth->FormattingEnabled = true;
			   this->mem_cmb_SearchAuth->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Yes", L"No" });
			   this->mem_cmb_SearchAuth->Location = System::Drawing::Point(709, 138);
			   this->mem_cmb_SearchAuth->Margin = System::Windows::Forms::Padding(4);
			   this->mem_cmb_SearchAuth->Name = L"mem_cmb_SearchAuth";
			   this->mem_cmb_SearchAuth->Size = System::Drawing::Size(99, 24);
			   this->mem_cmb_SearchAuth->TabIndex = 15;
			   // 
			   // mem_cmb_Type
			   // 
			   this->mem_cmb_Type->FormattingEnabled = true;
			   this->mem_cmb_Type->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Normal", L"DivHead", L"Staff", L"Head" });
			   this->mem_cmb_Type->Location = System::Drawing::Point(251, 68);
			   this->mem_cmb_Type->Margin = System::Windows::Forms::Padding(4);
			   this->mem_cmb_Type->Name = L"mem_cmb_Type";
			   this->mem_cmb_Type->Size = System::Drawing::Size(135, 24);
			   this->mem_cmb_Type->TabIndex = 14;
			   // 
			   // mem_cmb_Status
			   // 
			   this->mem_cmb_Status->FormattingEnabled = true;
			   this->mem_cmb_Status->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Active", L"Review", L"Invalid" });
			   this->mem_cmb_Status->Location = System::Drawing::Point(444, 66);
			   this->mem_cmb_Status->Margin = System::Windows::Forms::Padding(4);
			   this->mem_cmb_Status->Name = L"mem_cmb_Status";
			   this->mem_cmb_Status->Size = System::Drawing::Size(135, 24);
			   this->mem_cmb_Status->TabIndex = 13;
			   // 
			   // mem_txt_Gender
			   // 
			   this->mem_txt_Gender->Location = System::Drawing::Point(837, 66);
			   this->mem_txt_Gender->Margin = System::Windows::Forms::Padding(4);
			   this->mem_txt_Gender->Name = L"mem_txt_Gender";
			   this->mem_txt_Gender->Size = System::Drawing::Size(99, 22);
			   this->mem_txt_Gender->TabIndex = 11;
			   // 
			   // mem_txt_Name
			   // 
			   this->mem_txt_Name->Location = System::Drawing::Point(649, 66);
			   this->mem_txt_Name->Margin = System::Windows::Forms::Padding(4);
			   this->mem_txt_Name->Name = L"mem_txt_Name";
			   this->mem_txt_Name->Size = System::Drawing::Size(99, 22);
			   this->mem_txt_Name->TabIndex = 10;
			   // 
			   // mem_txt_Major
			   // 
			   this->mem_txt_Major->Location = System::Drawing::Point(411, 139);
			   this->mem_txt_Major->Margin = System::Windows::Forms::Padding(4);
			   this->mem_txt_Major->Name = L"mem_txt_Major";
			   this->mem_txt_Major->Size = System::Drawing::Size(152, 22);
			   this->mem_txt_Major->TabIndex = 9;
			   // 
			   // mem_txt_Id
			   // 
			   this->mem_txt_Id->Location = System::Drawing::Point(86, 70);
			   this->mem_txt_Id->Margin = System::Windows::Forms::Padding(4);
			   this->mem_txt_Id->Name = L"mem_txt_Id";
			   this->mem_txt_Id->Size = System::Drawing::Size(99, 22);
			   this->mem_txt_Id->TabIndex = 8;
			   // 
			   // mem_lbl_Prompt_SearchAuth
			   // 
			   this->mem_lbl_Prompt_SearchAuth->AutoSize = true;
			   this->mem_lbl_Prompt_SearchAuth->Location = System::Drawing::Point(617, 143);
			   this->mem_lbl_Prompt_SearchAuth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_lbl_Prompt_SearchAuth->Name = L"mem_lbl_Prompt_SearchAuth";
			   this->mem_lbl_Prompt_SearchAuth->Size = System::Drawing::Size(82, 17);
			   this->mem_lbl_Prompt_SearchAuth->TabIndex = 7;
			   this->mem_lbl_Prompt_SearchAuth->Text = L"SearchAuth";
			   // 
			   // mem_lbl_Prompt_Major
			   // 
			   this->mem_lbl_Prompt_Major->AutoSize = true;
			   this->mem_lbl_Prompt_Major->Location = System::Drawing::Point(343, 143);
			   this->mem_lbl_Prompt_Major->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_lbl_Prompt_Major->Name = L"mem_lbl_Prompt_Major";
			   this->mem_lbl_Prompt_Major->Size = System::Drawing::Size(43, 17);
			   this->mem_lbl_Prompt_Major->TabIndex = 6;
			   this->mem_lbl_Prompt_Major->Text = L"Major";
			   // 
			   // mem_lbl_Prompt_CareerStatus
			   // 
			   this->mem_lbl_Prompt_CareerStatus->AutoSize = true;
			   this->mem_lbl_Prompt_CareerStatus->Location = System::Drawing::Point(61, 143);
			   this->mem_lbl_Prompt_CareerStatus->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_lbl_Prompt_CareerStatus->Name = L"mem_lbl_Prompt_CareerStatus";
			   this->mem_lbl_Prompt_CareerStatus->Size = System::Drawing::Size(91, 17);
			   this->mem_lbl_Prompt_CareerStatus->TabIndex = 5;
			   this->mem_lbl_Prompt_CareerStatus->Text = L"CareerStatus";
			   // 
			   // mem_lbl_Prompt_Gender
			   // 
			   this->mem_lbl_Prompt_Gender->AutoSize = true;
			   this->mem_lbl_Prompt_Gender->Location = System::Drawing::Point(773, 70);
			   this->mem_lbl_Prompt_Gender->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_lbl_Prompt_Gender->Name = L"mem_lbl_Prompt_Gender";
			   this->mem_lbl_Prompt_Gender->Size = System::Drawing::Size(56, 17);
			   this->mem_lbl_Prompt_Gender->TabIndex = 4;
			   this->mem_lbl_Prompt_Gender->Text = L"Gender";
			   // 
			   // mem_lbl_Prompt_Name
			   // 
			   this->mem_lbl_Prompt_Name->AutoSize = true;
			   this->mem_lbl_Prompt_Name->Location = System::Drawing::Point(595, 71);
			   this->mem_lbl_Prompt_Name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_lbl_Prompt_Name->Name = L"mem_lbl_Prompt_Name";
			   this->mem_lbl_Prompt_Name->Size = System::Drawing::Size(45, 17);
			   this->mem_lbl_Prompt_Name->TabIndex = 3;
			   this->mem_lbl_Prompt_Name->Text = L"Name";
			   // 
			   // mem_lbl_Prompt_Type
			   // 
			   this->mem_lbl_Prompt_Type->AutoSize = true;
			   this->mem_lbl_Prompt_Type->Location = System::Drawing::Point(395, 70);
			   this->mem_lbl_Prompt_Type->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_lbl_Prompt_Type->Name = L"mem_lbl_Prompt_Type";
			   this->mem_lbl_Prompt_Type->Size = System::Drawing::Size(40, 17);
			   this->mem_lbl_Prompt_Type->TabIndex = 2;
			   this->mem_lbl_Prompt_Type->Text = L"Type";
			   // 
			   // mem_lbl_Prompt_Status
			   // 
			   this->mem_lbl_Prompt_Status->AutoSize = true;
			   this->mem_lbl_Prompt_Status->Location = System::Drawing::Point(193, 70);
			   this->mem_lbl_Prompt_Status->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_lbl_Prompt_Status->Name = L"mem_lbl_Prompt_Status";
			   this->mem_lbl_Prompt_Status->Size = System::Drawing::Size(48, 17);
			   this->mem_lbl_Prompt_Status->TabIndex = 1;
			   this->mem_lbl_Prompt_Status->Text = L"Status";
			   // 
			   // mem_lbl_Prompt_Id
			   // 
			   this->mem_lbl_Prompt_Id->AutoSize = true;
			   this->mem_lbl_Prompt_Id->Location = System::Drawing::Point(61, 70);
			   this->mem_lbl_Prompt_Id->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->mem_lbl_Prompt_Id->Name = L"mem_lbl_Prompt_Id";
			   this->mem_lbl_Prompt_Id->Size = System::Drawing::Size(19, 17);
			   this->mem_lbl_Prompt_Id->TabIndex = 0;
			   this->mem_lbl_Prompt_Id->Text = L"Id";
			   // 
			   // mem_splitter2
			   // 
			   this->mem_splitter2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->mem_splitter2->Cursor = System::Windows::Forms::Cursors::HSplit;
			   this->mem_splitter2->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->mem_splitter2->Enabled = false;
			   this->mem_splitter2->Location = System::Drawing::Point(0, 314);
			   this->mem_splitter2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->mem_splitter2->MinimumSize = System::Drawing::Size(0, 53);
			   this->mem_splitter2->Name = L"mem_splitter2";
			   this->mem_splitter2->Size = System::Drawing::Size(1359, 470);
			   this->mem_splitter2->TabIndex = 66;
			   this->mem_splitter2->TabStop = false;
			   // 
			   // pan_staff
			   // 
			   this->pan_staff->Controls->Add(this->label1);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_SearchResult);
			   this->pan_staff->Controls->Add(this->stf_splitter3);
			   this->pan_staff->Controls->Add(this->stf_splitter2);
			   this->pan_staff->Controls->Add(this->stf_dataGridView);
			   this->pan_staff->Controls->Add(this->stf_splitter1);
			   this->pan_staff->Controls->Add(this->stf_lbl_Count);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Count);
			   this->pan_staff->Controls->Add(this->stf_lbl_Error);
			   this->pan_staff->Controls->Add(this->stf_cmb_Auth);
			   this->pan_staff->Controls->Add(this->stf_cmb_Dept);
			   this->pan_staff->Controls->Add(this->stf_btn_Clear);
			   this->pan_staff->Controls->Add(this->stf_btn_Search);
			   this->pan_staff->Controls->Add(this->stf_txt_Name);
			   this->pan_staff->Controls->Add(this->stf_txt_Id);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Auth);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Dept);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Name);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Id);
			   this->pan_staff->Controls->Add(this->stf_btn_Add);
			   this->pan_staff->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_staff->Location = System::Drawing::Point(0, 0);
			   this->pan_staff->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_staff->Name = L"pan_staff";
			   this->pan_staff->Size = System::Drawing::Size(1359, 784);
			   this->pan_staff->TabIndex = 5;
			   // 
			   // label1
			   // 
			   this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::SystemColors::Control;
			   this->label1->Font = (gcnew System::Drawing::Font(L"SimSun", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(134)));
			   this->label1->Location = System::Drawing::Point(945, 331);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(327, 15);
			   this->label1->TabIndex = 23;
			   this->label1->Text = L"All member info will be shown by default";
			   // 
			   // stf_lbl_Prompt_SearchResult
			   // 
			   this->stf_lbl_Prompt_SearchResult->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Prompt_SearchResult->AutoSize = true;
			   this->stf_lbl_Prompt_SearchResult->BackColor = System::Drawing::SystemColors::Control;
			   this->stf_lbl_Prompt_SearchResult->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(134)));
			   this->stf_lbl_Prompt_SearchResult->Location = System::Drawing::Point(605, 325);
			   this->stf_lbl_Prompt_SearchResult->Name = L"stf_lbl_Prompt_SearchResult";
			   this->stf_lbl_Prompt_SearchResult->Size = System::Drawing::Size(152, 20);
			   this->stf_lbl_Prompt_SearchResult->TabIndex = 22;
			   this->stf_lbl_Prompt_SearchResult->Text = L"Search Result";
			   // 
			   // stf_splitter3
			   // 
			   this->stf_splitter3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->stf_splitter3->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->stf_splitter3->Location = System::Drawing::Point(0, 275);
			   this->stf_splitter3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->stf_splitter3->Name = L"stf_splitter3";
			   this->stf_splitter3->Size = System::Drawing::Size(1359, 37);
			   this->stf_splitter3->TabIndex = 21;
			   this->stf_splitter3->TabStop = false;
			   // 
			   // stf_splitter2
			   // 
			   this->stf_splitter2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->stf_splitter2->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->stf_splitter2->Location = System::Drawing::Point(0, 312);
			   this->stf_splitter2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->stf_splitter2->Name = L"stf_splitter2";
			   this->stf_splitter2->Size = System::Drawing::Size(1359, 44);
			   this->stf_splitter2->TabIndex = 20;
			   this->stf_splitter2->TabStop = false;
			   // 
			   // stf_dataGridView
			   // 
			   this->stf_dataGridView->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->stf_dataGridView->Location = System::Drawing::Point(-8, 356);
			   this->stf_dataGridView->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->stf_dataGridView->Name = L"stf_dataGridView";
			   this->stf_dataGridView->RowHeadersWidth = 51;
			   this->stf_dataGridView->RowTemplate->Height = 27;
			   this->stf_dataGridView->Size = System::Drawing::Size(1280, 368);
			   this->stf_dataGridView->TabIndex = 19;
			   this->stf_dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::stf_dataGridView_CellContentClick);
			   // 
			   // stf_splitter1
			   // 
			   this->stf_splitter1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->stf_splitter1->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->stf_splitter1->Location = System::Drawing::Point(0, 356);
			   this->stf_splitter1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->stf_splitter1->Name = L"stf_splitter1";
			   this->stf_splitter1->Size = System::Drawing::Size(1359, 428);
			   this->stf_splitter1->TabIndex = 18;
			   this->stf_splitter1->TabStop = false;
			   // 
			   // stf_lbl_Count
			   // 
			   this->stf_lbl_Count->AutoSize = true;
			   this->stf_lbl_Count->Location = System::Drawing::Point(125, 124);
			   this->stf_lbl_Count->Name = L"stf_lbl_Count";
			   this->stf_lbl_Count->Size = System::Drawing::Size(0, 17);
			   this->stf_lbl_Count->TabIndex = 17;
			   // 
			   // stf_lbl_Prompt_Count
			   // 
			   this->stf_lbl_Prompt_Count->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Prompt_Count->AutoSize = true;
			   this->stf_lbl_Prompt_Count->Location = System::Drawing::Point(50, 127);
			   this->stf_lbl_Prompt_Count->Name = L"stf_lbl_Prompt_Count";
			   this->stf_lbl_Prompt_Count->Size = System::Drawing::Size(40, 17);
			   this->stf_lbl_Prompt_Count->TabIndex = 16;
			   this->stf_lbl_Prompt_Count->Text = L"Total";
			   // 
			   // stf_lbl_Error
			   // 
			   this->stf_lbl_Error->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Error->AutoSize = true;
			   this->stf_lbl_Error->ForeColor = System::Drawing::Color::Red;
			   this->stf_lbl_Error->Location = System::Drawing::Point(618, 218);
			   this->stf_lbl_Error->Name = L"stf_lbl_Error";
			   this->stf_lbl_Error->Size = System::Drawing::Size(58, 17);
			   this->stf_lbl_Error->TabIndex = 15;
			   this->stf_lbl_Error->Text = L"ERROR";
			   this->stf_lbl_Error->Visible = false;
			   // 
			   // stf_cmb_Auth
			   // 
			   this->stf_cmb_Auth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_cmb_Auth->FormattingEnabled = true;
			   this->stf_cmb_Auth->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				   L"Level-1", L"Level-2", L"Level-3", L"Level-4",
					   L"Level-5"
			   });
			   this->stf_cmb_Auth->Location = System::Drawing::Point(776, 68);
			   this->stf_cmb_Auth->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->stf_cmb_Auth->Name = L"stf_cmb_Auth";
			   this->stf_cmb_Auth->Size = System::Drawing::Size(149, 24);
			   this->stf_cmb_Auth->TabIndex = 14;
			   // 
			   // stf_cmb_Dept
			   // 
			   this->stf_cmb_Dept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_cmb_Dept->FormattingEnabled = true;
			   this->stf_cmb_Dept->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				   L"General Administration", L"Information Technology Support",
					   L"Career Development Support"
			   });
			   this->stf_cmb_Dept->Location = System::Drawing::Point(432, 68);
			   this->stf_cmb_Dept->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->stf_cmb_Dept->Name = L"stf_cmb_Dept";
			   this->stf_cmb_Dept->Size = System::Drawing::Size(279, 24);
			   this->stf_cmb_Dept->TabIndex = 13;
			   // 
			   // stf_btn_Clear
			   // 
			   this->stf_btn_Clear->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_btn_Clear->Location = System::Drawing::Point(1046, 124);
			   this->stf_btn_Clear->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->stf_btn_Clear->Name = L"stf_btn_Clear";
			   this->stf_btn_Clear->Size = System::Drawing::Size(93, 34);
			   this->stf_btn_Clear->TabIndex = 10;
			   this->stf_btn_Clear->Text = L"Clear";
			   this->stf_btn_Clear->UseVisualStyleBackColor = true;
			   this->stf_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::stf_btn_Clear_Click);
			   // 
			   // stf_btn_Search
			   // 
			   this->stf_btn_Search->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_btn_Search->Location = System::Drawing::Point(1046, 52);
			   this->stf_btn_Search->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->stf_btn_Search->Name = L"stf_btn_Search";
			   this->stf_btn_Search->Size = System::Drawing::Size(93, 34);
			   this->stf_btn_Search->TabIndex = 9;
			   this->stf_btn_Search->Text = L"Search";
			   this->stf_btn_Search->UseVisualStyleBackColor = true;
			   this->stf_btn_Search->Click += gcnew System::EventHandler(this, &MainWindow::stf_btn_Search_Click);
			   // 
			   // stf_txt_Name
			   // 
			   this->stf_txt_Name->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_txt_Name->Location = System::Drawing::Point(226, 68);
			   this->stf_txt_Name->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->stf_txt_Name->Name = L"stf_txt_Name";
			   this->stf_txt_Name->Size = System::Drawing::Size(100, 22);
			   this->stf_txt_Name->TabIndex = 6;
			   // 
			   // stf_txt_Id
			   // 
			   this->stf_txt_Id->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_txt_Id->Location = System::Drawing::Point(74, 68);
			   this->stf_txt_Id->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->stf_txt_Id->Name = L"stf_txt_Id";
			   this->stf_txt_Id->Size = System::Drawing::Size(100, 22);
			   this->stf_txt_Id->TabIndex = 5;
			   // 
			   // stf_lbl_Prompt_Auth
			   // 
			   this->stf_lbl_Prompt_Auth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Prompt_Auth->AutoSize = true;
			   this->stf_lbl_Prompt_Auth->Location = System::Drawing::Point(716, 71);
			   this->stf_lbl_Prompt_Auth->Name = L"stf_lbl_Prompt_Auth";
			   this->stf_lbl_Prompt_Auth->Size = System::Drawing::Size(37, 17);
			   this->stf_lbl_Prompt_Auth->TabIndex = 4;
			   this->stf_lbl_Prompt_Auth->Text = L"Auth";
			   // 
			   // stf_lbl_Prompt_Dept
			   // 
			   this->stf_lbl_Prompt_Dept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Prompt_Dept->AutoSize = true;
			   this->stf_lbl_Prompt_Dept->Location = System::Drawing::Point(338, 71);
			   this->stf_lbl_Prompt_Dept->Name = L"stf_lbl_Prompt_Dept";
			   this->stf_lbl_Prompt_Dept->Size = System::Drawing::Size(82, 17);
			   this->stf_lbl_Prompt_Dept->TabIndex = 3;
			   this->stf_lbl_Prompt_Dept->Text = L"Department";
			   // 
			   // stf_lbl_Prompt_Name
			   // 
			   this->stf_lbl_Prompt_Name->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Prompt_Name->AutoSize = true;
			   this->stf_lbl_Prompt_Name->Location = System::Drawing::Point(182, 70);
			   this->stf_lbl_Prompt_Name->Name = L"stf_lbl_Prompt_Name";
			   this->stf_lbl_Prompt_Name->Size = System::Drawing::Size(45, 17);
			   this->stf_lbl_Prompt_Name->TabIndex = 2;
			   this->stf_lbl_Prompt_Name->Text = L"Name";
			   // 
			   // stf_lbl_Prompt_Id
			   // 
			   this->stf_lbl_Prompt_Id->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Prompt_Id->AutoSize = true;
			   this->stf_lbl_Prompt_Id->Location = System::Drawing::Point(50, 70);
			   this->stf_lbl_Prompt_Id->Name = L"stf_lbl_Prompt_Id";
			   this->stf_lbl_Prompt_Id->Size = System::Drawing::Size(19, 17);
			   this->stf_lbl_Prompt_Id->TabIndex = 1;
			   this->stf_lbl_Prompt_Id->Text = L"Id";
			   // 
			   // stf_btn_Add
			   // 
			   this->stf_btn_Add->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_btn_Add->Location = System::Drawing::Point(1046, 199);
			   this->stf_btn_Add->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->stf_btn_Add->Name = L"stf_btn_Add";
			   this->stf_btn_Add->Size = System::Drawing::Size(93, 34);
			   this->stf_btn_Add->TabIndex = 0;
			   this->stf_btn_Add->Text = L"Add";
			   this->stf_btn_Add->UseVisualStyleBackColor = true;
			   this->stf_btn_Add->Click += gcnew System::EventHandler(this, &MainWindow::stf_btn_Add_Click);
			   // 
			   // pan_record
			   // 
			   this->pan_record->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_record->Location = System::Drawing::Point(0, 0);
			   this->pan_record->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_record->Name = L"pan_record";
			   this->pan_record->Size = System::Drawing::Size(1359, 784);
			   this->pan_record->TabIndex = 4;
			   // 
			   // pan_OPT
			   // 
			   this->pan_OPT->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_OPT->Location = System::Drawing::Point(0, 0);
			   this->pan_OPT->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_OPT->Name = L"pan_OPT";
			   this->pan_OPT->Size = System::Drawing::Size(1359, 784);
			   this->pan_OPT->TabIndex = 3;
			   // 
			   // pan_treasury
			   // 
			   this->pan_treasury->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_treasury->Location = System::Drawing::Point(0, 0);
			   this->pan_treasury->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_treasury->Name = L"pan_treasury";
			   this->pan_treasury->Size = System::Drawing::Size(1359, 784);
			   this->pan_treasury->TabIndex = 1;
			   // 
			   // pan_myInfo
			   // 
			   this->pan_myInfo->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_myInfo->Location = System::Drawing::Point(0, 0);
			   this->pan_myInfo->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_myInfo->Name = L"pan_myInfo";
			   this->pan_myInfo->Size = System::Drawing::Size(1359, 784);
			   this->pan_myInfo->TabIndex = 0;
			   // 
			   // ms_panelOptions
			   // 
			   this->ms_panelOptions->Dock = System::Windows::Forms::DockStyle::None;
			   this->ms_panelOptions->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->ms_panelOptions->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				   this->tsm_member,
					   this->tsm_staff, this->tsm_record, this->tsm_OPT, this->tsm_order, this->tsm_treasury, this->tsm_myInfo
			   });
			   this->ms_panelOptions->Location = System::Drawing::Point(0, 0);
			   this->ms_panelOptions->Margin = System::Windows::Forms::Padding(50, 0, 50, 0);
			   this->ms_panelOptions->MinimumSize = System::Drawing::Size(150, 0);
			   this->ms_panelOptions->Name = L"ms_panelOptions";
			   this->ms_panelOptions->Size = System::Drawing::Size(150, 784);
			   this->ms_panelOptions->TabIndex = 0;
			   this->ms_panelOptions->Text = L"ms_leftBar";
			   // 
			   // tsm_member
			   // 
			   this->tsm_member->Name = L"tsm_member";
			   this->tsm_member->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_member->Size = System::Drawing::Size(143, 74);
			   this->tsm_member->Text = L"Member";
			   this->tsm_member->Click += gcnew System::EventHandler(this, &MainWindow::tsm_member_Click);
			   // 
			   // tsm_staff
			   // 
			   this->tsm_staff->Name = L"tsm_staff";
			   this->tsm_staff->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_staff->Size = System::Drawing::Size(143, 74);
			   this->tsm_staff->Text = L"Staff";
			   this->tsm_staff->Click += gcnew System::EventHandler(this, &MainWindow::tsm_staff_Click);
			   // 
			   // tsm_record
			   // 
			   this->tsm_record->Name = L"tsm_record";
			   this->tsm_record->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_record->Size = System::Drawing::Size(143, 74);
			   this->tsm_record->Text = L"Record";
			   this->tsm_record->Click += gcnew System::EventHandler(this, &MainWindow::tsm_record_Click);
			   // 
			   // tsm_OPT
			   // 
			   this->tsm_OPT->Name = L"tsm_OPT";
			   this->tsm_OPT->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_OPT->Size = System::Drawing::Size(143, 74);
			   this->tsm_OPT->Text = L"OPT";
			   this->tsm_OPT->Click += gcnew System::EventHandler(this, &MainWindow::tsm_OPT_Click);
			   // 
			   // tsm_order
			   // 
			   this->tsm_order->Name = L"tsm_order";
			   this->tsm_order->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_order->Size = System::Drawing::Size(143, 74);
			   this->tsm_order->Text = L"Order";
			   this->tsm_order->Click += gcnew System::EventHandler(this, &MainWindow::tsm_order_Click);
			   // 
			   // tsm_treasury
			   // 
			   this->tsm_treasury->Name = L"tsm_treasury";
			   this->tsm_treasury->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_treasury->Size = System::Drawing::Size(143, 74);
			   this->tsm_treasury->Text = L"Treasury";
			   // 
			   // tsm_myInfo
			   // 
			   this->tsm_myInfo->Name = L"tsm_myInfo";
			   this->tsm_myInfo->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_myInfo->Size = System::Drawing::Size(143, 74);
			   this->tsm_myInfo->Text = L"My Info";
			   // 
			   // ms_systemOptions
			   // 
			   this->ms_systemOptions->BackColor = System::Drawing::SystemColors::Control;
			   this->ms_systemOptions->Dock = System::Windows::Forms::DockStyle::None;
			   this->ms_systemOptions->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->ms_systemOptions->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->tsm_system,
					   this->tsm_database, this->tsm_help
			   });
			   this->ms_systemOptions->Location = System::Drawing::Point(0, 0);
			   this->ms_systemOptions->Name = L"ms_systemOptions";
			   this->ms_systemOptions->Size = System::Drawing::Size(1509, 28);
			   this->ms_systemOptions->TabIndex = 0;
			   this->ms_systemOptions->Text = L"menuStrip1";
			   // 
			   // tsm_system
			   // 
			   this->tsm_system->Name = L"tsm_system";
			   this->tsm_system->Padding = System::Windows::Forms::Padding(25, 0, 25, 0);
			   this->tsm_system->Size = System::Drawing::Size(110, 24);
			   this->tsm_system->Text = L"System";
			   // 
			   // tsm_database
			   // 
			   this->tsm_database->Name = L"tsm_database";
			   this->tsm_database->Padding = System::Windows::Forms::Padding(25, 0, 25, 0);
			   this->tsm_database->Size = System::Drawing::Size(126, 24);
			   this->tsm_database->Text = L"Database";
			   // 
			   // tsm_help
			   // 
			   this->tsm_help->Name = L"tsm_help";
			   this->tsm_help->Padding = System::Windows::Forms::Padding(25, 0, 25, 0);
			   this->tsm_help->Size = System::Drawing::Size(95, 24);
			   this->tsm_help->Text = L"Help";
			   // 
			   // MainWindow
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1509, 812);
			   this->Controls->Add(this->toolStripContainer1);
			   this->MainMenuStrip = this->ms_systemOptions;
			   this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->MinimumSize = System::Drawing::Size(1498, 847);
			   this->Name = L"MainWindow";
			   this->Text = L"MainWindow";
			   this->toolStripContainer1->ContentPanel->ResumeLayout(false);
			   this->toolStripContainer1->LeftToolStripPanel->ResumeLayout(false);
			   this->toolStripContainer1->LeftToolStripPanel->PerformLayout();
			   this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
			   this->toolStripContainer1->TopToolStripPanel->PerformLayout();
			   this->toolStripContainer1->ResumeLayout(false);
			   this->toolStripContainer1->PerformLayout();
			   this->pan_order->ResumeLayout(false);
			   this->pan_order->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ord_dataGridView))->EndInit();
			   this->pan_member->ResumeLayout(false);
			   this->pan_member->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mem_dataGridView1))->EndInit();
			   this->pan_staff->ResumeLayout(false);
			   this->pan_staff->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stf_dataGridView))->EndInit();
			   this->ms_panelOptions->ResumeLayout(false);
			   this->ms_panelOptions->PerformLayout();
			   this->ms_systemOptions->ResumeLayout(false);
			   this->ms_systemOptions->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private:
		Void tsm_member_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_member->Visible = true;
		}
		Void tsm_staff_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_staff->Visible = true;
		}
		Void tsm_record_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_record->Visible = true;
		}
		Void tsm_OPT_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_OPT->Visible = true;
		}
		Void tsm_order_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_order->Visible = true;
		}
		Void tsm_treasury_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_treasury->Visible = true;
		}
		Void tsm_myInfo_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_myInfo->Visible = true;
		}
		void SetAllPanelInvisible();

	private:
		Database^ database;
		PublicUserInfo^ _pui;
		PublicUserInfo::Auth _Auth;

		/*
			MemberMainWindow
		*/
	private:
		Void Initialize();
		Void mem_CheckAuth();
		Void mem_UpdateDataGridView(String^ command);
		Void mem_GeneralInformation();
		Void mem_btn_Search_Click(System::Object^ sender, System::EventArgs^ e);
		Void mem_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e);
		Void mem_btn_Add_Click(System::Object^ sender, System::EventArgs^ e);
		Void mem_btn_Import_Click(System::Object^ sender, System::EventArgs^ e);
		Void mem_dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

		/*
			StaffMainWindow
		*/
	private:
		Void stf_CheckAuth();
		Void stf_UpdateDataGridView(String^ command);
		Void stf_GeneralInformation();
		Void stf_btn_Add_Click(System::Object^ sender, System::EventArgs^ e);
		Void stf_btn_Search_Click(System::Object^ sender, System::EventArgs^ e);
		Void stf_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e);
		Void stf_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		/*
			OrderMainWindow
		*/
	private:
		Void ord_UpdateDataGridView(String^ command);
		Void ord_GeneralInformation();
		Void ord_btn_Search_Click(System::Object^ sender, System::EventArgs^ e);
		Void ord_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e);
		Void ord_btn_Add_Click(System::Object^ sender, System::EventArgs^ e);
		Void ord_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
};
}
