#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        vector<int>mxFromHere(200005);
        vector<int>rightEdge[200005];
        int i, j, l, r, mx = 0, n, l, r;
        cin>>n;
        for(i = 0; i != n; i++){
            cin>>l>>r;
            rightEdge[l].push_back(r);
        }
        for(i = 200003; i != -1; i--){
            if(rightEdge[i].empty())continue;
            //else
            ////for every r boundary starting from here,
            //////calc the max number of them 
        }
    }
}