class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // initial approach, thought of finding maxPile then for loop till maxPile, but this will make the O(n);
        // better approach of apply binary search from the very start;

        int left = 1;
        int right = 1000000000;

        while(left <= right){
            int mid = left + (right - left) /2;
            if ( canEat(piles, mid, h)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
    bool canEat(vector<int>& piles, int k, int h){
        long hours =0; // overflow error
        for(int pile: piles){
            int div = pile / k;
            hours += div;
            if(pile % k) hours++;
        }
        return hours <= h;
    }
};