#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

void solve()
{
    ll p, q, x = 1, pp, qq;
    cin>>p>>q;
    if(p % q){
        cout<<p<<'\n';
        return;
    }
    pp = p / q;
    vll prime, quit;
    for(ll i = 2; i * i <= q; i++){
        if(q % i == 0){
            prime.push_back(0);
            quit.push_back(i);
            while(pp % i == 0){
                prime[prime.size() - 1]++;
                pp /= i;
            }
            while(q % i == 0)q /= i;
        }
    }
    if(q != 1){
        prime.push_back(0);
        quit.push_back(q);
        while(pp % q == 0){
            prime[prime.size() - 1]++;
            pp /= q;
        }
        q = 1;
    }
    ll mn = 
}

int main()
{
    int t;
    cin>>t;
    while(t--)solve();
}