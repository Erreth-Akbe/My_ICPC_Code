import math
T = int(input())
maxp = 500
prime = []
a=[]
for i in range(0, maxp+1):
    a.append(True)
a[1] = False
for i in range(2, maxp+1):
    if a[i]:
        prime.append(i)
    for j in prime:
        if i*j > maxp:
            break
        a[i*j] = False
        if not i%j: break
for test in range(0, T):
    n = int(input())
    sum = 1
    tot = 0
    for i in prime:
        if sum*i>n:
            break
        sum *= i
        tot += 1
    f = [1]
    for i in range(1, tot+1):
        f.append(f[i-1]*(prime[i-1]+1))
    g = math.gcd(sum, f[tot])
    print(sum//g, end = '/')
    print(f[tot]//g)
    