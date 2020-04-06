// https://leetcode.com/problems/group-anagrams/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<pair<string, string>> strings;
        
        int i;
        
        for (i = 0; i < strs.size(); i++) {
            strings.push_back({strs[i], strs[i]});
            sort(strings[i].first.begin(), strings[i].first.end());
        }
        
        sort(strings.begin(), strings.end());
        
        i = 1;
        ans.push_back({strings[0].second});
        
        while (i < strings.size()) {
            if (strings[i].first == strings[i - 1].first) {
                ans[ans.size() - 1].push_back(strings[i].second);
            } else {
                ans.push_back({strings[i].second});
            }
            i++;
        }
        
        return ans;
    }
};