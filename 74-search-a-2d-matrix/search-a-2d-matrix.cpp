class Solution {
public:
    bool bs(vector<int>&a,int target){
        int i=0;
        int j=a.size()-1;
        int mid;
        while(i<=j){
            mid=i+(j-i)/2;
            if(a[mid]==target) return true;
            else if(a[mid]>target){
                j=mid-1;
            }
            else i=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) { 
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(target>=matrix[i][0] && target<=matrix[i][m-1]){
                return bs(matrix[i],target);
            }
        }
        return false;
    }
};