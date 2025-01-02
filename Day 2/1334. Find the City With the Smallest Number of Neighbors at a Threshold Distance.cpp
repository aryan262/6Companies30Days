class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans = -1;
        int mini = n;
        vector<vector<int>>dist = floydWarshall(n, edges, distanceThreshold);
        for (int i=0;i<n;++i) {
            int count=0;
            for (int j=0;j<n;++j){
                if (dist[i][j]<=distanceThreshold){
                    ++count;
                }
            }
            if (count<=mini){
                ans=i;
                mini=count;
            }
        }
        return ans;
    }

private:
    vector<vector<int>> floydWarshall(int n, const vector<vector<int>>& edges,
    int distanceThreshold){
        vector<vector<int>> dist(n, vector<int>(n, distanceThreshold+1));
        for (int i=0;i<n;++i){
            dist[i][i]=0;
        }
        for (vector<int> edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int k=0;k<n;++k){
            for (int i=0;i<n;++i){
                for (int j=0;j<n;++j){
                    dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        return dist;
    }
};
