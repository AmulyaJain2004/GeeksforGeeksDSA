

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> new_arr;
        new_arr.push_back(arr[arr.size()-1]);
        for (int i = arr.size()-2; i >= 0 ; i-- ){
            if (arr[i] >=new_arr[0]){
                new_arr.insert(new_arr.begin(), arr[i]);
            }
        }
        return new_arr;
    }
};