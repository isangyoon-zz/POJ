#include <iostream>
#include <functional>
#include <queue>

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  int N;
  std::cin >> N;

  std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
  for (int i = 0; i < N; ++i)
  {
    int length;
    std::cin >> length;

    pq.push(length);
  }

  long long answer = 0;
  while (pq.size() > 1)
  {
    long long a = pq.top();
    pq.pop();

    long long b = pq.top();
    pq.pop();

    answer += (a + b);

    pq.push(a + b);
  }

  std::cout << answer << "\n";

  return 0;
}
