#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>w,val;

vector<vector<int>>a;

int rec(int ii, int weight){
    if(ii == -1 || weight == 0)return 0;
    if(a[ii][weight] != -1)return a[ii][weight];
    if(weight < w[ii]){
        a[ii][weight] = rec(ii - 1, weight);
        return a[ii][weight];
    }
    a[ii][weight] = max(val[ii] + rec(ii - 1,weight - w[ii]), rec(ii - 1, weight));
    return a[ii][weight];
}

int main()
{
    int i, m, j, weight;
    cin>>n;
    w = val = vector<int>(n);
    for(i = 0; i != n; i++){
        cin>>w[i];
    }
    for(i = 0; i != n; i++){
        cin>>val[i];
    }
    cin>>weight;
    a = vector<vector<int>>(n,vector<int>(weight + 1, -1));
    cout<<rec(n - 1,weight);
}