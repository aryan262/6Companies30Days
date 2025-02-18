class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    int n = nums.size();
    nth_element(nums.begin(), nums.begin() + n/2, nums.end());
    int median = nums[n/2];
    return accumulate(nums.begin(), nums.end(), 0, [&](int subtotal, int num) {
      return subtotal + abs(num-median);
    });
  }
};
