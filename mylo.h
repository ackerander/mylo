#ifndef MYGLM_H
#define MYGLM_H
#include <math.h>
#include <string.h>
#define LOFUN static inline

typedef float vec3[3];
typedef float mat3[9];
typedef float vec4[4];
typedef float mat4[16];

LOFUN void v3norm(vec3 v);
LOFUN float v3mag(const vec3 v);
LOFUN void v3scaleeq(float c, vec3 v);
LOFUN void v3scale(float c, const vec3 a, vec3 b);
LOFUN float v3dot(const vec3 a, const vec3 b);
LOFUN void v3add(const vec3 a, const vec3 b, vec3 c);
LOFUN void v3addeq(const vec3 a, vec3 b);
LOFUN void v3sub(const vec3 a, const vec3 b, vec3 c);
LOFUN void v3hadamard(const vec3 a, const vec3 b, vec3 c);
LOFUN void v3hadamardeq(const vec3 a, vec3 b);
LOFUN void cross(const vec3 a, const vec3 b, vec3 c);
LOFUN void m3zero(mat3 a);
LOFUN void m3id(mat3 a);
LOFUN void m3scale(float a, mat3 m);
LOFUN void m3add(const mat3 a, const mat3 b, mat3 c);
LOFUN void m3addeq(const mat3 a, mat3 b);
LOFUN void m3hadamard(const mat3 a, const mat3 b, mat3 c);
LOFUN void m3hadamardeq(const mat3 a, mat3 b);
LOFUN void mm3mult(const mat3 a, const mat3 b, mat3 c);
LOFUN void mv3mult(const mat3 m, const vec3 v, vec3 o);

LOFUN void v4norm(vec4 v);
LOFUN float v4mag(const vec4 v);
LOFUN void v4scale(float a, vec4 v);
LOFUN float v4dot(const vec4 a, const vec4 b);
LOFUN void v4add(const vec4 a, const vec4 b, vec4 c);
LOFUN void v4addeq(const vec4 a, vec4 b);
LOFUN void v4hadamard(const vec4 a, const vec4 b, vec4 c);
LOFUN void v4hadamardeq(const vec4 a, vec4 b);
LOFUN void m4zero(mat4 a);
LOFUN void m4id(mat4 a);
LOFUN void m4scale(float a, mat4 m);
LOFUN void m4add(const mat4 a, const mat4 b, mat4 c);
LOFUN void m4addeq(const mat4 a, mat4 b);
LOFUN void m4hadamard(const mat4 a, const mat4 b, mat4 c);
LOFUN void m4hadamardeq(const mat4 a, mat4 b);
LOFUN void mm4mult(const mat4 a, const mat4 b, mat4 c);
LOFUN void mv4mult(const mat4 m, const vec4 v, vec4 o);

/* Vector operations */
LOFUN void
v3norm(vec3 v)
{
	v3scaleeq(1 / v3mag(v), v);
}

LOFUN float
v3mag(const vec3 v)
{
	return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

LOFUN void
v3scaleeq(float c, vec3 v)
{
	v[0] *= c;
	v[1] *= c;
	v[2] *= c;
}

LOFUN void
v3scale(float c, const vec3 a, vec3 b)
{
	b[0] = c * a[0];
	b[1] = c * a[1];
	b[2] = c * a[2];
}

LOFUN float
v3dot(const vec3 a, const vec3 b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

LOFUN void
v3add(const vec3 a, const vec3 b, vec3 c)
{
	c[0] = a[0] + b[0];
	c[1] = a[1] + b[1];
	c[2] = a[2] + b[2];
}

LOFUN void
v3addeq(const vec3 a, vec3 b)
{
	b[0] += a[0];
	b[1] += a[1];
	b[2] += a[2];
}

LOFUN void
v3sub(const vec3 a, const vec3 b, vec3 c)
{
	c[0] = a[0] - b[0];
	c[1] = a[1] - b[1];
	c[2] = a[2] - b[2];
}

LOFUN void
v3hadamard(const vec3 a, const vec3 b, vec3 c)
{
	c[0] = a[0] * b[0];
	c[1] = a[1] * b[1];
	c[2] = a[2] * b[2];
}

LOFUN void
v3hadamardeq(const vec3 a, vec3 b)
{
	b[0] *= a[0];
	b[1] *= a[1];
	b[2] *= a[2];
}

LOFUN void
cross(const vec3 a, const vec3 b, vec3 c)
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

/* Matrix operations */
LOFUN void
m3zero(mat3 a)
{
	memset(a, 0, 9 * sizeof(float));
}

LOFUN void
m3id(mat3 a)
{
	a[0] = a[4] = a[12] = 1;
}

LOFUN void
m3scale(float a, mat3 m)
{
	for (short i = 0; i < 9; ++i)
		m[i] *= a;
}

LOFUN void
m3add(const mat3 a, const mat3 b, mat3 c)
{
	for (short i = 0; i < 9; ++i)
		c[i] = a[i] + b[i];
}

LOFUN void
m3addeq(const mat3 a, mat3 b)
{
	for (short i = 0; i < 9; ++i)
		b[i] += a[i];
}

LOFUN void
m3hadamard(const mat3 a, const mat3 b, mat3 c)
{
	for (short i = 0; i < 9; ++i)
		c[i] = a[i] * b[i];
}

LOFUN void
m3hadamardeq(const mat3 a, mat3 b)
{
	for (short i = 0; i < 9; ++i)
		b[i] *= a[i];
}

LOFUN void
mm3mult(const mat3 a, const mat3 b, mat3 c)
{
	for (short i = 0; i < 9; i += 3) {
		for (short j = 0; j < 3; ++j)
			c[i + j] = a[i] * b[j] + a[i + 1] * b[j + 3] + a[i + 2] * b[j + 6];
	}
}

LOFUN void
mv3mult(const mat3 m, const vec3 v, vec3 o)
{
	o[0] = v3dot((float*)m, v);
	o[1] = v3dot((float*)m + 3, v);
	o[2] = v3dot((float*)m + 6, v);
}

/* 4d stuff */
LOFUN void
v4norm(vec4 v)
{
	v4scale(1 / v4mag(v), v);
}

LOFUN float
v4mag(const vec4 v)
{
	return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);
}

LOFUN void
v4scale(float a, vec4 v)
{
	v[0] *= a;
	v[1] *= a;
	v[2] *= a;
	v[3] *= a;
}

LOFUN float
v4dot(const vec4 a, const vec4 b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
}

LOFUN void
v4add(const vec4 a, const vec4 b, vec4 c)
{
	c[0] = a[0] + b[0];
	c[1] = a[1] + b[1];
	c[2] = a[2] + b[2];
	c[3] = a[3] + b[3];
}

LOFUN void
v4addeq(const vec4 a, vec4 b)
{
	b[0] += a[0];
	b[1] += a[1];
	b[2] += a[2];
	b[3] += a[3];
}

LOFUN void
v4hadamard(const vec4 a, const vec4 b, vec4 c)
{
	c[0] = a[0] * b[0];
	c[1] = a[1] * b[1];
	c[2] = a[2] * b[2];
	c[3] = a[3] * b[3];
}

LOFUN void
v4hadamardeq(const vec4 a, vec4 b)
{
	b[0] *= a[0];
	b[1] *= a[1];
	b[2] *= a[2];
	b[3] *= a[3];
}

LOFUN void
m4zero(mat4 a)
{
	memset(a, 0, 16 * sizeof(float));
}

LOFUN void
m4id(mat4 a)
{
	a[0] = a[5] = a[10] = a[15] = 1;
}

LOFUN void
m4scale(float a, mat4 m)
{
	for (short i = 0; i < 16; ++i)
		m[i] *= a;
}
		

LOFUN void
m4add(const mat4 a, const mat4 b, mat4 c)
{
	for (short i = 0; i < 16; ++i)
		c[i] = a[i] + b[i];
}

LOFUN void
m4addeq(const mat4 a, mat4 b)
{
	for (short i = 0; i < 16; ++i)
		b[i] += a[i];
}

LOFUN void
m4hadamard(const mat4 a, const mat4 b, mat4 c)
{
	for (short i = 0; i < 16; ++i)
		c[i] = a[i] * b[i];
}

LOFUN void
m4hadamardeq(const mat4 a, mat4 b)
{
	for (short i = 0; i < 16; ++i)
		b[i] += a[i];
}

LOFUN void
mm4mult(const mat4 a, const mat4 b, mat4 c)
{
	for (short i = 0; i < 16; i += 4) {
		for (short j = 0; j < 4; ++j)
			c[i + j] = a[i] * b[j] + a[i + 1] * b[j + 4] +
				a[i + 2] * b[j + 8] + a[i + 3] * b[j + 12];
	}
}

LOFUN void
mv4mult(const mat4 m, const vec4 v, vec4 o)
{
	o[0] = v4dot((float*)m, v);
	o[1] = v4dot((float*)m + 4, v);
	o[2] = v4dot((float*)m + 8, v);
	o[3] = v4dot((float*)m + 12, v);
}

#endif
