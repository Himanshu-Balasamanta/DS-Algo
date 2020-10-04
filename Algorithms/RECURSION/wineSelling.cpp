/**
 * "Imagine you have a collection of N wines placed next to each other on a shelf. 
 * For simplicity, let's number the wines from left to right as they are standing on the shelf with integers from 1 to N, respectively.
 * The price of the ith wine is pi. (prices of different wines can be different).
 *
 *Because the wines get better every year, supposing today is the year 1, on year y
 *the price of the ith wine will be y*pi, i.e. y-times the value that current year.
 *
 *You want to sell all the wines you have, but you want to sell exactly one wine per year, starting on this year.
 *One more constraint - on each year you are allowed to sell
 *only either the leftmost or the rightmost wine on the shelf and you are not allowed
 *to reorder the wines on the shelf (i.e. they must stay in the same order as they are in the beginning).
 */
#include<bits/stdc++.h>
using namespace std;

vector<int>a;

int maxInSubset(int year, int start, int end){
    if(start == end)return 0;
    int lMax = year*a[start]+maxInSubset(year + 1, start + 1, end);
    int rMax = year*a[end - 1]+maxInSubset(year + 1, start, end - 1);
    return max(lMax,rMax);
}

int main()
{
    int n, i;
    cin>>n;
    a = vector<int>(n);
    for(i = 0; i != n; i++)
        cin>>a[i];
    cout<<maxInSubset(1,0,n);
}