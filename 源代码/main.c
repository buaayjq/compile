#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"init.h"
#include"interupt.h"

void error(int i);
void getch(){
    ch=fgetc(in);
}
void clearToken(int i){
    int j;
    for(j=0;j<i;j++){
        token[j]=0;
    }
}

int transnum(){
    int j=0;
    int num=0;
    for(j=0;j<tokenbufpoint;j++)
       num=num*10+token[j]-'0';
    return num;
}
int isLetter(){
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||ch=='_')
        {
            if(ch>='A'&&ch<='Z')
                ch='a'+ch-'A';
            return 1;
        }
    else
        return 0;
    }

int isDigit(){
   if((ch>='0'&&ch<='9'))
        return 1;
    else
        return 0;
   }
/*void resultPrint(int line,char *symbolList[],enum symbol sym){
	printf("%d   %s\n",line,symbolList[sym]);
}*/
void getsym(){
    if(isEnd)
        return;
    int i,j;
    i=j=0;
    while(ch==' '||ch=='\t'||ch=='\n'){//
        if(ch == '\n')
            line++;
        getch();
    }
    if(ch=='*'){
    	sym=times;
    	getch();
    }
    else if(ch=='/'){
    	sym=slash;
    	getch();
    }
    else if(ch==';'){
    	sym=semicolon;
    	getch();
    }
    else if(ch==':'){
    	sym=colon;
    	getch();
    }
    else if(ch=='+'){
    	sym=add;
    	getch();
    }
    else if(ch=='-'){
    	sym=minus;
    	getch();
    }
    else if(ch==','){
    	sym=comma;
    	getch();
    }
    else if(ch=='('){
    	sym=leftparent;
    	getch();
    }
    else if(ch==')'){
    	sym=rightparent;
    	getch();
    }
    else if(ch=='['){
    	sym=leftbracket;
    	getch();
    }
    else if(ch==']'){
    	sym=rightbracket;
    	getch();
    }
    else if(ch=='{'){
    	sym=leftcurlybracket;
    	getch();
    }
    else if(ch=='}'){
    	sym=rightcurlybracket;
    	getch();
    }
    else if(ch=='<'){
        getch();
        if(ch=='='){
            sym=lessorequal;
            getch();
        }
        else{
            sym=less;
        }
    }
    else if(ch=='>'){
        getch();
        if(ch=='='){
            sym=moreorequal;
            getch();
        }
        else{
            sym=more;
        }
    }
    else if(ch=='='){
        getch();
        if(ch=='='){
            sym=equal;
            getch();
        }
        else{
            sym=becames;
        }
    }
    else if(ch=='!'){
        getch();
        if(ch=='='){
            sym=notequal;
            getch();
        }
        else{
            error(1);
        }
    }
    else if(ch=='\''){
        getch();
        zf=ch;
        getch();
        if(ch!='\''){
            error(2);
        }
        else{
            getch();
        }
        sym=character;

    }
    else if(ch=='\"'){
        getch();
        while(ch==32||ch==33||ch>=35&&ch<=126){
            token[i]=ch;
            i++;
            getch();
        }
        if(ch!='\"'){
            error(2);
        }
        else{
            getch();
        }
        strcpy(zfc,token);
        clearToken(i);
        i=0;
        sym=string;
    }
    else if(ch=='0'){
        getch();
        if(ch>='0'&&ch<='9'){
            error(5);
        }
        else{
            if(ch=='.'){
                token[0]='0';
                token[1]='.';
                i=2;
                getch();
                while(ch>='0'&&ch<='9'){
                    token[i]=ch;
                    i++;
                    getch();
                }
                realnum=atof(token);
                clearToken(i);
                i=0;
                sym=realnumber;
            }
            else{
                sym=integer;
                integernum=0;
            }
        }
    }
    else if(ch>='1'&&ch<='9'){
        token[i]=ch;
        i++;
        getch();
        while(ch>='0'&&ch<='9'){
            token[i]=ch;
            i++;
            getch();
        }
        if(ch=='.'){
            token[i]=ch;
            i++;
            getch();
            while(ch>='0'&&ch<='9'){
                token[i]=ch;
                i++;
                getch();
            }
            realnum=atof(token);
            clearToken(i);
            i=0;
            sym=realnumber;
        }
        else{
            integernum=atoi(token);
            clearToken(i);
            i=0;
            sym=unsignedinteger;
        }
    }
    else if(ch>='A'&&ch<='Z'||ch=='_'||(ch>='a'&&ch<='z')){
        token[i]=ch;
        i++;
        getch();
        while(ch>='A'&&ch<='Z'||ch=='_'||ch>='0'&&ch<='9'||(ch>='a'&&ch<='z')){
            if(i>20){
                error(3);
            }
            token[i]=ch;
            i++;
            getch();
        }
        token[i]=0;
        if(strcmp(token,"const")==0){
        	sym=constsym;
        }
        else if(strcmp(token,"int")==0){
        	sym=intsym;
        }
        else if(strcmp(token,"float")==0){
        	sym=floatsym;
        }
        else if(strcmp(token,"char")==0){
        	sym=charsym;
        }
        else if(strcmp(token,"void")==0){
        	sym=voidsym;
        }
        else if(strcmp(token,"main")==0){
        	sym=mainsym;
        }
        else if(strcmp(token,"if")==0){
        	sym=ifsym;
        }
        else if(strcmp(token,"else")==0){
        	sym=elsesym;
        }
        else if(strcmp(token,"while")==0){
        	sym=whilesym;
        }
        else if(strcmp(token,"switch")==0){
        	sym=switchsym;
        }
        else if(strcmp(token,"case")==0){
        	sym=casesym;
        }
        else if(strcmp(token,"scanf")==0){
        	sym=scanfsym;
        }
        else if(strcmp(token,"printf")==0){
        	sym=printfsym;
        }
        else if(strcmp(token,"return")==0){
        	sym=returnsym;
        }
        else{
            sym=ident;
            j=0;
            for(j=0;j<i;j++){
                if(token[j]>='A'&&token[j]<='Z')
                token[j]+=32;
            }
            strcpy(id,token);
        }
        clearToken(i);
        i=0;
    }
    else{
        error(4);
        getch();
    }
    //printf("%d   %s\n",line,symbolList[sym]);
    //integernum = 0;
    //realnum = 0.0;
    if(ch==EOF){
        puts("end");
        isEnd=1;
    }
}

void gen(enum fct x,int y,int z){
	code[cx].f=x;
	code[cx].l.intkind=y;
	code[cx].a.intkind=z;
	code[cx].isfloat=0;
	cx++;
}

void genf(enum fct x,int y,float z){
	code[cx].f=x;
	code[cx].l.intkind=y;
	code[cx].a.floatkind=z;
	code[cx].isfloat=1;
	cx++;
}

void insertTable(char name_in[],int kind_in, int value_in,int size_in,int address_in,int paranum_in,int index,int level_in){

     int tempj;
     if(index>1000)
     {
         error(4);
         return ;
     }
     /*if(kind_in==functionkind){
        tempj=1;
        while(tempj<=arrayindex){
            if(strcmp(Table[txarray[tempj]].name,name_in)==0)
            {
                error(5);
                return;
            }
            tempj++;
        }
     }*/
     strcpy(table[index].name,name_in);
     table[index].kind=kind_in;
     //table[index].value=value_in;
     table[index].size=size_in;
     //table[index].address=address_in;
     //table[index].paranum=paranum_in;
     table[index].level=level_in;
  //if(kind_in==functionkind){
     //
   //  txarray[++arrayindex]=index;

 // }
//      indexi++;//

}

void enter(int add,char *name,int level,int type,int kind,int size,int ret){
    strcpy(table[add].name,name);
    table[add].level=level;
    table[add].type=type;
    table[add].kind=kind;
    table[add].size=size;
    table[add].ret=ret;
    if(kind==0){
        table[add].offset=3;
        table[add].valuetype.funcval.paranum=0;
    }
    if(kind==1){
        if(add==1){
                table[add].offset=3;
        }
        else{
            table[add].offset=table[add-1].offset+table[add-1].size;
        }

    }
    if(kind==2){
        if(add==1){
            table[add].offset=3;
        }
        else{
            table[add].offset=table[add-1].offset;
        }
        switch(type){
        case 0:table[add].valuetype.intval=integernum;break;
        case 1:table[add].valuetype.floatval=realnum;break;
        case 2:table[add].valuetype.charval=zf;break;
        default:table[add].valuetype.intval=0;
    }
    }
}

void enterValue(int type){
    int address;
    address=tabtop;
    for(address=tabtop;address>0;address--){
        if(table[address].kind==0)
            break;
    }
    table[address].valuetype.funcval.paranum++;
    table[address].valuetype.funcval.parameter[table[address].valuetype.funcval.paranum-1]=type;
    table[address].valuetype.funcval.funcpoint=cx;
}
void enterStart(int start){
    int address;
    address=tabtop;
    for(address=tabtop;address>0;address--){
        if(table[address].kind==0)
            break;
    }
    table[address].valuetype.funcval.start=start;
    table[address].valuetype.funcval.funcpoint=cx;

}
void cleanTable(){//
    table[add].level=-1;
    table[add].type=-1;
    table[add].kind=-1;
    table[add].size=-1;
    table[add].ret=-1;
}
int find(char* name){
    int i;
    i=tabtop;
    for(i=tabtop;i>0;i--){
        if(table[i].kind==0){
            return 0;
        }
        if(strcmp(name,table[i].name)==0){
            return i;
        }
    }
    return 0;
}
int lookup(char *name){
    int i;
    i=tabtop;
    for(i=tabtop;i>0;i--){
        if(table[i].kind==0){
            break;
        }
        if(strcmp(name,table[i].name)==0){
            return i;
        }
    }
    for(i=1;i<=tabtop;i++){
        if(table[i].level==1)
            //break;
            continue;
        else{
            if(strcmp(name,table[i].name)==0){
            return i;
            }
        }
    }
    return 0;
}
int findGlobal(char *name){
    int i;
    for(i=1;i<=tabtop;i++){
        if(table[i].level==1)
            //break;
            continue;
        else{
            if(strcmp(name,table[i].name)==0){
            return i;
            }
        }
    }
    return 0;
}

void insertproc(int parameter)//
{
	int x = txarray[arrayindex];   //
	table[x].parameter = parameter;//
	return ;
}

int integerjudge(){//
    int judge=0;
    if(sym==integer)
        return 1;
    else if(sym==add||sym==minus){
        if(sym==minus)
            judge=1;
        getsym();
        if(sym==unsignedinteger){
            if(judge)
                integernum=-integernum;
            return 1;
        }
        //if(sym==unsignedinteger){if(judge==0)integernum=integernum;return 1;}
    }
    else if(sym==unsignedinteger)
        return 1;
    else
        return 0;
}
int realnumjudge(){
    int judge=0;
    if(sym==realnumber)
        return 1;
    else if(sym==add||sym==minus){
        if(sym==minus)
            judge=1;
        getsym();
        if(sym==realnumber){
            if(judge)
                realnum=-realnum;return 1;
        }
       // if(sym==realnumber){if(judge==0)realnum=realnum;return 1;}
    }
    else
        return 0;
}

void constdefine(int cnamed){
    int type;
    int add;
    type = -1;
    while(sym==constsym){
        getsym();
        switch(sym){
        case intsym:
            type=0;
            break;
        case floatsym:
            type=1;
            break;
        case charsym:
            type=2;
            break;
        default:
            type=-1;
            error(22);
        }
        getsym();
        if(sym==ident){
            if(add=find(id)){
                error(7);
            }
            if(add==0){
                tabtop++;
                add=tabtop;
            }
        }
        else{
                error(8);}
        getsym();
        if(sym!=becames){
            error(9);
        }
        getsym();
        if(integerjudge()&&type==0){
            getsym();
        }
        else if(realnumjudge()&&type==1){
            getsym();
        }
        else if(sym==character&&type==2){
            getsym();
        }
        else{
            error(10);
        }
        enter(add,id,cnamed,type,2,1,0);
        while(sym==comma){
            getsym();
            if(sym==ident){
                if(add=find(id)){
                    error(7);
                }
                if(add==0){
                    tabtop++;
                    add=tabtop;
                }
            }
            else{
                error(8);}
            getsym();
            if(sym!=becames){
                error(9);
            }
            getsym();
            if(integerjudge()&&type==0){
                getsym();
            }
            else if(realnumjudge()&&type==1){
                getsym();
            }
            else if(sym==character&&type==2){
                getsym();
            }
            else{
                error(10);
            }
            enter(add,id,cnamed,type,2,1,0);
        }
        if(sym!=semicolon){
            error(12);
        }
        getsym();
    }
}

int vardefine(){
    int type;
    int size;
    int add;
    int arr=0;
    int start=0;
    type=-1;
    size=1;
    while(sym==intsym||sym==floatsym||sym==charsym){
        switch(sym){
        case intsym:
            type=0;
            break;
        case floatsym:
            type=1;
            break;
        case charsym:
            type=2;
            break;
        default:
            type=-1;
            error(22);
        }
        getsym();
        if(sym!=ident){
            error(8);
        }
        else{
            if(add=find(id)){
                error(27);
            }
            if(add==0){
                tabtop++;
                add=tabtop;
            }
        }
        getsym();
        if(sym==leftbracket){
            arr=1;
            getsym();
            if(sym==unsignedinteger){
                size=integernum;
                getsym();
                if(sym==rightbracket){
                    getsym();
                }
                else{
                    error(13);
                }
            }
            else{
                error(14);
            }
        }
        enter(add,id,1,type,1,size,arr);
        size=1;
        arr=0;
        while(sym==comma){
            getsym();
            if(sym!=ident){
                error(8);
            }
            else{
                if(add=find(id)){
                    error(27);
                }
                if(add==0){
                    tabtop++;
                    add=tabtop;
                }
            }
            getsym();
            if(sym==leftbracket){
                arr=1;
                getsym();
                if(sym==unsignedinteger){
                    size=integernum;
                    getsym();
                    if(sym==rightbracket){
                        getsym();
                    }
                    else{
                        error(13);
                    }
                }
                else{
                    error(14);
                }
            }
            enter(add,id,1,type,1,size,arr);
            size=1;
            arr=0;
        }
        if(sym!=semicolon){
            error(12);}
        else{
            getsym();
        }
    }
    start=table[tabtop].offset+size-1;
    return start;
}

void defhead(){
    int kind;
    int intkind;
    char charkind;
    if(sym==intsym||sym==charsym){
        if(sym==intsym) kind=intkind;
        else if(sym==charsym) kind=charkind;
        getsym();
        if(sym!=ident){
            error(0);
            while (sym!=comma && sym!=leftbracket && sym!=rightbracket) {
                if(sym==eofsym) {printf("EOF!\n");return;}
                    getsym();
            }
            return ;
        }
        else {
            strcpy(id,tokenbufpoint);
        }
    }
    else {//
        error(0);
        while (sym!=comma && sym!=leftbracket && sym!=rightbracket) {
                if(sym==eofsym) {printf("EOF!\n");return;}
                    getsym();
            }
            return ;
    }
     getsym();
     return ;

}

void program(){
    int op1,op2,op3;
    int startpoint;
    getch();
    getsym();
    op2=cx;
    gen(JMP,0,0);
    constdefine(0);
    vardefineMain();
    startpoint=cx-1;
    op1=cx;
    gen(INT,1,0);
    op3=cx;
    gen(JMP,0,0);
    mainfun();
    code[op1].a.intkind=mainSize;
    code[op1].l.intkind=mainTable;
    code[op2].a.intkind=startpoint;
    code[op3].a.intkind=beginMain;
}

int factor(){
    int i=0;
    int paradr=4;
    int flag=0;
    //0 char
    //1 int
    //2 float
    int flags=0;
    if(sym==ident){
        i=lookup(id);
        if(i==0){
            error(28);
            gen(LIT,0,0);
            getsym();
            return 1;
        }
        getsym();

        if(table[i].type>3){
            error(40);
        }
        if(table[i].type==0){
                flag=1;
        }
        if(table[i].type==1){
            flag=2;
        }
        if(sym==leftbracket){
            if(table[i].kind!=1){
                error(30);
                gen(LIT,0,0);
                getsym();
                return 1;
            }
            getsym();
            expression();
            if(sym==rightbracket){
                getsym();
            }
            else{
                error(13);
            }
        }
        else if(sym==leftparent){
            if(table[i].kind!=0){
                i=findGlobal(table[i].name);
                if(i==0||table[i].kind!=0){
                    error(31);
                    gen(LIT,0,0);
                    getsym();
                    return 1;
                }
            }

            getsym();
            if(sym==rightparent){
               getsym();
                if(table[i].valuetype.funcval.paranum!=0){
                        error(32);
                    }
                gen(INT,i,table[i].valuetype.funcval.start);
                gen(STI,cx+2,2);
                gen(JMP,0,table[i].valuetype.funcval.funcpoint);
               // puts(table[i].valuetype.funcval.funcpoint);

            }
            else{
                flags = expression();
                if(flags==2&&table[i].valuetype.funcval.parameter[0]==0||flags==2&&table[i].valuetype.funcval.parameter[0]==2||flags==0&&table[i].valuetype.funcval.parameter[0]==1||flags==1&&table[i].valuetype.funcval.parameter[0]==1){
                    error(37);
                }
                paradr++;
                while(sym==comma){
                    getsym();
                    flags = expression();
                    if(flags==2&&table[i].valuetype.funcval.parameter[paradr-4]==0||flags==2&&table[i].valuetype.funcval.parameter[paradr-4]==2||flags==0&&table[i].valuetype.funcval.parameter[paradr-4]==1||flags==1&&table[i].valuetype.funcval.parameter[paradr-4]==1){
                    error(37);
                    }

                    paradr++;
                    if(paradr-4>table[i].valuetype.funcval.paranum){
                            error(32);
                    }
                }
                if(sym==rightparent)
                    getsym();
                else{
                    error(17);
                }
                gen(INT,i,table[i].valuetype.funcval.start);
                for(paradr-=1;paradr>=4;paradr--){
                    gen(STO,1,paradr);
                }

                gen(STI,cx+2,2);
                gen(JMP,0,table[i].valuetype.funcval.funcpoint);
                //puts(table[i].valuetype.funcval.funcpoint);

            }
            gen(LOD,1,3);
            gen(QUT,0,0);
        }
        if(table[i].kind==1&&table[i].ret==0){
            gen(LOD,table[i].level,table[i].offset);
        }
        else if(table[i].kind==1&&table[i].ret==1){
            gen(LIT,0,table[i].offset);
            gen(ADD,0,0);
            gen(LODT,table[i].level,0);
        }
        else if(table[i].kind==2){
            switch(table[i].type){
                case 0:gen(LIT,0,table[i].valuetype.intval);break;
                case 1:gen(LIT,0,table[i].valuetype.floatval);break;
                case 2:gen(LIT,0,table[i].valuetype.charval);break;
                case 3:error(40);break;
            }
        }
    }
    else if(integerjudge()==1){
            gen(LIT,0,integernum);
            getsym();
            flag=1;}
    else if(realnumjudge()==1){
            genf(LIT,0,realnum);
            getsym();
            flag=2;
            }
    else if(sym==character){
            gen(LIT,0,zf);
            getsym();
            flag=0;}
    else if(sym==leftparent){
        getsym();
        flag=expression();
        if(sym==rightparent)
            getsym();
        else{
            error(17);}
    }
    else{
        error(38);
    }
    return flag;
}
void rua(int a,int b){
    if(a<b){
        a=b;
    }
}
int terms(){
    int flag;
    int flags;
    int judge=0;
    int result;
    flag=flags=0;
    result = flags -flag;
    flags=factor();
    //rua(flag,flags);
    if(flag<flags){
        flag=flags;
    }
    while(sym==times||sym==slash){
        if(sym==slash)
            judge=0;
        else if(sym==times){
            judge=1;
        }
        getsym();
        flags=factor();
        if(flag<flags){
            flag=flags;
        }
        //rua(flag,flags);
        if(judge == 0)
            gen(DIV,0,0);
        else{
            gen(MUL,0,0);
        }
    }
    return flag;
}
int expression(){
    int judge;//1+ 0-
    int flag;
    int flags;
    int result;
    flag=flags =0;
    result = flags-flag;
   // printf("%d",result);
    if(sym==add||sym==minus){
        gen(LIT,0,0);
        if(sym==add){
            gen(ADD,0,0);
        }
        else if(sym==minus){
            gen(SUB,0,0);
        }
        else
            error(41);
        getsym();
    }
    flags=terms();
    //rua(flag,flags);
    if(flag<flags)
        flag=flags;
    while(sym==add||sym==minus){
        if(sym==add)
            judge=1;
        else{
            judge=0;
    }
        getsym();
        flags=terms();
        //rua(flag,flags);
        if(flag<flags)
            flag=flags;
        if(judge == 1)
            gen(ADD,0,0);
        else{
            gen(SUB,0,0);
        }
    }
    return flags;
}
void statement(){
    //while(sym==ifsym||sym==whilesym||sym==leftcurlybracket||sym==ident||sym==scanfsym||sym==printfsym||sym==semicolon||sym==switchsym||sym==returnsym){
        switch(sym){
            case switchsym:
                switchstatement();break;
            case ifsym:ifstatement();break;
            case whilesym:whilestatement();break;
            case leftcurlybracket:{
                getsym();
                while(sym!=rightcurlybracket){
                    statement();
                }
                getsym();
                break;
            }
            case scanfsym:
                readstatement();
                if(sym==semicolon){
                    getsym();}
                else{
                    error(12);}
                break;
            case printfsym:
                writestatement();
                if(sym==semicolon){
                    getsym();}
                else{
                    error(12);}
                break;

            case ident:{
                assignstatement();
                if(sym==semicolon){
                        getsym();}
                else{
                        error(12);}
                break;
            }
            case semicolon:
                getsym();break;
            case returnsym:
                returnstatement();
                if(sym==semicolon){
                        getsym();}
                else{
                    error(12);}
                break;
            //default:
             //   error(41);
        }

    }
//}
void ifstatement(){
    int op;
    int point1;
    int point2;
    int flag;
    flag =0;
    getsym();
    if(sym!=leftparent){
            error(21);
    }
    getsym();
    expression();
    if(sym==more||sym==moreorequal||sym==less||sym==lessorequal||sym==notequal||sym==equal){
        if(sym==more)
            op=1;
        else if(sym==moreorequal)
            op=2;
        else if(sym==less)
            op=3;
        else if(sym==lessorequal)
            op=4;
        else if(sym==notequal)
            op=5;
        else if(sym==equal)
            op=6;
        getsym();
        expression();
        gen(LOG,0,op);
    }
    if(sym!=rightparent){
            error(17);}

    gen(JPC,0,0);
    point1=cx-1;
    getsym();
    statement();
    code[point1].a.intkind=cx;
    if(sym==elsesym){
        gen(JMP,0,0);
        code[point1].a.intkind=cx;
        point2=cx-1;
        getsym();
        statement();
        code[point2].a.intkind=cx;
    }
}
void whilestatement(){
    int op;
    int point1;
    int point2;
    int flag;
    point1=cx;
    flag =0;
    getsym();
    if(sym!=leftparent){
            error(21);
    }
    getsym();
    expression();
    if(sym==more||sym==moreorequal||sym==less||sym==lessorequal||sym==notequal||sym==equal){
        if(sym==more)
            op=1;
        else if(sym==moreorequal)
            op=2;
        else if(sym==less)
            op=3;
        else if(sym==lessorequal)
            op=4;
        else if(sym==notequal)
            op=5;
        else if(sym==equal)
            op=6;
        getsym();
        expression();
        gen(LOG,0,op);
    }
    if(sym!=rightparent){
            error(17);
    }
    getsym();
    gen(JPC,0,0);
    point2=cx-1;
    statement();
    gen(JMP,0,point1);
    //printf("%d",point1);
    code[point2].a.intkind=cx;
}
void assignstatement(){
    int paradr;
    int i=0;
    int flag;
    int flag2;
    int flags;
    paradr=4;
    i=lookup(id);
    if(i==0||i<0){
        error(28);
        while(sym!=semicolon){
            getsym();
        }
        return;
    }
    flag=table[i].type;
    getsym();
    if(sym==leftparent){
        if(table[i].kind!=0){
            i=findGlobal(table[i].name);
            if(i==0||table[i].kind!=0){
              error(31);
                while(sym!=semicolon){
                    getsym();
                }
                return;
            }
        }
        getsym();
        if(sym==rightparent){
                if(table[i].valuetype.funcval.paranum!=0){
                        error(32);
                }
                gen(INT,i,table[i].valuetype.funcval.start);
                gen(STI,cx+2,2);
                gen(JMP,0,table[i].valuetype.funcval.funcpoint);
            //printf("%d",table[i].valuetype.funcval.funcpoint);
                gen(QUT,0,0);
                getsym();

        }
        else{
            flags = expression();
            if(flags==2&&table[i].valuetype.funcval.parameter[paradr-4]==0||flags==2&&table[i].valuetype.funcval.parameter[paradr-4]==1||flags==0&&table[i].valuetype.funcval.parameter[paradr-4]==1||flags==1&&table[i].valuetype.funcval.parameter[paradr-4]==1){
                error(37);
            }
            paradr++;
            if(paradr-4>table[i].valuetype.funcval.paranum){
                    error(32);
            }
            while(sym==comma){
                getsym();
                flags = expression();
                if(flags==2&&table[i].valuetype.funcval.parameter[paradr-4]==0||flags==2&&table[i].valuetype.funcval.parameter[paradr-4]==1||flags==0&&table[i].valuetype.funcval.parameter[paradr-4]==1||flags==1&&table[i].valuetype.funcval.parameter[paradr-4]==1){
                    error(37);
                }
                paradr++;
                if(paradr-4>table[i].valuetype.funcval.paranum){
                        error(32);}
            }
            if(sym==rightparent){
                getsym();
            }
            else{
                error(17);
            }
            gen(INT,i,table[i].valuetype.funcval.start);
            for(paradr-=1;paradr>=4;paradr--){
                    gen(STO,1,paradr);
                }
            gen(STI,cx+2,2);
            gen(JMP,0,table[i].valuetype.funcval.funcpoint);
            gen(QUT,0,0);
        }
        return;
    }
    if(sym==leftbracket){
        getsym();
        expression();
        if(sym==rightbracket){
            getsym();
        }
        else{
            error(13);}
    }
    if(table[i].ret==1){
        gen(LOA,table[i].level,table[i].offset);
        gen(ADD,0,0);
    }
    else if(table[i].ret==0){
        gen(LOA,table[i].level,table[i].offset);
    }
    else{
        error(41);
    }
    if(sym==becames){
        getsym();
    }
    else{
        error(6);
        while(sym!=semicolon){
            getsym();
        }
        return;
    }
    flag2=expression();
    //gen(STT,0,0);
    if(flag==0&&flag2==2||flag2==2&&flag==2)
        error(35);
    if(flag==1&&flag2==0||flag==1&&flag2==1){
        gen(STT,0,1);
    }
    else{
        gen(STT,0,0);
    }

}
void readstatement(){
    getsym();
    int i=0;
    if(sym==leftparent){
            getsym();
    }
    else{
        error(21);
        while(sym!=semicolon){
                getsym();
            }
            return;
    }
    if(sym==ident){
        i=lookup(id);
        if(i==0){
            error(28);
        while(sym!=semicolon){
            getsym();
        }
        return;
        }
        if(table[i].kind!=1){
            error(33);
            while(sym!=semicolon){
                getsym();
            }
            return;
        }

        if(table[i].type==0){
            gen(rei,0,0);
        }
        else if(table[i].type==1){
            gen(ref,0,0);
        }
        else if(table[i].type==2){
            gen(rec,0,0);
        }
        else{
            error(41);
        }
        gen(STO,table[i].level,table[i].offset);
        getsym();
    }
    else{
        error(8);
    }
    while(sym==comma){
        getsym();
        if(sym==ident){
            i=lookup(id);
            if(i==0){
                error(28);
                while(sym!=semicolon){
                getsym();
            }
            return;
            }
            if(table[i].kind!=1){
                error(33);
                while(sym!=semicolon){
                    getsym();
                }
                return;
            }
            if(table[i].type==0){
                gen(rei,0,0);
            }
            else if(table[i].type==1){
                gen(ref,0,0);
            }
            else if(table[i].type==2){
                gen(rec,0,0);
            }
            else{
                error(41);
            }
            gen(STO,table[i].level,table[i].offset);
            getsym();
        }
        else{
            error(8);
        }
    }
    if(sym==rightparent)
        getsym();
    else{
        error(17);}
}
void writestatement(){
    int flag;
    getsym();
    if(sym==leftparent){
            getsym();
        }
    else{
        error(21);
    }
    if(sym==string){
        strcpy(buff[bufftop],zfc);
        gen(ws,0,bufftop);
        bufftop++;
        getsym();
        if(sym==comma){
            getsym();
            flag=expression();
            gen(wr,0,flag);
        }
    }
    else{
        flag=expression();
        gen(wr,0,flag);
    }
    if(sym==rightparent)
        getsym();
    else{
        error(17);
    }

}
void switchstatement(){
    int point=0;
    int flag=0;
    getsym();
    if(sym==leftparent)
        getsym();
    else{
        error(21);}
    flag=expression();
    if(flag>1)
        error(42);
    if(sym==rightparent)
        getsym();
    else{
        error(17);}

    if(sym==leftcurlybracket)
        getsym();
    else{
        error(18);}
    while(sym==casesym){//
        getsym();
        if(integerjudge()){
            gen(LIT,0,integernum);
            gen(LOGT,0,6);
            gen(JPC,0,0);
            point=cx;
            getsym();
        }
        else if(sym==character){
            gen(LIT,0,zf);
            gen(LOGT,0,6);
            gen(JPC,0,0);
            point=cx;
            getsym();
        }
        else{//
            error(42);}
        if(sym==colon)
            getsym();
        else{
            error(24);}
        statement();
        code[point-1].a.intkind=cx;
    }
    if(sym==rightcurlybracket)
        getsym();
    else{
        error(19);}
}
void returnstatement(){
    getsym();
    int i;
    int isvoid=0;
    i=tabtop;
    for(i=tabtop;i>0;i--){
        if(table[i].kind==0){
            if(table[i].type==3){
                isvoid=1;
            }
            break;
        }
    }
    if(sym!=leftparent){
        error(21);
    }
    if(sym==leftparent){
        if(isvoid){
                error(39);
            }
        getsym();
        expression();
        gen(STO,1,3);
        if(sym==rightparent)
            getsym();
        else{
            error(17);}
        gen(JMB,0,0);
    }
}
void valueofpara(){
   char paras[100][100];
   int i;
   i=lookup(id);
   int j = 0;
	do {
		if (sym==comma) getsym();
		if (sym==add || sym==minus || sym==ident ||sym==leftbracket || sym==character||sym==integer) {
			expression();
			strcpy(paras[j],midvalue);
			j++;
		}
	}while (sym==comma);
	table[i].valuetype.funcval.paranum = j;
	for(j=0;j<table[i].valuetype.funcval.paranum;j++){
            //
            //
	}
	return ;
}
void parameters(){   //
    int i=0;
    int kind;
    int parameterkind,value,address,size,paranums;
	if( sym==intsym||sym==charsym ) {
            int temp4;
            temp4=sym;
		do{
             temp4=sym;
			if (sym==comma)
                getsym();
            if(temp4==comma&&(sym==intsym||sym==charsym))
                temp4=sym;
			defhead();
			kind = parameterkind;
    		value = 0;
	    	address = i;
	    	size=0;
    		paranums = 0;
    		/////todo:insert table
//	    	insertTable(id,kind,value,size,address,paranums,indexi,level);
            //if(temp4==INT)
          //      emit((char*)"para",(char*)"int",(char*)" ",id);
            //else if(temp4==CHAR)
            //    emit((char*)"para",(char*)"char",(char*)" ",id);
    		i++;
		}while(sym==comma);
	}
	paranums = i;
	insertproc(paranums);//
	return;
}
void vardefineMain(){//main
    int over=0;
    int type=-1;
    int size=1;
    int add;
    int arr=0;
    int start;
    int begin;
    start=begin=0;
    while(sym==intsym||sym==floatsym||sym==charsym||sym==voidsym){
        if(sym==voidsym){
                over=1;
        }
        switch(sym){
        case intsym:
            type=0;
            break;
        case floatsym:
            type=1;
            break;
        case charsym:
            type=2;
            break;
        case voidsym:
            type=3;
            break;
        default:
            type=-1;
        }
        getsym();
        if(sym==mainsym){
            gen(INT,-1,start);
            return;
        }
        if(sym!=ident){
            error(8);
        }
        else{
            if(add=find(id)){
                error(27);
            }
            else{
                tabtop++;
                add=tabtop;
            }
        }
        getsym();
        if(sym==leftparent){
            enter(add,id,0,type,0,1,0);
            over=1;
            getsym();
            if(sym==intsym||sym==floatsym||sym==charsym){
                switch(sym){
                    case intsym:
                        type=0;
                        break;
                    case floatsym:
                        type=1;
                        break;
                    case charsym:
                        type=2;
                        break;
                    default:
                        type=-1;
                    }
                getsym();
                if(sym!=ident){
                    error(8);
                }
                else{
                   if(add=find(id)){
                        error(27);
                    }
                    if(add==0){
                        tabtop++;
                        add=tabtop;
                    }
                }
                enter(add,id,1,type,1,1,0);
                enterValue(type);
                getsym();
                while(sym==comma){
                    getsym();
                    if(sym==intsym||sym==floatsym||sym==charsym){
                        switch(sym){
                        case intsym:
                            type=0;
                            break;
                        case floatsym:
                            type=1;
                            break;
                        case charsym:
                            type=2;
                            break;
                        default:
                            type=-1;
                        }
                        getsym();
                        if(sym!=ident){
                            error(8);
                        }
                        else{
                            if(add=find(id)){
                                error(27);
                            }
                            else{
                                tabtop++;
                                add=tabtop;
                            }
                        }
                        enter(add,id,1,type,1,1,0);
                        enterValue(type);
                        getsym();
                    }
                    else{
                        error(16);
                    }
                }
            }
            if(sym!=rightparent){
                error(17);
            }
            getsym();
            if(sym!=leftcurlybracket){
                error(18);
            }
            getsym();
            constdefine(1);
            begin=vardefine();
            enterStart(begin);

          //  if(sym!=rightcurlybracket){
           //     error(43);
          //  }
            while(sym!=rightcurlybracket){
                    statement();
            }
            gen(JMB,0,0);
            getsym();
            continue;
        }
        if(sym==leftbracket&&over==0){
            arr=1;
            getsym();
            if(sym==unsignedinteger){
                size=integernum;
                getsym();
                if(sym==rightbracket){
                    getsym();
                }
                else{
                    error(13);
                }
            }
            else{
                error(14);
            }
        }
        else if(over==1&&sym==leftbracket){
            error(15);
        }
        enter(add,id,0,type,1,size,arr);
        start=table[tabtop].offset+size;
        size=1;
        arr=0;
        while(sym==comma&&over==0){
            getsym();
            if(sym!=ident){
                error(8);
            }
            else{
            if(add=find(id)){
                error(7);
            }
            else{
                tabtop++;
                add=tabtop;
            }
            }
            getsym();
            if(sym==leftbracket){
                arr=1;
                getsym();
                if(sym==unsignedinteger){
                    size=integernum;
                    getsym();
                    if(sym==rightbracket){
                        getsym();
                    }
                    else{
                        error(13);
                    }
                }
                else{
                    error(14);
                }
            }
            enter(add,id,0,type,1,size,arr);
            start=table[tabtop].offset+size;
            size=1;
            arr=0;
        }
        if(sym==semicolon&&over==0){
                getsym();
        }
        else{
            if(sym!=semicolon&&over==0){
                    error(12);}
        }
    }
    gen(INT,-1,start);
}

void mainfun(){
//int maun()
    if(sym==mainsym)
        getsym();
    else{error(26);}
    if(sym==leftparent)
        getsym();
    else{error(21);}
    if(sym==rightparent)
        getsym();
    else{error(17);}
    if(sym==leftcurlybracket)
        getsym();
    else{
        error(18);}
    tabtop++;
    enter(tabtop,"MAIN",0,0,0,1,0);
    mainTable=tabtop;
    constdefine(1);
    mainSize=vardefine();
    beginMain=cx;
    //statement();
    //if(sym==rightcurlybracket)
      //  getsym();
    //else{
      //  error();}

    while(sym!=rightcurlybracket){
            statement();
    }
    getsym();
}



void error(int i){//
    switch(i){
    case 1:
        printf("error%d,in line%d\n",i,line);
        puts("没有=");
        break;
    case 2:
        printf("error%d,in line%d\n",i,line);
        puts("少引号");
        break;
    case 3:
        printf("error%d,in line%d\n",i,line);
        puts("标识符太长");
        break;
    case 4:
        printf("error%d,in line%d\n",i,line);
        puts("识别错误");
        break;
    case 5:
        printf("error%d,in line%d\n",i,line);
        puts("不是符合要求的数字");
        break;
    case 6:
        printf("error%d,in line%d\n",i,line);
        puts("=错误");
        break;
    case 7:
        printf("error%d,in line%d\n",i,line);
        puts("重复定义");
        break;
    case 8:
        printf("error%d,in line%d\n",i,line);
        puts("少标识符");
        break;
    case 9:
        printf("error%d,in line%d\n",i,line);
        puts("应该是等号");
        break;
    case 10:
        printf("error%d,in line%d\n",i,line);
        puts("常量定义类型不匹配");
        break;
    case 11:
        printf("error%d,in line%d\n",i,line);
        puts("缺少返回值");
        break;
    case 12:
        printf("error%d,in line%d\n",i,line-1);
        puts("没有；");
        break;
    case 13:
        printf("error%d,in line%d\n",i,line);
        puts("少]");
        break;
    case 14:
        printf("error%d,in line%d\n",i,line);
        puts("int");
        break;
    case 15:
        printf("error%d,in line%d\n",i,line);
        puts("声明变量错误");
        break;
    case 16:
        printf("error%d,in line%d\n",i,line);
        puts("应为类型标识符");
        break;
    case 17:
        printf("error%d,in line%d\n",i,line);
        puts("少）");
        break;
    case 18:
        printf("error%d,in line%d\n",i,line);
        puts("少{");
        break;
    case 19:
        printf("error%d,in line%d\n",i,line);
        puts("少}");
        break;
    case 20:
        printf("error%d,in line%d\n",i,line);
        puts("识别错误");
        break;
    case 21:
        printf("error%d,in line%d\n",i,line);
        puts("少（");
        break;
    case 22:
        printf("error%d,in line%d\n",i,line);
        puts("少类型标识符");
        break;
    case 23:
        printf("error%d,in line%d\n",i,line);
        puts("应为变量");
        break;
    case 24:
        printf("error%d,in line%d\n",i,line);
        puts("缺少：");
        break;
    case 25:
        printf("error%d,in line%d\n",i,line);
        puts("应为void");
        break;
    case 26:
        printf("error%d,in line%d\n",i,line);
        puts("应为main");
        break;
    case 27:
        printf("error%d,in line%d\n",i,line);
        puts("重复定义");
        break;
    case 28:
        printf("error%d,in line%d\n",i,line);
        puts("没有此标识符");
        break;
    case 29:
        printf("error%d,in line%d\n",i,line);
        puts("数组越界");
        break;
    case 30:
        printf("error%d,in line%d\n",i,line);
        puts("数组错误");
        break;
    case 31:
        printf("error%d,in line%d\n",i,line);
        puts("没有找到次函数");
        break;
    case 32:
        printf("error%d,in line%d\n",i,line);
        puts("参数类型不对");
        break;
    case 33:
        printf("error%d,in line%d\n",i,line);
        puts("不能对其赋值");
        break;
    case 34:
        printf("error%d,in line%d\n",i,line);
        puts("switch错误");
        break;
    case 35:
        printf("error%d,in line%d\n",i,line);
        puts("赋值错误");
        break;
    case 36:
        printf("error%d,in line%d\n",i,line);
        puts("返回类型不对");
        break;
    case 37:
        printf("error%d,in line%d\n",i,line);
        puts("参数错误");
        break;
    case 38:
        printf("error%d,in line%d\n",i,line);
        puts("因子错误");
        break;
    case 39:
        printf("error%d,in line%d\n",i,line);
        puts("返回值与函数类型不符");
        break;
    case 40:
        printf("error%d,in line%d\n",i,line);
        puts("类型错误");
        break;
    case 41:
        printf("error%d,in line%d\n",i,line);
        puts("weizhi cuowu");
        break;
    case 42:
        printf("error%d,in line%d\n",i,line);
        puts("switch 错误");
        break;
    case 43:
        printf("error%d,in line%d\n",i,line);
        puts("shao");
        break;
    }
    is_error=1;
}


void interupt(){

    enum fct p;
    int pc=0;
    int mbase=0;
    int mtop=0;
    struct emit{
        int isfloat;
        int intkind;
        double floatkind;
    };
    struct emit run[amax];
    struct emit mem[amax];
    int rx=0;

    while(pc!=cx){
        p=code[pc].f;
        int l;
        int A;
        switch(p){
        case ADD:
            if((!run[rx-1].isfloat)&&(!run[rx].isfloat)){run[rx-1].intkind=run[rx-1].intkind+run[rx].intkind;}
            else if((run[rx-1].isfloat)&&(!run[rx].isfloat)){run[rx-1].floatkind=run[rx-1].floatkind+(double)run[rx].intkind;}
            else if((!run[rx-1].isfloat)&&(run[rx].isfloat)){run[rx-1].floatkind=(double)run[rx-1].intkind+run[rx].floatkind;run[rx-1].isfloat=1;}
            else if((run[rx-1].isfloat)&&(run[rx].isfloat)){run[rx-1].floatkind=run[rx-1].floatkind+run[rx].floatkind;}
            rx--;
            pc++;
            break;
        case SUB:
            if((!run[rx-1].isfloat)&&(!run[rx].isfloat)){run[rx-1].intkind=run[rx-1].intkind-run[rx].intkind;}
            else if((run[rx-1].isfloat)&&(!run[rx].isfloat)){run[rx-1].floatkind=run[rx-1].floatkind-(double)run[rx].intkind;}
            else if((!run[rx-1].isfloat)&&(run[rx].isfloat)){run[rx-1].floatkind=(double)run[rx-1].intkind-run[rx].floatkind;run[rx-1].isfloat=1;}
            else if((run[rx-1].isfloat)&&(run[rx].isfloat)){run[rx-1].floatkind=run[rx-1].floatkind-run[rx].floatkind;}
            rx--;
            pc++;
            break;
        case MUL:
            if((!run[rx-1].isfloat)&&(!run[rx].isfloat)){run[rx-1].intkind=run[rx-1].intkind*run[rx].intkind;}
            else if((run[rx-1].isfloat)&&(!run[rx].isfloat)){run[rx-1].floatkind=run[rx-1].floatkind*(double)run[rx].intkind;}
            else if((!run[rx-1].isfloat)&&(run[rx].isfloat)){run[rx-1].floatkind=(double)run[rx-1].intkind*run[rx].floatkind;run[rx-1].isfloat=1;}
            else if((run[rx-1].isfloat)&&(run[rx].isfloat)){run[rx-1].floatkind=run[rx-1].floatkind*run[rx].floatkind;}
            rx--;
            pc++;
            break;

        case DIV:
            if((!run[rx-1].isfloat)&&(!run[rx].isfloat)){run[rx-1].intkind=run[rx-1].intkind/run[rx].intkind;}
            else if((run[rx-1].isfloat)&&(!run[rx].isfloat)){run[rx-1].floatkind=run[rx-1].floatkind/(double)run[rx].intkind;}
            else if((!run[rx-1].isfloat)&&(run[rx].isfloat)){run[rx-1].floatkind=(double)run[rx-1].intkind/run[rx].floatkind;run[rx-1].isfloat=1;}
            else if((run[rx-1].isfloat)&&(run[rx].isfloat)){run[rx-1].floatkind=run[rx-1].floatkind/run[rx].floatkind;}
            rx--;
            pc++;
            break;
        case LIT:
            rx++;
            if(code[pc].isfloat){
                run[rx].isfloat=1;
                run[rx].floatkind=code[pc].a.floatkind;
            }
            else if(!code[pc].isfloat){
                run[rx].isfloat=0;
                run[rx].intkind=code[pc].a.intkind;
            }
            pc++;
            break;
        case LOD:
            rx++;
            l=code[pc].l.intkind;
            A=code[pc].a.intkind;
            if(l==0){
                if(mem[A].isfloat){
                    run[rx].isfloat=1;
                    run[rx].floatkind=mem[A].floatkind;
                }
                else{
                    run[rx].isfloat=0;
                    run[rx].intkind=mem[A].intkind;
                }
            }
            else{
                if(mem[A+mbase].isfloat){
                    run[rx].isfloat=1;
                    run[rx].floatkind=mem[A+mbase].floatkind;
                }
                else{
                    run[rx].isfloat=0;
                    run[rx].intkind=mem[A+mbase].intkind;
                }
            }
            pc++;
            break;
        case LODT:
            l=code[pc].l.intkind;
            if(l==0){
                if(mem[run[rx].intkind].isfloat){
                    run[rx].isfloat=1;
                    run[rx].floatkind=mem[run[rx].intkind].floatkind;
                }
                else{
                    run[rx].isfloat=0;
                    run[rx].intkind=mem[run[rx].intkind].intkind;
                }
            }
            else{
                if(mem[run[rx].intkind+mbase].isfloat){
                    run[rx].isfloat=1;
                    run[rx].floatkind=mem[run[rx].intkind+mbase].floatkind;
                }
                else{
                    run[rx].isfloat=0;
                    run[rx].intkind=mem[run[rx].intkind+mbase].intkind;
                }
            }
            pc++;
            break;
        case LOA:
            rx++;
            l=code[pc].l.intkind;
            A=code[pc].a.intkind;
            if(l==0){
                run[rx].isfloat=0;
                run[rx].intkind=A;
            }
            else{
                run[rx].isfloat=0;
                run[rx].intkind=A+mbase;
            }
            pc++;
            break;

        case STT:
        if(code[pc].a.intkind==1){
            if(run[rx].isfloat){
            mem[run[rx-1].intkind].isfloat=1;
            mem[run[rx-1].intkind].floatkind=run[rx].floatkind;
            }
            else{
            mem[run[rx-1].intkind].isfloat=1;
            mem[run[rx-1].intkind].floatkind=run[rx].intkind;
        }
        }
        else{
            if(run[rx].isfloat){
            mem[run[rx-1].intkind].isfloat=1;
            mem[run[rx-1].intkind].floatkind=run[rx].floatkind;
            }
            else{
            mem[run[rx-1].intkind].isfloat=0;
            mem[run[rx-1].intkind].intkind=run[rx].intkind;
        }
        }

            rx-=2;
            pc++;
            break;
        case LOG:
            switch(code[pc].a.intkind){
            case 1:
                if(run[rx].isfloat==0&&run[rx-1].isfloat==0)run[rx-1].intkind=run[rx-1].intkind>run[rx].intkind;
                else if(run[rx].isfloat==1&&run[rx-1].isfloat==0)run[rx-1].intkind=run[rx-1].intkind>run[rx].floatkind;
                else if(run[rx].isfloat==0&&run[rx-1].isfloat==1){
                        run[rx-1].isfloat=0;
                        run[rx-1].intkind=run[rx-1].floatkind>run[rx].intkind;
                }
                else if(run[rx].isfloat==1&&run[rx-1].isfloat==1){
                        run[rx-1].isfloat=0;
                        run[rx-1].intkind=run[rx-1].floatkind>run[rx].floatkind;
                }
                break;
            case 2:
                if(run[rx].isfloat==0&&run[rx-1].isfloat==0)run[rx-1].intkind=run[rx-1].intkind>=run[rx].intkind;
                else if(run[rx].isfloat==1&&run[rx-1].isfloat==0)run[rx-1].intkind=run[rx-1].intkind>=run[rx].floatkind;
                else if(run[rx].isfloat==0&&run[rx-1].isfloat==1){
                        run[rx-1].isfloat=0;
                        run[rx-1].intkind=run[rx-1].floatkind>=run[rx].intkind;
                }
                else if(run[rx].isfloat==1&&run[rx-1].isfloat==1){
                        run[rx-1].isfloat=0;
                        run[rx-1].intkind=run[rx-1].floatkind>=run[rx].floatkind;
                }
                break;
            case 3:
                if(run[rx].isfloat==0&&run[rx-1].isfloat==0)run[rx-1].intkind=run[rx-1].intkind<run[rx].intkind;
                else if(run[rx].isfloat==1&&run[rx-1].isfloat==0)run[rx-1].intkind=run[rx-1].intkind<run[rx].floatkind;
                else if(run[rx].isfloat==0&&run[rx-1].isfloat==1){
                        run[rx-1].isfloat=0;
                        run[rx-1].intkind=run[rx-1].floatkind<run[rx].intkind;
                }
                else if(run[rx].isfloat==1&&run[rx-1].isfloat==1){
                        run[rx-1].isfloat=0;
                        run[rx-1].intkind=run[rx-1].floatkind<run[rx].floatkind;
                }
                break;
            case 4:
                if(run[rx].isfloat==0&&run[rx-1].isfloat==0)run[rx-1].intkind=run[rx-1].intkind<=run[rx].intkind;
                else if(run[rx].isfloat==1&&run[rx-1].isfloat==0)run[rx-1].intkind=run[rx-1].intkind<=run[rx].floatkind;
                else if(run[rx].isfloat==0&&run[rx-1].isfloat==1){
                        run[rx-1].isfloat=0;
                        run[rx-1].intkind=run[rx-1].floatkind<=run[rx].intkind;
                }
                else if(run[rx].isfloat==1&&run[rx-1].isfloat==1){
                        run[rx-1].isfloat=0;
                        run[rx-1].intkind=run[rx-1].floatkind<=run[rx].floatkind;
                }
                break;
            case 5:
                if(run[rx].isfloat==0&&run[rx-1].isfloat==0)run[rx-1].intkind=run[rx-1].intkind!=run[rx].intkind;
                else if(run[rx].isfloat==1&&run[rx-1].isfloat==0)run[rx-1].intkind=run[rx-1].intkind!=run[rx].floatkind;
                else if(run[rx].isfloat==0&&run[rx-1].isfloat==1){
                        run[rx-1].isfloat=0;
                        run[rx-1].intkind=run[rx-1].floatkind!=run[rx].intkind;
                }
                else if(run[rx].isfloat==1&&run[rx-1].isfloat==1){
                        run[rx-1].isfloat=0;
                        run[rx-1].intkind=run[rx-1].floatkind!=run[rx].floatkind;
                }
                break;
            case 6:
                if(run[rx].isfloat==0&&run[rx-1].isfloat==0)run[rx-1].intkind=run[rx-1].intkind==run[rx].intkind;
                else if(run[rx].isfloat==1&&run[rx-1].isfloat==0)run[rx-1].intkind=run[rx-1].intkind==run[rx].floatkind;
                else if(run[rx].isfloat==0&&run[rx-1].isfloat==1){
                        run[rx-1].isfloat=0;
                        run[rx-1].intkind=run[rx-1].floatkind==run[rx].intkind;
                }
                else if(run[rx].isfloat==1&&run[rx-1].isfloat==1){
                        run[rx-1].isfloat=0;
                        run[rx-1].intkind=run[rx-1].floatkind==run[rx].floatkind;
                }
                break;
            }
            rx--;
            pc++;
            break;
        case LOGT:
            if(run[rx].isfloat||run[rx-1].isfloat)error(34);
            switch(code[pc].a.intkind){
            case 1:
                run[rx].intkind=run[rx-1].intkind>run[rx].intkind;
                break;
            case 2:
                run[rx].intkind=run[rx-1].intkind>=run[rx].intkind;
                break;
            case 3:
                run[rx].intkind=run[rx-1].intkind<run[rx].intkind;
                break;
            case 4:
                run[rx].intkind=run[rx-1].intkind<=run[rx].intkind;
                break;
            case 5:
                run[rx].intkind=run[rx-1].intkind!=run[rx].intkind;
                break;
            case 6:
                run[rx].intkind=run[rx-1].intkind==run[rx].intkind;
                break;
            }
            pc++;
            break;
        case JPC:
             if(run[rx].intkind==0){
                pc=code[pc].a.intkind;
             }
             else{
                pc++;
             }
             rx--;
             break;
        case JMP:
            pc=code[pc].a.intkind;
            break;
        case INT:
            mem[mtop+1].isfloat=0;
            mem[mtop+1].intkind=mbase;
            mbase=mtop;
            mtop=mtop+code[pc].a.intkind;
            mem[mbase+2].isfloat=0;
            if(table[code[pc].l.intkind].type==1){mem[mbase+3].isfloat=1;}
            else{mem[mbase+3].isfloat=0;}
            pc++;
            break;
        case STI:
            mem[mbase+code[pc].a.intkind].isfloat=0;
            mem[mbase+code[pc].a.intkind].intkind=code[pc].l.intkind;
            pc++;
            break;
        case JMB:
            pc=mem[mbase+2].intkind;
            break;
        case STO:
            l=code[pc].l.intkind;
            A=code[pc].a.intkind;
            if(A!=3){
            if(l==0){
                if(run[rx].isfloat){
                    mem[A].isfloat=1;
                    mem[A].floatkind=run[rx].floatkind;
                }
                else{
                    mem[A].isfloat=0;
                    mem[A].intkind=run[rx].intkind;
                }
            }
            else{
                if(run[rx].isfloat){
                    mem[A+mbase].isfloat=1;
                    mem[A+mbase].floatkind=run[rx].floatkind;
                }
                else{
                    mem[A+mbase].isfloat=0;
                    mem[A+mbase].intkind=run[rx].intkind;
                }
            }
            }
            else{
                if(l==0){
                    if(run[rx].isfloat==mem[A].isfloat){
                        if(run[rx].isfloat){
                        mem[A].floatkind=run[rx].floatkind;
                    }
                    else{
                        mem[A].intkind=run[rx].intkind;
                    }
                    }
                    else{
                        error(35);
                    }
                }
                else{
                    if(run[rx].isfloat==mem[A+mbase].isfloat){
                        if(run[rx].isfloat){
                        mem[A+mbase].floatkind=run[rx].floatkind;
                    }
                    else{
                        mem[A+mbase].intkind=run[rx].intkind;
                    }
                    }
                    else{
                        error(35);
                    }
                }
            }
            pc++;
            rx--;
            break;
        case QUT:
            mtop=mbase;
            mbase=mem[mbase+1].intkind;
            pc++;
            break;
        case rei:
            rx++;
            run[rx].isfloat=0;
            scanf("%d",&run[rx].intkind);
            pc++;
            break;
        case ref:
            rx++;
            run[rx].isfloat=1;
            scanf("%lf",&run[rx].floatkind);
            pc++;
            break;
        case rec:
            rx++;
            run[rx].isfloat=0;
            scanf("%c",&run[rx].intkind);
            pc++;
            break;
        case wr:
            if(run[rx].isfloat){
                printf("%lf",run[rx].floatkind);
            }
            else{
                if(code[pc].a.intkind==1){
                    printf("%d",run[rx].intkind);
                }
                else if(code[pc].a.intkind==0){
                    printf("%c",run[rx].intkind);
                }

            }
            rx--;
            pc++;
            break;
        case ws:
            A=code[pc].a.intkind;
            printf(buff[A]);
            pc++;
            break;
        }
    }
}


int main()
{
    int i=0;
    char Fileaddress[100];

    gets(Fileaddress);
    if((in=fopen(Fileaddress,"r"))==NULL){
        puts("文件不存在");
        exit(1);
    }
    program();
    fout=fopen("pcode.txt","a");
    for(i=0;i<cx;i++)
        fprintf(fout,"%d: %s,%d,%d\n",i,fct_[code[i].f],code[i].l.intkind,code[i].a.intkind);
    if(is_error==0){
      //  puts("1");
        interupt();
     //   puts("2");
//
    }

    return 0;
}
