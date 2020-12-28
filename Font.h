#pragma once

#include <stdint.h>

// Used for easy define big Bitmap as 0bXXXXXXXXX image
#define _BMP8(d)                                                        ((d)&0xFF)
#define _BMP16(d)                                      (((d)>>8)&0xFF), ((d)&0xFF)
#define _BMP24(d)                    (((d)>>16)&0xFF), (((d)>>8)&0xFF), ((d)&0xFF)
#define _BMP32(d)  (((d)>>24)&0xFF), (((d)>>16)&0xFF), (((d)>>8)&0xFF), ((d)&0xFF)

// Additional chars in fonts
#define S_DELTA    "\027"  // hex 0x17
#define S_SARROW   "\030"  // hex 0x18
#define S_INFINITY "\031"  // hex 0x19
#define S_LARROW   "\032"  // hex 0x1A
#define S_RARROW   "\033"  // hex 0x1B
#define S_PI       "\034"  // hex 0x1C
#define S_MICRO    "\035"  // hex 0x1D
#define S_OHM      "\036"  // hex 0x1E
#define S_DEGREE   "\037"  // hex 0x1F

#ifndef DISPLAY_ST7796
extern const uint8_t x5x7_bits [];
// Font definitions
#define FONT_START_CHAR   0x17
#define FONT_MAX_WIDTH       7
#define FONT_WIDTH           5
#define FONT_GET_HEIGHT      7
#define FONT_STR_HEIGHT      8
#define FONT_GET_DATA(ch)    (  &x5x7_bits[(ch-FONT_START_CHAR)*FONT_GET_HEIGHT])
#define FONT_GET_WIDTH(ch)   (8-(x5x7_bits[(ch-FONT_START_CHAR)*FONT_GET_HEIGHT]&7))

#else
extern const uint8_t x7x11b_bits[];
// Font definitions
#define FONT_START_CHAR   0x17
#define FONT_MAX_WIDTH       8
#define FONT_WIDTH           7
#define FONT_GET_HEIGHT     11
#define FONT_STR_HEIGHT     11
#define FONT_GET_DATA(ch)   (  &x7x11b_bits[(ch-FONT_START_CHAR)*FONT_GET_HEIGHT])
#define FONT_GET_WIDTH(ch)  (8-(x7x11b_bits[(ch-FONT_START_CHAR)*FONT_GET_HEIGHT]&7))

#endif

extern const uint8_t numfont16x22[];
#define NUM_FONT_GET_WIDTH      16
#define NUM_FONT_GET_HEIGHT     22
#define NUM_FONT_GET_DATA(ch)   (&numfont16x22[ch*2*NUM_FONT_GET_HEIGHT])
