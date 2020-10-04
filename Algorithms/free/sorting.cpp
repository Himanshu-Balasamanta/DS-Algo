#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n, q, k = 0, i, mx = 0, l, r;
        cin>>n>>q;
        long long a[n];
        for(i = 0; i != n; i++){
            cin>>a[i];
            if(i && a[i] < a[i - 1]){
                mx += a[i - 1] - a[i];
                k = i;
            }
        }
        mx += a[n - 1];
        cout<<mx<<'\n';
        for(i = 0; i != q; i++){
            cin>>l>>r;
            if(l && a[l] < a[l - 1])mx -= a[l - 1] - a[l];
            if(r && a[r] < a[r - 1])mx -= a[r - 1] - a[r];
            if(l != n - 1 && a[l] > a[l + 1])mx -= a[l] - a[l + 1];
            if(r != n - 1 && a[r] > a[r + 1])mx -= a[r] - a[r + 1];
            if(r == n - 1)mx -= a[r];
            swap(a[l],a[r]);
            if(l && a[l] < a[l - 1])mx += a[l - 1] - a[l];
            if(r && a[r] < a[r - 1])mx += a[r - 1] - a[r];
            if(l != n - 1 && a[l] > a[l + 1])mx += a[l] - a[l + 1];
            if(r != n - 1 && a[r] > a[r + 1])mx += a[r] - a[r + 1];
            if(r == n - 1)mx += a[r];
            cout<<mx<<'\n';
        }
    }
}