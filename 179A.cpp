#include<iostream>
typedef long long int ll;
using namespace std;

ll solve( ll num , ll x , ll cnt ) {
    if ( num >= x ) return 2*cnt+1;
    return solve( 2*num+1 , x , cnt+1 );
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        ll x; cin >> x;
        cout << solve( 0 , x , 0 ) << endl;
    }
    return 0;
}
