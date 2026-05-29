class Solution {
public:

    void solve(vector<vector<int>> &res, vector<int> &tmp, vector<int> &nums, vector<bool> & mark){
        for (int i = 0; i< nums.size(); i++){
            if (mark[i] == true) continue;
            tmp.push_back(nums[i]);
            mark[i] = true;

            if (tmp.size() == nums.size()){
                res.push_back(tmp);
            }
            else solve(res, tmp, nums, mark);
            
            tmp.pop_back();
            mark[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> mark(nums.size(), false);

        solve(res, tmp, nums, mark);
        return res;
    }
};
