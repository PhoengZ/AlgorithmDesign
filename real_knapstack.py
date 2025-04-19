ans = 0
w,n = [float(e) for e in input().split()]
n = int(n)
value = [float(e) for e in input().split()]
weight = [float(e) for e in input().split()]
ratio = [(value[i]/weight[i],i) for i in range(n)]
ratio.sort(reverse=True)
def b(now,we):
    total = 0
    for i in range(now,n):
        if (we + weight[ratio[i][1]] <= w):
            total+= value[ratio[i][1]]
            we += weight[ratio[i][1]]
        else:
            total+= ratio[i][0]*(w-we)
            break
    return total

def f(now,val,we):
    global ans
    if (we > w):return
    if (now == n):
        ans = max(val,ans)
        return 
    if (b(now,we) + val < ans):return
    if (weight[ratio[now][1]] + we <= w):f(now+1,val+value[ratio[now][1]],we+weight[ratio[now][1]])
    f(now+1,val,we)
f(0,0,0)
print(ans)