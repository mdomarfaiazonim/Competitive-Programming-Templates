struct DSU {
    vector<int> par, sz,tm;
    DSU(int n):par(n+1), sz(n+1,1),tm(n+1,0) {
      iota(par.begin(), par.end(), 0);
    }
   
    int find(int v) {
      return par[v]==v?v:(par[v]=find(par[v]));
    }
   
    void unite(int u, int v){
      u=find(u), v=find(v);
      if(u!=v){
        if(sz[u]<sz[v]) {
          swap(u, v);
        }
        par[v]=u;
        sz[u]+=sz[v];
        tm[u]=max(tm[u],tm[v]);
      }
    }
   
    int size(int v) {
      return sz[find(v)];
    }
   
    bool same_set(int u, int v) {
      return find(u)==find(v);
    }
  };