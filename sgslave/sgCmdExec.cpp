/*==============================================================================
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include "sgMessage.h"
#include "sgCmdExec.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace SG
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
   mTxCount = 0;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Process the input command contained in the receive buffer
// and place a response in the transmit buffer.

void CmdExec::doProcess(
   char* aRxBuffer,      // Input
   int   aRxLength,      // Input
   char* aTxBuffer,      // Output
   int*  aTxLength)      // Output
{
   // Reset the transmit variables.
   *aTxLength = 0;

   // Guard.
   if (aRxLength < 32) return;

   // Message header and payload variables.
   UsbHello_t tHello;
   CodeVersions_s tCodeVersions;
   memset(&tHello, 0, sizeof(tHello));
   memset(&tCodeVersions, 0, sizeof(tCodeVersions));

   // Fill header variables.
   tHello.cSync[0] = 'S';
   tHello.cSync[1] = 'G';
   tHello.uiSequenceNumber = mTxCount;
   tHello.usPacketID = 1;
   tHello.uiUnusedDataLength = sizeof(tCodeVersions);
   tHello.uiMachineType = 19;
   tHello.uiSoftwareVersion = 0x010203;
   tHello.uiIsBootCode = 1;
   tHello.uiRevisionNumber = 102;
   tHello.uiSampleEnabled = 2;

   // Fill payload variables.
   tCodeVersions.uiID = 0;
   tCodeVersions.uiBuild = 103;

   // Copy variables to transmit buffer.
   memcpy(&aTxBuffer[0], &tHello, sizeof(tHello));
   memcpy(&aTxBuffer[sizeof(tHello)], &tCodeVersions, sizeof(tCodeVersions));
   *aTxLength = sizeof(tHello) + sizeof(tCodeVersions);
   mTxCount++;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace