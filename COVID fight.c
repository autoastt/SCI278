#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "createboard.h"
#include "play.h"
#include "item.h"
#define SIZE 25
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
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | FOREGROUND_INTENSITY );
                    printf(" %c ",brd[i][k]);
                }
                else if(brd[i][k]=='P')
                {
                    if(mask>0){
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
                        printf(" %c ",brd[i][k]);
                    }
                    else{
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                        printf(" %c ",brd[i][k]);
                    }
                }
                else if(brd[i][k]=='M')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE | FOREGROUND_INTENSITY );
                    printf(" %c ",brd[i][k]);
                }
                else if(brd[i][k]=='V')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY );
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
        if(brd[poM_x+1][poM_y]!='P'&&brd[poM_x-1][poM_y]!='P'&&brd[poM_x][poM_y+1]!='P'&&brd[poM_x][poM_y-1]!='P')
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
    char x, brd[SIZE+2][SIZE+2];
    int level, c=1, cb=1, turn=0, po_x=0, po_y=0, mask=0;
    printf("1.EASY\n2.NORMAL\n3.HARD\n");
    //level=getche();
    scanf("%d",&level);//input level
    createboard(SIZE,level,brd);//create board
    do//locate player
    {
        srand(time(0));
        po_x=rand()%SIZE;
        po_y=rand()%SIZE;
    }while(brd[po_x][po_y]!=' ');
    brd[po_x][po_y]='P';
    if(level==1) spawn(brd,5,level);//spawn people
    else if(level==2) spawn(brd,8,level);
    else if(level==3) spawn(brd,12,level);
    show(brd,mask);
    while(c!=69&&cb!=69)//play
    {
        srand(time(0));
        x=getche(); //input turn
        //scanf(" %c",&x);
        //printf("x=%c\n",x);
        c=play(SIZE,brd,x,po_x,po_y,&mask);
        cb=botplay(SIZE,brd,&mask);
        system("cls");
        printf("turn %d, mask %d\n",turn,mask);
        if(c==420)
        {
            mask=3;
            c=1;
        }
        show(brd,mask);
        turn++;
        for(int i=0;i<SIZE+2;i++)
        {
            for(int j=0;j<SIZE+2;j++)
            {
                if(brd[i][j]=='P')
                {
                    po_x=i;
                    po_y=j;
                    break;
                }
            }
        }
        if(turn%5==0) spawn(brd,level,level);
        if(turn%20==0) spmask(SIZE,brd);
        //if(turn%50==0) algohol(SIZE,brd);
    }
    system("color FC");
    printf("YOU ARE INFECTED\nYOU HAVE SURVIVED FOR %d TURN",turn-1);
    return 0;
}
