class Solution {
  public:
    string printParenthesis(int i, int j, vector<vector<int>>& bracket) {
        if (i == j)
            return string(1, 'A' + i - 1);

        return "(" + printParenthesis(i, bracket[i][j], bracket) + printParenthesis(bracket[i][j] + 1, j, bracket) + ")";
    }
    string matrixChainOrder(vector<int> &arr) {
        // code here
        int N=arr.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j)
                    dp[i][j] = 0;
            }
        }

        vector<vector<int>> bracket(N, vector<int>(N, 0));
        for (int l = 2; l < N; l++) {
            for (int i = 1; i < N - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        bracket[i][j] = k;
                    }
                }
            }
        }

        return printParenthesis(1, N - 1, bracket);
    }
};
