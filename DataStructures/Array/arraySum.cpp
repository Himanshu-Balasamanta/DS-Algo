/**
 * add a number given in form of an array to a number and return the answer in form of an array.
 * This is not the most efficient solution. Here, I didn't take advantage of the fact that one of
 * the numbers comes within the int range.
 * 
 * Better would be to 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        vector<int>K;
        int z, y, i;
        if(k == 0)K = vector<int>(1,0);
        else{
            K = vector<int>((int)log10(k) + 1);
            z = K.size(), y = k, i;
            for(i = 0; i != z; i++){
                K[i] = y%10;
                y /= 10;
            }
        }
        if(y)cout<<"y is not zero !!\n";
        int as = a.size(), ks = K.size();
        z = max(K.size(),a.size()) + 1, y = min(K.size(),a.size());
        vector<int>ans(z);
        //cout<<"z "<<z<<'\n';
        reverse(a.begin(),a.end());
        reverse(K.begin(),K.end());
        int rem = 0;
        for(i = 0; i != y; i++){
            int x = a[i] + K[i] + rem;
            rem = x/10;
            //cout<<i<<' '<<rem<<'\n';
            ans[i] = x%10;
        }
        for(;i != z - 1; i++){
            int x = ((i >= as) ? K[i] : a[i]) + rem;
            rem = x/10;
            //cout<<i<<' '<<rem<<'\n';
            ans[i] = x%10;
        }
        ans[i] = rem;
        reverse(ans.begin(),ans.end());
        cout<<ans[0]<<'\n';
        if(ans[0] == 0)ans.erase(ans.begin());
        return ans;
    }
};

int main()
{
    int i, n, k;
    cin>>n;
    vector<int>a(n);
    for(i = 0; i != n; i++){
        cin>>a[i];
    }
    cin>>k;
    Solution s = Solution();
    a = s.addToArrayForm(a,k);
    for(int w : a){
        cout<<w<<' ';
    }
}