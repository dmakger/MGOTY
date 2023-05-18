#include <iostream>
#include <vector>
#include <queue>

const int INF = 1e9;

void Dijkstra(const std::vector<std::vector<std::pair<int, int>>>& graph, int start, std::vector<int>& distances) {
    int n = graph.size();
    distances.assign(n, INF);
    distances[start] = 0;
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        
        if (dist > distances[u]) {
            continue;
        }
        
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (dist + weight < distances[v]) {
                distances[v] = dist + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;  // Количество вершин и рёбер
    
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        std::cin >> u >> v >> weight;  // Ввод ребра (u, v) с весом weight
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});  // Для неориентированного графа
    }
    
    int start;
    std::cin >> start;  // Вершина, из которой начинается поиск кратчайшего пути
    
    std::vector<int> distances;
    Dijkstra(graph, start, distances);
    
    // Вывод кратчайших расстояний от start до всех остальных вершин
    for (int i = 0; i < n; ++i) {
        std::cout << "Shortest distance from " << start << " to " << i << ": ";
        
        if (distances[i] == INF) {
            std::cout << "No path";
        } else {
            std::cout << distances[i];
        }
        
        std::cout << std::endl;
    }
    
    return 0;
}