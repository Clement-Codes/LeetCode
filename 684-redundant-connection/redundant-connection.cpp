class Solution {
public:

    int find(int i, int parent[]){
        int res = parent[i];
        while (res != parent[res]){
            parent[res] = parent[parent[res]];
            res = parent[res];
        }
        return res;
    }


    bool unions(int i, int j, int parent[], int rank[]){
        i = find(i, parent);
        j = find(j, parent);
        if (i == j) return false;
        if (rank[i] >= rank[j]){
            rank[i] += rank[j];
            parent[j] = i;
        }
        else{
            rank[j] += rank[i];
            parent[i] = j;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int parent[edges.size() + 1];
        int rank[edges.size() + 1];

        for (int i = 0; i <= edges.size(); i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        for (auto edge: edges)
            if (!unions(edge[0], edge[1], parent, rank)) return edge;
        
        return vector<int>();
    }
};