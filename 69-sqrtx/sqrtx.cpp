class Solution {
public:
    int mySqrt(int x) {
        long long i=0;
        int j=x-1;
        long long mid;
        while(i<=j){
            mid=(i+j)/2;
            if(mid*mid==x){
                return mid;
            }
            else if(mid*mid<x){
                i=mid+1;
            }
            else if(mid*mid>x){
                j=mid-1;

            }
        }
        if(i*i==x) return i;
        return i-1;
    }
};