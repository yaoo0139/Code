#include <stdio.h>

int cyclelength(int n) {
  if (n == 1) {
    return 1;
  }
  else if (n % 2) {
    return 1 + cyclelength(3 * n + 1);
  }
  else {
    return 1 + cyclelength(n / 2);
  }
}

int main() {
  int i, j;
  while (scanf("%d%d", &i, &j) != EOF) {
    int maxLength = 0;
    int minValue = (i < j) ? i : j;
    int maxValue = (i > j) ? i : j;

    for (int value = minValue ; minValue <= maxValue; ++minValue) {
      int termLength = cyclelength(minValue);
      maxLength = (termLength > maxLength) ? termLength : maxLength;
    }

    printf("%d %d %d\n", i, j, maxLength);
  }
  return 0;
}