t = int(input())
for tt in range(0,t):
    inp = input().split(" ")
    n=int(inp[0])
    g=int(inp[1])
    b=int(inp[2])

    r=0

    if(n&1):
        r=n//2+1
    else:
        r=n//2

    if(r<=g):
        print(n)
    else:
        f=r//g
        m=r%g

        bad = (f-1)*b

        if(m!=0):
            bad+=b 

        total = f*g+bad+m

        bal = n-r

        if(bal<=bad):
            print(total)
        else:
            print(total+(bal-bad))

