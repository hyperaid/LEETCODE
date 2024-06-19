class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> v;
        v.push_back({a[0][0], a[0][1]});
        for (int i = 1; i < a.size(); i++) {
            int start = a[i][0];
            int end = a[i][1];
            if (v.back()[1] >= start) {
                if (v.back()[1] <= end) {
                    v.back()[1] = end;
                }

            } else {
                v.push_back({start, end});
            }
        }
        return v;
    }
};
