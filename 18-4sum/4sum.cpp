class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4)
            return {};
        
        unordered_map<long long, long long> mpp;
        vector<vector<int>> ans;
        set<vector<int>> set;
        sort(nums.begin(), nums.end());
        
        for (long long i = 0; i < n - 3; i++) {
            for (long long j = i + 1; j < n - 2; j++) {
                long long a = (long long)(target) - ((long long)(nums[i]) + (long long)(nums[j]));
                long long start = j + 1;
                long long end = n - 1;
                
                while (start < end) {
                    long long sum = (long long)(nums[start]) + (long long)(nums[end]);
                    if (sum == a) {
                        set.insert({nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                    } else if (sum > a) {
                        end--;
                    } else {
                        start++;
                    }
                }
            }
        }
        
        for (auto it : set) {
            ans.push_back(it);
        }
        return ans;
    }
};
