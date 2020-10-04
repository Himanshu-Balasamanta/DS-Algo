#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;

    Node(){
        this->val = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

class MyLinkedList {
    Node* rootNode;
    Node* tailNode;
    Node* point;
    int n;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        n = 0;
        rootNode = tailNode = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        point = rootNode;
        while(index--){
            //checks if or not the nodes [rootNode,nodeRequired) are nullptrs, and returns -1, prevents nullptr exception
            if(point == nullptr)return -1;
            point = point->next;
        }
        //the node to be got is not checked in the loop.
        if(point == nullptr)return -1;
        return point->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    //2 cases. If rootNode is not there, make a rootNode and a tail node. else, put it behind the rootNode.
    void addAtHead(int val) {
        //when rootNode is not there, (n == 0)
        if(rootNode == nullptr){
            rootNode = tailNode = new Node(val);
        }
        else{
            Node* nde = new Node(val);
            rootNode->prev = nde;
            nde->next = rootNode;
            rootNode = nde;
        }
        //either case, n++, as the function call is always valid
        n++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        //rootNode == tailNode if tailNode is nullPtr
        if(rootNode == nullptr){
            rootNode = tailNode = new Node(val);
        }
        else{
            Node* nde = new Node(val);
            tailNode->next = nde;
            nde->prev = tailNode;
            tailNode = nde;
        }
        n++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    //4 cases. 1 rootNode to be modified, 2 to be appended at the end, 3 if beyond the size of array, return null, 4 normal case.
    void addAtIndex(int index, int val) {
        //there are cases here.. when tailNode == rootNode, or both are null... addAtHead function covers them.
        if(index == 0)addAtHead(val);
        //same as index == 0
        else if(index == n)addAtTail(val);
        //nowhere to add
        else if(index > n)return;
        //normal procedure.
        else{
            point = rootNode;
            while(index--){
                point = point->next;
            }
            Node* nde = new Node(val);
            nde->next = point;
            nde->prev = point->prev;
            (point->prev)->next = nde;
            point->prev = nde;
            n++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        //as there is no delete head function, all cases are typed out here.
        if(index == 0){
            if(rootNode == nullptr){
                return;
            }
            //here, rootNode needs to be updated to tailNode after deletion. decrease the size by 1.
            else if(n == 1){
                rootNode = tailNode = nullptr;
                n--;
                return;
            }
            //if none of the two cases, shift rootNode ahead by 1, and decrease the size by 1.
            rootNode = rootNode->next;
            rootNode->prev == nullptr;
            n--;
            return;
        }
        //here the tailNode needs to be brought behind, and n decreased by 1.
        else if(index == n - 1){
            (tailNode->prev)->next == nullptr;
            tailNode = tailNode->prev;
        }
        //nothing to delete.
        else if(index >= n)return;
        point = rootNode;
        while(index--){
            point = point->next;
        }
        Node* nde = point->next;
        point = point->prev;
        if(nde == nullptr)point->next = nullptr;
        else{
            nde->prev = point;
            point->next = nde;
        }
        n--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    MyLinkedList list = MyLinkedList();
    list.addAtHead(2);
    list.addAtTail(3);
    list.deleteAtIndex(1);
    list.addAtTail(8);
    list.addAtIndex(1,-6);
}
