class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
            low = max(low, weights[i]);
            high += weights[i];
        }
        int ans;
        while (low <= high) {
            int mid = (low + high) >> 1;
            int count = 1;
            int sum = 0;

            for (int i = 0; i < weights.size(); i++) {
                sum += weights[i];

                if (sum > mid) {
                    count++;
                    sum = weights[i];
                }
            }
            if (count <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }

            
        }
        return ans;

    }
};