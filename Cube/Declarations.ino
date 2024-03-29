//DEFINE the pins for the layers

#define ModeSwitchOne
#define ModeSwitchTwo
#define ModeSwitchThree
#define ModeSwitchFour

#define BrigPot

//LayerDuration = 250/(frame rate)
//DEFINE the channels for each column of LEDs

//for RED channel
#define AAchr 33
#define ABchr 34
#define ACchr 35
#define ADchr 36

#define BAchr 37
#define BBchr 38
#define BCchr 39
#define BDchr 40

#define CAchr 41
#define CBchr 42
#define CCchr 43
#define CDchr 44

#define DAchr 45
#define DBchr 46
#define DCchr 47
#define DDchr 48

//for GREEN channel
#define AAchg 1
#define ABchg 2
#define ACchg 3
#define ADchg 4

#define BAchg 5
#define BBchg 6
#define BCchg 7
#define BDchg 8

#define CAchg 9
#define CBchg 10
#define CCchg 11
#define CDchg 12

#define DAchg 13
#define DBchg 14
#define DCchg 15
#define DDchg 16

//for BLUE channel
#define AAchb 17
#define ABchb 18
#define ACchb 19
#define ADchb 20

#define BAchb 21
#define BBchb 22
#define BCchb 23
#define BDchb 24

#define CAchb 25
#define CBchb 26
#define CCchb 27
#define CDchb 28

#define DAchb 29
#define DBchb 30
#define DCchb 31
#define DDchb 32

//variables for storing the values of the LEDs, RED channel.

int AAAr = 500;
int AABr = 500;
int AACr = 500;
int AADr = 500;

int ABAr = 500;
int ABBr = 500;
int ABCr = 500;
int ABDr = 500;

int ACAr = 500;
int ACBr = 500;
int ACCr = 500;
int ACDr = 500;

int ADAr = 500;
int ADBr = 500;
int ADCr = 500;
int ADDr = 500;


int BAAr = 500;
int BABr = 500;
int BACr = 500;
int BADr = 500;

int BBAr = 500;
int BBBr = 500;
int BBCr = 500;
int BBDr = 500;

int BCAr = 500;
int BCBr = 500;
int BCCr = 500;
int BCDr = 500;

int BDAr = 500;
int BDBr = 500;
int BDCr = 500;
int BDDr = 500;

int CAAr = 500;
int CABr = 500;
int CACr = 500;
int CADr = 500;

int CBAr = 500;
int CBBr = 500;
int CBCr = 500;
int CBDr = 500;

int CCAr = 500;
int CCBr = 500;
int CCCr = 500;
int CCDr = 500;

int CDAr = 500;
int CDBr = 500;
int CDCr = 500;
int CDDr = 500;


int DAAr = 500;
int DABr = 500;
int DACr = 500;
int DADr = 500;

int DBAr = 500;
int DBBr = 500;
int DBCr = 500;
int DBDr = 500;

int DCAr = 500;
int DCBr = 500;
int DCCr = 500;
int DCDr = 500;

int DDAr = 500;
int DDBr = 500;
int DDCr = 500;
int DDDr = 500;

//variables for storing the values of the LEDs, GREEN channel.

int AAAg = 500;
int AABg = 500;
int AACg = 500;
int AADg = 500;

int ABAg = 500;
int ABBg = 500;
int ABCg = 500;
int ABDg = 500;

int ACAg = 500;
int ACBg = 500;
int ACCg = 500;
int ACDg = 500;

int ADAg = 500;
int ADBg = 500;
int ADCg = 500;
int ADDg = 500;


int BAAg = 500;
int BABg = 500;
int BACg = 500;
int BADg = 500;

int BBAg = 500;
int BBBg = 500;
int BBCg = 500;
int BBDg = 500;

int BCAg = 500;
int BCBg = 500;
int BCCg = 500;
int BCDg = 500;

int BDAg = 500;
int BDBg = 500;
int BDCg = 500;
int BDDg = 500;


int CAAg = 500;
int CABg = 500;
int CACg = 500;
int CADg = 500;

int CBAg = 500;
int CBBg = 500;
int CBCg = 500;
int CBDg = 500;

int CCAg = 500;
int CCBg = 500;
int CCCg = 500;
int CCDg = 500;

int CDAg = 500;
int CDBg = 500;
int CDCg = 500;
int CDDg = 500;


int DAAg = 500;
int DABg = 500;
int DACg = 500;
int DADg = 500;

int DBAg = 500;
int DBBg = 500;
int DBCg = 500;
int DBDg = 500;

int DCAg = 500;
int DCBg = 500;
int DCCg = 500;
int DCDg = 500;

int DDAg = 500;
int DDBg = 500;
int DDCg = 500;
int DDDg = 500;

//variables for storing the values of the LEDs, BLUE channel.

int AAAb = 500;
int AABb = 500;
int AACb = 500;
int AADb = 500;

int ABAb = 500;
int ABBb = 500;
int ABCb = 500;
int ABDb = 500;

int ACAb = 500;
int ACBb = 500;
int ACCb = 500;
int ACDb = 500;

int ADAb = 500;
int ADBb = 500;
int ADCb = 500;
int ADDb = 500;

int BAAb = 500;
int BABb = 500;
int BACb = 500;
int BADb = 500;

int BBAb = 500;
int BBBb = 500;
int BBCb = 500;
int BBDb = 500;

int BCAb = 500;
int BCBb = 500;
int BCCb = 500;
int BCDb = 500;

int BDAb = 500;
int BDBb = 500;
int BDCb = 500;
int BDDb = 500;


int CAAb = 500;
int CABb = 500;
int CACb = 500;
int CADb = 500;

int CBAb = 500;
int CBBb = 500;
int CBCb = 500;
int CBDb = 500;

int CCAb = 500;
int CCBb = 500;
int CCCb = 500;
int CCDb = 500;

int CDAb = 500;
int CDBb = 500;
int CDCb = 500;
int CDDb = 500;


int DAAb = 500;
int DABb = 500;
int DACb = 500;
int DADb = 500;

int DBAb = 500;
int DBBb = 500;
int DBCb = 500;
int DBDb = 500;

int DCAb = 500;
int DCBb = 500;
int DCCb = 500;
int DCDb = 500;

int DDAb = 500;
int DDBb = 500;
int DDCb = 500;
int DDDb = 500;


//others
int HueOutR;
int HueOutG;
int HueOutB;


