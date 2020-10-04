#include<bits/stdc++.h>
using namespace std;

int main(){
    int src, des, n, i, j;
    cin>>n;
    vector<int>strt(n + 1),end(n + 1), price(n + 1),a[n + 1],stack;
    for(i = 1; i <= n; i++){
        cin>>strt[i]>>end[i]>>price[i];
        a[strt[i]].push_back(end[i]);
    }
    cin>>src>>des;
    stack.push_back(src);
    
}