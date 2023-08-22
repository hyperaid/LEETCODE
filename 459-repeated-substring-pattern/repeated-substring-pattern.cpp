class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string dupli="";
        string temp="";
        for(int i=0;i<s.length();i++){
            dupli+=s[i];
            if(s.length()%dupli.length()==0 &&dupli.length()<s.length()){
                while(temp.length()<=s.length()-1){
                    temp+=dupli;
                }
                // cout<<temp<<endl;
                if(temp==s){
                    return true;
                    // break;
                }
                temp="";
            }
        }
        return false;
    }
};