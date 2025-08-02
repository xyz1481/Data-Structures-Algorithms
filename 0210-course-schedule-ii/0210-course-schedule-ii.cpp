class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> ans,indegree(numCourses,0);
        queue<int> q;
        int n = prerequisites.size();
        //creating adjList and keeping track of indegree
        for(auto it : prerequisites){
            adjList[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        } 

        //topo sort
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        //applying bfs 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto adjNode : adjList[node]){
                    indegree[adjNode]--;
                    if(indegree[adjNode]==0) q.push(adjNode);
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans; 
    }
};