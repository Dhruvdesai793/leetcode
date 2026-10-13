class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqCounter;
        for(int num: nums){
            freqCounter[num]++;
        }

        int maxFrequency = 0;
        for(auto entry: freqCounter){
            maxFrequency = max(maxFrequency, entry.second);
        }

        int maxElements = 0;
        for(auto entry: freqCounter){
            if(entry.second == maxFrequency) maxElements++;
        }

        return maxFrequency * maxElements;
    }
};