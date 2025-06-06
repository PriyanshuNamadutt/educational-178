#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n, m;
        cin >> n >> m;
        priority_queue<int , vector<int> , greater<int>> mn1;
        priority_queue<int , vector<int> , greater<int>> mn2;
        priority_queue<int> mx1;
        priority_queue<int> mx2;

        for ( int i = 0; i < m; i++ ) {
            int num; cin >> num;
            mn1.push(num);
            mn2.push(num);
            mx1.push(num);
            mx2.push(num);
        }

        vector<vector<int>> ans( 2 , vector<int>(n) );
        for ( int i = 0; i < n; i++ ) {

            if ( i % 2 == 0 ) {
                ans[0][i] = mn1.top();
                mn1.pop();
            }
            else {
                ans[0][i] = mx1.top();
                mx1.pop();
            }
        }
        for ( int i = 0; i < n; i++ ) {

            if ( i % 2 == 0 ) {
                ans[1][i] = mx2.top();
                mx2.pop();
            }
            else {
                ans[1][i] = mn2.top();
                mn2.pop();
            }
        }

        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < 6; j++ ) {

                if ( j % 2 == 0 ) cout << ans[0][i] << " ";
                else cout << ans[1][i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
