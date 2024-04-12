class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int>v1(n);
        vector<int>v2(n);
        v1[0]=h[0];
        v2[n-1]=h[n-1];
        for(int i=1;i<n;i++){
            v1[i]=max(v1[i-1],h[i]);
        }
        for(int i=n-2;i>=0;i--){
            v2[i]=max(h[i],v2[i+1]);
        }
        int count=0;

        for(int i=0;i<h.size();i++){
            count+=min(v1[i],v2[i])-h[i];
        }
        return count;
    }
};