#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

char a[200][200], b[200][200];
int mrk[200][200];
int n, m, i, j;

bool isValid(int ii, int jj){
    if(ii >= n || jj >= n || ii < 0 || jj < 0)return false;
    return true;
}

bool rec(int ii, int jj){
    if(isValid(ii,jj) == false)return false;
    if(ii == n - 1 && jj == n - 1)return true;
    if(rec(ii + 1,jj) && b[ii + 1][jj] == b[ii][jj])return true;
    if(rec(ii,jj + 1) && b[ii][jj + 1] == b[ii][jj])return true;
    return false;
}

void print(int x){
    if(a[0][1] != b[0][1])cout<<"1 2\n";
    if(a[1][0] != b[1][0])cout<<"2 1\n";
    if(a[n - 1][n - 2] != b[n - 1][n - 2])cout<<n<<' '<<n - 1<<"\n";
    if(a[n - 2][n - 1] != b[n - 2][n - 1])cout<<n - 1<<' '<<n<<"\n";
}

void solve(){
    
    cin>>n;
    for(i = 0; i != n; i++)
        for(j = 0; j != n; j++)cin>>a[i][j], b[i][j] = a[i][j];
    memset(mrk,0,sizeof(mrk));
    for(i = 0; i != 16; i++){
        b[0][1] = (i & 1 ? '1' : '0');
        b[1][0] = (i & 2 ? '1' : '0');
        b[n - 1][n - 2] = (i & 4 ? '1' : '0');
        b[n - 2][n - 1] = (i & 8 ? '1' : '0');    
        if(rec(1,0) == false && rec(0,1) == false){
            int c = 0;
            if(a[0][1] != b[0][1])c++;
            if(a[1][0] != b[1][0])c++;
            if(a[n - 1][n - 2] != b[n - 1][n - 2])c++;
            if(a[n - 2][n - 1] != b[n - 2][n - 1])c++;
            if(c > 2)continue;
            cout<<c<<'\n';
            print(c);
            break;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)solve();
}