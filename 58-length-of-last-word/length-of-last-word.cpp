class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1;
        int count=0;
        while(s[i]==' ') i--;
        while(s[i]!=' '){
            count++;
            i--;
            if(i<0) return count;
        }
        return count;
    }
};