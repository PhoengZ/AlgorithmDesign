n,d = [int(e) for e in input().split()]
s = [int(e) for e in input().split()]
left = s[0]
right = s[n-1]
while (left < right):
    mid = (left+right)//2
    step = 0
    check = True
    check_1 = True
    count = 1
    i = 0
    while (i != n):
        if (step + mid < s[i]):
            if (not check):
                check_1 = False
                break
            count += 1
            if i != 0:
                step = s[i-1]
            check = False
        else:
            check = True 
            i+=1
    for i in range(n):
        if (step + mid < s[i]):
            if (not check):
                check_1 = False
                break
            count += 1
            if i != 0:
                step = s[i-1]
            check = False
            i-=1
        else:
            check = True
    if (not check_1 or count > d):left = mid+1
    else:right = mid
step = 0
count = 1
i = 0
while (i != n):
    if (step + left < s[i]):
        if (not check):
            check_1 = False
            break
        count += 1
        if i != 0:
            step = s[i-1]
        check = False
    else:
        check = True 
        i+=1
print(left,count)