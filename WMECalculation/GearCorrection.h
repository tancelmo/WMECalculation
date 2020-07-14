#pragma once



namespace WMECalculation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;
	using namespace System::Globalization;
	using namespace System::Threading;


	
	/// <summary>
	/// Sumário para GearCorrection
	/// </summary>
	public ref class GearCorrection : public System::Windows::Forms::Form
	{
	public:
		double r1, r2, resultGear;
	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::PictureBox^ pictureBox_r1gear;
	private: System::Windows::Forms::PictureBox^ pictureBox_r2gear;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

	public:

	public:

		   bool checkCalutateBtn;
		GearCorrection()
		{
			
			InitializeComponent();
			//labelResult->Text = v;
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

		


	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~GearCorrection()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelCurrentGear;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	public: System::Windows::Forms::Label^ labelResult;
	public: System::Windows::Forms::Button^  button1;
	private:



	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		OleDbConnection^ connection = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=WMEData.accdb;Persist Security Info=True");
		OleDbCommand^ com = gcnew OleDbCommand();

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GearCorrection::typeid));
			this->labelCurrentGear = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->labelResult = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->pictureBox_r1gear = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_r2gear = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_r1gear))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_r2gear))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// labelCurrentGear
			// 
			resources->ApplyResources(this->labelCurrentGear, L"labelCurrentGear");
			this->labelCurrentGear->Name = L"labelCurrentGear";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			resources->ApplyResources(this->comboBox1, L"comboBox1");
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &GearCorrection::comboBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			resources->ApplyResources(this->comboBox2, L"comboBox2");
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &GearCorrection::comboBox2_SelectedIndexChanged);
			// 
			// labelResult
			// 
			resources->ApplyResources(this->labelResult, L"labelResult");
			this->labelResult->Name = L"labelResult";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &GearCorrection::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->labelResult);
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"NOIMG.png");
			// 
			// pictureBox_r1gear
			// 
			resources->ApplyResources(this->pictureBox_r1gear, L"pictureBox_r1gear");
			this->pictureBox_r1gear->Name = L"pictureBox_r1gear";
			this->pictureBox_r1gear->TabStop = false;
			// 
			// pictureBox_r2gear
			// 
			resources->ApplyResources(this->pictureBox_r2gear, L"pictureBox_r2gear");
			this->pictureBox_r2gear->Name = L"pictureBox_r2gear";
			this->pictureBox_r2gear->TabStop = false;
			// 
			// pictureBox2
			// 
			resources->ApplyResources(this->pictureBox2, L"pictureBox2");
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->TabStop = false;
			// 
			// GearCorrection
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox_r2gear);
			this->Controls->Add(this->pictureBox_r1gear);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->labelCurrentGear);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"GearCorrection";
			this->Load += gcnew System::EventHandler(this, &GearCorrection::GearCorrection_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_r1gear))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_r2gear))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void connectComboBoxRanges() {
			try
			{
				
				connection->Open();

				com->Connection = connection;

				com->CommandText = "select * from CalibrationGears";

				OleDbDataReader^ reader = com->ExecuteReader();
				while (reader->Read())
				{
					comboBox1->Items->Add(reader["StringGear"]);
					comboBox2->Items->Add(reader["StringGear"]);

				}
				connection->Close();

			}
			catch (Exception^)
			{
				String^ errorConnection;
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("en-US")) {
					errorConnection = "Could not connect to the database \"CalibrationGears\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("es")) {
					errorConnection = "No se pudo conectar a la base de datos \"CalibrationGears\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("pt-BR")) {
					errorConnection = "Não foi possível se conectar ao banco de dados \"CalibrationGears\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				else
				{
					errorConnection = "Could not connect to the database \"CalibrationGears\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}

				MessageBox::Show(errorConnection);
				this->Close();

			}
		}

		void calculateGears1() {
			try
			{
				
				
				connection->Open();

				com->Connection = connection;

				com->CommandText = "select * from CalibrationGears where StringGear='" + comboBox1->Text + "'";
				
				OleDbDataReader^ reader = com->ExecuteReader();
				while (reader->Read())
				{
					r1 = Convert::ToDouble(reader["Correction"]);
					

				}
				connection->Close();

			}
			catch (Exception^)
			{
				String^ errorConnection;
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("en-US")) {
					errorConnection = "Could not connect to the database \"CalibrationGears\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("es")) {
					errorConnection = "No se pudo conectar a la base de datos \"CalibrationGears\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("pt-BR")) {
					errorConnection = "Não foi possível se conectar ao banco de dados \"CalibrationGears\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				else
				{
					errorConnection = "Could not connect to the database \"CalibrationGears\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}

				MessageBox::Show(errorConnection);
				this->Close();

			}
		}

		void calculateGears2() {
			try
			{

				
				connection->Open();

				com->Connection = connection;

				com->CommandText = "select * from CalibrationGears where StringGear='" + comboBox2->Text + "'";

				OleDbDataReader^ reader = com->ExecuteReader();
				while (reader->Read())
				{
					r2 = Convert::ToDouble(reader["Correction"]);
					

				}
				connection->Close();

			}
			catch (Exception^)
			{
				String^ errorConnection;
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("en-US")) {
					errorConnection = "Could not connect to the database \"CalibrationGears\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("es")) {
					errorConnection = "No se pudo conectar a la base de datos \"CalibrationGears\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				if (Convert::ToString(CultureInfo::CurrentUICulture) == ("pt-BR")) {
					errorConnection = "Não foi possível se conectar ao banco de dados \"CalibrationGears\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}
				else
				{
					errorConnection = "Could not connect to the database \"CalibrationGears\"\n" + Convert::ToString(Application::StartupPath) + "\\WMEData.accdb";
				}

				MessageBox::Show(errorConnection);
				this->Close();

			}
		}

		void resultCalc() {
			if (comboBox1->Text == "" || comboBox2->Text == "") {}
			else
			{
				if (r1 + r2 < 0 && r1 > r2) {
					resultGear = Math::Abs(r1 - r2) * -1;
				}

				else if (r1 + r2 > 0 && r1 > r2)
				{
					resultGear = Math::Abs(r1 - r2) * -1;
				}

				else {
					resultGear = Math::Abs(r1 - r2);
				}
				labelResult->Text = ((String::Format("{0:0.00}", resultGear)) + " %");
				
			}
		}

		void gearsImgR1() {
			try
			{
				pictureBox_r1gear->Image = gcnew Bitmap(Convert::ToString(Application::StartupPath) + "\\images\\gears\\" + (comboBox1->Text->Replace(";", "_"))->Remove(5) + ".png");
			}
			catch (Exception^)
			{
				pictureBox_r1gear->Image = imageList1->Images[0];
			}
			
		}

		void gearsImgR2() {
			try
			{
				pictureBox_r2gear->Image = gcnew Bitmap(Convert::ToString(Application::StartupPath) + "\\images\\gears\\" + (comboBox2->Text->Replace(";", "_"))->Remove(5) + ".png");
			}
			catch (Exception^)
			{
				pictureBox_r2gear->Image = imageList1->Images[0];
			}

		}
		
		
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		checkCalutateBtn = true;
		resultCalc();
		this->Close();
		
		
		
	}
private: System::Void GearCorrection_Load(System::Object^  sender, System::EventArgs^  e) {
	connectComboBoxRanges();
	comboBox1->SelectedIndex = 22;
	comboBox2->SelectedIndex = 22;
	labelResult->Focus();

	
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	calculateGears1();
	resultCalc();
	gearsImgR1();
	

}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	calculateGears2();
	resultCalc();
	gearsImgR2();
}
};
}
