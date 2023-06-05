#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
class Graph {
private:
int numVertices;
vector<vector<int>>adjMatrix;
map<int, string> landmarks;
public:
Graph(int vertices) {
numVertices = vertices;
adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
}
void addEdge(int src, int dest) {
adjMatrix[src][dest] = 1;
adjMatrix[dest][src] = 1;
}
void addLandmark(int vertex, const string& landmark) {
landmarks[vertex] = landmark;
}
void printAdjMatrix() {
cout << "Adjacency Matrix:" << endl;
for (int i = 0; i < numVertices; i++) {
for (int j = 0; j < numVertices; j++) {
cout << adjMatrix[i][j] << " ";
}
cout << endl;
}
}
void printAdjList() {
cout << "Adjacency List:" << endl;
for (int i = 0; i < numVertices; i++) {
cout << landmarks[i] << ": ";
for (int j = 0; j < numVertices; j++) {
if (adjMatrix[i][j] == 1) {
cout << landmarks[j] << " ";
}
}
cout << endl;
}
}
void dfs(int vertex, vector<bool>& visited) {
visited[vertex] = true;
cout << landmarks[vertex] << " ";
for (int i = 0; i < numVertices; i++) {
if (adjMatrix[vertex][i] == 1 && !visited[i]) {
dfs(i, visited);
}
}
}
void performDFS(int startVertex) {
vector<bool> visited(numVertices, false);
cout << "DFS Traversal: ";
dfs(startVertex, visited);
cout << endl;
}
void performBFS(int startVertex) {
vector<bool> visited(numVertices, false);
queue<int> q;
q.push(startVertex);
visited[startVertex] = true;
cout << "BFS Traversal: ";
while (!q.empty()) {
int vertex = q.front();
q.pop();
cout << landmarks[vertex] << " ";
for (int i = 0; i < numVertices; i++) {
if (adjMatrix[vertex][i] == 1 && !visited[i]) {
q.push(i);
visited[i] = true;
}
}
}
cout << endl;
}
};
int main() {
int numVertices;
cout << "Enter the number of vertices: ";
cin >> numVertices;
Graph graph(numVertices);
for (int i = 0; i < numVertices; i++) {
string landmark;
cout << "Enter the landmark for vertex " << i << ": ";
cin >> landmark;
graph.addLandmark(i, landmark);
}
cout << "Enter the number of edges: ";
int numEdges;
cin >> numEdges;
cout << "Enter the edges (as space-separated pairs of vertices):" << endl;
for (int i = 0; i < numEdges; i++) {
int src, dest;
cin >> src >> dest;
graph.addEdge(src, dest);
}
cout << endl;
graph.printAdjMatrix();
cout << endl;
graph.printAdjList();
cout << endl;
graph.performDFS(0);
graph.performBFS(0);
return 0;
}
