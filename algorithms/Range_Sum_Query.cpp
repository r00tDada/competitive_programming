#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp>  // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for (__typeof((b)) i = (a); i < (b); i++)
#define nrep(i, a, b) for (__typeof((b)) i = (a); i > (b); i--)
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define ppi pair<int, int>
#define pppi pair<ppi, int>
#define vi vector<int>
#define vii vector<ppi>
#define viii vector<pppi>
#define vs vector<string>
#define pb push_back
#define bitcount __builtin_popcountll  // count no's of ones in a set bit
#define mem(x, val) memset((x), (val), sizeof(x));
#define sz(x) (int)x.size()
#define M_PI 3.14159265358979323846
#define int long long
#define rootdada                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define test \
  int T;     \
  cin >> T;  \
  while (T--)
#define MOD 1000000007
#define ordered_set                            \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>

void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T1, typename T2, typename T3>
void __print(const tuple<T1, T2, T3> &x) {cerr << '{'; __print(get<0>(x)); cerr << ','; __print(get<1>(x)); cerr << ','; __print(get<2>(x)); cerr << '}';}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


struct hash_pair
{
// use pair as key in unordered_map<pair<int,int>,int,hash_pair>;
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2> &p) const
	{
		auto hash1 = hash<T1> {}(p.first);
		auto hash2 = hash<T2> {}(p.second);
		return hash1 ^ hash2;
	}
};

int ceil_div(int a, int b) {
	return (a + b - 1) / b;
}


struct segtree {
	int size;
	vector<int> tree;
	void init(int n)
	{
		size = 1;
		while (size < n)
			size *= 2;
		tree.assign(2 * size + 1, 0LL);
	}
	void build(vector<int> &a, int x, int tl, int tr)
	{
		if (tl == tr)
		{
			if (tl < (int)a.size())
				tree[x] = a[tl];
			return;
		}
		int mid = (tl + tr) / 2;
		build(a, 2 * x, tl, mid);
		build(a, 2 * x + 1, mid + 1, tr);
		tree[x] = tree[2 * x] + tree[2 * x + 1];
	}
	void build(vector<int> &a)
	{
		build(a, 1, 1, size);
	}
	void set(vector<int> &a, int i, int new_val, int x, int tl, int tr)
	{
		if (tl == tr)
		{
			a[i] = new_val;
			tree[x] = new_val;
			return;
		}
		int mid = (tl + tr) / 2;
		if (tl <= i && i <= mid)
			set(a, i, new_val, 2 * x , tl, mid);
		else
			set(a, i, new_val, 2 * x + 1, mid + 1, tr);
		tree[x] = tree[2 * x] + tree[2 * x + 1];

	}
	void set(vector<int> &a, int i, int new_val)
	{
		set(a, i, new_val, 1, 1, size);
	}
	int sum(int l, int r, int x, int tl, int tr)
	{
		if (tl > r || tr < l)
			return 0;
		if (tl >= l && tr <= r)
			return tree[x];
		int mid = (tl + tr) / 2;
		int s1 = sum(l, r, 2 * x , tl, mid);
		int s2 = sum(l, r, 2 * x + 1, mid + 1, tr);
		return s1 + s2;
	}
	int sum(int l, int r)
	{
		return sum(l, r, 1, 1, size);
	}
} st;

signed main() {
	rootdada;
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	st.init(n + 1);
	st.build(a);
	while (q--) {
		int type; cin >> type;
		if (type == 2) {
			int l, r;
			cin >> l >> r;
			cout << st.sum(l, r) << endl;
		}
		else {
			int i, new_val;
			cin >> i >> new_val;
			st.set(a, i, new_val);
		}

	}

}