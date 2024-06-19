class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        int m=n;
        n=abs(n);
        while(n>0){
            if(n%2==0){

                x=x*x;
                n=n/2;
            }
            else{
                ans*=x;
                n=n-1;
            }

        }
        if (m<0) return 1.0/ans;
        return ans;
    }
};