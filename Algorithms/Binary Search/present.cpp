/**
 * The program checks if the target number is present or not within the array of numbers
 * Even if the number is at the start or at the end, it returns the correct answer.
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    int tar, n, i;
    cin>>n>>tar;
    int a[n];
    for(i = 0; i != n; i++)cin>>a[i];
    int h = n - 1, l = 0, m;
    while(h >= l){
        m = (h + l)/2;
        if(a[m] > tar)h = m - 1;
        else if(a[m] < tar)l = m + 1;
        else {
            cout<<m<<'\n';
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}