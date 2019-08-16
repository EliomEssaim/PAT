#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXV = 510, INF = 0x3fffffff;
int length[MAXV][MAXV], Gtime[MAXV][MAXV], dist[MAXV], n, m, st, des;
vector<int> ShortPath, FastPath, tmpPath, pre[MAXV];
int minTime = INF, minSection = INF; bool DFS_flag = true;
void Dijkstra(int st, int G[MAXV][MAXV]) {
	fill(dist, dist + MAXV, INF);
	bool visited[MAXV] = { false };
	dist[st] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, minWeight = INF;
		for (int i = 0; i < n; i++) {
			if (visited[i] == false && dist[i] < minWeight) {
				u = i; minWeight = dist[i];
			}
		}
		if (u == -1) return;
		visited[u] = true;
		for (int v = 0; v < n; v++) {
			if (G[u][v] != INF && visited[v] == false) {//v写成i
				if (dist[u] + G[u][v] < dist[v]) {
					dist[v] = dist[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dist[u] + G[u][v] == dist[v])
					pre[v].push_back(u);
			}
		}
	}
}
void DFS(int id) {
	tmpPath.push_back(id);
	if (id == st) {
		int totalTime = 0;
		for (int i = tmpPath.size() - 1; i >= 1; i--) {//写成++
			int id = tmpPath[i], idnext = tmpPath[i - 1];//没写出来
			totalTime += Gtime[id][idnext];
		}
		if (DFS_flag&&totalTime < minTime) {
			minTime = totalTime;
			ShortPath = tmpPath;
		}
		if (!DFS_flag && (int)tmpPath.size() < minSection) {//没了！
			minSection = tmpPath.size();
			FastPath = tmpPath;
		}
		tmpPath.pop_back();
		return;
	}
	for (int i = 0; i < (int)pre[id].size(); i++) {
		DFS(pre[id][i]);
	}
	tmpPath.pop_back();
}
int main() {
	fill(length[0], length[0] + MAXV * MAXV, INF);
	fill(Gtime[0], Gtime[0] + MAXV * MAXV, INF);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v1, v2, oneway, lengthh, timee;
		scanf("%d%d%d%d%d", &v1, &v2, &oneway, &lengthh, &timee);
		length[v1][v2] = lengthh; Gtime[v1][v2] = timee;
		if (!oneway) { length[v2][v1] = lengthh; Gtime[v2][v1] = timee; }//没加上！
	}
	scanf("%d%d", &st, &des);
	Dijkstra(st, length); DFS(des);
	int Dist = dist[des];
	DFS_flag = false; for (int i = 0; i < n; i++) pre[i].clear();
	Dijkstra(st, Gtime); DFS(des);
	int Time = dist[des];
	if (FastPath == ShortPath) {
		printf("Distance = %d; Time = %d: ", Dist, Time);
		for (int i = ShortPath.size() - 1; i >= 0; i--)
			printf("%d%s", ShortPath[i], i == 0 ? "\n" : " -> ");
	}
	else {
		printf("Distance = %d: ", Dist);
		for (int i = ShortPath.size() - 1; i >= 0; i--)
			printf("%d%s", ShortPath[i], i == 0 ? "\n" : " -> ");
		printf("Time = %d: ", Time);
		for (int i = FastPath.size() - 1; i >= 0; i--)
			printf("%d%s", FastPath[i], i == 0 ? "\n" : " -> ");
	}
	return 0;
}
