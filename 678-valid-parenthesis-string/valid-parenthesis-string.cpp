class Solution {
public:
    bool checkValidString(string s) {
        stack<char>st;
        stack<char>st1;
        int n=s.length();
        // if(n==1) return false;
        
        for(int i=0;i<n;i++){
            if(s[i]=='*') st1.push(i);
            else if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty()) st.pop();
                else if(!st1.empty()){
                    st1.pop();
                }
                else return false;
            }
                
            
        } 
        while(!st1.empty() && !st.empty()){
            if(st.top()>st1.top()) return false;
            st.pop();
            st1.pop();
        }
        if(st.empty()) return true;
        return false;
    }
};