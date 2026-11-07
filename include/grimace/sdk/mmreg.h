#ifndef GRIMACE_SDK_MMREG_H
#define GRIMACE_SDK_MMREG_H

#include <msacm.h>

#ifdef __cplusplus
extern "C" {
#endif

struct adpcmcoef_tag;
typedef struct adpcmcoef_tag ADPCMCOEFSET;
struct adpcmewaveformat_tag;
typedef struct adpcmewaveformat_tag ADPCMEWAVEFORMAT;
struct adpcmwaveformat_tag;
typedef struct adpcmwaveformat_tag ADPCMWAVEFORMAT;
struct aptxwaveformat_tag;
typedef struct aptxwaveformat_tag APTXWAVEFORMAT;
struct audiofile_af10waveformat_tag;
typedef struct audiofile_af10waveformat_tag AUDIOFILE_AF10WAVEFORMAT;
struct audiofile_af36waveformat_tag;
typedef struct audiofile_af36waveformat_tag AUDIOFILE_AF36WAVEFORMAT;
struct contres_cr10waveformat_tag;
typedef struct contres_cr10waveformat_tag CONTRESCR10WAVEFORMAT;
struct contres_vqlpcwaveformat_tag;
typedef struct contres_vqlpcwaveformat_tag CONTRESVQLPCWAVEFORMAT;
struct creative_adpcmwaveformat_tag;
typedef struct creative_adpcmwaveformat_tag CREATIVEADPCMWAVEFORMAT;
struct creative_fastspeech10format_tag;
typedef struct creative_fastspeech10format_tag CREATIVEFASTSPEECH10WAVEFORMAT;
struct creative_fastspeech8format_tag;
typedef struct creative_fastspeech8format_tag CREATIVEFASTSPEECH8WAVEFORMAT;
struct csimaadpcmwaveformat_tag;
typedef struct csimaadpcmwaveformat_tag CSIMAADPCMWAVEFORMAT;
struct creative_fastspeechformat_tag;
typedef struct creative_fastspeechformat_tag DIALOGICOKIADPCMWAVEFORMAT;
struct digiadpcmmwaveformat_tag;
typedef struct digiadpcmmwaveformat_tag DIGIADPCMWAVEFORMAT;
struct digifixwaveformat_tag;
typedef struct digifixwaveformat_tag DIGIFIXWAVEFORMAT;
struct digirealwaveformat_tag;
typedef struct digirealwaveformat_tag DIGIREALWAVEFORMAT;
struct digistdwaveformat_tag;
typedef struct digistdwaveformat_tag DIGISTDWAVEFORMAT;
struct dolbyac2waveformat_tag;
typedef struct dolbyac2waveformat_tag DOLBYAC2WAVEFORMAT;
struct dvi_adpcmwaveformat_tag;
typedef struct dvi_adpcmwaveformat_tag DVIADPCMWAVEFORMAT;
struct echosc1waveformat_tag;
typedef struct echosc1waveformat_tag ECHOSC1WAVEFORMAT;
struct wavefilter_echo_tag;
typedef struct wavefilter_echo_tag ECHOWAVEFILTER;
struct tagEXBMINFOHEADER;
typedef struct tagEXBMINFOHEADER EXBMINFOHEADER;
struct fmtowns_snd_waveformat_tag;
typedef struct fmtowns_snd_waveformat_tag FMTOWNS_SND_WAVEFORMAT;
struct g721_adpcmwaveformat_tag;
typedef struct g721_adpcmwaveformat_tag G721_ADPCMWAVEFORMAT;
struct g723_adpcmwaveformat_tag;
typedef struct g723_adpcmwaveformat_tag G723_ADPCMWAVEFORMAT;
struct gsm610waveformat_tag;
typedef struct gsm610waveformat_tag GSM610WAVEFORMAT;
struct ima_adpcmwaveformat_tag;
typedef struct ima_adpcmwaveformat_tag IMAADPCMWAVEFORMAT;
struct tagJPEGINFOHEADER;
typedef struct tagJPEGINFOHEADER JPEGINFOHEADER;
typedef ADPCMCOEFSET *LPADPCMCOEFSET;
typedef ADPCMEWAVEFORMAT *LPADPCMEWAVEFORMAT;
typedef ADPCMWAVEFORMAT *LPADPCMWAVEFORMAT;
typedef APTXWAVEFORMAT *LPAPTXWAVEFORMAT;
typedef AUDIOFILE_AF10WAVEFORMAT *LPAUDIOFILE_AF10WAVEFORMAT;
typedef AUDIOFILE_AF36WAVEFORMAT *LPAUDIOFILE_AF36WAVEFORMAT;
typedef CONTRESCR10WAVEFORMAT *LPCONTRESCR10WAVEFORMAT;
typedef CONTRESVQLPCWAVEFORMAT *LPCONTRESVQLPCWAVEFORMAT;
typedef CREATIVEADPCMWAVEFORMAT *LPCREATIVEADPCMWAVEFORMAT;
typedef CREATIVEFASTSPEECH10WAVEFORMAT *LPCREATIVEFASTSPEECH10WAVEFORMAT;
typedef CREATIVEFASTSPEECH8WAVEFORMAT *LPCREATIVEFASTSPEECH8WAVEFORMAT;
typedef CSIMAADPCMWAVEFORMAT *LPCSIMAADPCMWAVEFORMAT;
typedef DIALOGICOKIADPCMWAVEFORMAT *LPDIALOGICOKIADPCMWAVEFORMAT;
typedef DIGIADPCMWAVEFORMAT *LPDIGIADPCMWAVEFORMAT;
typedef DIGIFIXWAVEFORMAT *LPDIGIFIXWAVEFORMAT;
typedef DIGIREALWAVEFORMAT *LPDIGIREALWAVEFORMAT;
typedef DIGISTDWAVEFORMAT *LPDIGISTDWAVEFORMAT;
typedef DVIADPCMWAVEFORMAT *LPDVIADPCMWAVEFORMAT;
typedef ECHOSC1WAVEFORMAT *LPECHOSC1WAVEFORMAT;
typedef ECHOWAVEFILTER *LPECHOWAVEFILTER;
typedef FMTOWNS_SND_WAVEFORMAT *LPFMTOWNS_SND_WAVEFORMAT;
typedef G721_ADPCMWAVEFORMAT *LPG721_ADPCMWAVEFORMAT;
typedef G723_ADPCMWAVEFORMAT *LPG723_ADPCMWAVEFORMAT;
typedef GSM610WAVEFORMAT *LPGSM610WAVEFORMAT;
typedef IMAADPCMWAVEFORMAT *LPIMAADPCMWAVEFORMAT;
struct mediaspace_adpcmwaveformat_tag;
typedef struct mediaspace_adpcmwaveformat_tag MEDIASPACEADPCMWAVEFORMAT;
typedef MEDIASPACEADPCMWAVEFORMAT *LPMEDIASPACEADPCMWAVEFORMAT;
struct mpeg1waveformat_tag;
typedef struct mpeg1waveformat_tag MPEG1WAVEFORMAT;
typedef MPEG1WAVEFORMAT *LPMPEG1WAVEFORMAT;
struct mpeglayer3waveformat_tag;
typedef struct mpeglayer3waveformat_tag MPEGLAYER3WAVEFORMAT;
typedef MPEGLAYER3WAVEFORMAT *LPMPEGLAYER3WAVEFORMAT;
struct nms_vbxadpcmmwaveformat_tag;
typedef struct nms_vbxadpcmmwaveformat_tag NMS_VBXADPCMWAVEFORMAT;
typedef NMS_VBXADPCMWAVEFORMAT *LPNMS_VBXADPCMWAVEFORMAT;
struct oliadpcmwaveformat_tag;
typedef struct oliadpcmwaveformat_tag OLIADPCMWAVEFORMAT;
typedef OLIADPCMWAVEFORMAT *LPOLIADPCMWAVEFORMAT;
struct olicelpwaveformat_tag;
typedef struct olicelpwaveformat_tag OLICELPWAVEFORMAT;
typedef OLICELPWAVEFORMAT *LPOLICELPWAVEFORMAT;
struct oligsmwaveformat_tag;
typedef struct oligsmwaveformat_tag OLIGSMWAVEFORMAT;
typedef OLIGSMWAVEFORMAT *LPOLIGSMWAVEFORMAT;
struct olioprwaveformat_tag;
typedef struct olioprwaveformat_tag OLIOPRWAVEFORMAT;
typedef OLIOPRWAVEFORMAT *LPOLIOPRWAVEFORMAT;
struct olisbcwaveformat_tag;
typedef struct olisbcwaveformat_tag OLISBCWAVEFORMAT;
typedef OLISBCWAVEFORMAT *LPOLISBCWAVEFORMAT;
struct sierra_adpcmwaveformat_tag;
typedef struct sierra_adpcmwaveformat_tag SIERRAADPCMWAVEFORMAT;
typedef SIERRAADPCMWAVEFORMAT *LPSIERRAADPCMWAVEFORMAT;
struct sonarcwaveformat_tag;
typedef struct sonarcwaveformat_tag SONARCWAVEFORMAT;
typedef SONARCWAVEFORMAT *LPSONARCWAVEFORMAT;
struct truespeechwaveformat_tag;
typedef struct truespeechwaveformat_tag TRUESPEECHWAVEFORMAT;
typedef TRUESPEECHWAVEFORMAT *LPTRUESPEECHWAVEFORMAT;
struct wavefilter_volume_tag;
typedef struct wavefilter_volume_tag VOLUMEWAVEFILTER;
typedef VOLUMEWAVEFILTER *LPVOLUMEWAVEFILTER;
struct yamaha_adpmcwaveformat_tag;
typedef struct yamaha_adpmcwaveformat_tag YAMAHA_ADPCMWAVEFORMAT;
typedef YAMAHA_ADPCMWAVEFORMAT *LPYAMAHA_ADPCMWAVEFORMAT;
typedef ADPCMCOEFSET *NPADPCMCOEFSET;
typedef ADPCMEWAVEFORMAT *NPADPCMEWAVEFORMAT;
typedef ADPCMWAVEFORMAT *NPADPCMWAVEFORMAT;
typedef APTXWAVEFORMAT *NPAPTXWAVEFORMAT;
typedef AUDIOFILE_AF10WAVEFORMAT *NPAUDIOFILE_AF10WAVEFORMAT;
typedef AUDIOFILE_AF36WAVEFORMAT *NPAUDIOFILE_AF36WAVEFORMAT;
typedef CONTRESCR10WAVEFORMAT *NPCONTRESCR10WAVEFORMAT;
typedef CONTRESVQLPCWAVEFORMAT *NPCONTRESVQLPCWAVEFORMAT;
typedef CREATIVEADPCMWAVEFORMAT *NPCREATIVEADPCMWAVEFORMAT;
typedef CREATIVEFASTSPEECH10WAVEFORMAT *NPCREATIVEFASTSPEECH10WAVEFORMAT;
typedef CREATIVEFASTSPEECH8WAVEFORMAT *NPCREATIVEFASTSPEECH8WAVEFORMAT;
typedef CSIMAADPCMWAVEFORMAT *NPCSIMAADPCMWAVEFORMAT;
typedef DIALOGICOKIADPCMWAVEFORMAT *NPDIALOGICOKIADPCMWAVEFORMAT;
typedef DIGIADPCMWAVEFORMAT *NPDIGIADPCMWAVEFORMAT;
typedef DIGIFIXWAVEFORMAT *NPDIGIFIXWAVEFORMAT;
typedef DIGIREALWAVEFORMAT *NPDIGIREALWAVEFORMAT;
typedef DIGISTDWAVEFORMAT *NPDIGISTDWAVEFORMAT;
typedef DVIADPCMWAVEFORMAT *NPDVIADPCMWAVEFORMAT;
typedef ECHOSC1WAVEFORMAT *NPECHOSC1WAVEFORMAT;
typedef ECHOWAVEFILTER *NPECHOWAVEFILTER;
typedef FMTOWNS_SND_WAVEFORMAT *NPFMTOWNS_SND_WAVEFORMAT;
typedef G721_ADPCMWAVEFORMAT *NPG721_ADPCMWAVEFORMAT;
typedef G723_ADPCMWAVEFORMAT *NPG723_ADPCMWAVEFORMAT;
typedef GSM610WAVEFORMAT *NPGSM610WAVEFORMAT;
typedef IMAADPCMWAVEFORMAT *NPIMAADPCMWAVEFORMAT;
typedef MEDIASPACEADPCMWAVEFORMAT *NPMEDIASPACEADPCMWAVEFORMAT;
typedef MPEG1WAVEFORMAT *NPMPEG1WAVEFORMAT;
typedef MPEGLAYER3WAVEFORMAT *NPMPEGLAYER3WAVEFORMAT;
typedef NMS_VBXADPCMWAVEFORMAT *NPNMS_VBXADPCMWAVEFORMAT;
typedef OLIADPCMWAVEFORMAT *NPOLIADPCMWAVEFORMAT;
typedef OLICELPWAVEFORMAT *NPOLICELPWAVEFORMAT;
typedef OLIGSMWAVEFORMAT *NPOLIGSMWAVEFORMAT;
typedef OLIOPRWAVEFORMAT *NPOLIOPRWAVEFORMAT;
typedef OLISBCWAVEFORMAT *NPOLISBCWAVEFORMAT;
typedef SIERRAADPCMWAVEFORMAT *NPSIERRAADPCMWAVEFORMAT;
typedef SONARCWAVEFORMAT *NPSONARCWAVEFORMAT;
typedef TRUESPEECHWAVEFORMAT *NPTRUESPEECHWAVEFORMAT;
typedef VOLUMEWAVEFILTER *NPVOLUMEWAVEFILTER;
typedef WAVEFILTER *NPWAVEFILTER;
typedef YAMAHA_ADPCMWAVEFORMAT *NPYAMAHA_ADPCMWAVEFORMAT;
typedef ADPCMCOEFSET *PADPCMCOEFSET;
typedef ADPCMEWAVEFORMAT *PADPCMEWAVEFORMAT;
typedef ADPCMWAVEFORMAT *PADPCMWAVEFORMAT;
typedef APTXWAVEFORMAT *PAPTXWAVEFORMAT;
typedef AUDIOFILE_AF10WAVEFORMAT *PAUDIOFILE_AF10WAVEFORMAT;
typedef AUDIOFILE_AF36WAVEFORMAT *PAUDIOFILE_AF36WAVEFORMAT;
typedef CONTRESCR10WAVEFORMAT *PCONTRESCR10WAVEFORMAT;
typedef CONTRESVQLPCWAVEFORMAT *PCONTRESVQLPCWAVEFORMAT;
typedef CREATIVEADPCMWAVEFORMAT *PCREATIVEADPCMWAVEFORMAT;
typedef CREATIVEFASTSPEECH10WAVEFORMAT *PCREATIVEFASTSPEECH10WAVEFORMAT;
typedef CREATIVEFASTSPEECH8WAVEFORMAT *PCREATIVEFASTSPEECH8WAVEFORMAT;
typedef CSIMAADPCMWAVEFORMAT *PCSIMAADPCMWAVEFORMAT;
typedef DIALOGICOKIADPCMWAVEFORMAT *PDIALOGICOKIADPCMWAVEFORMAT;
typedef DIGIADPCMWAVEFORMAT *PDIGIADPCMWAVEFORMAT;
typedef DIGIFIXWAVEFORMAT *PDIGIFIXWAVEFORMAT;
typedef DIGIREALWAVEFORMAT *PDIGIREALWAVEFORMAT;
typedef DIGISTDWAVEFORMAT *PDIGISTDWAVEFORMAT;
typedef DVIADPCMWAVEFORMAT *PDVIADPCMWAVEFORMAT;
typedef ECHOSC1WAVEFORMAT *PECHOSC1WAVEFORMAT;
typedef ECHOWAVEFILTER *PECHOWAVEFILTER;
typedef FMTOWNS_SND_WAVEFORMAT *PFMTOWNS_SND_WAVEFORMAT;
typedef G721_ADPCMWAVEFORMAT *PG721_ADPCMWAVEFORMAT;
typedef G723_ADPCMWAVEFORMAT *PG723_ADPCMWAVEFORMAT;
typedef GSM610WAVEFORMAT *PGSM610WAVEFORMAT;
typedef IMAADPCMWAVEFORMAT *PIMAADPCMWAVEFORMAT;
typedef MEDIASPACEADPCMWAVEFORMAT *PMEDIASPACEADPCMWAVEFORMAT;
typedef MPEG1WAVEFORMAT *PMPEG1WAVEFORMAT;
typedef MPEGLAYER3WAVEFORMAT *PMPEGLAYER3WAVEFORMAT;
typedef NMS_VBXADPCMWAVEFORMAT *PNMS_VBXADPCMWAVEFORMAT;
typedef OLIADPCMWAVEFORMAT *POLIADPCMWAVEFORMAT;
typedef OLICELPWAVEFORMAT *POLICELPWAVEFORMAT;
typedef OLIGSMWAVEFORMAT *POLIGSMWAVEFORMAT;
typedef OLIOPRWAVEFORMAT *POLIOPRWAVEFORMAT;
typedef OLISBCWAVEFORMAT *POLISBCWAVEFORMAT;
typedef SIERRAADPCMWAVEFORMAT *PSIERRAADPCMWAVEFORMAT;
typedef SONARCWAVEFORMAT *PSONARCWAVEFORMAT;
typedef TRUESPEECHWAVEFORMAT *PTRUESPEECHWAVEFORMAT;
typedef VOLUMEWAVEFILTER *PVOLUMEWAVEFILTER;
typedef WAVEFILTER *PWAVEFILTER;
typedef YAMAHA_ADPCMWAVEFORMAT *PYAMAHA_ADPCMWAVEFORMAT;
typedef struct {

} s_RIFFWAVE_inst;

struct adpcmcoef_tag {
    short iCoef1;
    short iCoef2;
} __attribute__((packed, aligned(1)));

struct adpcmewaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wSamplesPerBlock;
} __attribute__((packed, aligned(1)));

struct adpcmwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wSamplesPerBlock;
    WORD wNumCoef;
    ADPCMCOEFSET aCoef[];
} __attribute__((packed, aligned(1)));

struct aptxwaveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));

struct audiofile_af10waveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));

struct audiofile_af36waveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));

struct contres_cr10waveformat_tag {
    WAVEFORMATEX wfx;
    WORD wSamplesPerBlock;
} __attribute__((packed, aligned(1)));

struct contres_vqlpcwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wSamplesPerBlock;
} __attribute__((packed, aligned(1)));

struct creative_adpcmwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wRevision;
} __attribute__((packed, aligned(1)));

struct creative_fastspeech10format_tag {
    WAVEFORMATEX wfx;
    WORD wRevision;
} __attribute__((packed, aligned(1)));

struct creative_fastspeech8format_tag {
    WAVEFORMATEX wfx;
    WORD wRevision;
} __attribute__((packed, aligned(1)));

struct creative_fastspeechformat_tag {
    WAVEFORMATEX ewf;
} __attribute__((packed, aligned(1)));

struct csimaadpcmwaveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));

struct digiadpcmmwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wSamplesPerBlock;
} __attribute__((packed, aligned(1)));

struct digifixwaveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));

struct digirealwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wSamplesPerBlock;
} __attribute__((packed, aligned(1)));

struct digistdwaveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));

struct dolbyac2waveformat_tag {
    WAVEFORMATEX wfx;
    WORD nAuxBitsCode;
} __attribute__((packed, aligned(1)));

struct dvi_adpcmwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wSamplesPerBlock;
} __attribute__((packed, aligned(1)));

struct echosc1waveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));

struct fmtowns_snd_waveformat_tag {
    WAVEFORMATEX wfx;
    WORD wRevision;
} __attribute__((packed, aligned(1)));

struct g721_adpcmwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD nAuxBlockSize;
} __attribute__((packed, aligned(1)));

struct g723_adpcmwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD cbExtraSize;
    WORD nAuxBlockSize;
} __attribute__((packed, aligned(1)));

struct gsm610waveformat_tag {
    WAVEFORMATEX wfx;
    WORD wSamplesPerBlock;
} __attribute__((packed, aligned(1)));

struct ima_adpcmwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wSamplesPerBlock;
} __attribute__((packed, aligned(1)));

struct mediaspace_adpcmwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wRevision;
} __attribute__((packed, aligned(1)));

struct mpeg1waveformat_tag {
    WAVEFORMATEX wfx;
    WORD fwHeadLayer;
    DWORD dwHeadBitrate;
    WORD fwHeadMode;
    WORD fwHeadModeExt;
    WORD wHeadEmphasis;
    WORD fwHeadFlags;
    DWORD dwPTSLow;
    DWORD dwPTSHigh;
} __attribute__((packed, aligned(1)));

struct mpeglayer3waveformat_tag {
    WAVEFORMATEX wfx;
    WORD wID;
    DWORD fdwFlags;
    WORD nBlockSize;
    WORD nFramesPerBlock;
    WORD nCodecDelay;
} __attribute__((packed, aligned(1)));

struct nms_vbxadpcmmwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wSamplesPerBlock;
} __attribute__((packed, aligned(1)));

struct oliadpcmwaveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));

struct olicelpwaveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));

struct oligsmwaveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));

struct olioprwaveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));

struct olisbcwaveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));

struct sierra_adpcmwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wRevision;
} __attribute__((packed, aligned(1)));

struct sonarcwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wCompType;
} __attribute__((packed, aligned(1)));

struct tagEXBMINFOHEADER {
    BITMAPINFOHEADER bmi;
    DWORD biExtDataOffset;
} __attribute__((packed, aligned(1)));

struct tagJPEGINFOHEADER {
    DWORD JPEGSize;
    DWORD JPEGProcess;
    DWORD JPEGColorSpaceID;
    DWORD JPEGBitsPerSample;
    DWORD JPEGHSubSampling;
    DWORD JPEGVSubSampling;
} __attribute__((packed, aligned(1)));

struct tag_s_RIFFWAVE_inst;
struct tag_s_RIFFWAVE_inst {
    BYTE bUnshiftedNote;
    char chFineTune;
    char chGain;
    BYTE bLowNote;
    BYTE bHighNote;
    BYTE bLowVelocity;
    BYTE bHighVelocity;
} __attribute__((packed, aligned(1)));

struct truespeechwaveformat_tag {
    WAVEFORMATEX wfx;
    WORD wRevision;
    WORD nSamplesPerBlock;
    BYTE abReserved[28];
} __attribute__((packed, aligned(1)));

struct wavefilter_echo_tag {
    WAVEFILTER wfltr;
    DWORD dwVolume;
    DWORD dwDelay;
} __attribute__((packed, aligned(1)));

struct wavefilter_tag;
struct wavefilter_tag {
    DWORD cbStruct;
    DWORD dwFilterTag;
    DWORD fdwFilter;
    DWORD dwReserved[5];
} __attribute__((packed, aligned(1)));

struct wavefilter_volume_tag {
    WAVEFILTER wfltr;
    DWORD dwVolume;
} __attribute__((packed, aligned(1)));

struct yamaha_adpmcwaveformat_tag {
    WAVEFORMATEX wfx;
} __attribute__((packed, aligned(1)));


#ifdef __cplusplus
}
#endif

#endif
