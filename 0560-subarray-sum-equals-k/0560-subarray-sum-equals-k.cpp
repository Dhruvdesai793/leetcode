class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // initial approach, sliding window failed at it
        // learned : SW ain't usable for very strict constraint like equals to k!

        //using PREFIX SUM
        int n = nums.size(); 
        
        int prefix[n]; 
        
        prefix[0] = nums[0]; // init
        
        for(int i = 1; i < n; i++)
        {
            prefix[i] = nums[i] + prefix[i - 1];
        }
        
        unordered_map<int,int> mp; 
        
        int ans = 0; 
        
        for(int i = 0; i < n; i++) // traverse prefix arr;
        {
            if(prefix[i] == k)
                ans++;
            
            // check for prefix[i] - k present in map
            if(mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k]; // yeah, increment;
            }
            
            mp[prefix[i]]++; // noope, then create one;
        }
        
        return ans; 
    }
};