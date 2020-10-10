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
    string s;
    vi a('D');
    int i;
    for(i = 0; i != 3; i++){
        cin>>s;
        if(s[1] == '<'){
            a[s[0]]--;
            a[s[2]]++;
        }
        else{
            a[s[0]]++;
            a[s[2]]--;
        }
    }
    s = "";
    map<int,char>mp;
    mp[a['A']] = 'A';mp[a['B']] = 'B';mp[a['C']] = 'C';
    if(mp.size() < 3){
        cout<<"Impossible";
        return 0;
    }
    for(auto p : mp){
        s+= p.second;
    }
    cout<<s;
}