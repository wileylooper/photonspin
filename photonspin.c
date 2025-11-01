#include <stdint.h>

struct photonSpinState64 {
  uint64_t elements[20];
  uint64_t a;
  uint64_t b;
  uint64_t c;
};

struct photonSpinState32 {
  uint32_t elements[20];
  uint32_t a;
  uint32_t b;
  uint32_t c;
};

void photonSpin64(struct photonSpinState64 *s) {
  uint64_t mix[4] = {
    s->elements[s->a & 15],
    s->elements[(s->a + 3) & 15],
    s->elements[(s->a + 6) & 15],
    s->elements[(s->a + 9) & 15]
  };
  unsigned char i = 0;
  unsigned char j;
  unsigned char k = 0;

  s->a += 1111111111111;

  while (i < 4) {
    s->b += s->a;
    s->c ^= s->a;
    mix[i] += (s->b << 19) | (s->b >> 45);
    j = 0;

    while (j < 5) {
      s->elements[k] += (mix[i] << 51) | (mix[i] >> 13);
      s->elements[k] ^= s->c;
      mix[i] += s->elements[k];
      j++;
      k++;
    }

    i++;
  }

  s->b += (mix[0] << 47) | (mix[0] >> 17);
  s->b ^= mix[1];
  s->c += (mix[2] << 25) | (mix[2] >> 39);
  s->c ^= mix[3];
}

void photonSpin32(struct photonSpinState32 *s) {
  uint32_t mix[4] = {
    s->elements[s->a & 15],
    s->elements[(s->a + 3) & 15],
    s->elements[(s->a + 6) & 15],
    s->elements[(s->a + 9) & 15]
  };
  unsigned char i = 0;
  unsigned char j;
  unsigned char k = 0;

  s->a += 111111;

  while (i < 4) {
    s->b += s->a;
    s->c ^= s->a;
    mix[i] += (s->b << 9) | (s->b >> 23);
    j = 0;

    while (j < 5) {
      s->elements[k] += (mix[i] << 25) | (mix[i] >> 7);
      s->elements[k] ^= s->c;
      mix[i] += s->elements[k];
      j++;
      k++;
    }

    i++;
  }

  s->b += (mix[0] << 23) | (mix[0] >> 9);
  s->b ^= mix[1];
  s->c += (mix[2] << 13) | (mix[2] >> 19);
  s->c ^= mix[3];
}
