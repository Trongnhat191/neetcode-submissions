class Solution {
public:
    bool check(int target, int ucv){
        if (target>=ucv){
            return true;
        }
        return false;
    }

    void solve(vector<int> &nums, int target, int k, vector<vector<int>> &res, vector<int> &tmp){
        for (int i = k; i< nums.size(); i++){
            if (check(target, nums[i])){
                tmp.push_back(nums[i]);
                target-= nums[i];
                
                if (target==0) {
                    res.push_back(tmp);
                }
                else {
                    solve(nums, target, i, res, tmp);
                }
                tmp.pop_back();
                target+=nums[i];
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        solve(nums,  target,  0, res, tmp);
        return res;
    }
};
