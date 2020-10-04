#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, u, m, i, j, p;
    vector<int>a = {18,17},b;
    n = a.size();
    b.push_back(a[0]);
    for(i = 1; i < n; i++){
        l = 0, u = i - 1;
        while(l <= u){
            m = (l + u)/2;
            if(b[m] > a[i])u = m - 1;
            else l = m + 1;
        }
        if(l >= i)b.push_back(a[i]);
        else b.insert(b.begin() + l,a[i]);
    }
    for(int h : b)cout<<h<<' ';
}