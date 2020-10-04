#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i = 1, tp = 0, thp = 0, fp = 0, num;
    vector<int>a(n + 1,1);
    cin>>n;
    for(i = 1; i <= n; i++){
        if(a[tp] * 2 <= a[thp] * 3 && a[tp] * 2 <= a[fp] * 5){
            //a.push_back(a[tp]*2);
            a[i] = a[tp] * 2;
            tp++;
        }
        else if(a[thp] * 3 <= a[tp] * 2 && a[thp] * 3 <= a[fp] * 5){
            //a.push_back(a[thp] * 3);
            a[i] = a[thp] * 3;
            thp++;
        }
        else if(a[fp] * 5 <= a[thp] * 3 && a[tp] * 2 >= a[fp] * 5){
            //a.push_back(a[fp]*5);
            a[i] = a[fp] * 5;
            fp++;
        }
        while(a[tp]*2 <= a[i])tp++;
        while(a[thp]*3 <= a[i])thp++;
        while(a[fp]*5 <= a[i])fp++;
    }
    cout<<a.back();
}
