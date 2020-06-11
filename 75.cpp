class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = 0, idx = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                j = i + 1;
                while (j < nums.size() and nums[j]) {
                    j++;
                }
                if (j < nums.size()) {
                    swap(nums[i], nums[j]);
                }
            }
            if (!nums[i]) {
                idx = i;
            }
        }
        
        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] == 2) {
                j = i + 1;
                while (j < nums.size() and nums[j] == 2) {
                    j++;
                }
                if (j < nums.size()) {
                    swap(nums[i], nums[j]);
                }
            }
        }
        
    }
};