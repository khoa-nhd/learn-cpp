class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i = 0; i < n; ++i){
            string c = tokens[i];
            if(c == "*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a*b);
            } else if(c == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b/a);
            } else if(c == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a+b);
            } else if(c == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b-a);
            } else{
                int num = 0;
                int dau = 1;
                for(int i = 0; i < c.size(); ++i){
                    if(c[i] == '-'){
                        dau = -1;
                        continue;
                    }
                    num *= 10;
                    num += c[i] - '0';
                }
                num *= dau;
                st.push(num);
            }
            cout << st.top() << " ";
        }
        return st.top();
    }
};