#ifndef GRIMACE_SDK_OLE2_H
#define GRIMACE_SDK_OLE2_H

#include <grimace/sdk/objbase.h>
#include <grimace/sdk/oleidl.h>
#include <grimace/sdk/unknwn.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates an OLE advise holder for managing compound-document notifications.
 *
 * The implementation does not support IOleAdviseHolder::EnumAdvise.
 *
 * @param ppOAHolder Receives the IOleAdviseHolder interface pointer.
 * @return S_OK, or E_OUTOFMEMORY.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT CreateOleAdviseHolder(LPOLEADVISEHOLDER *ppOAHolder);
/**
 * Creates a readable and writable IStream backed by global memory.
 *
 * Pass NULL to allocate a new zero-length memory block. The stream's
 * initial length is GlobalSize(hGlobal); use IStream::SetSize when the
 * logical length matters. It does not support transactions or locking.
 *
 * @param hGlobal Movable, nondiscardable global-memory handle, or NULL.
 * @param fDeleteOnRelease TRUE to free the memory handle when the stream
 *        is released.
 * @param ppstm Receives the IStream interface pointer.
 * @return S_OK, E_INVALIDARG or E_OUTOFMEMORY.
 *
 * @note Windows CE 3.0 only.
 */
HRESULT CreateStreamOnHGlobal(HGLOBAL hGlobal, BOOL fDeleteOnRelease, LPSTREAM *ppstm);
/**
 * Runs an OLE drag-and-drop operation for a data source.
 *
 * Call OleInitialize first. The source supplies IDataObject and IDropSource
 * implementations; the target window must be registered with
 * RegisterDragDrop. On drop or cancellation, the return value is
 * DRAGDROP_S_DROP or DRAGDROP_S_CANCEL.
 *
 * @param pDataObj IDataObject containing the dragged data.
 * @param pDropSource IDropSource implementation for the drag operation.
 * @param dwOKEffects DROPEFFECT_* operations the source permits.
 * @param pdwEffect Receives the effect selected by the target.
 * @return DRAGDROP_S_DROP, DRAGDROP_S_CANCEL or an HRESULT error.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT DoDragDrop(LPDATAOBJECT pDataObj, LPDROPSOURCE pDropSource, DWORD dwOKEffects, LPDWORD pdwEffect);
/**
 * Retrieves the current global-memory handle backing an HGLOBAL stream.
 *
 * The handle may differ from the one originally passed to
 * CreateStreamOnHGlobal because the stream can reallocate its memory.
 *
 * @param pstm Stream created by CreateStreamOnHGlobal.
 * @param phglobal Receives the current memory handle.
 * @return S_OK, or E_INVALIDARG for an unsupported stream.
 *
 * @note Windows CE 3.0 only.
 */
HRESULT GetHGlobalFromStream(LPSTREAM pstm, HGLOBAL *phglobal);
/**
 * Creates and initializes a new embedded OLE object in storage.
 *
 * pStg is required. If pClientSite is NULL, set the client site before
 * using the object. The created object is initially blank unless a render
 * option requests cached data.
 *
 * @param rclsid Class identifier of the object to create.
 * @param riid Interface identifier to return, usually IID_IOleObject.
 * @param renderopt OLERENDER cache option.
 * @param pFormatEtc Format description required by renderopt.
 * @param pClientSite Container's IOleClientSite, or NULL.
 * @param pStg Storage for the new object.
 * @param ppvObj Receives the requested interface pointer.
 * @return S_OK, E_OUTOFMEMORY, or an object-creation error.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT OleCreate(const CLSID *const rclsid, const IID *const riid, DWORD renderopt, LPFORMATETC pFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID *ppvObj);
/**
 * Draws an object's IViewObject representation into a device context.
 *
 * Queries pUnknown for IViewObject and calls Draw with the requested
 * aspect and bounds. Do not use a metafile DC.
 *
 * @param pUnknown Object supporting IViewObject.
 * @param dwAspect DVASPECT representation to draw.
 * @param hdcDraw Destination device context.
 * @param lprcBounds Destination rectangle.
 * @return S_OK, OLE_E_BLANK, VIEW_E_DRAW, or a drawing error.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT OleDraw(LPUNKNOWN pUnknown, DWORD dwAspect, HDC hdcDraw, LPCRECT lprcBounds);
/**
 * Checks whether an OLE object is in the running state.
 *
 * Queries the object for IRunnableObject and calls IsRunning.
 *
 * @param pObject Object to check.
 * @return TRUE if running, otherwise FALSE.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
BOOL OleIsRunning(LPOLEOBJECT pObject);
/**
 * Puts an OLE object into the running state.
 *
 * Queries the object for IRunnableObject and calls Run.
 *
 * @param pUnknown Object to run.
 * @return S_OK, OLE_E_CLASSDIFF, or an error from IRunnableObject::Run.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT OleRun(LPUNKNOWN pUnknown);
/**
 * Saves a persistent-storage object and commits its destination storage.
 *
 * Writes the object's CLSID, calls IPersistStorage::Save, then commits
 * when saving succeeds. Use the interfaces directly for other save cases.
 *
 * @param pPS Object's IPersistStorage interface.
 * @param pStg Destination IStorage.
 * @param fSameAsLoad TRUE when pStg is the storage from which it was loaded.
 * @return S_OK, STG_E_MEDIUMFULL, or an IPersistStorage error.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT OleSave(LPPERSISTSTORAGE pPS, LPSTORAGE pStg, BOOL fSameAsLoad);
/**
 * Notifies an OLE object that it is embedded in a container.
 *
 * Queries the object for IRunnableObject and calls SetContainedObject.
 *
 * @param pUnknown Object to update.
 * @param fContained TRUE for a contained object, FALSE otherwise.
 * @return S_OK, or an error from IRunnableObject::SetContainedObject.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT OleSetContainedObject(LPUNKNOWN pUnknown, BOOL fContained);
/**
 * Installs or removes OLE menu-message dispatch on a frame window.
 *
 * Pass NULL for holemenu to remove dispatch. hwndActiveObject and
 * lpActiveObj are unsupported and must be NULL.
 *
 * @param holemenu Composite descriptor from OleCreateMenuDescriptor, or NULL.
 * @param hwndFrame Container frame window.
 * @param hwndActiveObject Unsupported; set to NULL.
 * @param lpFrame Container's IOleInPlaceFrame interface.
 * @param lpActiveObj Unsupported; set to NULL.
 * @return S_OK, or an OLE error.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT OleSetMenuDescriptor(HOLEMENU holemenu, HWND hwndFrame, HWND hwndActiveObject, LPOLEINPLACEFRAME lpFrame, LPOLEINPLACEACTIVEOBJECT lpActiveObj);
/**
 * Reads the CLSID stored in an IStorage object.
 *
 * The CLSID is written by WriteClassStg.
 *
 * @param pStg Storage to read.
 * @param pclsid Receives the CLSID; may receive CLSID_NULL.
 * @return S_OK, E_OUTOFMEMORY, or an IStorage error.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT ReadClassStg(LPSTORAGE pStg, CLSID *pclsid);
/**
 * Reads a CLSID previously written to an IStream.
 *
 * @param pStm Stream containing the CLSID.
 * @param pclsid Receives the CLSID.
 * @return S_OK, or STG_E_READFAULT if the stream ends before the CLSID.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT ReadClassStm(LPSTREAM pStm, CLSID *pclsid);
/**
 * Registers a window as an OLE drop target.
 *
 * Call OleInitialize first. The function holds a reference to
 * `pDropTarget`; call RevokeDragDrop when the window is no longer a target.
 *
 * @param hwnd Window that accepts drops.
 * @param pDropTarget IDropTarget implementation for the window.
 * @return S_OK, DRAGDROP_E_INVALIDHWND, DRAGDROP_E_ALREADYREGISTERED or an error.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT RegisterDragDrop(HWND hwnd, LPDROPTARGET pDropTarget);
/**
 * Releases the resources owned by a storage medium.
 *
 * The release action depends on tymed and punkForRelease. The medium is
 * invalid after this call.
 *
 * @param pmedium Storage medium to release.
 *
 * @note Windows CE 3.0 only.
 */
void ReleaseStgMedium(LPSTGMEDIUM pmedium);
/**
 * Removes a window's OLE drop-target registration.
 *
 * This releases the IDropTarget reference acquired by RegisterDragDrop.
 *
 * @param hwnd Window previously registered as a drop target.
 * @return S_OK, DRAGDROP_E_NOTREGISTERED, DRAGDROP_E_INVALIDHWND or an error.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT RevokeDragDrop(HWND hwnd);
/**
 * Writes a CLSID to an IStorage object for later retrieval by ReadClassStg.
 *
 * @param pStg Storage object to update.
 * @param rclsid Class identifier to store.
 * @return S_OK, STG_E_MEDIUMFULL, or an IStorage::SetClass error.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT WriteClassStg(LPSTORAGE pStg, const CLSID *const rclsid);
/**
 * Writes a CLSID to an IStream for later retrieval by ReadClassStm.
 *
 * Most applications do not need to call this helper directly.
 *
 * @param pStm Stream to update.
 * @param rclsid Class identifier to write.
 * @return S_OK, STG_E_MEDIUMFULL, or a stream error.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
HRESULT WriteClassStm(LPSTREAM pStm, const CLSID *const rclsid);
struct _OLESTREAM;
typedef struct _OLESTREAM *LPOLESTREAM;
struct _OLESTREAMVTBL;
typedef struct _OLESTREAMVTBL OLESTREAMVTBL;
typedef OLESTREAMVTBL *LPOLESTREAMVTBL;
typedef struct _OLESTREAM OLESTREAM;
struct _OLESTREAM {
    LPOLESTREAMVTBL lpstbl;
};

struct _OLESTREAMVTBL {
    DWORD (*Get)(LPOLESTREAM, void *, DWORD);
    DWORD (*Put)(LPOLESTREAM, const void *, DWORD);
};


#ifdef __cplusplus
}
#endif

#endif
