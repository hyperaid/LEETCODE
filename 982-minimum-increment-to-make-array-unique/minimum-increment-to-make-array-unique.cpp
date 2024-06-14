class Solution {
public:
    int minIncrementForUnique(std::vector<int>& nums) {
         map<int, int> mp;

         for (auto it : nums) {
            mp[it]++;
        }

        int count = 0;

         for (auto it = mp.begin(); it != mp.end(); ++it) {
            int excess = it->second - 1;
            if (excess > 0) {
                mp[it->first + 1] += excess;
                count += excess;
            }
        }

        return count;
    }
};