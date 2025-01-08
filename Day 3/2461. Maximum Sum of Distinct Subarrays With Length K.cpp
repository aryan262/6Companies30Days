class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, curr=0;
        int begin = 0, end=0;
        unordered_map<int, int>convert;
        while(end<nums.size()) {
            int currNum = nums[end];
            int last = (convert.count(currNum)?convert[currNum]:-1);
            while(begin<=last || end-begin+1>k) {
                curr -= nums[begin];
                begin++;
            }
            convert[currNum] = end;
            curr += nums[end];
            if (end-begin+1 == k) {
                ans = max(ans, curr);
            }
            end++;
        }
        return ans;
    }
};
