/*
Coded by
Thunyapat Silpsamrit
Peeranat Kongkjpipat
Apisara Comchiang

*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "welcome.h"
#include "createboard.h"
#include "walk.h"
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
int play(int *score, char name[], int *w)
{
    char x, brd[SIZE+2][SIZE+2], leve[10];
    int level, c=1, cb=1, turn=1, po_x=0, po_y=0, mask=0, alcohol=0,n,q=1,a=1,le;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    WORD normal;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h,&csbiInfo);
    normal=csbiInfo.wAttributes;
    ENH(&q);
    if(q==4) return 77;
    level=q;
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
        spawn(SIZE,brd,5,level);
        strcpy(leve,"EASY");
    }
    else if(level==2){
        spawn(SIZE,brd,8,level);
        strcpy(leve,"NORMAL");
    }
    else if(level==3){
        spawn(SIZE,brd,12,level);
        strcpy(leve,"HARD");
    }
    (*w)=level;
    printf("Mode: %s  ",leve);
    SetConsoleTextAttribute(h,inten | red | green);
    printf("Score: 0  ");
    SetConsoleTextAttribute(h,inten | red | blue | green);
    printf("Mask:       ",mask);
    SetConsoleTextAttribute(h,inten | blue | green);
    printf("Alcohol: %d\n",alcohol);
    SetConsoleTextAttribute(h,normal);
    if(check_coin(SIZE,brd)==0) spcoin(SIZE,brd);
    show(brd,mask);
    while(c!=69&&cb!=69)//play
    {
        srand(time(0));
        x=_getch(); //input turn
        if(x==27) return 1;
        c=walk(SIZE,brd,x,po_x,po_y,&mask,&alcohol,score);
        cb=botwalk(SIZE,brd,&mask);
        turn++;
        system("cls");
        printf("Mode: %s  ",leve);
        SetConsoleTextAttribute(h,inten | red | green);
        printf("Score: %d  ",*score);
        SetConsoleTextAttribute(h,inten | red | blue | green);
        printf("Mask:");
        printf("%.*s",mask*2," m m m");
        if(mask==1) printf("      ");
        else if(mask==2) printf("   ");
        else if(mask==3) printf(" ");
        else if(mask==0) printf("       ");
        SetConsoleTextAttribute(h,inten | blue | green);
        printf("Alcohol: %d\n",alcohol);
        SetConsoleTextAttribute(h,normal);
        if(x==32&&alcohol!=0)
        {
            alcohol_use(SIZE,brd,po_x,po_y,mask);
            alcohol--;
            printf("Mode: %s  ",leve);
            SetConsoleTextAttribute(h,inten | red | green);
            printf("Score: %d  ",*score);
            SetConsoleTextAttribute(h,inten | red | blue | green);
            printf("Mask:");
            printf("%.*s",mask*2," m m m");
            if(mask==1) printf("      ");
            else if(mask==2) printf("   ");
            else if(mask==3) printf(" ");
            else if(mask==0) printf("       ");
            SetConsoleTextAttribute(h,inten | blue | green);
            printf("Alcohol: %d\n",alcohol);
            SetConsoleTextAttribute(h,normal);
        }
        if(check_coin(SIZE,brd)==0) spcoin(SIZE,brd);
        show(brd,mask);
        for(int i=0;i<SIZE+2;i++)//find position of I
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
        if(turn%5==0) spawn(SIZE,brd,level,level);
        if(turn%20==0) spmask(SIZE,brd);
        if(turn%50==0) spalcohol(SIZE,brd);
    }
    system("color FC");
    printf("YOU ARE INFECTED.\nYOU SURVIVED FOR %d TURNS.\nYOU GOT %d SCORES.\n",turn-1,*score);
    Beep(1000,500);
    Beep(850,750);
    Beep(500,500);
    Sleep(500);
    SetConsoleTextAttribute(h,normal);
    system("cls");
    printf("ENTER YOUR NAME:");
    scanf("%s",name);
    system("cls");
    SetConsoleTextAttribute(h,normal);
    printf(">  HOME\n");
    SetConsoleTextAttribute(h,inten);
    printf("  SCORE BOARD\n  QUIT");
    while(1)
    {
        n=_getch();
        system("cls");
        if(n=='s'&&a<3) a++;
        else if(n=='w'&&a>0) a--;
        else if(n==13)
        {
            break;
        }
        if(a==1)
        {
            SetConsoleTextAttribute(h,normal);
            printf(">   HOME\n");
            SetConsoleTextAttribute(h,inten);
            printf("  SCORE BOARD\n  QUIT");
        }
        else if(a==2)
        {
            SetConsoleTextAttribute(h,inten);
            printf("  HOME\n");
            SetConsoleTextAttribute(h,normal);
            printf(">   SCORE BOARD\n");
            SetConsoleTextAttribute(h,inten);
            printf("  QUIT");
        }
        else if(a==3)
        {
            SetConsoleTextAttribute(h,inten);
            printf("  HOME\n  SCORE BOARD\n");
            SetConsoleTextAttribute(h,normal);
            printf(">   QUIT");
        }
    }
    if(a==1) return 1;
    else if(a==2) return 2;
    else if(a==3) return 0;
}
void show_score_board(int score, char name[30], char score_list[11][30], int w)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    WORD normal;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h,&csbiInfo);
    normal=csbiInfo.wAttributes;
    FILE *fr, *fw;
    int sc[11], temp_sc,x;
    char temp_name[30];
    if(w==1) fr=fopen("scoreboard_easy.txt","r");
    else if(w==2) fr=fopen("scoreboard_normal.txt","r");
    else if(w==3) fr=fopen("scoreboard_hard.txt","r");
    for(int i=0;i<10;i++) fscanf(fr,"%s %d",&score_list[i],&sc[i]);
    strcpy(score_list[10],name);
    sc[10]=score;
    for(int k=0;k<11;k++)
    {
        for(int j=0;j<11;j++)
        {
            if(sc[j]<sc[k])
            {
                strcpy(temp_name,score_list[k]);
                temp_sc=sc[k];
                strcpy(score_list[k],score_list[j]);
                sc[k]=sc[j];
                strcpy(score_list[j],temp_name);
                sc[j]=temp_sc;
            }
        }
    }
    SetConsoleTextAttribute(h,inten);
    printf("RANK\t\t\t\tNAME\t\t\t\tSCORE\n\n");
    SetConsoleTextAttribute(h,normal);
    if(w==1) fw=fopen("scoreboard_easy.txt","w");
    else if(w==2) fw=fopen("scoreboard_normal.txt","w");
    else if(w==3) fw=fopen("scoreboard_hard.txt","w");
    for(int i=0;i<10;i++)
    {
        if(i==0) SetConsoleTextAttribute(h,green | red | inten);
        fprintf(fw,"%s %d\n",score_list[i],sc[i]);
        printf("%d\t\t\t\t%s",i+1,score_list[i],sc[i]);
        if(strlen(score_list[i])<=8) printf("\t");
        printf("\t\t\t%d\n",sc[i]);
        SetConsoleTextAttribute(h,normal);
    }
    x=getch();
    fclose(fr);
    fclose(fw);
}
int main()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    WORD normal;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h,&csbiInfo);
    normal=csbiInfo.wAttributes;
    char score_list[11][30], name[30];
    int hom,l,score=0,w;
    welcome();
    while(1)
    {
        score=0;
        hom=home();
        if(hom==1) goto PLAY;
        else if(hom==2) goto HELP;
        else if(hom==3)
        {
            ENH(&w);
            if(w!=4) show_score_board(score,name,score_list,w);
            goto HOME;
        }
        else if(hom==4) return 0;
        else goto HOME;
        HELP:
        help();
        goto HOME;
        PLAY:
        l=play(&score,name,&w);
        SetConsoleTextAttribute(h,normal);
        if(l==2) show_score_board(score,name,score_list,w);
        else if(!l) break;
        HOME:
        ;
    }
    return 0;
}
