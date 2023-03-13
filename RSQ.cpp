#include <iostream>
#include <vector>

using namespace std;

uint64_t n;
uint64_t a[100000];
uint64_t tree[400004];


void build_tree(uint64_t v, uint64_t tl, uint64_t tr) {
    if (tl == tr) {
        tree[v] = a[tl];  
    }
    else {
        uint64_t tm = (tl + tr) / 2;
        build_tree(v * 2, tl, tm);
        build_tree(v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

uint64_t get_sum(uint64_t l, uint64_t r, uint64_t v, uint64_t tl, uint64_t tr) {
  
    if (l <= tl && tr <= r) {
        return tree[v];
    }

    if (tr < l || r < tl) {
        return 0;
    }

    uint64_t tm = (tl + tr) / 2;
    return get_sum(l, r, v * 2, tl, tm)
        + get_sum(l, r, v * 2 + 1, tm + 1, tr);
}


void update(int idx, int val, int v, int tl, int tr) {
    
    if (idx <= tl && tr <= idx) {    
        a[idx] = val;
        tree[v] = val;
        return;
    }

    if (tr < idx || idx < tl) {
        return;
    }

    int tm = (tl + tr) / 2;
    update(idx, val, v * 2, tl, tm);
    update(idx, val, v * 2 + 1, tm + 1, tr);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build_tree(1, 0, n - 1);

    int k = 0;
    cin >> k;

    vector<uint64_t> ans;
    for (int i = 0; i < k; i++) {

        char s;
        cin >> s;
        if (s == 's') {
            int l, r;
            cin >> l >> r;
            l--; r--;
            ans.push_back(get_sum(l, r, 1, 0, n - 1));
        }
        else {
            int idx, val;
            cin >> idx >> val;
            idx--;
            update(idx, val, 1, 0, n-1);
        }


    }

    for (auto& it : ans) {
        cout << it << " ";
    }
}