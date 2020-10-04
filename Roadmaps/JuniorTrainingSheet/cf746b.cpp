/**
 * https://codeforces.com/contest/746/problem/B
 */
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>

int main()
{
    int l, i = 1, n, j;
    string s, t;
    cin>>n>>s;
    t = string(n,'#');
    l = n%2;
    int st = (n - 1)/2;
    for(j = 0; j != n; j++){
        char c = s[j];
        t[st] = c;
        if(l%2)st -= j + 1;
        else st += j + 1;
        l++;
    }
    cout<<t;
}