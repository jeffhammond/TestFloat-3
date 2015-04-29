
/*============================================================================

This C header file is part of TestFloat, Release 3, a package of programs for
testing the correctness of floating-point arithmetic complying with the IEEE
Standard for Floating-Point, by John R. Hauser.

Copyright 2011, 2012, 2013, 2014 The Regents of the University of California
(Regents).  All Rights Reserved.  Redistribution and use in source and binary
forms, with or without modification, are permitted provided that the following
conditions are met:

Redistributions of source code must retain the above copyright notice,
this list of conditions, and the following two paragraphs of disclaimer.
Redistributions in binary form must reproduce the above copyright notice,
this list of conditions, and the following two paragraphs of disclaimer in the
documentation and/or other materials provided with the distribution.  Neither
the name of the Regents nor the names of its contributors may be used to
endorse or promote products derived from this software without specific prior
written permission.

IN NO EVENT SHALL REGENTS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT,
SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING
OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF REGENTS HAS
BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE.  THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED
HEREUNDER IS PROVIDED "AS IS".  REGENTS HAS NO OBLIGATION TO PROVIDE
MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

=============================================================================*/

#include <stdint.h>

/*----------------------------------------------------------------------------
| Warning:  This list must match the contents of "functionInfos.c".
*----------------------------------------------------------------------------*/
enum {
    UI32_TO_F32 = 1,
    UI32_TO_F64,
#ifdef EXTFLOAT80
    UI32_TO_EXTF80,
#endif
#ifdef FLOAT128
    UI32_TO_F128,
#endif
    UI64_TO_F32,
    UI64_TO_F64,
#ifdef EXTFLOAT80
    UI64_TO_EXTF80,
#endif
#ifdef FLOAT128
    UI64_TO_F128,
#endif
    I32_TO_F32,
    I32_TO_F64,
#ifdef EXTFLOAT80
    I32_TO_EXTF80,
#endif
#ifdef FLOAT128
    I32_TO_F128,
#endif
    I64_TO_F32,
    I64_TO_F64,
#ifdef EXTFLOAT80
    I64_TO_EXTF80,
#endif
#ifdef FLOAT128
    I64_TO_F128,
#endif
    F32_TO_UI32,
    F32_TO_UI64,
    F32_TO_I32,
    F32_TO_I64,
    F32_TO_UI32_R_MINMAG,
    F32_TO_UI64_R_MINMAG,
    F32_TO_I32_R_MINMAG,
    F32_TO_I64_R_MINMAG,
    F32_TO_F64,
#ifdef EXTFLOAT80
    F32_TO_EXTF80,
#endif
#ifdef FLOAT128
    F32_TO_F128,
#endif
    F32_ROUNDTOINT,
    F32_ADD,
    F32_SUB,
    F32_MUL,
    F32_MULADD,
    F32_DIV,
    F32_REM,
    F32_SQRT,
    F32_EQ,
    F32_LE,
    F32_LT,
    F32_EQ_SIGNALING,
    F32_LE_QUIET,
    F32_LT_QUIET,
    F64_TO_UI32,
    F64_TO_UI64,
    F64_TO_I32,
    F64_TO_I64,
    F64_TO_UI32_R_MINMAG,
    F64_TO_UI64_R_MINMAG,
    F64_TO_I32_R_MINMAG,
    F64_TO_I64_R_MINMAG,
    F64_TO_F32,
#ifdef EXTFLOAT80
    F64_TO_EXTF80,
#endif
#ifdef FLOAT128
    F64_TO_F128,
#endif
    F64_ROUNDTOINT,
    F64_ADD,
    F64_SUB,
    F64_MUL,
    F64_MULADD,
    F64_DIV,
    F64_REM,
    F64_SQRT,
    F64_EQ,
    F64_LE,
    F64_LT,
    F64_EQ_SIGNALING,
    F64_LE_QUIET,
    F64_LT_QUIET,
#ifdef EXTFLOAT80
    EXTF80_TO_UI32,
    EXTF80_TO_UI64,
    EXTF80_TO_I32,
    EXTF80_TO_I64,
    EXTF80_TO_UI32_R_MINMAG,
    EXTF80_TO_UI64_R_MINMAG,
    EXTF80_TO_I32_R_MINMAG,
    EXTF80_TO_I64_R_MINMAG,
    EXTF80_TO_F32,
    EXTF80_TO_F64,
#ifdef FLOAT128
    EXTF80_TO_F128,
#endif
    EXTF80_ROUNDTOINT,
    EXTF80_ADD,
    EXTF80_SUB,
    EXTF80_MUL,
    EXTF80_DIV,
    EXTF80_REM,
    EXTF80_SQRT,
    EXTF80_EQ,
    EXTF80_LE,
    EXTF80_LT,
    EXTF80_EQ_SIGNALING,
    EXTF80_LE_QUIET,
    EXTF80_LT_QUIET,
#endif
#ifdef FLOAT128
    F128_TO_UI32,
    F128_TO_UI64,
    F128_TO_I32,
    F128_TO_I64,
    F128_TO_UI32_R_MINMAG,
    F128_TO_UI64_R_MINMAG,
    F128_TO_I32_R_MINMAG,
    F128_TO_I64_R_MINMAG,
    F128_TO_F32,
    F128_TO_F64,
#ifdef EXTFLOAT80
    F128_TO_EXTF80,
#endif
    F128_ROUNDTOINT,
    F128_ADD,
    F128_SUB,
    F128_MUL,
    F128_MULADD,
    F128_DIV,
    F128_REM,
    F128_SQRT,
    F128_EQ,
    F128_LE,
    F128_LT,
    F128_EQ_SIGNALING,
    F128_LE_QUIET,
    F128_LT_QUIET,
#endif
    NUM_FUNCTIONS
};

enum {
    ROUND_NEAR_EVEN = 1,
    ROUND_MINMAG,
    ROUND_MIN,
    ROUND_MAX,
    ROUND_NEAR_MAXMAG,
    NUM_ROUNDINGMODES
};
enum {
    TININESS_BEFORE_ROUNDING = 1,
    TININESS_AFTER_ROUNDING,
    NUM_TININESSMODES
};

extern const uint_fast8_t roundingModes[NUM_ROUNDINGMODES];
extern const uint_fast8_t tininessModes[NUM_TININESSMODES];

enum {
    FUNC_ARG_UNARY                    = 0x01,
    FUNC_ARG_BINARY                   = 0x02,
    FUNC_ARG_ROUNDINGMODE             = 0x04,
    FUNC_ARG_EXACT                    = 0x08,
    FUNC_EFF_ROUNDINGPRECISION        = 0x10,
    FUNC_EFF_ROUNDINGMODE             = 0x20,
    FUNC_EFF_TININESSMODE             = 0x40,
    FUNC_EFF_TININESSMODE_REDUCEDPREC = 0x80
};
struct functionInfo {
    const char *namePtr;
    unsigned char attribs;
};
extern const struct functionInfo functionInfos[NUM_FUNCTIONS];

struct standardFunctionInfo {
    const char *namePtr;
    unsigned char functionCode;
    char roundingCode, exact;
};
extern const struct standardFunctionInfo standardFunctionInfos[];

