class Solution:
    def dfs(self, fromNode, adj, visited):
        result = 0
        for dest, isRev in adj[fromNode]:
            if dest not in visited:
                visited.add(dest)
                result += self.dfs(dest, adj, visited) if isRev else self.dfs(dest, adj, visited) + 1
        return result

    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        visited = set([0])
        for source, dest in connections:
            adj[source].append((dest, False))
            adj[dest].append((source, True))
        return self.dfs(0, adj, visited)

