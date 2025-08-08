#include<iostream>
#include<vector>

using namespace std;

int DFS(vector<vector<int>> graph, int start, vector<int> &vis, int Pnode){
    vis[start] = Pnode;

    for (auto it : graph[start]){
        if (vis[it] == -1){
            if (!DFS(graph, it, vis, !Pnode))
                return false;
        }
        else if (vis[it] == vis[start]){
            return false;
        }
    }

    return true;
}


bool isBipartite(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> vis(n, -1);

    for (int i = 0; i < n; i++){
        if (vis[i] == -1){
            if (!DFS(graph, i, vis, 0))
                return false;
        }
    }

    return true;
}


int main(){
    vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};

    int ans = isBipartite(graph);
    cout<<ans<<endl;
    // ans -> false
}