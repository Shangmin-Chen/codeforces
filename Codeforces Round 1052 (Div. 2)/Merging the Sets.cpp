#include <bits/stdc++.h>
using namespace std;

// Type definitions
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// Macros
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;

// Utility functions
template<typename T>
void print_vector(const vector<T>& v) {
    for (int i = 0; i < sz(v); i++) {
        cout << v[i] << (i == sz(v) - 1 ? "\n" : " ");
    }
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll power(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vi cnt(m, 0); // declare with size m, fill it up with 0s
    int t = 0; // total number of unique elements
    vector<vi> v(n); // store the sets
    
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            int x;
            cin >> x;
            x--; // Convert to 0-indexed
            if (cnt[x] == 0) t++;
            cnt[x]++;
            v[i].push_back(x);
        }
    }

    int ans = (t == m) ? 1 : 0; // check trivial solution.
    
    for (int i = 0; i < n; i++) {
        // start remove set i
        for (auto x : v[i]) { // for each collected set, start removing the counters to check for set exclusions
            cnt[x]--;
            if (cnt[x] == 0) t--; // this set no good
        }
        
        if (t == m) ans++; // other sets combine into 1 ... m when removing this one
        
        // Add set i back 
        for (auto x : v[i]) {
            if (cnt[x] == 0) t++;
            cnt[x]++;
        }
    }
    
    cout << (ans >= 3 ? "YES" : "NO") << "\n";
}

int main() {
    fast_io;
    
    int t = 1;
    cin >> t;  // Comment this line if single test case
    
    while (t--) {
        solve();
    }
    
    return 0;
}