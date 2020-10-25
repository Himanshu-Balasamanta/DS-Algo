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
    int t;
    cin>>t;
    while(t--){
        int a, b, ans = 0, i = 0;
        cin>>a>>b;
        while(a > 0 || b > 0){
            int x = a % 2, y = b % 2;
            if(x != y)ans |= 1<<i;
            i++;
            a/= 2; b /= 2;
        }
        cout<<ans<<'\n';
    }
}