// LintCode coins in a line iii
// The DP in this program is expanding through the gap dimension.

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        // This problem with two sides, 2D dp is a good choice.
        // we use dp[i][j] i <= j to represents the array from index i to j
        // what is the maximum amount we can get.
        // when i > j, dp[i][j] = 0;
        int n = values.size();
        if (n == 1)
            return true;
        if (n == 2)
            return values[0] != values[1];
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = values[i];
            
        // We gradually increase the distance between i and j to achieve
        // the solvation of dp[0][n - 1].
        // dp[i][j] = max(values[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
        //                values[j] + min(dp[i][j - 2], dp[i + 1][j - 1])).
        // Becareful of the boundary check.
        for (int gap = 1; gap <= n - 1; gap++) {
            for (int i = 0; i + gap <= n - 1; i++) {
                // Calculate dp[i][i + gap] in this case.
                // getting the left coin. 
                int leftCoin, rightCoin;
                if (i + 2 > n - 1)
                    leftCoin = values[i];
                else
                    leftCoin = values[i] + min(dp[i + 2][i + gap], dp[i + 1][i + gap - 1]);
                
                // getting the right coin.
                if (i + gap - 2 < 0)
                    rightCoin = values[i + gap];
                else
                    rightCoin = values[i + gap] + min(dp[i + 1][i + gap - 1], dp[i][i + gap - 2]);
                
                dp[i][i + gap] = max(leftCoin, rightCoin);
            }
        }
        return dp[0][n - 1] > min(dp[1][n - 1], dp[0][n - 2]);
    }
};

// If there is even number of coins, for instance, the original position is numbered as
// 1, 2, 3, 4, 5, 6, 7, 8  
// there is a strategy that we can only pick the even/odd numbers for the first player.

bool firstWinEvenCoins(const vector<int>& values) {
    int odd_sum = 0;
    int even_sum = 0;
    for (int i = 0; i < values.size(); i++) {
        if (i % 2 == 0)
            even_sum += values[i];
        else
            odd_sum += values[i];
    }
    
    // If it is equal, we are still not sure who will win,
    // Then we should still go through the above method to check who will win.
    // This is actually a bypassing function that can be used.
    return odd_sum != even_sum;
}
