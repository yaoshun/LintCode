// Longest Increasing Subsequence

// Naive DP solution.
// Complexity O(n^2).
class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> dp(n, 0);
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] <= nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// Binary Search approach.
// Complexity O(nlog n).

// Key idea is during the process of scanning the array.
// We keep track of the longest increasing subarray and also
// trying to use the newly coming element to lower the requirement
// for future elements.
class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int n = nums.size();
        
        if (n == 0)
            return 0;
            
        // O(nlogn) algorithm
        // p[i] represents the index of the predecessor of nums[i] in the longest
        // increasing subsequence ending in nums[i]
        vector<int> p(n, 0);
        // m[j] represents the index of k of the smallest value nums[k] so that
        // there is an increasing sequence of length j ending in nums[k].
        
        // nums[m[i]] is non-decreasing with respect to i, which enables the possibility
        // of binary searching.
        vector<int> m(n + 1, 0);
        
        // L represents the length of current possible longest increasing subsequence. 
        int L = 0;
        for (int i = 0; i < n; i++) {
            // Binary search for the largest positive j <= res
            // so that nums[m[j]] <= nums[i]
            int low = 1;
            int high = L;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[m[mid]] <= nums[i]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            // The binary search returns a newL so that nums[m[low]] > nums[i] and
            // nums[m[low-1]] <= nums[i], which is the exact position we want to modify
            // the m array.
            int newL = low;
            p[i] = m[newL - 1];
            m[newL] = i;
            
            if (newL > L)
                L = newL;
        }
        
        return L;
    }
};
