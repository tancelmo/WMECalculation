#pragma once
#include "NoDataEngine.h"
#include "StdFunctions.h"
#include "Calculation.h"
#include "GearCorrection.h"
#include "WMEInfo.h"


namespace WMECalculation {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	using namespace System::Data::OleDb;
	using namespace System::Globalization;
	using namespace System::Threading;
	using namespace System::IO;


	/// <summary>
	/// Sumário para MainUI
	/// </summary>

	public ref class MainUI : public System::Windows::Forms::Form
	{
		
		OleDbConnection^ connection = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=WMEData.accdb;Persist Security Info=True");
		
		OleDbCommand^ com = gcnew OleDbCommand();

	public:
		double resultFromGears;
		bool checkBtn;
		
		
		MainUI(void)
			
		{
			if (!File::Exists(Directory::GetCurrentDirectory() + "\\WMEData.accdb")) {
				String^ noDataBase;
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("en-US")) {
					noDataBase = "Database file not found.\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("es")) {
					noDataBase = "Archivo de base de datos no encontrado.\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("pt-BR")) {
					noDataBase = "Arquivo de banco de dados não encontrado.\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				else
				{
					noDataBase = "Database file not found.\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				MessageBox::Show(noDataBase);
				throw;
			}
			try
			{
				
				connection->Open();
				connection->Close();
			}
			catch (Exception^)
			{
				NoDataEngine^ callErrDb = gcnew NoDataEngine;
				callErrDb->ShowDialog();
				throw;
			}
			
			getLanguage();
			InitializeComponent();
			

			//
			//TODO: Adicione o código do construtor aqui
			//
			
		}
		
	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MainUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBoxRange;
	private: System::Windows::Forms::TextBox^ TextBox_Qmax;
	private: System::Windows::Forms::Label^ labelResult;
	private: System::Windows::Forms::GroupBox^ groupBox_Errors;
	private: System::Windows::Forms::TextBox^ textBox_005Qmax;
	private: System::Windows::Forms::TextBox^ textBox_010Qmax;
	private: System::Windows::Forms::TextBox^ textBox_015Qmax;
	private: System::Windows::Forms::TextBox^ textBox_025Qmax;
	private: System::Windows::Forms::TextBox^ textBox_04Qmax;
	private: System::Windows::Forms::TextBox^ textBox_07Qmax;
	private: System::Windows::Forms::Label^ label_QQmax;
	private: System::Windows::Forms::Label^ label_Qmax;
	private: System::Windows::Forms::TextBox^ textBox_Qmin;
	private: System::Windows::Forms::GroupBox^ groupQiQmax;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ labelQQmin;
	private: System::Windows::Forms::Label^ labelQmin;
	private: System::Windows::Forms::Label^ labelQ005Qmax;
	private: System::Windows::Forms::Label^ label005Qmax;
	private: System::Windows::Forms::Label^ labelQ010Qmax;
	private: System::Windows::Forms::Label^ label010Qmax;
	private: System::Windows::Forms::Label^ labelQ015Qmax;
	private: System::Windows::Forms::Label^ label015Qmax;
	private: System::Windows::Forms::Label^ labelQ025Qmax;
	private: System::Windows::Forms::Label^ label025Qmax;
	private: System::Windows::Forms::Label^ labelQ04Qmax;
	private: System::Windows::Forms::Label^ label04Qmax;
	private: System::Windows::Forms::Label^ labelQ07Qmax;
	private: System::Windows::Forms::Label^ label07Qmax;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::ComboBox^ comboBox_GCalibre;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label_WFactor_Qmin;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ opçõesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ idiomaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ inglesEUAToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ espanholToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ portuguêsBrasilToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ simularCorreçãoToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainUI::typeid));
			this->comboBoxRange = (gcnew System::Windows::Forms::ComboBox());
			this->TextBox_Qmax = (gcnew System::Windows::Forms::TextBox());
			this->labelResult = (gcnew System::Windows::Forms::Label());
			this->groupBox_Errors = (gcnew System::Windows::Forms::GroupBox());
			this->labelQQmin = (gcnew System::Windows::Forms::Label());
			this->labelQmin = (gcnew System::Windows::Forms::Label());
			this->labelQ005Qmax = (gcnew System::Windows::Forms::Label());
			this->label005Qmax = (gcnew System::Windows::Forms::Label());
			this->labelQ010Qmax = (gcnew System::Windows::Forms::Label());
			this->label010Qmax = (gcnew System::Windows::Forms::Label());
			this->labelQ015Qmax = (gcnew System::Windows::Forms::Label());
			this->label015Qmax = (gcnew System::Windows::Forms::Label());
			this->labelQ025Qmax = (gcnew System::Windows::Forms::Label());
			this->label025Qmax = (gcnew System::Windows::Forms::Label());
			this->labelQ04Qmax = (gcnew System::Windows::Forms::Label());
			this->label04Qmax = (gcnew System::Windows::Forms::Label());
			this->labelQ07Qmax = (gcnew System::Windows::Forms::Label());
			this->label07Qmax = (gcnew System::Windows::Forms::Label());
			this->label_QQmax = (gcnew System::Windows::Forms::Label());
			this->label_Qmax = (gcnew System::Windows::Forms::Label());
			this->textBox_Qmin = (gcnew System::Windows::Forms::TextBox());
			this->textBox_005Qmax = (gcnew System::Windows::Forms::TextBox());
			this->textBox_010Qmax = (gcnew System::Windows::Forms::TextBox());
			this->textBox_015Qmax = (gcnew System::Windows::Forms::TextBox());
			this->textBox_025Qmax = (gcnew System::Windows::Forms::TextBox());
			this->textBox_04Qmax = (gcnew System::Windows::Forms::TextBox());
			this->textBox_07Qmax = (gcnew System::Windows::Forms::TextBox());
			this->groupQiQmax = (gcnew System::Windows::Forms::GroupBox());
			this->label_WFactor_Qmin = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->comboBox_GCalibre = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->opçõesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->idiomaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->inglesEUAToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->espanholToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->portuguêsBrasilToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->simularCorreçãoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox_Errors->SuspendLayout();
			this->groupQiQmax->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBoxRange
			// 
			resources->ApplyResources(this->comboBoxRange, L"comboBoxRange");
			this->comboBoxRange->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxRange->FormattingEnabled = true;
			this->comboBoxRange->Name = L"comboBoxRange";
			this->toolTip1->SetToolTip(this->comboBoxRange, resources->GetString(L"comboBoxRange.ToolTip"));
			this->comboBoxRange->SelectedIndexChanged += gcnew System::EventHandler(this, &MainUI::comboBoxRange_SelectedIndexChanged);
			// 
			// TextBox_Qmax
			// 
			resources->ApplyResources(this->TextBox_Qmax, L"TextBox_Qmax");
			this->TextBox_Qmax->Name = L"TextBox_Qmax";
			this->toolTip1->SetToolTip(this->TextBox_Qmax, resources->GetString(L"TextBox_Qmax.ToolTip"));
			this->TextBox_Qmax->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainUI::TextBox_Qmax_KeyPress);
			this->TextBox_Qmax->Validated += gcnew System::EventHandler(this, &MainUI::TextBox_Qmax_Validated);
			// 
			// labelResult
			// 
			resources->ApplyResources(this->labelResult, L"labelResult");
			this->labelResult->AutoEllipsis = true;
			this->labelResult->Name = L"labelResult";
			this->toolTip1->SetToolTip(this->labelResult, resources->GetString(L"labelResult.ToolTip"));
			// 
			// groupBox_Errors
			// 
			resources->ApplyResources(this->groupBox_Errors, L"groupBox_Errors");
			this->groupBox_Errors->Controls->Add(this->labelQQmin);
			this->groupBox_Errors->Controls->Add(this->labelQmin);
			this->groupBox_Errors->Controls->Add(this->labelQ005Qmax);
			this->groupBox_Errors->Controls->Add(this->label005Qmax);
			this->groupBox_Errors->Controls->Add(this->labelQ010Qmax);
			this->groupBox_Errors->Controls->Add(this->label010Qmax);
			this->groupBox_Errors->Controls->Add(this->labelQ015Qmax);
			this->groupBox_Errors->Controls->Add(this->label015Qmax);
			this->groupBox_Errors->Controls->Add(this->labelQ025Qmax);
			this->groupBox_Errors->Controls->Add(this->label025Qmax);
			this->groupBox_Errors->Controls->Add(this->labelQ04Qmax);
			this->groupBox_Errors->Controls->Add(this->label04Qmax);
			this->groupBox_Errors->Controls->Add(this->labelQ07Qmax);
			this->groupBox_Errors->Controls->Add(this->label07Qmax);
			this->groupBox_Errors->Controls->Add(this->label_QQmax);
			this->groupBox_Errors->Controls->Add(this->label_Qmax);
			this->groupBox_Errors->Controls->Add(this->textBox_Qmin);
			this->groupBox_Errors->Controls->Add(this->textBox_005Qmax);
			this->groupBox_Errors->Controls->Add(this->textBox_010Qmax);
			this->groupBox_Errors->Controls->Add(this->textBox_015Qmax);
			this->groupBox_Errors->Controls->Add(this->textBox_025Qmax);
			this->groupBox_Errors->Controls->Add(this->textBox_04Qmax);
			this->groupBox_Errors->Controls->Add(this->textBox_07Qmax);
			this->groupBox_Errors->Controls->Add(this->TextBox_Qmax);
			this->groupBox_Errors->Name = L"groupBox_Errors";
			this->groupBox_Errors->TabStop = false;
			this->toolTip1->SetToolTip(this->groupBox_Errors, resources->GetString(L"groupBox_Errors.ToolTip"));
			// 
			// labelQQmin
			// 
			resources->ApplyResources(this->labelQQmin, L"labelQQmin");
			this->labelQQmin->ForeColor = System::Drawing::Color::Blue;
			this->labelQQmin->Name = L"labelQQmin";
			this->toolTip1->SetToolTip(this->labelQQmin, resources->GetString(L"labelQQmin.ToolTip"));
			// 
			// labelQmin
			// 
			resources->ApplyResources(this->labelQmin, L"labelQmin");
			this->labelQmin->Name = L"labelQmin";
			this->toolTip1->SetToolTip(this->labelQmin, resources->GetString(L"labelQmin.ToolTip"));
			// 
			// labelQ005Qmax
			// 
			resources->ApplyResources(this->labelQ005Qmax, L"labelQ005Qmax");
			this->labelQ005Qmax->ForeColor = System::Drawing::Color::Blue;
			this->labelQ005Qmax->Name = L"labelQ005Qmax";
			this->toolTip1->SetToolTip(this->labelQ005Qmax, resources->GetString(L"labelQ005Qmax.ToolTip"));
			// 
			// label005Qmax
			// 
			resources->ApplyResources(this->label005Qmax, L"label005Qmax");
			this->label005Qmax->Name = L"label005Qmax";
			this->toolTip1->SetToolTip(this->label005Qmax, resources->GetString(L"label005Qmax.ToolTip"));
			// 
			// labelQ010Qmax
			// 
			resources->ApplyResources(this->labelQ010Qmax, L"labelQ010Qmax");
			this->labelQ010Qmax->ForeColor = System::Drawing::Color::Blue;
			this->labelQ010Qmax->Name = L"labelQ010Qmax";
			this->toolTip1->SetToolTip(this->labelQ010Qmax, resources->GetString(L"labelQ010Qmax.ToolTip"));
			// 
			// label010Qmax
			// 
			resources->ApplyResources(this->label010Qmax, L"label010Qmax");
			this->label010Qmax->Name = L"label010Qmax";
			this->toolTip1->SetToolTip(this->label010Qmax, resources->GetString(L"label010Qmax.ToolTip"));
			// 
			// labelQ015Qmax
			// 
			resources->ApplyResources(this->labelQ015Qmax, L"labelQ015Qmax");
			this->labelQ015Qmax->ForeColor = System::Drawing::Color::Blue;
			this->labelQ015Qmax->Name = L"labelQ015Qmax";
			this->toolTip1->SetToolTip(this->labelQ015Qmax, resources->GetString(L"labelQ015Qmax.ToolTip"));
			// 
			// label015Qmax
			// 
			resources->ApplyResources(this->label015Qmax, L"label015Qmax");
			this->label015Qmax->Name = L"label015Qmax";
			this->toolTip1->SetToolTip(this->label015Qmax, resources->GetString(L"label015Qmax.ToolTip"));
			// 
			// labelQ025Qmax
			// 
			resources->ApplyResources(this->labelQ025Qmax, L"labelQ025Qmax");
			this->labelQ025Qmax->ForeColor = System::Drawing::Color::Blue;
			this->labelQ025Qmax->Name = L"labelQ025Qmax";
			this->labelQ025Qmax->Tag = L"";
			this->toolTip1->SetToolTip(this->labelQ025Qmax, resources->GetString(L"labelQ025Qmax.ToolTip"));
			// 
			// label025Qmax
			// 
			resources->ApplyResources(this->label025Qmax, L"label025Qmax");
			this->label025Qmax->Name = L"label025Qmax";
			this->label025Qmax->Tag = L"";
			this->toolTip1->SetToolTip(this->label025Qmax, resources->GetString(L"label025Qmax.ToolTip"));
			// 
			// labelQ04Qmax
			// 
			resources->ApplyResources(this->labelQ04Qmax, L"labelQ04Qmax");
			this->labelQ04Qmax->ForeColor = System::Drawing::Color::Blue;
			this->labelQ04Qmax->Name = L"labelQ04Qmax";
			this->toolTip1->SetToolTip(this->labelQ04Qmax, resources->GetString(L"labelQ04Qmax.ToolTip"));
			// 
			// label04Qmax
			// 
			resources->ApplyResources(this->label04Qmax, L"label04Qmax");
			this->label04Qmax->Name = L"label04Qmax";
			this->toolTip1->SetToolTip(this->label04Qmax, resources->GetString(L"label04Qmax.ToolTip"));
			// 
			// labelQ07Qmax
			// 
			resources->ApplyResources(this->labelQ07Qmax, L"labelQ07Qmax");
			this->labelQ07Qmax->ForeColor = System::Drawing::Color::Blue;
			this->labelQ07Qmax->Name = L"labelQ07Qmax";
			this->toolTip1->SetToolTip(this->labelQ07Qmax, resources->GetString(L"labelQ07Qmax.ToolTip"));
			// 
			// label07Qmax
			// 
			resources->ApplyResources(this->label07Qmax, L"label07Qmax");
			this->label07Qmax->Name = L"label07Qmax";
			this->toolTip1->SetToolTip(this->label07Qmax, resources->GetString(L"label07Qmax.ToolTip"));
			// 
			// label_QQmax
			// 
			resources->ApplyResources(this->label_QQmax, L"label_QQmax");
			this->label_QQmax->ForeColor = System::Drawing::Color::Blue;
			this->label_QQmax->Name = L"label_QQmax";
			this->toolTip1->SetToolTip(this->label_QQmax, resources->GetString(L"label_QQmax.ToolTip"));
			// 
			// label_Qmax
			// 
			resources->ApplyResources(this->label_Qmax, L"label_Qmax");
			this->label_Qmax->Name = L"label_Qmax";
			this->toolTip1->SetToolTip(this->label_Qmax, resources->GetString(L"label_Qmax.ToolTip"));
			// 
			// textBox_Qmin
			// 
			resources->ApplyResources(this->textBox_Qmin, L"textBox_Qmin");
			this->textBox_Qmin->Name = L"textBox_Qmin";
			this->toolTip1->SetToolTip(this->textBox_Qmin, resources->GetString(L"textBox_Qmin.ToolTip"));
			this->textBox_Qmin->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainUI::textBox_Qmin_KeyPress);
			this->textBox_Qmin->Validated += gcnew System::EventHandler(this, &MainUI::textBox_Qmin_Validated);
			// 
			// textBox_005Qmax
			// 
			resources->ApplyResources(this->textBox_005Qmax, L"textBox_005Qmax");
			this->textBox_005Qmax->Name = L"textBox_005Qmax";
			this->toolTip1->SetToolTip(this->textBox_005Qmax, resources->GetString(L"textBox_005Qmax.ToolTip"));
			this->textBox_005Qmax->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainUI::textBox_005Qmax_KeyPress);
			this->textBox_005Qmax->Validated += gcnew System::EventHandler(this, &MainUI::textBox_005Qmax_Validated);
			// 
			// textBox_010Qmax
			// 
			resources->ApplyResources(this->textBox_010Qmax, L"textBox_010Qmax");
			this->textBox_010Qmax->Name = L"textBox_010Qmax";
			this->toolTip1->SetToolTip(this->textBox_010Qmax, resources->GetString(L"textBox_010Qmax.ToolTip"));
			this->textBox_010Qmax->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainUI::textBox_010Qmax_KeyPress);
			this->textBox_010Qmax->Validated += gcnew System::EventHandler(this, &MainUI::textBox_010Qmax_Validated);
			// 
			// textBox_015Qmax
			// 
			resources->ApplyResources(this->textBox_015Qmax, L"textBox_015Qmax");
			this->textBox_015Qmax->Name = L"textBox_015Qmax";
			this->toolTip1->SetToolTip(this->textBox_015Qmax, resources->GetString(L"textBox_015Qmax.ToolTip"));
			this->textBox_015Qmax->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainUI::textBox_015Qmax_KeyPress);
			this->textBox_015Qmax->Validated += gcnew System::EventHandler(this, &MainUI::textBox_015Qmax_Validated);
			// 
			// textBox_025Qmax
			// 
			resources->ApplyResources(this->textBox_025Qmax, L"textBox_025Qmax");
			this->textBox_025Qmax->Name = L"textBox_025Qmax";
			this->textBox_025Qmax->Tag = L"";
			this->toolTip1->SetToolTip(this->textBox_025Qmax, resources->GetString(L"textBox_025Qmax.ToolTip"));
			this->textBox_025Qmax->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainUI::textBox_025Qmax_KeyPress);
			this->textBox_025Qmax->Validated += gcnew System::EventHandler(this, &MainUI::textBox_025Qmax_Validated);
			// 
			// textBox_04Qmax
			// 
			resources->ApplyResources(this->textBox_04Qmax, L"textBox_04Qmax");
			this->textBox_04Qmax->Name = L"textBox_04Qmax";
			this->toolTip1->SetToolTip(this->textBox_04Qmax, resources->GetString(L"textBox_04Qmax.ToolTip"));
			this->textBox_04Qmax->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainUI::textBox_04Qmax_KeyPress);
			this->textBox_04Qmax->Validated += gcnew System::EventHandler(this, &MainUI::textBox_04Qmax_Validated);
			// 
			// textBox_07Qmax
			// 
			resources->ApplyResources(this->textBox_07Qmax, L"textBox_07Qmax");
			this->textBox_07Qmax->Name = L"textBox_07Qmax";
			this->toolTip1->SetToolTip(this->textBox_07Qmax, resources->GetString(L"textBox_07Qmax.ToolTip"));
			this->textBox_07Qmax->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainUI::textBox_07Qmax_KeyPress);
			this->textBox_07Qmax->Validated += gcnew System::EventHandler(this, &MainUI::textBox_07Qmax_Validated);
			// 
			// groupQiQmax
			// 
			resources->ApplyResources(this->groupQiQmax, L"groupQiQmax");
			this->groupQiQmax->Controls->Add(this->label_WFactor_Qmin);
			this->groupQiQmax->Controls->Add(this->label16);
			this->groupQiQmax->Controls->Add(this->label13);
			this->groupQiQmax->Controls->Add(this->label14);
			this->groupQiQmax->Controls->Add(this->label11);
			this->groupQiQmax->Controls->Add(this->label12);
			this->groupQiQmax->Controls->Add(this->label9);
			this->groupQiQmax->Controls->Add(this->label10);
			this->groupQiQmax->Controls->Add(this->label7);
			this->groupQiQmax->Controls->Add(this->label8);
			this->groupQiQmax->Controls->Add(this->label5);
			this->groupQiQmax->Controls->Add(this->label6);
			this->groupQiQmax->Controls->Add(this->label3);
			this->groupQiQmax->Controls->Add(this->label4);
			this->groupQiQmax->Controls->Add(this->label2);
			this->groupQiQmax->Controls->Add(this->label1);
			this->groupQiQmax->Name = L"groupQiQmax";
			this->groupQiQmax->TabStop = false;
			this->toolTip1->SetToolTip(this->groupQiQmax, resources->GetString(L"groupQiQmax.ToolTip"));
			// 
			// label_WFactor_Qmin
			// 
			resources->ApplyResources(this->label_WFactor_Qmin, L"label_WFactor_Qmin");
			this->label_WFactor_Qmin->Name = L"label_WFactor_Qmin";
			this->toolTip1->SetToolTip(this->label_WFactor_Qmin, resources->GetString(L"label_WFactor_Qmin.ToolTip"));
			// 
			// label16
			// 
			resources->ApplyResources(this->label16, L"label16");
			this->label16->Name = L"label16";
			this->toolTip1->SetToolTip(this->label16, resources->GetString(L"label16.ToolTip"));
			// 
			// label13
			// 
			resources->ApplyResources(this->label13, L"label13");
			this->label13->Name = L"label13";
			this->toolTip1->SetToolTip(this->label13, resources->GetString(L"label13.ToolTip"));
			// 
			// label14
			// 
			resources->ApplyResources(this->label14, L"label14");
			this->label14->Name = L"label14";
			this->toolTip1->SetToolTip(this->label14, resources->GetString(L"label14.ToolTip"));
			// 
			// label11
			// 
			resources->ApplyResources(this->label11, L"label11");
			this->label11->Name = L"label11";
			this->toolTip1->SetToolTip(this->label11, resources->GetString(L"label11.ToolTip"));
			// 
			// label12
			// 
			resources->ApplyResources(this->label12, L"label12");
			this->label12->Name = L"label12";
			this->toolTip1->SetToolTip(this->label12, resources->GetString(L"label12.ToolTip"));
			// 
			// label9
			// 
			resources->ApplyResources(this->label9, L"label9");
			this->label9->Name = L"label9";
			this->toolTip1->SetToolTip(this->label9, resources->GetString(L"label9.ToolTip"));
			// 
			// label10
			// 
			resources->ApplyResources(this->label10, L"label10");
			this->label10->Name = L"label10";
			this->toolTip1->SetToolTip(this->label10, resources->GetString(L"label10.ToolTip"));
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->Name = L"label7";
			this->label7->Tag = L"";
			this->toolTip1->SetToolTip(this->label7, resources->GetString(L"label7.ToolTip"));
			// 
			// label8
			// 
			resources->ApplyResources(this->label8, L"label8");
			this->label8->Name = L"label8";
			this->label8->Tag = L"";
			this->toolTip1->SetToolTip(this->label8, resources->GetString(L"label8.ToolTip"));
			// 
			// label5
			// 
			resources->ApplyResources(this->label5, L"label5");
			this->label5->Name = L"label5";
			this->toolTip1->SetToolTip(this->label5, resources->GetString(L"label5.ToolTip"));
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->Name = L"label6";
			this->toolTip1->SetToolTip(this->label6, resources->GetString(L"label6.ToolTip"));
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			this->toolTip1->SetToolTip(this->label3, resources->GetString(L"label3.ToolTip"));
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			this->toolTip1->SetToolTip(this->label4, resources->GetString(L"label4.ToolTip"));
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			this->toolTip1->SetToolTip(this->label2, resources->GetString(L"label2.ToolTip"));
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			this->toolTip1->SetToolTip(this->label1, resources->GetString(L"label1.ToolTip"));
			// 
			// groupBox2
			// 
			resources->ApplyResources(this->groupBox2, L"groupBox2");
			this->groupBox2->Controls->Add(this->labelResult);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->TabStop = false;
			this->toolTip1->SetToolTip(this->groupBox2, resources->GetString(L"groupBox2.ToolTip"));
			// 
			// groupBox3
			// 
			resources->ApplyResources(this->groupBox3, L"groupBox3");
			this->groupBox3->Controls->Add(this->pictureBox1);
			this->groupBox3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->TabStop = false;
			this->toolTip1->SetToolTip(this->groupBox3, resources->GetString(L"groupBox3.ToolTip"));
			// 
			// pictureBox1
			// 
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
			this->toolTip1->SetToolTip(this->pictureBox1, resources->GetString(L"pictureBox1.ToolTip"));
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainUI::pictureBox1_Click);
			// 
			// toolTip1
			// 
			this->toolTip1->AutoPopDelay = 5000;
			this->toolTip1->InitialDelay = 0;
			this->toolTip1->ReshowDelay = 100;
			// 
			// comboBox_GCalibre
			// 
			resources->ApplyResources(this->comboBox_GCalibre, L"comboBox_GCalibre");
			this->comboBox_GCalibre->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_GCalibre->ForeColor = System::Drawing::SystemColors::WindowText;
			this->comboBox_GCalibre->FormattingEnabled = true;
			this->comboBox_GCalibre->Name = L"comboBox_GCalibre";
			this->comboBox_GCalibre->Tag = L"";
			this->toolTip1->SetToolTip(this->comboBox_GCalibre, resources->GetString(L"comboBox_GCalibre.ToolTip"));
			this->comboBox_GCalibre->SelectedIndexChanged += gcnew System::EventHandler(this, &MainUI::comboBox_GCalibre_SelectedIndexChanged);
			// 
			// label15
			// 
			resources->ApplyResources(this->label15, L"label15");
			this->label15->Name = L"label15";
			this->toolTip1->SetToolTip(this->label15, resources->GetString(L"label15.ToolTip"));
			// 
			// label17
			// 
			resources->ApplyResources(this->label17, L"label17");
			this->label17->Name = L"label17";
			this->toolTip1->SetToolTip(this->label17, resources->GetString(L"label17.ToolTip"));
			// 
			// menuStrip1
			// 
			resources->ApplyResources(this->menuStrip1, L"menuStrip1");
			this->menuStrip1->BackColor = System::Drawing::Color::White;
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->opçõesToolStripMenuItem });
			this->menuStrip1->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::HorizontalStackWithOverflow;
			this->menuStrip1->Name = L"menuStrip1";
			this->toolTip1->SetToolTip(this->menuStrip1, resources->GetString(L"menuStrip1.ToolTip"));
			// 
			// opçõesToolStripMenuItem
			// 
			resources->ApplyResources(this->opçõesToolStripMenuItem, L"opçõesToolStripMenuItem");
			this->opçõesToolStripMenuItem->BackColor = System::Drawing::Color::White;
			this->opçõesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->idiomaToolStripMenuItem,
					this->simularCorreçãoToolStripMenuItem
			});
			this->opçõesToolStripMenuItem->Name = L"opçõesToolStripMenuItem";
			// 
			// idiomaToolStripMenuItem
			// 
			resources->ApplyResources(this->idiomaToolStripMenuItem, L"idiomaToolStripMenuItem");
			this->idiomaToolStripMenuItem->BackColor = System::Drawing::Color::White;
			this->idiomaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->inglesEUAToolStripMenuItem,
					this->espanholToolStripMenuItem, this->portuguêsBrasilToolStripMenuItem
			});
			this->idiomaToolStripMenuItem->Name = L"idiomaToolStripMenuItem";
			// 
			// inglesEUAToolStripMenuItem
			// 
			resources->ApplyResources(this->inglesEUAToolStripMenuItem, L"inglesEUAToolStripMenuItem");
			this->inglesEUAToolStripMenuItem->BackColor = System::Drawing::Color::White;
			this->inglesEUAToolStripMenuItem->Name = L"inglesEUAToolStripMenuItem";
			this->inglesEUAToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainUI::inglesEUAToolStripMenuItem_Click);
			// 
			// espanholToolStripMenuItem
			// 
			resources->ApplyResources(this->espanholToolStripMenuItem, L"espanholToolStripMenuItem");
			this->espanholToolStripMenuItem->BackColor = System::Drawing::Color::White;
			this->espanholToolStripMenuItem->Name = L"espanholToolStripMenuItem";
			this->espanholToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainUI::espanholToolStripMenuItem_Click);
			// 
			// portuguêsBrasilToolStripMenuItem
			// 
			resources->ApplyResources(this->portuguêsBrasilToolStripMenuItem, L"portuguêsBrasilToolStripMenuItem");
			this->portuguêsBrasilToolStripMenuItem->BackColor = System::Drawing::Color::White;
			this->portuguêsBrasilToolStripMenuItem->Name = L"portuguêsBrasilToolStripMenuItem";
			this->portuguêsBrasilToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainUI::portuguêsBrasilToolStripMenuItem_Click);
			// 
			// simularCorreçãoToolStripMenuItem
			// 
			resources->ApplyResources(this->simularCorreçãoToolStripMenuItem, L"simularCorreçãoToolStripMenuItem");
			this->simularCorreçãoToolStripMenuItem->BackColor = System::Drawing::Color::White;
			this->simularCorreçãoToolStripMenuItem->Name = L"simularCorreçãoToolStripMenuItem";
			this->simularCorreçãoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainUI::simularCorreçãoToolStripMenuItem_Click);
			// 
			// MainUI
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupQiQmax);
			this->Controls->Add(this->groupBox_Errors);
			this->Controls->Add(this->comboBoxRange);
			this->Controls->Add(this->comboBox_GCalibre);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MainUI";
			this->toolTip1->SetToolTip(this, resources->GetString(L"$this.ToolTip"));
			this->Load += gcnew System::EventHandler(this, &MainUI::MainUI_Load);
			this->groupBox_Errors->ResumeLayout(false);
			this->groupBox_Errors->PerformLayout();
			this->groupQiQmax->ResumeLayout(false);
			this->groupQiQmax->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		};

		void resetForm() {

			labelResult->Text = "0,00";
			labelResult->ForeColor = Color::Black;
			TextBox_Qmax->Clear();
			textBox_07Qmax->Clear();
			textBox_04Qmax->Clear();
			textBox_025Qmax->Clear();
			textBox_015Qmax->Clear();
			textBox_010Qmax->Clear();
			textBox_005Qmax->Clear();
			textBox_Qmin->Clear();
			//
			// 10:1 
			//
			if (comboBoxRange->Text == "10:1") {

				// show 04
				textBox_04Qmax->Visible = true;
				label04Qmax->Visible = true;
				labelQ04Qmax->Visible = true;
				label6->Visible = true;
				label5->Visible = true;

				//positon 04
				textBox_04Qmax->Location = Point(89, 100);
				label04Qmax->Location = Point(9, 100);
				labelQ04Qmax->Location = Point(10, 116);
				label6->Location = Point(6, 100);
				label5->Location = Point(6, 116);

				//show 025
				textBox_025Qmax->Visible = true;
				label025Qmax->Visible = true;
				labelQ025Qmax->Visible = true;
				label8->Visible = true;
				label7->Visible = true;

				//position 025
				textBox_025Qmax->Location = Point(89, 139);
				label025Qmax->Location = Point(9, 139);
				labelQ025Qmax->Location = Point(10, 155);
				label8->Location = Point(6, 139);
				label7->Location = Point(6, 155);

				//positon Qmin
				textBox_Qmin->Location = Point(89, 178);
				labelQmin->Location = Point(40, 178);
				labelQQmin->Location = Point(6, 194);
				label16->Location = Point(6, 178);
				label_WFactor_Qmin->Location = Point(6, 194);

				//hide 15
				textBox_015Qmax->Visible = false;
				label015Qmax->Visible = false;
				labelQ015Qmax->Visible = false;
				label10->Visible = false;
				label9->Visible = false;

				//hide 10
				textBox_010Qmax->Visible = false;
				label010Qmax->Visible = false;
				labelQ010Qmax->Visible = false;
				label12->Visible = false;
				label11->Visible = false;

				//hide 05
				textBox_005Qmax->Visible = false;
				label005Qmax->Visible = false;
				labelQ005Qmax->Visible = false;
				label14->Visible = false;
				label13->Visible = false;

				//form readjust
				groupBox_Errors->Height = 218;
				groupQiQmax->Height = 218;
				this->Height = 440;
				
			}
			//
			// 20:1 
			//
			else if (comboBoxRange->Text == "20:1") {

				// show 04
				textBox_04Qmax->Visible = true;
				label04Qmax->Visible = true;
				labelQ04Qmax->Visible = true;
				label6->Visible = true;
				label5->Visible = true;

				//positon 04
				textBox_04Qmax->Location = Point(89, 100);
				label04Qmax->Location = Point(9, 100);
				labelQ04Qmax->Location = Point(10, 116);
				label6->Location = Point(6, 100);
				label5->Location = Point(6, 116);

				//show 025
				textBox_025Qmax->Visible = true;
				label025Qmax->Visible = true;
				labelQ025Qmax->Visible = true;
				label8->Visible = true;
				label7->Visible = true;

				//position 025
				textBox_025Qmax->Location = Point(89, 139);
				label025Qmax->Location = Point(9, 139);
				labelQ025Qmax->Location = Point(10, 155);
				label8->Location = Point(6, 139);
				label7->Location = Point(6, 155);

				//show 010
				textBox_010Qmax->Visible = true;
				label010Qmax->Visible = true;
				labelQ010Qmax->Visible = true;
				label12->Visible = true;
				label11->Visible = true;

				//position 010
				textBox_010Qmax->Location = Point(89, 178);
				label010Qmax->Location = Point(11, 178);
				labelQ010Qmax->Location = Point(10, 194);
				label12->Location = Point(6, 178);
				label11->Location = Point(6, 194);

				//position Qmin
				textBox_Qmin->Location = Point(89, 217);
				labelQmin->Location = Point(40, 217);
				labelQQmin->Location = Point(6, 233);
				label16->Location = Point(6, 217);
				label_WFactor_Qmin->Location = Point(6, 233);
				
				//hide 15
				textBox_015Qmax->Visible = false;
				label015Qmax->Visible = false;
				labelQ015Qmax->Visible = false;
				label10->Visible = false;
				label9->Visible = false;

				//hide 005
				textBox_005Qmax->Visible = false;
				label005Qmax->Visible = false;
				labelQ005Qmax->Visible = false;
				label14->Visible = false;
				label13->Visible = false;

				//form readjust
				groupBox_Errors->Height = 256;
				groupQiQmax->Height = 256;
				this->Height = 480;
				
			}
			//
			// 30:1 
			//
			else if (comboBoxRange->Text == "30:1") {

			// show 04
			textBox_04Qmax->Visible = true;
			label04Qmax->Visible = true;
			labelQ04Qmax->Visible = true;
			label6->Visible = true;
			label5->Visible = true;

			//positon 04
			textBox_04Qmax->Location = Point(89, 100);
			label04Qmax->Location = Point(9, 100);
			labelQ04Qmax->Location = Point(10, 116);
			label6->Location = Point(6, 100);
			label5->Location = Point(6, 116);

			//show 025
			textBox_025Qmax->Visible = true;
			label025Qmax->Visible = true;
			labelQ025Qmax->Visible = true;
			label8->Visible = true;
			label7->Visible = true;

			//position 025
			textBox_025Qmax->Location = Point(89, 139);
			label025Qmax->Location = Point(9, 139);
			labelQ025Qmax->Location = Point(10, 155);
			label8->Location = Point(6, 139);
			label7->Location = Point(6, 155);

			//show 010
			textBox_010Qmax->Visible = true;
			label010Qmax->Visible = true;
			labelQ010Qmax->Visible = true;
			label12->Visible = true;
			label11->Visible = true;

			//position 010
			textBox_010Qmax->Location = Point(89, 178);
			label010Qmax->Location = Point(11, 178);
			labelQ010Qmax->Location = Point(10, 194);
			label12->Location = Point(6, 178);
			label11->Location = Point(6, 194);

			//show 005
			textBox_005Qmax->Visible = true;
			label005Qmax->Visible = true;
			labelQ005Qmax->Visible = true;
			label14->Visible = true;
			label13->Visible = true;

			//position 005
			textBox_005Qmax->Location = Point(89, 217);
			label005Qmax->Location = Point(11, 217);
			labelQ005Qmax->Location = Point(10, 233);
			label14->Location = Point(6, 217);
			label13->Location = Point(6, 233);

			//position Qmin
			textBox_Qmin->Location = Point(89, 256);
			labelQmin->Location = Point(40, 256);
			labelQQmin->Location = Point(6, 272);
			label16->Location = Point(6, 256);
			label_WFactor_Qmin->Location = Point(6, 272);

			//hide 15
			textBox_015Qmax->Visible = false;
			label015Qmax->Visible = false;
			labelQ015Qmax->Visible = false;
			label10->Visible = false;
			label9->Visible = false;


			//form readjust
			groupBox_Errors->Height = 295;
			groupQiQmax->Height = 295;
			this->Height = 515;
				
			}
			//
			// 50:1+ 
			//
			else {

			//show 025
			textBox_025Qmax->Visible = true;
			label025Qmax->Visible = true;
			labelQ025Qmax->Visible = true;
			label8->Visible = true;
			label7->Visible = true;

			//position 025
			textBox_025Qmax->Location = Point(89, 100);
			label025Qmax->Location = Point(9, 100);
			labelQ025Qmax->Location = Point(10, 116);
			label8->Location = Point(6, 100);
			label7->Location = Point(6, 116);

			//show 015
			textBox_015Qmax->Visible = true;
			label015Qmax->Visible = true;
			labelQ015Qmax->Visible = true;
			label10->Visible = true;
			label9->Visible = true;

			//position 015
			textBox_015Qmax->Location = Point(89, 139);
			label015Qmax->Location = Point(10, 139);
			labelQ015Qmax->Location = Point(10, 155);
			label10->Location = Point(6, 139);
			label9->Location = Point(6, 155);

			//show 005
			textBox_005Qmax->Visible = true;
			label005Qmax->Visible = true;
			labelQ005Qmax->Visible = true;
			label14->Visible = true;
			label13->Visible = true;

			//position 005
			textBox_005Qmax->Location = Point(89, 178);
			label005Qmax->Location = Point(10, 178);
			labelQ005Qmax->Location = Point(10, 194);
			label14->Location = Point(6, 178);
			label13->Location = Point(6, 194);

			//position Qmin
			textBox_Qmin->Location = Point(89, 217);
			labelQmin->Location = Point(40, 217);
			labelQQmin->Location = Point(6, 233);
			label16->Location = Point(6, 217);
			label_WFactor_Qmin->Location = Point(6, 233);

			//hide 04
			textBox_04Qmax->Visible = false;
			label04Qmax->Visible = false;
			labelQ04Qmax->Visible = false;
			label6->Visible = false;
			label5->Visible = false;
			//hide 10
			textBox_010Qmax->Visible = false;
			label010Qmax->Visible = false;
			labelQ010Qmax->Visible = false;
			label12->Visible = false;
			label11->Visible = false;

			//form readjust
			groupBox_Errors->Height = 256;
			groupQiQmax->Height = 256;
			this->Height = 480;
				
			}
		}

		void getLanguage() {
			try
			{
				
				connection->Open();

				com->Connection = connection;

				com->CommandText = "select * from Localization";

				OleDbDataReader^ reader = com->ExecuteReader();
				while (reader->Read())
				{
					if ((Convert::ToString(reader["Languages"])) == "en-US"){
						CultureInfo^ ci = gcnew CultureInfo("en-US");
						CultureInfo::DefaultThreadCurrentUICulture = ci;
					}
					if ((Convert::ToString(reader["Languages"])) == "es") {
						CultureInfo^ ci = gcnew CultureInfo("es");
						CultureInfo::DefaultThreadCurrentUICulture = ci;
					}
					if ((Convert::ToString(reader["Languages"])) == "pt-BR") {
						CultureInfo^ ci = gcnew CultureInfo("pt-BR");
						CultureInfo::DefaultThreadCurrentUICulture = ci;
					}

				}
				
				connection->Close();

			}
			catch (Exception^)
			{
				String^ errorConnection;
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("en-US")) {
					errorConnection = "Could not connect to the database \"Languages\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("es")) {
					errorConnection = "No se pudo conectar a la base de datos \"Languages\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("pt-BR")) {
					errorConnection = "Não foi possível se conectar ao banco de dados \"Languages\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				else
				{
					errorConnection = "Could not connect to the database \"Languages\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}

				MessageBox::Show(errorConnection);
				Application::Exit();

			}
		}

		void saveNewLanguage() {
			
			try
			{
				
				connection->Open();

				com->Connection = connection;
				String^ query = "UPDATE Localization SET Languages= '" + Convert::ToString(CultureInfo::CurrentUICulture) + "' where Identificação=1";
				com->CommandText = query;
				com->ExecuteNonQuery();
				connection->Close();

			}
			catch (Exception^)
			{
				String^ errorConnection;
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("en-US")) {
					errorConnection = "Could not connect to the database \"Localization\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("es")) {
					errorConnection = "No se pudo conectar a la base de datos \"Localization\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("pt-BR")) {
					errorConnection = "Não foi possível se conectar ao banco de dados \"Localization\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				else
				{
					errorConnection = "Could not connect to the database \"Localization\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}

				MessageBox::Show(errorConnection);
				Application::Exit();

			}
		}

		void connectComboBox() {
			try
			{
				
				connection->Open();

				com->Connection = connection;

				com->CommandText = "select * from Data";

				OleDbDataReader^ reader = com->ExecuteReader();
				while (reader->Read())
				{
					comboBox_GCalibre->Items->Add(reader["G_Calibre"]);

				}
				for (int index = 3; index < reader->FieldCount; index++) {
					comboBoxRange->Items->Add(reader->GetName(index));
				}
				connection->Close();

			}
			catch (Exception^)
			{
				String^ errorConnection;
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("en-US")) {
					errorConnection = "Could not connect to the database \"Data\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				else if (Convert::ToString(CultureInfo::CurrentUICulture) == ("es")) {
					errorConnection = "No se pudo conectar a la base de datos \"Data\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				else if (Convert::ToString(CultureInfo::CurrentUICulture) == ("pt-BR")) {
					errorConnection = "Não foi possível se conectar ao banco de dados \"Data\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				else
				{
					errorConnection = "Could not connect to the database \"Data\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				
				MessageBox::Show(errorConnection);
				Application::Exit();
				
			}
		
			
		}

		void applyCalculatedGear() {


			if (TextBox_Qmax->Text == "") {
			}
			else {
				TextBox_Qmax->Text = String::Format("{0:0.00}", ((Convert::ToDouble(TextBox_Qmax->Text) + resultFromGears)));
			}
			if (textBox_07Qmax->Text == "") {
			}
			else {
				textBox_07Qmax->Text = String::Format("{0:0.00}", ((Convert::ToDouble(textBox_07Qmax->Text) + resultFromGears)));
			}
			if (textBox_04Qmax->Text == "") {
			}
			else {
				textBox_04Qmax->Text = String::Format("{0:0.00}", ((Convert::ToDouble(textBox_04Qmax->Text) + resultFromGears)));
			}
			if (textBox_025Qmax->Text == "") {
			}
			else {
				textBox_025Qmax->Text = String::Format("{0:0.00}", ((Convert::ToDouble(textBox_025Qmax->Text) + resultFromGears)));
			}
			if (textBox_015Qmax->Text == "") {
			}
			else {
				textBox_015Qmax->Text = String::Format("{0:0.00}", ((Convert::ToDouble(textBox_015Qmax->Text) + resultFromGears)));
			}
			if (textBox_010Qmax->Text == "") {
			}
			else {
				textBox_010Qmax->Text = String::Format("{0:0.00}", ((Convert::ToDouble(textBox_010Qmax->Text) + resultFromGears)));
			}
			if (textBox_005Qmax->Text == "") {
			}
			else {
				textBox_005Qmax->Text = String::Format("{0:0.00}", ((Convert::ToDouble(textBox_005Qmax->Text) + resultFromGears)));
			}
			if (textBox_Qmin->Text == "") {
			}
			else {
				textBox_Qmin->Text = String::Format("{0:0.00}", ((Convert::ToDouble(textBox_Qmin->Text) + resultFromGears)));
			}
			
		}

#pragma endregion
		
private: System::Void comboBox_GCalibre_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (comboBoxRange->Text == "") {
		comboBoxRange->Text = "20:1";
	}
	if (groupBox_Errors->Enabled == false) {
		groupBox_Errors->Enabled = true;
		groupQiQmax->Enabled = true;
	}
	setFlowRate(comboBox_GCalibre, comboBoxRange, label_QQmax, labelQ07Qmax, labelQ04Qmax, labelQ025Qmax, labelQ015Qmax, labelQ010Qmax, labelQ005Qmax, labelQQmin, label_WFactor_Qmin);	
}
private: System::Void comboBoxRange_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	
	resetForm();
	
	if (comboBox_GCalibre->Text == "") {
		comboBox_GCalibre->Text = "G10";
	}
	if (groupBox_Errors->Enabled == false) {
		groupBox_Errors->Enabled = true;
		groupQiQmax->Enabled = true;
	}
	
	setFlowRate(comboBox_GCalibre, comboBoxRange, label_QQmax, labelQ07Qmax, labelQ04Qmax, labelQ025Qmax, labelQ015Qmax, labelQ010Qmax, labelQ005Qmax, labelQQmin, label_WFactor_Qmin);
}		   
private: System::Void MainUI_Load(System::Object^ sender, System::EventArgs^ e) {

	connectComboBox();
	
}
private: System::Void TextBox_Qmax_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	checkKeyPress(TextBox_Qmax, e);
}
private: System::Void textBox_07Qmax_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	checkKeyPress(textBox_07Qmax, e);
}
private: System::Void textBox_04Qmax_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	checkKeyPress(textBox_04Qmax, e);
}
private: System::Void textBox_025Qmax_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	checkKeyPress(textBox_025Qmax, e);
}
private: System::Void textBox_015Qmax_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	checkKeyPress(textBox_015Qmax, e);
}
private: System::Void textBox_010Qmax_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	checkKeyPress(textBox_010Qmax, e);
}
private: System::Void textBox_005Qmax_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	checkKeyPress(textBox_005Qmax, e);
}
private: System::Void textBox_Qmin_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	checkKeyPress(textBox_Qmin, e);
}
private: System::Void TextBox_Qmax_Validated(System::Object^ sender, System::EventArgs^ e) {
	checkIsNumber(TextBox_Qmax, textBox_07Qmax, textBox_04Qmax, textBox_025Qmax, textBox_015Qmax, textBox_010Qmax, textBox_005Qmax, textBox_Qmin, labelResult, comboBox_GCalibre, comboBoxRange);
}
private: System::Void textBox_07Qmax_Validated(System::Object^ sender, System::EventArgs^ e) {
	checkIsNumber(TextBox_Qmax, textBox_07Qmax, textBox_04Qmax, textBox_025Qmax, textBox_015Qmax, textBox_010Qmax, textBox_005Qmax, textBox_Qmin, labelResult, comboBox_GCalibre, comboBoxRange);
	
}
private: System::Void textBox_04Qmax_Validated(System::Object^ sender, System::EventArgs^ e) {
	checkIsNumber(TextBox_Qmax, textBox_07Qmax, textBox_04Qmax, textBox_025Qmax, textBox_015Qmax, textBox_010Qmax, textBox_005Qmax, textBox_Qmin, labelResult, comboBox_GCalibre, comboBoxRange);
}
private: System::Void textBox_025Qmax_Validated(System::Object^ sender, System::EventArgs^ e) {
	checkIsNumber(TextBox_Qmax, textBox_07Qmax, textBox_04Qmax, textBox_025Qmax, textBox_015Qmax, textBox_010Qmax, textBox_005Qmax, textBox_Qmin, labelResult, comboBox_GCalibre, comboBoxRange);
}
private: System::Void textBox_015Qmax_Validated(System::Object^ sender, System::EventArgs^ e) {
	checkIsNumber(TextBox_Qmax, textBox_07Qmax, textBox_04Qmax, textBox_025Qmax, textBox_015Qmax, textBox_010Qmax, textBox_005Qmax, textBox_Qmin, labelResult, comboBox_GCalibre, comboBoxRange);
}
private: System::Void textBox_010Qmax_Validated(System::Object^ sender, System::EventArgs^ e) {
	checkIsNumber(TextBox_Qmax, textBox_07Qmax, textBox_04Qmax, textBox_025Qmax, textBox_015Qmax, textBox_010Qmax, textBox_005Qmax, textBox_Qmin, labelResult, comboBox_GCalibre, comboBoxRange);
}
private: System::Void textBox_005Qmax_Validated(System::Object^ sender, System::EventArgs^ e) {
	checkIsNumber(TextBox_Qmax, textBox_07Qmax, textBox_04Qmax, textBox_025Qmax, textBox_015Qmax, textBox_010Qmax, textBox_005Qmax, textBox_Qmin, labelResult, comboBox_GCalibre, comboBoxRange);
}
private: System::Void textBox_Qmin_Validated(System::Object^ sender, System::EventArgs^ e) {
	checkIsNumber(TextBox_Qmax, textBox_07Qmax, textBox_04Qmax, textBox_025Qmax, textBox_015Qmax, textBox_010Qmax, textBox_005Qmax, textBox_Qmin, labelResult, comboBox_GCalibre, comboBoxRange);
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

	WMEInfo^ openInfoForm = gcnew WMEInfo;
	openInfoForm->ShowDialog();

}
private: System::Void inglesEUAToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	CultureInfo^ ci = gcnew CultureInfo("en-US");
	CultureInfo::DefaultThreadCurrentUICulture = ci;
	saveNewLanguage();
	connection->Close();
	Controls->Clear();
	InitializeComponent();
	connectComboBox();
	
}
private: System::Void espanholToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	CultureInfo^ ci = gcnew CultureInfo("es");
	CultureInfo::DefaultThreadCurrentUICulture = ci;
	saveNewLanguage();
	Controls->Clear();
	InitializeComponent();
	connectComboBox();
	
}
private: System::Void portuguêsBrasilToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	CultureInfo^ ci = gcnew CultureInfo("pt-BR");
	CultureInfo::DefaultThreadCurrentUICulture = ci;
	saveNewLanguage();
	Controls->Clear();
	InitializeComponent();
	connectComboBox();
	
}   
private: System::Void simularCorreçãoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (comboBoxRange->Text ==  "" || comboBox_GCalibre->Text == "") {
		String^ strNoMeter;
		if (Convert::ToString(CultureInfo::CurrentUICulture) == ("en-US")) {
			strNoMeter = "No G Size selected.";
		}
		else if (Convert::ToString(CultureInfo::CurrentUICulture) == ("es")) {
			strNoMeter = "No se ha seleccionado una Designación G.";
		}
		else if (Convert::ToString(CultureInfo::CurrentUICulture) == ("pt-BR")) {
			strNoMeter = "Nenhuma Designação G selecionada.";
		}
		else
		{
			strNoMeter = "No G Size selected.";
		}

		MessageBox::Show(strNoMeter);
	}
	else {
		GearCorrection^ callForm = gcnew GearCorrection;
		callForm->ShowDialog();
		if (callForm->checkCalutateBtn) {
			resultFromGears = callForm->resultGear;
			applyCalculatedGear();
			checkIsNumber(TextBox_Qmax, textBox_07Qmax, textBox_04Qmax, textBox_025Qmax, textBox_015Qmax, textBox_010Qmax, textBox_005Qmax, textBox_Qmin, labelResult, comboBox_GCalibre, comboBoxRange);
		}
	}
	
}
};
}
