/**
 * Let us say that you are given a number N,
 * you've to find the number of different ways to write it as the sum of 1, 3 and 4.
 * Consider different permutations to be different.
 */
#include<bits/stdc++.h>
using namespace std;

vector<long long>a;

long long someWays(int n){
    if(n == 1)return 1;
    if(n == 3)return 2;
    if(n == 4)return 4;
    if(a[n] != 0)return a[n];
    long long tot = 0;
    if(n > 4)tot += someWays(n - 4);
    if(n > 3)tot += someWays(n - 3);
    tot += someWays(n - 1);
    a[n] = tot;
    cout<<"ways in "<<n<<" th number is "<<tot<<'\n';
    return tot;
}

int main()
{
    int n;
    cin>>n;
    a = vector<long long>(n + 1);
    cout<<someWays(n);
}