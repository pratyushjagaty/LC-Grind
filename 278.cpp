// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int idx = -1;
        long int lo = 1, hi = n;
        
        while (lo <= hi) {
            long int mid = lo + hi >> 1;
            if (isBadVersion(mid)) {
                idx = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return idx;
    }
};