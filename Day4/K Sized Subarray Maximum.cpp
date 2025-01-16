class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> result;
        deque<int> dq;
        for(int i=0;i<arr.size();i++){
            if (!dq.empty() && dq.front()==i-k) {
                dq.pop_front();
            }
            while (!dq.empty() && arr[dq.back()]<=arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1){
                result.push_back(arr[dq.front()]);
            }
        }
        return result;
    }
};
