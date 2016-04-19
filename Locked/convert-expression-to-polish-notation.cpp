// LintCode hard problem

// infix to prefix.
// Standard algorithm
// 1. reverse the infix expression.
// 2. traverse the expression, if number output
// if opening parenthesis push )
// if closing parenthesis pop output until )
// if operator, check stack and output the high precedence ones first.
// push the current one to the stack.
// 3. reverse back to prefix notation.
class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Polish notation of this expression
     */
    vector<string> convertToPN(vector<string> &expression) {
        // write your code here
        vector<string> output;
        infixToPrefix(expression, output);
        return output;
    }

    // The algorithm of converting infix to prefix.
    void infixToPrefix(vector<string>& infix, vector<string>& prefix) {
        reverse(infix.begin(), infix.end());
        
        // Stack s only stores operators, "(" and ")".
        stack<string> s;
        
        for (auto& tok : infix) {
            if (atoi(tok.c_str())) {
                prefix.push_back(tok);
            } else if (tok == ")") {
                s.push(tok);
            } else if (tok == "(") {
                // pop the operators until the end of operators.
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

