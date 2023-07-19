
#include<bits/stdc++.h>
using namespace std;

int dfs_timer = 0;

void dfs(int vertex, vector<vector<int>>&graph ,bool visited[], int enter[], int exit[]){

    visited[vertex] = true;
    enter[vertex] = dfs_timer++;

    for(int child: graph[vertex]){
        if(visited[child] == true) continue; //ignore the case

        dfs(child,graph,visited,enter,exit);
    }

    exit[vertex] = dfs_timer++;
}

int main(){

    int n,m;// n= number of nodes
            //m = number of edges

    cin>>n>>m;

    vector<vector<int>> graph(n); // 0-based graph

    for(int i=0; i<n; i++){
        int x,y;

        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x); //for directed graphs, only one pushback needed
    }

    bool visited[n];
    int enter_time[n]={0};
    int exit_time[n]={0};

    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    dfs(0,graph,visited,enter_time,exit_time);


    for(int i=0; i<n; i++){
        cout<<i<<" : "<<"enter_time = "<<enter_time[i]<<" exit_time = "<<exit_time[i]<<" duration = "<<
        exit_time[i] - enter_time[i]<<endl;
    }



return 0;
}