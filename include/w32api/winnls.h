#ifndef _WINNLS_H
#define _WINNLS_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifndef WINBASEAPI
#ifdef __W32API_USE_DLLIMPORT__
#define WINBASEAPI DECLSPEC_IMPORT
#else
#define WINBASEAPI
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_LEADBYTES 	12
#define MAX_DEFAULTCHAR	2
#define LOCALE_NOUSEROVERRIDE	0x80000000
#define LOCALE_USE_CP_ACP	0x40000000
#if (WINVER >= 0x0400)
#define LOCALE_RETURN_NUMBER	0x20000000
#endif
#define LOCALE_ILANGUAGE	1
#define LOCALE_SLANGUAGE	2
#define LOCALE_SENGLANGUAGE	0x1001
#define LOCALE_SABBREVLANGNAME	3
#define LOCALE_SNATIVELANGNAME	4
#define LOCALE_ICOUNTRY	5
#define LOCALE_SCOUNTRY	6
#define LOCALE_SENGCOUNTRY	0x1002
#define LOCALE_SABBREVCTRYNAME	7
#define LOCALE_SNATIVECTRYNAME	8
#define LOCALE_IDEFAULTLANGUAGE	9
#define LOCALE_IDEFAULTCOUNTRY	10
#define LOCALE_IDEFAULTCODEPAGE	11
#define LOCALE_IDEFAULTANSICODEPAGE 0x1004
#define LOCALE_SLIST	12
#define LOCALE_IMEASURE	13
#define LOCALE_SDECIMAL	14
#define LOCALE_STHOUSAND	15
#define LOCALE_SGROUPING	16
#define LOCALE_IDIGITS	17
#define LOCALE_ILZERO	18
#define LOCALE_INEGNUMBER	0x1010
#define LOCALE_SNATIVEDIGITS	19
#define LOCALE_SCURRENCY	20
#define LOCALE_SINTLSYMBOL	21
#define LOCALE_SMONDECIMALSEP	22
#define LOCALE_SMONTHOUSANDSEP	23
#define LOCALE_SMONGROUPING	24
#define LOCALE_ICURRDIGITS	25
#define LOCALE_IINTLCURRDIGITS	26
#define LOCALE_ICURRENCY	27
#define LOCALE_INEGCURR	28
#define LOCALE_SDATE	29
#define LOCALE_STIME	30
#define LOCALE_SSHORTDATE	31
#define LOCALE_SLONGDATE	32
#define LOCALE_STIMEFORMAT	0x1003
#define LOCALE_IDATE	33
#define LOCALE_ILDATE	34
#define LOCALE_ITIME	35
#define LOCALE_ITIMEMARKPOSN	0x1005
#define LOCALE_ICENTURY	36
#define LOCALE_ITLZERO	37
#define LOCALE_IDAYLZERO	38
#define LOCALE_IMONLZERO	39
#define LOCALE_S1159	40
#define LOCALE_S2359	41
#define LOCALE_ICALENDARTYPE	0x1009
#define LOCALE_IOPTIONALCALENDAR	0x100B
#define LOCALE_IFIRSTDAYOFWEEK	0x100C
#define LOCALE_IFIRSTWEEKOFYEAR	0x100D
#define LOCALE_SDAYNAME1	42
#define LOCALE_SDAYNAME2	43
#define LOCALE_SDAYNAME3	44
#define LOCALE_SDAYNAME4	45
#define LOCALE_SDAYNAME5	46
#define LOCALE_SDAYNAME6	47
#define LOCALE_SDAYNAME7	48
#define LOCALE_SABBREVDAYNAME1	49
#define LOCALE_SABBREVDAYNAME2	50
#define LOCALE_SABBREVDAYNAME3	51
#define LOCALE_SABBREVDAYNAME4	52
#define LOCALE_SABBREVDAYNAME5	53
#define LOCALE_SABBREVDAYNAME6	54
#define LOCALE_SABBREVDAYNAME7	55
#define LOCALE_SMONTHNAME1	56
#define LOCALE_SMONTHNAME2	57
#define LOCALE_SMONTHNAME3	58
#define LOCALE_SMONTHNAME4	59
#define LOCALE_SMONTHNAME5	60
#define LOCALE_SMONTHNAME6	61
#define LOCALE_SMONTHNAME7	62
#define LOCALE_SMONTHNAME8	63
#define LOCALE_SMONTHNAME9	64
#define LOCALE_SMONTHNAME10	65
#define LOCALE_SMONTHNAME11	66
#define LOCALE_SMONTHNAME12	67
#define LOCALE_SMONTHNAME13	0x100E
#define LOCALE_SABBREVMONTHNAME1	68
#define LOCALE_SABBREVMONTHNAME2	69
#define LOCALE_SABBREVMONTHNAME3	70
#define LOCALE_SABBREVMONTHNAME4	71
#define LOCALE_SABBREVMONTHNAME5	72
#define LOCALE_SABBREVMONTHNAME6	73
#define LOCALE_SABBREVMONTHNAME7	74
#define LOCALE_SABBREVMONTHNAME8	75
#define LOCALE_SABBREVMONTHNAME9	76
#define LOCALE_SABBREVMONTHNAME10	77
#define LOCALE_SABBREVMONTHNAME11	78
#define LOCALE_SABBREVMONTHNAME12	79
#define LOCALE_SABBREVMONTHNAME13	0x100F
#define LOCALE_SPOSITIVESIGN	80
#define LOCALE_SNEGATIVESIGN	81
#define LOCALE_IPOSSIGNPOSN	82
#define LOCALE_INEGSIGNPOSN	83
#define LOCALE_IPOSSYMPRECEDES	84
#define LOCALE_IPOSSEPBYSPACE	85
#define LOCALE_INEGSYMPRECEDES	86
#define LOCALE_INEGSEPBYSPACE	87
#define LOCALE_FONTSIGNATURE	88
#define LOCALE_SISO639LANGNAME 89
#define LOCALE_SISO3166CTRYNAME 90
#define LOCALE_SYSTEM_DEFAULT	0x800
#define LOCALE_USER_DEFAULT	0x400
#define NORM_IGNORECASE	1
#define NORM_IGNOREKANATYPE	65536
#define NORM_IGNORENONSPACE	2
#define NORM_IGNORESYMBOLS	4
#define NORM_IGNOREWIDTH	131072
#define SORT_STRINGSORT	4096
#define LCMAP_LOWERCASE 0x00000100
#define LCMAP_UPPERCASE 0x00000200
#define LCMAP_SORTKEY 0x00000400
#define LCMAP_BYTEREV 0x00000800
#define LCMAP_HIRAGANA 0x00100000
#define LCMAP_KATAKANA 0x00200000
#define LCMAP_HALFWIDTH 0x00400000
#define LCMAP_FULLWIDTH 0x00800000
#define LCMAP_LINGUISTIC_CASING 0x01000000
#define LCMAP_SIMPLIFIED_CHINESE 0x02000000
#define LCMAP_TRADITIONAL_CHINESE 0x04000000
#define ENUM_ALL_CALENDARS (-1)
#define DATE_SHORTDATE 1
#define DATE_LONGDATE 2
#define DATE_USE_ALT_CALENDAR 4
#define CP_INSTALLED 1
#define CP_SUPPORTED 2
#define LCID_INSTALLED 1
#define LCID_SUPPORTED 2
#define LCID_ALTERNATE_SORTS 4
#define MAP_FOLDCZONE 16
#define MAP_FOLDDIGITS 128
#define MAP_PRECOMPOSED 32
#define MAP_COMPOSITE 64
#define CP_ACP 0
#define CP_OEMCP 1
#define CP_MACCP 2
#define CP_THREAD_ACP 3
#define CP_SYMBOL 42
#define CP_UTF7 65000
#define CP_UTF8 65001
#define CT_CTYPE1 1
#define CT_CTYPE2 2
#define CT_CTYPE3 4
#define C1_UPPER 1
#define C1_LOWER 2
#define C1_DIGIT 4
#define C1_SPACE 8
#define C1_PUNCT 16
#define C1_CNTRL 32
#define C1_BLANK 64
#define C1_XDIGIT 128
#define C1_ALPHA 256
#define C2_LEFTTORIGHT 1
#define C2_RIGHTTOLEFT 2
#define C2_EUROPENUMBER 3
#define C2_EUROPESEPARATOR 4
#define C2_EUROPETERMINATOR 5
#define C2_ARABICNUMBER 6
#define C2_COMMONSEPARATOR 7
#define C2_BLOCKSEPARATOR 8
#define C2_SEGMENTSEPARATOR 9
#define C2_WHITESPACE 10
#define C2_OTHERNEUTRAL 11
#define C2_NOTAPPLICABLE 0
#define C3_NONSPACING 1
#define C3_DIACRITIC 2
#define C3_VOWELMARK 4
#define C3_SYMBOL 8
#define C3_KATAKANA 16
#define C3_HIRAGANA 32
#define C3_HALFWIDTH 64
#define C3_FULLWIDTH 128
#define C3_IDEOGRAPH 256
#define C3_KASHIDA 512
#define C3_LEXICAL 1024
#define C3_ALPHA 32768
#define C3_NOTAPPLICABLE 0
#define TIME_NOMINUTESORSECONDS 1
#define TIME_NOSECONDS 2
#define TIME_NOTIMEMARKER 4
#define TIME_FORCE24HOURFORMAT 8
#define MB_PRECOMPOSED 1
#define MB_COMPOSITE 2
#define MB_ERR_INVALID_CHARS 8
#define MB_USEGLYPHCHARS 4
#define WC_COMPOSITECHECK 512
#define WC_DISCARDNS 16
#define WC_SEPCHARS 32
#define WC_DEFAULTCHAR 64
#define CTRY_DEFAULT 0
#define CTRY_ALBANIA 355
#define CTRY_ALGERIA 213
#define CTRY_ARGENTINA 54
#define CTRY_ARMENIA 374
#define CTRY_AUSTRALIA 61
#define CTRY_AUSTRIA 43
#define CTRY_AZERBAIJAN 994
#define CTRY_BAHRAIN 973
#define CTRY_BELARUS 375
#define CTRY_BELGIUM 32
#define CTRY_BELIZE 501
#define CTRY_BOLIVIA 591
#define CTRY_BRAZIL 55
#define CTRY_BRUNEI_DARUSSALAM 673
#define CTRY_BULGARIA 359
#define CTRY_CANADA 2
#define CTRY_CARIBBEAN 1
#define CTRY_CHILE 56
#define CTRY_COLOMBIA 57
#define CTRY_COSTA_RICA 506
#define CTRY_CROATIA 385
#if defined(_WIN32_WCE) && _WIN32_WCE < 0x300
#define CTRY_CZECH 42
#else
#define CTRY_CZECH 420
#endif
#define CTRY_DENMARK 45
#define CTRY_DOMINICAN_REPUBLIC 1
#define CTRY_ECUADOR 593
#define CTRY_EGYPT 20
#define CTRY_EL_SALVADOR 503
#define CTRY_ESTONIA 372
#define CTRY_FAEROE_ISLANDS 298
#define CTRY_FINLAND 358
#define CTRY_FRANCE 33
#define CTRY_GEORGIA 995
#define CTRY_GERMANY 49
#define CTRY_GREECE 30
#define CTRY_GUATEMALA 502
#define CTRY_HONDURAS 504
#define CTRY_HONG_KONG 852
#define CTRY_HUNGARY 36
#define CTRY_ICELAND 354
#define CTRY_INDIA 91
#define CTRY_INDONESIA 62
#define CTRY_IRAN 981
#define CTRY_IRAQ 964
#define CTRY_IRELAND 353
#define CTRY_ISRAEL 972
#define CTRY_ITALY 39
#define CTRY_JAMAICA 1
#define CTRY_JAPAN 81
#define CTRY_JORDAN 962
#define CTRY_KAZAKSTAN 7
#define CTRY_KENYA 254
#define CTRY_KUWAIT 965
#define CTRY_KYRGYZSTAN 996
#define CTRY_LATVIA 371
#define CTRY_LEBANON 961
#define CTRY_LIBYA 218
#define CTRY_LIECHTENSTEIN 41
#define CTRY_LITHUANIA 370
#define CTRY_LUXEMBOURG 352
#define CTRY_MACAU 853
#define CTRY_MACEDONIA 389
#define CTRY_MALAYSIA 60
#define CTRY_MALDIVES 960
#define CTRY_MEXICO 52
#define CTRY_MONACO 33
#define CTRY_MONGOLIA 976
#define CTRY_MOROCCO 212
#define CTRY_NETHERLANDS 31
#define CTRY_NEW_ZEALAND 64
#define CTRY_NICARAGUA 505
#define CTRY_NORWAY 47
#define CTRY_OMAN 968
#define CTRY_PAKISTAN 92
#define CTRY_PANAMA 507
#define CTRY_PARAGUAY 595
#define CTRY_PERU 51
#define CTRY_PHILIPPINES 63
#define CTRY_POLAND 48
#define CTRY_PORTUGAL 351
#define CTRY_PRCHINA 86
#define CTRY_PUERTO_RICO 1
#define CTRY_QATAR 974
#define CTRY_ROMANIA 40
#define CTRY_RUSSIA 7
#define CTRY_SAUDI_ARABIA 966
#define CTRY_SERBIA 381
#define CTRY_SINGAPORE 65
#if defined(_WIN32_WCE) && _WIN32_WCE < 0x300
#define CTRY_SLOVAK 42
#else
#define CTRY_SLOVAK 421
#endif
#define CTRY_SLOVENIA 386
#define CTRY_SOUTH_AFRICA 27
#define CTRY_SOUTH_KOREA 82
#define CTRY_SPAIN 34
#define CTRY_SWEDEN 46
#define CTRY_SWITZERLAND 41
#define CTRY_SYRIA 963
#define CTRY_TAIWAN 886
#define CTRY_TATARSTAN 7
#define CTRY_THAILAND 66
#define CTRY_TRINIDAD_Y_TOBAGO 1
#define CTRY_TUNISIA 216
#define CTRY_TURKEY 90
#define CTRY_UAE 971
#define CTRY_UKRAINE 380
#define CTRY_UNITED_KINGDOM 44
#define CTRY_UNITED_STATES 1
#define CTRY_URUGUAY 598
#define CTRY_UZBEKISTAN 7
#define CTRY_VENEZUELA 58
#define CTRY_VIET_NAM 84
#define CTRY_YEMEN 967
#define CTRY_ZIMBABWE 263
#define CAL_ICALINTVALUE 1
#define CAL_SCALNAME 2
#define CAL_IYEAROFFSETRANGE 3
#define CAL_SERASTRING 4
#define CAL_SSHORTDATE 5
#define CAL_SLONGDATE 6
#define CAL_SDAYNAME1 7
#define CAL_SDAYNAME2 8
#define CAL_SDAYNAME3 9
#define CAL_SDAYNAME4 10
#define CAL_SDAYNAME5 11
#define CAL_SDAYNAME6 12
#define CAL_SDAYNAME7 13
#define CAL_SABBREVDAYNAME1 14
#define CAL_SABBREVDAYNAME2 15
#define CAL_SABBREVDAYNAME3 16
#define CAL_SABBREVDAYNAME4 17
#define CAL_SABBREVDAYNAME5 18
#define CAL_SABBREVDAYNAME6 19
#define CAL_SABBREVDAYNAME7 20
#define CAL_SMONTHNAME1 21
#define CAL_SMONTHNAME2 22
#define CAL_SMONTHNAME3 23
#define CAL_SMONTHNAME4 24
#define CAL_SMONTHNAME5 25
#define CAL_SMONTHNAME6 26
#define CAL_SMONTHNAME7 27
#define CAL_SMONTHNAME8 28
#define CAL_SMONTHNAME9 29
#define CAL_SMONTHNAME10 30
#define CAL_SMONTHNAME11 31
#define CAL_SMONTHNAME12 32
#define CAL_SMONTHNAME13 33
#define CAL_SABBREVMONTHNAME1 34
#define CAL_SABBREVMONTHNAME2 35
#define CAL_SABBREVMONTHNAME3 36
#define CAL_SABBREVMONTHNAME4 37
#define CAL_SABBREVMONTHNAME5 38
#define CAL_SABBREVMONTHNAME6 39
#define CAL_SABBREVMONTHNAME7 40
#define CAL_SABBREVMONTHNAME8 41
#define CAL_SABBREVMONTHNAME9 42
#define CAL_SABBREVMONTHNAME10 43
#define CAL_SABBREVMONTHNAME11 44
#define CAL_SABBREVMONTHNAME12 45
#define CAL_SABBREVMONTHNAME13 46
#define CAL_GREGORIAN 1
#define CAL_GREGORIAN_US 2
#define CAL_JAPAN 3
#define CAL_TAIWAN 4
#define CAL_KOREA 5
#define CAL_HIJRI 6
#define CAL_THAI 7
#define CAL_HEBREW 8
#define CAL_GREGORIAN_ME_FRENCH 9
#define CAL_GREGORIAN_ARABIC 10
#define CAL_GREGORIAN_XLIT_ENGLISH 11
#define CAL_GREGORIAN_XLIT_FRENCH 12
#define CSTR_LESS_THAN 1
#define CSTR_EQUAL 2
#define CSTR_GREATER_THAN 3
#define LGRPID_INSTALLED 1
#define LGRPID_SUPPORTED 2
#define LGRPID_WESTERN_EUROPE 1
#define LGRPID_CENTRAL_EUROPE 2
#define LGRPID_BALTIC 3
#define LGRPID_GREEK 4
#define LGRPID_CYRILLIC 5
#define LGRPID_TURKISH 6
#define LGRPID_JAPANESE 7
#define LGRPID_KOREAN 8
#define LGRPID_TRADITIONAL_CHINESE 9
#define LGRPID_SIMPLIFIED_CHINESE 10
#define LGRPID_THAI 11
#define LGRPID_HEBREW 12
#define LGRPID_ARABIC 13
#define LGRPID_VIETNAMESE 14
#define LGRPID_INDIC 15
#define LGRPID_GEORGIAN 16
#define LGRPID_ARMENIAN 17
#define IS_HIGH_SURROGATE(c) (((c) & 0xFC00) == 0xD800)
#define IS_LOW_SURROGATE(c) (((c) & 0xFC00) == 0xDC00)
#define IS_SURROGATE_PAIR(hc,lc) (IS_HIGH_SURROGATE(hc) && IS_LOW_SURROGATE(lc))
#if (WINVER >= 0x0410)
#define CAL_SYEARMONTH 47
#define CAL_ITWODIGITYEARMAX 48
#define CAL_NOUSEROVERRIDE LOCALE_NOUSEROVERRIDE
#define CAL_RETURN_NUMBER LOCALE_RETURN_NUMBER
#define CAL_USE_CP_ACP LOCALE_USE_CP_ACP
#define LOCALE_SYEARMONTH 0x1006
#define LOCALE_SENGCURRNAME 0x1007
#define LOCALE_SNATIVECURRNAME 0x1008
#define LOCALE_SSORTNAME 0x1013
#endif /* (WINVER >= 0x0410) */
#if (WINVER >= 0x0500)
#define LOCALE_IDEFAULTEBCDICCODEPAGE 0x1012
#define LOCALE_IDIGITSUBSTITUTION 0x1014
#define LOCALE_IPAPERSIZE 0x100A
#define DATE_YEARMONTH 8
#define DATE_LTRREADING 16
#define DATE_RTLREADING 32
#define MAP_EXPAND_LIGATURES   0x2000
#define WC_NO_BEST_FIT_CHARS 1024
#endif /* (WINVER >= 0x0500) */
#if (WINVER >= 0x0600)
/*#define CAL_SSHORTESTDAYNAME1 */
/*#define CAL_SSHORTESTDAYNAME2 */
/*#define CAL_SSHORTESTDAYNAME3 */
/*#define CAL_SSHORTESTDAYNAME4 */
/*#define CAL_SSHORTESTDAYNAME5 */
/*#define CAL_SSHORTESTDAYNAME6 */
/*#define CAL_SSHORTESTDAYNAME7 */
#define CAL_UMALQURA 23
/*#define LOCALE_SDURATION */
/*#define LOCALE_SIETFLANGUAGE */
/*#define LOCALE_SISO3166CTRYNAME2 */
/*#define LOCALE_SISO639LANGNAME2 */
/*#define LOCALE_SKEYBOARDSTOINSTALL */
/*#define LOCALE_SNAME */
/*#define LOCALE_SNAN */
/*#define LOCALE_SNEGINFINITY */
/*#define LOCALE_SPOSINFINITY */
/*#define LOCALE_SSCRIPTS */
#endif /* (WINVER >= 0x0600) */
#ifndef  _BASETSD_H
typedef long LONG_PTR;
#endif 

#ifndef RC_INVOKED
typedef DWORD LCTYPE;
typedef DWORD CALTYPE;
typedef DWORD CALID;
typedef DWORD LGRPID;
typedef DWORD GEOID;
typedef DWORD GEOTYPE;
typedef DWORD GEOCLASS;
typedef BOOL (CALLBACK *CALINFO_ENUMPROCA)(LPSTR);
typedef BOOL (CALLBACK *CALINFO_ENUMPROCW)(LPWSTR);
typedef BOOL (CALLBACK *CALINFO_ENUMPROCEXA)(LPSTR, CALID);
typedef BOOL (CALLBACK *CALINFO_ENUMPROCEXW)(LPWSTR, CALID);
typedef BOOL (CALLBACK *LANGUAGEGROUP_ENUMPROCA)(LGRPID, LPSTR, LPSTR, DWORD, LONG_PTR);
typedef BOOL (CALLBACK *LANGUAGEGROUP_ENUMPROCW)(LGRPID, LPWSTR, LPWSTR, DWORD, LONG_PTR);
typedef BOOL (CALLBACK *LANGGROUPLOCALE_ENUMPROCA)(LGRPID, LCID, LPSTR, LONG_PTR);
typedef BOOL (CALLBACK *LANGGROUPLOCALE_ENUMPROCW)(LGRPID, LCID, LPWSTR, LONG_PTR);
typedef BOOL (CALLBACK *UILANGUAGE_ENUMPROCW)(LPWSTR, LONG_PTR);
typedef BOOL (CALLBACK *UILANGUAGE_ENUMPROCA)(LPSTR, LONG_PTR);
typedef BOOL (CALLBACK *LOCALE_ENUMPROCA)(LPSTR);
typedef BOOL (CALLBACK *LOCALE_ENUMPROCW)(LPWSTR);
typedef BOOL (CALLBACK *CODEPAGE_ENUMPROCA)(LPSTR);
typedef BOOL (CALLBACK *CODEPAGE_ENUMPROCW)(LPWSTR);
typedef BOOL (CALLBACK *DATEFMT_ENUMPROCA)(LPSTR);
typedef BOOL (CALLBACK *DATEFMT_ENUMPROCW)(LPWSTR);
typedef BOOL (CALLBACK *DATEFMT_ENUMPROCEXA)(LPSTR, CALID);
typedef BOOL (CALLBACK *DATEFMT_ENUMPROCEXW)(LPWSTR, CALID);
typedef BOOL (CALLBACK *TIMEFMT_ENUMPROCA)(LPSTR);
typedef BOOL (CALLBACK *TIMEFMT_ENUMPROCW)(LPWSTR);
typedef BOOL (CALLBACK *GEO_ENUMPROC)(GEOID);

enum NLS_FUNCTION {
	COMPARE_STRING = 0x0001
};
typedef enum NLS_FUNCTION NLS_FUNCTION;
enum SYSGEOCLASS {
	GEOCLASS_NATION = 16,
	GEOCLASS_REGION = 14
};
enum SYSGEOTYPE {
	GEO_NATION            = 0x0001,
	GEO_LATITUDE          = 0x0002,
	GEO_LONGITUDE         = 0x0003,
	GEO_ISO2              = 0x0004,
	GEO_ISO3              = 0x0005,
	GEO_RFC1766           = 0x0006,
	GEO_LCID              = 0x0007,
	GEO_FRIENDLYNAME      = 0x0008,
	GEO_OFFICIALNAME      = 0x0009,
	GEO_TIMEZONES         = 0x000a,
	GEO_OFFICIALLANGUAGES = 0x000a
};

/**
 * This structure contains information about a code page.
 *
 * Lead bytes are unique to double-byte character sets (DBCS). A lead byte
 * is the first byte of a 2-byte character in a DBCS. Lead bytes occupy a
 * specific range of byte values.
 */
typedef struct _cpinfo {
	/**
	 * Specifies the maximum length, in bytes, of a
	 * character in this code page.
	 */
	UINT MaxCharSize;
	/**
	 * Specifies the default character used in translations
	 * into this code page. This character is used by the
	 * WideCharToMultiByte function if an explicit default character is
	 * not given.
	 */
	BYTE DefaultChar[MAX_DEFAULTCHAR];
	/**
	 * Specifies a fixed-length array of lead-byte ranges,
	 * where the number of lead-byte ranges is variable. If there are no
	 * lead bytes in this code page, then every element of the array is
	 * NULL. If there are lead bytes in this code page, a starting value
	 * and ending value is given for each range. Ranges are inclusive.
	 * The maximum number of lead-byte ranges for any code page is 5.
	 * The array uses two bytes to describe each range, with a
	 * double-byte terminating null character after the last range.
	 */
	BYTE LeadByte[MAX_LEADBYTES];
} CPINFO,*LPCPINFO;
typedef struct _cpinfoexA {
	UINT MaxCharSize;
	BYTE DefaultChar[MAX_DEFAULTCHAR];
	BYTE LeadByte[MAX_LEADBYTES];
	WCHAR UnicodeDefaultChar;
	UINT CodePage;
	CHAR CodePageName[MAX_PATH];
} CPINFOEXA,*LPCPINFOEXA;
typedef struct _cpinfoexW {
	UINT MaxCharSize;
	BYTE DefaultChar[MAX_DEFAULTCHAR];
	BYTE LeadByte[MAX_LEADBYTES];
	WCHAR UnicodeDefaultChar;
	UINT CodePage;
	WCHAR CodePageName[MAX_PATH];
} CPINFOEXW,*LPCPINFOEXW;
typedef struct _currencyfmtA {
	UINT NumDigits;
	UINT LeadingZero;
	UINT Grouping;
	LPSTR lpDecimalSep;
	LPSTR lpThousandSep;
	UINT NegativeOrder;
	UINT PositiveOrder;
	LPSTR lpCurrencySymbol;
} CURRENCYFMTA,*LPCURRENCYFMTA;
typedef struct _currencyfmtW {
	UINT NumDigits;
	UINT LeadingZero;
	UINT Grouping;
	LPWSTR lpDecimalSep;
	LPWSTR lpThousandSep;
	UINT NegativeOrder;
	UINT PositiveOrder;
	LPWSTR lpCurrencySymbol;
} CURRENCYFMTW,*LPCURRENCYFMTW;
typedef struct nlsversioninfo { 
	DWORD dwNLSVersionInfoSize; 
	DWORD dwNLSVersion; 
	DWORD dwDefinedVersion; 
} NLSVERSIONINFO,*LPNLSVERSIONINFO; 
typedef struct _numberfmtA {
	UINT NumDigits;
	UINT LeadingZero;
	UINT Grouping;
	LPSTR lpDecimalSep;
	LPSTR lpThousandSep;
	UINT NegativeOrder;
} NUMBERFMTA,*LPNUMBERFMTA;
typedef struct _numberfmtW {
	UINT NumDigits;
	UINT LeadingZero;
	UINT Grouping;
	LPWSTR lpDecimalSep;
	LPWSTR lpThousandSep;
	UINT NegativeOrder;
} NUMBERFMTW,*LPNUMBERFMTW;

WINBASEAPI int WINAPI CompareStringA(LCID,DWORD,LPCSTR,int,LPCSTR,int);
/**
 * Compares two strings using a locale's collation rules.
 *
 * Windows CE always uses a string sort (SORT_STRINGSORT), so hyphens and
 * apostrophes sort with the other symbols. Subtract 2 from a nonzero result
 * to get a C-style comparison. "Equal" means equal for sorting, not
 * necessarily identical.
 *
 * @param Locale LOCALE_SYSTEM_DEFAULT, LOCALE_USER_DEFAULT or a MAKELCID
 *        value.
 * @param dwCmpFlags 0 or NORM_IGNORECASE. Windows CE doesn't support
 *        NORM_IGNOREKANATYPE, NORM_IGNORENONSPACE, NORM_IGNORESYMBOLS or
 *        NORM_IGNOREWIDTH.
 * @param lpString1 First string.
 * @param cchCount1 Length of lpString1 in characters, or -1 if
 *        null-terminated.
 * @param lpString2 Second string.
 * @param cchCount2 Length of lpString2 in characters, or -1 if
 *        null-terminated.
 * @return 1 (less than), 2 (equal) or 3 (greater than), or 0 on failure
 *         (see GetLastError).
 */
WINBASEAPI int WINAPI CompareStringW(LCID Locale,DWORD dwCmpFlags,LPCWSTR lpString1,int cchCount1,LPCWSTR lpString2,int cchCount2);
/**
 * Converts a special default locale value into a real locale identifier.
 *
 * @param Locale LOCALE_SYSTEM_DEFAULT, LOCALE_USER_DEFAULT, 0 (language
 *        neutral) or a MAKELCID value with SUBLANG_NEUTRAL.
 * @return The locale identifier, or Locale unchanged if it isn't one of the
 *         special values.
 */
WINBASEAPI LCID WINAPI ConvertDefaultLocale(LCID Locale);
WINBASEAPI BOOL WINAPI EnumCalendarInfoA(CALINFO_ENUMPROCA,LCID,CALID,CALTYPE);
/**
 * Enumerates one item of calendar information for a locale's calendars.
 *
 * Calls lpCalInfoEnumProc with each string until it returns FALSE or the
 * calendars run out.
 *
 * @param lpCalInfoEnumProc Callback receiving each string.
 * @param Locale LOCALE_SYSTEM_DEFAULT, LOCALE_USER_DEFAULT or a MAKELCID
 *        value.
 * @param Calendar A calendar identifier (CAL_GREGORIAN and so on), or
 *        ENUM_ALL_CALENDARS.
 * @param CalType The item to return, a CAL_* value such as CAL_SERASTRING
 *        or CAL_SLONGDATE.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI EnumCalendarInfoW(CALINFO_ENUMPROCW lpCalInfoEnumProc,LCID Locale,CALID Calendar,CALTYPE CalType);
WINBASEAPI BOOL WINAPI EnumDateFormatsA(DATEFMT_ENUMPROCA,LCID,DWORD);
/**
 * Enumerates a locale's short or long date formats, including those of any
 * alternate calendars.
 *
 * Calls lpDateFmtEnumProc with each format picture until it returns FALSE or
 * the formats run out.
 *
 * @param lpDateFmtEnumProc Callback receiving each format string.
 * @param Locale LOCALE_SYSTEM_DEFAULT, LOCALE_USER_DEFAULT or a MAKELCID
 *        value.
 * @param dwFlags DATE_SHORTDATE or DATE_LONGDATE, not both.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI EnumDateFormatsW(DATEFMT_ENUMPROCW lpDateFmtEnumProc,LCID Locale,DWORD dwFlags);
WINBASEAPI BOOL WINAPI EnumSystemCodePagesA(CODEPAGE_ENUMPROCA,DWORD);
/**
 * Enumerates the code pages installed on or supported by the system.
 *
 * Calls lpCodePageEnumProc with each code page identifier, as a string,
 * until it returns FALSE or the code pages run out.
 *
 * @param lpCodePageEnumProc Callback receiving each code page.
 * @param dwFlags CP_INSTALLED or CP_SUPPORTED, not both.
 * @return Nonzero on success, zero on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI EnumSystemCodePagesW(CODEPAGE_ENUMPROCW lpCodePageEnumProc,DWORD dwFlags);
WINBASEAPI BOOL WINAPI EnumSystemGeoID(GEOCLASS,GEOID,GEO_ENUMPROC);
WINBASEAPI BOOL WINAPI EnumSystemLocalesA(LOCALE_ENUMPROCA,DWORD);
/**
 * Enumerates the locales installed on or supported by the system.
 *
 * Calls lpLocaleEnumProc with each locale identifier, as a hex string, until
 * it returns FALSE or the locales run out.
 *
 * @param lpLocaleEnumProc Callback receiving each locale.
 * @param dwFlags LCID_INSTALLED or LCID_SUPPORTED, not both. Windows CE
 *        doesn't support LCID_ALTERNATE_SORTS.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI EnumSystemLocalesW(LOCALE_ENUMPROCW lpLocaleEnumProc,DWORD dwFlags);
WINBASEAPI BOOL WINAPI EnumTimeFormatsA(TIMEFMT_ENUMPROCA,LCID,DWORD);
/**
 * Enumerates a locale's time formats.
 *
 * Calls lpTimeFmtEnumProc with each format picture until it returns FALSE or
 * the formats run out.
 *
 * @param lpTimeFmtEnumProc Callback receiving each format string.
 * @param Locale LOCALE_SYSTEM_DEFAULT, LOCALE_USER_DEFAULT or a MAKELCID
 *        value.
 * @param dwFlags Must be 0.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
WINBASEAPI BOOL WINAPI EnumTimeFormatsW(TIMEFMT_ENUMPROCW lpTimeFmtEnumProc,LCID Locale,DWORD dwFlags);
WINBASEAPI int WINAPI FoldStringA(DWORD,LPCSTR,int,LPSTR,int);
/**
 * Maps a string to another, folding character variants as requested.
 *
 * The source and destination buffers must differ. The result is
 * null-terminated if the source is.
 *
 * @param dwMapFlags One or more of MAP_FOLDCZONE (compatibility zone
 *        characters to standard Unicode), MAP_FOLDDIGITS (all digits to
 *        0-9), MAP_PRECOMPOSED or MAP_COMPOSITE (not both), and
 *        MAP_EXPAND_LIGATURES (not with MAP_PRECOMPOSED or MAP_COMPOSITE).
 * @param lpSrcStr The source string.
 * @param cchSrc Length of lpSrcStr in characters, or -1 if null-terminated.
 * @param lpDestStr Receives the mapped string.
 * @param cchDest Size of lpDestStr in characters, or 0 to query the size
 *        needed.
 * @return Characters written, or the size needed if cchDest is 0, or 0 on
 *         failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI int WINAPI FoldStringW(DWORD dwMapFlags,LPCWSTR lpSrcStr,int cchSrc,LPWSTR lpDestStr,int cchDest);
/**
 * Returns the system's ANSI code page identifier, e.g. 1252.
 *
 * @return The code page identifier.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI UINT WINAPI GetACP(void);
WINBASEAPI int WINAPI GetCalendarInfoA(LCID,CALID,CALTYPE,LPSTR,int,LPDWORD);
WINBASEAPI int WINAPI GetCalendarInfoW(LCID,CALID,CALTYPE,LPWSTR,int,LPDWORD);
/**
 * Gets information about a code page: maximum character size, default
 * character and lead byte ranges.
 *
 * @param CodePage A code page identifier, or CP_ACP or CP_OEMCP.
 * @param lpCPInfo Receives the information.
 * @return Nonzero on success, zero on failure, with ERROR_INVALID_PARAMETER
 *         if the code page isn't available.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI GetCPInfo(UINT CodePage,LPCPINFO lpCPInfo);
WINBASEAPI BOOL WINAPI GetCPInfoExA(UINT,DWORD,LPCPINFOEXA);
WINBASEAPI BOOL WINAPI GetCPInfoExW(UINT,DWORD,LPCPINFOEXW);
WINBASEAPI int WINAPI GetCurrencyFormatA(LCID,DWORD,LPCSTR,const CURRENCYFMTA*,LPSTR,int);
/**
 * Formats a number string as currency.
 *
 * Windows CE ignores Locale and always uses the system locale.
 *
 * @param Locale Pass LOCALE_SYSTEM_DEFAULT.
 * @param dwFlags Must be 0.
 * @param lpValue The number: digits, an optional leading minus sign and at
 *        most one decimal point.
 * @param lpFormat Currency format, with every member set, or NULL for the
 *        locale's format.
 * @param lpCurrencyStr Receives the formatted string.
 * @param cchCurrency Size of lpCurrencyStr in characters, or 0 to query the
 *        size needed.
 * @return Characters written, or the size needed if cchCurrency is 0, or 0
 *         on failure (see GetLastError).
 */
WINBASEAPI int WINAPI GetCurrencyFormatW(LCID Locale,DWORD dwFlags,LPCWSTR lpValue,const CURRENCYFMTW*lpFormat,LPWSTR lpCurrencyStr,int cchCurrency);
WINBASEAPI int WINAPI GetDateFormatA(LCID,DWORD,const SYSTEMTIME*,LPCSTR,LPSTR,int);
/**
 * Formats a date as a string.
 *
 * Windows CE ignores Locale and always uses the system locale. The time
 * fields of lpDate are ignored. A wrong wDayOfWeek is corrected; other
 * invalid fields fail with ERROR_INVALID_PARAMETER. Bad format pictures
 * don't fail: the function does its best.
 *
 * @param Locale Pass LOCALE_SYSTEM_DEFAULT.
 * @param dwFlags DATE_SHORTDATE (default) or DATE_LONGDATE if lpFormat is
 *        NULL, otherwise 0. Windows CE doesn't support LOCALE_NOUSEROVERRIDE
 *        or DATE_USE_ALT_CALENDAR.
 * @param lpDate The date, or NULL for today's local date.
 * @param lpFormat Format picture built from d, dd, ddd, dddd, M, MM, MMM,
 *        MMMM, y, yy, yyyy and gg, with literal text in single quotes, or
 *        NULL for the locale's format.
 * @param lpDateStr Receives the formatted date.
 * @param cchDate Size of lpDateStr in characters, or 0 to query the size
 *        needed.
 * @return Characters written, or the size needed if cchDate is 0, or 0 on
 *         failure (see GetLastError).
 */
WINBASEAPI int WINAPI GetDateFormatW(LCID Locale,DWORD dwFlags,const SYSTEMTIME*lpDate,LPCWSTR lpFormat,LPWSTR lpDateStr,int cchDate);
WINBASEAPI int WINAPI GetGeoInfoA(GEOID,GEOTYPE,LPSTR,int,LANGID);
WINBASEAPI int WINAPI GetGeoInfoW(GEOID,GEOTYPE,LPWSTR,int,LANGID);
WINBASEAPI int WINAPI GetLocaleInfoA(LCID,LCTYPE,LPSTR,int);
/**
 * Gets one item of information about a locale, as a string.
 *
 * Numeric values are returned as decimal text.
 *
 * @param Locale LOCALE_SYSTEM_DEFAULT, LOCALE_USER_DEFAULT or a MAKELCID
 *        value.
 * @param LCType A LOCALE_* item, e.g. LOCALE_SDECIMAL or LOCALE_SSHORTDATE,
 *        optionally OR'd with LOCALE_NOUSEROVERRIDE to ignore user settings.
 * @param lpLCData Receives the data.
 * @param cchData Size of lpLCData in characters, or 0 to query the size
 *        needed.
 * @return Characters written, or the size needed if cchData is 0, or 0 on
 *         failure (see GetLastError).
 */
WINBASEAPI int WINAPI GetLocaleInfoW(LCID Locale,LCTYPE LCType,LPWSTR lpLCData,int cchData);
WINBASEAPI BOOL WINAPI GetNLSVersion(NLS_FUNCTION,LCID,LPNLSVERSIONINFO);
WINBASEAPI int WINAPI GetNumberFormatA(LCID,DWORD,LPCSTR,const NUMBERFMTA*,LPSTR,int);
/**
 * Formats a number string with a locale's separators, grouping and decimal
 * places.
 *
 * Windows CE ignores Locale and always uses the system locale.
 *
 * @param Locale Pass LOCALE_SYSTEM_DEFAULT.
 * @param dwFlags Must be 0.
 * @param lpValue The number: digits, an optional leading minus sign and at
 *        most one decimal point.
 * @param lpFormat Number format, with every member set, or NULL for the
 *        locale's format.
 * @param lpNumberStr Receives the formatted string.
 * @param cchNumber Size of lpNumberStr in characters, or 0 to query the size
 *        needed.
 * @return Characters written, or the size needed if cchNumber is 0, or 0 on
 *         failure (see GetLastError).
 */
WINBASEAPI int WINAPI GetNumberFormatW(LCID Locale,DWORD dwFlags,LPCWSTR lpValue,const NUMBERFMTW*lpFormat,LPWSTR lpNumberStr,int cchNumber);
/**
 * Returns the system's OEM code page identifier, e.g. 437.
 *
 * @return The code page identifier.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI UINT WINAPI GetOEMCP(void);
WINBASEAPI BOOL WINAPI GetStringTypeA(LCID,DWORD,LPCSTR,int,LPWORD);
/**
 * Returns character-type flags for each character in a Unicode string.
 *
 * This is the Unicode form, with no locale parameter, unlike desktop
 * GetStringTypeA. GetStringTypeExW has the same behaviour and a portable
 * signature.
 *
 * @param dwInfoType CT_CTYPE1, CT_CTYPE2 or CT_CTYPE3.
 * @param lpSrcStr The string. Must not be the same buffer as lpCharType.
 * @param cchSrc Length in characters, or -1 if null-terminated.
 * @param lpCharType Receives one WORD of flags per character.
 * @return Nonzero on success, or 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI GetStringTypeW(DWORD dwInfoType,LPCWSTR lpSrcStr,int cchSrc,LPWORD lpCharType);
WINBASEAPI BOOL WINAPI GetStringTypeExA(LCID,DWORD,LPCSTR,int,LPWORD);
/**
 * Returns character-type flags for each character in a string.
 *
 * Fills one WORD per character. The types depend only on the Unicode code
 * point, not the locale.
 *
 * @param Locale Ignored on Windows CE. Pass LOCALE_SYSTEM_DEFAULT or
 *        LOCALE_USER_DEFAULT.
 * @param dwInfoType CT_CTYPE1 (C1_UPPER, C1_DIGIT, C1_ALPHA and so on),
 *        CT_CTYPE2 (bidirectional layout, C2_*) or CT_CTYPE3 (text
 *        processing, C3_*).
 * @param lpSrcStr The string. Must not be the same buffer as lpCharType.
 * @param cchSrc Length in characters, or -1 if null-terminated. A count
 *        that includes the terminator also returns its type.
 * @param lpCharType Receives one WORD of flags per character.
 * @return Nonzero on success, or 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI GetStringTypeExW(LCID Locale,DWORD dwInfoType,LPCWSTR lpSrcStr,int cchSrc,LPWORD lpCharType);
/**
 * Returns the system default language identifier.
 *
 * @return The system default LANGID.
 */
WINBASEAPI LANGID WINAPI GetSystemDefaultLangID(void);
/**
 * Returns the system default locale identifier.
 *
 * @return The system default LCID.
 */
WINBASEAPI LCID WINAPI GetSystemDefaultLCID(void);
WINBASEAPI LCID WINAPI GetThreadLocale(void);
WINBASEAPI int WINAPI GetTimeFormatA(LCID,DWORD,const SYSTEMTIME*,LPCSTR,LPSTR,int);
/**
 * Formats a time as a string, using a format picture or the locale's
 * default.
 *
 * The date fields of the SYSTEMTIME are ignored, and milliseconds are
 * never shown. An out-of-range time field fails with
 * ERROR_INVALID_PARAMETER, but a bad format picture doesn't fail.
 *
 * @param Locale Ignored: Windows CE always uses the system locale. Pass
 *        LOCALE_SYSTEM_DEFAULT.
 * @param dwFlags Zero or more of TIME_NOMINUTESORSECONDS, TIME_NOSECONDS,
 *        TIME_NOTIMEMARKER and TIME_FORCE24HOURFORMAT. Windows CE doesn't
 *        support LOCALE_NOUSEOVERRIDE.
 * @param lpTime The time to format, or NULL for the current local time.
 * @param lpFormat Format picture built from h, hh, H, HH, m, mm, s, ss, t
 *        and tt, with literal text in single quotes, e.g.
 *        L"hh':'mm':'ss tt". NULL for the locale's time format.
 * @param lpTimeStr Receives the string.
 * @param cchTime Buffer size in characters, or 0 to query the size needed.
 * @return Characters written including the terminator, or the size needed
 *         if cchTime is 0, or 0 on failure (see GetLastError).
 */
WINBASEAPI int WINAPI GetTimeFormatW(LCID Locale,DWORD dwFlags,const SYSTEMTIME*lpTime,LPCWSTR lpFormat,LPWSTR lpTimeStr,int cchTime);
/**
 * Returns the user default language identifier.
 *
 * @return The user default LANGID.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI LANGID WINAPI GetUserDefaultLangID(void);
/**
 * Returns the user default locale identifier.
 *
 * @return The user default LCID.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI LCID WINAPI GetUserDefaultLCID(void);
WINBASEAPI GEOID WINAPI GetUserGeoID(GEOCLASS);
/**
 * Tests whether a byte is a lead byte of a double-byte character in the
 * system ANSI code page.
 *
 * @param TestChar The byte to test.
 * @return TRUE if it is a lead byte, otherwise FALSE.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI IsDBCSLeadByte(BYTE TestChar);
/**
 * Tests whether a byte is a lead byte of a double-byte character in a given
 * code page.
 *
 * @param CodePage Code page, or 0 or CP_ACP for the system ANSI code page,
 *        or CP_OEMCP for the OEM code page.
 * @param TestChar The byte to test.
 * @return TRUE if it is a lead byte, otherwise FALSE (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI IsDBCSLeadByteEx(UINT CodePage,BYTE TestChar);
WINBASEAPI BOOL WINAPI IsNLSDefinedString(NLS_FUNCTION,DWORD,LPNLSVERSIONINFO,LPCWSTR,int);
/**
 * Tests whether a code page is installed on the device.
 *
 * @param CodePage Code page number, e.g. 1252.
 * @return Nonzero if the code page is installed, otherwise 0.
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI IsValidCodePage(UINT CodePage);
/**
 * Tests whether a locale identifier is supported or installed.
 *
 * @param Locale The LCID to test, e.g. from MAKELCID.
 * @param dwFlags LCID_INSTALLED (supported and installed) or
 *        LCID_SUPPORTED (supported, but maybe not installed).
 * @return TRUE if the locale passes the test, otherwise FALSE.
 */
WINBASEAPI BOOL WINAPI IsValidLocale(LCID Locale,DWORD dwFlags);
WINBASEAPI int WINAPI LCMapStringA(LCID,DWORD,LPCSTR,int,LPSTR,int);
/**
 * Transforms a string (case, width, kana) or generates a sort key for it.
 *
 * With LCMAP_SORTKEY, the output is a null-terminated array of bytes, not
 * WCHARs, and sizes are in bytes; compare sort keys byte by byte.
 *
 * @param Locale Locale for the mapping, e.g. LOCALE_USER_DEFAULT.
 * @param dwMapFlags LCMAP_LOWERCASE, LCMAP_UPPERCASE, LCMAP_HALFWIDTH,
 *        LCMAP_FULLWIDTH, LCMAP_HIRAGANA, LCMAP_KATAKANA, LCMAP_BYTEREV or
 *        LCMAP_SORTKEY, plus NORM_* and SORT_STRINGSORT flags for sort
 *        keys. Opposing pairs are mutually exclusive, and LCMAP_SORTKEY
 *        combines only with LCMAP_BYTEREV among the LCMAP_* flags.
 *        Windows CE doesn't support LCMAP_LINGUISTIC_CASING,
 *        LCMAP_SIMPLIFIED_CHINESE or LCMAP_TRADITIONAL_CHINESE.
 * @param lpSrcStr The source string. Must not be the same buffer as
 *        lpDestStr.
 * @param cchSrc Length in characters, or -1 if null-terminated.
 * @param lpDestStr Receives the mapped string or sort key.
 * @param cchDest Buffer size in characters (bytes for a sort key), or 0 to
 *        query the size needed.
 * @return Characters (or bytes) written including the terminator, or the
 *         size needed if cchDest is 0, or 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI int WINAPI LCMapStringW(LCID Locale,DWORD dwMapFlags,LPCWSTR lpSrcStr,int cchSrc,LPWSTR lpDestStr,int cchDest);
/**
 * Converts a multibyte or single-byte string to a WCHAR string.
 *
 * @param CodePage Code page of the source, or CP_ACP, CP_OEMCP or
 *        CP_MACCP. Windows CE doesn't support CP_UTF7 or CP_UTF8.
 * @param dwFlags Zero, or MB_PRECOMPOSED or MB_COMPOSITE (mutually
 *        exclusive), with MB_USEGLYPHCHARS and MB_ERR_INVALID_CHARS.
 * @param lpMultiByteStr The source string. Must not overlap the output.
 * @param cchMultiByte Source length in bytes, or -1 if null-terminated
 *        (the terminator is then converted and counted too).
 * @param lpWideCharStr Receives the converted string.
 * @param cchWideChar Buffer size in WCHARs, or 0 to query the size needed.
 * @return WCHARs written, or the size needed if cchWideChar is 0, or 0 on
 *         failure (see GetLastError; ERROR_NO_UNICODE_TRANSLATION with
 *         MB_ERR_INVALID_CHARS).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI int WINAPI MultiByteToWideChar(UINT CodePage,DWORD dwFlags,LPCSTR lpMultiByteStr,int cchMultiByte,LPWSTR lpWideCharStr,int cchWideChar);
WINBASEAPI int WINAPI SetCalendarInfoA(LCID,CALID,CALTYPE,LPCSTR);
WINBASEAPI int WINAPI SetCalendarInfoW(LCID,CALID,CALTYPE,LPCWSTR);
WINBASEAPI BOOL WINAPI SetLocaleInfoA(LCID,LCTYPE,LPCSTR);
/**
 * Sets one item of the user's locale settings.
 *
 * Changes the user override, not the system defaults. Numeric items are
 * passed as text.
 *
 * @param Locale Locale to change.
 * @param LCType One LOCALE_* item, e.g. LOCALE_SSHORTDATE, LOCALE_STIME,
 *        LOCALE_SCURRENCY or LOCALE_ITIME. Windows CE adds
 *        LOCALE_SYEARMONTH and doesn't support LOCALE_IPAPERSIZE.
 * @param lpLCData The new value as a null-terminated string, in the
 *        item's format.
 * @return Nonzero on success, or 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI BOOL WINAPI SetLocaleInfoW(LCID Locale,LCTYPE LCType,LPCWSTR lpLCData);
WINBASEAPI BOOL WINAPI SetThreadLocale(LCID);
WINBASEAPI BOOL WINAPI SetUserGeoID(GEOID);
/**
 * Converts a WCHAR string to a multibyte or single-byte string.
 *
 * @param CodePage Target code page, or CP_ACP, CP_OEMCP or CP_MACCP.
 *        Windows CE doesn't support CP_UTF7 or CP_UTF8.
 * @param dwFlags Zero, or WC_COMPOSITECHECK optionally with one of
 *        WC_DISCARDNS, WC_SEPCHARS or WC_DEFAULTCHAR. Windows CE doesn't
 *        support WC_NO_BEST_FIT_CHARS.
 * @param lpWideCharStr The source string. Must not overlap the output.
 * @param cchWideChar Source length in WCHARs, or -1 if null-terminated
 *        (the terminator is then converted and counted too).
 * @param lpMultiByteStr Receives the converted string.
 * @param cchMultiByte Buffer size in bytes, or 0 to query the size needed.
 * @param lpDefaultChar Character for unmappable input, or NULL for the
 *        system default. Faster if this and lpUsedDefaultChar are NULL.
 * @param lpUsedDefaultChar Set to TRUE if the default character was used,
 *        or NULL.
 * @return Bytes written, or the size needed if cchMultiByte is 0, or 0 on
 *         failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
WINBASEAPI int WINAPI WideCharToMultiByte(UINT CodePage,DWORD dwFlags,LPCWSTR lpWideCharStr,int cchWideChar,LPSTR lpMultiByteStr,int cchMultiByte,LPCSTR lpDefaultChar,LPBOOL lpUsedDefaultChar);
#if (WINVER >= 0x0500)
WINBASEAPI BOOL WINAPI EnumCalendarInfoExA(CALINFO_ENUMPROCEXA,LCID,CALID,CALTYPE);
WINBASEAPI BOOL WINAPI EnumCalendarInfoExW(CALINFO_ENUMPROCEXW,LCID,CALID,CALTYPE);
WINBASEAPI BOOL WINAPI EnumDateFormatsExA(DATEFMT_ENUMPROCEXA,LCID,DWORD);
WINBASEAPI BOOL WINAPI EnumDateFormatsExW(DATEFMT_ENUMPROCEXW,LCID,DWORD);
WINBASEAPI BOOL WINAPI EnumSystemLanguageGroupsA(LANGUAGEGROUP_ENUMPROCA,DWORD,LONG_PTR);
WINBASEAPI BOOL WINAPI EnumSystemLanguageGroupsW(LANGUAGEGROUP_ENUMPROCW,DWORD,LONG_PTR);
WINBASEAPI BOOL WINAPI EnumLanguageGroupLocalesA(LANGGROUPLOCALE_ENUMPROCA,LGRPID,DWORD,LONG_PTR);
WINBASEAPI BOOL WINAPI EnumLanguageGroupLocalesW(LANGGROUPLOCALE_ENUMPROCW,LGRPID,DWORD,LONG_PTR);
WINBASEAPI BOOL WINAPI EnumUILanguagesA(UILANGUAGE_ENUMPROCA,DWORD,LONG_PTR);
WINBASEAPI BOOL WINAPI EnumUILanguagesW(UILANGUAGE_ENUMPROCW,DWORD,LONG_PTR);
WINBASEAPI LANGID WINAPI GetSystemDefaultUILanguage(void);
WINBASEAPI LANGID WINAPI GetUserDefaultUILanguage(void);
WINBASEAPI BOOL WINAPI IsValidLanguageGroup(LGRPID,DWORD);
#endif /* (WINVER >= 0x0500) */

#ifdef UNICODE
#define CALINFO_ENUMPROC CALINFO_ENUMPROCW
#define CALINFO_ENUMPROCEX CALINFO_ENUMPROCEXW
#define LOCALE_ENUMPROC LOCALE_ENUMPROCW
#define CODEPAGE_ENUMPROC CODEPAGE_ENUMPROCW
#define DATEFMT_ENUMPROC DATEFMT_ENUMPROCW
#define DATEFMT_ENUMPROCEX DATEFMT_ENUMPROCEXW
#define TIMEFMT_ENUMPROC TIMEFMT_ENUMPROCW
#define LANGUAGEGROUP_ENUMPROC LANGUAGEGROUP_ENUMPROCW
#define LANGGROUPLOCALE_ENUMPROC LANGGROUPLOCALE_ENUMPROCW
#define UILANGUAGE_ENUMPROC UILANGUAGE_ENUMPROCW
typedef CPINFOEXW CPINFOEX;
typedef LPCPINFOEXW LPCPINFOEX;
typedef CURRENCYFMTW CURRENCYFMT;
typedef LPCURRENCYFMTW LPCURRENCYFMT;
typedef NUMBERFMTW NUMBERFMT;
typedef LPNUMBERFMTW LPNUMBERFMT;
/**
 * Compares two strings using a locale's collation rules.
 *
 * Windows CE always uses a string sort (SORT_STRINGSORT), so hyphens and
 * apostrophes sort with the other symbols. Subtract 2 from a nonzero result
 * to get a C-style comparison. "Equal" means equal for sorting, not
 * necessarily identical.
 *
 * @param Locale LOCALE_SYSTEM_DEFAULT, LOCALE_USER_DEFAULT or a MAKELCID
 *        value.
 * @param dwCmpFlags 0 or NORM_IGNORECASE. Windows CE doesn't support
 *        NORM_IGNOREKANATYPE, NORM_IGNORENONSPACE, NORM_IGNORESYMBOLS or
 *        NORM_IGNOREWIDTH.
 * @param lpString1 First string.
 * @param cchCount1 Length of lpString1 in characters, or -1 if
 *        null-terminated.
 * @param lpString2 Second string.
 * @param cchCount2 Length of lpString2 in characters, or -1 if
 *        null-terminated.
 * @return 1 (less than), 2 (equal) or 3 (greater than), or 0 on failure
 *         (see GetLastError).
 */
#define CompareString CompareStringW
/**
 * Enumerates one item of calendar information for a locale's calendars.
 *
 * Calls lpCalInfoEnumProc with each string until it returns FALSE or the
 * calendars run out.
 *
 * @param lpCalInfoEnumProc Callback receiving each string.
 * @param Locale LOCALE_SYSTEM_DEFAULT, LOCALE_USER_DEFAULT or a MAKELCID
 *        value.
 * @param Calendar A calendar identifier (CAL_GREGORIAN and so on), or
 *        ENUM_ALL_CALENDARS.
 * @param CalType The item to return, a CAL_* value such as CAL_SERASTRING
 *        or CAL_SLONGDATE.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
#define EnumCalendarInfo EnumCalendarInfoW
/**
 * Enumerates the code pages installed on or supported by the system.
 *
 * Calls lpCodePageEnumProc with each code page identifier, as a string,
 * until it returns FALSE or the code pages run out.
 *
 * @param lpCodePageEnumProc Callback receiving each code page.
 * @param dwFlags CP_INSTALLED or CP_SUPPORTED, not both.
 * @return Nonzero on success, zero on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define EnumSystemCodePages EnumSystemCodePagesW
/**
 * Enumerates the locales installed on or supported by the system.
 *
 * Calls lpLocaleEnumProc with each locale identifier, as a hex string, until
 * it returns FALSE or the locales run out.
 *
 * @param lpLocaleEnumProc Callback receiving each locale.
 * @param dwFlags LCID_INSTALLED or LCID_SUPPORTED, not both. Windows CE
 *        doesn't support LCID_ALTERNATE_SORTS.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
#define EnumSystemLocales EnumSystemLocalesW
/**
 * Enumerates a locale's time formats.
 *
 * Calls lpTimeFmtEnumProc with each format picture until it returns FALSE or
 * the formats run out.
 *
 * @param lpTimeFmtEnumProc Callback receiving each format string.
 * @param Locale LOCALE_SYSTEM_DEFAULT, LOCALE_USER_DEFAULT or a MAKELCID
 *        value.
 * @param dwFlags Must be 0.
 * @return TRUE on success, FALSE on failure (see GetLastError).
 */
#define EnumTimeFormats EnumTimeFormatsW
/**
 * Maps a string to another, folding character variants as requested.
 *
 * The source and destination buffers must differ. The result is
 * null-terminated if the source is.
 *
 * @param dwMapFlags One or more of MAP_FOLDCZONE (compatibility zone
 *        characters to standard Unicode), MAP_FOLDDIGITS (all digits to
 *        0-9), MAP_PRECOMPOSED or MAP_COMPOSITE (not both), and
 *        MAP_EXPAND_LIGATURES (not with MAP_PRECOMPOSED or MAP_COMPOSITE).
 * @param lpSrcStr The source string.
 * @param cchSrc Length of lpSrcStr in characters, or -1 if null-terminated.
 * @param lpDestStr Receives the mapped string.
 * @param cchDest Size of lpDestStr in characters, or 0 to query the size
 *        needed.
 * @return Characters written, or the size needed if cchDest is 0, or 0 on
 *         failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define FoldString FoldStringW
#define GetCalendarInfo GetCalendarInfoW
#define GetCPInfoEx GetCPInfoExW
/**
 * Formats a number string as currency.
 *
 * Windows CE ignores Locale and always uses the system locale.
 *
 * @param Locale Pass LOCALE_SYSTEM_DEFAULT.
 * @param dwFlags Must be 0.
 * @param lpValue The number: digits, an optional leading minus sign and at
 *        most one decimal point.
 * @param lpFormat Currency format, with every member set, or NULL for the
 *        locale's format.
 * @param lpCurrencyStr Receives the formatted string.
 * @param cchCurrency Size of lpCurrencyStr in characters, or 0 to query the
 *        size needed.
 * @return Characters written, or the size needed if cchCurrency is 0, or 0
 *         on failure (see GetLastError).
 */
#define GetCurrencyFormat GetCurrencyFormatW
/**
 * Formats a date as a string.
 *
 * Windows CE ignores Locale and always uses the system locale. The time
 * fields of lpDate are ignored. A wrong wDayOfWeek is corrected; other
 * invalid fields fail with ERROR_INVALID_PARAMETER. Bad format pictures
 * don't fail: the function does its best.
 *
 * @param Locale Pass LOCALE_SYSTEM_DEFAULT.
 * @param dwFlags DATE_SHORTDATE (default) or DATE_LONGDATE if lpFormat is
 *        NULL, otherwise 0. Windows CE doesn't support LOCALE_NOUSEROVERRIDE
 *        or DATE_USE_ALT_CALENDAR.
 * @param lpDate The date, or NULL for today's local date.
 * @param lpFormat Format picture built from d, dd, ddd, dddd, M, MM, MMM,
 *        MMMM, y, yy, yyyy and gg, with literal text in single quotes, or
 *        NULL for the locale's format.
 * @param lpDateStr Receives the formatted date.
 * @param cchDate Size of lpDateStr in characters, or 0 to query the size
 *        needed.
 * @return Characters written, or the size needed if cchDate is 0, or 0 on
 *         failure (see GetLastError).
 */
#define GetDateFormat GetDateFormatW
#define GetGeoInfo GetGeoInfoW
/**
 * Gets one item of information about a locale, as a string.
 *
 * Numeric values are returned as decimal text.
 *
 * @param Locale LOCALE_SYSTEM_DEFAULT, LOCALE_USER_DEFAULT or a MAKELCID
 *        value.
 * @param LCType A LOCALE_* item, e.g. LOCALE_SDECIMAL or LOCALE_SSHORTDATE,
 *        optionally OR'd with LOCALE_NOUSEROVERRIDE to ignore user settings.
 * @param lpLCData Receives the data.
 * @param cchData Size of lpLCData in characters, or 0 to query the size
 *        needed.
 * @return Characters written, or the size needed if cchData is 0, or 0 on
 *         failure (see GetLastError).
 */
#define GetLocaleInfo GetLocaleInfoW
/**
 * Formats a number string with a locale's separators, grouping and decimal
 * places.
 *
 * Windows CE ignores Locale and always uses the system locale.
 *
 * @param Locale Pass LOCALE_SYSTEM_DEFAULT.
 * @param dwFlags Must be 0.
 * @param lpValue The number: digits, an optional leading minus sign and at
 *        most one decimal point.
 * @param lpFormat Number format, with every member set, or NULL for the
 *        locale's format.
 * @param lpNumberStr Receives the formatted string.
 * @param cchNumber Size of lpNumberStr in characters, or 0 to query the size
 *        needed.
 * @return Characters written, or the size needed if cchNumber is 0, or 0 on
 *         failure (see GetLastError).
 */
#define GetNumberFormat GetNumberFormatW
/**
 * Returns character-type flags for each character in a string.
 *
 * Fills one WORD per character. The types depend only on the Unicode code
 * point, not the locale.
 *
 * @param Locale Ignored on Windows CE. Pass LOCALE_SYSTEM_DEFAULT or
 *        LOCALE_USER_DEFAULT.
 * @param dwInfoType CT_CTYPE1 (C1_UPPER, C1_DIGIT, C1_ALPHA and so on),
 *        CT_CTYPE2 (bidirectional layout, C2_*) or CT_CTYPE3 (text
 *        processing, C3_*).
 * @param lpSrcStr The string. Must not be the same buffer as lpCharType.
 * @param cchSrc Length in characters, or -1 if null-terminated. A count
 *        that includes the terminator also returns its type.
 * @param lpCharType Receives one WORD of flags per character.
 * @return Nonzero on success, or 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define GetStringTypeEx GetStringTypeExW
/**
 * Formats a time as a string, using a format picture or the locale's
 * default.
 *
 * The date fields of the SYSTEMTIME are ignored, and milliseconds are
 * never shown. An out-of-range time field fails with
 * ERROR_INVALID_PARAMETER, but a bad format picture doesn't fail.
 *
 * @param Locale Ignored: Windows CE always uses the system locale. Pass
 *        LOCALE_SYSTEM_DEFAULT.
 * @param dwFlags Zero or more of TIME_NOMINUTESORSECONDS, TIME_NOSECONDS,
 *        TIME_NOTIMEMARKER and TIME_FORCE24HOURFORMAT. Windows CE doesn't
 *        support LOCALE_NOUSEOVERRIDE.
 * @param lpTime The time to format, or NULL for the current local time.
 * @param lpFormat Format picture built from h, hh, H, HH, m, mm, s, ss, t
 *        and tt, with literal text in single quotes, e.g.
 *        L"hh':'mm':'ss tt". NULL for the locale's time format.
 * @param lpTimeStr Receives the string.
 * @param cchTime Buffer size in characters, or 0 to query the size needed.
 * @return Characters written including the terminator, or the size needed
 *         if cchTime is 0, or 0 on failure (see GetLastError).
 */
#define GetTimeFormat GetTimeFormatW
/**
 * Transforms a string (case, width, kana) or generates a sort key for it.
 *
 * With LCMAP_SORTKEY, the output is a null-terminated array of bytes, not
 * WCHARs, and sizes are in bytes; compare sort keys byte by byte.
 *
 * @param Locale Locale for the mapping, e.g. LOCALE_USER_DEFAULT.
 * @param dwMapFlags LCMAP_LOWERCASE, LCMAP_UPPERCASE, LCMAP_HALFWIDTH,
 *        LCMAP_FULLWIDTH, LCMAP_HIRAGANA, LCMAP_KATAKANA, LCMAP_BYTEREV or
 *        LCMAP_SORTKEY, plus NORM_* and SORT_STRINGSORT flags for sort
 *        keys. Opposing pairs are mutually exclusive, and LCMAP_SORTKEY
 *        combines only with LCMAP_BYTEREV among the LCMAP_* flags.
 *        Windows CE doesn't support LCMAP_LINGUISTIC_CASING,
 *        LCMAP_SIMPLIFIED_CHINESE or LCMAP_TRADITIONAL_CHINESE.
 * @param lpSrcStr The source string. Must not be the same buffer as
 *        lpDestStr.
 * @param cchSrc Length in characters, or -1 if null-terminated.
 * @param lpDestStr Receives the mapped string or sort key.
 * @param cchDest Buffer size in characters (bytes for a sort key), or 0 to
 *        query the size needed.
 * @return Characters (or bytes) written including the terminator, or the
 *         size needed if cchDest is 0, or 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define LCMapString LCMapStringW
#define SetCalendarInfo  SetCalendarInfoW
/**
 * Sets one item of the user's locale settings.
 *
 * Changes the user override, not the system defaults. Numeric items are
 * passed as text.
 *
 * @param Locale Locale to change.
 * @param LCType One LOCALE_* item, e.g. LOCALE_SSHORTDATE, LOCALE_STIME,
 *        LOCALE_SCURRENCY or LOCALE_ITIME. Windows CE adds
 *        LOCALE_SYEARMONTH and doesn't support LOCALE_IPAPERSIZE.
 * @param lpLCData The new value as a null-terminated string, in the
 *        item's format.
 * @return Nonzero on success, or 0 on failure (see GetLastError).
 *
 * @note Windows CE 2.0 and 3.0 only.
 */
#define SetLocaleInfo SetLocaleInfoW
#if (WINVER >= 0x0500)
#define EnumCalendarInfoEx EnumCalendarInfoExW
#define EnumDateFormatsEx EnumDateFormatsExW
#define EnumSystemLanguageGroups EnumSystemLanguageGroupsW
#define EnumLanguageGroupLocales EnumLanguageGroupLocalesW
#define EnumUILanguages EnumUILanguagesW
#endif /* (WINVER >= 0x0500) */
#else
#define CALINFO_ENUMPROC CALINFO_ENUMPROCA
#define CALINFO_ENUMPROCEX CALINFO_ENUMPROCEXA
#define LOCALE_ENUMPROC LOCALE_ENUMPROCA
#define CODEPAGE_ENUMPROC CODEPAGE_ENUMPROCA
#define DATEFMT_ENUMPROC DATEFMT_ENUMPROCA
#define DATEFMT_ENUMPROCEX DATEFMT_ENUMPROCEXA
#define TIMEFMT_ENUMPROC TIMEFMT_ENUMPROCA
#define LANGUAGEGROUP_ENUMPROC LANGUAGEGROUP_ENUMPROCA
#define LANGGROUPLOCALE_ENUMPROC LANGGROUPLOCALE_ENUMPROCA
#define UILANGUAGE_ENUMPROC UILANGUAGE_ENUMPROCA
typedef CPINFOEXA CPINFOEX;
typedef LPCPINFOEXA LPCPINFOEX;
typedef CURRENCYFMTA CURRENCYFMT;
typedef LPCURRENCYFMTA LPCURRENCYFMT;
typedef NUMBERFMTA NUMBERFMT;
typedef LPNUMBERFMTA LPNUMBERFMT;
#define CompareString CompareStringA
#define EnumCalendarInfo EnumCalendarInfoA
#define EnumSystemCodePages EnumSystemCodePagesA
#define EnumSystemLocales EnumSystemLocalesA
#define EnumTimeFormats EnumTimeFormatsA
#define FoldString FoldStringA
#define GetCalendarInfo GetCalendarInfoA
#define GetCPInfoEx GetCPInfoExA
#define GetCurrencyFormat GetCurrencyFormatA
#define GetDateFormat GetDateFormatA
#define GetGeoInfo GetGeoInfoA
#define GetLocaleInfo GetLocaleInfoA
#define GetNumberFormat GetNumberFormatA
#define GetStringTypeEx GetStringTypeExA
#define GetTimeFormat GetTimeFormatA
#define LCMapString LCMapStringA
#define SetCalendarInfo SetCalendarInfoA
#define SetLocaleInfo SetLocaleInfoA
#if (WINVER >= 0x0500)
#define EnumCalendarInfoEx EnumCalendarInfoExA
#define EnumDateFormatsEx EnumDateFormatsExA
#define EnumSystemLanguageGroups EnumSystemLanguageGroupsA
#define EnumLanguageGroupLocales EnumLanguageGroupLocalesA
#define EnumUILanguages EnumUILanguagesA
#endif /* (WINVER >= 0x0500) */
#endif /* UNICODE */
#endif /* RC_INVOKED */
#ifdef __cplusplus
}
#endif
#endif
