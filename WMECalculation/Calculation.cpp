#include "MainUI.h"
#include "Calculation.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::OleDb;





double cFlow;
double cQiQmin;

void getQiQmin(ComboBox^ comboBoxGC0, ComboBox^ comboBoxRangeC0) {
	OleDbConnection^ connection = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=WMEData.accdb;Persist Security Info=True");
	OleDbCommand^ com = gcnew OleDbCommand();
	connection->Open();
	com->Connection = connection;

	com->CommandText = "select * from Data where G_Calibre='" + comboBoxGC0->Text + "'";

	OleDbDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{
		cFlow = (Convert::ToDouble(reader["Qmax"]));
		cQiQmin = (Convert::ToDouble(reader[Convert::ToString(comboBoxRangeC0->Text)]));

	}
	connection->Close();
}



void Calculation(TextBox^ QmaxValue, TextBox^ e07QmaxValue, TextBox^ e04QmaxValue, TextBox^ e025QmaxValue, TextBox^ e015QmaxValue, TextBox^ e010QmaxValue, TextBox^ e005QmaxValue, TextBox^ eQminValue, Label^ labelResult, ComboBox^ comboBoxGC, ComboBox^ comboBoxRangeC) {

	double Qmax, e07Qmax, e04Qmax, e025Qmax, e015Qmax, e010Qmax, e005Qmax, eQmin, result, check;
	double QiQmax, Qi07Qmax, Qi04Qmax, Qi025Qmax, Qi015Qmax, Qi010Qmax, Qi005Qmax, QiQmin;

	if (!double::TryParse(QmaxValue->Text, check)) {
		Qmax = 0;
	}
	else {
		Qmax = Convert::ToDouble(QmaxValue->Text);
		QiQmax = 0.40;
	}
	if (!double::TryParse(e07QmaxValue->Text, check)) {
		e07Qmax = 0;
	}
	else {
		e07Qmax = Convert::ToDouble(e07QmaxValue->Text);
		Qi07Qmax = 0.70;
	}
	if (!double::TryParse(e04QmaxValue->Text, check)) {
		e04Qmax = 0;
	}
	else {
		e04Qmax = Convert::ToDouble(e04QmaxValue->Text);
		Qi04Qmax = 0.40;
	}
	if (!double::TryParse(e025QmaxValue->Text, check)) {
		e025Qmax = 0;
	}
	else {
		e025Qmax = Convert::ToDouble(e025QmaxValue->Text);
		Qi025Qmax = 0.25;
	}
	if (!double::TryParse(e015QmaxValue->Text, check)) {
		e015Qmax = 0;
	}
	else {
		e015Qmax = Convert::ToDouble(e015QmaxValue->Text);
		Qi015Qmax = 0.15;
	}
	if (!double::TryParse(e010QmaxValue->Text, check)) {
		e010Qmax = 0;
	}
	else {
		e010Qmax = Convert::ToDouble(e010QmaxValue->Text);
		Qi010Qmax = 0.10;
	}
	if (!double::TryParse(e005QmaxValue->Text, check)) {
		e005Qmax = 0;
	}
	else {
		e005Qmax = Convert::ToDouble(e005QmaxValue->Text);
		Qi005Qmax = 0.05;
	}
	if (!double::TryParse(eQminValue->Text, check)) {
		eQmin = 0;
	}
	else {
		getQiQmin(comboBoxGC, comboBoxRangeC);
		eQmin = Convert::ToDouble(eQminValue->Text);
		QiQmin = cQiQmin / cFlow;
	}


	result = ((QiQmax * Qmax) + (Qi07Qmax * e07Qmax) + (Qi04Qmax * e04Qmax) + (Qi025Qmax * e025Qmax) + (Qi015Qmax * e015Qmax) + (Qi010Qmax * e010Qmax) + (Qi005Qmax * e005Qmax) + (QiQmin * eQmin)) / (QiQmax + Qi07Qmax + Qi04Qmax + Qi025Qmax + Qi015Qmax + Qi010Qmax + Qi005Qmax + QiQmin);
	if (Double::IsNaN(result))
	{
		result = 0;
	}
	labelResult->Text = (String::Format("{0:0.00}", result));

	if (result > 0.404 || result < -0.404) {
		labelResult->ForeColor = Color::Red;
	}
	else if (result <= 0.404 && result >= 0.40 || result > -0.404 && result < -0.4) {
		labelResult->ForeColor = Color::Orange;
	}
	else {
		labelResult->ForeColor = Color::Black;
	}




}

