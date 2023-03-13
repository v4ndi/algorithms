#include <iostream>
#include <vector>
using namespace std;

unsigned int greatest_common_divisor(unsigned int a, unsigned int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return greatest_common_divisor(a % b, b);
    return greatest_common_divisor(a, b % a);
}

int n;
int a[100000];     
int tree[400004];  

void build_tree(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];    
    }
    else {
       
        int tm = (tl + tr) / 2;
        build_tree(v * 2, tl, tm);
        build_tree(v * 2 + 1, tm + 1, tr);
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
    }
}


int get_sum(int l, int r, int v, int tl, int tr) {
   
    if (l <= tl && tr <= r) {
        return tree[v];
    }

    
    if (tr < l || r < tl) {
        return 0;
    }

    int tm = (tl + tr) / 2;
    return max(get_sum(l, r, v * 2, tl, tm), get_sum(l, r, v * 2 + 1, tm + 1, tr));
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
    tree[v] = max(tree[v * 2] , tree[v * 2 + 1]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build_tree(1, 0, n - 1);

    int k = 0;
    cin >> k;

    vector<int> ans;
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
            update(idx, val, 1, 0, n - 1);
        }

        
    }

    for (auto& it : ans) {
        cout << it << " ";
    }
}