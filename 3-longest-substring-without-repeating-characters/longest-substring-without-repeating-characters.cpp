class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // last occurrence index + 1 for ASCII (256 covers letters, digits, symbols, spaces)
        vector<int> last(256, 0);
        int n = (int)s.size();
        int ans = 0;
        int l = 0; // window left

        for (int r = 0; r < n; ++r) {
            unsigned char c = s[r];
            // if c seen and inside current window, jump left just past its last position
            l = max(l, last[c]);
            // window length is r-l+1
            ans = max(ans, r - l + 1);
            // store next valid index after this character
            last[c] = r + 1;
        }
        return ans;
    }
};
