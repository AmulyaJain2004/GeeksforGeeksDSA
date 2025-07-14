class Solution {
  public:
    bool divby13(string &s) {
        // (A * B) % C = ((A % C) * (B % C)) % C
        // (A + B) % C = ((A % C) + (B % C)) % C
        int remainder = 0;
        for (char c: s){
            remainder = (remainder*10 + (c - '0'))%13;
        }
        if (remainder == 0) return true;
        return false;
    }
};