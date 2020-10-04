/**
 * this can be used to find first 1.
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, tar;
    cin>>n>>tar;
    int a[n];
    for(i = 0; i != n; i++)cin>>a[i];
    int l = -1, h = n, m;
    while(l < h){
        m = (l + h)/2;
        //above the required
        if(a[m] > tar)h = m - 1;
        //below the required
        else if(a[m] < tar)l = m + 1;
        else{
            cout<<m<<'\n';
            return 0;
        }
    }
    cout<<l<<'\n';
}