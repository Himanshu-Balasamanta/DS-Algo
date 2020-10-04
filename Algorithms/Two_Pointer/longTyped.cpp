/**
 * Check if typed can be typed by typing letters of name more than once. 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0, nl = name.length(),tl = typed.length(), cn, tn;
        for(i = 0; i < nl; i++){
            char n = name[i], t = typed[j];
            cn = tn = 0;
            while(name[i] == n && i < nl - 1){
                i++,cn++;
            }
            while(typed[j] == t && j < tl - 1){
                j++,tn++;
            }
            if()
        }
    }
};

int main()
{
    string name, typed;
    cin>>name>>typed;
    Solution s = Solution();
    cout<<s.isLongPressedName(name,typed);
}