// below is the implementation of basic bfs
const int INF= 1e9+10;
int vis[100000];
vll g[100000];
vll level(100000);
void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        int cur_v=q.front();
        q.pop();
        for(auto &child : g[cur_v]){
            if(vis[child])continue;
            q.push(child);
            level[child]=level[cur_v] + 1LL;
            vis[child]=1;
        }
    }
}
//basic bfs ends