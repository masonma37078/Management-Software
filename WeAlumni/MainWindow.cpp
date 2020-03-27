#include "MainWindow.h"

/*
 * MainWindow.h
 *
 * This file implements all sub-functions required in the MainWindow.
 *
 * @author: Hang Yuan
 * Revised: 3/27/20
 *
 */

/*
 * SetAllPanelInvisible
 * This method will change all property Visible of all panels into false
 * @param None
 * @return None
 */
void WeAlumni::MainWindow::SetAllPanelInvisible() {
	pan_member->Visible = false;
	pan_staff->Visible = false;
	pan_record->Visible = false;
	pan_OPT->Visible = false;
	pan_order->Visible = false;
	pan_treasury->Visible = false;
	pan_myInfo->Visible = false;
}