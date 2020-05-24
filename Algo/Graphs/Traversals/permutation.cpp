#include <bits/stdc++.h>
using namespace std;
 
int n, ans = 0;
set< vector<int> > st;
 
bool chk(vector<int> &x) {
  for(int i = 1; i < n; i++) {
    if(x[i] < x[i - 1]) return 0;
  }
  return 1;
}
/*
// DFS solution
map< vector<int>, int > mp;
void dfs(vector<int> cur, int d) {
  if(chk(cur)) {
    ans = min(ans, d);
    return;
  }
  for(int i = 2; i <= n; i++) {
    vector<int> go(cur);
    reverse(go.begin(), go.begin() + i);
    auto f = mp.find(go);
    if(f == mp.end() || f->second > d) {
      mp[go] = d;
      dfs(go, d + 1);
    }
  }
}
*/
//BFS
void bfs(vector<int> cur) {
  queue< pair< vector<int>, int > > Q;
  Q.push({cur, 0});
  while(!Q.empty()) {
    auto f = Q.front(); Q.pop();
    if(chk(f.first)) {
      ans = f.second;
      return;
    }
    for(int i = 2; i <= n; i++) {
      vector<int> go(f.first);
      reverse(go.begin(), go.begin() + i);
      if(st.find(go) == st.end()) {
        st.insert(go);
        Q.push({go, f.second + 1});
      }
    }
  }
}

 
int main() {
  scanf("%d", &n);
  vector<int> inp;
  for(int i = 0, t; i < n; i++) {
    scanf("%d", &t);
    inp.push_back(t);
  }
  bfs(inp);
  printf("%d\n", ans);
  return 0;
}