void createboard (int SIZE, int level, char brd[][SIZE+2])
{
    srand(time(0));
    int t2,t3;
    for(int i=0;i<SIZE+2;i++)
    {
        for(int j=0;j<SIZE+2;j++)
            {
                brd[i][j]=' ';
                if(i==0) brd[0][j]='-';
                else if(j==0) brd[i][0]='|';
                else if(i==SIZE+1) brd[SIZE+1][j]='-';
                else if(j==SIZE+1) brd[i][SIZE+1]='|' ;
            }
    }
    brd[0][0]='O';
    brd[0][SIZE+1]='O';
    brd[SIZE+1][0]='O';
    brd[SIZE+1][SIZE+1]='O';
  if(level==1)
    {
        t3=4;
        t2=7;
    }
  else if(level==2)
    {
        t3=6;
        t2=9;
    }
  else if(level==3)
    {
        t3=8;
        t2=11;
    }
    for(int i=0,k=0;i<t3;i++)//3*3 tower
        {
            k=rand()%(SIZE*SIZE);
            if(brd[k%SIZE+1][k/SIZE]==' ') brd[k%SIZE+1][k/SIZE]='X';
            if(brd[k%SIZE+2][k/SIZE]==' ') brd[k%SIZE+2][k/SIZE]='X';
            if(brd[k%SIZE][k/SIZE]==' ') brd[k%SIZE][k/SIZE]='X';
            if(brd[k%SIZE+1][k/SIZE+1]==' ') brd[k%SIZE+1][k/SIZE+1]='X';
            if(brd[k%SIZE+2][k/SIZE+1]==' ') brd[k%SIZE+2][k/SIZE+1]='X';
            if(brd[k%SIZE][k/SIZE+1]==' ') brd[k%SIZE][k/SIZE+1]='X';
            if(brd[k%SIZE+1][k/SIZE-1]==' ') brd[k%SIZE+1][k/SIZE-1]='X';
            if(brd[k%SIZE+2][k/SIZE-1]==' ') brd[k%SIZE+2][k/SIZE-1]='X';
            if(brd[k%SIZE][k/SIZE-1]==' ') brd[k%SIZE][k/SIZE-1]='X';
        }
        for(int i=0,k=0;i<t2;i++)//2*2 tower
        {
            k=rand()%(SIZE*SIZE);
            if(brd[k%SIZE+1][k/SIZE]==' ') brd[k%SIZE+1][k/SIZE]='X';
            if(brd[k%SIZE+2][k/SIZE]==' ') brd[k%SIZE+2][k/SIZE]='X';
            if(brd[k%SIZE+1][k/SIZE+1]==' ') brd[k%SIZE+1][k/SIZE+1]='X';
            if(brd[k%SIZE+2][k/SIZE+1]==' ') brd[k%SIZE+2][k/SIZE+1]='X';

        }

}
