#include<bits/stdc++.h>
using namespace std;

struct Node{
    char c;
    vector<Node*>dep;
    Node(int x) : c(x){};
};

class Solution {
public:

    string ans = "";
    vector<Node*> node;
    vector<bool> marked, present;
    Solution(){
        marked = present = vector<bool>(26,false);
        node = vector<Node*>(26,nullptr);
    }

    bool rec(int ind){
        if(marked[ind])return true;
        if(present[ind])return false;
        present[ind] = true;
        for(Node* nde : node[ind]->dep){
            if(rec(nde->c) == false)return false;
        }
        marked[ind] = true;
        present[ind] = false;
        ans += 'a' + ind;
        return true;
    }

    string alienOrder(vector<string>& words) {
        //
        //for(int i = 0; i != 26; i++)node.push_back(nullptr);
        //read and convert into a graph
        int wsz = words.size();
        vector<int>sz(wsz);
        for(int i = 0; i != wsz; i++)
            sz[i] = words[i].size();
        ////make a node of all present.
        for(int i = 0; i != wsz; i++)
            for(int j = 0; j != sz[i]; j++)
                node[words[i][j] - 'a'] = new Node(words[i][j] - 'a');
        //
        for(int i = 0; i < wsz - 1; i++){
            string s = words[i], t = words[i + 1];
            int j = 0;
            while(j < min(sz[i],sz[i + 1]) && s[j] == t[j])
                j++;
            if(j == min(sz[i],sz[i + 1])){
                if(sz[i] > sz[i + 1])return "";
                continue;
            }
            node[t[j] - 'a']->dep.push_back(node[s[j] - 'a']);
        }
        //convert graph into string
        for(int i = 0; i != 26; i++){
            if(node[i] == nullptr)continue;
            if(marked[i])continue;
            if(rec(i)== false)return "";
        }
        return ans;
    }
};


int main()
{
    vector<string>s = {"x","y","x"};
    Solution sol = Solution();
    cout<<sol.alienOrder(s)<<'\n';
}