#include <iostream>
#include <vector>
#include <limits.h>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
public: 
    map<char, map<char, int>> adjList; 

    void addEdge(char u, char v, int weight) {
        adjList[u][v] = weight;
        adjList[v][u] = weight;
    }

    pair<int, vector<char>> dijkstra(char start, char end) {
        map<char, int> distances;
        map<char, char> previous;
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> nodes;

        for (auto vertex : adjList) {
            distances[vertex.first] = (vertex.first == start) ? 0 : INT_MAX;
            nodes.push({distances[vertex.first], vertex.first});
        }

        while (!nodes.empty()) {
            char current = nodes.top().second;
            nodes.pop();

            if (current == end) {
                vector<char> path;
                int total_cost = distances[current];
                while (previous.find(current) != previous.end()) {
                    path.push_back(current);
                    current = previous[current];
                }
                path.push_back(start);
                reverse(path.begin(), path.end());
                return {total_cost, path};
            }

            if (distances[current] == INT_MAX) {
                break;
            }

            for (auto neighbor : adjList[current]) {
                char neighborNode = neighbor.first;
                int weight = neighbor.second;
                int alternative = distances[current] + weight;

                if (alternative < distances[neighborNode]) {
                    distances[neighborNode] = alternative;
                    previous[neighborNode] = current;
                    nodes.push({alternative, neighborNode});
                }
            }
        }
        return {INT_MAX, vector<char>()};
    }
};

int main() {
    Graph g;

    g.addEdge('A', 'B', 10);
    g.addEdge('A', 'E', 3);
    g.addEdge('E', 'B', 1);
    g.addEdge('E', 'C', 4);
    g.addEdge('B', 'C', 2);
    g.addEdge('C', 'D', 2);
    g.addEdge('B', 'D', 7);

    char start, end;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter end node: ";
    cin >> end;

    auto result = g.dijkstra(start, end);
    int cost = result.first;
    vector<char> path = result.second;

    if (cost == INT_MAX) {
        cout << "No path exists from " << start << " to " << end << endl;
    } else {
        cout << "The shortest path cost from " << start << " to " << end << " is: " << cost << endl;
        cout << "The path is: ";
        for (char node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
