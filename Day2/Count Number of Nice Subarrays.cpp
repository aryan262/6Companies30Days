class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        int sum=0, res=0;
        mp[0]=1; 
        for(auto pr:nums){
            sum+=pr%2;
            res+=mp[sum-k];
            mp[sum]+=1;
        }
        return res;
    }
};