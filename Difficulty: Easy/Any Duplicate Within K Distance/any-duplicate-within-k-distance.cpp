class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        // brute force approach
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j<n && j <= i+k; j++) { // better than j < n
        //         if (arr[i] == arr[j]) {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // optimised approach
        unordered_map<int,int>mp;
        for (int i = 0; i < n; i++){
            if (mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = i;
            }
            else {
                if (abs(i - mp[arr[i]]) <= k) {
                    return true;
                }
                else {
                    mp[arr[i]] = i;
                }
            }
        }
        return false;
    }
};