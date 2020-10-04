#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<string>a;
    vector<string>d;
    string str;

    void rec(int st, string s){
        if(st == n){
            a.push_back(s);
            return ;
        }
        for(char c : d[str[st] - '0']){
            rec(st + 1, s + c);
        }
    }

    vector<string> letterCombinations(string s) {
        n = s.length();
        d = vector<string>(10);
        str = s;
        if(n == 0)return a;
        d[0] ="", d[1] = "",d[2] = "abc",d[3] = "def", d[4] = "ghi", d[5] = "jkl", d[6] = "mno", d[7] = "pqrs", d[8] = "tuv", d[9] = "wxyz";
        rec(0,"");
        return a;
    }
};

int main(){
    string s = "23";
    Solution sol = Solution();
    vector<string>b = sol.letterCombinations(s);
    for(string c : b){
        cout<<c<<'\n';
    }
}