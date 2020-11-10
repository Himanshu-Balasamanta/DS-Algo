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
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int ieieou = 0;ieieou != (int)v.size(); ieieou++)cout<<ieieou<<":"<<v[ieieou]<<", ";cout<<'\n';

vi primes;
V<bool>p;
void findPrimes(){
    p = V<bool>(4501,true);
    int i, j;
    for(i = 2; i * i <= 4500; i++){
        if(p[i]){
            primes.push_back(i);
            for(j = i * i; j <= 4500; j += i){
                p[j] = false;
            }
        }
    }
    for(; i <= 4500; i++)
        if(p[i])primes.push_back(i);
}
int f = 0, s = 1;
int findNext(){
    int ret = primes[f] * primes[s];
    f++;
    if(s == f){
        f = 0;
        s++;
    }
    return ret;
}

void solve()
{
    int n, i, j;
    cin>>n;
    vi a(n + 1, 1), b(n + 1);
    for(i = 1; i <= n; i++){
        cin>>b[i];
        if(a[b[i]] > 1){
            a[i] = a[b[i]];
        }
        else if(a[i] == 1){
            int mul = findNext();
            a[i] = mul;
            a[b[i]] = mul;
        }
        else {
            cout<<"OMG!\n";
        }
    }
    for(i = 1; i <= n; i++)cout<<a[i]<<' ';
    cout<<'\n';
    f = 0, s = 1;
}

int main()
{
    io;
    fix(10);
    findPrimes();
    int sz = primes.size();
    int o = sz - 1, tw = sz - 2;
    //cout<<sz;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}