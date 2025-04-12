#include <gtest/gtest.h>
#include "library_code.cc"

// Question 7 Tests
TEST(MyLinkedListTest, BasicOperations) {
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);  // List: 1->2->3
    EXPECT_EQ(list.get(1), 2);
    list.deleteAtIndex(1);  // List: 1->3
    EXPECT_EQ(list.get(1), 3);

    // TODO: Implement tests
    EXPECT_EQ(list.get(100), -1);
    EXPECT_EQ(list.get(-1), -1);

    list.addAtHead(10);       // List: 10 -> 1 -> 3
    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 1);

    list.addAtTail(20);       // List: 10 -> 1 -> 3 -> 20
    EXPECT_EQ(list.get(3), 20);

    list.addAtIndex(0, 99);   // List: 99 -> 10 -> 1 -> 3 -> 20
    EXPECT_EQ(list.get(0), 99);

    list.addAtIndex(5, 77);   // List: 99 -> 10 -> 1 -> 3 -> 20 -> 77
    EXPECT_EQ(list.get(5), 77);

    list.addAtIndex(100, 42);
    EXPECT_EQ(list.get(100), -1);
}

// Question 8 Tests
TEST(KthCharacterTest, BasicExamples) {
    std::vector<int> ops1 = {0, 0, 0};
    EXPECT_EQ(kthCharacter(5, ops1), 'a');

    std::vector<int> ops2 = {0, 1, 0, 1};
    EXPECT_EQ(kthCharacter(10, ops2), 'b');

    // TODO: Implement tests
    std::vector<int> ops3 = {1, 1, 1};  // abcdefgh
    EXPECT_EQ(kthCharacter(1, ops3), 'a');
    EXPECT_EQ(kthCharacter(2, ops3), 'b');
    EXPECT_EQ(kthCharacter(8, ops3), 'h');

}


// Question 9 Tests
TEST(MedianSortedArraysTest, BasicExamples) {
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    EXPECT_FLOAT_EQ(findMedianSortedArrays(nums1, nums2), 2.0);

    nums1 = {1, 2};
    nums2 = {3, 4};
    EXPECT_FLOAT_EQ(findMedianSortedArrays(nums1, nums2), 2.5);

    // TODO: Implement tests

}

// Question 10 Tests
TEST(ReverseKGroupTest, BasicExamples) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* result = reverseKGroup(head, k);
    std::vector<int> expected_vals = {2, 1, 4, 3, 5};
    for (int val : expected_vals) {
        ASSERT_NE(result, nullptr);
        EXPECT_EQ(result->val, val);
        result = result->next;
    }

    // TODO: Implement tests

    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    int k1 = 1;
    ListNode* result1 = reverseKGroup(head1, k1);
    std::vector<int> expected1 = {1, 2, 3};
    for (int val : expected1) {
        ASSERT_NE(result1, nullptr);
        EXPECT_EQ(result1->val, val);
        result1 = result1->next;
    }

    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);
    head3->next->next->next = new ListNode(4);
    head3->next->next->next->next = new ListNode(5);
    int k3 = 3;
    ListNode* result3 = reverseKGroup(head3, k3);
    std::vector<int> expected3 = {3, 2, 1, 4, 5};
    for (int val : expected3) {
        ASSERT_NE(result3, nullptr);
        EXPECT_EQ(result3->val, val);
        result3 = result3->next;
    }

    ListNode* head4 = new ListNode(1);
    ListNode* cur = head4;
    for (int i = 2; i <= 7; ++i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    int k4 = 4;
    ListNode* result4 = reverseKGroup(head4, k4);
    std::vector<int> expected4 = {4, 3, 2, 1, 5, 6, 7};
    for (int val : expected4) {
        ASSERT_NE(result4, nullptr);
        EXPECT_EQ(result4->val, val);
        result4 = result4->next;
    }
}

// Main entry for GoogleTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
