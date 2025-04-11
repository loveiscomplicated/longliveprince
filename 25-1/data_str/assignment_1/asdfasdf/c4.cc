#include <iostream>
#include <vector>

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
    if (k == 1) return head;

    ListNode* pointer = head;
    int index = 0;

    std::vector<ListNode*> slidingWindow(k);    // sliding window 생성하기

    ListNode* start = nullptr; // 이전 sliding window에서의 처음, 마지막 elem 기억하기
    ListNode* end = nullptr;


    while (true) { // iterator가 순회하다 끝에 도달하면 종료
        int count = 0;

        for (int i = 0; i < k; i++) { //슬라이딩 윈도우 초기화하기
            slidingWindow[i] = nullptr;
        }

        for (int i = 0; i < k; i++) { // 슬라이딩 윈도우 생성하기
            if (pointer == nullptr) break; // iterator가 순회하는 중간에 끝에 도달하면 일단 멈추기
            slidingWindow[i] = pointer;
            pointer = pointer -> next; // 맨 마지막에 pointer는 slidingWindow의 바로 다음 노드를 가리킴
            count++;
        }


        if (count < k) { // 슬라이딩 윈도우가 중간에 끊기면 정리하고 종료
            start -> next = slidingWindow[0];
            break;
        } 
        
        slidingWindow[0]->next = pointer; // 맨 마지막 슬라이딩 윈도우에서 그 다음 나머지 노드(nullptr 포함)로 연결하기 

        for (int i = k - 1; i > 0 ; i--) { // 윈도우 안에 있는 값 reversing
            slidingWindow[i] -> next = slidingWindow[i-1];
        }
        
        if (index == 0) { // index가 0이면 가장 처음 윈도우, head를 윈도우의 가장 마지막 노드로 수정하기
            index += k; // 굳이 반복문 안에 들어갈 필요 없음, 처음 윈도우인지 여부만 파악하면 됨
            start = slidingWindow[0]; // start, end값 처음으로 넣기
            end = slidingWindow[k - 1];
            head = slidingWindow[k - 1];
        } else {
            start -> next = slidingWindow[k - 1]; // k 개 단위끼리 연결하기
            start = slidingWindow[0]; // start, end값 기억하기
            end = slidingWindow[k - 1];
        }
    }
    return head;
}

