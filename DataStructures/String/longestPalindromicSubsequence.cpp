/**
 * https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/180/
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    int n, i, j, mx = 0, strt = -1, end = -1;
    vector<vector<bool> >a;

    void checkPalindromic(int st, int en){
        if(st < 0 || en >= n)return;
        if(s[st] == s[en]){
            a[st][en] = true;
            if(en - st + 1 > mx){
                mx = en - st + 1;
                strt = st, end = en;
            }
            checkPalindromic(st - 1, en + 1);
        }
    }

    string longestPalindrome(string s) {
        if(s.empty())return "";
        this->s = s;
        n = s.length();
        a = vector<vector<bool> >(n, vector<bool>(n));
        for(i = 0; i != n; i++)
            a[i][i] = true;

        for(i = 0; i != n; i++){
            checkPalindromic(i,i);
            if(i)checkPalindromic(i, i - 1);
        }
        if(mx > 0){
            return s.substr(strt,mx);
        }
        return "";
    }
};

int main()
{
    string s;
    cin>>s;
    Solution sol = Solution();
    cout<<sol.longestPalindrome(s);
}