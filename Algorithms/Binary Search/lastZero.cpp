#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, h, l = 1, m,n, p = 0;
    vector<int> a = {1,0};
    h = a.size() - 1;
    if(h == 0)return 0;
    while(l <= h){
        while(a[l] <= a[p]) l++;
        while(a[h] > a[p]) h--;
        if(l <= h)
            swap(a[l],a[h]);
    }
    cout<<h<<'\n';
    swap(a[p],a[h]);
    for(int h : a)cout<<h<<' ';
    cout<<'\n';
}
