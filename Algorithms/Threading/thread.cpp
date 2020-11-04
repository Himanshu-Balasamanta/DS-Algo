#include<bits/stdc++.h>
#include<thread>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';
#define debarr(v) cout<<#v<<" : ";for(int i = 0;i != (int)v.size(); i++)cout<<i<<":"<<v[i]<<", ";cout<<'\n';

void threadfn(){
    cout<<"inside threadfn\n";
}

void solve()
{
    thread t1(threadfn);
    t1.join();
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}