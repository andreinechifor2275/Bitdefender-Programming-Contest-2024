#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long durataMinima(vector<long long>& trenuri) {
    long long durata = 0;
    priority_queue<long long, vector<long long>, greater<long long>> lg(trenuri.begin(), trenuri.end());
    long long l1, l2;
    while (lg.size() > 1)
    {
        l1 = lg.top(); lg.pop();
        l2 = lg.top(); lg.pop();
        durata += (l1 + l2);
        lg.push(l1 + l2);
    }
    return durata;
}

int main() {
    int N;
    cin >> N;

    vector<long long> lungimi(N);
    for (int i = 0; i < N; i++) {
        cin >> lungimi[i];
    }

    long long durata = durataMinima(lungimi);
    cout << durata << endl;

    return 0;
}