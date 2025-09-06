class Solution {
  public:
    bool isRotated(string& s1, string& s2) {
        // code here
        // O(1) solution
        if (s1.size() < 3) {
            return false;
        }
        string s1_clock = s1.substr(2) + s1.substr(0,2);
        string s1_anticlock = s1.substr(s1.size() - 2) + s1.substr(0, s1.size() - 2);
        if (s1_clock == s2 || s1_anticlock == s2) {
            return true;
        }
        return false;
    }
};
