#pragma once
using namespace System::Windows::Forms;

void checkIsNumber(TextBox^ checkIsNumberQmax, TextBox^ checkIsNumber07Qmax, TextBox^ checkIsNumber04Qmax, TextBox^ checkIsNumber025Qmax, TextBox^ checkIsNumber015Qmax, TextBox^ checkIsNumber010Qmax, TextBox^ checkIsNumber005Qmax, TextBox^ checkIsNumberQmin, Label^ resultLabel, ComboBox^ comboBoxGC, ComboBox^ comboBoxRangeC);
void Calculation(TextBox^ QmaxValue, TextBox^ e07QmaxValue, TextBox^ e04QmaxValue, TextBox^ e025QmaxValue, TextBox^ e015QmaxValue, TextBox^ e010QmaxValue, TextBox^ e005QmaxValue, TextBox^ eQminValue, Label^ labelResult, ComboBox^ comboBoxGC, ComboBox^ comboBoxRangeC);
void checkKeyPress(TextBox^ checkKeyPress, KeyPressEventArgs^ e);
void setFlowRate(ComboBox^ comboBoxG, ComboBox^ comboBoxRange, Label^ flowQmax, Label^ flow07Qmax, Label^ flow04Qmax, Label^ flow025Qmax, Label^ flow015Qmax, Label^ flow010Qmax, Label^ flow005Qmax, Label^ flowQmin, Label^ labelWFQmin);