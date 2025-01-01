class Solution {
 public:
  int maxProduct(string s) {
    int ans = 0;
    dfs(s, 0, "", "", ans);
    return ans;
  }

  void dfs(string& s, int i, string s1, string s2, int& ans) {
    if (i == s.length()) {
        if (isPalindrome(s1) && isPalindrome(s2)){
            ans = max(ans, static_cast<int>(s1.length() * s2.length()));
        }
      return;
    }

    s1.push_back(s[i]);
    dfs(s, i + 1, s1, s2, ans);
    s1.pop_back();

    s2.push_back(s[i]);
    dfs(s, i + 1, s1, s2, ans);
    s2.pop_back();

    dfs(s, i + 1, s1, s2, ans);
  }

  bool isPalindrome(string& s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j){
        if (s[i] != s[j]){
            return false;
        }
        ++i;
        --j;
    }
    return true;
  }
};
