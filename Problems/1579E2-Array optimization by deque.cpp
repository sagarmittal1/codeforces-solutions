#pragma GCC optimize("Ofast")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #include<unistd.h>

// defines
#define int long long
#define el "\n"
typedef long long ll;
// #define double long double
#define vec vector
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define F first
#define S second
#define MP make_pair
#define vii vector<ii>
#define PQ priority_queue
#define minPQ priority_queue<int, vec<int>, greater <int>>
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define ER equal_range
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define EACH(z, A) for (auto& z: A)
#define UNI(c) c.resize(distance(c.begin(),unique(c.begin(),c.end())));
#define SORT_UNI(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
template<class T> void sortUni(vec<T> &v){sort(all(v));	v.erase(unique(ALL(v)),v.end());}
#define POS(c,x) (lower_bound(c.begin(),c.end(),(x))-c.begin())
#define max(a, b) ((a)<(b)? b : a)
#define min(a, b) ((a)<(b)? a : b)
#define max3(a, b) max(max((a), (b)), (c))
#define min3(a, b, c) min(min((a), (b)), (c))
// int a = min({x2,x2,x3,x4,x5});
#define setmin(a, b) a = min(a, b)
#define setmax(a, b) a = max(a, b)
#define MINMAX(x) minmax_element(begin(x), end(x))

//permanent constants
const long long INF64 = 1e18; const int INF32 = 1e9;
const double EPS = static_cast<double>(1e-10);
const double PI = 2.0*acos(0.0); //acos(-1.0L);
const int MOD = (int)1e9+7; //998244353
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
constexpr ll ten(int n) { return n==0?1:ten(n-1)*10;} // 10^n

ll powMod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll invMod(ll a) {ll b=MOD,u=1,v=0;while(b){ll t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v);} return (MOD + u) % MOD;}

//for PDBS use only:

template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k): iterator to the kth largest(0 indexed). order_of_key(k): no. of items < k

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* USE: order_of_key (k) : Number of items strictly smaller than k .
		find_by_order(k) : K-th element in a set (counting from zero).
*/

// OR: template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* USE pair with index if need MULTISET:
// #define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
*/

// TIP: if you have complier error message of missing file hash_standard_resize_policy_imp.hpp. Try to find file 
// "hash_standard_resize_policy_imp.hpp0000644" and rename it to match the name of the missing one. 

//random
ll rand_int(ll l, ll r) { //returns a random number within [l, r]
	// #ifdef LOCAL
	// static mt19937_64 gen;
	// #else
    static random_device rd;
    static mt19937_64 gen(rd());
    // #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}

// Lambda Function:  auto f = [] (int a, int b) -> int { return a + b; }; 
// cout << f(1, 2); // prints "3"

//Tricks:
// Sort w Lambda Function: sort(begin(v), end(v), [] (int a, int b) { return a > b; });
// Sort vector cua bo ba so: struct MyStr {int a, b, c;}; vector<MyStr> v; ...fill v...
// sort(all(v), [](MyStr &A, MyStr &B) { return tie(A.a, A.b, A.c) < tie(B.a, B.b, B.c); });

/*********** SORT INDEXES of Vector Using Lambda function ********
vector<int> sort_indexes(const vector<int> &v) {
  vector<int> idx(v.size()); iota(idx.begin(), idx.end(), 0); // initialize original index locations
  sort(idx.begin(), idx.end(),     // sort indexes based on comparing values in v
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});
  return idx;
}
// Now you can use the returned index vector in iterations such as
for (auto i: sort_indexes(v))  cout << v[i] << endl;
************** END *************************************/

#define odd(x) ((x) & 1)
#define even(x) !((x) & 1)
// vec - vector, p(x) - predicate so that p(x) = true for all elements of some prefix of vector
// vec and false on all others. To find the first place where p(x) doesn't hold one can simply use: 
#define FIRST_FAIL(vec, p) partition_point(ALL(vec), p) - vec.begin()
// partition_point(begin, end, p) returns the first ITERATOR it that p(*it) = false
#define isIn(vec, key) binary_search(ALL(vec), key)
#define toBool(num) !!(num)
#define bin(N, num) cerr << bitset<N>(num) << "\n"
string get_binary(ll n) {string res=""; while(n) {res+=((n&1)+'0');n/=2;} reverse(ALL(res));return res;}
// vector a: tinh XOR sum tu l den r:
#define XORsum(a, l, r) accumulate(a.begin()+l-1, a.begin()+r, 0, [](int x, int y){ return x^y; })
// BASIC STRING: just like vector but allows to use a few string member functions/operators: operator+ and operator+=.:
/*  int n;    basic_string<int> a;
    cin >> n; FOR(i, 0, n) { int x;   cin >> x; a += x; }
    a += a; a = a.substr(n/2, n);
    cout << (a + a).find({1, 2, 1}) << '\n';
*/
// count(a.begin(), a.end(), val) - count how many val in an array a
vector<int> prefixSum(vector<int> &a) {vi b; std::partial_sum(a.begin(), a.end(), b.begin()); return b;} 

int mostSignDigit(int n) { double k = log10(n); return (int)pow(10, k-floor(k));}
int numOfDigits(int n) {return (int)floor(log10(n)) + 1;}
bool isPowerOfTwo(int x) {return x && (!(x&(x-1)));} // first x is for the case x=0

bool allPositive(vector<int> &a) {return all_of(begin(a), end(a), [](int x){return x > 0;});} // are all of the elements positive?
// CHECK there is all numbers in array is positive: bool ok=true; for(auto z: a) ok &= (z>0);
bool anyPositive(vector<int> &a) {return any_of(begin(a), end(a), [](int x){return x > 0;});} // is there at least one positive element?
bool nonePositive(vector<int> &a) {return none_of(begin(a), end(a), [](int x){return x > 0;});} // are none of the elements positive?

void FILEIO() {  freopen("in.txt", "r", stdin);  freopen("out.txt", "w", stdout); } 
//void FILEIO() {  freopen("berries.in", "r", stdin);  freopen("berries.out", "w", stdout); } // USACO

/****************** DEBUG *******************/
//Universal DEBUG: https://codeforces.com/blog/entry/68809
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "T" : "F");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define db(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define db(x...)
#endif

//******************** MULTISET (!) Ordered-set Library Class (using pairing value with index) ***********************/
//Normally ordered-set requires values must be different!

template <typename num_t>
struct ordered_multiset {
	ordered_set<pair<num_t, int> > vals;
	set<pair<num_t, int>> best; /* start at -1 */
	
	int findbest(num_t val) { /* helper, find the lowest value that represents the element */
		return (*best.upper_bound(make_pair(val - 1, 0))).second;
	}
	
	/* is element in set */
	bool contains(num_t val) { return vals.find(make_pair(val, -1)) != vals.end(); }
	
	void insert(num_t val) {
		if (contains(val)) { /* already in, update lowest value and insert a new one */
			int loc = findbest(val);
			best.erase(make_pair(val, loc));
			best.insert(make_pair(val, loc - 1));
			vals.insert(make_pair(val, loc - 1));
		} else { /* make lowest value -1 and insert it */
			best.insert(make_pair(val, -1));
			vals.insert(make_pair(val, -1));
		}
	}
	
	void erase(num_t val) { /* erases one */
		if (!contains(val)) return; /* not in */
		num_t loc = findbest(val);
		
		/* remove the element and its best */
		best.erase(make_pair(val, loc));
		vals.erase(make_pair(val, loc));
		if (loc != -1) best.insert(make_pair(val, loc + 1)); /* more elements in set, update best */
	}
	
	/* unmodified functions */
	num_t find_by_order(int k) { return (*vals.find_by_order(k)).first; } // here there's no pointer. direct value returned
	int order_of_key(num_t k) { return vals.order_of_key(make_pair(k - 1, 0)); }
	auto begin() { return vals.begin(); }
	auto end() { return vals.end(); }
	auto rbegin() { return vals.rbegin(); }
	auto rend() { return vals.rend(); }
	int size() { return vals.size(); }
	void clear() { vals.clear(); best.clear(); }
	int count(num_t k) { return vals.order_of_key({k, 0}) - vals.order_of_key({k - 1, 0}); }
	auto lower_bound(num_t k) { return vals.lower_bound(make_pair(k - 1, 0)); }
	auto upper_bound(num_t k) { return vals.upper_bound(make_pair(k, 0)); }
};

/***********************END of LIBRARY *************************************/
 
void solve() {
    int n; cin >> n;
    vi a(n); FOR(i, 0, n) cin >> a[i];
    ordered_multiset<int> ms;
    // deque<int> de;
    int ans = 0;
    FOR(i, 0, n) {
        int left = ms.order_of_key(a[i]);
        int cnt = ms.count(a[i]);
        int right = SZ(ms) - left - cnt;
        if(left < right) {
            ans += left;
        } else {
            ans += right;
        }
        ms.insert(a[i]);
    }
    cout << ans << endl;
}


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
	// FILEIO();
	//  auto beginProgram = chrono::steady_clock::now();

	// preCalc(); // any 1-time precalculation need to do before many test cases?
	
	int tc; cin >> tc; FORE(i, 1, tc)
	  {
		//   int n = rand_int(0, (int)1e6); solve(n);
		  // cout << "Case #" << i << ": "; // Google CodeJam style
		  solve();
	  }
	
	//  auto endProgram = chrono::steady_clock::now();
	//  cerr << chrono::duration_cast<chrono::milliseconds>(endProgram - beginProgram).count() << " ms" << endl;
	  return 0;
}