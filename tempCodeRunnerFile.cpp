#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
  int n,m; // n no. of nodes, m no. of edges
  cin>>n>>m;
  vector<int>adj[n];
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  int vis[n];
  for(int i=0;i<n;i++) vis[i]=-1;
  bool b=true;
  for(int i=0;i<n;i++){
    queue<int>q;
    if(vis[i]==-1){
      q.push(i);
      vis[i]=1;
      while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto j:adj[node]){
          if(vis[j]==-1){
            q.push(j);
            vis[j]=1-vis[node];
          }
          else if(vis[j]==vis[node]){
            b=false;
            break;
          }
        }
        if(!b) break;
      }
    }
  }
  if(b) cout<<"true";
  else cout<<"false";
}