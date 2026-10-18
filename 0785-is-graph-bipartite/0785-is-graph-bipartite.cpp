class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        // disconnect graph handled.
        for(int src = 0; src< graph.size(); src++){
            if(color[src] != -1) continue;
            queue<int> q;

            q.push(src);
            color[src] = 0;
            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(int i: graph[curr]){
                    if(color[i] != -1){
                        if (color[curr] == color[i]) return false;
                    }
                    else{
                        color[i] = 1 - color[curr]; q.push(i);
                    }
                }
            }
        }
        return true;
    }
};