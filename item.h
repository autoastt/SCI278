#define red FOREGROUND_RED
#define blue FOREGROUND_BLUE
#define green FOREGROUND_GREEN
#define inten FOREGROUND_INTENSITY
#define Red BACKGROUND_RED
#define Blue BACKGROUND_BLUE
#define Green BACKGROUND_GREEN
#define Inten BACKGROUND_INTENSITY
void showalcohol(int SIZE, char brd[SIZE+2][SIZE+2], int po_x, int po_y, int mask, int p)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    WORD normal;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h,&csbiInfo);
    normal=csbiInfo.wAttributes;
    for(int i=0;i<SIZE+2;i++)
    {
        for(int k=0;k<=SIZE+2;k++)
        {
            if(k==SIZE+2) printf("\n");
            else
            {
                //printf(" %c ",brd[i][k]);
                if(brd[i][k]=='X')
                {
                    SetConsoleTextAttribute(h,Inten | inten );
                    printf(" %c ",brd[i][k]);
                }
                else if(brd[i][k]=='I')
                {
                    if(mask>0){
                        SetConsoleTextAttribute(h,green | inten | Blue | Green | Inten);
                        printf(" %c ",brd[i][k]);
                    }
                    else{
                        SetConsoleTextAttribute(h,green | inten | Green | Blue | Inten);
                        printf(" %c ",brd[i][k]);
                    }
                }
                else if(brd[i][k]=='M')
                {
                    SetConsoleTextAttribute(h,blue | inten );
                    printf(" %c ",brd[i][k]);
                }
                else if(brd[i][k]=='V')
                {
                    SetConsoleTextAttribute(h,red | inten );
                    printf(" %c ",brd[i][k]);
                }
                else if(brd[i][k]=='A')
                {
                    SetConsoleTextAttribute(h,blue | green | inten);
                    printf(" %c ",brd[i][k]);
                }
                else if(brd[i][k]=='c')
                {
                    SetConsoleTextAttribute(h,inten | red | green);
                    printf(" %c ",brd[i][k]);
                }
                else
                {
                    SetConsoleTextAttribute(h, normal);
                    printf(" %c ",brd[i][k]);
                }
                SetConsoleTextAttribute(h, normal);
            }
        }
    }
}
void spmask(int SIZE, char brd[][SIZE+2])
{
    int pom_x, pom_y;
    srand(time(0));
    do
    {
        pom_x=rand()%25;
        pom_y=rand()%25;
        if(brd[pom_x][pom_y]==' ') brd[pom_x][pom_y]='m';
    }while(brd[pom_x][pom_y]!='m');
}
void spalcohol(int SIZE, char brd[][SIZE+2])
{
    int poa_x, poa_y;
    srand(time(0));
    do
    {
        poa_x=rand()%25;
        poa_y=rand()%25;
        if(brd[poa_x][poa_y]==' ') brd[poa_x][poa_y]='A';
    }while(brd[poa_x][poa_y]!='A');
}
void alcohol_use(int SIZE, char brd[][SIZE+2], int po_x, int po_y, int mask)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    WORD normal;
    int i=0;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h,&csbiInfo);
    normal=csbiInfo.wAttributes;
    if(brd[po_x][po_y-1]=='V') brd[po_x][po_y-1]='M';
    if(brd[po_x][po_y+1]=='V') brd[po_x][po_y+1]='M';
    if(brd[po_x-1][po_y]=='V') brd[po_x-1][po_y]='M';
    if(brd[po_x+1][po_y]=='V') brd[po_x+1][po_y]='M';
    i++;
    system("cls");
    SetConsoleTextAttribute(h,green | blue | inten);
    printf("::::::ALCOHOL USED!::::::\n");
    showalcohol(SIZE,brd,po_x,po_y,mask,i);
    if(brd[po_x-1][po_y-1]=='V') brd[po_x-1][po_y-1]='M';
    if(brd[po_x-1][po_y+1]=='V') brd[po_x-1][po_y+1]='M';
    if(brd[po_x+1][po_y-1]=='V') brd[po_x+1][po_y-1]='M';
    if(brd[po_x+1][po_y+1]=='V') brd[po_x+1][po_y+1]='M';
    i++;
    system("cls");
    SetConsoleTextAttribute(h,green | blue | inten);
    printf("::::::ALCOHOL USED!::::::\n");
    showalcohol(SIZE,brd,po_x,po_y,mask,i);
    if(brd[po_x+2][po_y]=='V') brd[po_x+2][po_y]='M';
    if(brd[po_x-2][po_y]=='V') brd[po_x-2][po_y]='M';
    if(brd[po_x][po_y+2]=='V') brd[po_x][po_y+2]='M';
    if(brd[po_x][po_y-2]=='V') brd[po_x][po_y-2]='M';
    system("cls");
    SetConsoleTextAttribute(h,green | blue | inten);
    printf("::::::ALCOHOL USED!::::::\n");
    showalcohol(SIZE,brd,po_x,po_y,mask,i);
    if(brd[po_x+3][po_y]=='V') brd[po_x+3][po_y]='M';
    if(brd[po_x-3][po_y]=='V') brd[po_x-3][po_y]='M';
    if(brd[po_x][po_y+3]=='V') brd[po_x][po_y+3]='M';
    if(brd[po_x][po_y-3]=='V') brd[po_x][po_y-3]='M';
    if(brd[po_x+1][po_y+2]=='V') brd[po_x+1][po_y+2]='M';
    if(brd[po_x+2][po_y+1]=='V') brd[po_x+2][po_y+1]='M';
    if(brd[po_x-1][po_y+2]=='V') brd[po_x-1][po_y+2]='M';
    if(brd[po_x-2][po_y+1]=='V') brd[po_x-2][po_y+1]='M';
    if(brd[po_x+1][po_y-2]=='V') brd[po_x+1][po_y-2]='M';
    if(brd[po_x+2][po_y-1]=='V') brd[po_x+2][po_y-1]='M';
    if(brd[po_x-1][po_y-2]=='V') brd[po_x-1][po_y-2]='M';
    if(brd[po_x-2][po_y-1]=='V') brd[po_x-2][po_y-1]='M';
    i++;
    system("cls");
    SetConsoleTextAttribute(h,green | blue | inten);
    printf("::::::ALCOHOL USED!::::::\n");
    SetConsoleTextAttribute(h,normal);
}
