from collections import deque
r,c,T = [int(e) for e in input().split()]
g = [[] for i in range(r)]
d = [[1,0],[-1,0],[0,1],[0,-1]]
q = deque()
total = 0
for i in range(r):
    v = [int(e) for e in input().split()]
    g[i] = v
    for j in range(len(v)):
        if(v[j] == 1):
            total+=1
            q.append((i,j,0))
            g[i][j] = 1
        if (v[j] == 2):g[i][j] = 1
while(len(q) != 0):
    t = q[0]
    q.popleft()
    for i in range(4):
        R = t[0]+d[i][0]
        C = t[1]+d[i][1]
        if (R < 0 or C < 0 or R >= r or C >= c):continue
        if (g[R][C] != 1 and t[2] + 1 <= T ):
            total+=1
            g[R][C] = 1
            q.append((R,C,t[2]+1))
print(total)


