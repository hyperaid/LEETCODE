class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int count = 0;
        int prod = 1;
        if (k == 0)
            return 0;
        if (k == 1)
            return 0;
        while (i < n && j < n) {
            prod *= nums[j];
            while (i < j && prod >= k) {
                prod /= nums[i];
                i++;
            }
            if (prod < k) {
                count += j - i + 1;
            }

            j++;
        }
        return count;
    }
};