#include<bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int>s{1,5,3,7,2,8,1,5};
    for(int ss : s)cout<<ss<<' ';
    cout<<'\n';
    s.erase(1);
    for(int ss : s)cout<<ss<<' ';
}