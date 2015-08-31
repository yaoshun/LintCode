// Lintcode problem.
// In O(n) two pointer solution, we only need to
// change one pointer by 1, which is already enough.
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if (n <= 1)
            return;
        
        int i = 0, j = n - 1;
        while (i < j) {
            if (nums[i] % 2 == 1) {
                i++;
            } else if (nums[j] % 2 == 0) {
                j--;
            } else {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        return;
    }
};
