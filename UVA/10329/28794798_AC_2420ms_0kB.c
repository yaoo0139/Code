import math 
try:
    while True:
        n,m = map(int,input().split())
        n1=1
        n2=1
        for i in range (0,n):
            a,b = map(int,input().split())
            n1 *= (math.factorial(a)//math.factorial(b)//math.factorial(a-b))
        for i in range (0,m):
            a,b = map(int,input().split())
            n2 *= (math.factorial(a)//math.factorial(b)//math.factorial(a-b))
        if(n1%n2==0):
            ans = int(n1//n2)
            if(len(str(ans))>100):
                print(-1)
            else:
                print(ans)
        else:
            print(0)
except EOFError:
    pass