// https://leetcode.com/problems/valid-parenthesis-string/

class Solution {
    int n;
    string s;
    int dp[105][105];
public:
    int f(int idx, int cnt) {
        if (cnt < 0) {
            return 0;
        }    
        
        if (idx == n) {
            return (cnt == 0);
        }
        
        if (dp[idx][cnt] != -1) {
            return dp[idx][cnt];
        }
        
        int ans = 0;
        
        if(s[idx] == '(') {
            ans |= f(idx + 1, cnt + 1);    
        } else if (s[idx] == ')') {
            ans |= f(idx + 1, cnt - 1);
        } else {
            ans |= f(idx + 1, cnt + 1);
            ans |= f(idx + 1, cnt - 1);
            ans |= f(idx + 1, cnt);
        }
        
        return dp[idx][cnt] = ans;
    }
    
    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        this->s = s;
        n = s.length();
        
        return f(0, 0);
    }
};