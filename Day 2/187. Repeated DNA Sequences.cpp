class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int>count;
        int starts = s.size()-9;
        vector<string>repeats;
        for (int i=0;i<starts;++i) {
            string subsequence=s.substr(i, 10);
            if (++count[subsequence]==2) {
                repeats.push_back(subsequence);
            }
        }
        return repeats;
    }
};
