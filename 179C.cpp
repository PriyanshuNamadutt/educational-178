#include<iostream>
#include<vector>
#include<unordered_map>
typedef long long int ll;
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<int> a(n);
        int mn = 1e9;
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
            mn = min( mn , a[i] );
        }

        unordered_map<int,int> mp;
        int i = 0;
        while ( i < n ) {
            int j = i+1;
            int cnt = 1;
            while ( j < n && a[i] == a[j] ) {
                cnt += 1;
                if ( mp[a[i]] < cnt ) mp[a[i]] = cnt;
                j++;
            }
            i = j;
        }

        ll ans = 1e15;
        for ( auto it : mp ) {

            ans = min( (1LL)*(it.first)*( n - it.second) , ans);
        }
        cout << min( ans , (1LL)*mn*(n-1) ) << endl;
    }
    return 0;
}
