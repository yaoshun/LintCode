// LintCode Copy Books problem
// The simple DP solution will cost O(n^2*k)
// The optimized DP solution can only cost O(n*k)

class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // Here we use the naive DP solution.
        // f(k, n) = min(max(f(k-1, n-i), sum(n-i to n-1)))
        // Vary the work amount of the last person and check all the
        // conditions.
        int n = pages.size();
        // Each person can at most copy one book.
        // k = min(n, k) can effectively reduce the amount of time
        // consumed in extreme cases, similar to Best time to buy and sell
        // stocks problem 4.
        k = min(n, k);
        vector<int> sum_from_start(n ,0);
        partial_sum(pages.begin(), pages.end(), sum_from_start.begin());

        vector<vector<int>> res(k + 1, vector<int>(n, INT_MAX));
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                // Initialization condition
                // j == 0 means only the first book.
                // i == 1 means only one person
                if (i == 1 || j == 0) {
                    res[i][j] = sum_from_start[j];
                } else {
                    for (int k = j - 1; k >= 0; k--) {
                        int curr = max(res[i-1][k], sum_from_start[j] - sum_from_start[k]);
                        res[i][j] = min(res[i][j], curr);
                    }
                }
            }
        }
        return res[k][n-1];
    }
};

// Solution two which is O(n*k)
class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        int n = pages.size();
        k = min(n, k);
        vector<int> sum_from_start(n, 0);
        partial_sum(pages.begin(), pages.end(), sum_from_start.begin());
        vector<vector<int>> res(k + 1, vector<int>(n, INT_MAX));
        for (int j = 0; j < n; j++) {
            res[1][j] = sum_from_start[j];
        }

        // Two pointer solution here.
        // Very smartly use the monotonic trend of res[i][n]
        // as n (left) increases, res[i][left] will increase.
        // Also the optimal solution always lies on the point
        // where curr is close to res[i-1][left], which provide the possibility of 
        // doing a two pointer search.
        for (int i = 2; i <= k; i++) {
            minutes[i][0] = sum_from_start[0];
            int left = 0, right = 1;
            while (right < n) {
                int curr = sum_from_start[right] - sum_from_start[left];
                res[i][right] = min(max(curr, res[i - 1][left]), res[i][right]);
                if (left < right && res[i-1][left] < curr) {
                    left++;
                } else {
                    right++;
                    // we should calculate the next solution from left - 1
                    // only add one additional consideration.
                    if (left > 0) {
                        left --;
                    }
                }
            }
        }
        return res[k][n-1];
    }
};
