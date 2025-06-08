#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n , q;
        cin >> n >> q;
        string s; cin >> s;
        vector<vector<set<int>>> qu( 3 , vector<set<int>>(3) );
        for ( int i = 0; i < q; i++ ) {
            char ch1 , ch2;
            cin >> ch1 >> ch2;
            qu[ch1 - 'a'][ch2 - 'a'].insert(i);
        }

        for ( int i = 0; i < n; i++ ) {
            if ( s[i] == 'a' ) continue;
            else if ( s[i] == 'b' ) {
                
                if ( !qu[1][0].empty() ) {
                    qu[1][0].erase( qu[1][0].begin() );
                    s[i] = 'a';
                }
                else if ( !qu[1][2].empty() ) {
                    auto idx = *qu[1][2].begin();
                    auto lst = qu[2][0].lower_bound(idx);
                    if ( lst != qu[2][0].end() ) {
                        qu[1][2].erase(idx);
                        qu[2][0].erase(lst);
                        s[i] = 'a';
                    }
                }
            }
            else {
                if ( !qu[2][0].empty() ) {
                    s[i] = 'a';
                    qu[2][0].erase( qu[2][0].begin());
                }
                else if ( !qu[2][1].empty() ) {

                    auto idx = *qu[2][1].begin();
                    qu[2][1].erase(idx);
                    s[i] = 'b';
                    auto lst = qu[1][0].lower_bound(idx);
                    if ( lst != qu[1][0].end() ) {
                        s[i] = 'a';
                        qu[1][0].erase(lst);
                    }
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
