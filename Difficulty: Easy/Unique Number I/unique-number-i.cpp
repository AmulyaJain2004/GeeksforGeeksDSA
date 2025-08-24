class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        for (int i = 0; i <  arr.size(); i++) {
            arr[i] = arr[i]^arr[i-1];
        }
        return arr[arr.size() -1];
    }
};