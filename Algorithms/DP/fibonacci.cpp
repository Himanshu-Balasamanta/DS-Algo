/**
 * Fibonacci through recursion and dp.
 * Here DP isn't necessary.
 */
#include<bits/stdc++.h>
using namespace std;
vector<long long>a;
long long fib(int n){
    if(n == 0)return 0;
    if(n==1)return 1;
    if(a[n] != 0)return a[n];
    a[n] = fib(n - 1)+ fib(n - 2);
    cout<<n<<" has fib of "<<a[n]<<'\n';
    return a[n];
}

int main()
{
    int n;
    cin>>n;
    a = vector<long long>(n + 1, 0);
    cout<<fib(n);
}