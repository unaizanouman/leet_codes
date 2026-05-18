class Solution:
    def minJumps(self, arr):
        n = len(arr)

        if n <= 1:
            return 0

        graph = {}

        for i in range(n):
            if arr[i] in graph:
                graph[arr[i]].append(i)
            else:
                graph[arr[i]] = [i]

        curs = [0]
        visited = set([0])
        step = 0

        while curs:
            nex = []

            for node in curs:

                # reached end
                if node == n - 1:
                    return step

                # same value jumps
                for child in graph[arr[node]]:
                    if child not in visited:
                        visited.add(child)
                        nex.append(child)

                # clear list safely
                graph[arr[node]] = []

                # adjacent jumps
                for child in [node - 1, node + 1]:
                    if 0 <= child < n and child not in visited:
                        visited.add(child)
                        nex.append(child)

            curs = nex
            step += 1

        return -1