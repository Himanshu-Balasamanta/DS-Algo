#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define deb(x) cout<<#x<<' '<<x<<' ';

int main()
{
    int n, i, x, sum;
    cin>>n;
    int a[n + 2], b[n + 2], c[n + 2];
    b[0] = b[n + 1] = INT_MAX;
    a[0] = a[n + 1] = c[0] = c[n + 1] = 0;
    for(i = 1; i <= n; i++){
        scanf("%d",b + i);
        if(b[i] >= b[i - 1]){
            a[i] = a[i - 1] + 1;
        }
        else{
            a[i] = 1;
        }
    }
    for(i = n; i >= 1; i--){
        if(b[i] >= b[i + 1])c[i] = c[i + 1] + 1;
        else c[i] = 1;
        //deb(c[i]);
    }
    for(i = 1; i <= n; i++)c[i] += a[i] - 1;
    cout<<*max_element(c + 1,c + n + 1);
}