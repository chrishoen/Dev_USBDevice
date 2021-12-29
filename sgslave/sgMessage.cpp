/*==============================================================================
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include "sgMessage.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace SG
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

void showDefaultPacket(UsbDefaultPacket_t* aP)
{
   Prn::print(Prn::Show1, "UsbDefaultPacket_t************************");

   Prn::print(Prn::Show1, "cSync               %02x %02x $ %c %c",
      (int)aP->cSync[0], (int)aP->cSync[1], aP->cSync[0], aP->cSync[1]);

   Prn::print(Prn::Show1, "uiSequenceNumber    %d", aP->uiSequenceNumber);
   Prn::print(Prn::Show1, "usPacketID          %d", (int)aP->usPacketID);
   Prn::print(Prn::Show1, "uiDataLength        %d", aP->uiDataLength);
   Prn::print(Prn::Show1, "uiP1                %d", aP->uiP1);
   Prn::print(Prn::Show1, "uiP2                %d", aP->uiP2);
   Prn::print(Prn::Show1, "uiP3                %d", aP->uiP3);
   Prn::print(Prn::Show1, "uiP4                %d", aP->uiP4);
   Prn::print(Prn::Show1, "uiP5                %d", aP->uiP5);

   Prn::print(Prn::Show1, "");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace