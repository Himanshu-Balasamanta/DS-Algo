#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<" : "<<x<<' ';
#define debarr(arr) if(!sizeof(arr))cout<<#arr<<" is empty"; else{cout<<#arr<<' ';for(int i = 0; i != sizeof(arr)/arr[0]; i++)cout<<i<<": "arr[i]<<' ';cout<<'\n';}
#define debvi(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';
#define debvvi(v) for(int i = 0; i != v.size(); i++){cout<<#v<<'['<<i<<"] : ";for(int j = 0; j != v[i].size(); j++)cout<<v[i][j]<<' ';cout<<'\n';}


int main()
{
    int n, m, i, j, x, ans = 0;
    cin>>n>>m;
    vector<int>la[m + 1], mrk(m + 1);
    vvi lang(m + 1,vi(m + 1));
    for(i = 0; i != n; i++){
        scanf("%d",&x);
        if(!x)ans++;
        vi v(x);
        for(j = 0; j != x; j++){
            scanf("%d",&v[j]);
            for(int k = 0; k != j; k++){
                lang[v[j]][v[k]] = 1;
                lang[v[k]][v[j]] = 1;
            }
            lang[v[j]][v[j]] = 1;
        }
    }
    for(i = 1; i <= m; i++){
        for(j = 1; j <= m; j++){
            if(lang[i][j])la[i].push_back(j);
        }
    }
    //debvvi(lang);
    x = 0;
    for(i = 1; i <= m; i++){
        if(!mrk[i] && !la[i].empty()){
            x++;
            stack<int>st;
            st.push(i);
            mrk[i] = x;
            while(!st.empty()){
                int x = st.top();
                int z = la[x].size();
                st.pop();
                for(j = 0; j != z; j++){
                    int y = la[x][j];
                    if(mrk[y])continue;
                    //cout<<y<<' ';
                    mrk[y] = x;
                    st.push(y);
                }
            }
            //cout<<'\n';
        }
    }
    cout<<max(0,x - 1) + ans;
}