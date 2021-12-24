//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include "risCmdLineFile.h"

#define  _SOMEUSBDEVICEPARMS_CPP_
#include "someUSBDeviceParms.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

USBDeviceParms::USBDeviceParms()
{
   reset();
}

void USBDeviceParms::reset()
{
   BaseClass::reset();
   if (Ris::portableIsWindows())
   {
      BaseClass::setFilePath("c:/aaa_prime/files/USBDevice_Parms.txt");
   }
   else
   {
      BaseClass::setFilePath("/opt/prime/files/USBDevice_Parms.txt");
   }

   mDeviceDevPath[0]=0;
   mDelay1 = 0;
   mDelay2 = 0;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Show.

void USBDeviceParms::show()
{
   printf("\n");
   printf("USBDeviceParms************************************************ %s\n", mTargetSection);

   printf("\n");
   printf("DeviceDevPath            %-10s\n", mDeviceDevPath);
   printf("Delay1                   %-10d\n", mDelay1);
   printf("Delay2                   %-10d\n", mDelay2);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Base class override: Execute a command from the command file to set a 
// member variable.  Only process commands for the target section.This is
// called by the associated command file object for each command in the file.

void USBDeviceParms::execute(Ris::CmdLineCmd* aCmd)
{
   if (!isTargetSection(aCmd)) return;

   if (aCmd->isCmd("DeviceDevPath"))         aCmd->copyArgString(1, mDeviceDevPath, cMaxStringSize);
   if (aCmd->isCmd("Delay1"))                mDelay1 = aCmd->argInt(1);
   if (aCmd->isCmd("Delay2"))                mDelay2 = aCmd->argInt(1);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Calculate expanded member variables. This is called after the entire
// section of the command file has been processed.

void USBDeviceParms::expand()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace