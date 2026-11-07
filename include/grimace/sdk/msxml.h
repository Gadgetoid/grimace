#ifndef GRIMACE_SDK_MSXML_H
#define GRIMACE_SDK_MSXML_H

#include <grimace/sdk/oaidl.h>
#include <grimace/sdk/unknwn.h>
#include <grimace/sdk/wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {

} DOMDocument;

typedef struct {

} DOMFreeThreadedDocument;

enum tagDOMNodeType {
    NODE_INVALID = 0,
    NODE_ELEMENT = 1,
    NODE_ATTRIBUTE = 2,
    NODE_TEXT = 3,
    NODE_CDATA_SECTION = 4,
    NODE_ENTITY_REFERENCE = 5,
    NODE_ENTITY = 6,
    NODE_PROCESSING_INSTRUCTION = 7,
    NODE_COMMENT = 8,
    NODE_DOCUMENT = 9,
    NODE_DOCUMENT_TYPE = 10,
    NODE_DOCUMENT_FRAGMENT = 11,
    NODE_NOTATION = 12
};

typedef enum tagDOMNodeType DOMNodeType;
struct IXMLAttribute;
typedef struct IXMLAttribute IXMLAttribute;
struct IXMLAttributeVtbl;
typedef struct IXMLAttributeVtbl IXMLAttributeVtbl;
struct IXMLDOMAttribute;
typedef struct IXMLDOMAttribute IXMLDOMAttribute;
struct IXMLDOMAttributeVtbl;
typedef struct IXMLDOMAttributeVtbl IXMLDOMAttributeVtbl;
struct IXMLDOMCDATASection;
typedef struct IXMLDOMCDATASection IXMLDOMCDATASection;
struct IXMLDOMCDATASectionVtbl;
typedef struct IXMLDOMCDATASectionVtbl IXMLDOMCDATASectionVtbl;
struct IXMLDOMCharacterData;
typedef struct IXMLDOMCharacterData IXMLDOMCharacterData;
struct IXMLDOMCharacterDataVtbl;
typedef struct IXMLDOMCharacterDataVtbl IXMLDOMCharacterDataVtbl;
struct IXMLDOMComment;
typedef struct IXMLDOMComment IXMLDOMComment;
struct IXMLDOMCommentVtbl;
typedef struct IXMLDOMCommentVtbl IXMLDOMCommentVtbl;
struct IXMLDOMDocument;
typedef struct IXMLDOMDocument IXMLDOMDocument;
struct IXMLDOMDocumentFragment;
typedef struct IXMLDOMDocumentFragment IXMLDOMDocumentFragment;
struct IXMLDOMDocumentFragmentVtbl;
typedef struct IXMLDOMDocumentFragmentVtbl IXMLDOMDocumentFragmentVtbl;
struct IXMLDOMDocumentType;
typedef struct IXMLDOMDocumentType IXMLDOMDocumentType;
struct IXMLDOMDocumentTypeVtbl;
typedef struct IXMLDOMDocumentTypeVtbl IXMLDOMDocumentTypeVtbl;
struct IXMLDOMDocumentVtbl;
typedef struct IXMLDOMDocumentVtbl IXMLDOMDocumentVtbl;
struct IXMLDOMElement;
typedef struct IXMLDOMElement IXMLDOMElement;
struct IXMLDOMElementVtbl;
typedef struct IXMLDOMElementVtbl IXMLDOMElementVtbl;
struct IXMLDOMEntity;
typedef struct IXMLDOMEntity IXMLDOMEntity;
struct IXMLDOMEntityReference;
typedef struct IXMLDOMEntityReference IXMLDOMEntityReference;
struct IXMLDOMEntityReferenceVtbl;
typedef struct IXMLDOMEntityReferenceVtbl IXMLDOMEntityReferenceVtbl;
struct IXMLDOMEntityVtbl;
typedef struct IXMLDOMEntityVtbl IXMLDOMEntityVtbl;
struct IXMLDOMImplementation;
typedef struct IXMLDOMImplementation IXMLDOMImplementation;
struct IXMLDOMImplementationVtbl;
typedef struct IXMLDOMImplementationVtbl IXMLDOMImplementationVtbl;
struct IXMLDOMNamedNodeMap;
typedef struct IXMLDOMNamedNodeMap IXMLDOMNamedNodeMap;
struct IXMLDOMNamedNodeMapVtbl;
typedef struct IXMLDOMNamedNodeMapVtbl IXMLDOMNamedNodeMapVtbl;
struct IXMLDOMNode;
typedef struct IXMLDOMNode IXMLDOMNode;
struct IXMLDOMNodeList;
typedef struct IXMLDOMNodeList IXMLDOMNodeList;
struct IXMLDOMNodeListVtbl;
typedef struct IXMLDOMNodeListVtbl IXMLDOMNodeListVtbl;
struct IXMLDOMNodeVtbl;
typedef struct IXMLDOMNodeVtbl IXMLDOMNodeVtbl;
struct IXMLDOMNotation;
typedef struct IXMLDOMNotation IXMLDOMNotation;
struct IXMLDOMNotationVtbl;
typedef struct IXMLDOMNotationVtbl IXMLDOMNotationVtbl;
struct IXMLDOMParseError;
typedef struct IXMLDOMParseError IXMLDOMParseError;
struct IXMLDOMParseErrorVtbl;
typedef struct IXMLDOMParseErrorVtbl IXMLDOMParseErrorVtbl;
struct IXMLDOMProcessingInstruction;
typedef struct IXMLDOMProcessingInstruction IXMLDOMProcessingInstruction;
struct IXMLDOMProcessingInstructionVtbl;
typedef struct IXMLDOMProcessingInstructionVtbl IXMLDOMProcessingInstructionVtbl;
struct IXMLDOMText;
typedef struct IXMLDOMText IXMLDOMText;
struct IXMLDOMTextVtbl;
typedef struct IXMLDOMTextVtbl IXMLDOMTextVtbl;
struct IXMLDSOControl;
typedef struct IXMLDSOControl IXMLDSOControl;
struct IXMLDSOControlVtbl;
typedef struct IXMLDSOControlVtbl IXMLDSOControlVtbl;
struct IXMLDocument;
typedef struct IXMLDocument IXMLDocument;
struct IXMLDocument2;
typedef struct IXMLDocument2 IXMLDocument2;
struct IXMLDocument2Vtbl;
typedef struct IXMLDocument2Vtbl IXMLDocument2Vtbl;
struct IXMLDocumentVtbl;
typedef struct IXMLDocumentVtbl IXMLDocumentVtbl;
struct IXMLElement;
typedef struct IXMLElement IXMLElement;
struct IXMLElement2;
typedef struct IXMLElement2 IXMLElement2;
struct IXMLElement2Vtbl;
typedef struct IXMLElement2Vtbl IXMLElement2Vtbl;
struct IXMLElementCollection;
typedef struct IXMLElementCollection IXMLElementCollection;
struct IXMLElementCollectionVtbl;
typedef struct IXMLElementCollectionVtbl IXMLElementCollectionVtbl;
struct IXMLElementVtbl;
typedef struct IXMLElementVtbl IXMLElementVtbl;
struct IXMLError;
typedef struct IXMLError IXMLError;
struct IXMLErrorVtbl;
typedef struct IXMLErrorVtbl IXMLErrorVtbl;
struct IXMLHttpRequest;
typedef struct IXMLHttpRequest IXMLHttpRequest;
struct IXMLHttpRequestVtbl;
typedef struct IXMLHttpRequestVtbl IXMLHttpRequestVtbl;
struct IXTLRuntime;
typedef struct IXTLRuntime IXTLRuntime;
struct IXTLRuntimeVtbl;
typedef struct IXTLRuntimeVtbl IXTLRuntimeVtbl;
struct XMLDOMDocumentEvents;
typedef struct XMLDOMDocumentEvents XMLDOMDocumentEvents;
struct XMLDOMDocumentEventsVtbl;
typedef struct XMLDOMDocumentEventsVtbl XMLDOMDocumentEventsVtbl;
typedef struct {

} XMLDSOControl;

typedef struct {

} XMLDocument;

enum tagXMLEMEM_TYPE {
    XMLELEMTYPE_ELEMENT = 0,
    XMLELEMTYPE_TEXT = 1,
    XMLELEMTYPE_COMMENT = 2,
    XMLELEMTYPE_DOCUMENT = 3,
    XMLELEMTYPE_DTD = 4,
    XMLELEMTYPE_PI = 5,
    XMLELEMTYPE_OTHER = 6
};

typedef enum tagXMLEMEM_TYPE XMLELEM_TYPE;
typedef struct {

} XMLHTTPRequest;

struct _xml_error;
typedef struct _xml_error XML_ERROR;
struct IXMLAttribute {
    struct IXMLAttributeVtbl *lpVtbl;
};

struct IXMLAttributeVtbl {
    HRESULT (*QueryInterface)(IXMLAttribute *, const IID *const, void **);
    ULONG (*AddRef)(IXMLAttribute *);
    ULONG (*Release)(IXMLAttribute *);
    HRESULT (*GetTypeInfoCount)(IXMLAttribute *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLAttribute *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLAttribute *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLAttribute *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_name)(IXMLAttribute *, BSTR *);
    HRESULT (*get_value)(IXMLAttribute *, BSTR *);
};

struct IXMLDOMAttribute {
    struct IXMLDOMAttributeVtbl *lpVtbl;
};

struct IXMLDOMAttributeVtbl {
    HRESULT (*QueryInterface)(IXMLDOMAttribute *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMAttribute *);
    ULONG (*Release)(IXMLDOMAttribute *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMAttribute *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMAttribute *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMAttribute *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMAttribute *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMAttribute *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMAttribute *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMAttribute *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMAttribute *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMAttribute *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMAttribute *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMAttribute *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMAttribute *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMAttribute *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMAttribute *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMAttribute *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMAttribute *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMAttribute *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMAttribute *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMAttribute *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMAttribute *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMAttribute *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMAttribute *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMAttribute *, BSTR *);
    HRESULT (*get_text)(IXMLDOMAttribute *, BSTR *);
    HRESULT (*put_text)(IXMLDOMAttribute *, BSTR);
    HRESULT (*get_specified)(IXMLDOMAttribute *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMAttribute *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMAttribute *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMAttribute *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMAttribute *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMAttribute *, BSTR);
    HRESULT (*get_xml)(IXMLDOMAttribute *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMAttribute *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMAttribute *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMAttribute *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMAttribute *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMAttribute *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMAttribute *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMAttribute *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMAttribute *, IXMLDOMNode *, VARIANT);
    HRESULT (*get_name)(IXMLDOMAttribute *, BSTR *);
    HRESULT (*get_value)(IXMLDOMAttribute *, VARIANT *);
    HRESULT (*put_value)(IXMLDOMAttribute *, VARIANT);
};

struct IXMLDOMCDATASection {
    struct IXMLDOMCDATASectionVtbl *lpVtbl;
};

struct IXMLDOMCDATASectionVtbl {
    HRESULT (*QueryInterface)(IXMLDOMCDATASection *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMCDATASection *);
    ULONG (*Release)(IXMLDOMCDATASection *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMCDATASection *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMCDATASection *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMCDATASection *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMCDATASection *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMCDATASection *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMCDATASection *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMCDATASection *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMCDATASection *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMCDATASection *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMCDATASection *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMCDATASection *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMCDATASection *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMCDATASection *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMCDATASection *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMCDATASection *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMCDATASection *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMCDATASection *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMCDATASection *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMCDATASection *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMCDATASection *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMCDATASection *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMCDATASection *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMCDATASection *, BSTR *);
    HRESULT (*get_text)(IXMLDOMCDATASection *, BSTR *);
    HRESULT (*put_text)(IXMLDOMCDATASection *, BSTR);
    HRESULT (*get_specified)(IXMLDOMCDATASection *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMCDATASection *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMCDATASection *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMCDATASection *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMCDATASection *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMCDATASection *, BSTR);
    HRESULT (*get_xml)(IXMLDOMCDATASection *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMCDATASection *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMCDATASection *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMCDATASection *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMCDATASection *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMCDATASection *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMCDATASection *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMCDATASection *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMCDATASection *, IXMLDOMNode *, VARIANT);
    HRESULT (*get_data)(IXMLDOMCDATASection *, BSTR *);
    HRESULT (*put_data)(IXMLDOMCDATASection *, BSTR);
    HRESULT (*get_length)(IXMLDOMCDATASection *, long *);
    HRESULT (*substringData)(IXMLDOMCDATASection *, long, long, BSTR *);
    HRESULT (*appendData)(IXMLDOMCDATASection *, BSTR);
    HRESULT (*insertData)(IXMLDOMCDATASection *, long, BSTR);
    HRESULT (*deleteData)(IXMLDOMCDATASection *, long, long);
    HRESULT (*replaceData)(IXMLDOMCDATASection *, long, long, BSTR);
    HRESULT (*splitText)(IXMLDOMCDATASection *, long, IXMLDOMText **);
};

struct IXMLDOMCharacterData {
    struct IXMLDOMCharacterDataVtbl *lpVtbl;
};

struct IXMLDOMCharacterDataVtbl {
    HRESULT (*QueryInterface)(IXMLDOMCharacterData *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMCharacterData *);
    ULONG (*Release)(IXMLDOMCharacterData *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMCharacterData *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMCharacterData *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMCharacterData *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMCharacterData *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMCharacterData *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMCharacterData *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMCharacterData *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMCharacterData *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMCharacterData *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMCharacterData *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMCharacterData *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMCharacterData *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMCharacterData *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMCharacterData *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMCharacterData *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMCharacterData *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMCharacterData *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMCharacterData *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMCharacterData *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMCharacterData *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMCharacterData *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMCharacterData *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMCharacterData *, BSTR *);
    HRESULT (*get_text)(IXMLDOMCharacterData *, BSTR *);
    HRESULT (*put_text)(IXMLDOMCharacterData *, BSTR);
    HRESULT (*get_specified)(IXMLDOMCharacterData *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMCharacterData *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMCharacterData *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMCharacterData *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMCharacterData *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMCharacterData *, BSTR);
    HRESULT (*get_xml)(IXMLDOMCharacterData *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMCharacterData *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMCharacterData *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMCharacterData *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMCharacterData *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMCharacterData *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMCharacterData *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMCharacterData *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMCharacterData *, IXMLDOMNode *, VARIANT);
    HRESULT (*get_data)(IXMLDOMCharacterData *, BSTR *);
    HRESULT (*put_data)(IXMLDOMCharacterData *, BSTR);
    HRESULT (*get_length)(IXMLDOMCharacterData *, long *);
    HRESULT (*substringData)(IXMLDOMCharacterData *, long, long, BSTR *);
    HRESULT (*appendData)(IXMLDOMCharacterData *, BSTR);
    HRESULT (*insertData)(IXMLDOMCharacterData *, long, BSTR);
    HRESULT (*deleteData)(IXMLDOMCharacterData *, long, long);
    HRESULT (*replaceData)(IXMLDOMCharacterData *, long, long, BSTR);
};

struct IXMLDOMComment {
    struct IXMLDOMCommentVtbl *lpVtbl;
};

struct IXMLDOMCommentVtbl {
    HRESULT (*QueryInterface)(IXMLDOMComment *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMComment *);
    ULONG (*Release)(IXMLDOMComment *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMComment *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMComment *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMComment *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMComment *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMComment *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMComment *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMComment *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMComment *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMComment *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMComment *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMComment *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMComment *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMComment *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMComment *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMComment *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMComment *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMComment *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMComment *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMComment *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMComment *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMComment *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMComment *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMComment *, BSTR *);
    HRESULT (*get_text)(IXMLDOMComment *, BSTR *);
    HRESULT (*put_text)(IXMLDOMComment *, BSTR);
    HRESULT (*get_specified)(IXMLDOMComment *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMComment *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMComment *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMComment *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMComment *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMComment *, BSTR);
    HRESULT (*get_xml)(IXMLDOMComment *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMComment *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMComment *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMComment *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMComment *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMComment *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMComment *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMComment *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMComment *, IXMLDOMNode *, VARIANT);
    HRESULT (*get_data)(IXMLDOMComment *, BSTR *);
    HRESULT (*put_data)(IXMLDOMComment *, BSTR);
    HRESULT (*get_length)(IXMLDOMComment *, long *);
    HRESULT (*substringData)(IXMLDOMComment *, long, long, BSTR *);
    HRESULT (*appendData)(IXMLDOMComment *, BSTR);
    HRESULT (*insertData)(IXMLDOMComment *, long, BSTR);
    HRESULT (*deleteData)(IXMLDOMComment *, long, long);
    HRESULT (*replaceData)(IXMLDOMComment *, long, long, BSTR);
};

struct IXMLDOMDocument {
    struct IXMLDOMDocumentVtbl *lpVtbl;
};

struct IXMLDOMDocumentFragment {
    struct IXMLDOMDocumentFragmentVtbl *lpVtbl;
};

struct IXMLDOMDocumentFragmentVtbl {
    HRESULT (*QueryInterface)(IXMLDOMDocumentFragment *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMDocumentFragment *);
    ULONG (*Release)(IXMLDOMDocumentFragment *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMDocumentFragment *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMDocumentFragment *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMDocumentFragment *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMDocumentFragment *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMDocumentFragment *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMDocumentFragment *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMDocumentFragment *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMDocumentFragment *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMDocumentFragment *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMDocumentFragment *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMDocumentFragment *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMDocumentFragment *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMDocumentFragment *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMDocumentFragment *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMDocumentFragment *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMDocumentFragment *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMDocumentFragment *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMDocumentFragment *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMDocumentFragment *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMDocumentFragment *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMDocumentFragment *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMDocumentFragment *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMDocumentFragment *, BSTR *);
    HRESULT (*get_text)(IXMLDOMDocumentFragment *, BSTR *);
    HRESULT (*put_text)(IXMLDOMDocumentFragment *, BSTR);
    HRESULT (*get_specified)(IXMLDOMDocumentFragment *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMDocumentFragment *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMDocumentFragment *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMDocumentFragment *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMDocumentFragment *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMDocumentFragment *, BSTR);
    HRESULT (*get_xml)(IXMLDOMDocumentFragment *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMDocumentFragment *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMDocumentFragment *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMDocumentFragment *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMDocumentFragment *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMDocumentFragment *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMDocumentFragment *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMDocumentFragment *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMDocumentFragment *, IXMLDOMNode *, VARIANT);
};

struct IXMLDOMDocumentType {
    struct IXMLDOMDocumentTypeVtbl *lpVtbl;
};

struct IXMLDOMDocumentTypeVtbl {
    HRESULT (*QueryInterface)(IXMLDOMDocumentType *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMDocumentType *);
    ULONG (*Release)(IXMLDOMDocumentType *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMDocumentType *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMDocumentType *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMDocumentType *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMDocumentType *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMDocumentType *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMDocumentType *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMDocumentType *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMDocumentType *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMDocumentType *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMDocumentType *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMDocumentType *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMDocumentType *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMDocumentType *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMDocumentType *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMDocumentType *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMDocumentType *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMDocumentType *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMDocumentType *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMDocumentType *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMDocumentType *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMDocumentType *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMDocumentType *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMDocumentType *, BSTR *);
    HRESULT (*get_text)(IXMLDOMDocumentType *, BSTR *);
    HRESULT (*put_text)(IXMLDOMDocumentType *, BSTR);
    HRESULT (*get_specified)(IXMLDOMDocumentType *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMDocumentType *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMDocumentType *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMDocumentType *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMDocumentType *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMDocumentType *, BSTR);
    HRESULT (*get_xml)(IXMLDOMDocumentType *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMDocumentType *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMDocumentType *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMDocumentType *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMDocumentType *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMDocumentType *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMDocumentType *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMDocumentType *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMDocumentType *, IXMLDOMNode *, VARIANT);
    HRESULT (*get_name)(IXMLDOMDocumentType *, BSTR *);
    HRESULT (*get_entities)(IXMLDOMDocumentType *, IXMLDOMNamedNodeMap **);
    HRESULT (*get_notations)(IXMLDOMDocumentType *, IXMLDOMNamedNodeMap **);
};

struct IXMLDOMDocumentVtbl {
    HRESULT (*QueryInterface)(IXMLDOMDocument *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMDocument *);
    ULONG (*Release)(IXMLDOMDocument *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMDocument *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMDocument *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMDocument *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMDocument *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMDocument *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMDocument *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMDocument *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMDocument *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMDocument *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMDocument *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMDocument *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMDocument *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMDocument *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMDocument *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMDocument *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMDocument *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMDocument *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMDocument *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMDocument *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMDocument *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMDocument *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMDocument *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMDocument *, BSTR *);
    HRESULT (*get_text)(IXMLDOMDocument *, BSTR *);
    HRESULT (*put_text)(IXMLDOMDocument *, BSTR);
    HRESULT (*get_specified)(IXMLDOMDocument *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMDocument *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMDocument *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMDocument *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMDocument *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMDocument *, BSTR);
    HRESULT (*get_xml)(IXMLDOMDocument *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMDocument *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMDocument *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMDocument *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMDocument *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMDocument *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMDocument *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMDocument *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMDocument *, IXMLDOMNode *, VARIANT);
    HRESULT (*get_doctype)(IXMLDOMDocument *, IXMLDOMDocumentType **);
    HRESULT (*get_implementation)(IXMLDOMDocument *, IXMLDOMImplementation **);
    HRESULT (*get_documentElement)(IXMLDOMDocument *, IXMLDOMElement **);
    HRESULT (*putref_documentElement)(IXMLDOMDocument *, IXMLDOMElement *);
    HRESULT (*createElement)(IXMLDOMDocument *, BSTR, IXMLDOMElement **);
    HRESULT (*createDocumentFragment)(IXMLDOMDocument *, IXMLDOMDocumentFragment **);
    HRESULT (*createTextNode)(IXMLDOMDocument *, BSTR, IXMLDOMText **);
    HRESULT (*createComment)(IXMLDOMDocument *, BSTR, IXMLDOMComment **);
    HRESULT (*createCDATASection)(IXMLDOMDocument *, BSTR, IXMLDOMCDATASection **);
    HRESULT (*createProcessingInstruction)(IXMLDOMDocument *, BSTR, BSTR, IXMLDOMProcessingInstruction **);
    HRESULT (*createAttribute)(IXMLDOMDocument *, BSTR, IXMLDOMAttribute **);
    HRESULT (*createEntityReference)(IXMLDOMDocument *, BSTR, IXMLDOMEntityReference **);
    HRESULT (*getElementsByTagName)(IXMLDOMDocument *, BSTR, IXMLDOMNodeList **);
    HRESULT (*createNode)(IXMLDOMDocument *, VARIANT, BSTR, BSTR, IXMLDOMNode **);
    HRESULT (*nodeFromID)(IXMLDOMDocument *, BSTR, IXMLDOMNode **);
    HRESULT (*load)(IXMLDOMDocument *, VARIANT, VARIANT_BOOL *);
    HRESULT (*get_readyState)(IXMLDOMDocument *, long *);
    HRESULT (*get_parseError)(IXMLDOMDocument *, IXMLDOMParseError **);
    HRESULT (*get_url)(IXMLDOMDocument *, BSTR *);
    HRESULT (*get_async)(IXMLDOMDocument *, VARIANT_BOOL *);
    HRESULT (*put_async)(IXMLDOMDocument *, VARIANT_BOOL);
    HRESULT (*abort)(IXMLDOMDocument *);
    HRESULT (*loadXML)(IXMLDOMDocument *, BSTR, VARIANT_BOOL *);
    HRESULT (*save)(IXMLDOMDocument *, VARIANT);
    HRESULT (*get_validateOnParse)(IXMLDOMDocument *, VARIANT_BOOL *);
    HRESULT (*put_validateOnParse)(IXMLDOMDocument *, VARIANT_BOOL);
    HRESULT (*get_resolveExternals)(IXMLDOMDocument *, VARIANT_BOOL *);
    HRESULT (*put_resolveExternals)(IXMLDOMDocument *, VARIANT_BOOL);
    HRESULT (*get_preserveWhiteSpace)(IXMLDOMDocument *, VARIANT_BOOL *);
    HRESULT (*put_preserveWhiteSpace)(IXMLDOMDocument *, VARIANT_BOOL);
    HRESULT (*put_onreadystatechange)(IXMLDOMDocument *, VARIANT);
    HRESULT (*put_ondataavailable)(IXMLDOMDocument *, VARIANT);
    HRESULT (*put_ontransformnode)(IXMLDOMDocument *, VARIANT);
};

struct IXMLDOMElement {
    struct IXMLDOMElementVtbl *lpVtbl;
};

struct IXMLDOMElementVtbl {
    HRESULT (*QueryInterface)(IXMLDOMElement *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMElement *);
    ULONG (*Release)(IXMLDOMElement *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMElement *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMElement *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMElement *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMElement *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMElement *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMElement *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMElement *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMElement *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMElement *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMElement *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMElement *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMElement *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMElement *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMElement *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMElement *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMElement *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMElement *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMElement *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMElement *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMElement *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMElement *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMElement *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMElement *, BSTR *);
    HRESULT (*get_text)(IXMLDOMElement *, BSTR *);
    HRESULT (*put_text)(IXMLDOMElement *, BSTR);
    HRESULT (*get_specified)(IXMLDOMElement *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMElement *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMElement *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMElement *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMElement *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMElement *, BSTR);
    HRESULT (*get_xml)(IXMLDOMElement *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMElement *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMElement *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMElement *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMElement *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMElement *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMElement *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMElement *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMElement *, IXMLDOMNode *, VARIANT);
    HRESULT (*get_tagName)(IXMLDOMElement *, BSTR *);
    HRESULT (*getAttribute)(IXMLDOMElement *, BSTR, VARIANT *);
    HRESULT (*setAttribute)(IXMLDOMElement *, BSTR, VARIANT);
    HRESULT (*removeAttribute)(IXMLDOMElement *, BSTR);
    HRESULT (*getAttributeNode)(IXMLDOMElement *, BSTR, IXMLDOMAttribute **);
    HRESULT (*setAttributeNode)(IXMLDOMElement *, IXMLDOMAttribute *, IXMLDOMAttribute **);
    HRESULT (*removeAttributeNode)(IXMLDOMElement *, IXMLDOMAttribute *, IXMLDOMAttribute **);
    HRESULT (*getElementsByTagName)(IXMLDOMElement *, BSTR, IXMLDOMNodeList **);
    HRESULT (*normalize)(IXMLDOMElement *);
};

struct IXMLDOMEntity {
    struct IXMLDOMEntityVtbl *lpVtbl;
};

struct IXMLDOMEntityReference {
    struct IXMLDOMEntityReferenceVtbl *lpVtbl;
};

struct IXMLDOMEntityReferenceVtbl {
    HRESULT (*QueryInterface)(IXMLDOMEntityReference *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMEntityReference *);
    ULONG (*Release)(IXMLDOMEntityReference *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMEntityReference *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMEntityReference *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMEntityReference *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMEntityReference *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMEntityReference *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMEntityReference *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMEntityReference *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMEntityReference *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMEntityReference *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMEntityReference *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMEntityReference *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMEntityReference *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMEntityReference *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMEntityReference *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMEntityReference *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMEntityReference *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMEntityReference *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMEntityReference *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMEntityReference *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMEntityReference *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMEntityReference *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMEntityReference *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMEntityReference *, BSTR *);
    HRESULT (*get_text)(IXMLDOMEntityReference *, BSTR *);
    HRESULT (*put_text)(IXMLDOMEntityReference *, BSTR);
    HRESULT (*get_specified)(IXMLDOMEntityReference *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMEntityReference *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMEntityReference *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMEntityReference *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMEntityReference *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMEntityReference *, BSTR);
    HRESULT (*get_xml)(IXMLDOMEntityReference *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMEntityReference *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMEntityReference *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMEntityReference *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMEntityReference *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMEntityReference *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMEntityReference *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMEntityReference *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMEntityReference *, IXMLDOMNode *, VARIANT);
};

struct IXMLDOMEntityVtbl {
    HRESULT (*QueryInterface)(IXMLDOMEntity *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMEntity *);
    ULONG (*Release)(IXMLDOMEntity *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMEntity *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMEntity *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMEntity *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMEntity *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMEntity *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMEntity *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMEntity *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMEntity *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMEntity *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMEntity *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMEntity *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMEntity *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMEntity *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMEntity *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMEntity *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMEntity *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMEntity *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMEntity *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMEntity *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMEntity *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMEntity *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMEntity *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMEntity *, BSTR *);
    HRESULT (*get_text)(IXMLDOMEntity *, BSTR *);
    HRESULT (*put_text)(IXMLDOMEntity *, BSTR);
    HRESULT (*get_specified)(IXMLDOMEntity *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMEntity *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMEntity *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMEntity *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMEntity *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMEntity *, BSTR);
    HRESULT (*get_xml)(IXMLDOMEntity *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMEntity *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMEntity *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMEntity *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMEntity *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMEntity *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMEntity *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMEntity *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMEntity *, IXMLDOMNode *, VARIANT);
    HRESULT (*get_publicId)(IXMLDOMEntity *, VARIANT *);
    HRESULT (*get_systemId)(IXMLDOMEntity *, VARIANT *);
    HRESULT (*get_notationName)(IXMLDOMEntity *, BSTR *);
};

struct IXMLDOMImplementation {
    struct IXMLDOMImplementationVtbl *lpVtbl;
};

struct IXMLDOMImplementationVtbl {
    HRESULT (*QueryInterface)(IXMLDOMImplementation *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMImplementation *);
    ULONG (*Release)(IXMLDOMImplementation *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMImplementation *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMImplementation *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMImplementation *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMImplementation *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*hasFeature)(IXMLDOMImplementation *, BSTR, BSTR, VARIANT_BOOL *);
};

struct IXMLDOMNamedNodeMap {
    struct IXMLDOMNamedNodeMapVtbl *lpVtbl;
};

struct IXMLDOMNamedNodeMapVtbl {
    HRESULT (*QueryInterface)(IXMLDOMNamedNodeMap *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMNamedNodeMap *);
    ULONG (*Release)(IXMLDOMNamedNodeMap *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMNamedNodeMap *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMNamedNodeMap *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMNamedNodeMap *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMNamedNodeMap *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*getNamedItem)(IXMLDOMNamedNodeMap *, BSTR, IXMLDOMNode **);
    HRESULT (*setNamedItem)(IXMLDOMNamedNodeMap *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeNamedItem)(IXMLDOMNamedNodeMap *, BSTR, IXMLDOMNode **);
    HRESULT (*get_item)(IXMLDOMNamedNodeMap *, long, IXMLDOMNode **);
    HRESULT (*get_length)(IXMLDOMNamedNodeMap *, long *);
    HRESULT (*getQualifiedItem)(IXMLDOMNamedNodeMap *, BSTR, BSTR, IXMLDOMNode **);
    HRESULT (*removeQualifiedItem)(IXMLDOMNamedNodeMap *, BSTR, BSTR, IXMLDOMNode **);
    HRESULT (*nextNode)(IXMLDOMNamedNodeMap *, IXMLDOMNode **);
    HRESULT (*reset)(IXMLDOMNamedNodeMap *);
    HRESULT (*get__newEnum)(IXMLDOMNamedNodeMap *, IUnknown **);
};

struct IXMLDOMNode {
    struct IXMLDOMNodeVtbl *lpVtbl;
};

struct IXMLDOMNodeList {
    struct IXMLDOMNodeListVtbl *lpVtbl;
};

struct IXMLDOMNodeListVtbl {
    HRESULT (*QueryInterface)(IXMLDOMNodeList *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMNodeList *);
    ULONG (*Release)(IXMLDOMNodeList *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMNodeList *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMNodeList *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMNodeList *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMNodeList *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_item)(IXMLDOMNodeList *, long, IXMLDOMNode **);
    HRESULT (*get_length)(IXMLDOMNodeList *, long *);
    HRESULT (*nextNode)(IXMLDOMNodeList *, IXMLDOMNode **);
    HRESULT (*reset)(IXMLDOMNodeList *);
    HRESULT (*get__newEnum)(IXMLDOMNodeList *, IUnknown **);
};

struct IXMLDOMNodeVtbl {
    HRESULT (*QueryInterface)(IXMLDOMNode *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMNode *);
    ULONG (*Release)(IXMLDOMNode *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMNode *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMNode *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMNode *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMNode *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMNode *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMNode *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMNode *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMNode *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMNode *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMNode *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMNode *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMNode *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMNode *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMNode *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMNode *, BSTR *);
    HRESULT (*get_text)(IXMLDOMNode *, BSTR *);
    HRESULT (*put_text)(IXMLDOMNode *, BSTR);
    HRESULT (*get_specified)(IXMLDOMNode *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMNode *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMNode *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMNode *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMNode *, BSTR);
    HRESULT (*get_xml)(IXMLDOMNode *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMNode *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMNode *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMNode *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMNode *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMNode *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMNode *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMNode *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMNode *, IXMLDOMNode *, VARIANT);
};

struct IXMLDOMNotation {
    struct IXMLDOMNotationVtbl *lpVtbl;
};

struct IXMLDOMNotationVtbl {
    HRESULT (*QueryInterface)(IXMLDOMNotation *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMNotation *);
    ULONG (*Release)(IXMLDOMNotation *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMNotation *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMNotation *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMNotation *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMNotation *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMNotation *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMNotation *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMNotation *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMNotation *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMNotation *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMNotation *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMNotation *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMNotation *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMNotation *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMNotation *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMNotation *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMNotation *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMNotation *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMNotation *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMNotation *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMNotation *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMNotation *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMNotation *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMNotation *, BSTR *);
    HRESULT (*get_text)(IXMLDOMNotation *, BSTR *);
    HRESULT (*put_text)(IXMLDOMNotation *, BSTR);
    HRESULT (*get_specified)(IXMLDOMNotation *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMNotation *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMNotation *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMNotation *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMNotation *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMNotation *, BSTR);
    HRESULT (*get_xml)(IXMLDOMNotation *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMNotation *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMNotation *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMNotation *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMNotation *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMNotation *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMNotation *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMNotation *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMNotation *, IXMLDOMNode *, VARIANT);
    HRESULT (*get_publicId)(IXMLDOMNotation *, VARIANT *);
    HRESULT (*get_systemId)(IXMLDOMNotation *, VARIANT *);
};

struct IXMLDOMParseError {
    struct IXMLDOMParseErrorVtbl *lpVtbl;
};

struct IXMLDOMParseErrorVtbl {
    HRESULT (*QueryInterface)(IXMLDOMParseError *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMParseError *);
    ULONG (*Release)(IXMLDOMParseError *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMParseError *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMParseError *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMParseError *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMParseError *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_errorCode)(IXMLDOMParseError *, long *);
    HRESULT (*get_url)(IXMLDOMParseError *, BSTR *);
    HRESULT (*get_reason)(IXMLDOMParseError *, BSTR *);
    HRESULT (*get_srcText)(IXMLDOMParseError *, BSTR *);
    HRESULT (*get_line)(IXMLDOMParseError *, long *);
    HRESULT (*get_linepos)(IXMLDOMParseError *, long *);
    HRESULT (*get_filepos)(IXMLDOMParseError *, long *);
};

struct IXMLDOMProcessingInstruction {
    struct IXMLDOMProcessingInstructionVtbl *lpVtbl;
};

struct IXMLDOMProcessingInstructionVtbl {
    HRESULT (*QueryInterface)(IXMLDOMProcessingInstruction *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMProcessingInstruction *);
    ULONG (*Release)(IXMLDOMProcessingInstruction *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMProcessingInstruction *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMProcessingInstruction *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMProcessingInstruction *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMProcessingInstruction *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMProcessingInstruction *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMProcessingInstruction *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMProcessingInstruction *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMProcessingInstruction *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMProcessingInstruction *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMProcessingInstruction *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMProcessingInstruction *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMProcessingInstruction *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMProcessingInstruction *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMProcessingInstruction *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMProcessingInstruction *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMProcessingInstruction *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMProcessingInstruction *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMProcessingInstruction *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMProcessingInstruction *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMProcessingInstruction *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMProcessingInstruction *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMProcessingInstruction *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMProcessingInstruction *, BSTR *);
    HRESULT (*get_text)(IXMLDOMProcessingInstruction *, BSTR *);
    HRESULT (*put_text)(IXMLDOMProcessingInstruction *, BSTR);
    HRESULT (*get_specified)(IXMLDOMProcessingInstruction *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMProcessingInstruction *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMProcessingInstruction *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMProcessingInstruction *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMProcessingInstruction *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMProcessingInstruction *, BSTR);
    HRESULT (*get_xml)(IXMLDOMProcessingInstruction *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMProcessingInstruction *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMProcessingInstruction *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMProcessingInstruction *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMProcessingInstruction *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMProcessingInstruction *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMProcessingInstruction *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMProcessingInstruction *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMProcessingInstruction *, IXMLDOMNode *, VARIANT);
    HRESULT (*get_target)(IXMLDOMProcessingInstruction *, BSTR *);
    HRESULT (*get_data)(IXMLDOMProcessingInstruction *, BSTR *);
    HRESULT (*put_data)(IXMLDOMProcessingInstruction *, BSTR);
};

struct IXMLDOMText {
    struct IXMLDOMTextVtbl *lpVtbl;
};

struct IXMLDOMTextVtbl {
    HRESULT (*QueryInterface)(IXMLDOMText *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDOMText *);
    ULONG (*Release)(IXMLDOMText *);
    HRESULT (*GetTypeInfoCount)(IXMLDOMText *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDOMText *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDOMText *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDOMText *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXMLDOMText *, BSTR *);
    HRESULT (*get_nodeValue)(IXMLDOMText *, VARIANT *);
    HRESULT (*put_nodeValue)(IXMLDOMText *, VARIANT);
    HRESULT (*get_nodeType)(IXMLDOMText *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXMLDOMText *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXMLDOMText *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXMLDOMText *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXMLDOMText *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXMLDOMText *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXMLDOMText *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXMLDOMText *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXMLDOMText *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXMLDOMText *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXMLDOMText *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXMLDOMText *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXMLDOMText *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXMLDOMText *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXMLDOMText *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXMLDOMText *, BSTR *);
    HRESULT (*get_text)(IXMLDOMText *, BSTR *);
    HRESULT (*put_text)(IXMLDOMText *, BSTR);
    HRESULT (*get_specified)(IXMLDOMText *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXMLDOMText *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXMLDOMText *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXMLDOMText *, VARIANT);
    HRESULT (*get_dataType)(IXMLDOMText *, VARIANT *);
    HRESULT (*put_dataType)(IXMLDOMText *, BSTR);
    HRESULT (*get_xml)(IXMLDOMText *, BSTR *);
    HRESULT (*transformNode)(IXMLDOMText *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXMLDOMText *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXMLDOMText *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXMLDOMText *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXMLDOMText *, BSTR *);
    HRESULT (*get_prefix)(IXMLDOMText *, BSTR *);
    HRESULT (*get_baseName)(IXMLDOMText *, BSTR *);
    HRESULT (*transformNodeToObject)(IXMLDOMText *, IXMLDOMNode *, VARIANT);
    HRESULT (*get_data)(IXMLDOMText *, BSTR *);
    HRESULT (*put_data)(IXMLDOMText *, BSTR);
    HRESULT (*get_length)(IXMLDOMText *, long *);
    HRESULT (*substringData)(IXMLDOMText *, long, long, BSTR *);
    HRESULT (*appendData)(IXMLDOMText *, BSTR);
    HRESULT (*insertData)(IXMLDOMText *, long, BSTR);
    HRESULT (*deleteData)(IXMLDOMText *, long, long);
    HRESULT (*replaceData)(IXMLDOMText *, long, long, BSTR);
    HRESULT (*splitText)(IXMLDOMText *, long, IXMLDOMText **);
};

struct IXMLDSOControl {
    struct IXMLDSOControlVtbl *lpVtbl;
};

struct IXMLDSOControlVtbl {
    HRESULT (*QueryInterface)(IXMLDSOControl *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDSOControl *);
    ULONG (*Release)(IXMLDSOControl *);
    HRESULT (*GetTypeInfoCount)(IXMLDSOControl *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDSOControl *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDSOControl *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDSOControl *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_XMLDocument)(IXMLDSOControl *, IXMLDOMDocument **);
    HRESULT (*put_XMLDocument)(IXMLDSOControl *, IXMLDOMDocument *);
    HRESULT (*get_JavaDSOCompatible)(IXMLDSOControl *, BOOL *);
    HRESULT (*put_JavaDSOCompatible)(IXMLDSOControl *, BOOL);
    HRESULT (*get_readyState)(IXMLDSOControl *, long *);
};

struct IXMLDocument {
    struct IXMLDocumentVtbl *lpVtbl;
};

struct IXMLDocument2 {
    struct IXMLDocument2Vtbl *lpVtbl;
};

struct IXMLDocument2Vtbl {
    HRESULT (*QueryInterface)(IXMLDocument2 *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDocument2 *);
    ULONG (*Release)(IXMLDocument2 *);
    HRESULT (*GetTypeInfoCount)(IXMLDocument2 *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDocument2 *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDocument2 *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDocument2 *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_root)(IXMLDocument2 *, IXMLElement2 **);
    HRESULT (*get_fileSize)(IXMLDocument2 *, BSTR *);
    HRESULT (*get_fileModifiedDate)(IXMLDocument2 *, BSTR *);
    HRESULT (*get_fileUpdatedDate)(IXMLDocument2 *, BSTR *);
    HRESULT (*get_URL)(IXMLDocument2 *, BSTR *);
    HRESULT (*put_URL)(IXMLDocument2 *, BSTR);
    HRESULT (*get_mimeType)(IXMLDocument2 *, BSTR *);
    HRESULT (*get_readyState)(IXMLDocument2 *, long *);
    HRESULT (*get_charset)(IXMLDocument2 *, BSTR *);
    HRESULT (*put_charset)(IXMLDocument2 *, BSTR);
    HRESULT (*get_version)(IXMLDocument2 *, BSTR *);
    HRESULT (*get_doctype)(IXMLDocument2 *, BSTR *);
    HRESULT (*get_dtdURL)(IXMLDocument2 *, BSTR *);
    HRESULT (*createElement)(IXMLDocument2 *, VARIANT, VARIANT, IXMLElement2 **);
    HRESULT (*get_async)(IXMLDocument2 *, VARIANT_BOOL *);
    HRESULT (*put_async)(IXMLDocument2 *, VARIANT_BOOL);
};

struct IXMLDocumentVtbl {
    HRESULT (*QueryInterface)(IXMLDocument *, const IID *const, void **);
    ULONG (*AddRef)(IXMLDocument *);
    ULONG (*Release)(IXMLDocument *);
    HRESULT (*GetTypeInfoCount)(IXMLDocument *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLDocument *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLDocument *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLDocument *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_root)(IXMLDocument *, IXMLElement **);
    HRESULT (*get_fileSize)(IXMLDocument *, BSTR *);
    HRESULT (*get_fileModifiedDate)(IXMLDocument *, BSTR *);
    HRESULT (*get_fileUpdatedDate)(IXMLDocument *, BSTR *);
    HRESULT (*get_URL)(IXMLDocument *, BSTR *);
    HRESULT (*put_URL)(IXMLDocument *, BSTR);
    HRESULT (*get_mimeType)(IXMLDocument *, BSTR *);
    HRESULT (*get_readyState)(IXMLDocument *, long *);
    HRESULT (*get_charset)(IXMLDocument *, BSTR *);
    HRESULT (*put_charset)(IXMLDocument *, BSTR);
    HRESULT (*get_version)(IXMLDocument *, BSTR *);
    HRESULT (*get_doctype)(IXMLDocument *, BSTR *);
    HRESULT (*get_dtdURL)(IXMLDocument *, BSTR *);
    HRESULT (*createElement)(IXMLDocument *, VARIANT, VARIANT, IXMLElement **);
};

struct IXMLElement {
    struct IXMLElementVtbl *lpVtbl;
};

struct IXMLElement2 {
    struct IXMLElement2Vtbl *lpVtbl;
};

struct IXMLElement2Vtbl {
    HRESULT (*QueryInterface)(IXMLElement2 *, const IID *const, void **);
    ULONG (*AddRef)(IXMLElement2 *);
    ULONG (*Release)(IXMLElement2 *);
    HRESULT (*GetTypeInfoCount)(IXMLElement2 *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLElement2 *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLElement2 *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLElement2 *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_tagName)(IXMLElement2 *, BSTR *);
    HRESULT (*put_tagName)(IXMLElement2 *, BSTR);
    HRESULT (*get_parent)(IXMLElement2 *, IXMLElement2 **);
    HRESULT (*setAttribute)(IXMLElement2 *, BSTR, VARIANT);
    HRESULT (*getAttribute)(IXMLElement2 *, BSTR, VARIANT *);
    HRESULT (*removeAttribute)(IXMLElement2 *, BSTR);
    HRESULT (*get_children)(IXMLElement2 *, IXMLElementCollection **);
    HRESULT (*get_type)(IXMLElement2 *, long *);
    HRESULT (*get_text)(IXMLElement2 *, BSTR *);
    HRESULT (*put_text)(IXMLElement2 *, BSTR);
    HRESULT (*addChild)(IXMLElement2 *, IXMLElement2 *, long, long);
    HRESULT (*removeChild)(IXMLElement2 *, IXMLElement2 *);
    HRESULT (*get_attributes)(IXMLElement2 *, IXMLElementCollection **);
};

struct IXMLElementCollection {
    struct IXMLElementCollectionVtbl *lpVtbl;
};

struct IXMLElementCollectionVtbl {
    HRESULT (*QueryInterface)(IXMLElementCollection *, const IID *const, void **);
    ULONG (*AddRef)(IXMLElementCollection *);
    ULONG (*Release)(IXMLElementCollection *);
    HRESULT (*GetTypeInfoCount)(IXMLElementCollection *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLElementCollection *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLElementCollection *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLElementCollection *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*put_length)(IXMLElementCollection *, long);
    HRESULT (*get_length)(IXMLElementCollection *, long *);
    HRESULT (*get__newEnum)(IXMLElementCollection *, IUnknown **);
    HRESULT (*item)(IXMLElementCollection *, VARIANT, VARIANT, IDispatch **);
};

struct IXMLElementVtbl {
    HRESULT (*QueryInterface)(IXMLElement *, const IID *const, void **);
    ULONG (*AddRef)(IXMLElement *);
    ULONG (*Release)(IXMLElement *);
    HRESULT (*GetTypeInfoCount)(IXMLElement *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLElement *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLElement *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLElement *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_tagName)(IXMLElement *, BSTR *);
    HRESULT (*put_tagName)(IXMLElement *, BSTR);
    HRESULT (*get_parent)(IXMLElement *, IXMLElement **);
    HRESULT (*setAttribute)(IXMLElement *, BSTR, VARIANT);
    HRESULT (*getAttribute)(IXMLElement *, BSTR, VARIANT *);
    HRESULT (*removeAttribute)(IXMLElement *, BSTR);
    HRESULT (*get_children)(IXMLElement *, IXMLElementCollection **);
    HRESULT (*get_type)(IXMLElement *, long *);
    HRESULT (*get_text)(IXMLElement *, BSTR *);
    HRESULT (*put_text)(IXMLElement *, BSTR);
    HRESULT (*addChild)(IXMLElement *, IXMLElement *, long, long);
    HRESULT (*removeChild)(IXMLElement *, IXMLElement *);
};

struct IXMLError {
    struct IXMLErrorVtbl *lpVtbl;
};

struct IXMLErrorVtbl {
    HRESULT (*QueryInterface)(IXMLError *, const IID *const, void **);
    ULONG (*AddRef)(IXMLError *);
    ULONG (*Release)(IXMLError *);
    HRESULT (*GetErrorInfo)(IXMLError *, XML_ERROR *);
};

struct IXMLHttpRequest {
    struct IXMLHttpRequestVtbl *lpVtbl;
};

struct IXMLHttpRequestVtbl {
    HRESULT (*QueryInterface)(IXMLHttpRequest *, const IID *const, void **);
    ULONG (*AddRef)(IXMLHttpRequest *);
    ULONG (*Release)(IXMLHttpRequest *);
    HRESULT (*GetTypeInfoCount)(IXMLHttpRequest *, UINT *);
    HRESULT (*GetTypeInfo)(IXMLHttpRequest *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXMLHttpRequest *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXMLHttpRequest *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*open)(IXMLHttpRequest *, BSTR, BSTR, VARIANT, VARIANT, VARIANT);
    HRESULT (*setRequestHeader)(IXMLHttpRequest *, BSTR, BSTR);
    HRESULT (*getResponseHeader)(IXMLHttpRequest *, BSTR, BSTR *);
    HRESULT (*getAllResponseHeaders)(IXMLHttpRequest *, BSTR *);
    HRESULT (*send)(IXMLHttpRequest *, VARIANT);
    HRESULT (*abort)(IXMLHttpRequest *);
    HRESULT (*get_status)(IXMLHttpRequest *, long *);
    HRESULT (*get_statusText)(IXMLHttpRequest *, BSTR *);
    HRESULT (*get_responseXML)(IXMLHttpRequest *, IDispatch **);
    HRESULT (*get_responseText)(IXMLHttpRequest *, BSTR *);
    HRESULT (*get_responseBody)(IXMLHttpRequest *, VARIANT *);
    HRESULT (*get_responseStream)(IXMLHttpRequest *, VARIANT *);
    HRESULT (*get_readyState)(IXMLHttpRequest *, long *);
    HRESULT (*put_onreadystatechange)(IXMLHttpRequest *, IDispatch *);
};

struct IXTLRuntime {
    struct IXTLRuntimeVtbl *lpVtbl;
};

struct IXTLRuntimeVtbl {
    HRESULT (*QueryInterface)(IXTLRuntime *, const IID *const, void **);
    ULONG (*AddRef)(IXTLRuntime *);
    ULONG (*Release)(IXTLRuntime *);
    HRESULT (*GetTypeInfoCount)(IXTLRuntime *, UINT *);
    HRESULT (*GetTypeInfo)(IXTLRuntime *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(IXTLRuntime *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(IXTLRuntime *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
    HRESULT (*get_nodeName)(IXTLRuntime *, BSTR *);
    HRESULT (*get_nodeValue)(IXTLRuntime *, VARIANT *);
    HRESULT (*put_nodeValue)(IXTLRuntime *, VARIANT);
    HRESULT (*get_nodeType)(IXTLRuntime *, DOMNodeType *);
    HRESULT (*get_parentNode)(IXTLRuntime *, IXMLDOMNode **);
    HRESULT (*get_childNodes)(IXTLRuntime *, IXMLDOMNodeList **);
    HRESULT (*get_firstChild)(IXTLRuntime *, IXMLDOMNode **);
    HRESULT (*get_lastChild)(IXTLRuntime *, IXMLDOMNode **);
    HRESULT (*get_previousSibling)(IXTLRuntime *, IXMLDOMNode **);
    HRESULT (*get_nextSibling)(IXTLRuntime *, IXMLDOMNode **);
    HRESULT (*get_attributes)(IXTLRuntime *, IXMLDOMNamedNodeMap **);
    HRESULT (*insertBefore)(IXTLRuntime *, IXMLDOMNode *, VARIANT, IXMLDOMNode **);
    HRESULT (*replaceChild)(IXTLRuntime *, IXMLDOMNode *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*removeChild)(IXTLRuntime *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*appendChild)(IXTLRuntime *, IXMLDOMNode *, IXMLDOMNode **);
    HRESULT (*hasChildNodes)(IXTLRuntime *, VARIANT_BOOL *);
    HRESULT (*get_ownerDocument)(IXTLRuntime *, IXMLDOMDocument **);
    HRESULT (*cloneNode)(IXTLRuntime *, VARIANT_BOOL, IXMLDOMNode **);
    HRESULT (*get_nodeTypeString)(IXTLRuntime *, BSTR *);
    HRESULT (*get_text)(IXTLRuntime *, BSTR *);
    HRESULT (*put_text)(IXTLRuntime *, BSTR);
    HRESULT (*get_specified)(IXTLRuntime *, VARIANT_BOOL *);
    HRESULT (*get_definition)(IXTLRuntime *, IXMLDOMNode **);
    HRESULT (*get_nodeTypedValue)(IXTLRuntime *, VARIANT *);
    HRESULT (*put_nodeTypedValue)(IXTLRuntime *, VARIANT);
    HRESULT (*get_dataType)(IXTLRuntime *, VARIANT *);
    HRESULT (*put_dataType)(IXTLRuntime *, BSTR);
    HRESULT (*get_xml)(IXTLRuntime *, BSTR *);
    HRESULT (*transformNode)(IXTLRuntime *, IXMLDOMNode *, BSTR *);
    HRESULT (*selectNodes)(IXTLRuntime *, BSTR, IXMLDOMNodeList **);
    HRESULT (*selectSingleNode)(IXTLRuntime *, BSTR, IXMLDOMNode **);
    HRESULT (*get_parsed)(IXTLRuntime *, VARIANT_BOOL *);
    HRESULT (*get_namespaceURI)(IXTLRuntime *, BSTR *);
    HRESULT (*get_prefix)(IXTLRuntime *, BSTR *);
    HRESULT (*get_baseName)(IXTLRuntime *, BSTR *);
    HRESULT (*transformNodeToObject)(IXTLRuntime *, IXMLDOMNode *, VARIANT);
    HRESULT (*uniqueID)(IXTLRuntime *, IXMLDOMNode *, long *);
    HRESULT (*depth)(IXTLRuntime *, IXMLDOMNode *, long *);
    HRESULT (*childNumber)(IXTLRuntime *, IXMLDOMNode *, long *);
    HRESULT (*ancestorChildNumber)(IXTLRuntime *, BSTR, IXMLDOMNode *, long *);
    HRESULT (*absoluteChildNumber)(IXTLRuntime *, IXMLDOMNode *, long *);
    HRESULT (*formatIndex)(IXTLRuntime *, long, BSTR, BSTR *);
    HRESULT (*formatNumber)(IXTLRuntime *, double, BSTR, BSTR *);
    HRESULT (*formatDate)(IXTLRuntime *, VARIANT, BSTR, VARIANT, BSTR *);
    HRESULT (*formatTime)(IXTLRuntime *, VARIANT, BSTR, VARIANT, BSTR *);
};

struct XMLDOMDocumentEvents {
    struct XMLDOMDocumentEventsVtbl *lpVtbl;
};

struct XMLDOMDocumentEventsVtbl {
    HRESULT (*QueryInterface)(XMLDOMDocumentEvents *, const IID *const, void **);
    ULONG (*AddRef)(XMLDOMDocumentEvents *);
    ULONG (*Release)(XMLDOMDocumentEvents *);
    HRESULT (*GetTypeInfoCount)(XMLDOMDocumentEvents *, UINT *);
    HRESULT (*GetTypeInfo)(XMLDOMDocumentEvents *, UINT, LCID, ITypeInfo **);
    HRESULT (*GetIDsOfNames)(XMLDOMDocumentEvents *, const IID *const, LPOLESTR *, UINT, LCID, DISPID *);
    HRESULT (*Invoke)(XMLDOMDocumentEvents *, DISPID, const IID *const, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);
};

struct _xml_error {
    unsigned int _nLine;
    BSTR _pchBuf;
    unsigned int _cchBuf;
    unsigned int _ich;
    BSTR _pszFound;
    BSTR _pszExpected;
    DWORD _reserved1;
    DWORD _reserved2;
};


#ifdef __cplusplus
}
#endif

#endif
