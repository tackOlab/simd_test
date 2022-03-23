#include <arm_neon.h>

#include <cstdio>
int main() {
  int16_t data0[] = {4096, 15421, -1232, -32768};
  int16_t data1[] = {29000, 3121, 1211, -32768};
  int16_t coeff[] = {-25987, -3472, 28931, 29066};
  int16_t offset[] = {8192, 32767, 16384, 32767};

  auto v0 = vld1_s16(data0);
  auto v1 = vld1_s16(data1);
  auto vc = vld1_s16(coeff);
  auto vo = vld1_s16(offset);
  auto vout = vmlal_s16(vo, vc, v0);

  printf("ok\n");
}