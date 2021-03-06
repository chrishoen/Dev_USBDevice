#include "stdafx.h"

#include "risThreadsProcess.h"
#include "risThreadsThreads.h"
#include "someUSBDeviceParms.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Initialize program resources.

void main_initialize(int argc,char** argv)
{
   printf("serialslave Program********************************************BEGIN\n");

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Enter process.

   // Set program process for high priority.
   Ris::Threads::enterProcessHigh();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize print facility.

   // Initialize print.
   Prn::resetPrint();
   Prn::initializePrint();

   // Initialize print filters.
   Prn::setFilter(Prn::Show1, true);
   Prn::setFilter(Prn::Show2, false);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Read parameters files.

   Some::gUSBDeviceParms.reset();
   Some::gUSBDeviceParms.readSection("default");


   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize program resources.

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   Prn::print(Prn::Show1, "serialslave Program*******************************************BEGIN");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Finalize program resourcs.

void main_finalize()
{
   Prn::print(Prn::Show1, "serialslave Program*******************************************END");
   printf("\n");
   printf("serialslave Program********************************************END\n");

   // Finalize print facility.
   Prn::finalizePrint();

   // Exit process.
   Ris::Threads::exitProcess();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
