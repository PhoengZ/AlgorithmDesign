from collections import deque
import sys
input = sys.stdin.readline

n,m,k = [int(e) for e in input().split()]
g = [[] for e in range(n)]
v = [int(e) for e in input().split()]
d = [int(e) for e in input().split()]
total = sum(v)
for i in range(m):
    a,b = [int(e) for e in input().split()]
    g[a].append(b)
q = deque()
for i in range(k):
    if (v[d[i]] == 0):
        print(total, end=" ")
        continue
    q.append(d[i])
    total-=v[d[i]]
    v[d[i]] = 0
    while(len(q) != 0):
        t = q[0]
        q.popleft()
        for e in g[t]:
            if v[e] != 0:
                total-=v[e]
                v[e] = 0
                q.append(e)
    print(total, end=" ")