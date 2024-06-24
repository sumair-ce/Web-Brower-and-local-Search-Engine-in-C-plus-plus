#include "guiform.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DSProject::guiform form;
	Application::Run(% form);

}