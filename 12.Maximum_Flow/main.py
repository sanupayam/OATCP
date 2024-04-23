from collections import deque

def bfs(graph, source, sink, parent):
    visited = [False] * len(graph)
    queue = deque()
    queue.append(source)
    visited[source] = True
    parent[source] = -1

    while queue:
        u = queue.popleft()
        for v in range(len(graph)):
            if not visited[v] and graph[u][v] > 0:
                queue.append(v)
                parent[v] = u
                visited[v] = True
    return visited[sink]

def ford_fulkerson(graph, source, sink):
    residual_graph = [row[:] for row in graph]
    parent = [-1] * len(graph)
    max_flow = 0

    while bfs(residual_graph, source, sink, parent):
        flow = float('inf')
        v = sink
        while v != source:
            u = parent[v]
            flow = min(flow, residual_graph[u][v])
            v = parent[v]

        v = sink
        while v != source:
            u = parent[v]
            residual_graph[u][v] -= flow
            residual_graph[v][u] += flow
            v = parent[v]

        max_flow += flow

    return max_flow

if __name__ == "__main__":
    n = int(input())
    source, sink = map(int, input().split())
    graph = [[0] * (n + 1) for _ in range(n + 1)]

    while True:
        try:
            node1, node2, weight = map(int, input().split())
            graph[node1][node2] = weight
        except:
            break

    print("Output:", ford_fulkerson(graph, source, sink))
