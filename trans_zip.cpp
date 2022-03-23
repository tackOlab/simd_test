//#include <arm64intr.h>
#include <arm_neon.h>

#include <cstdio>

int main() {
  size_t w = 5;
  size_t h = 8;
  int32_t *src = new int32_t[w * h];
  int32_t *dst = new int32_t[w * h];
  for (size_t i = 0; i < w * h; ++i) {
    src[i] = i;
  }
  for (size_t i = 0; i < h; ++i) {
    for (size_t j = 0; j < w; ++j) {
      printf("%3d ", src[i * w + j]);
    }
    printf("\n");
  }
  printf("----\n");
  int32_t *p = dst;
  for (size_t i = 0; i < h - 1; i += 2) {
    int32_t *sp0 = src + i * w;
    int32_t *sp1 = src + (i + 1) * w;
    for (size_t j = 0; j < w; j += 4) {
      auto v0 = vld1q_s32(sp0 + j);
      auto v1 = vld1q_s32(sp1 + j);
      auto vout0 = vzipq_s32(v0, v1);
      vst1q_s32(p, vout0.val[0]);
      p += 4;
      vst1q_s32(p, vout0.val[1]);
      p += 4;
    }
  }

  for (size_t i = 0; i < h; ++i) {
    for (size_t j = 0; j < w; ++j) {
      printf("%3d ", dst[i * w + j]);
    }
    printf("\n");
  }
}