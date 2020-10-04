#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    vector<Node*> dep;
    Node(int v) : val(v) {}
};

class Solution
{
public:

    vector<bool> visited;
    vector<bool>current;
    map<int, Node *> course;

    bool strt(Node* nde){

        if(visited[nde->val])return true;
        if(current[nde->val])return false;
        current[nde->val] = true;
        for(auto nd : nde->dep){
            if(visited[nd->val] == false){
                if(strt(nd) == false)return false;
            }
        }
        visited[nde->val] = true;
        current[nde->val] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prereq)
    {
        visited = current = vector<bool>(numCourses,false);
        int i, noDep = prereq.size();
        for (i = 0; i != numCourses; i++)
        {
            course.insert(make_pair(i, new Node(i)));
        }
        for (i = 0; i != noDep; i++)
        {
            Node* ye, *baap;
            ye = course[prereq[i][0]];
            baap = course[prereq[i][1]];
            ye->dep.push_back(baap);
            //baap->child.push_back(ye);
        }
        for(auto nde : course){
            if(visited[nde.first] == false){
                if(strt(nde.second) == false)return false;
            }
        }
        return true;
    }
};

int main()
