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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* l3 = new ListNode(), *ans;
        ans = l3;
        while(l2 && l1){
            l3->val = (l1->val + l2->val + c) % 10;
            c = (l1->val + l2->val + c)/10;
            l1 = l1->next;
            l2 = l2->next;
            if(l1 || l2 || c){
                l3->next = new ListNode();
                l3 = l3->next;
            }
        }
        if(l1 == nullptr)
            l1 = l2;
        while(l1){
            l3->val = (l1->val + c)%10;
            c = (l1->val + c)/10;
            l1 = l1->next;
            if(l1 || c){
                l3->next = new ListNode(-1);
                l3 = l3->next;
            }
        }
        if(c){
            l3->val = c;
        }
        else{
            //erase the leading zero.
        }
        return ans;
    }
};
