class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // int c1=0;
        // int c2=0;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='(') c1++;
        //     if(s[i]==')') c2++;

        // }
        // stack<char>st;
        // string ans=" "
        // for(int i=0;i<s.length();i++){
        //     if(s[i]==')'|| s[i]=='('){
        //         if(s[i]=='(' &&c2>0){
        //             st.push('(');
        //             c1--;
        //             c2--;
        //             ans+='(';
        //         }
        //         else if(!st.empty() && st.top()==')'){
        //             ans+=s[i];
        //             st.pop();
        //             c2--;
        //         }
        //     }
        //     else{
        //         ans+=s[i];
        //     }
        // }
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                continue;
            }
            if(s[i]=='('){
                st.push(i);
            }
            else{
               if(!st.empty()){
                st.pop();
               }
               else{
                s[i]='@';
               }
            }
        }
        while(!st.empty()){
            s[st.top()]='@';
            st.pop();
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='@') ans+=s[i];
        }
        return ans;
    }
};