/**
 * https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2961/
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")return 0;
        int i, mx = 0, st = 0, n = s.length();
        map<char,int>m;
        for(i = 0; i < n; i++){
            if(m[s[i]] == 0){
                mx = max(mx, i - st + 1);
            }
            else{
                st = max(st,m[s[i]]);
                mx = max(mx, i - st + 1);
            }
            m[s[i]] = i + 1;
        }
        return mx;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution sol = Solution();
    cout<<sol.lengthOfLongestSubstring(s)<<'\n';
}