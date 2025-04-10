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
}

// Question 8 Tests
TEST(KthCharacterTest, BasicExamples) {
    std::vector<int> ops1 = {0, 0, 0};
    EXPECT_EQ(kthCharacter(5, ops1), 'a');

    std::vector<int> ops2 = {0, 1, 0, 1};
    EXPECT_EQ(kthCharacter(10, ops2), 'b');

    // TODO: Implement tests
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
}

// Main entry for GoogleTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
