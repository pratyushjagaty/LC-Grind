// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        int ans = -1;
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            
            if (nums[mid] == target) {
                ans = mid;
                break;
            } else if (nums[mid] >= nums[lo]) {
                if (target >= nums[lo] and target <= nums[mid]) {
                    hi = mid - 1;
                } else{
                    lo = mid + 1;
                }
            } else {
                if (target >= nums[mid] and target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        
        return ans;
    }
};

// idea is to search in the sorted part
// trim the array depending on the target