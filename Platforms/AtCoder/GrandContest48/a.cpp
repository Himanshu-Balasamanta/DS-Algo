#include<bits/stdc++.h>
using namespace std;

#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fix(n) cout << fixed << setprecision(n)

#define ll long long
#define all(v) v.begin(),v.end()
#define V vector
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<'\n';
#define debarr(v) cout<<#v<<" : ";for(int ieieou = 0;ieieou != (int)v.size(); ieieou++)cout<<ieieou<<":"<<v[ieieou]<<", ";cout<<'\n';
#define printArr(v){for(auto x : v){cout<<x<<' ';};cout<<'\n';}

void solve()
{
    string s, p, t = "atcoder";
    cin>>s;
    p = s;
    sort(s.rbegin(),s.rend());
    if(lexicographical_compare(s.begin(),s.end(),t.begin(),t.end())){
        cout<<"-1\n";
        return;
    }
    else if(p == t){
        cout<<"-1\n";
        return ;
    }
    else if(lexicographical_compare(t.begin(),t.end(),s.begin(),s.end())){
        cout<<"0\n";
        return;
    }
    s = p;
    vvi a()
}

int main()
{
    io;
    fix(10);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}