class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach= 0;
        int curReach = nums[0];
        int i = 0;

        while (i<= curReach){
            maxReach = max(maxReach, nums[i]+ i);
            if (maxReach >= nums.size()-1) return true;
            i++;
            if (i>  maxReach){
                return false;
            }
            curReach = maxReach;
        }
        return true;

    }
};
