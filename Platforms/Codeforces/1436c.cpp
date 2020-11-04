#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

ll n, m, k, q;
vvi a;
vi dist;
set<int> special,temp;
map<int,queue<int> >mp;

void solve(){
    cin>>n>>m>>k;
    ll i, j;
    int x, y;
    a = vvi(n + 1);dist = vi(n + 1, -1);
    for(i = 0; i != m; i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(i = 0; i != k; i++){
        cin>>x;
        special.insert(x);
        dist[x] = 0;
        for(j = 0; j != a[x].size(); j++){
            ll y = a[x][j];
            if(dist[y] != -1)continue;
            dist[y] = 1;
            mp[x].push(y);
        }
    }
    int rank = 2;
    temp = special;
    while(!special.empty()){
        for(int x : special){
            if(mp[x].empty()){
                temp.erase(x);
            }
            else{
                queue<int>que;
                while(!mp[x].empty()){
                    int xx = mp[x].front();
                    mp[x].pop();
                    for(int yy : a[xx]){
                        if(dist[yy] == -1){
                            dist[yy] = rank;
                            que.push(yy);
                        }
                    }
                }
                mp[x] = que;
            }
        }
        rank++;
        special = temp;
    }
    cin>>q;
    for(i = 0; i != q; i++){
        cin>>x;
        cout<<dist[x]<<'\n';
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    
}