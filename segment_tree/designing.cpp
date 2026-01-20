#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <iostream>

int a[100005] , seg[4 * 100005];

void build(int ind , int low , int high) {
    if(low == high) {
        // when at the leaf node when both are equal like (9 - 9) , (4 -4) etc...
        seg[ind] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    // left subtree
    build(2 * ind + 1 , 0 , mid);
    // right subtree
    build(2 * ind + 2 , mid + 1 , high);

    // taking the max of both the left subtree and the right subtree
    seg[ind] = max(seg[2 * ind + 1] , seg[2 * ind + 2]);
}

// now quering in the segmnt tree
int query(int ind , int low , int high , int l , int r) {
    // when it lies inside the interval
    if(l >= low && r <= high) {
        return seg[ind];
    }
    // If does not lies inside any interval
    if(high < l || low > r) return INT_MIN;
    int mid = (low + high) / 2;
    // if overlaps
    int left = query(2 * ind + 1 , low , mid , l , r);
    int right = query(2 * ind + 2 , mid + 1 , high , l , r);
    return max(left , right);
}

void pointUpdate(int ind , int low , int high , int node , int val) {
    if(low == high) {
        seg[ind] += val;
    } else {
        int mid = (low + high) / 2;
        if(node <= mid && node >= low) pointUpdate(2 * ind + 1 , low , mid , node , val);
        else pointUpdate(2 * ind + 2 , mid + 1 , high , node , val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
}

void rangeUpdate(int ind , int low , int high , int l , int r , int val) {
    if(lazy[ind] != -1) {
        seg[ind] += (high - low + 1) * lazy[ind];
        if(low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(r < low || l > high || low > high) return;
    if(low >= l && high <= r) {
        seg[ind] += (high - low + 1) * val;
        if(low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        return;
    }
    ind mid = (low + high) >> 1;
    rangeUpdate(2 * ind + 1 , low , mid , l , r , val);
    rangeUpdate(2 * ind + 2 , mid + 1 , high , l , r , val);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int querySumLazy(int ind , int low , int high , int l , int r , int val) {
    if(lazy[ind] != 0) {
        seg[ind] += (high - low + 1) * lazy[ind];
        if(low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(r < low || l > high || low > high) return 0;
    if(low >= l && high <= r) {
        return seg[ind];
    }
    int mid = (low + high) >> 1;
    return querySumLazy(2 * ind + 1 , low , mid , l , r , val)
          +querySumLazy(2 * ind + 2 , mid + 1 , high , l , r , val);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    build(0 , 0 , n - 1);
    int q;
    cin >> q;
    while(q--) {
        int l , r;
        cin >> l >> r;
        int ans = query(0 , 0 , n - 1 , l , r);
        cout << ans << endl;
    }
    return 0;
}