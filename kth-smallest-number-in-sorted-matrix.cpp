// LintCode problem
// Very similar to merge k sorted list problem.
// Build an heap from the smallest elemnents on the left.
// Then extract them one by one and add the next level.

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> min_heap;
        
        // Init heap by the first element of the first kth column.
        for (int j = 0; j < min(static_cast<int>(matrix[0].size()), k); j++) {
            min_heap.push(pair<int, pair<int, int>>{matrix[0][j], {0, j}});
        }
        
        int res = INT_MAX;
        while (!min_heap.empty() && k--) {
            if (k == 0)
                res = min_heap.top().first;
            int i = min_heap.top().second.first;
            int j = min_heap.top().second.second;
            min_heap.pop();
            
            // Very similar to merge k sorted lists.
            if (i + 1 < matrix.size()) {
                min_heap.push(pair<int, pair<int, int>>{matrix[i + 1][j], {i + 1, j}});
            }
        }
        
        return res;
    }
private:
    struct Compare {
        bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            // Make sure it is min heap.
            // By default priority_queue is a max_heap.
            return a.first > b.first;
        }
    };
};

