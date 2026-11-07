#ifndef GRIMACE_SDK_OLEAUTO_H
#define GRIMACE_SDK_OLEAUTO_H

#include <grimace/sdk/oaidl.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates a BSTR from a one-dimensional byte SAFEARRAY.
 *
 * @param psa Byte vector to convert.
 * @param pbstr Receives the allocated BSTR.
 * @return S_OK, E_OUTOFMEMORY, E_INVALIDARG or DISP_E_TYPEMISMATCH.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT BstrFromVector(SAFEARRAY *psa, BSTR *pbstr);
/**
 * Creates a generic COM error-information object.
 *
 * Use ICreateErrorInfo to fill it in, then pass it to SetErrorInfo.
 *
 * @param pperrinfo Receives the ICreateErrorInfo interface pointer.
 * @return S_OK, or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT CreateErrorInfo(ICreateErrorInfo **pperrinfo);
/**
 * Creates a type library and returns its ICreateTypeLib2 interface.
 *
 * Windows CE does not implement ICreateTypeLib2::SaveAllChanges.
 *
 * @param syskind Target system kind.
 * @param szFile File path for the type library.
 * @param ppctlib Receives the ICreateTypeLib2 interface pointer.
 * @return S_OK, or an error code.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT CreateTypeLib2(SYSKIND syskind, LPCOLESTR szFile, ICreateTypeLib2 **ppctlib);
/**
 * Calls a function through a vtable entry for a customized IDispatch::Invoke.
 *
 * The helper provides machine-independent calling conventions for the
 * custom invocation.
 *
 * @param pvInstance Instance whose vtable contains the function.
 * @param oVft Vtable offset of the function.
 * @param cc Calling convention.
 * @param vtReturn Return VARTYPE.
 * @param cActuals Number of arguments.
 * @param prgvt VARTYPE of each argument.
 * @param prgpvarg Pointers to the argument VARIANTARG values.
 * @param pvargResult Receives the result VARIANT.
 * @return HRESULT indicating success or failure.
 *
 * @note Windows CE 3.0 and later.
 */
HRESULT DispCallFunc(void *pvInstance, ULONG oVft, CALLCONV cc, VARTYPE vtReturn, UINT cActuals, VARTYPE *prgvt, VARIANTARG **prgpvarg, VARIANT *pvargResult);
/**
 * Maps member and parameter names to DISPIDs using interface type information.
 *
 * When cNames is greater than one, the first name is the member and the
 * remaining names are its parameters.
 *
 * @param ptinfo Type information for the interface and locale.
 * @param rgszNames Names to resolve.
 * @param cNames Number of names.
 * @param rgdispid Receives one DISPID per name.
 * @return S_OK, DISP_E_UNKNOWNNAME, E_INVALIDARG, or a type-info error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT DispGetIDsOfNames(ITypeInfo *ptinfo, OLECHAR **rgszNames, UINT cNames, DISPID *rgdispid);
/**
 * Gets an invocation argument and coerces it to the requested VARTYPE.
 *
 * Position zero selects the last positional argument. Named and
 * positional arguments cannot be accessed interchangeably.
 *
 * @param pdispparams Parameters passed to IDispatch::Invoke.
 * @param position Argument position, counted from the end of rgvarg.
 * @param vtTarg Target VARTYPE.
 * @param pvarResult Receives the converted value; initialize as a valid VARIANT.
 * @param puArgErr Receives the argument index on DISP_E_TYPEMISMATCH.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_PARAMNOTFOUND, or another
 *         conversion error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT DispGetParam(DISPPARAMS *pdispparams, UINT position, VARTYPE vtTarg, VARIANT *pvarResult, UINT *puArgErr);
/**
 * Invokes an interface member using its type information.
 *
 * The helper maps and coerces DISPPARAMS arguments before calling the
 * member. rgvarg stores arguments in reverse order.
 *
 * @param _this Object implementing the described IDispatch interface.
 * @param ptinfo Type information for the interface.
 * @param dispidMember Member DISPID to invoke.
 * @param wFlags DISPATCH_METHOD, DISPATCH_PROPERTYGET, DISPATCH_PROPERTYPUT
 *        or DISPATCH_PROPERTYPUTREF.
 * @param pparams Invocation arguments and named DISPIDs.
 * @param pvarResult Receives the result, or NULL when unused.
 * @param pexcepinfo Receives exception information for DISP_E_EXCEPTION.
 * @param puArgErr Receives the index of an invalid argument.
 * @return S_OK, DISP_E_MEMBERNOTFOUND, DISP_E_TYPEMISMATCH, or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT DispInvoke(void *_this, ITypeInfo *ptinfo, DISPID dispidMember, WORD wFlags, DISPPARAMS *pparams, VARIANT *pvarResult, EXCEPINFO *pexcepinfo, UINT *puArgErr);
/**
 * Retrieves and clears the current logical thread's COM error information.
 *
 * The returned IErrorInfo reference belongs to the caller.
 *
 * @param dwReserved Reserved; set to zero.
 * @param pperrinfo Receives the IErrorInfo pointer.
 * @return S_OK if error information was present, S_FALSE otherwise.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT GetErrorInfo(ULONG dwReserved, IErrorInfo **pperrinfo);
/**
 * Loads a registered type library by GUID, version and locale.
 *
 * Only typelib2 libraries are supported. If an exact version is absent,
 * the loader may use a higher minor version with the same major version.
 *
 * @param rguid Type library GUID.
 * @param wVerMajor Requested major version.
 * @param wVerMinor Requested minor version.
 * @param lcid Locale identifier.
 * @param pptlib Receives the ITypeLib interface pointer.
 * @return S_OK, TYPE_E_CANTLOADLIBRARY, or a registry/storage error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT LoadRegTypeLib(const GUID *const rguid, WORD wVerMajor, WORD wVerMinor, LCID lcid, ITypeLib **pptlib);
/**
 * Loads a typelib2 library from a DLL or executable resource.
 *
 * Windows CE does not load standalone or foreign type-library files.
 * Append a resource index to the file path to select a resource. When no
 * path is specified, this function may register the library as a
 * backward-compatibility behavior.
 *
 * @param szFile DLL or executable path, optionally with a resource index.
 * @param pptlib Receives the ITypeLib interface pointer.
 * @return S_OK, TYPE_E_CANTLOADLIBRARY, or a type-library error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT LoadTypeLib(const OLECHAR *szFile, ITypeLib **pptlib);
/**
 * Registers a type library and its Automation-compatible interfaces.
 *
 * This does not register its coclasses.
 *
 * @param ptlib Type library to register.
 * @param szFullPath Fully qualified path to the library.
 * @param szHelpDir Help-file directory, or NULL.
 * @return S_OK, TYPE_E_REGISTRYACCESS, or a registration error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT RegisterTypeLib(ITypeLib *ptlib, OLECHAR *szFullPath, OLECHAR *szHelpDir);
/**
 * Locks a SAFEARRAY and returns a pointer to its data block.
 *
 * Call SafeArrayUnaccessData when finished; the pointer is valid only
 * while the array remains locked.
 *
 * @param psa SAFEARRAY descriptor.
 * @param ppvData Receives the data pointer.
 * @return S_OK, E_INVALIDARG or E_UNEXPECTED.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayAccessData(SAFEARRAY *psa, void **ppvData);
/**
 * Allocates element storage for a SAFEARRAY descriptor.
 *
 * @param psa Descriptor created by SafeArrayAllocDescriptor.
 * @return S_OK, E_INVALIDARG or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayAllocData(SAFEARRAY *psa);
/**
 * Allocates a SAFEARRAY descriptor without allocating element data.
 *
 * Set the element size and call SafeArrayAllocData to allocate its data.
 *
 * @param cDims Number of dimensions.
 * @param ppsaOut Receives the descriptor pointer.
 * @return S_OK, E_INVALIDARG or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayAllocDescriptor(UINT cDims, SAFEARRAY **ppsaOut);
/**
 * Creates a deep copy of a SAFEARRAY.
 *
 * String and VARIANT elements are copied using their Automation
 * operations; object references are AddRef'd.
 *
 * @param psa Array to copy.
 * @param ppsaOut Receives the copied array.
 * @return S_OK, E_INVALIDARG or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayCopy(SAFEARRAY *psa, SAFEARRAY **ppsaOut);
/**
 * Copies source elements into an existing SAFEARRAY descriptor.
 *
 * Releases existing target elements first. The caller supplies the target
 * array; this function does not allocate or resize it.
 *
 * @param psaSource Source array.
 * @param psaTarget Existing target array.
 * @return S_OK, E_INVALIDARG or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayCopyData(SAFEARRAY *psaSource, SAFEARRAY *psaTarget);
/**
 * Creates a SAFEARRAY with the specified element type and bounds.
 *
 * VT_ARRAY, VT_BYREF, VT_EMPTY and VT_NULL are invalid base types. Destroy
 * the array with SafeArrayDestroy.
 *
 * @param vt Element VARTYPE.
 * @param cDims Number of dimensions.
 * @param rgsabound Bounds for each dimension.
 * @return SAFEARRAY descriptor, or NULL on failure.
 *
 * @note Windows CE 2.0 and later.
 */
SAFEARRAY * SafeArrayCreate(VARTYPE vt, UINT cDims, SAFEARRAYBOUND *rgsabound);
/**
 * Creates a fixed-size, one-dimensional SAFEARRAY.
 *
 * The lower bound may be negative. Destroy the array with
 * SafeArrayDestroy.
 *
 * @param vt Element VARTYPE.
 * @param lLbound Lower index bound.
 * @param cElements Number of elements.
 * @return SAFEARRAY descriptor, or NULL on failure.
 *
 * @note Windows CE 2.0 and later.
 */
SAFEARRAY * SafeArrayCreateVector(VARTYPE vt, LONG lLbound, ULONG cElements);
/**
 * Destroys a SAFEARRAY and releases its elements.
 *
 * Object elements are released. The array must not be locked.
 *
 * @param psa Array to destroy.
 * @return S_OK, DISP_E_ARRAYISLOCKED or E_INVALIDARG.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayDestroy(SAFEARRAY *psa);
/**
 * Releases all element data while preserving the SAFEARRAY descriptor.
 *
 * Object elements are released. The array must not be locked.
 *
 * @param psa Array whose data to destroy.
 * @return S_OK, DISP_E_ARRAYISLOCKED or E_INVALIDARG.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayDestroyData(SAFEARRAY *psa);
/**
 * Destroys a SAFEARRAY descriptor without releasing its element data.
 *
 * Call SafeArrayDestroyData first when the data must also be freed.
 *
 * @param psa Descriptor to destroy.
 * @return S_OK, DISP_E_ARRAYISLOCKED or E_INVALIDARG.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayDestroyDescriptor(SAFEARRAY *psa);
/**
 * Returns the number of dimensions in a SAFEARRAY.
 *
 * @param psa SAFEARRAY descriptor.
 * @return Number of dimensions.
 *
 * @note Windows CE 2.0 and later.
 */
UINT SafeArrayGetDim(SAFEARRAY *psa);
/**
 * Copies one SAFEARRAY element to caller-provided storage.
 *
 * Indices are ordered from the rightmost dimension at index zero. The
 * function handles BSTR, object and VARIANT element copying.
 *
 * @param psa Array to read.
 * @param rgIndices One index per dimension.
 * @param pv Receives an element of the correct size and type.
 * @return S_OK, DISP_E_BADINDEX or E_INVALIDARG.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayGetElement(SAFEARRAY *psa, LONG *rgIndices, void *pv);
/**
 * Returns the size in bytes of each SAFEARRAY element.
 *
 * @param psa SAFEARRAY descriptor.
 * @return Element size in bytes.
 *
 * @note Windows CE 2.0 and later.
 */
UINT SafeArrayGetElemsize(SAFEARRAY *psa);
/**
 * Retrieves the lower index bound of one SAFEARRAY dimension.
 *
 * @param psa SAFEARRAY descriptor.
 * @param nDim Dimension to query.
 * @param plLbound Receives the lower bound.
 * @return S_OK, DISP_E_BADINDEX or E_INVALIDARG.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayGetLBound(SAFEARRAY *psa, UINT nDim, LONG *plLbound);
/**
 * Retrieves the upper index bound of one SAFEARRAY dimension.
 *
 * @param psa SAFEARRAY descriptor.
 * @param nDim Dimension to query.
 * @param plUbound Receives the upper bound.
 * @return S_OK, DISP_E_BADINDEX or E_INVALIDARG.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayGetUBound(SAFEARRAY *psa, UINT nDim, LONG *plUbound);
/**
 * Increments the SAFEARRAY lock count and exposes its data through pvData.
 *
 * Lock calls may be nested; balance each with SafeArrayUnlock. A locked
 * array cannot be destroyed.
 *
 * @param psa SAFEARRAY descriptor.
 * @return S_OK, E_INVALIDARG or E_UNEXPECTED.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayLock(SAFEARRAY *psa);
/**
 * Returns a pointer to a SAFEARRAY element at the supplied indices.
 *
 * Lock the array before calling; unlock it after using the pointer.
 *
 * @param psa SAFEARRAY descriptor.
 * @param rgIndices One index per dimension.
 * @param ppvData Receives the element pointer.
 * @return S_OK, DISP_E_BADINDEX or E_INVALIDARG.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayPtrOfIndex(SAFEARRAY *psa, LONG *rgIndices, void **ppvData);
/**
 * Copies a value into one SAFEARRAY element.
 *
 * Indices are ordered from the rightmost dimension at index zero. BSTR,
 * object and VARIANT elements are copied and any existing value is cleared.
 *
 * @param psa Array to update.
 * @param rgIndices One index per dimension.
 * @param pv Value to copy; pointer-valued VARTYPEs are passed directly.
 * @return S_OK, DISP_E_BADINDEX, E_INVALIDARG or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayPutElement(SAFEARRAY *psa, LONG *rgIndices, void *pv);
/**
 * Changes the bound of the rightmost SAFEARRAY dimension.
 *
 * Shrinking releases removed elements; growing initializes new ones. The
 * array must not be locked.
 *
 * @param psa Array to resize.
 * @param psaboundNew New bound for the rightmost dimension.
 * @return S_OK, DISP_E_ARRAYISLOCKED or E_INVALIDARG.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayRedim(SAFEARRAY *psa, SAFEARRAYBOUND *psaboundNew);
/**
 * Unlocks an array previously accessed with SafeArrayAccessData.
 *
 * The data pointer returned by SafeArrayAccessData is invalid afterward.
 *
 * @param psa SAFEARRAY descriptor.
 * @return S_OK, E_INVALIDARG or E_UNEXPECTED.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayUnaccessData(SAFEARRAY *psa);
/**
 * Decrements the SAFEARRAY lock count.
 *
 * Call after finishing direct data access; balance each SafeArrayLock.
 *
 * @param psa SAFEARRAY descriptor.
 * @return S_OK, E_INVALIDARG or E_UNEXPECTED.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SafeArrayUnlock(SAFEARRAY *psa);
/**
 * Sets the current thread's error information object.
 *
 * The previous object is released. Set dwReserved to zero.
 *
 * @param dwReserved Reserved; set to zero.
 * @param perrinfo Error information object to associate with the thread.
 * @return S_OK on success.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT SetErrorInfo(ULONG dwReserved, IErrorInfo *perrinfo);
/**
 * Allocates a BSTR and copies a null-terminated Unicode string.
 *
 * Free the result with SysFreeString. NULL input returns NULL.
 *
 * @param sz Unicode string to copy.
 * @return Allocated BSTR, or NULL on failure.
 *
 * @note Windows CE 2.0 and later.
 */
BSTR SysAllocString(const OLECHAR *sz);
/**
 * Allocates a BSTR with a specified byte length without character conversion.
 *
 * Use for binary data only when the BSTR will not cross an ANSI/Unicode
 * translation boundary. Prefer SAFEARRAY(VT_UI1) for binary data.
 *
 * @param psz Bytes to copy, or NULL for uninitialized storage.
 * @param len Number of bytes to allocate and copy.
 * @return Allocated BSTR, or NULL on failure.
 *
 * @note Windows CE 2.0 and later.
 */
BSTR SysAllocStringByteLen(LPCSTR psz, UINT len);
/**
 * Allocates a BSTR with a specified character length.
 *
 * Embedded NULs are preserved. If pch is NULL, the allocated characters
 * are uninitialized. Free the result with SysFreeString.
 *
 * @param pch Characters to copy, or NULL for uninitialized storage.
 * @param cch Number of characters.
 * @return Allocated BSTR, or NULL on failure.
 *
 * @note Windows CE 2.0 and later.
 */
BSTR SysAllocStringLen(const OLECHAR *pch, UINT cch);
/**
 * Frees a BSTR allocated by an Automation string allocator.
 *
 * Passing NULL has no effect.
 *
 * @param bstr BSTR to free, or NULL.
 *
 * @note Windows CE 2.0 and later.
 */
void SysFreeString(BSTR bstr);
/**
 * Reallocates a BSTR from a null-terminated Unicode string.
 *
 * The old BSTR is freed and pbstr is updated to the new string.
 *
 * @param pbstr Address of the BSTR to replace.
 * @param sz Unicode string to copy.
 * @return Nonzero on success, zero if allocation fails.
 *
 * @note Windows CE 2.0 and later.
 */
INT SysReAllocString(BSTR *pbstr, const OLECHAR *sz);
/**
 * Reallocates a BSTR to contain a specified number of characters.
 *
 * Embedded NULs are preserved. The old BSTR is freed and pbstr is updated.
 *
 * @param pbstr Address of the BSTR to replace.
 * @param pch Characters to copy, or NULL for uninitialized storage.
 * @param cch Number of characters.
 * @return Nonzero on success, zero if allocation fails.
 *
 * @note Windows CE 2.0 and later.
 */
INT SysReAllocStringLen(BSTR *pbstr, const OLECHAR *pch, UINT cch);
/**
 * Returns the byte length stored with a BSTR, excluding its terminator.
 *
 * The length can include embedded NUL bytes and may differ from a
 * null-terminated string length.
 *
 * @param bstr BSTR to measure.
 * @return Stored length in bytes.
 *
 * @note Windows CE 2.0 and later.
 */
UINT SysStringByteLen(BSTR bstr);
/**
 * Returns the character length stored with a BSTR, excluding its terminator.
 *
 * The length can include embedded NUL characters.
 *
 * @param bstr BSTR to measure.
 * @return Stored length in characters.
 *
 * @note Windows CE 2.0 and later.
 */
UINT SysStringLen(BSTR bstr);
/**
 * Converts SYSTEMTIME to an Automation DATE value.
 *
 * DATE is a double whose integral portion counts days and fractional
 * portion represents time of day.
 *
 * @param lpSystemTime Date and time to convert.
 * @param pvtime Receives the Automation DATE.
 * @return Nonzero on success, zero on failure.
 *
 * @note Windows CE 2.0 and later.
 */
INT SystemTimeToVariantTime(LPSYSTEMTIME lpSystemTime, DOUBLE *pvtime);
/**
 * Converts CY to VARIANT_BOOL.
 *
 * @param cyIn Currency value to convert.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromCy(CY cyIn, VARIANT_BOOL *pboolOut);
/**
 * Converts DATE to VARIANT_BOOL.
 *
 * @param dateIn Automation DATE value.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromDate(DATE dateIn, VARIANT_BOOL *pboolOut);
/**
 * Converts DECIMAL to VARIANT_BOOL.
 *
 * @param pdecIn Decimal value to convert.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromDec(DECIMAL *pdecIn, VARIANT_BOOL *pboolOut);
/**
 * Converts IDispatch to VARIANT_BOOL using the specified locale.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier for conversion.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromDisp(IDispatch *pdispIn, LCID lcid, VARIANT_BOOL *pboolOut);
/**
 * Converts a signed byte to VARIANT_BOOL.
 *
 * @param cIn Value to convert.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromI1(CHAR cIn, VARIANT_BOOL *pboolOut);
/**
 * Converts a signed 16-bit integer to VARIANT_BOOL.
 *
 * @param sIn Value to convert.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromI2(SHORT sIn, VARIANT_BOOL *pboolOut);
/**
 * Converts a signed 32-bit integer to VARIANT_BOOL.
 *
 * @param lIn Value to convert.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromI4(LONG lIn, VARIANT_BOOL *pboolOut);
/**
 * Converts a single-precision float to VARIANT_BOOL.
 *
 * @param fltIn Value to convert.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromR4(FLOAT fltIn, VARIANT_BOOL *pboolOut);
/**
 * Converts a double-precision float to VARIANT_BOOL.
 *
 * @param dblIn Value to convert.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromR8(DOUBLE dblIn, VARIANT_BOOL *pboolOut);
/**
 * Converts a locale-formatted string to VARIANT_BOOL.
 *
 * @param strIn String value to parse.
 * @param lcid Locale identifier.
 * @param dwFlags Locale and date-conversion flags.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, VARIANT_BOOL *pboolOut);
/**
 * Converts an unsigned byte to VARIANT_BOOL.
 *
 * @param bIn Value to convert.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromUI1(BYTE bIn, VARIANT_BOOL *pboolOut);
/**
 * Converts an unsigned 16-bit integer to VARIANT_BOOL.
 *
 * @param uiIn Value to convert.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromUI2(USHORT uiIn, VARIANT_BOOL *pboolOut);
/**
 * Converts an unsigned 32-bit integer to VARIANT_BOOL.
 *
 * @param ulIn Value to convert.
 * @param pboolOut Receives VARIANT_TRUE or VARIANT_FALSE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBoolFromUI4(ULONG ulIn, VARIANT_BOOL *pboolOut);
/**
 * Formats VARIANT_BOOL as a locale-aware BSTR.
 *
 * The caller owns the allocated BSTR and must free it with SysFreeString.
 *
 * @param boolIn Boolean value to format.
 * @param lcid Locale identifier.
 * @param dwFlags Conversion and locale flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromBool(VARIANT_BOOL boolIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Formats CY as a locale-aware BSTR.
 *
 * The caller owns the allocated BSTR and must free it with SysFreeString.
 *
 * @param cyIn Currency value to format.
 * @param lcid Locale identifier.
 * @param dwFlags Conversion and locale flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromCy(CY cyIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Formats an Automation DATE as a locale-aware BSTR.
 *
 * VAR_DATEVALUEONLY or VAR_TIMEVALUEONLY can omit the time or date.
 * Calendar and locale flags can control formatting. Free the returned
 * BSTR with SysFreeString.
 *
 * @param dateIn Automation DATE value.
 * @param lcid Locale identifier.
 * @param dwFlags Date, calendar and locale formatting flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromDate(DATE dateIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Formats DECIMAL as a locale-aware BSTR.
 *
 * Free the returned BSTR with SysFreeString.
 *
 * @param pdecIn Decimal value to format.
 * @param lcid Locale identifier.
 * @param dwFlags Conversion and locale flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromDec(DECIMAL *pdecIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Converts IDispatch to a locale-aware BSTR.
 *
 * Free the returned BSTR with SysFreeString.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier.
 * @param dwFlags Conversion and locale flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromDisp(IDispatch *pdispIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Formats a signed byte as a locale-aware BSTR.
 *
 * Free the returned BSTR with SysFreeString.
 *
 * @param cIn Value to format.
 * @param lcid Locale identifier.
 * @param dwFlags Conversion and locale flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromI1(CHAR cIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Formats a signed 16-bit integer as a locale-aware BSTR.
 *
 * Free the returned BSTR with SysFreeString.
 *
 * @param iVal Value to format.
 * @param lcid Locale identifier.
 * @param dwFlags Conversion and locale flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromI2(SHORT iVal, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Formats a signed 32-bit integer as a locale-aware BSTR.
 *
 * Free the returned BSTR with SysFreeString.
 *
 * @param lIn Value to format.
 * @param lcid Locale identifier.
 * @param dwFlags Conversion and locale flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromI4(LONG lIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Formats a single-precision float as a locale-aware BSTR.
 *
 * Free the returned BSTR with SysFreeString.
 *
 * @param fltIn Value to format.
 * @param lcid Locale identifier.
 * @param dwFlags Conversion and locale flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromR4(FLOAT fltIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Formats a double-precision float as a locale-aware BSTR.
 *
 * Free the returned BSTR with SysFreeString.
 *
 * @param dblIn Value to format.
 * @param lcid Locale identifier.
 * @param dwFlags Conversion and locale flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromR8(DOUBLE dblIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Formats an unsigned byte as a locale-aware BSTR.
 *
 * Free the returned BSTR with SysFreeString.
 *
 * @param bVal Value to format.
 * @param lcid Locale identifier.
 * @param dwFlags Conversion and locale flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromUI1(BYTE bVal, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Formats an unsigned 16-bit integer as a locale-aware BSTR.
 *
 * Free the returned BSTR with SysFreeString.
 *
 * @param uiIn Value to format.
 * @param lcid Locale identifier.
 * @param dwFlags Conversion and locale flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromUI2(USHORT uiIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Formats an unsigned 32-bit integer as a locale-aware BSTR.
 *
 * Free the returned BSTR with SysFreeString.
 *
 * @param ulIn Value to format.
 * @param lcid Locale identifier.
 * @param dwFlags Conversion and locale flags.
 * @param pbstrOut Receives the allocated BSTR.
 * @return S_OK, DISP_E_TYPEMISMATCH, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarBstrFromUI4(ULONG ulIn, LCID lcid, ULONG dwFlags, BSTR *pbstrOut);
/**
 * Converts VARIANT_BOOL to CY.
 *
 * @param boolIn Boolean value to convert.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromBool(VARIANT_BOOL boolIn, CY *pcyOut);
/**
 * Converts Automation DATE to CY.
 *
 * @param dateIn DATE value to convert.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromDate(DATE dateIn, CY *pcyOut);
/**
 * Converts DECIMAL to CY.
 *
 * @param pdecIn Decimal value to convert.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromDec(DECIMAL *pdecIn, CY *pcyOut);
/**
 * Converts IDispatch to CY using the specified locale.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromDisp(IDispatch *pdispIn, LCID lcid, CY *pcyOut);
/**
 * Converts a signed byte to CY.
 *
 * @param cIn Value to convert.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromI1(CHAR cIn, CY *pcyOut);
/**
 * Converts a signed 16-bit integer to CY.
 *
 * @param sIn Value to convert.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromI2(SHORT sIn, CY *pcyOut);
/**
 * Converts a signed 32-bit integer to CY.
 *
 * @param lIn Value to convert.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromI4(LONG lIn, CY *pcyOut);
/**
 * Converts a single-precision float to CY.
 *
 * @param fltIn Value to convert.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromR4(FLOAT fltIn, CY *pcyOut);
/**
 * Converts a double-precision float to CY.
 *
 * @param dblIn Value to convert.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromR8(DOUBLE dblIn, CY *pcyOut);
/**
 * Parses a locale-formatted string as CY.
 *
 * @param strIn String to parse.
 * @param lcid Locale identifier.
 * @param dwFlags Locale and date-conversion flags.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, CY *pcyOut);
/**
 * Converts an unsigned byte to CY.
 *
 * @param bIn Value to convert.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromUI1(BYTE bIn, CY *pcyOut);
/**
 * Converts an unsigned 16-bit integer to CY.
 *
 * @param uiIn Value to convert.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromUI2(USHORT uiIn, CY *pcyOut);
/**
 * Converts an unsigned 32-bit integer to CY.
 *
 * @param ulIn Value to convert.
 * @param pcyOut Receives the currency value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarCyFromUI4(ULONG ulIn, CY *pcyOut);
/**
 * Converts VARIANT_BOOL to an Automation DATE.
 *
 * @param boolIn Boolean value to convert.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromBool(VARIANT_BOOL boolIn, DATE *pdateOut);
/**
 * Converts CY to an Automation DATE.
 *
 * @param cyIn Currency value to convert.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromCy(CY cyIn, DATE *pdateOut);
/**
 * Converts DECIMAL to an Automation DATE.
 *
 * @param pdecIn Decimal value to convert.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromDec(DECIMAL *pdecIn, DATE *pdateOut);
/**
 * Converts IDispatch to an Automation DATE using the specified locale.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromDisp(IDispatch *pdispIn, LCID lcid, DATE *pdateOut);
/**
 * Converts a signed byte to an Automation DATE.
 *
 * @param cIn Value to convert.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromI1(CHAR cIn, DATE *pdateOut);
/**
 * Converts a signed 16-bit integer to an Automation DATE.
 *
 * @param sIn Value to convert.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromI2(SHORT sIn, DATE *pdateOut);
/**
 * Converts a signed 32-bit integer to an Automation DATE.
 *
 * @param lIn Value to convert.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromI4(LONG lIn, DATE *pdateOut);
/**
 * Converts a single-precision float to an Automation DATE.
 *
 * @param fltIn Value to convert.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromR4(FLOAT fltIn, DATE *pdateOut);
/**
 * Converts a double-precision float to an Automation DATE.
 *
 * @param dblIn Value to convert.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromR8(DOUBLE dblIn, DATE *pdateOut);
/**
 * Parses a locale-formatted string as an Automation DATE.
 *
 * VAR_DATEVALUEONLY and VAR_TIMEVALUEONLY control which portion is
 * converted; dwFlags also accepts calendar and locale options.
 *
 * @param strIn String to parse.
 * @param lcid Locale identifier.
 * @param dwFlags Locale, calendar and date/time conversion flags.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, DATE *pdateOut);
/**
 * Converts an unsigned byte to an Automation DATE.
 *
 * @param bIn Value to convert.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromUI1(BYTE bIn, DATE *pdateOut);
/**
 * Converts an unsigned 16-bit integer to an Automation DATE.
 *
 * @param uiIn Value to convert.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromUI2(USHORT uiIn, DATE *pdateOut);
/**
 * Converts an unsigned 32-bit integer to an Automation DATE.
 *
 * @param ulIn Value to convert.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromUI4(ULONG ulIn, DATE *pdateOut);
typedef struct {
    SYSTEMTIME st;
    USHORT wDayOfYear;
} UDATE;

/**
 * Converts a UDATE structure to a packed Automation DATE.
 *
 * @param pudateIn Unpacked date to convert.
 * @param dwFlags Conversion flags; receives VAR_VALIDDATE when valid.
 * @param pdateOut Receives the DATE value.
 * @return S_OK, E_OUTOFMEMORY or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDateFromUdate(UDATE *pudateIn, ULONG dwFlags, DATE *pdateOut);
/**
 * Converts VARIANT_BOOL to DECIMAL.
 *
 * @param boolIn Boolean value to convert.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromBool(VARIANT_BOOL boolIn, DECIMAL *pdecOut);
/**
 * Converts CY to DECIMAL.
 *
 * @param cyIn Currency value to convert.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromCy(CY cyIn, DECIMAL *pdecOut);
/**
 * Converts an Automation DATE to DECIMAL.
 *
 * @param dateIn DATE value to convert.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromDate(DATE dateIn, DECIMAL *pdecOut);
/**
 * Converts IDispatch to DECIMAL using the specified locale.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromDisp(IDispatch *pdispIn, LCID lcid, DECIMAL *pdecOut);
/**
 * Converts a signed byte to DECIMAL.
 *
 * @param cIn Value to convert.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromI1(CHAR cIn, DECIMAL *pdecOut);
/**
 * Converts a signed 16-bit integer to DECIMAL.
 *
 * @param sIn Value to convert.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromI2(SHORT uiIn, DECIMAL *pdecOut);
/**
 * Converts a signed 32-bit integer to DECIMAL.
 *
 * @param lIn Value to convert.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromI4(LONG lIn, DECIMAL *pdecOut);
/**
 * Converts a single-precision float to DECIMAL.
 *
 * @param fltIn Value to convert.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromR4(FLOAT fltIn, DECIMAL *pdecOut);
/**
 * Converts a double-precision float to DECIMAL.
 *
 * @param dblIn Value to convert.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromR8(DOUBLE dblIn, DECIMAL *pdecOut);
/**
 * Parses a locale-formatted string as DECIMAL.
 *
 * @param strIn String to parse.
 * @param lcid Locale identifier.
 * @param dwFlags Locale conversion flags.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, DECIMAL *pdecOut);
/**
 * Converts an unsigned byte to DECIMAL.
 *
 * @param bIn Value to convert.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromUI1(BYTE bIn, DECIMAL *pdecOut);
/**
 * Converts an unsigned 16-bit integer to DECIMAL.
 *
 * @param uiIn Value to convert.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromUI2(USHORT uiIn, DECIMAL *pdecOut);
/**
 * Converts an unsigned 32-bit integer to DECIMAL.
 *
 * @param ulIn Value to convert.
 * @param pdecOut Receives the DECIMAL value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarDecFromUI4(ULONG ulIn, DECIMAL *pdecOut);
/**
 * Converts VARIANT_BOOL to a signed byte.
 *
 * @param boolIn Boolean value to convert.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromBool(VARIANT_BOOL boolIn, CHAR *pcOut);
/**
 * Converts CY to a signed byte.
 *
 * @param cyIn Currency value to convert.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromCy(CY cyIn, CHAR *pcOut);
/**
 * Converts an Automation DATE to a signed byte.
 *
 * @param dateIn DATE value to convert.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromDate(DATE dateIn, CHAR *pcOut);
/**
 * Converts DECIMAL to a signed byte.
 *
 * @param pdecIn Decimal value to convert.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromDec(DECIMAL *pdecIn, CHAR *pcOut);
/**
 * Converts IDispatch to a signed byte using the specified locale.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromDisp(IDispatch *pdispIn, LCID lcid, CHAR *pcOut);
/**
 * Converts a signed 16-bit integer to a signed byte.
 *
 * @param uiIn Value to convert.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromI2(SHORT uiIn, CHAR *pcOut);
/**
 * Converts a signed 32-bit integer to a signed byte.
 *
 * @param lIn Value to convert.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromI4(LONG lIn, CHAR *pcOut);
/**
 * Converts a single-precision float to a signed byte.
 *
 * @param fltIn Value to convert.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromR4(FLOAT fltIn, CHAR *pcOut);
/**
 * Converts a double-precision float to a signed byte.
 *
 * @param dblIn Value to convert.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromR8(DOUBLE dblIn, CHAR *pcOut);
/**
 * Parses a locale-formatted string as a signed byte.
 *
 * @param strIn String to parse.
 * @param lcid Locale identifier.
 * @param dwFlags Locale conversion flags.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, CHAR *pcOut);
/**
 * Converts an unsigned byte to a signed byte.
 *
 * @param bIn Value to convert.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromUI1(BYTE bIn, CHAR *pcOut);
/**
 * Converts an unsigned 16-bit integer to a signed byte.
 *
 * @param uiIn Value to convert.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromUI2(USHORT uiIn, CHAR *pcOut);
/**
 * Converts an unsigned 32-bit integer to a signed byte.
 *
 * @param ulIn Value to convert.
 * @param pcOut Receives the signed byte.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI1FromUI4(ULONG ulIn, CHAR *pcOut);
/**
 * Converts VARIANT_BOOL to a signed 16-bit integer.
 *
 * @param boolIn Boolean value to convert.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromBool(VARIANT_BOOL boolIn, SHORT *psOut);
/**
 * Converts CY to a signed 16-bit integer.
 *
 * @param cyIn Currency value to convert.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromCy(CY cyIn, SHORT *psOut);
/**
 * Converts an Automation DATE to a signed 16-bit integer.
 *
 * @param dateIn DATE value to convert.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromDate(DATE dateIn, SHORT *psOut);
/**
 * Converts DECIMAL to a signed 16-bit integer.
 *
 * @param pdecIn Decimal value to convert.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromDec(DECIMAL *pdecIn, SHORT *psOut);
/**
 * Converts IDispatch to a signed 16-bit integer using the specified locale.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromDisp(IDispatch *pdispIn, LCID lcid, SHORT *psOut);
/**
 * Converts a signed byte to a signed 16-bit integer.
 *
 * @param cIn Value to convert.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromI1(CHAR cIn, SHORT *psOut);
/**
 * Converts a signed 32-bit integer to a signed 16-bit integer.
 *
 * @param lIn Value to convert.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromI4(LONG lIn, SHORT *psOut);
/**
 * Converts a single-precision float to a signed 16-bit integer.
 *
 * @param fltIn Value to convert.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromR4(FLOAT fltIn, SHORT *psOut);
/**
 * Converts a double-precision float to a signed 16-bit integer.
 *
 * @param dblIn Value to convert.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromR8(DOUBLE dblIn, SHORT *psOut);
/**
 * Parses a locale-formatted string as a signed 16-bit integer.
 *
 * @param strIn String to parse.
 * @param lcid Locale identifier.
 * @param dwFlags Locale and date-conversion flags.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, SHORT *psOut);
/**
 * Converts an unsigned byte to a signed 16-bit integer.
 *
 * @param bIn Value to convert.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromUI1(BYTE bIn, SHORT *psOut);
/**
 * Converts an unsigned 16-bit integer to a signed 16-bit integer.
 *
 * @param uiIn Value to convert.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromUI2(USHORT uiIn, SHORT *psOut);
/**
 * Converts an unsigned 32-bit integer to a signed 16-bit integer.
 *
 * @param ulIn Value to convert.
 * @param psOut Receives the SHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI2FromUI4(ULONG ulIn, SHORT *psOut);
/**
 * Converts VARIANT_BOOL to a signed 32-bit integer.
 *
 * @param boolIn Boolean value to convert.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromBool(VARIANT_BOOL boolIn, LONG *plOut);
/**
 * Converts CY to a signed 32-bit integer.
 *
 * @param cyIn Currency value to convert.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromCy(CY cyIn, LONG *plOut);
/**
 * Converts an Automation DATE to a signed 32-bit integer.
 *
 * @param dateIn DATE value to convert.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromDate(DATE dateIn, LONG *plOut);
/**
 * Converts DECIMAL to a signed 32-bit integer.
 *
 * @param pdecIn Decimal value to convert.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromDec(DECIMAL *pdecIn, LONG *plOut);
/**
 * Converts IDispatch to a signed 32-bit integer using the specified locale.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromDisp(IDispatch *pdispIn, LCID lcid, LONG *plOut);
/**
 * Converts a signed byte to a signed 32-bit integer.
 *
 * @param cIn Value to convert.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromI1(CHAR cIn, LONG *plOut);
/**
 * Converts a signed 16-bit integer to a signed 32-bit integer.
 *
 * @param sIn Value to convert.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromI2(SHORT sIn, LONG *plOut);
/**
 * Converts a single-precision float to a signed 32-bit integer.
 *
 * @param fltIn Value to convert.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromR4(FLOAT fltIn, LONG *plOut);
/**
 * Converts a double-precision float to a signed 32-bit integer.
 *
 * @param dblIn Value to convert.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromR8(DOUBLE dblIn, LONG *plOut);
/**
 * Parses a locale-formatted string as a signed 32-bit integer.
 *
 * @param strIn String to parse.
 * @param lcid Locale identifier.
 * @param dwFlags Locale and date-conversion flags.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, LONG *plOut);
/**
 * Converts an unsigned byte to a signed 32-bit integer.
 *
 * @param bIn Value to convert.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromUI1(BYTE bIn, LONG *plOut);
/**
 * Converts an unsigned 16-bit integer to a signed 32-bit integer.
 *
 * @param uiIn Value to convert.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromUI2(USHORT uiIn, LONG *plOut);
/**
 * Converts an unsigned 32-bit integer to a signed 32-bit integer.
 *
 * @param ulIn Value to convert.
 * @param plOut Receives the LONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarI4FromUI4(ULONG ulIn, LONG *plOut);
typedef struct {
    INT cDig;
    ULONG dwInFlags;
    ULONG dwOutFlags;
    INT cchUsed;
    INT nBaseShift;
    INT nPwr10;
} NUMPARSE;

/**
 * Converts parsed digits to a VARIANT using an allowed numeric type.
 *
 * Set one VTBIT_* flag per accepted output type. For decimal rounding,
 * rgbDig must hold up to 30 digits; octal input may need 11 digits.
 *
 * @param pnumprs Parsed number description; cDig gives the digit count.
 * @param rgbDig Parsed digits.
 * @param dwVtBits Bitmask of acceptable VTBIT_* result types.
 * @param pvar Receives the converted VARIANT.
 * @return S_OK, DISP_E_OVERFLOW or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarNumFromParseNum(NUMPARSE *pnumprs, BYTE *rgbDig, ULONG dwVtBits, VARIANT *pvar);
/**
 * Parses a string into locale-independent numeric digits and metadata.
 *
 * With dwFlags zero, only decimal digits are accepted. Set NUMPRS_* bits
 * to allow other syntax; NUMPRS_STD enables standard Automation parsing.
 *
 * @param strIn String to parse.
 * @param lcid Locale identifier.
 * @param dwFlags NUMPRS_* syntax options.
 * @param pnumprs Receives parsed sign, scale, digit count and consumed length.
 * @param rgbDig Receives parsed digits; size is specified by pnumprs.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarParseNumFromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, NUMPARSE *pnumprs, BYTE *rgbDig);
/**
 * Converts VARIANT_BOOL to a single-precision float.
 *
 * @param boolIn Boolean value to convert.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromBool(VARIANT_BOOL boolIn, FLOAT *pfltOut);
/**
 * Converts CY to a single-precision float.
 *
 * @param cyIn Currency value to convert.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromCy(CY cyIn, FLOAT *pfltOut);
/**
 * Converts an Automation DATE to a single-precision float.
 *
 * @param dateIn DATE value to convert.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromDate(DATE dateIn, FLOAT *pfltOut);
/**
 * Converts DECIMAL to a single-precision float.
 *
 * @param pdecIn Decimal value to convert.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromDec(DECIMAL *pdecIn, FLOAT *pfltOut);
/**
 * Converts IDispatch to a single-precision float using the specified locale.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromDisp(IDispatch *pdispIn, LCID lcid, FLOAT *pfltOut);
/**
 * Converts a signed byte to a single-precision float.
 *
 * @param cIn Value to convert.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromI1(CHAR cIn, FLOAT *pfltOut);
/**
 * Converts a signed 16-bit integer to a single-precision float.
 *
 * @param sIn Value to convert.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromI2(SHORT sIn, FLOAT *pfltOut);
/**
 * Converts a signed 32-bit integer to a single-precision float.
 *
 * @param lIn Value to convert.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromI4(LONG lIn, FLOAT *pfltOut);
/**
 * Converts a double-precision float to a single-precision float.
 *
 * @param dblIn Value to convert.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromR8(DOUBLE dblIn, FLOAT *pfltOut);
/**
 * Parses a locale-formatted string as a single-precision float.
 *
 * @param strIn String to parse.
 * @param lcid Locale identifier.
 * @param dwFlags Locale conversion flags.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, FLOAT *pfltOut);
/**
 * Converts an unsigned byte to a single-precision float.
 *
 * @param bIn Value to convert.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromUI1(BYTE bIn, FLOAT *pfltOut);
/**
 * Converts an unsigned 16-bit integer to a single-precision float.
 *
 * @param uiIn Value to convert.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromUI2(USHORT uiIn, FLOAT *pfltOut);
/**
 * Converts an unsigned 32-bit integer to a single-precision float.
 *
 * @param ulIn Value to convert.
 * @param pfltOut Receives the FLOAT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR4FromUI4(ULONG ulIn, FLOAT *pfltOut);
/**
 * Converts VARIANT_BOOL to a double-precision float.
 *
 * @param boolIn Boolean value to convert.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromBool(VARIANT_BOOL boolIn, DOUBLE *pdblOut);
/**
 * Converts CY to a double-precision float.
 *
 * @param cyIn Currency value to convert.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromCy(CY cyIn, DOUBLE *pdblOut);
/**
 * Converts an Automation DATE to a double-precision float.
 *
 * @param dateIn DATE value to convert.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromDate(DATE dateIn, DOUBLE *pdblOut);
/**
 * Converts DECIMAL to a double-precision float.
 *
 * @param pdecIn Decimal value to convert.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromDec(DECIMAL *pdecIn, DOUBLE *pdblOut);
/**
 * Converts IDispatch to a double using the specified locale.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromDisp(IDispatch *pdispIn, LCID lcid, DOUBLE *pdblOut);
/**
 * Converts a signed byte to a double-precision float.
 *
 * @param cIn Value to convert.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromI1(CHAR cIn, DOUBLE *pdblOut);
/**
 * Converts a signed 16-bit integer to a double-precision float.
 *
 * @param sIn Value to convert.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromI2(SHORT sIn, DOUBLE *pdblOut);
/**
 * Converts a signed 32-bit integer to a double-precision float.
 *
 * @param lIn Value to convert.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromI4(LONG lIn, DOUBLE *pdblOut);
/**
 * Converts a single-precision float to a double-precision float.
 *
 * @param fltIn Value to convert.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromR4(FLOAT fltIn, DOUBLE *pdblOut);
/**
 * Parses a locale-formatted string as a double-precision float.
 *
 * @param strIn String to parse.
 * @param lcid Locale identifier.
 * @param dwFlags Locale conversion flags.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, DOUBLE *pdblOut);
/**
 * Converts an unsigned byte to a double-precision float.
 *
 * @param bIn Value to convert.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromUI1(BYTE bIn, DOUBLE *pdblOut);
/**
 * Converts an unsigned 16-bit integer to a double-precision float.
 *
 * @param uiIn Value to convert.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromUI2(USHORT uiIn, DOUBLE *pdblOut);
/**
 * Converts an unsigned 32-bit integer to a double-precision float.
 *
 * @param ulIn Value to convert.
 * @param pdblOut Receives the DOUBLE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarR8FromUI4(ULONG ulIn, DOUBLE *pdblOut);
/**
 * Converts VARIANT_BOOL to an unsigned byte.
 *
 * @param boolIn Boolean value to convert.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromBool(VARIANT_BOOL boolIn, BYTE *pbOut);
/**
 * Converts CY to an unsigned byte.
 *
 * @param cyIn Currency value to convert.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromCy(CY cyIn, BYTE *pbOut);
/**
 * Converts an Automation DATE to an unsigned byte.
 *
 * @param dateIn DATE value to convert.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromDate(DATE dateIn, BYTE *pbOut);
/**
 * Converts DECIMAL to an unsigned byte.
 *
 * @param pdecIn Decimal value to convert.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromDec(DECIMAL *pdecIn, BYTE *pbOut);
/**
 * Converts IDispatch to an unsigned byte using the specified locale.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromDisp(IDispatch *pdispIn, LCID lcid, BYTE *pbOut);
/**
 * Converts a signed byte to an unsigned byte.
 *
 * @param cIn Value to convert.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromI1(CHAR cIn, BYTE *pbOut);
/**
 * Converts a signed 16-bit integer to an unsigned byte.
 *
 * @param sIn Value to convert.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromI2(SHORT sIn, BYTE *pbOut);
/**
 * Converts a signed 32-bit integer to an unsigned byte.
 *
 * @param lIn Value to convert.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromI4(LONG lIn, BYTE *pbOut);
/**
 * Converts a single-precision float to an unsigned byte.
 *
 * @param fltIn Value to convert.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromR4(FLOAT fltIn, BYTE *pbOut);
/**
 * Converts a double-precision float to an unsigned byte.
 *
 * @param dblIn Value to convert.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromR8(DOUBLE dblIn, BYTE *pbOut);
/**
 * Parses a locale-formatted string as an unsigned byte.
 *
 * @param strIn String to parse.
 * @param lcid Locale identifier.
 * @param dwFlags Locale conversion flags.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, BYTE *pbOut);
/**
 * Converts an unsigned 16-bit integer to an unsigned byte.
 *
 * @param uiIn Value to convert.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromUI2(USHORT uiIn, BYTE *pbOut);
/**
 * Converts an unsigned 32-bit integer to an unsigned byte.
 *
 * @param ulIn Value to convert.
 * @param pbOut Receives the BYTE value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI1FromUI4(ULONG ulIn, BYTE *pbOut);
/**
 * Converts VARIANT_BOOL to an unsigned 16-bit integer.
 *
 * @param boolIn Boolean value to convert.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromBool(VARIANT_BOOL boolIn, USHORT *puiOut);
/**
 * Converts CY to an unsigned 16-bit integer.
 *
 * @param cyIn Currency value to convert.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromCy(CY cyIn, USHORT *puiOut);
/**
 * Converts an Automation DATE to an unsigned 16-bit integer.
 *
 * @param dateIn DATE value to convert.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromDate(DATE dateIn, USHORT *puiOut);
/**
 * Converts DECIMAL to an unsigned 16-bit integer.
 *
 * @param pdecIn Decimal value to convert.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromDec(DECIMAL *pdecIn, USHORT *puiOut);
/**
 * Converts IDispatch to an unsigned 16-bit integer using the specified locale.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromDisp(IDispatch *pdispIn, LCID lcid, USHORT *puiOut);
/**
 * Converts a signed byte to an unsigned 16-bit integer.
 *
 * @param cIn Value to convert.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromI1(CHAR cIn, USHORT *puiOut);
/**
 * Converts a signed 16-bit integer to an unsigned 16-bit integer.
 *
 * @param uiIn Value to convert.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromI2(SHORT uiIn, USHORT *puiOut);
/**
 * Converts a signed 32-bit integer to an unsigned 16-bit integer.
 *
 * @param lIn Value to convert.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromI4(LONG lIn, USHORT *puiOut);
/**
 * Converts a single-precision float to an unsigned 16-bit integer.
 *
 * @param fltIn Value to convert.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromR4(FLOAT fltIn, USHORT *puiOut);
/**
 * Converts a double-precision float to an unsigned 16-bit integer.
 *
 * @param dblIn Value to convert.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromR8(DOUBLE dblIn, USHORT *puiOut);
/**
 * Parses a locale-formatted string as an unsigned 16-bit integer.
 *
 * @param strIn String to parse.
 * @param lcid Locale identifier.
 * @param dwFlags Locale conversion flags.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, USHORT *puiOut);
/**
 * Converts an unsigned byte to an unsigned 16-bit integer.
 *
 * @param bIn Value to convert.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromUI1(BYTE bIn, USHORT *puiOut);
/**
 * Converts an unsigned 32-bit integer to an unsigned 16-bit integer.
 *
 * @param ulIn Value to convert.
 * @param puiOut Receives the USHORT value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI2FromUI4(ULONG ulIn, USHORT *puiOut);
/**
 * Converts VARIANT_BOOL to an unsigned 32-bit integer.
 *
 * @param boolIn Boolean value to convert.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromBool(VARIANT_BOOL boolIn, ULONG *pulOut);
/**
 * Converts CY to an unsigned 32-bit integer.
 *
 * @param cyIn Currency value to convert.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromCy(CY cyIn, ULONG *pulOut);
/**
 * Converts an Automation DATE to an unsigned 32-bit integer.
 *
 * @param dateIn DATE value to convert.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromDate(DATE dateIn, ULONG *pulOut);
/**
 * Converts DECIMAL to an unsigned 32-bit integer.
 *
 * @param pdecIn Decimal value to convert.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromDec(DECIMAL *pdecIn, ULONG *pulOut);
/**
 * Converts IDispatch to an unsigned 32-bit integer using the specified locale.
 *
 * @param pdispIn Value to convert.
 * @param lcid Locale identifier.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromDisp(IDispatch *pdispIn, LCID lcid, ULONG *pulOut);
/**
 * Converts a signed byte to an unsigned 32-bit integer.
 *
 * @param cIn Value to convert.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromI1(CHAR cIn, ULONG *pulOut);
/**
 * Converts a signed 16-bit integer to an unsigned 32-bit integer.
 *
 * @param uiIn Value to convert.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromI2(SHORT uiIn, ULONG *pulOut);
/**
 * Converts a signed 32-bit integer to an unsigned 32-bit integer.
 *
 * @param lIn Value to convert.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromI4(LONG lIn, ULONG *pulOut);
/**
 * Converts a single-precision float to an unsigned 32-bit integer.
 *
 * @param fltIn Value to convert.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromR4(FLOAT fltIn, ULONG *pulOut);
/**
 * Converts a double-precision float to an unsigned 32-bit integer.
 *
 * @param dblIn Value to convert.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromR8(DOUBLE dblIn, ULONG *pulOut);
/**
 * Parses a locale-formatted string as an unsigned 32-bit integer.
 *
 * @param strIn String to parse.
 * @param lcid Locale identifier.
 * @param dwFlags Locale conversion flags.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_TYPEMISMATCH, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromStr(OLECHAR *strIn, LCID lcid, ULONG dwFlags, ULONG *pulOut);
/**
 * Converts an unsigned byte to an unsigned 32-bit integer.
 *
 * @param bIn Value to convert.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromUI1(BYTE bIn, ULONG *pulOut);
/**
 * Converts an unsigned 16-bit integer to an unsigned 32-bit integer.
 *
 * @param uiIn Value to convert.
 * @param pulOut Receives the ULONG value.
 * @return S_OK, DISP_E_OVERFLOW or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUI4FromUI2(USHORT uiIn, ULONG *pulOut);
/**
 * Converts a DATE value into an unpacked date structure.
 *
 * @param dateIn DATE value to convert.
 * @param dwFlags Calendar flags.
 * @param pudateOut Receives the unpacked date.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VarUdateFromDate(DATE dateIn, ULONG dwFlags, UDATE *pudateOut);
/**
 * Converts a VARIANTARG from one type to another.
 *
 * @param pvargDest Receives the coerced value.
 * @param pvarSrc Source value to coerce.
 * @param wFlags Coercion flags.
 * @param vt Destination VARTYPE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VariantChangeType(VARIANTARG *pvargDest, VARIANTARG *pvarSrc, USHORT wFlags, VARTYPE vt);
/**
 * Converts a VARIANTARG from one type to another using a locale identifier.
 *
 * @param pvargDest Receives the coerced value.
 * @param pvarSrc Source value to coerce.
 * @param lcid Locale identifier for string and date conversions.
 * @param wFlags Coercion flags.
 * @param vt Destination VARTYPE.
 * @return S_OK, DISP_E_OVERFLOW, DISP_E_TYPEMISMATCH or an error.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VariantChangeTypeEx(VARIANTARG *pvargDest, VARIANTARG *pvarSrc, LCID lcid, USHORT wFlags, VARTYPE vt);
/**
 * Clears a VARIANTARG and releases any owned data.
 *
 * @param pvarg Variant to clear.
 * @return S_OK, DISP_E_ARRAYISLOCKED or E_INVALIDARG.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VariantClear(VARIANTARG *pvarg);
/**
 * Copies one VARIANTARG into another, freeing the destination first.
 *
 * @param pvargDest Receives the copied value.
 * @param pvargSrc Source variant to copy.
 * @return S_OK, DISP_E_ARRAYISLOCKED, DISP_E_BADVARTYPE or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VariantCopy(VARIANTARG *pvargDest, VARIANTARG *pvargSrc);
/**
 * Copies a VARIANTARG while dereferencing VT_BYREF values as needed.
 *
 * @param pvarDest Receives the copy.
 * @param pvargSrc Source variant to copy.
 * @return S_OK, DISP_E_ARRAYISLOCKED, DISP_E_BADVARTYPE or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VariantCopyInd(VARIANT *pvarDest, VARIANTARG *pvargSrc);
/**
 * Initializes a VARIANTARG to VT_EMPTY.
 *
 * @param pvarg Variant to initialize.
 *
 * @note Windows CE 2.0 and later.
 */
void VariantInit(VARIANTARG *pvarg);
/**
 * Converts a variant time value to a Win32 SYSTEMTIME structure.
 *
 * @param vtime Variant time value to convert.
 * @param lpSystemTime Receives the system time.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 2.0 and later.
 */
INT VariantTimeToSystemTime(DOUBLE vtime, LPSYSTEMTIME lpSystemTime);
/**
 * Creates a one-dimensional SAFEARRAY from the characters in a BSTR.
 *
 * @param bstr BSTR to convert.
 * @param ppsa Receives the SAFEARRAY pointer.
 * @return S_OK, E_OUTOFMEMORY or E_INVALIDARG.
 *
 * @note Windows CE 2.0 and later.
 */
HRESULT VectorFromBstr(BSTR bstr, SAFEARRAY **ppsa);
struct tagINTERFACEDATA;
typedef struct tagINTERFACEDATA INTERFACEDATA;
typedef struct tagINTERFACEDATA *LPINTERFACEDATA;
struct tagMETHODDATA;
typedef struct tagMETHODDATA *LPMETHODDATA;
struct tagPARAMDATA;
typedef struct tagPARAMDATA *LPPARAMDATA;
typedef struct tagMETHODDATA METHODDATA;
typedef struct tagPARAMDATA PARAMDATA;
enum tagREGKIND {
    REGKIND_DEFAULT,
    REGKIND_REGISTER,
    REGKIND_NONE
};

typedef enum tagREGKIND REGKIND;
struct tagINTERFACEDATA {
    METHODDATA *pmethdata;
    UINT cMembers;
} __attribute__((packed, aligned(4)));

struct tagMETHODDATA {
    OLECHAR *szName;
    PARAMDATA *ppdata;
    DISPID dispid;
    UINT iMeth;
    CALLCONV cc;
    UINT cArgs;
    WORD wFlags;
    VARTYPE vtReturn;
} __attribute__((packed, aligned(4)));

struct tagPARAMDATA {
    OLECHAR *szName;
    VARTYPE vt;
} __attribute__((packed, aligned(4)));


#ifdef __cplusplus
}
#endif

#endif
