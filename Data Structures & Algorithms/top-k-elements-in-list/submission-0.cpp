class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> counts;
        vector<vector<int>> buckets(n+1);

        for (int i = 0; i<n; i++){
            counts[nums[i]] ++;
        }

        for (auto &pair:counts){
            int num= pair.first;
            int freq = pair.second;
            buckets[freq].push_back(num);
        }

        vector<int> res;

        for (int i = n; i>=0; i--){
            for (int num: buckets[i]){
                res.push_back(num);
                if (res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};
