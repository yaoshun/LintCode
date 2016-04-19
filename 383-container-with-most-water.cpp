// LintCode medium problem
//

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int n = heights.size();
        if (n <= 1)
            return 0;
        int i = 0;
        int j = n - 1;
        int res = 0;
        while (i < j) {
            int area = min(heights[i], heights[j]) * (j - i);
            res = max(area, res);
            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};
