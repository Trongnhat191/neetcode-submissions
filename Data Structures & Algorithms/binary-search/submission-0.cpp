class Solution {
public:

    void solve(vector<int>& nums, int target, int & res, int begin, int end){
        int mid = (begin+end)/2;
        if (begin == end) {
            if (nums[mid] == target) res = mid;
            else return;
        }
        if (nums[mid] == target) {
            res = mid;
            return;
        }
        else {
            if (target< nums[mid]){
                solve(nums, target, res, 0, mid);
            }
            else solve(nums, target, res, mid+1, end);
        } 
    }

    int search(vector<int>& nums, int target) {
        int res = -1;
        solve(nums, target, res, 0, nums.size());
        return res;
    }
};
