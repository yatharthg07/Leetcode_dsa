#define ll long long
#define pii pair<ll, ll>

class Solution {
public:
    const int MODULO = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pii>> adjList(n);

        // Building the adjacency list
        for (const auto& road : roads) {
            ll u = road[0], v = road[1], duration = road[2];
            adjList[u].emplace_back(v, duration);
            adjList[v].emplace_back(u, duration);
        }

        return findShortestPaths(adjList, n, 0);
    }

private:
    int findShortestPaths(const vector<vector<pii>>& adjList, int n, int start) {
        vector<ll> distances(n, LLONG_MAX);
        vector<ll> pathCounts(n, 0);
        distances[start] = 0;
        pathCounts[start] = 1;

        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.emplace(0, start);

        while (!pq.empty()) {
            auto [currentDist, u] = pq.top();
            pq.pop();

            if (currentDist != distances[u]) continue;

            for (const auto& [v, travelTime] : adjList[u]) {
                if (distances[v] > currentDist + travelTime) {
                    distances[v] = currentDist + travelTime;
                    pathCounts[v] = pathCounts[u];
                    pq.emplace(distances[v], v);
                } else if (distances[v] == currentDist + travelTime) {
                    pathCounts[v] = (pathCounts[v] + pathCounts[u]) % MODULO;
                }
            }
        }

        return pathCounts[n - 1];
    }
};
