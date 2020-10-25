#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define V vector
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

vector<int>mrk,xx,yy,a[1001],b[1001];

int main()
{
    int n, i, j;
    cin>>n;
    xx = yy = mrk = vi(n + 1);
    for(i = 1; i <= n; i++){
        cin>>xx[i]>>yy[i];
        a[xx[i]].push_back(i);
        b[yy[i]].push_back(i);
    }
    int z = 0;
    for(i = 1; i <= n; i++){
        if(mrk[i])continue;
        z++;
        stack<int>x, y;
        x.push(i);y.push(i);
        while(!x.empty() || !y.empty()){
            if(!x.empty()){
                int aa = x.top();
                mrk[aa] = 1;
                x.pop();
                for(int bb : b[yy[aa]]){
                    if(mrk[bb])continue;
                    mrk[bb] = 1;
                    y.push(bb);
                }
            }
            if(!y.empty()){
                int aa = y.top();
                mrk[aa] = 1;
                y.pop();
                for(int bb : a[xx[aa]]){
                    if(mrk[bb])continue;
                    mrk[bb] = 1;
                    x.push(bb);
                }
            }
        }
    }
    cout<<z - 1;
}