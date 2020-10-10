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
    cin>>s;
    vector<int>num;
    int n = s.length(), i, sum = 0, ans = 0;
    while(s.length() > 1){
        sum = 0;
        for(i = 0; i != s.length(); i++){
            sum += s[i] - '0';
        }
        num.push_back(sum);
        s = to_string(sum);
    }
    cout<<num.size();
}