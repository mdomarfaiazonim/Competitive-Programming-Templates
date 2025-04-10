const ll N=1e6;
vector<ll>g[N];
bool vis[N];
void dfs(int ver){
    //Take action on vertex after entering the vertex
    for(int child : g[ver]){
        //Take action on child before entering the child node.
        dfs(child);
        //Take action on child after exiting the child node.
        /*
        example : cnt[ver]+=cnt[child]
        */
    }
    //Take action on vertex before exiting the vertex
}