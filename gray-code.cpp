// LintCode easy problem

class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> res;
        if (n == 0)
            return vector<int>{0};

        res.push_back(0);
        res.push_back(1);
        // We can use for loop to achieve the effect of recursive.
        // Use a power to track the thing to add.
        int power = 1;
        for (int i = 1; i < n; i++) {
            power *= 2;
            int size = res.size();
            for (int i = 0; i < size; i++) {
                res.push_back(res[size - i - 1] + power);
            }
        }
        
        return res;
    }
};
