#pragma once

/*==============================================================================

==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace SG
{

//******************************************************************************
//******************************************************************************
//******************************************************************************

#ifdef _WIN32
#pragma pack(push,1)
#define PACKED
#else
#define PACKED __attribute__ ((packed))
#endif

enum
{
   eSensorBoard
};

typedef struct CodeVersions_s
{
   unsigned int uiID;
   unsigned int uiBuild;
} CodeVersions_t;

typedef struct
{
   unsigned char cSync[2];
   unsigned int uiSequenceNumber;
   unsigned short usPacketID;
   unsigned int uiDataLength;
   unsigned int uiP1;
   unsigned int uiP2;
   unsigned int uiP3;
   unsigned int uiP4;
   unsigned int uiP5;
}  PACKED UsbDefaultPacket_t;


typedef struct
{
   unsigned char cSync[2];
   unsigned int uiSequenceNumber;
   unsigned short usPacketID;
   unsigned int uiUnusedDataLength;
   unsigned int uiMachineType;
   unsigned int uiSoftwareVersion;
   unsigned int uiIsBootCode;
   unsigned int uiRevisionNumber;
   unsigned int uiSampleEnabled;

}  PACKED UsbHello_t;

//******************************************************************************
//******************************************************************************
//******************************************************************************

void showDefaultPacket(UsbDefaultPacket_t* aP);

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace