
t = int(input())
for _ in range(t):
    n, m = map(int , input().split())

    fib = [1,2]
    ans = ""
    for i in range( 2 , 11 ):
        fib.append( fib[i-1] + fib[i-2] )
    for _ in range(m):

        a = list( map(int , input().split()))
        a.sort()

        if ( a[0] >= fib[n-1] and a[1] >= fib[n-1] and a[2] >= fib[n] ):
            ans += '1'
        else :
            ans += '0'

    print( ans )            
    

