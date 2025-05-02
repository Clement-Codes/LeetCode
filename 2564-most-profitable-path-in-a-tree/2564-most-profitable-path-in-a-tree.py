class Solution:
    def mostProfitablePath(self, edges, bob, amount):
        n = len(amount)
        max_income = float("-inf")
        tree = [[] for _ in range(n)]
        bob_path = {}
        visited = [False] * n

        # Form tree with edges
        for edge in edges:
            tree[edge[0]].append(edge[1])
            tree[edge[1]].append(edge[0])

        # Inline DFS to find Bob's path
        def find_bob_path(node, time):
            bob_path[node] = time
            visited[node] = True

            if node == 0:
                return True
            for neighbor in tree[node]:
                if not visited[neighbor]:
                    if find_bob_path(neighbor, time + 1):
                        return True
            bob_path.pop(node, None)
            return False

        # Find the path taken by Bob
        find_bob_path(bob, 0)

        # Breadth-First Search (BFS)
        visited = [False] * n
        queue = deque([(0, 0, 0)])

        while queue:
            node, time, income = queue.popleft()

            # Alice reaches the node first
            if node not in bob_path or time < bob_path[node]:
                income += amount[node]
            elif time == bob_path[node]:  # Alice and Bob arrive together
                income += amount[node] // 2

            # Update max value if current node is a leaf
            if len(tree[node]) == 1 and node != 0:
                max_income = max(max_income, income)

            # Explore adjacent unvisited nodes
            for neighbor in tree[node]:
                if not visited[neighbor]:
                    queue.append((neighbor, time + 1, income))
            visited[node] = True

        return max_income