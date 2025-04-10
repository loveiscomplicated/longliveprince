// library_code.cc

#include <iostream>
#include <vector>


// Question 7: Linked List Implementation
class MyLinkedList {
public:
    MyLinkedList() {}
    
    int get(int index) {
        // TODO: Implement
        return 0;
    }
    
    void addAtHead(int val) {
        // TODO: Implement
    }
    
    void addAtTail(int val) {
        // TODO: Implement
    }
    
    void addAtIndex(int index, int val) {
        // TODO: Implement
    }
    
    void deleteAtIndex(int index) {
        // TODO: Implement
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



// Question 8: kth character after operations
char kthCharacter(long long k, std::vector<int>& operations) {
    // TODO: Implement
    return 'a';
}

// Question 9: Median of two sorted arrays
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    // TODO: Implement
    return 0.0;
}

// Question 10: Reverse linked list k nodes
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    
ListNode* reverseKGroup(ListNode* head, int k) {
    // TODO: Implement  
    return head;
}


