class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0, nZero = 0;
        int n = nums.size();
        while (zero < n and nZero < n) {
            if (nums[nZero] and !nums[zero]) {
                swap(nums[zero], nums[nZero]);
                zero++;
                nZero++;
            }
            
            if (zero < n and nums[zero]) {
                zero++;
                nZero = zero;
            }
            
            if (nZero < n and !nums[nZero]) {
                nZero++;
            }
        }
    }
};