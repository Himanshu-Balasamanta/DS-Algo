/**
 * Implementing a factorial through recursion and dp.
 */
#include<bits/stdc++.h>
using namespace std;

vector<long long>a;

long long fact(int n){
    if(n == 0)return 1;
    if(a[n] != 0)return a[n];
    a[n] = n * fact(n - 1);
    return a[n];
}

int main()
{
    int n;
    cin>>n;
    a = vector<long long>(n + 1);
    cout<<fact(n);
}