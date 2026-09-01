class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& vis) {
        vis[city] = true;

        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            if (isConnected[city][i] == 1 && !vis[i]) {

                dfs(i, isConnected, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int count = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(i, isConnected, vis);
            }
        }
        return count;
    }
};