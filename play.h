//  #include<stdio.h>
int play(int SIZE, char brd[][SIZE+2], char x, int po_x, int po_y, int *mask)
{
    //printf("%d %d",mask,&mask);
    if(x=='w')
    {
        if(brd[po_x-1][po_y]==' ')
        {
            brd[po_x][po_y]=' ';
            brd[po_x-1][po_y]='P';
        }
        else if(brd[po_x-1][po_y]=='V')
        {
            if((*mask)>0)
            {
                (*mask)--;
                return 1;
            }
            else return 69;
        }
        else if(brd[po_x-1][po_y]=='m')
        {
            (*mask)=3;
            brd[po_x][po_y]=' ';
            brd[po_x-1][po_y]='P';
            return 420;
        }
    }
    else if(x=='s')
    {
        if(brd[po_x+1][po_y]==' ')
        {
            brd[po_x][po_y]=' ';
            brd[po_x+1][po_y]='P';
        }
        else if(brd[po_x+1][po_y]=='V')
        {
            if((*mask)>0)
            {
                (*mask)--;
                return 1;
            }
            else return 69;
        }
        else if(brd[po_x+1][po_y]=='m')
        {
            (*mask)=3;
            brd[po_x][po_y]=' ';
            brd[po_x+1][po_y]='P';
            return 420;
        }
    }
    else if(x=='d')
    {
        if(brd[po_x][po_y+1]==' ')
        {
            brd[po_x][po_y]=' ';
            brd[po_x][po_y+1]='P';
        }
        else if(brd[po_x][po_y+1]=='V')
        {
            if((*mask)>0)
            {
                (*mask)--;
                return 1;
            }
            else return 69;
        }
        else if(brd[po_x][po_y+1]=='m')
        {
            (*mask)=3;
            brd[po_x][po_y]=' ';
            brd[po_x][po_y+1]='P';
            return 420;
        }
    }
    else if(x=='a')
    {
        if(brd[po_x][po_y-1]==' ')
        {
            brd[po_x][po_y]=' ';
            brd[po_x][po_y-1]='P';
        }
        else if(brd[po_x][po_y-1]=='V')
        {
            if((*mask)>0)
            {
                (*mask)--;
                return 1;
            }
            else return 69;
        }
        else if(brd[po_x][po_y-1]=='m')
        {
            (*mask)=3;
            brd[po_x][po_y]=' ';
            brd[po_x][po_y-1]='P';
            return 420;
        }
    }
    return 1;
}
int botplay(int SIZE, char brd[][SIZE+2],int *mask)
{
    int w;
    for(int i=0;i<SIZE+2;i++)
    {
        for(int j=0;j<SIZE+2;j++)
        {
            if(brd[i][j]=='M')
            {
                w=rand()%5;
                brd[i][j]=' ';
                if(w==1&&(brd[i+1][j]==' '))
                {
                    brd[i+1][j]='M';
                }
                else if(w==2&&(brd[i-1][j]==' '))
                {
                    brd[i-1][j]='M';
                }
                else if(w==3&&(brd[i][j+1]==' '))
                {
                    brd[i][j+1]='M';
                }
                else if(w==4&&(brd[i][j-1]==' '))
                {
                    brd[i][j-1]='M';
                }
                else
                {
                    if(w==1&&(brd[i+1][j]=='V')) brd[i][j]='V';
                    else if(w==2&&(brd[i-1][j]=='V')) brd[i][j]='V';
                    else if(w==3&&(brd[i][j+1]=='V')) brd[i][j]='V';
                    else if(w==4&&(brd[i][j-1]=='V')) brd[i][j]='V';
                    else brd[i][j]='M';
                }
            }
            if(brd[i][j]=='V')
            {
                w=rand()%5;
                brd[i][j]=' ';
                if(w==1&&((brd[i+1][j]==' ')||brd[i+1][j]=='P'))
                {

                    if(brd[i+1][j]=='P')
                    {
                        if((*mask)>0){
                            (*mask)--;
                            brd[i][j]='V';
                            return 1;
                        }
                        else{
                            brd[i+1][j]='V';
                            return 69;
                        }
                    }
                    else brd[i+1][j]='V';
                }
                else if(w==2&&((brd[i-1][j]==' ')||brd[i-1][j]=='P'))
                {
                    if(brd[i-1][j]=='P')
                    {
                        if((*mask)>0){
                            (*mask)--;
                            brd[i][j]='V';
                            return 1;
                        }
                        else{
                            brd[i-1][j]='V';
                            return 69;
                        }
                    }
                    else brd[i-1][j]='V';
                }
                else if(w==3&&((brd[i][j+1]==' ')||brd[i][j+1]=='P'))
                {
                    if(brd[i][j+1]=='P')
                    {
                        if((*mask)>0){
                            (*mask)--;
                            brd[i][j]='V';
                            return 1;
                        }
                        else{
                            brd[i][j+1]='V';
                            return 69;
                        }
                    }
                    else brd[i][j+1]='V';
                }
                else if(w==4&&((brd[i][j-1]==' ')||brd[i][j-1]=='P'))
                {
                    if(brd[i][j-1]=='P')
                    {
                        if((*mask)>0){
                            (*mask)--;
                            brd[i][j]='V';
                            return 1;
                        }
                        else{
                            brd[i][j-1]='V';
                            return 69;
                        }
                    }
                    else brd[i][j-1]='V';
                }
                else
                {
                    if(w==1&&(brd[i+1][j]=='M')) brd[i+1][j]='V';
                    else if(w==2&&(brd[i-1][j]=='M')) brd[i-1][j]='V';
                    else if(w==3&&(brd[i][j+1]=='M')) brd[i][j+1]='V';
                    else if(w==4&&(brd[i][j-1]=='M')) brd[i][j-1]='V';
                    else brd[i][j]='V';
                }
            }
        }
    }
}

