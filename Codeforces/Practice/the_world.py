def com(n,k):
    if n == 0:
        return 1
    res=1
    for i in range(1,n+1):
        res=res*i
    for i in range(1,k+1):
        res=res//i
    for i in range(1,n-k+1):
        res=res//i
    return res

n,m,t=map(int,input().split())
res=0
for i in range(4,t):
    res=res+com(n,i)*com(m,t-i)
print(res)
