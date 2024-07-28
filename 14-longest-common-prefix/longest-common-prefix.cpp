class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs[0].length();
        string s="";
        for(int i=0;i<n;i++){
            char a=strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=a) return s;
            }
            s+=strs[0][i];
        }
        return s;
    }
};