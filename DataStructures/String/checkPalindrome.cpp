#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length(), i = 0, j = n - 1;
    while(i < j){
        if(s[i] != s[j]){
            cout<<"Not Palindrome\n";
            return 0;
        }
        i++;
        j--;
    }
    cout<<"Is a Palindrome\n";
}