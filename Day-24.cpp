class Solution {
public:
    void dfs(vector<vector<int>>& graph, int src, int dest, vector<vector<int>>& res, vector<int>& temp)
    {
        temp.push_back(src);
        if(src==dest)
            res.push_back(temp);
        else
            for(int i=0; i<graph[src].size(); i++)
                dfs(graph, graph[src][i], dest, res, temp);
        
        temp.pop_back();
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(graph, 0, graph.size()-1, res, temp);
        return res;
    }
};
