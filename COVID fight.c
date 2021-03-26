#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "createboard.h"
#include "play.h"
#include "item.h"
#define SIZE 25
#define red FOREGROUND_RED
#define blue FOREGROUND_BLUE
#define green FOREGROUND_GREEN
#define inten FOREGROUND_INTENSITY
#define Red BACKGROUND_RED
#define Blue BACKGROUND_BLUE
#define Green BACKGROUND_GREEN
#define Inten BACKGROUND_INTENSITY
void show(char brd[SIZE+2][SIZE+2],int mask)
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
                        SetConsoleTextAttribute(h,green | inten | Red |Blue | Green | Inten);
                        printf(" %c ",brd[i][k]);
                    }
                    else{
                        SetConsoleTextAttribute(h,green | inten);
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
void spawn(char brd[SIZE+2][SIZE+2],int k,int level)
{
    int poM_x, poM_y,r;
    srand(time(0));
    r=rand();
    for(int i=0;i<k;i++)
    {
        poM_x=rand()%25,r;
        poM_y=rand()%25;
        r=rand()%5;
        if(brd[poM_x+1][poM_y]!='I'&&brd[poM_x-1][poM_y]!='I'&&brd[poM_x][poM_y+1]!='I'&&brd[poM_x][poM_y-1]!='I')
        {
            if(r>=level)
                {
                    if(brd[poM_x][poM_y]==' ')
                        {
                            brd[poM_x][poM_y]='M';
                        }
                    else i--;
                }
            else if(r<level)
                {
                    if(brd[poM_x][poM_y]==' ')
                        {
                            brd[poM_x][poM_y]='V';
                        }
                    else i--;
                }
        }
        else i--;
    }
}
int main()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    WORD normal;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h,&csbiInfo);
    normal=csbiInfo.wAttributes;
    char x, brd[SIZE+2][SIZE+2], leve[10];
    int level, c=1, cb=1, turn=1, po_x=0, po_y=0, mask=0, alcohol=0;
    printf("1.EASY\n2.NORMAL\n3.HARD\n");
    //level=getche();
    scanf("%d",&level);//input level
    system("cls");
    createboard(SIZE,level,brd);//create board
    do//locate player
    {
        srand(time(0));
        po_x=rand()%SIZE;
        po_y=rand()%SIZE;
    }while(brd[po_x][po_y]!=' ');
    brd[po_x][po_y]='I';
    //spawn people
    if(level==1){
        spawn(brd,5,level);
        strcpy(leve,"EASY");
    }
    else if(level==2){
        spawn(brd,8,level);
        strcpy(leve,"NORMAL");
    }
    else if(level==3){
        spawn(brd,12,level);
        strcpy(leve,"HARD");
    }
    printf("Mode: %s  ",leve);
    SetConsoleTextAttribute(h,inten | red | green);
    printf("Turn: 0  ");
    SetConsoleTextAttribute(h,inten | red | blue | green);
    printf("Mask: %d  ",mask);
    SetConsoleTextAttribute(h,inten | blue | green);
    printf("Alcohol: %d\n",alcohol);
    SetConsoleTextAttribute(h,normal);
    show(brd,mask);
    while(c!=69&&cb!=69)//play
    {
        srand(time(0));
        x=getche(); //input turn
        c=play(SIZE,brd,x,po_x,po_y,&mask,&alcohol);
        cb=botplay(SIZE,brd,&mask);
        system("cls");
        printf("Mode: %s  ",leve);
        SetConsoleTextAttribute(h,inten | red | green);
        printf("Turn: %d  ",turn);
        SetConsoleTextAttribute(h,inten | red | blue | green);
        printf("Mask: %d  ",mask);
        SetConsoleTextAttribute(h,inten | blue | green);
        printf("Alcohol: %d\n",alcohol);
        SetConsoleTextAttribute(h,normal);
        if(x==32&&alcohol!=0)
        {
            alcohol_use(SIZE,brd,po_x,po_y,mask);
            alcohol--;
        }
        show(brd,mask);
        turn++;
        for(int i=0;i<SIZE+2;i++)//find position of P
        {
            for(int j=0;j<SIZE+2;j++)
            {
                if(brd[i][j]=='I')
                {
                    po_x=i;
                    po_y=j;
                    break;
                }
            }
        }
        if(turn%5==0) spawn(brd,level,level);
        if(turn%20==0) spmask(SIZE,brd);
        if(turn%50==0) spalcohol(SIZE,brd);
    }
    system("color FC");
    printf("YOU ARE INFECTED\nYOU HAVE SURVIVED FOR %d TURN",turn-1);
    Beep(300,3000);
    return 0;
}
