ll find_set(ll v,vll &par,vll &sz) {
    if (v == par[v])
        return v;
    return par[v] = find_set(par[v],par,sz);
}
void make_set(ll v,vll &par,vll &sz) {
    par[v] = v;
    sz[v] = 1;
}

void union_sets(ll a, ll b,vll &par,vll &sz) {
    a = find_set(a,par,sz);
    b = find_set(b,par,sz);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}d