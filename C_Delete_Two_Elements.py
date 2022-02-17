from collections import defaultdict
t = int(input())
while(t > 0):
    t -= 1
    n = int(input())
    l = list(map(int,input().split()))
    a = sum(l)// n
    a *= 2
    ans = 0
    d = defaultdict(int)
    for x in l:
        d[x]+=1
    for x in l:
        wanted = a - x
        if(wanted in d):
            ans += d[wanted]
        if(x == wanted):
            ans -= 1
    print(ans//2)
        
            
    