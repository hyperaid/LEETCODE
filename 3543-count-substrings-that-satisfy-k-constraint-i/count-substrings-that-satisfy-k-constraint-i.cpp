class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.length();
        int count = 0;
        int no1 = 0;
        int no0 = 0;
        while (i < n && j < n) {
            if (s[j] == '1')
                no1++;
            if (s[j] == '0')
                no0++;
            while (no1 > k && no0 > k && i<j) {
                
                if (s[i] == '1')
                    no1--;
                if (s[i] == '0')
                    no0--;
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
};