class Solution {
public:
    bool check(vector<int>& mark, int i, vector<int> & candidates, int target){
        if (mark[i] == true) return false;
        if (candidates[i] > target) return false;
        return true;
    }

    void solve(vector<vector<int>> &res, int k, vector<int> &res_tmp, vector<int> &candidates, int target, vector<int> &mark){
        for (int i = k; i<candidates.size(); i++){
            if (i>k && candidates[i] ==candidates[i-1]){
                continue;
            }
            if (check(mark, i, candidates, target)){
                res_tmp.push_back(candidates[i]);
                mark[i] = true;
                target -= candidates[i];

                if (target == 0){
                    res.push_back(res_tmp);
                }
                else solve(res, i+1, res_tmp, candidates, target, mark);

                res_tmp.pop_back();
                mark[i] = false;
                target+= candidates[i];

            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> res_tmp;
        vector<int> mark(candidates.size(), false);
        solve(res,0, res_tmp, candidates, target, mark);
        return res;
    }
};
