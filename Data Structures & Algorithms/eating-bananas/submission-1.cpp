class Solution {
public:
    bool canEatAll(vector<int>& piles, int h, int k){
        int sumHour=0;
        for (int pile : piles){
            sumHour += (pile-1)/k +1;
        }
        return (sumHour <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low= 1;
        int high = 0;

        for (int pile :piles){
            high = max(high, pile);
        }

        int res = high;

        while (low <= high){
            int mid = (low+high) /2;
            if (canEatAll(piles, h, mid)){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return res;
    }
};
