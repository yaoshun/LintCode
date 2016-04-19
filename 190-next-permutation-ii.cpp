// LintCode medium problem

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if (n <= 1)
            return;
        
        int i;
        for (i = n - 1; i >= 1; i--) {
            // Could not be equal here.
            if (nums[i - 1] < nums[i]) {
                break;
            }
        }
        
        // The whole sequence follow a decreasing trend.
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
 
        // Master the reverse function.       
        reverse(nums.begin() + i, nums.end());
        int j = i;

        // Notice we need to find the first number
        // bigger than nums[i - 1].
        while (nums[i - 1] >= nums[j]) {
            j++;
        }
        swap(nums[i - 1], nums[j]);
        return;
    }
};
