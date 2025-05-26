
//  In a eular path, every edge must be visited exactly once.
//  An Eulerian cycle exists if and only if the degrees of all vertices are even. 
// And an Eulerian path exists if and only if the number of vertices with odd degrees is two (or zero, in the case of the existence of a Eulerian cycle).
// In addition, of course, the graph must be sufficiently connected (i.e., if you remove all isolated vertices from it, you should get a connected graph).
// A Eulerian path is a path in a graph that passes through all of its edges exactly once. A Eulerian cycle is a Eulerian path that is a cycle.
// The problem is to find the Eulerian path in an undirected multigraph with loops.


vector<vector<pair<int,int>>>adj(N);
vector<int> eular_path(int st){
  // vector<iterator>itr(nodes);
  vector<vector<pair<int,int>>::iterator> itr(nodes);
  for(int i=0;i<nodes;i++)itr[i]=adj[i].begin();
  bool used[n]={0};
  vector<pair<int,int>>vp;
  vp.push_back({st,-1});

  vector<int>ans;

  int lst=-1;

  while(!vp.empty()){
    int cur=vp.back().first;

    auto &it=itr[cur];
    while(it!=adj[cur].end() && used[it->second])it++;

    if(it==adj[cur].end()){
      if(vp.back().second!=-1) ans.push_back(vp.back().second);
      vp.pop_back();

      if(lst!=-1 && lst!=cur)return {};

      if(vp.size())lst=vp.back().first;
    }else{
      vp.push_back(*it);
      used[it->second]=1;
    }
  }
  if(ans.size()!=n)return {};
  return ans;
}