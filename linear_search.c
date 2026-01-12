#include <stdio.h>

int main(void) {
  int numbers[10] = {5, 2, 4, 6, 8, 10, 40, 20, 45, 80};

  int search = 10;

  for (int i = 0; i < 10; i++) {
    if (numbers[i] == search) {
      printf("found on index %i", i);
    }
  }
}
