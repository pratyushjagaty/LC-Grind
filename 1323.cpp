// https://leetcode.com/problems/maximum-69-number/

class Solution {
public:
    int maximum69Number (int num) {
        int maxi = num;
        int cntDigits = 0;
        int temp = num;
        
        while (temp) {
            cntDigits++;
            temp /= 10;
        }
        
        for (int i = 0; i < cntDigits; i++) {
            string s = to_string(num);
            if (s[i] == '9') {
                s[i] = '6';
            } else if (s[i] == '6') {
                s[i] = '9';
            }
            temp = 0;
            for (int j = 0; j < cntDigits; j++) {
                temp = temp * 10 + (s[j] - '0');
            }
            maxi = max(maxi, temp);
        }
        
        return maxi;
    }
};