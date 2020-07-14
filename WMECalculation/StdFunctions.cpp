#include "MainUI.h"
#include"StdFunctions.h"
#include "Calculation.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::OleDb;
using namespace System::Globalization;
using namespace System::Threading;


void checkIsNumber(TextBox^ checkIsNumberQmax, TextBox^ checkIsNumber07Qmax, TextBox^ checkIsNumber04Qmax, TextBox^ checkIsNumber025Qmax, TextBox^ checkIsNumber015Qmax, TextBox^ checkIsNumber010Qmax, TextBox^ checkIsNumber005Qmax, TextBox^ checkIsNumberQmin, Label^ resultLabel, ComboBox^ comboBoxGC, ComboBox^ comboBoxRangeC) {

	

	double checkValidValue;
			
	String^ InvalidValue; 

	if (Convert::ToString(CultureInfo::DefaultThreadCurrentUICulture) == ("en-US")) {
		InvalidValue = "Only numbers are allowed. Try again.";
	}
	else if (Convert::ToString(CultureInfo::DefaultThreadCurrentUICulture) == ("es")) {
		InvalidValue = "Solo se permiten números. Inténtalo de nuevo.";
	}
	else if (Convert::ToString(CultureInfo::DefaultThreadCurrentUICulture) == ("pt-BR")) {
		InvalidValue = "Apenas valores numéricos são permitidos. Tente novamente.";
	}
	else {
		InvalidValue = "Only numbers are allowed. Try again.";
	}

	if (checkIsNumberQmax->Text == String::Empty) {
	}

	else if (!double::TryParse(checkIsNumberQmax->Text, checkValidValue)) { //checar se é um numero valido
		MessageBox::Show(InvalidValue);
		checkIsNumberQmax->Clear();
		checkIsNumberQmax->Select();
	}

	if (checkIsNumber07Qmax->Text == String::Empty) {
	}

	else if (!double::TryParse(checkIsNumber07Qmax->Text, checkValidValue)) { 
		MessageBox::Show(InvalidValue);
		checkIsNumber07Qmax->Clear();
		checkIsNumber07Qmax->Select();
	}

	if (checkIsNumber04Qmax->Text == String::Empty) {
	}

	else if (!double::TryParse(checkIsNumber04Qmax->Text, checkValidValue)) { 
		MessageBox::Show(InvalidValue);
		checkIsNumber04Qmax->Clear();
		checkIsNumber04Qmax->Select();
	}
	if (checkIsNumber025Qmax->Text == String::Empty) {
	}

	else if (!double::TryParse(checkIsNumber025Qmax->Text, checkValidValue)) { 
		MessageBox::Show(InvalidValue);
		checkIsNumber025Qmax->Clear();
		checkIsNumber025Qmax->Select();
	}
	if (checkIsNumber015Qmax->Text == String::Empty) {
	}

	else if (!double::TryParse(checkIsNumber015Qmax->Text, checkValidValue)) { 
		MessageBox::Show(InvalidValue);
		checkIsNumber015Qmax->Clear();
		checkIsNumber015Qmax->Select();
	}
	if (checkIsNumber010Qmax->Text == String::Empty) {
	}

	else if (!double::TryParse(checkIsNumber010Qmax->Text, checkValidValue)) { 
		MessageBox::Show(InvalidValue);
		checkIsNumber010Qmax->Clear();
		checkIsNumber010Qmax->Select();
	}
	if (checkIsNumber005Qmax->Text == String::Empty) {
	}

	else if (!double::TryParse(checkIsNumber005Qmax->Text, checkValidValue)) { 
		MessageBox::Show(InvalidValue);
		checkIsNumber005Qmax->Clear();
		checkIsNumber005Qmax->Select();
	}
	if (checkIsNumberQmin->Text == String::Empty) {
	}

	else if (!double::TryParse(checkIsNumberQmin->Text, checkValidValue)) { 
		MessageBox::Show(InvalidValue);
		checkIsNumberQmin->Clear();
		checkIsNumberQmin->Select();
	}
	else {

	}
	Calculation(checkIsNumberQmax, checkIsNumber07Qmax, checkIsNumber04Qmax, checkIsNumber025Qmax, checkIsNumber015Qmax, checkIsNumber010Qmax, checkIsNumber005Qmax, checkIsNumberQmin, resultLabel, comboBoxGC, comboBoxRangeC);
}

void checkKeyPress(TextBox^ checkKeyPress, KeyPressEventArgs^ e) {

	if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-') {  //limitar caracteres  a numeros virgula 
		System::Media::SystemSounds::Beep->Play();
		e->Handled = true;
	}
	wchar_t ch = e->KeyChar;
	if (ch == ',' && checkKeyPress->Text->IndexOf(',') != -1) { //apenas uma virgula
		e->Handled = true;
	}
	if (ch == '-' && checkKeyPress->Text->IndexOf('-') != -1) { //apenas um sinal negativo
		e->Handled = true;
	}
	if (ch == 13) { //desabilitar tecla enter e substituir por TAB
		e->Handled = true;
		SendKeys::Send("{TAB}");
	}
}

void setFlowRate(ComboBox^ comboBoxG, ComboBox^ comboBoxRange, Label^ flowQmax, Label^ flow07Qmax, Label^ flow04Qmax, Label^ flow025Qmax, Label^ flow015Qmax, Label^ flow010Qmax, Label^ flow005Qmax, Label^ flowQmin, Label^ labelWFQmin) {

	OleDbConnection^ connection = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=WMEData.accdb;Persist Security Info=True");
	OleDbCommand^ com = gcnew OleDbCommand();
	connection->Open();
	com->Connection = connection;

	com->CommandText = "select * from Data where G_Calibre='" + comboBoxG->Text + "'";

	OleDbDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{
		double flow = (Convert::ToDouble(reader["Qmax"]));
		double QiQmin = (Convert::ToDouble(reader[Convert::ToString(comboBoxRange->Text)]));

		flowQmax->Text = (Convert::ToString(flow) + " m³/h");
		flow07Qmax->Text = (Convert::ToString(flow * 0.7) + " m³/h");
		flow04Qmax->Text = (Convert::ToString(flow * 0.4) + " m³/h");
		flow025Qmax->Text = (Convert::ToString(flow * 0.25) + " m³/h");
		flow015Qmax->Text = (Convert::ToString(flow * 0.15) + " m³/h");
		flow010Qmax->Text = (Convert::ToString(flow * 0.10) + " m³/h");
		flow005Qmax->Text = (Convert::ToString(flow * 0.05) + " m³/h");
		flowQmin->Text = (Convert::ToString(reader[Convert::ToString(comboBoxRange->Text)]) + " m³/h");
		labelWFQmin->Text = (String::Format("{0:#.###}", (Convert::ToString(QiQmin / flow))));


	}
	connection->Close();
}