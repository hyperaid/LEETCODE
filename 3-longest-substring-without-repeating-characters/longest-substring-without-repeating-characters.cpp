class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mpp;
        int i=0;
        int j=0;
        int ans=0;
        int count=0;
        while(j<s.length() && i<s.length()){
            // if(!(mpp.find(s[j])!=mpp.end()) && mpp[s[i]]==0){
            //     while(mpp[s[j]]==0 && j<s.length()){
            //         mpp[s[j]]++;
            //         j++;
            //     }
            //     ans=max(ans,j-i+1);

            // }
            // else{
            //     while(mpp[s[i]]>1 && i<s.length()){
            //         mpp[s[i]]--;
            //         i++;
            //     }
            // }

            while(mpp[s[j]]==0 &&j<s.length()){
                count++;
                mpp[s[j]]++;
                j++;
                ans=max(ans,j-i);
            }
            mpp[s[i]]--;
            i++;
        }
        return ans;

    }
};