#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;

class item {
public:
    double weight;   // น้ำหนักที่เหลือ
    double value;    // ค่าที่เก็บมาแล้ว
    int idx;         // index ของ item ปัจจุบัน (เริ่มจาก n, นับถอยหลัง)
    double priority; // value + heuristic

    item(double w, double v, int i, double p) : weight(w), value(v), idx(i), priority(p) {}
};

class Compare {
public:
    bool operator()(const item& a, const item& b) {
        return a.priority < b.priority;
    }
};

// heuristic function (คำนวณ upper bound)
double heuristic(const vector<vector<double>>& items, int idx, double weight, double value) {
    double total = value;
    double w = weight;
    for (int i = idx; i > 0; i--) {
        if (w >= items[i][2]) {
            w -= items[i][2];
            total += items[i][1];
        } else {
            total += items[i][0] * w;
            break;
        }
    }
    return total;
}

int main() {
    int n;
    double W;
    cin >> W >> n;

    vector<vector<double>> items(n + 1, vector<double>(3)); // [0] = ratio, [1] = value, [2] = weight
    for (int i = 1; i <= n; i++) {
        cin >> items[i][1]; // value
    }
    for (int i = 1; i <= n; i++) {
        cin >> items[i][2]; // weight
        items[i][0] = items[i][1] / items[i][2]; // value/weight
    }

    sort(items.begin() + 1, items.end());

    priority_queue<item, vector<item>, Compare> pq;
    double init_heuristic = heuristic(items, n, W, 0);
    pq.emplace(W, 0, n, init_heuristic);

    double answer = 0;

    while (!pq.empty()) {
        item current = pq.top();
        pq.pop();

        if (current.weight < 0) continue;

        if (current.idx == 0) {
            answer = max(answer, current.value);
            break;
        }

        if (current.priority <= answer) continue;

        int i = current.idx;

        if (current.weight >= items[i][2]) {
            double new_w = current.weight - items[i][2];
            double new_val = current.value + items[i][1];
            double new_priority = heuristic(items, i - 1, new_w, new_val);
            if (new_val > answer){
                answer = new_val;
            }
            pq.emplace(new_w, new_val, i - 1, new_priority);
        }

        double new_priority = heuristic(items, i - 1, current.weight, current.value);
        pq.emplace(current.weight, current.value, i - 1, new_priority);
    }

    cout << fixed << setprecision(4) << answer << endl;
    return 0;
}
