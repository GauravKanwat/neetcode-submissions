class Solution {
    bool isValidOperator(string& str) {
        if(str == "+" || str == "-" || str == "*" || str == "/") return true;
        return false;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(string str : tokens) {
            if(!isValidOperator(str)) {
                int num = stoi(str);
                st.push(num);
            }
            else {
                int a, b;
                if(!st.empty()) b = st.top();
                st.pop();
                if(!st.empty()) a = st.top();
                st.pop();
                int num;
                if(str == "+") num = a+b;
                else if(str == "-") num = a-b;
                else if(str == "*") num = a*b;
                else num = a/b;
                st.push(num);
            }
        }
        return st.top();
    }
};