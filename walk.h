//  #include<stdio.h>
int walk(int SIZE, char brd[][SIZE+2], char x, int po_x, int po_y, int *mask, int *alcohol, int *score)
{
    //printf("%d %d",mask,&mask);
    if(x=='w')
    {
        if(brd[po_x-1][po_y]==' ')
        {
            brd[po_x][po_y]=' ';
            brd[po_x-1][po_y]='I';
        }
        else if(brd[po_x-1][po_y]=='V')
        {
            if((*mask)>0)
            {
                (*mask)--;
                Beep(300,300);
                return 1;
            }
            else return 69;
        }
        else if(brd[po_x-1][po_y]=='m')
        {
            (*mask)=3;
            brd[po_x][po_y]=' ';
            brd[po_x-1][po_y]='I';
            return 420;
        }
        else if(brd[po_x-1][po_y]=='A')
        {
            (*alcohol)++;
            brd[po_x][po_y]=' ';
            brd[po_x-1][po_y]='I';
            return 798;
        }
        else if(brd[po_x-1][po_y]=='c')
        {
            Beep(850,300);
            (*score)++;
            brd[po_x][po_y]=' ';
            brd[po_x-1][po_y]='I';
        }
    }
    else if(x=='s')
    {
        if(brd[po_x+1][po_y]==' ')
        {
            brd[po_x][po_y]=' ';
            brd[po_x+1][po_y]='I';
        }
        else if(brd[po_x+1][po_y]=='V')
        {
            if((*mask)>0)
            {
                Beep(300,300);
                (*mask)--;
                return 1;
            }
            else return 69;
        }
        else if(brd[po_x+1][po_y]=='m')
        {
            (*mask)=3;
            brd[po_x][po_y]=' ';
            brd[po_x+1][po_y]='I';
            return 420;
        }
        else if(brd[po_x+1][po_y]=='A')
        {
            (*alcohol)++;
            brd[po_x][po_y]=' ';
            brd[po_x+1][po_y]='I';
            return 798;
        }
        else if(brd[po_x+1][po_y]=='c')
        {
            Beep(850,300);
            (*score)++;
            brd[po_x][po_y]=' ';
            brd[po_x+1][po_y]='I';
        }
    }
    else if(x=='d')
    {
        if(brd[po_x][po_y+1]==' ')
        {
            brd[po_x][po_y]=' ';
            brd[po_x][po_y+1]='I';
        }
        else if(brd[po_x][po_y+1]=='V')
        {
            if((*mask)>0)
            {
                Beep(300,300);
                (*mask)--;
                return 1;
            }
            else return 69;
        }
        else if(brd[po_x][po_y+1]=='m')
        {
            (*mask)=3;
            brd[po_x][po_y]=' ';
            brd[po_x][po_y+1]='I';
            return 420;
        }
        else if(brd[po_x][po_y+1]=='A')
        {
            (*alcohol)++;
            brd[po_x][po_y]=' ';
            brd[po_x][po_y+1]='I';
            return 798;
        }
        else if(brd[po_x][po_y+1]=='c')
        {
            Beep(850,300);
            (*score)++;
            brd[po_x][po_y]=' ';
            brd[po_x][po_y+1]='I';
        }
    }
    else if(x=='a')
    {
        if(brd[po_x][po_y-1]==' ')
        {
            brd[po_x][po_y]=' ';
            brd[po_x][po_y-1]='I';
        }
        else if(brd[po_x][po_y-1]=='V')
        {
            if((*mask)>0)
            {
                Beep(300,300);
                (*mask)--;
                return 1;
            }
            else return 69;
        }
        else if(brd[po_x][po_y-1]=='m')
        {
            (*mask)=3;
            brd[po_x][po_y]=' ';
            brd[po_x][po_y-1]='I';
            return 420;
        }
        else if(brd[po_x][po_y-1]=='A')
        {
            (*alcohol)++;
            brd[po_x][po_y]=' ';
            brd[po_x][po_y-1]='I';
            return 798;
        }
        else if(brd[po_x][po_y-1]=='c')
        {
            Beep(850,300);
            (*score)++;
            brd[po_x][po_y]=' ';
            brd[po_x][po_y-1]='I';
        }
    }
    return 1;
}
int botwalk(int SIZE, char brd[][SIZE+2],int *mask)
{
    int w;
    for(int i=0;i<SIZE+2;i++)
    {
        for(int j=0;j<SIZE+2;j++)
        {
            if(brd[i][j]=='M')// if bot is M
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
                else// if bot is V
                {
                    if(w==1&&(brd[i+1][j]=='V')) brd[i][j]='V';
                    else if(w==2&&(brd[i-1][j]=='V')) brd[i][j]='V';
                    else if(w==3&&(brd[i][j+1]=='V')) brd[i][j]='V';
                    else if(w==4&&(brd[i][j-1]=='V')) brd[i][j]='V';
                    else brd[i][j]='M';
                }
            }
            if(brd[i][j]=='V')// V hit I
            {
                w=rand()%5;
                brd[i][j]=' ';
                if(w==1&&((brd[i+1][j]==' ')||brd[i+1][j]=='P'))
                {

                    if(brd[i+1][j]=='P')
                    {
                        if((*mask)>0){
                            Beep(300,300);
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
                            Beep(300,300);
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
                    if(brd[i][j+1]=='I')
                    {
                        if((*mask)>0){
                            Beep(300,300);
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
                else if(w==4&&((brd[i][j-1]==' ')||brd[i][j-1]=='I'))
                {
                    if(brd[i][j-1]=='I')
                    {
                        if((*mask)>0){
                            Beep(300,300);
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
                else//M is infected & become V
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

