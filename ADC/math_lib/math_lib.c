#include "math_lib.h"
uint32_t Prescaler(uint32_t value, uint32_t pres)
{
	uint32_t res = value / pres;
	return res;
}