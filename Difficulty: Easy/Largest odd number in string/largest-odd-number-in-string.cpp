class Solution {
  public:
    string maxOdd(string s) {
        // your code here
        for (int i = s.size() - 1; i >= 0 ; i--) {
            if (int(s[i]) % 2 != 0) {
                return s.substr(0, i+1);
            }
        }
        return "";
    }
};