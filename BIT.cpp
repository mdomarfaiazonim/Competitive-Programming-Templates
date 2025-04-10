void update(vll &BIT, int i, int val){
    ++i;
    while (i < BIT.size())
    {
        BIT[i] += val;
        i += lowetset(i);
    }
}
vll con(vll &v){
    vll BIT(v.size() + 1);
    for (int i = 0; i < v.size(); i++)update(BIT, i, v[i]);
    
    return BIT;
}
ll get(int ind, vll &BIT){
    ++ind;
    ll sum = 0;
    while (ind > 0){
        sum += BIT[ind];
        ind -= lowetset(ind);
    }
    return sum;
}