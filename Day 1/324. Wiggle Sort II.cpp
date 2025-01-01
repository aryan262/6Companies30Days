class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto it = nums.begin() + n/2;
        nth_element(nums.begin(), it, nums.end());
        int median = *it;
        for (int i=0, j=0, k=n-1;i<=k;) {
            if (nums[(2*i + 1)%(n|1)]>median) {
                swap(nums[(2*i + 1)%(n|1)], nums[(2*j++ + 1)%(n|1)]);
                ++i;
            } 
            else if(nums[(2*i + 1)%(n|1)]<median) {
                swap(nums[(2*i + 1)%(n|1)], nums[(2*k-- + 1)%(n|1)]);
            } 
            else {
                ++i;
            }
        }
    }
};
