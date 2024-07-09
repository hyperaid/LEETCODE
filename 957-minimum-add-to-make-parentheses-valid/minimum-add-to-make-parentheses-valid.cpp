class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(1);
            }
            else if(s[i]==')'){
                if(!st.empty()) st.pop();
                else count++;
            }
        }
        return st.size()+count;

    }
};