class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.length();
        int n=needle.length();
        int j=0;
        for(int i=0;i<m;i++){
            
            if(needle[j]==haystack[i]){ 
                if(j==(n-1)) return i-n+1;
                j++;
                
            }
            else {
                i=i-j;
                j=0;
                
                // i--;
            }
        }
        return -1;
    }
};