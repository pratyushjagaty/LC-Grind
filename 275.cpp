https : //leetcode.com/problems/h-index-ii/

class Solution
{
public:
    int hIndex(vector<int>& citations) {
        int lo = 0, hi = citations.size();
        int ans = -1;
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int lowestIndex = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
            
            //cout << lowestIndex << endl;
            
            if (citations.size() - lowestIndex >= mid) {
                ans = mid;
                lo = mid + 1;
            } else if (citations.size() - lowestIndex < mid) {
                hi = mid - 1;
            } 
        }
        
        return ans;
    }
};