class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double, int>>valBywt;
        for (int i = 0; i < val.size(); i++) {
            valBywt.push_back({(double)val[i] / wt[i], i});
        }
        double ans = 0.0;
        sort(valBywt.begin(), valBywt.end(), greater<pair<double, int>>());
        int i = 0;
        while (i < val.size() && capacity > 0) {
            int idx = valBywt[i].second;
            if (wt[idx] <= capacity) {
                ans += val[idx];
                capacity -= wt[idx];
            }
            else {
                // Take only the fraction that fits
                ans += valBywt[i].first * capacity;
                capacity = 0;
            }
            i++;
        }
        return ans;
    }
};
