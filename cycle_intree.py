import sys
kb = sys.stdin
from collections import deque
n = int(input())
g = [[] for e in range(n)]
for i in range(n):
    a,b = map(int, kb.readline().split())
    g[a].append(b)
    g[b].append(a)
q = deque()
s = [False]*n
size = [0]*n
s[0] = True
size[0] = 1
q.append((0,-1))
found = False
total = 0
while(len(q) != 0 and not found):
    t = q.pop()
    for i in g[t[0]]:
        if not s[i]:
            s[i] = True
            size[i] = 1+ size[t[0]]
            q.append((i,t[0]))
        else:
            if (i != t[1]):
                total = size[t[0]] - size[i]  + 3
                found = True
                break
print(total)