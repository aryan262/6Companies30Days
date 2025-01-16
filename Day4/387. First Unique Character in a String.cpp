class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        int n = s.length();
        for (int i=0;i<n;i++) {
            char c=s[i];
            count[c]++;
        }
        for (int i=0;i<n;i++) {
            if (count[s[i]]==1) 
                return i;
        }
        return -1;
    }
};
