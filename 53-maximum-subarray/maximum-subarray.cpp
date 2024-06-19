class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(sum, ans);

            if (sum < 0)
                sum = 0;
        }
        // if(ans<0) return 0;
        return ans;
    }
};