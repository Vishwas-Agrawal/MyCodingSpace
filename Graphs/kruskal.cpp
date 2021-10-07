#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
int rankA[MAXN];
int parent[MAXN];
void make_set(int v)
{
    parent[v] = v;
    rankA[v] = 0;
}
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rankA[a] < rankA[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        if (rankA[a] == rankA[b])
        {
            rankA[a]++;
        }
    }
}
int main(){
  int n,m,a,b,wt;
  cin>>n>>m;
  vector<pair<int,pair<int,int>>> graph;
  for(int i=0; i<m; i++){
    cin>>a>>b>>wt;
    graph.push_back({wt,{a,b}});
  }
  sort(graph.begin(),graph.end());
  for(int i=0; i<=n; i++){
    make_set(i);
  }
  int mstwt = 0;
  for(int i=0; i<m; i++){
     a = graph[i].second.first,b = graph[i].second.second,wt = graph[i].first;
     a = find_set(a);
     b = find_set(b);
     if(a!=b){
       mstwt+=wt;
       union_sets(a,b);
     }    
  }
  cout<<mstwt<<endl;

  return 0;
}
