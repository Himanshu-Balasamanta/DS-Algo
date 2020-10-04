#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, m, l, h;
    cin>>n;
    vector<int>a(n);
    for(i = 0; i != n; i++){
        cin>>a[i];
    }
    h = n - 1, l = 0;
    if(a[h] != 1){
        cout<<"One doesnt exist\n";return 0;
    }
    if(a[l] == 1){
        cout<<0;return 0;
    }
    while(l + 1 < h){
        m = (l + h)/2;
        if(a[m] == 0)l = m;
        else if(a[m] == 1)h = m;
    }
    cout<<h<<'\n';
}