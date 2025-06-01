class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int greatest = arr[0];
        for (int i = 0; i<arr.size(); i++){
            if (arr[i] > greatest){
                 greatest = arr[i];
            }
        }
        return greatest;
    }
};
