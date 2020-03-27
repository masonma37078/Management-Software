#pragma once

/*
 * MainWindow.h
 *
 * This file initializes the MainWindow's UI and declares the sub-functions required.
 *
 * @author: Hang Yuan
 * Revised: 3/27/20
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
	private: System::Windows::Forms::Panel^ pan_myInfo;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
		this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
		this->pan_member = (gcnew System::Windows::Forms::Panel());
		this->pan_staff = (gcnew System::Windows::Forms::Panel());
		this->pan_record = (gcnew System::Windows::Forms::Panel());
		this->pan_OPT = (gcnew System::Windows::Forms::Panel());
		this->pan_order = (gcnew System::Windows::Forms::Panel());
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
		this->tsm_system = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->tsm_database = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->tsm_help = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->ms_systemOptions = (gcnew System::Windows::Forms::MenuStrip());
		this->toolStripContainer1->ContentPanel->SuspendLayout();
		this->toolStripContainer1->LeftToolStripPanel->SuspendLayout();
		this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
		this->toolStripContainer1->SuspendLayout();
		this->ms_panelOptions->SuspendLayout();
		this->ms_systemOptions->SuspendLayout();
		this->SuspendLayout();
		// 
		// toolStripContainer1
		// 
		// 
		// toolStripContainer1.ContentPanel
		// 
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_member);
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_staff);
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_record);
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_OPT);
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_order);
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_treasury);
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_myInfo);
		this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(1360, 725);
		this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
		// 
		// toolStripContainer1.LeftToolStripPanel
		// 
		this->toolStripContainer1->LeftToolStripPanel->Controls->Add(this->ms_panelOptions);
		this->toolStripContainer1->Location = System::Drawing::Point(0, 0);
		this->toolStripContainer1->Name = L"toolStripContainer1";
		this->toolStripContainer1->Size = System::Drawing::Size(1510, 753);
		this->toolStripContainer1->TabIndex = 0;
		this->toolStripContainer1->Text = L"toolStripContainer1";
		// 
		// toolStripContainer1.TopToolStripPanel
		// 
		this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->ms_systemOptions);
		// 
		// pan_member
		// 
		this->pan_member->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_member->Location = System::Drawing::Point(0, 0);
		this->pan_member->Name = L"pan_member";
		this->pan_member->Size = System::Drawing::Size(1360, 725);
		this->pan_member->TabIndex = 6;
		// 
		// pan_staff
		// 
		this->pan_staff->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_staff->Location = System::Drawing::Point(0, 0);
		this->pan_staff->Name = L"pan_staff";
		this->pan_staff->Size = System::Drawing::Size(1360, 725);
		this->pan_staff->TabIndex = 5;
		// 
		// pan_record
		// 
		this->pan_record->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_record->Location = System::Drawing::Point(0, 0);
		this->pan_record->Name = L"pan_record";
		this->pan_record->Size = System::Drawing::Size(1360, 725);
		this->pan_record->TabIndex = 4;
		// 
		// pan_OPT
		// 
		this->pan_OPT->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_OPT->Location = System::Drawing::Point(0, 0);
		this->pan_OPT->Name = L"pan_OPT";
		this->pan_OPT->Size = System::Drawing::Size(1360, 725);
		this->pan_OPT->TabIndex = 3;
		// 
		// pan_order
		// 
		this->pan_order->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_order->Location = System::Drawing::Point(0, 0);
		this->pan_order->Name = L"pan_order";
		this->pan_order->Size = System::Drawing::Size(1360, 725);
		this->pan_order->TabIndex = 2;
		// 
		// pan_treasury
		// 
		this->pan_treasury->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_treasury->Location = System::Drawing::Point(0, 0);
		this->pan_treasury->Name = L"pan_treasury";
		this->pan_treasury->Size = System::Drawing::Size(1360, 725);
		this->pan_treasury->TabIndex = 1;
		// 
		// pan_myInfo
		// 
		this->pan_myInfo->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_myInfo->Location = System::Drawing::Point(0, 0);
		this->pan_myInfo->Name = L"pan_myInfo";
		this->pan_myInfo->Size = System::Drawing::Size(1360, 725);
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
		this->ms_panelOptions->Size = System::Drawing::Size(150, 725);
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
		this->tsm_order->Click += gcnew System::EventHandler(this, &MainWindow::tsm_myInfo_Click);
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
		// ms_systemOptions
		// 
		this->ms_systemOptions->Dock = System::Windows::Forms::DockStyle::None;
		this->ms_systemOptions->ImageScalingSize = System::Drawing::Size(20, 20);
		this->ms_systemOptions->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
			this->tsm_system,
				this->tsm_database, this->tsm_help
		});
		this->ms_systemOptions->Location = System::Drawing::Point(0, 0);
		this->ms_systemOptions->Name = L"ms_systemOptions";
		this->ms_systemOptions->Size = System::Drawing::Size(1510, 28);
		this->ms_systemOptions->TabIndex = 0;
		this->ms_systemOptions->Text = L"menuStrip1";
		// 
		// MainWindow
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(1510, 753);
		this->Controls->Add(this->toolStripContainer1);
		this->MainMenuStrip = this->ms_systemOptions;
		this->MinimumSize = System::Drawing::Size(1500, 800);
		this->Name = L"MainWindow";
		this->Text = L"MainWindow";
		this->toolStripContainer1->ContentPanel->ResumeLayout(false);
		this->toolStripContainer1->LeftToolStripPanel->ResumeLayout(false);
		this->toolStripContainer1->LeftToolStripPanel->PerformLayout();
		this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
		this->toolStripContainer1->TopToolStripPanel->PerformLayout();
		this->toolStripContainer1->ResumeLayout(false);
		this->toolStripContainer1->PerformLayout();
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
};
}
