#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Recursive Functions
void dfs(vector<vector<int>>& AdjacencyList , vector<int>& ans , int startNode ,vector<bool>& visited){
    visited[startNode] = 1;
    ans.push_back(startNode);
    for(int i = 0 ; i < AdjacencyList[startNode].size() ; i ++){
        int node = AdjacencyList[startNode][i];
        if(!visited[node]){
            dfs(AdjacencyList , ans , node , visited);
        }
    }
}

void solveBfs(vector<vector<int>>& AdjacencyList , queue<int>& q , vector<int>& ans , vector<bool>& visited){
    if(q.empty()){
        return ;
    }
    int temp = q.front();
    q.pop();
    ans.push_back(temp);
    for(int i = 0 ; i < AdjacencyList[temp].size() ; i ++){
        int node = AdjacencyList[temp][i];
        if(!visited[node]){
            q.push(node);
            visited[node] = 1;
        }
    }
    solveBfs(AdjacencyList , q , ans , visited);
}

void bfs(vector<vector<int>>& AdjacencyList , vector<int>& ans , int startNode , vector<bool>& visited){
    queue<int> q;
    visited[startNode] = 1;
    q.push(startNode);
    while(!q.empty()){
        solveBfs(AdjacencyList , q , ans , visited);
    }
}
void print(vector<int> ans){
    for(auto it : ans){
        cout << it << " ";
    }cout << endl;
}
int main(){
    // Creation of Adjacency List
    
    vector<int>bfsTraversal;

    vector<int>dfsTraversal;

    int vertices , edges;

    vector<bool>visitedDfs(vertices , 0);

    vector<bool>visitedBfs(vertices , 0);

    cout << "Enter Vertices and Edges\n";
    cin >> vertices >> edges;
    vector<vector<int>> AdjacencyList(vertices);

    int u , v;
    for(int i = 0 ; i < edges ; i ++){
        cout << "Enter endpoints of edges\n";
        cin >> u >> v;
        AdjacencyList[u].push_back(v);
        AdjacencyList[v].push_back(u);
    }
// example Adjacency List:
    /*
    0 -> 1
    1 -> 0 , 2 , 4
    2 -> 1 , 3 , 6
    3 -> 2 , 4 , 5
    4 -> 1 , 7 , 3
    5 -> 3 , 8
    6 -> 2
    7 -> 4
    8 -> 5
    
    */
    dfs(AdjacencyList , dfsTraversal , 0 , visitedDfs);
    cout << "DFS: " << " ";
    print(dfsTraversal);

    bfs(AdjacencyList , bfsTraversal , 0 , visitedBfs);
    cout << "BFS: " << " ";
    print(bfsTraversal);


    return 0;
}