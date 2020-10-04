/**
 * can't believe it got accepted.
 * https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1214/
 */
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool>s;
        while(head != nullptr){
            if(s.find(head) == s.end())s.insert({head,true});
            else{
                return head;
            }
            head = head->next;
        }
        return nullptr;
    }
};

int main()
{
    Solution s = Solution();
    ListNode a = ListNode(1);
    ListNode b = ListNode(2);
    ListNode c = ListNode(3);
    b.next = &c;a.next = &b;c.next = &a;
    ListNode* d = s.detectCycle(&a);
    cout<<d->val<<'\n';
}
