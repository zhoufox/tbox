#include "tbox.h"

static tb_uint64_t tb_uint64_test_add(tb_uint32_t x, tb_uint32_t y)
{
	tb_uint64_t r = tb_uint64_add(tb_uint32_to_uint64(x), tb_uint32_to_uint64(y));
	tb_printf("[uint64]: %u + %u = %llu\n", x, y, r);
	return r;
}
static tb_uint64_t tb_uint64_test_add_uint32(tb_uint64_t x, tb_uint32_t y)
{
	tb_uint64_t r = tb_uint64_add_uint32(x, y);
	tb_printf("[uint64]: %llu + %u = %llu\n", x, y, r);
	return r;
}
static tb_uint64_t tb_uint64_test_sub(tb_uint64_t x, tb_uint64_t y)
{
	tb_uint64_t r = tb_uint64_sub(x, y);
	tb_printf("[uint64]: %llu - %llu = %llu\n", x, y, r);
	return r;
}
static tb_uint64_t tb_uint64_test_sub_uint32(tb_uint64_t x, tb_uint32_t y)
{
	tb_uint64_t r = tb_uint64_sub_uint32(x, y);
	tb_printf("[uint64]: %llu - %u = %llu\n", x, y, r);
	return r;
}
static tb_uint64_t tb_uint64_test_mul(tb_uint64_t x, tb_uint64_t y)
{
	tb_uint64_t r = tb_uint64_mul(x, y);
	tb_printf("[uint64]: %llu * %llu = %llu\n", x, y, r);
	return r;
}
static tb_uint64_t tb_uint64_test_mul_uint32(tb_uint64_t x, tb_uint32_t y)
{
	tb_uint64_t r = tb_uint64_mul_uint32(x, y);
	tb_printf("[uint64]: %llu * %u = %llu\n", x, y, r);
	return r;
}
static tb_uint64_t tb_uint64_test_not(tb_uint64_t x)
{
	tb_uint64_t r = tb_uint64_not(x);
	tb_printf("[uint64]: ~%llu = %llu\n", x, r);
	return r;
}
static tb_uint64_t tb_uint64_test_or(tb_uint64_t x, tb_uint64_t y)
{
	tb_uint64_t r = tb_uint64_or(x, y);
	tb_printf("[uint64]: %llu | %llu = %llu\n", x, y, r);
	return r;
}
static tb_uint64_t tb_uint64_test_or_uint32(tb_uint64_t x, tb_uint32_t y)
{
	tb_uint64_t r = tb_uint64_or_uint32(x, y);
	tb_printf("[uint64]: %llu | %u = %llu\n", x, y, r);
	return r;
}
static tb_uint64_t tb_uint64_test_and(tb_uint64_t x, tb_uint64_t y)
{
	tb_uint64_t r = tb_uint64_and(x, y);
	tb_printf("[uint64]: %llu & %llu = %llu\n", x, y, r);
	return r;
}
static tb_uint64_t tb_uint64_test_and_uint32(tb_uint64_t x, tb_uint32_t y)
{
	tb_uint64_t r = tb_uint64_and_uint32(x, y);
	tb_printf("[uint64]: %llu & %u = %llu\n", x, y, r);
	return r;
}
static tb_uint64_t tb_uint64_test_xor(tb_uint64_t x, tb_uint64_t y)
{
	tb_uint64_t r = tb_uint64_xor(x, y);
	tb_printf("[uint64]: %llu ^ %llu = %llu\n", x, y, r);
	return r;
}
static tb_uint64_t tb_uint64_test_xor_uint32(tb_uint64_t x, tb_uint32_t y)
{
	tb_uint64_t r = tb_uint64_xor_uint32(x, y);
	tb_printf("[uint64]: %llu ^ %u = %llu\n", x, y, r);
	return r;
}
static tb_uint64_t tb_uint64_test_lsh(tb_uint64_t x, tb_uint32_t b)
{
	tb_uint64_t r = tb_uint64_lsh(x, b);
	tb_printf("[uint64]: %llu << %u = %llu\n", x, b, r);
	return r;
}
static tb_uint64_t tb_uint64_test_rsh(tb_uint64_t x, tb_uint32_t b)
{
	tb_uint64_t r = tb_uint64_rsh(x, b);
	tb_printf("[uint64]: %llu >> %u = %llu\n", x, b, r);
	return r;
}
static tb_size_t tb_uint64_test_clz(tb_uint64_t x)
{
	tb_size_t r = tb_uint64_clz(x);
	tb_printf("[uint64]: clz: %llu = %u\n", x, r);
	return r;
}
int main(int argc, char** argv)
{
	if (!tb_init(malloc(1024 * 1024), 1024 * 1024)) return 0;


	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_add:\n");
	tb_uint64_t a0 = tb_uint64_test_add(0x0, 0xf);
	tb_uint64_t a1 = tb_uint64_test_add(0xf, 0xff);
	tb_uint64_t a2 = tb_uint64_test_add(0xff, 0xfff);
	tb_uint64_t a3 = tb_uint64_test_add(0xfff, 0xffff);
	tb_uint64_t a4 = tb_uint64_test_add(0xffff, 0xfffff);
	tb_uint64_t a5 = tb_uint64_test_add(0xfffff, 0xffffff);
	tb_uint64_t a6 = tb_uint64_test_add(0xffffff, 0xfffffff);
	tb_uint64_t a7 = tb_uint64_test_add(0xfffffff, 0xfffffff);
	tb_uint64_t a8 = tb_uint64_test_add(0xffffffff, 0xffffffff);
	
	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_add_uint32:\n");
	tb_uint64_test_add_uint32(a0, 0xf);
	tb_uint64_test_add_uint32(a1, 0xff);
	tb_uint64_test_add_uint32(a2, 0xfff);
	tb_uint64_test_add_uint32(a3, 0xffff);
	tb_uint64_test_add_uint32(a4, 0xfffff);
	tb_uint64_test_add_uint32(a5, 0xffffff);
	tb_uint64_test_add_uint32(a6, 0xfffffff);
	tb_uint64_test_add_uint32(a7, 0xfffffff);
	tb_uint64_test_add_uint32(a8, 0xffffffff);

	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_sub:\n");
	tb_uint64_test_sub(a1, a0);
	tb_uint64_test_sub(a0, a1);
	tb_uint64_test_sub(a3, a2);
	tb_uint64_test_sub(a2, a3);
	tb_uint64_test_sub(a5, a4);
	tb_uint64_test_sub(a4, a5);
	tb_uint64_test_sub(a7, a6);
	tb_uint64_test_sub(a6, a7);
	tb_uint64_test_sub(a8, a7);
	tb_uint64_test_sub(a7, a8);
	tb_uint64_test_sub(a8, a1);
	tb_uint64_test_sub(a1, a8);
	tb_uint64_test_sub(a8, a8);
	
	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_sub_uint32:\n");
	tb_uint64_test_sub_uint32(a1, 0x0);
	tb_uint64_test_sub_uint32(a0, 0xf);
	tb_uint64_test_sub_uint32(a3, 0xff);
	tb_uint64_test_sub_uint32(a2, 0xfff);
	tb_uint64_test_sub_uint32(a5, 0xffff);
	tb_uint64_test_sub_uint32(a4, 0xfffff);
	tb_uint64_test_sub_uint32(a7, 0xffffff);
	tb_uint64_test_sub_uint32(a6, 0xfffffff);
	tb_uint64_test_sub_uint32(a8, 0xffffffff);
	tb_uint64_test_sub_uint32(a7, 0xfffffff);
	tb_uint64_test_sub_uint32(a8, 0xffffff);
	tb_uint64_test_sub_uint32(a1, 0xfffff);
	tb_uint64_test_sub_uint32(a8, 0xffff);

#if 0
	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_mul:\n");
	tb_uint64_test_mul(a1, a0);
	tb_uint64_test_mul(a0, a1);
	tb_uint64_test_mul(a3, a2);
	tb_uint64_test_mul(a2, a3);
	tb_uint64_test_mul(a5, a4);
	tb_uint64_test_mul(a4, a5);
	tb_uint64_test_mul(a7, a6);
	tb_uint64_test_mul(a6, a7);
	tb_uint64_test_mul(a8, a7);
	tb_uint64_test_mul(a7, a8);
	tb_uint64_test_mul(a8, a1);
	tb_uint64_test_mul(a1, a8);
	tb_uint64_test_mul(a8, a8);
	
	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_mul_uint32:\n");
	tb_uint64_test_mul_uint32(a1, 0x0);
	tb_uint64_test_mul_uint32(a0, 0xf);
	tb_uint64_test_mul_uint32(a3, 0xff);
	tb_uint64_test_mul_uint32(a2, 0xfff);
	tb_uint64_test_mul_uint32(a5, 0xffff);
	tb_uint64_test_mul_uint32(a4, 0xfffff);
	tb_uint64_test_mul_uint32(a7, 0xffffff);
	tb_uint64_test_mul_uint32(a6, 0xfffffff);
	tb_uint64_test_mul_uint32(a8, 0xffffffff);
	tb_uint64_test_mul_uint32(a7, 0xfffffff);
	tb_uint64_test_mul_uint32(a8, 0xffffff);
	tb_uint64_test_mul_uint32(a1, 0xfffff);
	tb_uint64_test_mul_uint32(a8, 0xffff);
#endif

	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_or:\n");
	tb_uint64_test_or(a1, a0);
	tb_uint64_test_or(a0, a1);
	tb_uint64_test_or(a3, a2);
	tb_uint64_test_or(a2, a3);
	tb_uint64_test_or(a5, a4);
	tb_uint64_test_or(a4, a5);
	tb_uint64_test_or(a7, a6);
	tb_uint64_test_or(a6, a7);
	tb_uint64_test_or(a8, a7);
	tb_uint64_test_or(a7, a8);
	tb_uint64_test_or(a8, a1);
	tb_uint64_test_or(a1, a8);
	tb_uint64_test_or(a8, a8);
	
	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_or_uint32:\n");
	tb_uint64_test_or_uint32(a1, 0x0);
	tb_uint64_test_or_uint32(a0, 0xf);
	tb_uint64_test_or_uint32(a3, 0xff);
	tb_uint64_test_or_uint32(a2, 0xfff);
	tb_uint64_test_or_uint32(a5, 0xffff);
	tb_uint64_test_or_uint32(a4, 0xfffff);
	tb_uint64_test_or_uint32(a7, 0xffffff);
	tb_uint64_test_or_uint32(a6, 0xfffffff);
	tb_uint64_test_or_uint32(a8, 0xffffffff);
	tb_uint64_test_or_uint32(a7, 0xfffffff);
	tb_uint64_test_or_uint32(a8, 0xffffff);
	tb_uint64_test_or_uint32(a1, 0xfffff);
	tb_uint64_test_or_uint32(a8, 0xffff);
	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_and:\n");
	tb_uint64_test_and(a1, a0);
	tb_uint64_test_and(a0, a1);
	tb_uint64_test_and(a3, a2);
	tb_uint64_test_and(a2, a3);
	tb_uint64_test_and(a5, a4);
	tb_uint64_test_and(a4, a5);
	tb_uint64_test_and(a7, a6);
	tb_uint64_test_and(a6, a7);
	tb_uint64_test_and(a8, a7);
	tb_uint64_test_and(a7, a8);
	tb_uint64_test_and(a8, a1);
	tb_uint64_test_and(a1, a8);
	tb_uint64_test_and(a8, a8);
	
	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_and_uint32:\n");
	tb_uint64_test_and_uint32(a1, 0x0);
	tb_uint64_test_and_uint32(a0, 0xf);
	tb_uint64_test_and_uint32(a3, 0xff);
	tb_uint64_test_and_uint32(a2, 0xfff);
	tb_uint64_test_and_uint32(a5, 0xffff);
	tb_uint64_test_and_uint32(a4, 0xfffff);
	tb_uint64_test_and_uint32(a7, 0xffffff);
	tb_uint64_test_and_uint32(a6, 0xfffffff);
	tb_uint64_test_and_uint32(a8, 0xffffffff);
	tb_uint64_test_and_uint32(a7, 0xfffffff);
	tb_uint64_test_and_uint32(a8, 0xffffff);
	tb_uint64_test_and_uint32(a1, 0xfffff);
	tb_uint64_test_and_uint32(a8, 0xffff);

	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_xor:\n");
	tb_uint64_test_xor(a1, a0);
	tb_uint64_test_xor(a0, a1);
	tb_uint64_test_xor(a3, a2);
	tb_uint64_test_xor(a2, a3);
	tb_uint64_test_xor(a5, a4);
	tb_uint64_test_xor(a4, a5);
	tb_uint64_test_xor(a7, a6);
	tb_uint64_test_xor(a6, a7);
	tb_uint64_test_xor(a8, a7);
	tb_uint64_test_xor(a7, a8);
	tb_uint64_test_xor(a8, a1);
	tb_uint64_test_xor(a1, a8);
	tb_uint64_test_xor(a8, a8);
	
	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_xor_uint32:\n");
	tb_uint64_test_xor_uint32(a1, 0x0);
	tb_uint64_test_xor_uint32(a0, 0xf);
	tb_uint64_test_xor_uint32(a3, 0xff);
	tb_uint64_test_xor_uint32(a2, 0xfff);
	tb_uint64_test_xor_uint32(a5, 0xffff);
	tb_uint64_test_xor_uint32(a4, 0xfffff);
	tb_uint64_test_xor_uint32(a7, 0xffffff);
	tb_uint64_test_xor_uint32(a6, 0xfffffff);
	tb_uint64_test_xor_uint32(a8, 0xffffffff);
	tb_uint64_test_xor_uint32(a7, 0xfffffff);
	tb_uint64_test_xor_uint32(a8, 0xffffff);
	tb_uint64_test_xor_uint32(a1, 0xfffff);
	tb_uint64_test_xor_uint32(a8, 0xffff);

	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_clz:\n");
	tb_uint64_test_clz(TB_UINT64_ZERO);
	tb_uint64_test_clz(TB_UINT64_ONE);
	tb_uint64_test_clz(a0);
	tb_uint64_test_clz(a1);
	tb_uint64_test_clz(a2);
	tb_uint64_test_clz(a3);
	tb_uint64_test_clz(a4);
	tb_uint64_test_clz(a5);
	tb_uint64_test_clz(a6);
	tb_uint64_test_clz(a7);
	tb_uint64_test_clz(a8);

	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_not:\n");
	tb_uint64_test_not(TB_UINT64_ZERO);
	tb_uint64_test_not(TB_UINT64_ONE);
	tb_uint64_test_not(a0);
	tb_uint64_test_not(a1);
	tb_uint64_test_not(a2);
	tb_uint64_test_not(a3);
	tb_uint64_test_not(a4);
	tb_uint64_test_not(a5);
	tb_uint64_test_not(a6);
	tb_uint64_test_not(a7);
	tb_uint64_test_not(a8);

	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_lsh:\n");
	tb_uint64_test_lsh(a1, 0);
	tb_uint64_test_lsh(a0, 4);
	tb_uint64_test_lsh(a3, 7);
	tb_uint64_test_lsh(a2, 8);
	tb_uint64_test_lsh(a5, 10);
	tb_uint64_test_lsh(a4, 15);
	tb_uint64_test_lsh(a7, 16);
	tb_uint64_test_lsh(a6, 17);
	tb_uint64_test_lsh(a8, 28);
	tb_uint64_test_lsh(a7, 29);
	tb_uint64_test_lsh(a8, 32);
	tb_uint64_test_lsh(a1, 34);
	tb_uint64_test_lsh(a8, 63);

	tb_printf("==================================================\n");
	tb_printf("tb_uint64_test_rsh:\n");
	tb_uint64_test_rsh(a1, 0);
	tb_uint64_test_rsh(a0, 4);
	tb_uint64_test_rsh(a3, 7);
	tb_uint64_test_rsh(a2, 8);
	tb_uint64_test_rsh(a5, 10);
	tb_uint64_test_rsh(a4, 15);
	tb_uint64_test_rsh(a7, 16);
	tb_uint64_test_rsh(a6, 17);
	tb_uint64_test_rsh(a8, 28);
	tb_uint64_test_rsh(a7, 29);
	tb_uint64_test_rsh(a8, 32);
	tb_uint64_test_rsh(a1, 34);
	tb_uint64_test_rsh(a8, 63);



	return 0;
}
