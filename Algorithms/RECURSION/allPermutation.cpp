#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>rec;
vector<bool>mark;
vector<vector<int> >a;

void subPerm(int m)
{
    int i, f = 0;
    //vector<int>e = rec;
    //vector<vector<int> >k = a;
    for(i = 1; i <= n; i++){
        if(mark[m] == false){
            mark[m] = true;
            rec[m] = i;
            subPerm(m + 1);
            mark[m] = false;
            f++;
        }
    }
    if(f == 0){
        a.push_back(rec);
    }
}

int main()
{
    cin>>n;
    rec = vector<int>(n + 1);
    mark = vector<bool>(n + 1, false);
    subPerm(1);
    for(vector<int>b : a){
        for(int c : b){
            cout<<c<<' ';
        }
        cout<<'\n';
    }
}
