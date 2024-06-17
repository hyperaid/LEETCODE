class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0; i<=sqrt(c); i++){
            double root = sqrt(c-pow(i,2));
            int intval = static_cast<int>(root);
            if(root == intval)return true;
        }
        return false;
    }
};