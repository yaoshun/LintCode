// LintCode Medium problem

// The key point is to notice that 4, 13, 5, /, +
// represents (4 + (13/5)), the later number from the stack is
// the front operator.
class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b + a);
            } else if (tokens[i] == "-") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b - a);
            } else if (tokens[i] == "*") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b * a);
            } else if (tokens[i] == "/") {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b / a);
            } else {
                nums.push(stoi(tokens[i]));
            }
        }
        return nums.top();
    }
};

