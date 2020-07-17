class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) 
    { 
        return a.second > b.second; 
    } 
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int num: nums)
            umap[num]++;
        
        vector<pair<int, int> > vect;
        
        for(auto& it : umap)
            vect.push_back(it); 
        
        sort(vect.begin(), vect.end(), cmp);
        
        vector<int> res;
        for(int i=0; i<k; i++)
            res.push_back(vect[i].first);
        
        return res;
    }
};
