#include <arm_neon.h>

#include <cstdint>
#include <iostream>

void show(int16_t *p, int num) {
  for (int i = 0; i < num; ++i) {
    std::cout << p[i] << ", ";
  }
  std::cout << std::endl;
}
int main() {
  int16_t data[32];
  int16_t dst[32];
  for (int i = 0; i < 32; ++i) {
    data[i] = i;
  }
  show(data, 32);

  int16x8x2_t vsrc0 = vld2q_s16(data);
  int16x8x2_t vsrc1 = vld2q_s16(data + 2);
  vst1q_s16(dst, 2 * (vsrc0.val[0] + vsrc1.val[0]) + vsrc0.val[1]);
  vst1q_s16(dst + 8, vsrc0.val[1]);

  show(dst, 32);
}