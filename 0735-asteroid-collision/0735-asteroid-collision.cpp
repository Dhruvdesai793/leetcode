class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        stack<int> s;
        for(int i: asteroids){
            if(i>0) s.push(i);
            else{
                while(!s.empty() && s.top() > 0 && s.top() < -i){
                    s.pop();
                }

                if(s.empty() || s.top() < 0) s.push(i); 
                if(!s.empty() && s.top() == -i) s.pop();
                    
            }
        }

        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};