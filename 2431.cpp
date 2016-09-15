#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

int main(int const argc, char const** argv)
{
  int N, L, P;

  std::cin >> N;

  std::vector<std::pair<int, int>> stop(N + 1); // position, amount
  for (int i = 0; i < N; ++i) std::cin >> stop[i].first >> stop[i].second;

  std::cin >> L >> P;

  std::sort(stop.begin(), stop.end(), std::greater<std::pair<int, int>>());

  std::priority_queue<int> pq;
  std::vector<std::pair<int, int>>::iterator it = stop.begin(); // auto it = stop.begin();
  int d = L - P;
  int answer = 0;
  while (d > 0)
  {
    while (it != stop.end() && it->first >= d)
    {
      pq.push(it->second);

      ++it;
    }

    if (pq.empty())
    {
      answer = -1;

      break;
    }
    else
    {
      d -= pq.top();
      pq.pop();

      ++answer;
    }
  }

  std::cout << answer << "\n";

  return 0;
}
