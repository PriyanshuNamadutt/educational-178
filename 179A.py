def solve( num , x , cnt ):
    if ( num >= x ):
        return 2*cnt + 1
    return solve( 2*num + 1 , x , cnt+1 )

t = int(input())
for _ in range(t):
    x = int(input())
    print( solve( 0, x, 0 ) )
