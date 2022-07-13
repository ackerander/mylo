#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "myglm.h"
short
eq(const mat4 a, const mat4 b)
{
	for (short i = 0; i < 16; ++i) {
		if (a[i] != b[i])
			return 0;
	}
	return 1;
}

int
main()
{
	mat4 id = {0}, random, out = {0};

	m4id(id);
	srand(time(0));
	for (short i = 0; i < 16; ++i)
		random[i] = 10 - 20.0 * rand() / RAND_MAX;
	printf("%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n", random[0], random[1], random[2], random[3], random[4], random[5], random[6], random[7], random[8], random[9], random[10], random[11], random[12], random[13], random[14], random[15]);
	mm4mult(random, id, out);
	printf(eq(random, out) ? "Equal\n" : "Oh no!\n");
	memset(out, 0, 16 * sizeof(float));
	mm4mult(id, random, out);
	printf(eq(random, out) ? "Equal\n" : "Oh no!\n");

	return 0;
}
