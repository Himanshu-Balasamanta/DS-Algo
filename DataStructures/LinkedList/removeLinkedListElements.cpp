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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val)head = head->next;
        ListNode* point = head;
        if(head == nullptr)return head;
        ListNode* root = head->next;
        while(root){
            if(root->val == val){
                head->next = root->next;
                root = root->next;
            }
            else{
                head = head->next;
                root = root->next;
            }
        }
        return point;
    }
};