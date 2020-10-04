/**
 * correct at first go..
 */

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
    ListNode* reverseList(ListNode* head) {
        ListNode *root = head, *point = head->next;
        if(head->next == nullptr)return head;
        head->next = nullptr;
        while(point != nullptr){
            root = point->next;
            point->next = head;
            head = point;
            point = root;
        }
        return head;
    }
};

