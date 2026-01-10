class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        // We have sorted and unsorted part and we iterate through unsorted and place at the correct position in sorted 
        for (int i = 0; i < arr.size() - 1; i ++) {
            int smallestIdx = i;
            for (int j = i+1; j < arr.size(); j ++) {
                if (arr[j] < arr[smallestIdx]) {
                    smallestIdx = j;
                }
            }
            swap(arr[i], arr[smallestIdx]);
        }
    }
};