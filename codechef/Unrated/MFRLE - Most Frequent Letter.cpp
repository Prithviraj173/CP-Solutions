#include<bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define vout(A) for(int i = 0; i < A.size(); i++) { cout << A[i] << " "; } cout << endl;
#define ll long long
#define ull unsigned long long
#define yes cout <<"YES"<<endl;
#define no cout <<"NO"<<endl;
#define inc(a) sort(a.begin(), a.end());
#define rev(a) sort(a.begin(), a.end());
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a * b) / gcd(a, b))
#define f(i,s,e) for( int i=s;i<e;i++)
const int MOD = 1e9 + 7;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    string s;
    getline(cin, s);
    vector<int> freq(26, 0);
    for(char c : s) {
        if(isalpha(c)) {
            freq[tolower(c) - 'a']++;
        }
    }
    ll maxi = 0;
    char res = 'a';
    for(int i = 0; i < 26; i++) {
        if(freq[i] > maxi) {
            maxi = freq[i];
            res = 'a' + i;
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}