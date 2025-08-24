class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        if (s1.size() != s2.size()) {
            return false;
        }
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < s1.size(); i++) {
            mp1[s1[i]] ++;
            mp2[s2[i]] ++;
        }
        return mp1 == mp2;
    }
};