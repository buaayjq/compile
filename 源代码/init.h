# define txmax 1000               /*名字表容量*/
# define nmax  14                /*number的最大位数*/
# define al 10                   /*符号的最大长度*/
# define amax 1000
# define levmax 3                /*最大允许过程嵌套声明层数[0，lexmax]*/
# define cxmax 200               /*最多的虚拟机代码数*/



int line = 1;
int isEnd = 0;
int integernum;
double realnum;
char id[20];
char token[100];
int tokenbufpoint =0;
char ch;
char zf;
char zfc[100];
/*符号*/
enum symbol{
    becames,add,minus,times,slash,less,lessorequal,more,moreorequal,notequal,equal,semicolon,constsym,intsym,ident,integer,comma
,floatsym,realnumber,charsym,character,unsignedinteger,leftbracket,rightbracket,leftparent,rightparent,leftcurlybracket,rightcurlybracket,
voidsym,mainsym,ifsym,elsesym,whilesym,switchsym,casesym,colon,scanfsym,printfsym,returnsym,string,eofsym};

enum symbol sym;

char *symbolList[]={"becames","add","minus","times","slash","less","lessorequal","more","moreorequal","notequal","equal","semicolon","constsym","intsym","ident","integer","comma"
,"floatsym","realnumber","charsym","character","unsignedinteger","leftbracket","rightbracket","leftparent","rightparent","leftcurlybracket","rightcurlybracket",
"voidsym","mainsym","ifsym","elsesym","whilesym","switchsym","casesym","colon","scanfsym","printfsym","returnsym","string"};

struct func{
    int paranum; //参数个数
    int parameter[20];
    int start;
    int funcpoint;
};

union Valuetype{
    int intval;
    char charval;
    double floatval;
    struct func funcval;
};

struct tablestruct
{
    char name[20];                            /*名字*/
    int level;                                /*所处层*/
    int type;                                  /*标识符*/
    int size;                                 /*数组长度*/
    int kind;
    union Valuetype valuetype;                         /*类型：int float char fun*/
    int offset;                                    //地址偏移
    //bool ret;                                 /*是否有返回值*/
    int ret;
    int parameter;                            /*参数个数*/
};
struct tablestruct table[txmax];
int tabtop;

enum fct{
    ADD,LIT,SUB,MUL,DIV,LOD,LODT,LOA,STT,JPC,JMP,INT,STI,JMB,STO,QUT,LOG,LOGT,rei,ref,rec,wr,ws
};

char *fct_[]={
    "ADD","LIT","SUB","MUL","DIV","LOD","LODT","LOA","STT","JPC","JMP","INT","STI","JMB","STO","QUT","LOG","LOGT","rei","ref","rec","wr","ws"
    };

union pkind{
    int intkind;
    float floatkind;
};

struct instruction
{
  enum fct f;
  union pkind l;
  union pkind a;
  int isfloat;
};

int cx;
struct instruction code[cxmax];

char buff[100][100];
int bufftop;

FILE *in;
FILE *fout;

int mainSize;
int beginMain;
int mainTable;

char midvalue[60];
int txarray[200]={0};
int arrayindex;
int err;                                       /*错误计数器*/
int is_error = 0;       //错误标识


void getch();
void clearToken(int i);
void resultPrint(int sym,char id[],int integernum,float realnum);
void getsym();
void error();
void gen(enum fct x,int y,int z);
void genf(enum fct x,int y,float z);
void enter(int add,char *name,int level,int type,int kind,int size,int ret);
void enter_function_value(int type);
void enter_function_big(int start);
void cleanTable();
int find(char* name);
int lookup(char *name);
int lookupmain(char *name);
int factor();
int terms();
int expression();
void ifstatement();
void whilestatement();
void assignstatement();
void readstatement();
void writestatement();
void switchstatement();
void returnstatement();
void statement();
int vardefine();
void vardefine_inmain();
int integerjudge();

int realnumjudge();
void constdefine(int c_lev);
void mainfun();
void program();
void interupt();







