class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0;
        int j=arr.size()-1;
        int n=arr.size();
        if(n==1) return 0;
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1]>arr[n-2]) return n-1;
        while(i<=j){
            int mid=(i+j)>>1;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
                return mid;
            }
            else if(arr[mid]>arr[mid+1]){
                j=mid-1;
            }
            else i=mid+1;
        }
        return 0;
    } 
};