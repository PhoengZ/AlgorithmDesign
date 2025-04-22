#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n;
vector<vector<int>> g;
vector<vector<int>> d;
vector<pair<int, int>> v;
vector<int> color;
int ans;

void greedyColoring() {
    vector<int> result(n, -1);
    result[v[0].second] = 1;

    for (int i = 1; i < n; i++) {
        set<int> used;
        for (auto &e : d[v[i].second]) {
            if (result[e] != -1) {
                used.insert(result[e]);
            }
        }

        int cr = 1;
        while (used.find(cr) != used.end()) {
            cr++;
        }
        result[v[i].second] = cr;
    }
    
    ans = *max_element(result.begin(), result.end());
}

void backtrack(int node, int total, vector<int>& colorUsed) {
    if (total >= ans) return;

    if (node == n) {
        ans = min(ans, total);
        return;
    }

    int current = v[node].second;
    set<int> usedColors;
    for (auto &e : d[current]) {
        if (color[e] != 0) {
            usedColors.insert(color[e]);
        }
    }

    for (int cr = 1; cr <= total + 1; cr++) {
        if (usedColors.find(cr) == usedColors.end()) {
            color[current] = cr;
            int newTotal = max(total, cr);
            backtrack(node + 1, newTotal, colorUsed);
            color[current] = 0;
        }
    }
}

int main() {
    int e;
    cin >> n >> e;
    g.assign(n, vector<int>(n, 0));
    d.resize(n);
    color.assign(n, 0);
    v.resize(n);

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
        d[a].push_back(b);
        d[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        v[i] = {d[i].size(), i};
    }

    sort(v.rbegin(), v.rend());

    ans = n;
    greedyColoring();

    vector<int> colorUsed(ans + 1, 0);
    backtrack(0, 0, colorUsed);

    cout << ans << endl;
    return 0;
}