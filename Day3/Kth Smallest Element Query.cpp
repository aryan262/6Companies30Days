class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<pair<string, int>> arr(n);
        vector<int> res;
        for (auto& q : queries) {
            int k = q[0], temp = q[1];
            for (int j = 0; j < n; ++j) {
                arr[j] = {nums[j].substr(nums[j].size() - temp), j};
            }
            sort(arr.begin(), arr.end());
            res.push_back(arr[k - 1].second);
        }
        return res;
    }
};
