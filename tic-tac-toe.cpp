#include<iostream>
#include<stdio.h>
using namespace std;

void display(int *board)
{
    for(int i=0;i<9;i++)
    {
        cout<<"|";
        if(board[i]==1){cout<<"O";}
        else if(board[i]==2){cout<<"X";}
        else{cout<<" ";}
        if(i%3==2){cout<<"|\n";}
    }
}

bool wincheck(int *a)
{
    if(a[0]==1&&a[4]==1&&a[8]==1){cout<<"PLAYER 1 WINS!\n";return true;}
    else if(a[0]==2&&a[4]==2&&a[8]==2){cout<<"PLAYER 2 WINS!\n";return true;}
    else if(a[2]==2&&a[4]==2&&a[6]==2){cout<<"PLAYER 2 WINS!\n";return true;}
    else if(a[2]==1&&a[4]==1&&a[6]==1){cout<<"PLAYER 1 WINS!\n";return true;}
    
    for(int i=0;i<=6;i+=3)
    {
        if(a[i]==2&&a[i+1]==2&&a[i+2]==2){cout<<"PLAYER 2 WINS!\n";return true;}
        else if(a[i]==1&&a[i+1]==1&&a[i+2]==1){cout<<"PLAYER 1 WINS!\n";return true;}
    }
    
    for(int i=0;i<3;i++)
    {
        if(a[i]==2&&a[i+3]==2&&a[i+6]==2){cout<<"PLAYER 2 WINS!\n";return true;}
        else if(a[i]==1&&a[i+3]==1&&a[i+6]==1){cout<<"PLAYER 1 WINS!\n";return true;}
    }
    
    int flag=0;
    
    for(int i=0;i<9;i++)
    {
        if(a[i]==0){flag=1;break;}
    }
    if(flag==0){cout<<"DRAW\n";return true;}
}

void message()
{
    cout<<"THE BOARD POSITIONS ARE AS FOLLOWS\n|0|1|2|\n|3|4|5|\n|6|7|8|\nPLAYER 1 is O\nPLAYER 2 is X\n";
}

void fill(int *a,int n,int t)
{
    if(a[n]==1||a[n]==2){cout<<"INVALID MOVE : MUST RESTART GAME";exit(0);}
    a[n]=t;
}

int main()
{
    int board[9]={0,0,0,0,0,0,0,0,0};
    int p;
    message();
    display(board);
    wincheck(board);
    for(int i=0;i<9;i++)
    {
    printf("\033[u\033[2J");//for LINUX/UNIX
    system("CLS");//FOR WINDOWS
    message();
    display(board);
     cout<<"PLAYER "<<(i%2)+1<<"\'s TURN\nENTER POSITION : ";cin>>p;
     fill(board,p,(i%2)+1);
     if(wincheck(board))break;
    }
    display(board);
    cout<<"\r\n\r\nPRESS ANY KEY TO EXIT : ";cin>>p;
    return 0;
}
