class Solution {
    vector<int> Father;
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
public:
    int findFather(int x) {
        if(x != Father[x]) Father[x] = findFather(Father[x]);
        return Father[x];
    }
    void un(int x, int y) {
        x = Father[x]; y = Father[y];
        if(x < y) Father[y] = x;
        else Father[x] = y;
    }
    int mst(int n, vector<vector<int>>& edges, int idx) {
        Father.resize(n);
        for(int i = 0; i < n; ++i)
            Father[i] = i;
        int ret = 0;
        for(int i = 0; i < edges.size(); ++i) {
            if(i == idx) continue;
            int a = edges[i][0]; int b = edges[i][1];
            if(findFather(a) != findFather(b)) {
                un(a, b);
                ret += edges[i][2];
            }
        }
        
        for(int i = 0; i < n; ++i)
            if(findFather(i)!=Father[1]) return INT_MAX;
                
        return ret;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        unordered_set<int> Set1;
        unordered_set<int> Set2;
        for (int i=0; i<edges.size(); i++)
            edges[i].push_back(i);
        
        sort(edges.begin(), edges.end(), cmp);
        int minWt = mst(n, edges, -1);
   
        
        
        for(int i = 0; i < edges.size(); ++i){
            int newMstSize = mst(n,edges,i);
            if(newMstSize > minWt) Set1.insert(edges[i][3]);
        }
        for(int i = 0; i < edges.size(); ++i) {
            auto edge = edges[i];
            edges.insert(edges.begin(), edge);    
            int wt = mst(n, edges, -1);
            if (wt == minWt && Set1.find(edge[3]) == Set1.end()) Set2.insert(edge[3]);            
            edges.erase(edges.begin());
        }

        vector<int> ret1(Set1.begin(), Set1.end());
        vector<int> ret2(Set2.begin(), Set2.end());
    
        return {ret1, ret2};
        
    }
};