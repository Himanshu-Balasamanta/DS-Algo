#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n, k, q, i, x, y;
    multiset<int>s, diff;
    cin>>n>>q;
    for(i = 0; i != n; i++){
        cin>>x;
        s.insert(x);
    }
    auto it = s.begin(), itr = s.begin();
    itr++;
    while(itr != s.end()){
        int z = *itr - *it;
        diff.insert(z);
        itr++;it++;
    }
    cout<<(*s.rbegin() - *s.begin() - *diff.rbegin())<<'\n';
    for(i = 0; i != q; i++){
        cin>>y>>x;
        if(y){
            auto it = s.lower_bound(x);
            auto itr = it;
            if(it != s.begin()){
                itr--;
                diff.erase(*it - *itr);
                diff.insert(x - *itr);
                diff.insert(*it - x);
            }
            else{
                diff.insert(*it - x);
            }
            s.insert(x);
        }
        else{
            if(s.find(x)== s.end() || s.empty())continue;
            auto it = s.lower_bound(x);
            s.erase(it);
            auto itr = s.lower_bound(x);
            it = itr;
            if(s.empty())continue;
            if(it == s.end()){
                diff.erase(x - *s.rbegin());
            }
            else if(it != s.begin()){
                itr--;
                diff.insert(*it - *itr);
                diff.erase(diff.find(x - *itr));
                diff.erase(diff.find(*it - x));
            }
            else{
                diff.erase(diff.find(*it - x));
            }
        }
        if(s.empty())cout<<"0\n";
        else{
            cout<<(*s.rbegin() - *s.begin() - *diff.rbegin())<<'\n';
        }
    }
}