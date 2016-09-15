#include <cstdio>
#include <vector>

class unionfind
{
public:
  unionfind(int const n) : _parent(n, 0), _rank(n, 0)
  {
    for (int i = 0; i < n; ++i) _parent[i] = i;
  }
  ~unionfind() {}

  int find(int v)
  {
    return (_parent[v] == v) ? v : _parent[v] = find(_parent[v]);
  }

  void unite(int v, int u)
  {
    v = find(v);
    u = find(u);
    if (v == u) return;

    if (_rank[v] < _rank[u])
    {
      _parent[v] = u;
    }
    else
    {
      _parent[u] = v;
      if (_rank[v] == _rank[u]) ++_rank[v];
    }
  }

  bool same(int v, int u)
  {
    return find(v) == find(u);
  }

private:
  std::vector<int> _parent;
  std::vector<int> _rank;
};

int main(int const argc, char const** argv)
{
  int N, K;
  scanf("%d %d", &N, &K);

  int answer = 0;
  unionfind set(3 * N);
  for (int i = 0; i < K; ++i)
  {
    int D, X, Y;
    scanf("%d %d %d", &D, &X, &Y);
    --X, --Y;

    if (X < 0 || X >= N || Y < 0 || Y >= N)
    {
      ++answer;
      continue;
    }

    if (D == 1)
    {
      if (set.same(X, Y + N) || set.same(X, Y + 2 * N))
      {
        ++answer;

        continue;
      }

      set.unite(X, Y);
      set.unite(X + N, Y + N);
      set.unite(X + 2 * N, Y + 2 * N);
    }
    else if (D == 2)
    {
      if (set.same(X, Y) || set.same(X, Y + 2 * N) || set.same(X + N, Y + N) || set.same(X + N, Y) || set.same(X + 2 * N, Y + 2 * N) || set.same(X + 2 * N, Y + N))
      {
        ++answer;

        continue;
      }

      set.unite(X, Y + N);
      set.unite(X + N, Y + 2 * N);
      set.unite(X + 2 * N, Y);
    }
  }

  printf("%d\n", answer);

  return 0;
}
