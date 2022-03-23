#include <arm_neon.h>

#include <cstdio>
int main() {
  int16_t data0[] = {4096, 15421, -1232, -32768};
  int16_t data1[] = {29000, 3121, 1211, -32768};

  auto v0 = vld1_s16(data0);
  auto v1 = vld1_s16(data1);
  auto vout = vhadd_s16(v0, v1);

  printf("ok\n");
}