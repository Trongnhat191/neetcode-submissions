class Solution {
public:


    void solve(vector<vector<int>> &res, vector<int>&nums, vector<int>&tmp, int k, int pos){
        if (tmp.size() == k){
            res.push_back(tmp);
            return;
        }
        for (int i= pos; i< nums.size(); i++){
            if (i> pos && nums[i] == nums[i-1]) {
                continue;
            }
            tmp.push_back(nums[i]);
            solve(res, nums, tmp, k, i+1);
            tmp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        res.push_back(tmp);

        for (int i = 1; i<= nums.size(); i++){
            solve(res, nums, tmp, i, 0);

        }
        

        return res;
    }
};
