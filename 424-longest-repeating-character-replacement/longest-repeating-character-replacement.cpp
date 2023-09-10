class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mpp;
        int j=0;
        int i=0;
        int ans=INT_MIN;
        int a=-1;
        while(j<s.length()){
            mpp[s[j]]++;
            ans=max(ans,mpp[s[j]]);
            while(j-i+1-ans>k){
                mpp[s[i]]--;
                i++;
            }
            a=max(a,j-i+1);


            
            j++;
        }
        return a;
    }
};