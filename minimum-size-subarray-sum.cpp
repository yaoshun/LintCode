class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int n = nums.size();
        if (n == 0)
            return -1;

        int i = 0; 
        int j = 0;

        // Store the sum from [i, j].
        int sum = nums[0];
        int res = INT_MAX;
        while (j < n) {
            if (sum >= s) {
                res = min(res, j - i + 1);
                sum -= nums[i];
                i++;
            } else {
                j++;
                // if sum < s and j now == n,
                // we did not miss any solution at the end.
                if (j < n)
                    sum += nums[j];
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
