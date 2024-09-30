class Solution {


    int find(int i, int[] parent){
        int res = i;
        while (res != parent[res]){
            parent[res] = parent[parent[res]];
            res = parent[res];
        }
        return res;
    }

    int unions(int i, int j, int[] parent, int[] rank){
        int ni = find(i, parent), nj = find(j, parent);
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

    public int countComponents(int n, int[][] edges) {
        int parent[] = new int[n];  
        int rank[] = new int[n];

        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        int result = n;

        for(int[] edge: edges){
            result -= unions(edge[0], edge[1], parent, rank);
        }

        return result;        
    }
}