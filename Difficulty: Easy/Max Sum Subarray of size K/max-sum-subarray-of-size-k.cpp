class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int s = 0;
        int e = 0; 
        int winSum = 0;
        for (e = 0 ; e < k; e++){
            winSum += arr[e];
        } 
        int maxSum = winSum;
        for ( ; e < arr.size(); e++ ) {
            winSum += arr[e];
            winSum -= arr[s];
            s ++;
            maxSum = max(maxSum, winSum);
        }
        return maxSum;
    }
};