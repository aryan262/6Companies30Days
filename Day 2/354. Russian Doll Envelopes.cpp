class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& env1, vector<int>& env2) {
            return env1[0]<env2[0]||(env1[0]==env2[0]&&env1[1]>env2[1]);
        });
        int res=0;
        vector<int> dp(envelopes.size());
        for (auto pr:envelopes) {
            int left=0, right=res;
            while (left<right) {
                int mid=(left+right)/2;
                if (dp[mid]>=pr[1]){
                    right=mid;
                }
                else{
                    left=mid+1;
                }
            }
        dp[left]=pr[1];
        if (left==res)
            ++res;
        }
        return res;
    }
};
