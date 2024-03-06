#include <fltKernel.l>
#include <dontuse.h>
#include <suppress.h>


/**
*  A structure for the filter handle
*/

typedef struct _NULL_FILTER_DATA{

    PFLT_FILTER FilterHandle;
} NULL_FILTER_DATA, *PNULL_FILTER_DATA;


/**
* FilterRegistration provides information about the minifilter to the filter manager
* Specifies the callback functions for the IRP packet types
*/

CONST FLT_REGISTRATION FilterRegistration = {
    sizeof(FLT_REGISTRATION),      //  Size
    FLT_REGISTRATION_VERSION,      //  Version
    0,                             //  Flags
    NULL,                          //  Context registration
    callbacks,                   //  Operation callbacks
    InstanceFilterUnloadCallback,  //  FilterUnload
    InstanceSetupCallback,         //  InstanceSetup
    InstanceQueryTeardownCallback, //  InstanceQueryTeardown
    NULL,                          //  InstanceTeardownStart
    NULL,                          //  InstanceTeardownComplete
    NULL,                          //  GenerateFileName
    NULL,                          //  GenerateDestinationFileName
    NULL                           //  NormalizeNameComponent
}


/**
* Specify the callback functions for IRP case
*
* For the IRP packer IRP_MJ_CREATE we specify the PreOperationCreate
*/

CONST FLT_OPERATION_REGISTRATION callbacks[] =
{
    {
        IRP_MJ_CREATE,
        0,
        PreOperationCreate,
        0
    },
  
    { IRP_MJ_OPERATION_END }
};


NULL_FILTER_DATA NullFilterData;

NTSTATUS
DriverEntry (
    _In_ PDRIVER_OBJECT DriverObjectl
    _In_ PUNICODE_STRING RegistryPath    
)


DRIVER_INITIALIZE DriverEntry;


/*!
* Entry point of the program
* 
* Invoke two function:
* 1.  FltRegisterFilter: to register filter handler and  
* 2.  FltStartFiltering: 
*
*
* @param[in] DriverObject pointer to driver object created by the system
* @param[in] RegistryPath unicode string to locate parameter
* @param[out] STATUS_SUCCESS success code of the operation  
*/

NTSTATUS
DriverEntry (
    _In_ PDRIVER_OBJECT DriverObject,
    _In_ PUNICODE_STRING RegistryPath
)
{
    NTSTATUS status;

    UNREFERENCED_PARAMETER( RegistryPath );

    //
    // Register minifilter
    //

    status = FltRegisterFilter(DriverObject,
                               &FilterRegistration,
                               &NullFilterData.FilterHandle);

    //
    // Start minifilter
    //
    
    status = FltStartFiltering( NullFilterData.FilterHandle)

}


