#include<bits/stdc++.h>
using namespace std;

bool allEmpty(vector<vector<int> >a){
    for(vector<int>b : a)if(!b.empty())return true;
    return false;
}

int main()
{
    int n, i, j, l = 1;
    cin>>n;
    vector<int>temp;
    vector<bool>mark(n + 1, false);
    vector<vector<int> >a, st(n + 2);
    for(i = 1; i <= n; i++)st[1].push_back(i);
    while(allEmpty(st)){
        while(!st[l].empty()){
            int x = st[l].back();
            st[l].pop_back();
            temp.push_back(x);
            mark[x] = true;
            for(i = 1; i <= n; i++)
                if(mark[i] == false)
                    st[l + 1].push_back(i);
            l++;
        }
        a.push_back(temp);
        //
        while(st[l].empty()){
            mark[temp.back()] = false;
            temp.pop_back();
            l--;
            if(l < 1)break;
        }
    }
    for(vector<int> b : a){
        for(int c : b){
            cout<<c<<' ';
        }
        cout<<'\n';
    }
}
