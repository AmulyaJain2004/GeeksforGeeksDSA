class Solution {
  public:
    int dp[101][101];
    int helper(vector<int> &arr, int i, int j) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int temp = helper(arr, i, k) + helper(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int i = 1;
        int j = arr.size() - 1;
        memset(dp, -1, sizeof(dp));
        int ans = helper(arr, i, j);
        return ans;
    }
};