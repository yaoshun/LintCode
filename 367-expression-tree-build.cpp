// LintCode problem expression tree build

/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        // write your code here
        if (expression.empty())
            return NULL;

        vector<string> prefix;
        infixToPrefix(expression, prefix);
        int start = 0;
        return buildExpressionTree(prefix, start);
    }

    ExpressionTreeNode* buildExpressionTree(vector<string>& prefix, int& start) {
        if (prefix.empty())
            return NULL;
        ExpressionTreeNode* node = new ExpressionTreeNode(prefix[start]);
        start++;

        if (is_operator(prefix[start - 1])) {
            node->left = buildExpressionTree(prefix, start);
            node->right = buildExpressionTree(prefix, start);
        }
        return node;
    }

    bool is_operator(const string& op) {
        return op == "+" || op == "-" || op == "*" || op == "/";
    }

    void infixToPrefix(vector<string>& infix, vector<string>& prefix) {
        // Reverse the array in O(n) time.
        reverse(infix.begin(), infix.end());
        stack<string> s;
        for (auto& tok : infix) {
            // Zero will cause problem.
            // tok = "0" atoi is int zero.
            if (atoi(tok.c_str())) {
                prefix.push_back(tok);
            } else if (tok == ")") {
                s.push(tok);
            } else if (tok == "(") {
                while (!s.empty()) {
                    tok = s.top();
                    s.pop();
                    if (tok == ")") {
                        break;
                    }
                    prefix.push_back(tok);
                }
            } else {
                while (!s.empty() && precedence(tok) < precedence(s.top())) {
                    prefix.push_back(s.top());
                    s.pop();
                }
                s.push(tok);
            }
        }
        while (!s.empty()) {
            prefix.push_back(s.top());
            s.pop();
        }
        reverse(prefix.begin(), prefix.end());
    }

    int precedence(string x) {
        if (x == ")") {
            return 0;
        } else if (x == "+" || x == "-") {
            return 1;
        } else if (x == "*" || x == "/") {
            return 2;
        }
        return 3;
    }
};
