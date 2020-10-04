/**
 * input is a sorted array, output a sorted array containing the squares of input numbers. 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int k = a.size() - 1, i = 0, j = a.size() - 1, n = a.size();
        vector<int>sq(n);
        while(i <= j){
            if(a[i]*a[i] < a[j] * a[j]){
                sq[k] = a[j]*a[j];
                j--;
            }
            else{
                sq[k] = a[i]*a[i];
                i++;
            }
            k--;
        }
        return sq;
    }
};

int main()
{
    Solution s = Solution();
    int n, i;
    cin>>n;
    vector<int>a(n),b;
    for(i = 0; i != n; i++)cin>>a[i];
    b = s.sortedSquares(a);
    for(i = 0; i != n; i++)
        cout<<b[i]<<' ';
    cout<<'\n';
}