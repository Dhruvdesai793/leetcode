class Solution {
public:
    int firstUniqChar(string s) {
        int res = -1;
        unordered_map<char, int> mp;
        queue<char> q;

        for(char &ch : s){
            mp[ch]++;
            q.push(ch);
        }

        while(!q.empty()){
            char c = q.front();
            if(mp[c]>1){
                q.pop();
            }else break;
        }
        if (q.empty()) return -1;

        for(int i = 0; i<s.size(); i++){
            if (s[i] == q.front()) return i;
        }

        return -1;
    }
};