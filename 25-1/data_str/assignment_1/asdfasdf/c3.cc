#include <iostream>
#include <vector>

// Question 9: Median of two sorted arrays
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    // TODO: Implement
    int size1 = nums1.size();
    int size2 = nums2.size();
    int size3 = (size1 + size2) / 2;

    if (size3 % 2 == 0) {
        // 전체 길이가 짝수
    } else {
        // 전체 길이가 홀수
        
    }
    
    
    if (med(nums1) > med(nums2)) {
        std::vector<int>& big = nums1;  
        std::vector<int>& small = nums2;  

    } else if (med(nums1) < med(nums2)) {
        std::vector<int>& big = nums2;  
        std::vector<int>& small = nums1; 

    } else {
        // 같을 경우 그것이 중앙값
        return med(nums1);
    }

    

    

    return 0.0;
}


double med(std::vector<int>& nums) {
    if (nums.size() % 2 == 0) { 
        // 길이가 홀수일 경우
        return nums[(nums.size() - 1) / 2];
    } else {
        // 길이가 짝수일 경우
        return (nums[nums.size() / 2] + nums[(nums.size() / 2) - 1]) / 2;
    }
}