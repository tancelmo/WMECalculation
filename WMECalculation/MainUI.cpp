#include "MainUI.h"
using namespace System::Data::OleDb;
using namespace System;
using namespace System::Windows::Forms;


[STAThread]

int main(array<System::String^>^ args)
{
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WMECalculation::MainUI form;
	Application::Run(%form);

	return 0;
}