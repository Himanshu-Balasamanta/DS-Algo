/**
 * https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/200/
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int val;
        map<string,vector<string> >M;
        for(string s : strs){
            string t = "";
            vector<int>b(26);
            for(char c : s)b[c - 'a']++;
            for(int d : b)t += to_string(d) + ':';
            M[t].push_back(s);
        }
        vector<vector<string>>a;
        for(auto k : M){
            a.push_back(k.second);
        }
        return a;
    }
};

int main()
{
    int n, i;
    cin>>n;
    vector<string>a(n);
    for(i = 0; i != n; i++)
        cin>>a[i];
    Solution s = Solution();
    vector<vector<string> > b = s.groupAnagrams(a);
    for(vector<string>c : b){
        for(string d : c){
            cout<<d<<'\n';
        }
        cout<<'\n';
    }
}