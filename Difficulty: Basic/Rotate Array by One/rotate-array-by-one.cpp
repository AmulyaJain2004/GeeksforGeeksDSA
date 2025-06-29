// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        for (int i =arr.size()-2; i>= 0; i--){
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }
};