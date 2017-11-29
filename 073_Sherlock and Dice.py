t=int(input())
for i in range(0,t):
    m,n,k = (map(int,input().split()))
    print(n,m,k)
    mi,ma = m , n*m
    print(mi,ma)
    total = (m*n-n+1)
    mid = (total+1)/2
    print(mid)
    su = mid*mid
    pos = k-mi+1
    pro = pos
    if pos > mid :
        pro = 2*mid - pos
    prob = pos / pro
    print(prob)
    ct = 0
    while prob < 1 :
        ct+=1
        prob*=10
    print("%.3f %d\n" %(prob,i))