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

