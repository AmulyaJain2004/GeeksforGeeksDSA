class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int large= arr[0];
        int seclarge= INT_MIN;
        for (int i = 1; i < arr.size(); i++){
            if (arr[i]>large){
                seclarge = large;
                large = arr[i];
            }
            else if (arr[i] < large && arr[i] > seclarge){
                seclarge = arr[i];
            }
            else if (arr[i] < large && arr[i] < seclarge){
                continue;
            } 
        }
        if (seclarge == INT_MIN ){
            return -1;
        }
        return seclarge;
    }
};