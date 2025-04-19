w, n =[float(e)  for e in input().split()]
n = int(n)
v = [float(e) for e in input().split()]
weights = [float(e) for e in input().split()]
r = [(float(v[i]/weights[i]), i) if weights[i] != 0 else (v[i], i) for i in range(n)]
r.sort(reverse=True)
total = 0
weight = 0
for i in range(n):
    if (weight+weights[r[i][1]] > w):
        total += r[i][0]*(w-weight)
        weight = 0
        break
    weight += weights[r[i][1]]
    total += v[r[i][1]]
print(f"{total:.4f}")