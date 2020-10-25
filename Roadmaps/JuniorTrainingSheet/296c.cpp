#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(arr) if(!sizeof(arr))cout<<#arr<<" is empty"; else{cout<<#arr<<' ';for(int i = 0; i != sizeof(arr)/arr[0]; i++)cout<<i<<": "arr[i]<<' ';cout<<'\n';}
#define debvi(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';
#define debvvi(v) for(int i = 0; i != v.size(); i++){cout<<#v<<'['<<i<<"] : ";for(int j = 0; j != v[i].size(); j++)cout<<v[i][j]<<' ';cout<<'\n';}

int main()
{
    int n,m,k,i,j;
    cin>>n>>m>>k;
    ll a[n + 1], oper[m + 1][3];
    vll db(n + 2);
    vll book(m + 2);
    for(i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(i = 1; i <= m; i++){
        cin>>oper[i][0]>>oper[i][1]>>oper[i][2];
    }
    for(i = 0; i != k; i++){
        int x, y;
        cin>>x>>y;
        book[x] += 1;
        book[y + 1] -= 1;
    }
    for(i = 1; i <= m; i++){
        book[i] += book[i - 1];
    }
    for(i = 1; i <= m; i++){
        db[oper[i][0]] += book[i] * oper[i][2];
        db[oper[i][1] + 1] -= book[i] * oper[i][2];
    }
    for(i = 1; i <= n; i++){
        db[i] += db[i - 1];
    }
    for(i = 1; i <= n; i++){
        cout<<a[i] + db[i]<<' ';
    }
}