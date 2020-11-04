#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

vvi graph;
vi mrk, state;
int temp = 0;

int rec(int x, int st){

}

int main()
{
    int k, n, i, j,x,y;
    cin>>n;
    graph = vvi(n + 1);
    mrk = state = vi(n + 1);
    for(i = 1; i <= n; i++){
        cin>>k;
        while(k--){
            cin>>x;
            graph[i].push_back(x);
        }
    }
    x = 1;
    for(i = 1; i <= n; i++){
        if(mrk[i])continue;
        rec(i,x);
        x++;
    }
    for(i = 1; i <= n; i++)
        cout<<mrk[i]<<' ';
    cout<<'\n';
}
