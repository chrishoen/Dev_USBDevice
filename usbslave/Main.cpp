#include "stdafx.h"

#include "risThreadsProcess.h"
#include "MainInit.h"
#include "risCmdLineConsole.h"
#include "CmdLineExec.h"

#include "someUSBDeviceParms.h"
#include "SlaveThread.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

int main(int argc,char** argv)
{
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Begin program.

   main_initialize(argc, argv);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Launch program threads.

   if (Some::gUSBDeviceParms.mEnable1)
   {
      gSlaveThread1 = new SlaveThread(1);
      gSlaveThread1->launchThread();
   }
   if (Some::gUSBDeviceParms.mEnable2)
   {
      gSlaveThread2 = new SlaveThread(2);
      gSlaveThread2->launchThread();
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Show program threads.

   Ris::Threads::showCurrentThreadInfo();
   if (gSlaveThread1)    gSlaveThread1->showThreadInfo();
   if (gSlaveThread2)    gSlaveThread2->showThreadInfo();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Execute console command line executive, wait for user to exit.

   CmdLineExec* tExec = new CmdLineExec;
   Ris::gCmdLineConsole.execute(tExec);
   delete tExec;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Shutdown program threads.

   if (gSlaveThread1)     gSlaveThread1->shutdownThread();
   if (gSlaveThread2)     gSlaveThread2->shutdownThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Delete program threads.

   if (gSlaveThread1)
   {
      delete gSlaveThread1;
      gSlaveThread1 = 0;
   }
   if (gSlaveThread2)
   {
      delete gSlaveThread2;
      gSlaveThread2 = 0;
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // End program.

   main_finalize();
   return 0;
}
