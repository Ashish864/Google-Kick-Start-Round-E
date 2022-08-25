#include <bits/stdc++.h>
#define int int64_t //be careful about this 

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

  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int my_rand(int L, int R){ 
    return uniform_int_distribution<int>(L,R)(rng); }
  
  template<class T> int sz(const T& x){ 
    return int(x.size()); }

  template<class T> int lb(const vector<T>& vec,const T& val){
    return int(lower_bound(vec.begin(), vec.end(),val) - vec.begin()); }

  template<class T> int ub(const vector<T>& vec,const T& val){
    return int(upper_bound(vec.begin(), vec.end(),val) - vec.begin()); }

  constexpr int  dx[4] = {-1,0,0,1};
  constexpr int  dy[4] = {0,1,-1,0};

  constexpr long long INFLL1 = 1e16, INFLL2 = 9e18;
  constexpr int INF = 2e9;
}


using namespace IN;
using namespace OUT;
using namespace FUNC;

















template<typename T>
T fdiv(T a,T b){ 
  return a/b - ((a^b) < 0 && a%b); 
}




void solve(){
  
  int N,P,M,Ar,Ac;
  re(N,P,M,Ar,Ac);
  --Ar,--Ac;

  vt<pr<char,int>> op(4);
  re(op);

  vt<int> locx(P),locy(P),c(P);
  vt<vt<int>> wh(N,vt<int>(N,-1));
  fr(i,0,P){
    re(locx[i],locy[i],c[i]);
    --locx[i],--locy[i];
    wh[locx[i]][locy[i]] = i;
  }

  int dp[N][N][1 << P][M + 1];

  fr(i,0,N) fr(j,0,N) fr(k,0,1<<P) fr(u,0,M+1) dp[i][j][k][u] = -INFLL1;

  dp[Ar][Ac][0][0] = 0;

  priority_queue<pair<int,ar<int,4>>> pq;

  pq.push({dp[Ar][Ac][0][0],{Ar,Ac,0,0}});

  int ans = -INFLL1;

  while(!pq.empty()){
    auto [vv,aa] = pq.top(); pq.pop();
    auto [i,j,mask,t] = aa;

    assert(t <= M);
    if(mask == (1 << P) - 1) ckmax(ans,dp[i][j][mask][t]);

    if(dp[i][j][mask][t] != vv) continue;

    // stay here.
    if(t + 1 <= M && ckmax(dp[i][j][mask][t+1],dp[i][j][mask][t]))
      pq.push({dp[i][j][mask][t+1],{i,j,mask,t+1}});

    // deliver here if not.
    if(t <= M && wh[i][j] >= 0 && !(mask >> wh[i][j] & 1)){
      if(ckmax(dp[i][j][mask^(1<<wh[i][j])][t],dp[i][j][mask][t]+c[wh[i][j]]))
        pq.push({dp[i][j][mask^(1<<wh[i][j])][t],{i,j,mask^(1<<wh[i][j]),t}});
    }

    // move in four directions.
    fr(k,0,4){
      int ni = i + dx[k], nj = j + dy[k];
      if(ni >= 0 && nj >= 0 && ni < N && nj < N){
        int cost, cc = dp[i][j][mask][t];
        if(op[k].f == '+') cost = cc + op[k].s;
        if(op[k].f == '-') cost = cc - op[k].s;
        if(op[k].f == '*') cost = cc * op[k].s;
        if(op[k].f == '/') cost = fdiv(cc, op[k].s);
        if(t + 1 <= M && ckmax(dp[ni][nj][mask][t+1],cost)){
          pq.push({dp[ni][nj][mask][t+1],{ni,nj,mask,t+1}});
        }
      }
    }

  }

  if(ans == -INFLL1)
    cout << "IMPOSSIBLE" << "\n";
  else
    cout << ans << "\n";

  return;
}

signed main(){
  IO();
  int t; re(t);
  fr(i,0,t){
    cout << "Case #" << i+1 << ": ";
    solve();
  }
//   output_run_time();
  return 0;
}