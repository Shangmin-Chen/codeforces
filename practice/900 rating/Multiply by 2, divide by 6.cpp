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
    // Your solution here
    int cnt2 = 0; int cnt3 = 0;
    int n; cin >> n;
    while (n % 2 == 0) {
        n /= 2;
        ++cnt2;
    }
    while (n % 3 == 0) {
        n /= 3;
        ++cnt3;
    }

    if (n == 1 && cnt2 <= cnt3) {
        cout << (cnt3 - cnt2) + cnt3 << endl;
    } else {
        cout << -1 << endl;
    }
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