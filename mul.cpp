#include <arm_neon.h>

#include <cstdint>
#include <cstdio>
#include <cstdlib>

#define LENGTH 32

void neon_mul_0(int32_t* in0, int32_t* in1, int32_t* out, size_t len) {
  for (size_t i = 0; i < len; i += 4) {
    int32x4_t v0 = vld1q_s32(in0 + i);
    int32x4_t v1 = vld1q_s32(in1 + i);
    // int32x4_t vout = vmulq_s32(v0, v1);
    vst1q_s32(out + i, v0 * v1);
  }
}
void normal_mul(int32_t* in0, int32_t* in1, int32_t* out, size_t len) {
  for (size_t i = 0; i < len; ++i) {
    out[i] = in0[i] * in1[i];
  }
}

void setup(int32_t* data, size_t len) {
  for (size_t i = 0; i < len; ++i) {
    data[i] = rand() % 256;
  }
}

int main() {
  int32_t* d0 = new int32_t[LENGTH];
  int32_t* d1 = new int32_t[LENGTH];
  int32_t* dout = new int32_t[LENGTH];
  setup(d0, LENGTH);
  setup(d1, LENGTH);
  neon_mul_0(d0, d1, dout, LENGTH);
  normal_mul(d0, d1, dout, LENGTH);
  for (size_t i = 0; i < LENGTH; ++i) {
    printf("[%lu] = %d\n", i, dout[i]);
  }
  delete[] d0;
  delete[] d1;
  delete[] dout;
}