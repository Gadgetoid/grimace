#ifndef GRIMACE_SDK_ADDRSTOR_H
#define GRIMACE_SDK_ADDRSTOR_H

#include <grimace/sdk/addrmapi.h>

#ifdef __cplusplus
extern "C" {
#endif

struct _AddressCard;
typedef struct _AddressCard AddressCard;
/**
 * Adds an address card to the address book.
 *
 * @param pac Address-card data to add.
 * @param poidCard Receives the new card's object identifier.
 * @param pindex Receives the card's index.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL AddAddressCard(AddressCard *pac, CEOID *poidCard, int *pindex);
/**
 * Closes the address book.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
void CloseAddressBook(void);
/**
 * Creates the address book with the specified property tags.
 *
 * @param rghhProps Property tags to include.
 * @param numProps Number of property tags.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL CreateAddressBook(HHPRTAG *rghhProps, int numProps);
/**
 * Deletes an address card by its object identifier.
 *
 * @param oidCard Object identifier of the card to delete.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL DeleteAddressCard(CEOID oidCard);
/**
 * Finds the first address-book entry matching a property value.
 *
 * Use FFE_CONTAINS to match text contained in the field.
 *
 * @param szFind Text to find.
 * @param hhProp Property tag to search.
 * @param pindex Receives the matching card's index.
 * @param dwFlags Search flags.
 * @return Object identifier of the matching card.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
CEOID FindFirstEntry(TCHAR *szFind, HHPRTAG hhProp, int *pindex, DWORD dwFlags);
/**
 * Frees data allocated for an address card.
 *
 * Use this to release card data returned or allocated by the address-store
 * functions.
 *
 * @param pac Address card to free.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
void FreeAddressCard(AddressCard *pac);
/**
 * Retrieves the index of an address card.
 *
 * @param oidCard Card object identifier.
 * @return Card index.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
int GetAddressCardIndex(CEOID oidCard);
/**
 * Retrieves the object identifier of an address card by index.
 *
 * @param nCard Card index.
 * @return Card object identifier.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
CEOID GetAddressCardOid(int nCard);
/**
 * Retrieves selected properties for an address card.
 *
 * @param oidCard Card object identifier.
 * @param pac Receives the card properties.
 * @param numRequestedProps Number of properties to retrieve.
 * @param rghhProp Property tags to retrieve.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL GetAddressCardProperties(CEOID oidCard, AddressCard *pac, int numRequestedProps, HHPRTAG *rghhProp);
/**
 * Retrieves the property tags and count used for address-book columns.
 *
 * @param propList Receives the column property tags.
 * @param pColumns Receives the number of columns.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL GetColumnProperties(HHPRTAG *propList, int *pColumns);
/**
 * Finds an address-book entry matching text in a specified field.
 *
 * @param szMatch Text to match.
 * @param pBufSize Buffer-size value used by the search.
 * @param szField Field to search.
 * @param poidMatch Receives the matching card's object identifier.
 * @param phhMatch Receives the matching property tag.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL GetMatchingEntry(TCHAR *szMatch, int *pBufSize, TCHAR *szField, CEOID *poidMatch, HHPRTAG *phhMatch);
/**
 * Returns the number of address cards in the store.
 *
 * @return Number of cards.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
int GetNumberOfAddressCards(void);
struct _PropertyDataStruct;
typedef struct _PropertyDataStruct PropertyDataStruct;
/**
 * Retrieves metadata for an address-book property.
 *
 * `fFlag` selects whether `uValue` identifies a property, index or name;
 * the result includes the property name, type and tag.
 *
 * @param fFlag GPDS_PROPERTY, GPDS_INDEX or GPDS_NAME.
 * @param uValue Property identifier, index or name value selected by `fFlag`.
 * @param ppds Receives the property metadata.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
int GetPropertyDataStruct(int fFlag, ULONG uValue, PropertyDataStruct *ppds);
/**
 * Retrieves the property tag used for the selected sort order.
 *
 * @param fDatabaseSort Selects whether to retrieve the database sort order.
 * @return Sort-order property tag.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
HHPRTAG GetSortOrder(BOOL fDatabaseSort);
/**
 * Updates an existing address card.
 *
 * @param pac Updated address-card data.
 * @param oidCard Object identifier of the card to update.
 * @param pindex Receives the card's index.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL ModifyAddressCard(AddressCard *pac, CEOID oidCard, int *pindex);
/**
 * Opens the address book for a window and property tag.
 *
 * @param hwnd Window associated with the address book.
 * @param hhProp Property tag used to open the address book.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL OpenAddressBook(HWND hwnd, HHPRTAG hhProp);
/**
 * Opens an address card and retrieves its data.
 *
 * Use OAC_ALLOCATE to request allocated card data. Release allocated data
 * with FreeAddressCard.
 *
 * @param oidCard Card object identifier.
 * @param pac Receives the address-card data.
 * @param uFlags OpenAddressCard flags.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL OpenAddressCard(CEOID oidCard, AddressCard *pac, ULONG uFlags);
/**
 * Recounts address cards during replication.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
void RecountCards(void);
/**
 * Sets the property tags and count used for address-book columns.
 *
 * @param propList Column property tags.
 * @param nColumns Number of column properties.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL SetColumnProperties(HHPRTAG *propList, int nColumns);
void SetMask(AddressCard *pac, HHPRTAG hhProp);
/**
 * Sets the address-book sort-order property.
 *
 * @param hhProp Property tag to use for sorting.
 * @return TRUE on success, FALSE on failure.
 *
 * @note Windows CE 1.0 and 3.0 only.
 */
BOOL SetSortOrder(HHPRTAG hhProp);
struct _AddressCard {
    SYSTEMTIME stBirthday;
    SYSTEMTIME stAnniversary;
    TCHAR *pszBusinessFax;
    TCHAR *pszCompany;
    TCHAR *pszDepartment;
    TCHAR *pszEmail;
    TCHAR *pszMobilePhone;
    TCHAR *pszOfficeLocation;
    TCHAR *pszPager;
    TCHAR *pszWorkPhone;
    TCHAR *pszTitle;
    TCHAR *pszHomePhone;
    TCHAR *pszEmail2;
    TCHAR *pszSpouse;
    TCHAR *pszNotes;
    TCHAR *pszEmail3;
    TCHAR *pszHomePhone2;
    TCHAR *pszHomeFax;
    TCHAR *pszCarPhone;
    TCHAR *pszAssistant;
    TCHAR *pszAssistantPhone;
    TCHAR *pszChildren;
    TCHAR *pszCategory;
    TCHAR *pszWebPage;
    TCHAR *pszWorkPhone2;
    TCHAR *pszNamePrefix;
    TCHAR *pszGivenName;
    TCHAR *pszMiddleName;
    TCHAR *pszSurname;
    TCHAR *pszGeneration;
    TCHAR *pszHomeAddrStreet;
    TCHAR *pszHomeAddrCity;
    TCHAR *pszHomeAddrState;
    TCHAR *pszHomeAddrPostalCode;
    TCHAR *pszHomeAddrCountry;
    TCHAR *pszOtherAddrStreet;
    TCHAR *pszOtherAddrCity;
    TCHAR *pszOtherAddrState;
    TCHAR *pszOtherAddrPostalCode;
    TCHAR *pszOtherAddrCountry;
    TCHAR *pszOfficeAddrStreet;
    TCHAR *pszOfficeAddrCity;
    TCHAR *pszOfficeAddrState;
    TCHAR *pszOfficeAddrPostalCode;
    TCHAR *pszOfficeAddrCountry;
    BYTE rgbReserved[84];
};

struct _PropertyDataStruct {
    TCHAR *pszReserved;
    TCHAR *pszPropertyName;
    ULONG uPropType;
    HHPRTAG hhProp;
};


#ifdef __cplusplus
}
#endif

#endif
