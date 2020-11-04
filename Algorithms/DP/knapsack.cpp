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
    int n, l, i, x, sum;
    cin>>n;
    string s;
    vector<string>vs(n);
    for(i = 0; i != n; i++){
        cin>>vs[i];
    }
    vi chars(256);
    for(i = 0; i != 26; i++)chars[i + 'a'] = i;
    cin>>l;
    map<int,int>mp;
    mp[0] = 0;
    for(i = 0; i != n; i++){
        sum = 0;
        for(char c : vs[i])sum += chars[c];
        x = vs[i].length();
        for(auto p : mp){
            if(x + p.first <= l)
                mp[x + p.first] = max(mp[x + p.first], sum + mp[p.first]);
            else 
                break;
        }
    }
    cout<<mp[l]<<'\n';
    for(i = 'a'; i <= 'z'; i++)cout<<(char)i<<':'<<i - 'a'<<' ';
}