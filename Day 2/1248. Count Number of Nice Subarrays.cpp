class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        queue<int>odd;
        int subarrays=0, popped=-1, gap=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]%2==1) {
                odd.push(i);
            }
            if (odd.size()>k) {
                popped=odd.front();
                odd.pop();
            }
            if (odd.size()==k) {
                gap=odd.front()-popped;
                subarrays+=gap;
            }
        }
        return subarrays;
    }
};
