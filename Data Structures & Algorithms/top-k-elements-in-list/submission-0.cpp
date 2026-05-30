class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &p : mp) {
            int number = p.first;
            int frequency = p.second;
            bucket[frequency].push_back(number);
        }
        vector<int> ans;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};