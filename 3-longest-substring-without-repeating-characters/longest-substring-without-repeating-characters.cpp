class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mpp;
        int i=0;
        int j=0;
        int ans=0;
        int count=0;
        while(j<s.length() && i<s.length()){
            
            while(mpp[s[j]]==0 &&j<s.length()){
                count++;
                mpp[s[j]]++;
                ans=max(ans,j-i+1);

                j++;
            }
            mpp[s[i]]--;
            i++;
        }
        return ans;

    }
};