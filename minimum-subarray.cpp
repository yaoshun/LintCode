// LintCode

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if (n == 0)
            return 0;
            
        int res = nums[0];
        int prv = nums[0];
        for (int i = 1; i < n; i++) {
            int cur = prv < 0? prv + nums[i] : nums[i];
            if (cur < res)
                res = cur;
            prv = cur;
        }
        return res;
    }
};
