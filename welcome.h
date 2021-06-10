#define red FOREGROUND_RED
#define blue FOREGROUND_BLUE
#define green FOREGROUND_GREEN
#define inten FOREGROUND_INTENSITY
#define Red BACKGROUND_RED
#define Blue BACKGROUND_BLUE
#define Green BACKGROUND_GREEN
#define Inten BACKGROUND_INTENSITY
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
        if(kbhit())
        {
            s=getch();
            if((int)s==13){
                system("cls");
                printf("W");                Sleep(10);
                printf("i");                Sleep(10);
                printf("t");                Sleep(10);
                printf("h");                Sleep(10);
                printf(" ");                Sleep(10);
                printf("a");                Sleep(10);
                printf(" ");                Sleep(10);
                printf("p");                Sleep(10);
                printf("a");                Sleep(10);
                printf("n");                Sleep(10);
                printf("d");                Sleep(10);
                printf("e");                Sleep(10);
                printf("m");                Sleep(10);
                printf("i");                Sleep(10);
                printf("c");                Sleep(10);
                printf(" ");                Sleep(10);
                printf("h");                Sleep(10);
                printf("a");                Sleep(10);
                printf("p");                Sleep(10);
                printf("p");                Sleep(10);
                printf("e");                Sleep(10);
                printf("n");                Sleep(10);
                printf("i");                Sleep(10);
                printf("n");                Sleep(10);
                printf("g");                Sleep(10);
                printf(" ");                Sleep(10);
                printf("a");                Sleep(10);
                printf("r");                Sleep(10);
                printf("o");                Sleep(10);
                printf("u");                Sleep(10);
                printf("n");                Sleep(10);
                printf("d");                Sleep(10);
                printf(" ");                Sleep(10);
                printf("t");                Sleep(10);
                printf("h");                Sleep(10);
                printf("e");                Sleep(10);
                printf(" ");                Sleep(10);
                printf("g");                Sleep(10);
                printf("l");                Sleep(10);
                printf("o");                Sleep(10);
                printf("b");                Sleep(10);
                printf("e");                Sleep(10);
                printf(". \n");
                s=getch();
                printf("A"); Sleep(10);
                printf(" "); Sleep(10);
                printf("n"); Sleep(10);
                printf("o"); Sleep(10);
                printf("v"); Sleep(10);
                printf("e"); Sleep(10);
                printf("l"); Sleep(10);
                printf(" "); Sleep(10);
                printf("c"); Sleep(10);
                printf("o"); Sleep(10);
                printf("r"); Sleep(10);
                printf("o"); Sleep(10);
                printf("n"); Sleep(10);
                printf("a"); Sleep(10);
                printf("v"); Sleep(10);
                printf("i"); Sleep(10);
                printf("r"); Sleep(10);
                printf("u"); Sleep(10);
                printf("s"); Sleep(10);
                printf(" "); Sleep(10);
                printf("("); Sleep(10);
                printf("C"); Sleep(10);
                printf("O"); Sleep(10);
                printf("V"); Sleep(10);
                printf("I"); Sleep(10);
                printf("D"); Sleep(10);
                printf("-"); Sleep(10);
                printf("1"); Sleep(10);
                printf("9"); Sleep(10);
                printf(")"); Sleep(10);
                printf(" "); Sleep(10);
                printf("w"); Sleep(10);
                printf("a"); Sleep(10);
                printf("s"); Sleep(10);
                printf(" "); Sleep(10);
                printf("i"); Sleep(10);
                printf("d"); Sleep(10);
                printf("e"); Sleep(10);
                printf("n"); Sleep(10);
                printf("t"); Sleep(10);
                printf("i"); Sleep(10);
                printf("f"); Sleep(10);
                printf("i"); Sleep(10);
                printf("e"); Sleep(10);
                printf("d"); Sleep(10);
                printf(" "); Sleep(10);
                printf("i"); Sleep(10);
                printf("n"); Sleep(10);
                printf(" "); Sleep(10);
                printf("2"); Sleep(10);
                printf("0"); Sleep(10);
                printf("1"); Sleep(10);
                printf("9"); Sleep(10);
                printf(" "); Sleep(10);
                printf("i"); Sleep(10);
                printf("n"); Sleep(10);
                printf(" "); Sleep(10);
                printf("W"); Sleep(10);
                printf("u"); Sleep(10);
                printf("h"); Sleep(10);
                printf("a"); Sleep(10);
                printf("n"); Sleep(10);
                printf(","); Sleep(10);
                printf(" "); Sleep(10);
                printf("C"); Sleep(10);
                printf("h"); Sleep(10);
                printf("i"); Sleep(10);
                printf("n"); Sleep(10);
                printf("a"); Sleep(10);
                printf(". \n");
                s=getch();
                for(int i=1;i<78;i++){
                    for(int j=1;j<=i;j++) printf("\b");
                    printf("%.*s",i,"This is a new coronavirus that has not been previously identified in humans.");
                    Sleep(5);
                }
                printf("\n");
                //printf("This is a new coronavirus that has not been previously identified in humans. \n");
                s=getch();
                for(int i=1;i<171;i++){
                    for(int j=1;j<=i;j++) printf("\b");
                    printf("%.*s",i,"The outbreak of coronavirus disease 2019 (COVID-19) has created a global health crisis that has had a deep impact on the way we perceive our world and our everyday lives.");
                    Sleep(5);
                }
                printf("\n");
                s=getch();
                for(int i=1;i<115;i++){
                    for(int j=1;j<=i;j++) printf("\b");
                    printf("%.*s",i,"The disease may spread through large respiratory droplets and direct or indirect contact with infected secretions.");
                    Sleep(5);
                }
                printf("\n");
                s=getch();
                for(int i=1;i<79;i++){
                    for(int j=1;j<=i;j++) printf("\b");
                    printf("%.*s",i,"This game also, you will live in this city and protect yourself from COVID-19.");
                    Sleep(5);
                }
                s=getch();
                break;
            }
        }
        else continue;
    }
}

void help()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    WORD normal;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h,&csbiInfo);
    normal=csbiInfo.wAttributes;
    int a,b=1;
    SetConsoleTextAttribute(h,normal);
    printf(">  HOW TO PLAY\n\n");
    printf("\t1. Select level that has easy, normal, hard.\n\n");
    printf("\t2. Use W, A, S, D to control directions up, left, down, right.\n\n");
    printf("\t3. Collect the ");
    SetConsoleTextAttribute(h,red | green | inten);
    printf("c");
    SetConsoleTextAttribute(h,normal);
    printf("oins. Numbers of the coins will be your scores.\n\n");
    printf("\t4. Collect the item for help you from infected person.\n\n");
    printf("\t5. Keep distance with infected person. If you move to it, you will be infected. M can be inflected too!\n\n");
    printf("\t6. However, infected person can walk to you too!\n\n");
    printf("\t7. You walk before other people.\n\n");
    printf("\t8. Press \"Esc\" for exit at any time while playing game.\n\n");
    printf("\t9. Survive as long as you can!\n\n");
    SetConsoleTextAttribute(h,inten);
    printf("  CHARACTER\n  ITEM\n  BACK");
    while(1)
    {
        a=_getch();
        system("cls");
        if((a=='s')&&(b<4)) b++;
        else if((a=='w')&&(b>1)) b--;
        else if(a==13&&b==4)
        {
            break;
        }
        if(b==1)
        {
            SetConsoleTextAttribute(h,normal);
            printf("> HOW TO PLAY\n\n");
            printf("\t1. Select level that has easy, normal, hard.\n\n");
            printf("\t2. Use W, A, S, D to control directions up, left, down, right.\n\n");
            printf("\t3. Collect the ");
            SetConsoleTextAttribute(h,red | green | inten);
            printf("c");
            SetConsoleTextAttribute(h,normal);
            printf("oins. Numbers of the coins will be your scores.\n\n");
            printf("\t4. Collect the item for help you from infected person.\n\n");
            printf("\t5. Keep distance with infected person. If you move to it, you will be infected. M can be inflected too!\n\n");
            printf("\t6. However, infected person can walk to you too!\n\n");
            printf("\t7. You walk before other people.\n\n");
            printf("\t8. Press \"Esc\" for exit at any time while playing game.\n\n");
            printf("\t9. Survive as long as you can!\n\n");
            SetConsoleTextAttribute(h,inten);
            printf("  CHARACTER\n  ITEM\n  BACK");
        }
        else if(b==2)
        {
            SetConsoleTextAttribute(h,inten);
            printf("  HOW TO PLAY\n");
            SetConsoleTextAttribute(h,normal);
            printf("> CHARACTER\n");
            SetConsoleTextAttribute(h,green | inten);
            printf("    _____ \n");
            printf("   |_   _|\n");
            printf("     | |  ");
            printf("\t\tI ");
            SetConsoleTextAttribute(h,normal);
            printf("represents you, who plays game in this city.\n");
            SetConsoleTextAttribute(h,green | inten);
            printf("     | |  \n");
            printf("    _| |_ \n");
            printf("   |_____|\n");
            SetConsoleTextAttribute(h,normal);
            SetConsoleTextAttribute(h,blue | inten);
            printf("    __  __ \n");
            printf("   |  \\/  |\n");
            printf("   | \\  / |");
            printf("\t\tM ");
            SetConsoleTextAttribute(h,normal);
            printf("represents non-infected person with COVID-19.\n");
            SetConsoleTextAttribute(h,blue | inten);
            printf("   | |\\/| |\n");
            printf("   | |  | |\n");
            printf("   |_|  |_|\n");
            SetConsoleTextAttribute(h,normal);
            SetConsoleTextAttribute(h,red | inten);
            printf("  __      __\n");
            printf("  \\ \\    / /\n");
            printf("   \\ \\  / / ");
            printf("\t\tV ");
            SetConsoleTextAttribute(h,normal);
            printf("represents infected person with COVID-19.\n");
            SetConsoleTextAttribute(h,red | inten);
            printf("    \\ \\/ /  \n");
            printf("     \\  /   \n");
            printf("      \\/    \n");
            SetConsoleTextAttribute(h,normal);
            SetConsoleTextAttribute(h,inten);
            printf("\n  ITEM\n  BACK");
        }
        else if(b==3)
        {
            SetConsoleTextAttribute(h,inten);
            printf("  HOW TO PLAY\n  CHARACTER\n");
            SetConsoleTextAttribute(h,normal);
            printf("> ITEM\n");
            printf("   _ __ ___ \n");
            printf("  | '_ ` _ \\");
            printf("\t\tm represents the surgical mask using for protect you from COVID-19 for 3 times. You can collect maximum at 3 masks.\n");
            printf("  | | | | | |\n");
            printf("  |_| |_| |_|\n\n");

            SetConsoleTextAttribute(h,green | blue | inten);
            printf("      /\\    \n");
            printf("     /  \\   \n");
            printf("    / /\\ \\  ");
            printf("\t\tA ");
            SetConsoleTextAttribute(h,normal);
            printf("represents the Alcohol spray. Press \"SPACE BAR\" for using it to clean the virus from infected person in areas.\n");
            SetConsoleTextAttribute(h,green | blue | inten);
            printf("   / ____ \\ \n");
            printf("  /_/    \\_\\\n\n");

            SetConsoleTextAttribute(h,inten);
            printf("  BACK");
        }
        else if(b==4)
        {
            SetConsoleTextAttribute(h,inten);
            printf("  HOW TO PLAY\n  CHARACTER\n  ITEM\n");
            SetConsoleTextAttribute(h,normal);
            printf("<  BACK");
        }
    }
}
int home(){

    int start=1;
    char o;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD normal;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    normal = csbiInfo.wAttributes;
    int j=1;
    system("cls");
    SetConsoleTextAttribute(h, normal);
    printf(">  START\n");
    SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
    printf("  HELP\n  SCORE BOARD\n  QUIT");
    while(1){
    o=getch();
    system("cls");
    if((o=='s')&&(j<4)) j++;
    else if((o=='w')&&(j>1)) j--;
    else if(o==13)
    {
        SetConsoleTextAttribute(h, normal);
        if(j==1) return 1;
        else if(j==2) return 2;
        else if(j==3) return 3;
        else if(j==4) return 4;
        else return 35;
    }
    if(j==1)
    {
        SetConsoleTextAttribute(h,normal);
        printf(">  START\n");
        SetConsoleTextAttribute(h,inten);
        printf("  HELP\n  SCORE BOARD\n  QUIT");
    }
    else if(j==2)
    {
        SetConsoleTextAttribute(h,inten);
        printf("  START\n");
        SetConsoleTextAttribute(h,normal);
        printf(">  HELP\n");
        SetConsoleTextAttribute(h,inten);
        printf("  SCORE BOARD\n  QUIT");
    }
    else if(j==3)
    {
        SetConsoleTextAttribute(h,inten);
        printf("  START\n  HELP\n");
        SetConsoleTextAttribute(h,normal);
        printf(">  SCORE BOARD\n");
        SetConsoleTextAttribute(h,inten);
        printf("  QUIT\n");
    }
    else if(j==4)
    {
        SetConsoleTextAttribute(h,inten);
        printf("  START\n  HELP\n  SCORE BOARD\n");
        SetConsoleTextAttribute(h,normal);
        printf(">  QUIT\n");
    }
    }
}
void ENH(int *q)
{
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD normal;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    normal = csbiInfo.wAttributes;
    int x;
    *q=1;
    SetConsoleTextAttribute(h,inten);
    SetConsoleTextAttribute(h,normal);
    printf(">  EASY\n");
    SetConsoleTextAttribute(h,inten);
    printf("  NORMAL\n  HARD\n  BACK");
    SetConsoleTextAttribute(h,normal);
    while(1)
    {
        x=_getch();
        system("cls");
        if((x=='s')&&((*q)<4)) (*q)++;
        else if((x=='w')&&((*q)>1)) (*q)--;
        else if(x==13)
        {
            break;
        }
        if((*q)==1)
        {
            SetConsoleTextAttribute(h,normal);
            printf(">  EASY\n");
            SetConsoleTextAttribute(h,inten);
            printf("  NORMAL\n  HARD\n  BACK");
            SetConsoleTextAttribute(h,normal);
        }
        else if((*q)==2)
        {
            SetConsoleTextAttribute(h,inten);
            printf("  EASY\n");
            SetConsoleTextAttribute(h,normal);
            printf(">  NORMAL\n");
            SetConsoleTextAttribute(h,inten);
            printf("  HARD\n  BACK");
            SetConsoleTextAttribute(h,normal);
        }
        else if((*q)==3)
        {
            SetConsoleTextAttribute(h,inten);
            printf("  EASY\n  NORMAL\n");
            SetConsoleTextAttribute(h,normal);
            printf(">  HARD\n");
            SetConsoleTextAttribute(h,inten);
            printf("  BACK");
            SetConsoleTextAttribute(h,normal);
        }
        else if((*q)==4)
        {
            SetConsoleTextAttribute(h,inten);
            printf("  EASY\n  NORMAL\n  HARD\n");
            SetConsoleTextAttribute(h,normal);
            printf("<  BACK");
        }
    }
}
