class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mirror;

        for (int i = 0; i< nums.size(); i++){
            mirror[nums[i]]= i;
        }

        for (int i =0 ; i<nums.size(); i++){
            int diff = target-nums[i];

            if (mirror.count(diff) && mirror[diff] != i){
                return {i, mirror[diff]};
            }
        }
        return {};
    }
};
