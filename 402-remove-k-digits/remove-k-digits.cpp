class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        string ans="";
        
        for(int i=0;i<num.length();i++){
            while(k>0 && !s.empty() && num[i]<s.top() ){
                    s.pop();
                    k--;
            }
            s.push(num[i]);
        }
        while(k>0 && !s.empty() ){
                    s.pop();
                    k--;
        }
        while(s.size()>k){
            
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        int pos = 0;
        while (pos < ans.length() && ans[pos] == '0') {
            pos++;
        }
        ans = ans.substr(pos);
        if(ans=="") return "0";


        return ans;
    }
};