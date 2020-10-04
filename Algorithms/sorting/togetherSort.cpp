/**
 * b is sorted in accordance with a.
 */
#include<bits/stdc++.h>
using namespace std;

vector<int>a = {2,1}, b = {8,3};

void rec(int st, int en){
    if(st >= en)return;
    int p = st, i = st + 1, j = en;
    while(i < j){
        while(a[j] > a[p])j--;
        while(i <= j && a[i] <= a[p])i++;
        if(i <= j){
            swap(a[i],a[j]);
            swap(b[i],b[j]);
        }
    }
    swap(a[j],a[p]);
    swap(b[j],b[p]);
    rec(st,j - 1);
    rec(j + 1, en);
}

int main()
{
    int n, i, j, l, m, h, p;
    n = a.size();
    rec(0, n - 1);
    for(int p : b)cout<<p<<' ';
}