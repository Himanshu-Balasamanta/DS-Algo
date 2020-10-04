/**
 * https://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, m, x, j, mn = INT_MAX;
    cin>>n>>m>>x;
    int a[n], b[m];
    for(i = 0; i != n; i++)cin>>a[i];
    for(j = 0; j != m; j++)cin>>b[j];
    i = 0; j = m - 1;
    for(i = 0; i != n; i++){
        while(a[i] + b[j] > x){
            mn = min(mn,a[i] + b[j] - x);
            j--;
            if(j < 0)break;
        }
        mn = min(mn,abs(x - a[i] - b[j]));
        if(j != m - 1)j++;
        if(j < 0)break;
    }
    cout<<mn<<'\n';
}