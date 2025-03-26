# If you wannna use Python to solve competetitive problem i think you have to use C++ or Rust or C for performance
from collections import deque
n,m = [int(e) for e in input().split()]
c = [int(e) for e in input().split()]
g = [[] for e in range(n)]
for i in range(m):
    a,b = [int(e) for e in input().split()]
    g[a].append(b)
q = deque()
ans = 0
for i in range(n):
    s = [False]*n
    q.append(i)
    s[i] = True
    while(len(q) != 0):
        t = q[0]
        q.popleft()
        for e in g[t]:
            if not s[e]:
                s[e] = True
                q.append(e)
                ans = max(c[e]-c[i],ans)
print(ans)
