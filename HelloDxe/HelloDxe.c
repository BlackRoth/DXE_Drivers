#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Guid/EventGroup.h>

VOID
EFIAPI
OnReadyToBoot (
  IN EFI_EVENT  Event, //signalling input parameter
  IN VOID       *Context //arbitrary data when creating an event, but doesnt require a signature
  )
{
  Print (L"Hello, EDK2 World! (post console-connect)\n");
  DEBUG ((DEBUG_INFO, "HelloWorldDxe: printed at ReadyToBoot\n")); //debugs to the log file
  gBS->CloseEvent (Event); //closes event from firing again
}

EFI_STATUS
EFIAPI
HelloWorldEntryPoint (
  IN EFI_HANDLE       ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
  )
{
  EFI_EVENT  Event;

  DEBUG ((DEBUG_INFO, "HelloWorldDxe: driver loaded\n")); //debug line sent to the log file to check if the driver executed properly

  gBS->CreateEventEx (
         EVT_NOTIFY_SIGNAL, //notify when event is fired
         TPL_CALLBACK, //task priority level set as a standard
         OnReadyToBoot, //function above
         NULL,
         &gEfiEventReadyToBootGuid, //to execute the driver before attempting to boot the OS
         &Event //output parameter used to close event
         );

  return EFI_SUCCESS;
}
