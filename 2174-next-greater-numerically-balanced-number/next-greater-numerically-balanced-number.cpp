class Solution {
public:
    bool isBalanced(int x) {
        string s = to_string(x);
        vector<int> cnt(10, 0);
        for (char c : s) cnt[c - '0']++;

        for (char c : s) {
            int d = c - '0';
            if (cnt[d] != d) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        int num = n + 1;
        while (true) {
            if (isBalanced(num))
                return num;
            num++;
        }
    }
};
