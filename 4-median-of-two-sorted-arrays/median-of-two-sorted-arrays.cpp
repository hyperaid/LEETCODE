class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size()+nums2.size();
        vector<int>v(m);
        int i=0;
        int j=0;
        int k=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]>nums2[j]){
                v[k]=nums2[j];
                j++;
                k++;
            }
            else{
                v[k]=nums1[i];
                i++;
                k++;
            }
        }
        while(i<nums1.size()){
            v[k]=nums1[i];
            k++;
            i++;
        }
        while(j<nums2.size()){
            v[k]=nums2[j];
            k++;
            j++;
        }
        // cout<<v[m/2];
        // for(auto it :v) cout<<it<<" ";
        if(m%2==0){
        // cout<<m<<m/2;
            int a=m/2;
        // cout<<v[a]<<"  "<<v[a-1];

            double median=(v[a]+v[a-1])/2.0;
            return median;
        }
        return v[m/2];
    }
};