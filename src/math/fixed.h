/*!The Tiny Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2010, ruki All rights reserved.
 *
 * \author		ruki
 * \file		fixed.h
 *
 */
#ifndef TB_MATH_FIXED_H
#define TB_MATH_FIXED_H

/* ////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"
#include "fixed16.h"

/* ////////////////////////////////////////////////////////////////////////
 * macros
 */
#define TB_FIXED_ONE 				TB_FIXED16_ONE
#define TB_FIXED_HALF 				TB_FIXED16_HALF
#define TB_FIXED_MAX 				TB_FIXED16_MAX
#define TB_FIXED_MIN 				TB_FIXED16_MIN
#define TB_FIXED_NAN 				TB_FIXED16_NAN
#define TB_FIXED_INF 				TB_FIXED16_INF
#define TB_FIXED_PI 				TB_FIXED16_PI
#define TB_FIXED_SQRT2 				TB_FIXED16_SQRT2

// conversion
#ifdef TB_CONFIG_TYPE_FLOAT
# 	define tb_fixed_to_float(x) 	tb_fixed16_to_float(x)
# 	define tb_float_to_fixed(x) 	tb_float_to_fixed16(x)
#endif

#define tb_int_to_fixed(x) 			tb_int_to_fixed16(x)
#define tb_fixed_to_int(x) 			tb_fixed16_to_int(x)

// round
#define tb_fixed_round(x) 			tb_fixed16_round(x)
#define tb_fixed_ceil(x) 			tb_fixed16_ceil(x)
#define tb_fixed_floor(x) 			tb_fixed16_floor(x)

// operations
#define tb_fixed_abs(x) 			tb_fixed16_abs(x)
#define tb_fixed_avg(x, y) 			tb_fixed16_avg(x, y)
#define tb_fixed_mul(x, y) 			tb_fixed16_mul(x, y)
#define tb_fixed_div(x, y) 			tb_fixed16_div(x, y)
#define tb_fixed_muladd(x, y, a) 	tb_fixed16_muladd(x, y, a)
#define tb_fixed_square(x) 			tb_fixed16_square(x)
#define tb_fixed_sqrt(x) 			tb_fixed16_sqrt(x)
#define tb_fixed_sin(x) 			tb_fixed16_sin(x)
#define tb_fixed_cos(x) 			tb_fixed16_cos(x)
#define tb_fixed_tan(x) 			tb_fixed16_tan(x)
#define tb_fixed_asin(x) 			tb_fixed16_asin(x)
#define tb_fixed_acos(x) 			tb_fixed16_acos(x)
#define tb_fixed_atan(x) 			tb_fixed16_atan(x)
#define tb_fixed_exp(x) 			tb_fixed16_exp(x)
#define tb_fixed_ilog2(x) 			tb_fixed16_ilog2(x)




#endif
