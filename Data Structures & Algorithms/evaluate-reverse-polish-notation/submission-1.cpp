class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk; 

        for (const string& token : tokens){
            if (token == "+"){
                int a = stk.top(); 
                stk.pop(); 
                int b = stk.top(); 
                stk.pop(); 
                int result = a + b; 
                stk.push(result); 
            }
            else if (token == "-"){
                int a = stk.top(); 
                stk.pop(); 
                int b = stk.top(); 
                stk.pop(); 
                int result = b - a; 
                stk.push(result); 
            }

            else if (token == "*"){
                int a = stk.top(); 
                stk.pop(); 
                int b = stk.top(); 
                stk.pop(); 
                int result = a * b; 
                stk.push(result); 
            }
            else if (token == "/"){
                int a = stk.top(); 
                stk.pop(); 
                int b = stk.top(); 
                stk.pop(); 
                int result = b / a; 
                stk.push(result); 
            }
            else {
                stk.push(stoi(token)); 
            }
        }
        return stk.top(); 
    }
};
