class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string& it : tokens) {
            if (it == "+" || it == "-" || it == "*" || it == "/") {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();

                if (it == "+")
                    s.push(op1 + op2);
                else if (it == "-")
                    s.push(op1 - op2);
                else if (it == "*")
                    s.push(op1 * op2);
                else if (it == "/")
                    s.push(op1 / op2);
            } else {
                s.push(stoi(it));
            }
        }
        return s.top();
    }
};
