#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)return false;
        bool res = false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast){
            slow = slow->next;
            if(fast->next == nullptr)return false;
            if(fast->next == slow)return true;
            if((fast->next)->next == nullptr)return false;
            if((fast->next)->next == slow)return true;
        }
        return true;
    }
};

int main()
{

}