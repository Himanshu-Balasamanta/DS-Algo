#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q,i,h,l,m,x;
    cin>>n;vector<int>a(n);
    for(i=0;i!=n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    cin>>q;
    while(q--){
        cin>>x;
        h=n;l=0;
        while(h>l){
            m=(h+l)/2;
            if(a[m]>x){h=m;}
            else if(a[m]<x){l=m+1;}
            else{cout<<m+1<<'\n';break;}
        }
    }
}