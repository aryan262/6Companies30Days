class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> cnt1(10, 0);
        vector<int> cnt2(10, 0);
        for (int i=0;i<secret.length();++i){
            int secretDigit=secret[i]-'0', guessDigit=guess[i]-'0';
            if (secretDigit == guessDigit) {
                ++bulls;
            } else {
                ++cnt1[secretDigit];
                ++cnt2[guessDigit];
            }
        }
        for (int i=0;i<10;++i){
            cows+=min(cnt1[i], cnt2[i]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
