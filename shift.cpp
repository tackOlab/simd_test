#if defined(__ARM_NEON) || defined(__ARM_NEON__)
  #include <arm_neon.h>
#endif

#include <cstdio>

int main() {
  int32_t data[4] = {0, 1, 2, 3};
  auto v0         = vld1q_s32(data);
  auto vout       = vshlq_n_s32(vshrq_n_s32(v0, 1), 1) + 1;
  return 0;
}