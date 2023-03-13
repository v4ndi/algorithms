#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> tree;

void build(vector<int>& a, int v, int tl,int tr) {
    if (tl == tr) {
        tree[v].first = a[tl];
        tree[v].second = tl;
        return;
    }
    int mid = (tl + tr) / 2;
    build(a, v * 2, tl, mid);
    build(a, v * 2 + 1, mid + 1, tr);
    tree[v].first = max(tree[v * 2].first, tree[v * 2 + 1].first);
    if (tree[v * 2].first > tree[v * 2 + 1].first) {
        tree[v].second = tree[v * 2].second;
    }
    else {
        tree[v].second = tree[v * 2 + 1].second;
    }
}

pair<int,int> get_max(int v, int tl, int tr, int ql, int qr) {
    if (ql > qr)
        return make_pair(-1,-1);

    if (tl == ql && tr == qr)
    {
        return tree[v];
    }
    int mid = (tl + tr) / 2;
    return max(get_max(v * 2, tl, mid, ql, min(qr, mid)) , get_max(v * 2 + 1, mid + 1, tr, max(ql, mid + 1), qr));

}

int main()
{
    int n = 0;
    cin >> n;
    vector<int> vec(n);
    for (auto& it : vec) {
        cin >> it;
    }
    tree.resize(4 * n);
    build(vec, 1, 0, n - 1);

    int k = 0;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        pair<int, int> ans = get_max(1, 0, n - 1, l, r);
        std::cout << ans.first << " " << ans.second + 1 << " ";
    }
    
}