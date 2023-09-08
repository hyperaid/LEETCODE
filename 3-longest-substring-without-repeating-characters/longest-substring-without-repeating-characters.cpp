class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int i=0;
            int j=0;
            int count=0,ans=0;
            map<char,int>mpp;
            while(j<s.length()){
                mpp[s[j]]++;
                // if(mpp.size()>(j-i+1))
                if(mpp.size()==(j-i+1)){
                    ans=max(ans,j-i+1);
                    j++;
                }
                else if(mpp.size()<j-i+1){
                     while (mpp.size() < j - i + 1) {
                        mpp[s[i]]--;
                        if(mpp[s[i]]==0) mpp.erase(s[i]);
                        i++;
                    }
                    j++;
                }
                

            }
            return ans; 
        }
};
