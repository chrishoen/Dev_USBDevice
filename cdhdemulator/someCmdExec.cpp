/*==============================================================================
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include "someCmdExec.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

CmdExec::CmdExec()
{
   reset();
}

void CmdExec::reset()
{
   mRxValid = false;
   mRxLength = 0;
   mRxBuffer[0] = 0;
   mTxValid = false;
   mTxLength = 0;
   mTxBuffer[0] = 0;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Process the input command contained in the receive string
// and place a response in the transmit string.

void CmdExec::doProcess()
{
   // Reset the transmit variables.
   mTxValid = false;
   mTxLength = 0;
   mTxBuffer[0] = 0;

   // Guard.
   if (mRxLength < 2) return;

   // Formulate a response.
   mTxLength = sprintf(mTxBuffer, "RESPONSE");
   mTxValid = true;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace