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
