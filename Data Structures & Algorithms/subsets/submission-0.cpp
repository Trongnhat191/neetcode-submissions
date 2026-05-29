class Solution {
public:

    void solve(vector<vector<int>> &res, vector<int>  &tmp, vector<int> &nums, int k, int pos){
        for (int i = pos; i< nums.size(); i++){
            tmp.push_back(nums[i]);

            if (tmp.size() == k){
                res.push_back(tmp);
            }
            else solve(res, tmp, nums, k, i+1);

            tmp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;

        res.push_back(tmp);
        for (int i = 1; i<= nums.size(); i++){
            solve(res, tmp, nums, i, 0);
        }
        return res;
    }
};
