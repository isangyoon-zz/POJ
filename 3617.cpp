#include <iostream>
#include <vector>

int N;
std::vector<char> S;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  S.resize(N);
  for (int i = 0; i < N; ++i) std::cin >> S[i];

  int p1 = 0;
  int p2 = N - 1;
  int size = 0;
  while (p1 <= p2)
  {
    bool flag = false;
    for (int i = 0; p1 + i <= p2; ++i)
    {
      if (S[p1 + i] < S[p2 - i])
      {
        flag = true;

        break;
      }
      else if (S[p1 + i] > S[p2 - i])
      {
        flag = false;

        break;
      }
    }
    
    ++size;
    std::cout << ((flag) ? S[p1++] : S[p2--]) << ((size % 80) ? "" : "\n");
  }

  return 0;
}
