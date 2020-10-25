#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

int main()
{
    int n, m, i, j, x, y, z, s;
    cin>>n>>m>>s;
    vi a[n + 1], b[n + 1],mrk(n + 1), dist(n + 1,INT_MAX),locked(n + 1);
    for(i = 0; i != m; i++){
        cin>>x>>y>>z;
        a[x].push_back(y);
        b[x].push_back(z);
        a[y].push_back(x);
        b[y].push_back(z);
    }
    dist[s] = 0;
    locked[s] = 1;
    y = x = s;
    stack<int>st;
    st.push(s);
    while(!st.empty()){
        x = st.top();
        st.pop();
        z = a[x].size();
        for(i = 0; i != z; i++){
            y = a[x][i];
            if(locked[y])continue;
            dist[y] = min(dist[y],dist[x] + b[x][i]);
        }
        int mn = INT_MAX, mni = 0;
        for(i = 0; i <= n; i++){
            if(mn > dist[i] && locked[i] == 0){
                mn = dist[i];
                mni = i;
            }
        }
        if(mni != 0){
            st.push(mni);
            locked[mni] = 1;
        }
    }
    for(i = 1; i <= n; i++)cout<<dist[i]<<' ';
}