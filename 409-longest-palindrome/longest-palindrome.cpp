class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        int count=0;
        for(auto it:mpp){
            if(it.second%2==0){
                count+=it.second;
            }
            else if(it.second>2){
                count+=it.second-1;
            }
        }
        if(count==(s.length())) return count;
        return count+1;
    }
};