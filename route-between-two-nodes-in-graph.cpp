// LintCode problem BFS.

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        if (s == t)
            return true;
        
        queue<DirectedGraphNode*> q;
        unordered_set<DirectedGraphNode*> st;
        
        q.push(s);
        while (!q.empty()) {
            DirectedGraphNode* node = q.front();
            st.insert(node);
            q.pop();
            for (auto n : node->neighbors) {
                if (n == t) {
                    return true;
                } else if (st.find(n) == st.end()) {
                    q.push(n);
                }
            }
        }
        return false;
    }
};

