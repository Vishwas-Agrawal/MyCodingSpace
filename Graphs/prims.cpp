#include <bits/stdc++.h>
using namespace  std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>> adj[n+1];
  int a,b,wt;
  for(int i=0; i<m; i++){
    cin>>a>>b>>wt;
    adj[a].push_back({b,wt});
    adj[b].push_back({a,wt});

  }
  int parent[n+1],key[n+1],mstSet[n+1];
  for(int i=0; i<=n; i++){
    key[i] = INT_MAX;
    mstSet[i] = false;
    parent[i] = -1;
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
  key[1] = 0;
  parent[1] = -1;
  pq.push({0,1});
  int mstweight = 0;
  while(!pq.empty()){
    
    cout<<"node "<<pq.top().second<<" weight "<<pq.top().first<<endl;
    
    int u = pq.top().second;
    int x  = pq.top().first;
    pq.pop();
    if(mstSet[u] == true){
      continue;
    }
    mstSet[u] =true;
    mstweight += x;
    for(auto it:adj[u]){
      int v= it.first;
      int weight = it.second;
      if(mstSet[v] == false && weight<key[v]){
        cout<<weight<<" "<<v<<endl;
        parent[v] = u,key[v] = weight;
        key[v] = weight;
        pq.push({key[v],v});
      }
    }
  }
  cout<<mstweight<<endl;
  for(int i=1; i<=n; i++){
    cout<<parent[i]<<"---"<<i<<"\n";
  }

  return 0;
}
