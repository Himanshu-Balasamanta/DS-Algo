#include<bits/stdc++.h>
using namespace std;
int m;
vector<string>boardset(int n)
{
    vector<string>board(n,string(n,'0'));
    int i,j,k,o,p;cin>>m;
    for(i=0;i!=m;i++){
        cin>>o>>p;
        for(j=o-1;j!=o+2;j++){
            for(k=p-1;k!=p+2;k++){
                if((j>=0)&&(j<n)&&(k>=0)&&(k<n))
                        board[j][k]++;
            }
        }
        board[o][p]='*';
    }
    return board;
}
bool chkend(int n,char*screen)
{
    int i,j;
    for(i=0;i!=n;i++){
        for(j=0;j!=n;j++){
            if(*(screen+i*n+j)=='?')return true;
        }
    }
    return false;
}
void reveal(int i,int j,char* screen,char* board,int n)
{
    if((i>=0)&&(i<n)&&(j>=0)&&(j<n)){
        if(*(screen+n*i+j)=='?'){
            if(*(board+i*n+j)=='0'){reveal(i+1,j,screen,board,n);reveal(i-1,j,screen,board,n);
            reveal(i,j+1,screen,board,n);reveal(i,j-1,screen,board,n);swap(*(board+i*n+j),*(screen+i*n+j));
            }
            else{}
        }
    }
}
int main()
{
    int n=8,i,j;char x;
    char screen[n][n],board[n][n];
    for(i=0;i!=n;i++){for(j=0;j!=n;j++){screen[i][j]='?';}}
    vector<string>board= boardset(n);
    while(chkend(n,&screen[0][0])){
        cout<<"ENTER THE SYMBOL AND THE CO-ORDINATES, ALL SEPARATED BY SPACE\n";
        cout<<"USE '!' TO MARK MINE, '$' TO UNCOVER IT\n";
        cout<<"YOU CAN MARK ONLY "<<m<<" MINES MORE\n";
        cin>>x>>i>>j;
        if(screen[i][j]=='?'){
            if(x=='$'){
                if(board[i][j]=='*'){}
                else{reveal(i,j,&screen[0][0],&board[0][0],n);}
            }
        }
    }
}