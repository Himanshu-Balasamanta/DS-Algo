#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& list) {
        int n = lists.size(), ind = -1;
        ListNode* root = list[0], *point, *temp = nullptr;
        for(int i = 1; i != n; i++){
            if(list[i]->val < root->val)
                root = list[i], ind = i;
        }
        point = root;
        list[ind] = list[ind]->next;
        while(point){
            temp = point;
            point = nullptr;
            ind = -1;
            for(int i = 0; i != n; i++){
                if(list[i] == nullptr)continue;
                if(point == nullptr || list[i]->val < point->val){
                    ind = i;
                    point = list[i];
                }
            }
            if(ind == -1)break;
            list[ind] = list[ind]->next;

        }
    }
};