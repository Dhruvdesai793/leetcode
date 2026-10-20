class Solution {
public:
   int possible(vector<int>&bloomDay,int day, int m,int k){
    

       int bouquets = 0;
       int flowers = 0;

       for(int i = 0; i<bloomDay.size(); i++){
           if(bloomDay[i]<= day){
                flowers++;

                if(flowers ==k){
                    bouquets++;
                    flowers = 0;

                }
           }else{
               flowers = 0;

           }
           
       }
       return bouquets>=m;
      
   }
    int minDays(vector<int>& bloomDay, int m, int k) {

        long long val = m * 1LL * k * 1LL;
        if (val > bloomDay.size())
            return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini, high = maxi;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};