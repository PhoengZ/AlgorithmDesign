from collections import deque
r,c = [int(e) for e in input().split()]
g= [""]*r
s= [[False for i in range(c)] for e in range(r)]
o = [[-1 for i in range(c)] for e in range(r)]
d = [[1,0],[-1,0],[0,1],[0,-1]]
q = deque()
for i in range(r):
    a = input().strip()
    g[i] = a
q.append((0,0))
o[0][0] = 0
s[0][0] = True
while (len(q) != 0):
    t = q[0]
    q.popleft()
    for i in range(4):
        R = t[0]-d[i][0]
        C = t[1]-d[i][1]
        if (R < 0 or C < 0 or R >= r or C >= c):continue
        if ( not s[R][C] and g[R][C] != "#"):
            s[R][C] = True
            o[R][C] = o[t[0]][t[1]] + 1
            q.append((R,C))
if o[r-1][c-1] == -1:print(-1)
else:print(o[r-1][c-1])