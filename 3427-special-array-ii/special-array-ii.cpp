
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefix = {0};
        int n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                prefix.push_back(0);
            } else {
                prefix.push_back(1 + prefix.back());
            }
        }

      

        vector<bool> ans;
        for (const auto& query : queries) {
            int a = query[0];
            int b = query[1];
            int ln = prefix[b] - prefix[a];
            if (ln == b - a) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};