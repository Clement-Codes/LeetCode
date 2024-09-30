class Solution {
public:
    vector<int> parent, rank;

    int find(int i){
        int res = i;
        while (res != parent[res]){
            parent[res] = parent[parent[res]];
            res = parent[res];
        }
        return res;
    }

    int unions(int i, int j){
        int ni = find(i), nj = find(j);
        if (ni == nj) return 0;
        if (rank[ni] >= rank[nj]){
            rank[ni] += rank[nj];
            parent[nj] = ni;
        }
        else{
            rank[nj] += rank[ni];
            parent[ni] = nj;
        }
        return 1;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        

        for(int i = 0; i < n; i++){
            parent.push_back(i);
            rank.push_back(1);
        }

        int result = n;

        for(vector<int> edge: edges){
            result -= unions(edge[0], edge[1]);
        }

        return result;
    }
};