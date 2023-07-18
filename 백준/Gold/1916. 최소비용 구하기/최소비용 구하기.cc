#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define INF 100000001

int N, M;
int X, Y, C;
int city[1001][1001];
int out[1001];

void dijkstra(int s) {
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, s));
    out[s] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if (out[cur] < distance) continue;

        for (int i = 1; i <= N; i++) {
            int next = city[cur][i];
            if (next == INF) continue;
            int nextDistance = distance + next;
            if (nextDistance < out[i]) {
                out[i] = nextDistance;
                pq.push(make_pair(-nextDistance, i));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    fill(&city[0][0], &city[1000][1000], INF);
    fill(out, out + 1001, INF);
    for (int i = 0; i < M; i++) {
        cin >> X >> Y >> C;
        if (city[X][Y] > C) city[X][Y] = C;
    }
    cin >> X >> Y;
    dijkstra(X);
    cout << out[Y];

    return 0;
}