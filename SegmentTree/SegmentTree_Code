// max in a segment of array

#include <bits/stdc++.h>
using namespace std;

int a[200005],seg[4*200005];

void build(int idx, int low, int high) {
    if(low == high) {
        seg[idx] = a[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*idx+1,low,mid);
    build(2*idx+2,mid+1,high);
    seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
}

int query(int idx, int low, int high, int l, int r) {
    if(low >= l  && high <= r) {
        return seg[idx];
    }
    if(high < l || low > r) {
        return INT_MIN;
    }
    int mid = (low+high)/2;
    int left = query(2*idx+1,low,mid,l,r);
    int right = query(2*idx+2,mid+1,high,l,r);
    return max(left,right);
}

void update(int node, int start, int end, int idx, int val) {
    if(start == end) {
        a[idx] = val;
        seg[node] = val;
        return;
    }
    int mid = (start+end)/2;
    if(start <= idx && idx <= mid) {
        update(2*node+1, start, mid, idx, val);
    }
    else {
        update(2*node+2, mid+1, end, idx, val);
    }
    seg[node] = max(seg[2*node+1],seg[2*node+2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;

    for(int i = 0 ; i < m ;i++) {
        cin >> a[i];
    }

    build(0,0,m-1);


// Printing seg Tree (For Debugging)
    // for(int i = 0 ; i < 2*n-1 ; i++) {
    //     cout << seg[i] << " ";
    //     if(i == 0 || i == 2 || i == 6 || i == 14 || i == 30) {
    //         cout << "\n";
    //     }
    // }
    // cout << "\n";


    int q;
    cin >> q;
    while(q--) {
        int x1,x2;
        cin >> x1 >> x2;
        if(x1 > x2) {
            int temp = x1;
            x1 = x2;
            x2 = temp;
        }
        update(0,0,m-1,x1-1,15);
        cout << query(0,0,m-1,x1-1,x2-1) << "\n";
    }
    return 0;
}
