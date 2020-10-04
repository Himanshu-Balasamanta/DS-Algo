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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)return nullptr;
        int l = 0, i = 0;
        ListNode* point = head;
        while(point != nullptr){
            l++;
            point = point->next;
        }
        if(n == l)return head->next;
        point = head;
        while(i + n < l - 1){
            i++;
            point = point->next;
        }
        point->next = (point->next)->next;
        //
        return head;
    }
};