#include "LongestIncreasingSubsequence.h"

int longestIncreasingSubsequence(const std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int n = nums.size();
    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], 1 + dp[j]);
            }
        }
    }

    int max_len = 0;
    for (int len : dp) {
        if (len > max_len) {
            max_len = len;
        }
    }
    return max_len;
}
