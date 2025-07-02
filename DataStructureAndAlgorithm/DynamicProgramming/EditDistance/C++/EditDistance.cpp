#include "EditDistance.h"

int editDistance(const std::string& word1, const std::string& word2) {
    int m = word1.length();
    int n = word2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j; // Min. operations = j
            } else if (j == 0) {
                dp[i][j] = i; // Min. operations = i
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j],      // Delete
                                         dp[i][j - 1],      // Insert
                                         dp[i - 1][j - 1]}); // Replace
            }
        }
    }
    return dp[m][n];
}
