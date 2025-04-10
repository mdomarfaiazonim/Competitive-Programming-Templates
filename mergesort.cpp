ll merge(vll &v, vll &temp, ll l, ll mid, ll r)
{
    ll i = l, j = mid + 1, k = l, inv = 0;
    while (i <= mid && j <= r)
    {
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else
        {
            inv += mid - i + 1;
            temp[k++] = v[j++];
        }
    }
    while (i <= mid)
        temp[k++] = v[i++];

    while (j <= r)
        temp[k++] = v[j++];

    for (int it = l; it <= r; it++)
        v[it] = temp[it];
    return inv;
}
ll mergeSort(vll &v, vll &temp, ll l, ll r)
{
    ll inv = 0;
    if (l < r)
    {
        ll mid = (l + r) / 2;

        inv += mergeSort(v, temp, l, mid);
        inv += mergeSort(v, temp, mid + 1, r);
        inv += merge(v, temp, l, mid, r);
    }
    return inv;
}