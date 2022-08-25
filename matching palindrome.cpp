#include <bits/stdc++.h>
// #define int int64_t //be careful about this 

using namespace std;

#define vt vector 
#define ar array 
#define pr pair 

#define f first 
#define s second

#define pb push_back
#define eb emplace_back

#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define rf(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))

namespace IN{
  template<class T> void re(vector<T> &A);
  template<class S,class T> void re(pair<S,T> &A);
  template<class T,size_t N> void re(array<T,N> &A);

  template<class T> void re(T& x){ 
    cin >> x;}
  template<class H, class... T> void re(H& h, T&... t){ 
    re(h); re(t...);}

  template<class T> void re(vector<T> &A){ 
    for(auto& x : A) re(x);}
  template<class S,class T> void re(pair<S,T> &A){ 
      re(A.first); re(A.second);}
  template<class T,size_t N> void re(array<T,N> &A){
    for(int i = 0; i < N; ++i)  re(A[i]);}
}

namespace OUT{
  template<class T>
  void __p(const T& a){ cout<<a; }
  template<class T, class F>
  void __p(const pair<T, F>& a){ cout<<"{"; __p(a.first); cout<<","; __p(a.second); cout<<"}\n"; }
  template<class T, size_t N>
  void __p(const array<T,N>& a){ cout<<"{"; for(int i=0;i<N;++i)__p(a[i]),cout<<",}\n"[i+1==N]; }
  template<class T>
  void __p(const vector<T>& a){
    cout<<"{";for(auto it=a.begin();it<a.end();it++)__p(*it),cout<<",}\n"[it+1==a.end()]; }
  template<class T, class ...Arg>
  void __p(T a1, Arg ...a){__p(a1); __p(a...); }
  template<class Arg1>
  void __f(const char *s, Arg1 &&arg1){ cout<<s<<" : "; __p(arg1); cout<<endl; }
  template<class Arg1, class ... Args>
  void __f(const char *ss, Arg1 &&arg1, Args &&... args){
    int b=0,i=0; do{ if(ss[i]=='(') b++; if(ss[i]==')') b--; i++;}while(!(ss[i]==','&&b==0));
    const char *comma=ss+i; cout.write(ss,comma-ss)<<" : ";__p(arg1);cout<<" | ";__f(comma+1,args...);}
  #define trace(...) cout<<"Line:"<<__LINE__<<"  ", __f(#__VA_ARGS__, __VA_ARGS__)
}


namespace FUNC{
  void IO(string s = ""){
    ios_base::sync_with_stdio(NULL); 
    cin.tie(nullptr); 
    cout.precision(20); 
    cout << fixed;
    if(!s.empty()){
      freopen((s+".in").c_str(),"r",stdin);
      freopen((s+".out").c_str(),"w",stdout);
    }
  }

  const auto start_time = chrono::high_resolution_clock::now();
  void output_run_time(){
    // will work for ac,cc&&cf.
#ifndef ONLINE_JUDGE
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end_time-start_time;
      cout << "\n\n\nTime Taken : " << diff.count();
#endif
  }

  template<class T> bool ckmin(T& a, const T& b){ 
    return b < a ? a = b, true : false; }
    
  template<class T> bool ckmax(T& a, const T& b){ 
    return a < b ? a = b, true : false; }

  // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  // int my_rand(int L, int R){ 
  //   return uniform_int_distribution<int>(L,R)(rng); }
  
  template<class T> int sz(const T& x){ 
    return int(x.size()); }

  template<class T> int lb(const vector<T>& vec,const T& val){
    return int(lower_bound(vec.begin(), vec.end(),val) - vec.begin()); }

  template<class T> int ub(const vector<T>& vec,const T& val){
    return int(upper_bound(vec.begin(), vec.end(),val) - vec.begin()); }

  constexpr int  dx[4] = {1,0,-1,0};
  constexpr int  dy[4] = {0,1,0,-1};
  constexpr char dr[4] = {'D','R','U','L'};

  constexpr long long INFLL1 = 1e16, INFLL2 = 9e18;
  // constexpr int INF = 2e9;
}


using namespace IN;
using namespace OUT;
using namespace FUNC;















template<const unsigned &MOD>
struct _m_uint {
  unsigned val;
 
  _m_uint(int64_t v = 0){
    if(v < 0) v = v % MOD + MOD;
    if(v >= MOD) v %= MOD;
    val = unsigned(v);
  }
 
  _m_uint(uint64_t v){
    if(v >= MOD) v %= MOD;
    val = unsigned(v);
  }
 
  _m_uint(int v) : _m_uint(int64_t(v)) {}
  _m_uint(unsigned v) : _m_uint(uint64_t(v)) {}
 
  explicit operator unsigned() const { return val; }
  explicit operator int64_t() const { return val; }
  explicit operator uint64_t() const { return val; }
  explicit operator double() const { return val; }
  explicit operator long double() const { return val; }
 
  _m_uint& operator+=(const _m_uint &other){
    val = val < MOD - other.val ? val + other.val : val - (MOD - other.val);
    return *this;
  }
 
  _m_uint& operator-=(const _m_uint &other){
    val = val < other.val ? val + (MOD - other.val) : val - other.val;
    return *this;
  }
 
  static unsigned fast_mod(uint64_t x, unsigned m = MOD){
    return unsigned(x % m);
  }
 
  _m_uint& operator*=(const _m_uint &other){
    val = fast_mod(uint64_t(val) * other.val);
    return *this;
  }
 
  _m_uint& operator/=(const _m_uint &other){
    return *this *= other.inv();
  }
 
  friend _m_uint operator+(const _m_uint &a, const _m_uint &b){ return _m_uint(a) += b; }
  friend _m_uint operator-(const _m_uint &a, const _m_uint &b){ return _m_uint(a) -= b; }
  friend _m_uint operator*(const _m_uint &a, const _m_uint &b){ return _m_uint(a) *= b; }
  friend _m_uint operator/(const _m_uint &a, const _m_uint &b){ return _m_uint(a) /= b; }
 
  _m_uint& operator++(){
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
 
  _m_uint& operator--(){
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
    
  _m_uint operator++(int){ _m_uint before = *this; ++*this; return before; }
  _m_uint operator--(int){ _m_uint before = *this; --*this; return before; }
      
  _m_uint operator-() const {
    return val == 0 ? 0 : MOD - val;
  }
 
  friend bool operator==(const _m_uint &a, const _m_uint &b) { return a.val == b.val; }
  friend bool operator!=(const _m_uint &a, const _m_uint &b) { return a.val != b.val; }
  friend bool operator<(const _m_uint &a, const _m_uint &b) { return a.val < b.val; }
  friend bool operator>(const _m_uint &a, const _m_uint &b) { return a.val > b.val; }
  friend bool operator<=(const _m_uint &a, const _m_uint &b) { return a.val <= b.val; }
  friend bool operator>=(const _m_uint &a, const _m_uint &b) { return a.val >= b.val; }
 
  static const int SAVE_INV = int(1e6) + 5;
  static _m_uint save_inv[SAVE_INV];
 
  static void prepare_inv(){
    // Make sure MOD is prime, which is necessary for the inverse algorithm below.
    for(int64_t p = 2; p * p <= MOD; p += p % 2 + 1){
      assert(MOD % p != 0);
    } 
      
    save_inv[0] = 0;
    save_inv[1] = 1;
 
    for (int i = 2; i < SAVE_INV; i++){
      save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }
  }
 
  _m_uint inv() const {
    if(save_inv[1] == 0)  
      prepare_inv();
 
    if(val < SAVE_INV)  
      return save_inv[val];
 
    _m_uint product = 1;
    unsigned v = val;
 
    while(v >= SAVE_INV){
      product *= MOD - MOD / v;
      v = MOD % v;
    }
    return product * save_inv[v];
  }
 
  _m_uint pow(int64_t p) const {
    if(p < 0)  
      return inv().pow(-p);
    _m_uint a = *this, result = 1;
    while(p > 0){
      if(p & 1) 
        result *= a;
      p >>= 1;
      if(p > 0) 
        a *= a;
    }
    return result;
  }
 
  friend ostream& operator<<(ostream &os, const _m_uint &m){
    return os << m.val;
  }
};
 
template<const unsigned &MOD> _m_uint<MOD> _m_uint<MOD>::save_inv[_m_uint<MOD>::SAVE_INV];


auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
 
// P = 2^32 - 13337 is a safe prime: both P and (P - 1) / 2 are prime.
extern const unsigned HASH_P = unsigned(-13337); // hash prime
using hash_int = _m_uint<HASH_P>;
using hash_t = uint64_t;

const uint64_t HASH_P2 = uint64_t(HASH_P) * HASH_P;// square of hash prime
const int HASH_COUNT = 2;
 
// Avoid multiplication bases near 0 or P - 1.
uniform_int_distribution<unsigned> MULT_DIST(unsigned(0.1 * HASH_P), unsigned(0.9 * HASH_P));
const hash_int HASH_MULT[] = {MULT_DIST(rng), MULT_DIST(rng)}; // our bases
const hash_int HASH_INV[] = {1 / HASH_MULT[0], 1 / HASH_MULT[1]};
 
vector<hash_int> hash_pow[] = {{1}, {1}};
 
const int INF = int(1e9) + 5;
 
template<typename T_string = string>
struct string_hash {
  static const bool BUILD_REVERSE = true;
 
  static uint64_t hash(const T_string &str) {
    uint64_t result = 0;
 
    for(int h = 0; h < HASH_COUNT; h++) {
      uint64_t value = 1;
      for(const auto &x : str){
        value = (uint64_t(HASH_MULT[h]) * value + x) % HASH_P;
      }
    
      result += value << (32 * h);
    }
 
    return result;
  }
 
  T_string str;
  vector<hash_int> _prefix[HASH_COUNT];
  vector<hash_int> _inv_prefix[HASH_COUNT];
 
  string_hash() {
    build({});
  }
 
  string_hash(const T_string &_str) {
    build(_str);
  }
 
  int length() const {
    return int(_prefix[0].size()) - 1;
  }
 
  template<typename T_char>
  void add_char(const T_char &c) {
    str.push_back(c);
 
    for(int h = 0; h < HASH_COUNT; h++) {
      _prefix[h].push_back(HASH_MULT[h] * _prefix[h].back() + c);
 
      if(hash_pow[h].size() < _prefix[h].size()){
        hash_pow[h].push_back(HASH_MULT[h] * hash_pow[h].back());
      }
      
      if(BUILD_REVERSE){
        _inv_prefix[h].push_back((_inv_prefix[h].back() + c) * HASH_INV[h]);
      }
                
    }
  }
 
  void pop_char() {
    str.pop_back();
 
    for(int h = 0; h < HASH_COUNT; h++) {
      _prefix[h].pop_back();
 
      if(BUILD_REVERSE) {
        _inv_prefix[h].pop_back();
      }
                
    }
  }
 
  void build(const T_string &_str) {
    str = {};
    str.reserve(_str.size());
 
    for(int h = 0; h < HASH_COUNT; h++) {
      hash_pow[h].reserve(_str.size() + 1);
      _prefix[h] = {0};
      _prefix[h].reserve(_str.size() + 1);
 
      if(BUILD_REVERSE) {
        _inv_prefix[h] = {0};
        _inv_prefix[h].reserve(_str.size() + 1);
      }
    }
 
    for(auto &c : _str) add_char(c);
  }
 
  uint64_t _single_hash(int h, int start, int end) const {
    // Convert everything to `uint64_t` for speed. Note: we add hash_pow[length] to fix strings that start with 0.
    uint64_t power = uint64_t(hash_pow[h][end - start]);
    return (power + uint64_t(_prefix[h][end]) + HASH_P2 - uint64_t(_prefix[h][start]) * power) % HASH_P;
  }
 
  uint64_t substring_hash(int start, int end) const {
    assert(0 <= start && start <= end && end <= length());
    return _single_hash(0, start, end) + (HASH_COUNT > 1 ? _single_hash(1, start, end) << 32 : 0);
  }
 
  uint64_t complete_hash() const {
    return substring_hash(0, length());
  }
 
  uint64_t _reverse_single_hash(int h, int start, int end) const {
    // Convert everything to `uint64_t` for speed. Note: we add hash_pow[length] to fix strings that start with 0.
    uint64_t power = uint64_t(hash_pow[h][end - start]);
    return (power + uint64_t(_inv_prefix[h][end]) * power + HASH_P - uint64_t(_inv_prefix[h][start])) % HASH_P;
  }
 
  uint64_t reverse_substring_hash(int start, int end) const {
    assert(0 <= start && start <= end && end <= length());
    return _reverse_single_hash(0, start, end) + (HASH_COUNT > 1 ? _reverse_single_hash(1, start, end) << 32 : 0);
  }
 
  uint64_t reverse_complete_hash() const {
    return reverse_substring_hash(0, length());
  }
 
  bool equal(int start1, int start2, int length) const {
    return substring_hash(start1, start1 + length) == substring_hash(start2, start2 + length);
  }
 
  bool is_palindrome(int start, int end) const {
    return substring_hash(start, end) == reverse_substring_hash(start, end);
  }
 
  int compare(int start1, int start2, int max_length = INF) const;
};
 
uint64_t concat_hashes(uint64_t hash1, uint64_t hash2, int len2) {
  uint64_t hash1_low = hash1 & unsigned(-1);
  uint64_t hash2_low = hash2 & unsigned(-1);
  uint64_t power = uint64_t(hash_pow[0][len2]);
  uint64_t combined = (hash1_low * power + hash2_low + HASH_P - power) % HASH_P;
 
  if (HASH_COUNT > 1) {
    hash1 >>= 32;
    hash2 >>= 32;
    power = uint64_t(hash_pow[1][len2]);
    combined += (hash1 * power + hash2 + HASH_P - power) % HASH_P << 32;
  }
 
  return combined;
}


void solve(){
  
  int n;
  re(n);

  string p;
  re(p);

  string_hash<string> hash(p);

  fr(i,0,n){
    if(hash.is_palindrome(0,i+1) && hash.is_palindrome(i+1,n)){
      cout << p.substr(0,i+1) << "\n";
      return;
    }
  }

  assert(false);

  return;
}

signed main(){
  IO();

  int t;
  re(t);

  fr(i,0,t){
    cout << "Case #" << i+1 << ": ";
    solve();
  }

//   output_run_time();
  return 0;
}