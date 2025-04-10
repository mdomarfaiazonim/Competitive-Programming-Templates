const ll INF = 1e17;
int vis[100000];
const ll N = 1e5 + 5;
vll dist(N, INF);
vector<pair<ll, ll>> g[N];
void dijikistra()
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 1});
    // set<pair<ll, ll>> st;
    // st.insert({0, 1});
    dist[1] = 0;
    while (!q.empty())
    {
        // auto it = st.begin();
        int cur = q.top().S;
        q.pop();
        if (vis[cur])
            continue;
        vis[cur] = 1;
        for (auto &child : g[cur])
        {
            if (dist[child.F] > dist[cur] + child.S)
            {
                dist[child.F] = dist[cur] + child.S;
                q.push({dist[child.F], child.F});
            }
        }
    }
}