/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 * Actual space required by the tree = 2*2^ceil(log_2(n)) - 1
 */

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#include<string.h>
#include<math.h> 

#define N (int)(1e5+1)
#define inf 1e17

// ll arr[N];
ll tree[N*4];
ll lazy[N*4];

/**
 * Build and init tree
 */
void build_tree(ll node, ll a, ll b,vector<ll> &arr) {
    if(a > b) return; // Out of range
    
    if(a == b) { // Leaf node
            tree[node] = arr[a]; // Init value
        return;
    }
    
    build_tree(node*2, a, (a+b)/2,arr); // Init left child
    build_tree(node*2+1, 1+(a+b)/2, b,arr); // Init right child
    
    tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(ll node, ll a, ll b, ll i, ll j, ll value) {
  
    if(lazy[node] != 0) { // This node needs to be updated
        tree[node] += lazy[node]; // Update it

        if(a != b) {
            lazy[node*2] += lazy[node]; // Mark child as lazy
                lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }

        lazy[node] = 0; // Reset it
    }
  
    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;
    
    if(a >= i && b <= j) { // Segment is fully within range
            tree[node] += value;

        if(a != b) { // Not leaf node
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }

            return;
    }

    update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

    tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
ll query_tree(ll node, ll a, ll b, ll i, ll j) {
    
    if(a > b || a > j || b < i) return -inf; // Out of range

    if(lazy[node] != 0) { // This node needs to be updated
        tree[node] += lazy[node]; // Update it

        if(a != b) {
            lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }

        lazy[node] = 0; // Reset it
    }

    if(a >= i && b <= j) // Current segment is totally within range [i, j]
        return tree[node];

    ll q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
    ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    ll res = max(q1, q2); // Return final result
    
    return res;
}

int main() {

    // build_tree(1, 0, N-1,arr);

    // memset(lazy, 0, sizeof lazy);
    
}