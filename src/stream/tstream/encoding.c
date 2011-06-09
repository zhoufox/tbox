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
 * \file		estream.c
 *
 */
/* /////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"
#include "tstream.h"
#include "../../encoding/encoding.h"

/* /////////////////////////////////////////////////////////
 * types
 */

// the encoding stream type
typedef struct __tb_estream_t
{
	// the stream base
	tb_tstream_t 			base;

	// the encoder
	tb_encoder_t const* 	ic;
	tb_encoder_t const* 	oc;

}tb_estream_t;

/* /////////////////////////////////////////////////////////
 * implements
 */

static __tb_inline__ tb_estream_t* tb_estream_cast(tb_gstream_t* gst)
{
	tb_tstream_t* tst = tb_tstream_cast(gst);
	TB_ASSERT_RETURN_VAL(tst && tst->type == TB_TSTREAM_TYPE_ENCODING, TB_NULL);
	return (tb_estream_t*)tst;
}
static tb_bool_t tb_estream_open(tb_gstream_t* gst)
{
	tb_estream_t* est = tb_estream_cast(gst);
	TB_ASSERT_RETURN_VAL(est && est->ic && est->oc, TB_FALSE);

	return tb_tstream_open(gst);
}
static tb_bool_t tb_estream_ioctl1(tb_gstream_t* gst, tb_size_t cmd, void* arg1)
{
	tb_estream_t* est = tb_estream_cast(gst);
	TB_ASSERT_RETURN_VAL(est, TB_FALSE);

	// handle it
	switch (cmd)
	{
	case TB_ESTREAM_CMD_GET_IE:
		{
			tb_encoding_t* pe = (tb_encoding_t*)arg1;
			TB_ASSERT_RETURN_VAL(pe && est->ic, TB_FALSE);
			*pe = est->ic->encoding;
			return TB_TRUE;
		}
	case TB_ESTREAM_CMD_GET_OE:
		{
			tb_encoding_t* pe = (tb_encoding_t*)arg1;
			TB_ASSERT_RETURN_VAL(pe && est->oc, TB_FALSE);
			*pe = est->oc->encoding;
			return TB_TRUE;
		}
	case TB_ESTREAM_CMD_SET_IE:
		{
			est->ic = (tb_encoder_t const*)tb_encoding_get_encoder((tb_encoding_t)arg1);
			return est->ic? TB_TRUE : TB_FALSE;
		}
	case TB_ESTREAM_CMD_SET_OE:
		{
			est->oc = (tb_encoder_t const*)tb_encoding_get_encoder((tb_encoding_t)arg1);
			return est->oc? TB_TRUE : TB_FALSE;
		}
	default:
		break;
	}

	// routine to tstream 
	return tb_tstream_ioctl1(gst, cmd, arg1);
}
static tb_bool_t tb_estream_spank(tb_gstream_t* gst)
{
	tb_estream_t* est = tb_estream_cast(gst);
	tb_tstream_t* tst = tb_tstream_cast(gst);
	TB_ASSERT_RETURN_VAL(est && tst, TB_FALSE);

	// get convecter
	TB_ASSERT_RETURN_VAL(est->ic && est->oc, TB_FALSE);
	tb_encoder_t const* ic = est->ic;
	tb_encoder_t const* oc = est->oc;

	// get input
	TB_ASSERT_RETURN_VAL(tst->ip && tst->in, TB_FALSE);
	tb_byte_t const* ip = tst->ip;
	tb_byte_t const* ie = ip + tst->in;

	// get output
	TB_ASSERT_RETURN_VAL(tst->op, TB_FALSE);
	tb_byte_t* op = tst->op;
	tb_byte_t* oe = tst->ob + TB_GSTREAM_BLOCK_SIZE;

	// spank it
	tb_uint32_t ch;
	while (ip < ie && op < oe)
	{
		if (!ic->get(&ch, &ip, ie - ip)) break;
		if (!oc->set(ch, &op, oe - op)) break;
	}
	//while (ip < ie && op < oe) *op++ = *ip++;

	// check
	TB_ASSERT_RETURN_VAL(ip >= tst->ip && ip <= ie, TB_FALSE);
	TB_ASSERT_RETURN_VAL(op >= tst->op && op <= oe, TB_FALSE);

	// update input
	tst->in -= ip - tst->ip;
	tst->ip = ip;

	// update output
	tst->on += op - tst->op;

	return TB_TRUE;
}
/* /////////////////////////////////////////////////////////
 * interfaces
 */
tb_gstream_t* tb_gstream_create_encoding()
{
	// create stream
	tb_gstream_t* gst = (tb_gstream_t*)tb_calloc(1, sizeof(tb_estream_t));
	tb_tstream_t* tst = (tb_tstream_t*)gst;
	TB_ASSERT_RETURN_VAL(gst, TB_NULL);

	// init gstream
	gst->type 	= TB_GSTREAM_TYPE_TRAN;
	gst->open 	= tb_estream_open;
	gst->close 	= tb_tstream_close;
	gst->read 	= tb_tstream_read;
	gst->ioctl1 = tb_estream_ioctl1;

	// init tstream
	tst->type 	= TB_TSTREAM_TYPE_ENCODING;
	tst->spank 	= tb_estream_spank;

	return gst;
}

tb_gstream_t* tb_gstream_create_from_encoding(tb_gstream_t* gst, tb_size_t ie, tb_size_t oe)
{
	TB_ASSERT_RETURN_VAL(gst, TB_NULL);

	// create encoding stream
	tb_gstream_t* est = tb_gstream_create_encoding();
	TB_ASSERT_RETURN_VAL(est, TB_NULL);

	// set gstream
	if (TB_FALSE == tb_gstream_ioctl1(est, TB_TSTREAM_CMD_SET_GSTREAM, (void*)gst)) goto fail;
		
	// set input encoding
	if (TB_FALSE == tb_gstream_ioctl1(est, TB_ESTREAM_CMD_SET_IE, (void*)ie)) goto fail;
		
	// set output encoding
	if (TB_FALSE == tb_gstream_ioctl1(est, TB_ESTREAM_CMD_SET_OE, (void*)oe)) goto fail;
	
	return est;

fail:
	if (est) tb_gstream_destroy(est);
	return TB_NULL;
}