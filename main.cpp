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

}
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

    status = FltRegisterFilter(DriverObject,
                               &FilterRegistration,
                               &NullFilterData.FilterHandle);

    status = FltStartFiltering( NullFilterData.FilterHandle)

}


