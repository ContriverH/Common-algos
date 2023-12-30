#include <bits/sdtc++.h>
using namespace std;

class DSU
{
  int n;
  vector<int> parent;
  vector<int> rank;

  DSU(int N)
  {
    n = N;
    parent.resize(n);
    rank.resize(n);

    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int Find(int i)
  {
    if (parent[i] != i)
      parent[i] = Find(parent[i]);
    return i;
  }

  void Union(int u, int v)
  {
    int u_set = Find(u);
    int v_set = Find(v);

    if (u_set == v_set)
    {
      rank[u_set] += 1;
    }

    if (rank[u_set] > rank[v_set])
      parent[v_set] = parent[u_set];
    else
      parent[u_set] = parent[v_set];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    sdZ])
  }
};

int main()
{
  return 0;
}