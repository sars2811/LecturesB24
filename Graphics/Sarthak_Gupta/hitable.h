#ifndef HITABLEH
#define HITABLEH

#include "ray.h"

class material;

struct hit_record {
	float t;
	vec3 p;
	vec3 normal;
	material *material_ptr;
};

class hitable {
	public:
		virtual bool hit(const ray& r , float t_min , float t_max , hit_record& rec) const = 0;
};

class material {
	public:
		virtual bool scatter(const ray& r_in, const hit_record& rec , vec3& attenuation , ray& scattered) const = 0;
};

#endif
