#include<iostream>
#include<vector>
#include<set>

const int inf = (1 << 31) - 1;

int main() {
    int n = 0, s = 0, f = 0;
    std::cin >> n >> s >> f;
    s--, f--;
    std::vector<std::vector<std::pair<int, int> > > g(n);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            int w = 0;
            std::cin >> w;
            if (w == -1 || i == j) {
                continue;
            }
            g[i].push_back({ j, w });
        }
    }
    std::vector<int> r(n, inf);
    r[s] = 0;
    std::set<std::pair<int, int>> st; 
    st.insert({ 0, s });
    while (!st.empty()) {
        int from = st.begin()->second;
        st.erase(st.begin());
        for (auto p : g[from]) {
            int to = p.first;
            int w = p.second;
            if (r[from] + w < r[to]) {
                if (r[to] != inf) {
                    st.erase({ r[to], to });
                }
                r[to] = r[from] + w;
                st.insert({ r[to], to });
            }
        }
    }
    if (r[f] != inf) {
        std::cout << r[f];
    }
    else {
        std::cout << -1;
    }


    return 0;
}