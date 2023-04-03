#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>

using namespace std;

int m(char a, char b) {
    if (a == b) {
        return 0;
    }
    else {
        return 1;
    }
}

int levinshtain(string str_a, string str_b) {
    int n_a = str_a.size();
    int n_b = str_b.size();

    vector<vector<int>> dp(n_a + 1, vector<int>(n_b + 1));

    for (int i = 0; i < n_a + 1; i++) {
        for (int j = 0; j < n_b + 1; j++) {

            if (i == 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if (j == 0 && i > 0) {
                dp[i][j] = i;
                continue;
            }

            if (i == 0 && j > 0) {
                dp[i][j] = j;
                continue;
            }

            dp[i][j] = min({ dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + m(str_a[i - 1], str_b[j - 1]) });
        }
    }

    return dp[n_a][n_b];

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    string vxod = "";
    getline(cin, vxod);
    n = stoi(vxod);

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        string str_a = "", str_b = "";
        //cin >> str_a >> str_b;
        getline(cin, str_a);
        getline(cin, str_b);
        ans.push_back(levinshtain(str_a, str_b));
    }

    for (auto& it : ans) {
        cout << it << " ";
    }
    return 0;
}