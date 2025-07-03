

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int j = 0; 
        vector<int> new_arr;
        new_arr.push_back(arr[arr.size()-1]);
        for (int i = arr.size()-2; i >= 0 ; i-- ){
            if (arr[i] >=new_arr[j]){
                new_arr.insert(new_arr.begin(), arr[i]);
            }
        }
        return new_arr;
    }
};