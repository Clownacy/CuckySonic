#pragma once
#include <stdint.h>

#define abs(x) ((x) < 0 ? -(x) : (x))
#define sign(x) (x ? (x / abs(x)) : 0)
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

void GetSine(uint8_t angle, int16_t *sin, int16_t *cos);
uint8_t GetAtan(int16_t x, int16_t y);
