#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

vector<vll> two;
vvi level[32];

pair<int,ll> segregate(vector<int>a, int x){
    int n = a.size(), i, j, num = 0;
    vi one,zero;
    ll lesso = 0, lessz = 0;
    for(i = 0; i != n; i++){
        if(a[i] & 1<<x){
            one.push_back(a[i]);
            lessz += zero.size();
        }
        else{
            zero.push_back(a[i]);
            lesso += one.size();
        }
    }
    if(lesso == 0 || lessz == 0){
        num = 0;
    }
    else if(lesso > lessz){
        num |= 1<<x;
    }
    two[x][1] += lesso;
    two[x][0] += lessz;
    if(x){
        level[x - 1].push_back(one);
        level[x - 1].push_back(zero);
    }
    return make_pair(num,min(lesso,lessz));
}

int main()
{
    int n, i, j;
    ll ans = 0, lesso = 0, lessz = 0, x = 0;
    cin>>n;
    two = vector<vll>(32,vll(2,0));
    vi a(n);
    for(i = 0; i != n; i++){
        scanf("%d",&a[i]);
    }
    pair<int,ll>p;
    p = segregate(a,31);
    if(two[31][0] == 0 && two[31][1] == 0){

    }
    else if(two[31][0] < two[31][1]){
        ans += two[31][0];
        x |= 1<<31;
    }
    else{
        ans += two[31][1];
    }
    for(i = 30; i >= 0; i--){
        for(auto v : level[i]){
            if(!v.empty())
                segregate(v,i);
        }
        ans += min(two[i][0],two[i][1]);
        if(two[i][0] < two[i][1])
            x |= 1<<i;
    }
    cout<<ans<<' '<<x;
}