#include<stdio.h>
#include<conio.h>
#include<Windows.h>
void gotoXY(int x, int y)
{

 COORD coord;

 coord.X = x;

 coord.Y = y;

 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void welcome(){
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD normal;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    normal = csbiInfo.wAttributes;
    char s;
    SetConsoleTextAttribute( h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("===============================\n");
    SetConsoleTextAttribute( h, normal);
    printf("    WELCO");
    SetConsoleTextAttribute( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("M");
    SetConsoleTextAttribute( h, normal);
    printf("E TO CO");
    SetConsoleTextAttribute( h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("V");
    SetConsoleTextAttribute( h, normal);
    printf("ID F");
    SetConsoleTextAttribute( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("I");
    SetConsoleTextAttribute( h, normal);
    printf("GHT!\n");
    SetConsoleTextAttribute( h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("===============================\n");
    SetConsoleTextAttribute( h, normal);
    while(1){
        gotoXY(0,3);
        printf("Press ENTER to start. . .");
        Sleep(300);
        gotoXY(0,3);
        printf("                         ");
        Sleep(300);
        if(kbhit()){
            s=getch();
            if((int)s==13) break;
            //else printf("You have entered : %d\n", s);
        }
    }
    //printf("here");
}
int main(){
    int start=1;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD normal;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    normal = csbiInfo.wAttributes;
    int p=0;
    welcome();
    system("cls");
    SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
    printf("  1. Start\n");
    printf("  2. How to play");
    SetConsoleTextAttribute(h, normal);
    while(1){
    p=getch();
    system("cls");
    if(p=='w'){
        SetConsoleTextAttribute(h, normal);
        printf("> 1. Start\n");
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
        printf("  2. How to play");
        //PLAY GAME
    }
    else if(p=='s'){
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
        printf("  1. Start\n");
        SetConsoleTextAttribute(h, normal);
        printf("> 2. How to play");
        //INSTUCTION
        //printf("")
    }
    else if(p=13) break;
    }
    return 0;
}
