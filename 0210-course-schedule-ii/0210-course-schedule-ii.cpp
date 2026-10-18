class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // creating adj list;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto i : prerequisites){
            int dependency = i[1], course = i[0];
            
            adj[dependency].push_back(course);
            // we are counting ingoing edges i.e indegree;
            indegree[course]++;
        }
        queue<int> q;

        // finding  indegree = 0 and pushing them to q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> order; // list to store final result;
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            order.push_back(tmp);

            for(int v : adj[tmp]){
                if(--indegree[v] == 0) q.push(v);
            }

        }
        if (order.size() != numCourses) return {};
        return order;
    }
};