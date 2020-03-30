// https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int cnt1 = 0, cnt2 = 0;
        for (auto it : s) {
            if (it == 'R') {
                cnt1++;
            } else {
                cnt2++;
            }
            if (cnt1 == cnt2 and cnt1) {
                ans++;
                cnt1 = cnt2 = 0;
            }
        }
        return ans;
    }
};