#pragma once
using namespace System::Windows::Forms;

void getQiQmin(ComboBox^ comboBoxGC, ComboBox^ comboBoxRangeC);
void Calculation(TextBox^ QmaxValue, TextBox^ e07QmaxValue, TextBox^ e04QmaxValue, TextBox^ e025QmaxValue, TextBox^ e015QmaxValue, TextBox^ e010QmaxValue, TextBox^ e005QmaxValue, TextBox^ eQminValue, Label^ labelResult, ComboBox^ comboBoxGC, ComboBox^ comboBoxRangeC);