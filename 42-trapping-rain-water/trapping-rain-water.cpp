class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        // vector<int>prefix(n);
        // vector<int>suffix(n);
        // prefix[0]=height[0];
        // suffix[n-1]=height[n-1];
        // for(int i=1;i<n;i++){
        //     prefix[i]=max(prefix[i-1],height[i]);

        // }
        // for(int i=n-2;i>=0;i--){
        //     suffix[i]=max(suffix[i+1],height[i]);
            
        // }
        int prefix=INT_MIN;
        int suffix=INT_MIN;
        int index=-1;
        for(int j=0;j<n;j++){
            if(height[j]>=suffix){
                suffix=height[j];
                index=j;
            }
        }

        int ans=0;
         for(int i=0;i<index;i++){
            prefix=max(prefix,height[i]);

            // int a=min(prefix,suffix);
             if(height[i]<prefix){
                ans+=(prefix-height[i]);
            }
            
        }
        // int prefixnew=0;
        prefix=0;
        for(int j=n-1;j>index;j--){
            prefix=max(height[j],prefix);
            if(prefix-height[j]>0){
                ans+=prefix-height[j];
            }
        }
        return ans;
    }
};