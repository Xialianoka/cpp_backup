#include <iostream>
#include <vector>

int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int main() {
  int m, bagweight;
  std::cin >> m >> bagweight;
  std::vector<int> weight(m);
  std::vector<int> value(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> weight[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> value[i];
  }

  std::vector<int> dp1(bagweight + 1, 0);
  for (int i = weight[0]; i <= bagweight; ++i) {
    dp1[i] = value[0];
  }

  for (int i = 1; i < m; ++i) {
    for (int j = bagweight; j >= 0; --j) {
      if (j >= weight[i]) {
        dp1[j] = max(dp1[j], dp1[j - weight[i]] + value[i]);
      }
    }
  }

  std::cout << dp1[bagweight] << std::endl;
  return 0;
}