#include "LoginPage.h"
#include "MainWindow.h"

/*
 * Main.cpp
 *
 * This file includes Main function as the entry point.
 *
 * @author: Hang Yuan
 * Revised: 3/21/20
 *
 */

/*
* Application-Entry Page, including a Main method to raise the StarterPage.
*/
System::Void Main(array<System::String^>^ args)
{
    System::Windows::Forms::Application::EnableVisualStyles();
    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

    WeAlumni::LoginPage^ login = gcnew WeAlumni::LoginPage();
    login->ShowDialog();
    WeAlumni::MainWindow mainWindow(login->GetPublicUserInfo());
    login->Close();
    System::Windows::Forms::Application::Run(% mainWindow);
}