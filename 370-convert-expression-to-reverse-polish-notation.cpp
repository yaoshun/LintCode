// Lintcode hard problem

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        vector<string> res;
        infixToPostfix(expression, res);
        return res;
    }
    
    void infixToPostfix(vector<string>& infix, vector<string>& res) {
        stack<string> s;
        for (auto tok : infix) {
            if (atoi(tok.c_str())) {
                res.push_back(tok);
            } else if (tok == "(") {
                s.push(tok);
            } else if (tok == ")") {
                while (!s.empty()) {
                    tok = s.top();
                    s.pop();
                    if (tok == "(") {
                        break;
                    }
                    res.push_back(tok);
                }
            } else {
                while (!s.empty() && precedence(tok) <= precedence(s.top())) {
                    res.push_back(s.top());
                    s.pop();
                }
                s.push(tok);
            }
        }
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
    } 
    
    int precedence(string x) {
        // "(" should never be poped out; thus it has
        // the lowest precedence.
        if (x == "(") {
            return 0;
        } else if (x == "+" || x == "-") {
            return 1;
        } else if (x == "*" || x == "/") {
            return 2;
        } else {
            return 3;
        }
    }
};
