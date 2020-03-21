#include "StarterPage.h"

/*
 * StarterPage.cpp
 *
 * This file includes two basic functions: button_click and lable_change.
 *
 * @author: Hang Yuan
 * Revised: 3/21/20
 *
 */

/*
 * btn_ChangeLable_Click
 * This method changed the color and text content of Label : lbl_Title
 * @param: None
 * @return None
 */
System::Void WeAlumni::StarterPage::btn_ChangeLabel_Click(System::Object^ sender, System::EventArgs^ e) {
    if (_font == Lbl_Font::blue) {
        lbl_Title->ForeColor = Color::Red;
        lbl_Title->Text = "标签切换为红色";
        _font = Lbl_Font::red;
    }
    else {
        lbl_Title->ForeColor = Color::Blue;
        lbl_Title->Text = "标签切换为蓝色";
        _font = Lbl_Font::blue;
    }
}

/*
 * btn_JumpAnotherPage_Click
 * This method start a new page: 
 * @param: None
 * @return None
 */
System::Void WeAlumni::StarterPage::btn_JumpAnotherPage_Click(System::Object^ sender, System::EventArgs^ e) {
    NewPage^ newPage = gcnew NewPage();
    newPage->Show();
}