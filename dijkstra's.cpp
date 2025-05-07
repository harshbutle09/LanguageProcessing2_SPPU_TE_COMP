// Time Complexity O(V^2)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // make adjacency list
        vector<vector<pair<int , int>>> AdjacencyList(V);
        
        for(int i = 0 ; i < edges.size() ; i ++){
            pair<int , int> p = make_pair(edges[i][1] , edges[i][2]);
            AdjacencyList[edges[i][0]].push_back(p);
        } 
        // create distance and visited vectors
        vector<int>distance(V , INT_MAX);
        vector<bool>visited(V , 0);
        distance[src] = 0;
        
        int count = V;
        
        while(count --){
        int node = -1;
        int mini = INT_MAX;
        // find that node which is not visited and has the minimum distance 
        // from the starting node
        for(int i = 0 ; i < V ; i ++){
            if(!visited[i] && mini > distance[i]){
                node = i;
                mini = distance[i];
            }
        }
        
        // mark that node as visited
        visited[node] = 1;
        // explore all it's neighbours and relax their edges
        for(int i = 0 ; i < AdjacencyList[node].size() ; i ++){
            int temp = AdjacencyList[node][i].first;
            int weight = AdjacencyList[node][i].second;
            if(!visited[temp] && distance[temp] > distance[node] + weight){
                distance[temp] = distance[node] + weight;
            }
        }
        // repeat steps for all the vertices 
        }
        return distance;
        
    
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
