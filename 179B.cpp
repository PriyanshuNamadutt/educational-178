#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n , m;
        cin >> n >> m;

        vector<int> fib(12);
        fib[1] = 1, fib[2] = 2;
        for ( int i = 3; i <= 11; i++ ) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        vector<vector<int>> a( m , vector<int>(3) );
        for ( int i = 0; i < m; i++ ) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];

            sort( a[i].begin() , a[i].end() );

            cout << ( a[i][0] >= fib[n] && a[i][1] >= fib[n] && a[i][2] >= fib[n+1] ? 1 : 0 );
        }
        cout << endl;
    }
    return 0;
}
