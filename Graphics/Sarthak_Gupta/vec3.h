#include<math.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class vec3{
	public:
		vec3(){}
		vec3(float e0 , float e1 , float e2)
		{
			e[0] = e0; e[1] = e1; e[2] = e2;
		}
		inline float x() const {return e[0];}
		inline float y() const {return e[1];}
		inline float z() const {return e[2];}
		inline float r() const {return e[0];}
		inline float g() const {return e[1];}
		inline float b() const {return e[2];}
		
		inline const vec3& operator+() const {return *this;}
		inline vec3 operator-() {return vec3(-e[0] , -e[1] , -e[2]);}
		inline float operator[](int i) const {return e[1];}
		inline float& operator[](int i) {return e[i]; }
		
		inline vec3& operator+=(const vec3 &vec2);
		inline vec3& operator-=(const vec3 &vec2);
		inline vec3& operator*=(const vec3 &vec2);
		inline vec3& operator/=(const vec3 &vec2);
		inline vec3& operator*=(const float t);
		inline vec3& operator/=(const float t);
		
		inline float length() const{
		return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }
		inline float square_length(){
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}
		inline void make_unit_vector();
		
		inline vec3 toColor(){
	        return vec3(int(255.99*(e[0])) , int(255.99*(e[1])) , int(255.99*(e[2])) );
        } 

		float e[3];
};

inline istream& operator>>(istream &is , vec3 &t) {
	is >> t.e[0] >> t.e[1] >> t.e[2];
	return is;
}

inline ostream& operator<<(ostream &os , const vec3 &t){
	os << t.e[0] << t.e[1] << t.e[2];
	return os;
}

inline void vec3::make_unit_vector(){
	float k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]) ;
	e[0] *= k ; e[1] *= k ; e[2] *= k;
}

inline vec3 operator+(const vec3 &v1 , const vec3 &v2) {
	return vec3(v1.e[0] + v2.e[0] , v1.e[1] + v2.e[1] , v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3 &v1 , const vec3 &v2) {
	return vec3(v1.e[0] - v2.e[0] , v1.e[1] - v2.e[1] , v1.e[2] - v2.e[2]);
}

inline vec3 operator*(const vec3 &v1 , const vec3 &v2) {
	return vec3(v1.e[0] * v2.e[0] , v1.e[1] * v2.e[1] , v1.e[2] * v2.e[2]);
}

inline vec3 operator/(const vec3 &v1 , const vec3 &v2) {
	return vec3(v1.e[0] / v2.e[0] , v1.e[1] / v2.e[1] , v1.e[2] / v2.e[2]);
}

inline vec3 operator*(float t , const vec3 &v){
	return vec3(t*v.e[0] , t*v.e[1] , t*v.e[2]);
}

inline vec3 operator/(const vec3 &v , float t){
	return vec3(v.e[0]/t , v.e[1]/t , v.e[2]/t);
}

inline float dot(const vec3 &v1 , const vec3 &v2){
	return v1.e[0]*v2.e[0] + v1.e[1]*v2.e[1] + v1.e[2]*v2.e[2] ;
}

inline vec3 cross(const vec3 &v1 , const vec3 &v2){
	return vec3(
	v1.e[1]*v2.e[2] - v1.e[2]*v2.e[1] ,
	-(v1.e[0]*v2.e[2] - v1.e[2]*v2.e[0]) ,
	v1.e[0]*v2.e[1] - v1.e[1]*v2.e[0]
	);
}

inline vec3& vec3::operator+=(const vec3 &v){
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}

inline vec3& vec3::operator-=(const vec3 &v){
	e[0] -= v.e[0];
	e[1] -= v.e[1];
	e[2] -= v.e[2];
	return *this;
}

inline vec3& vec3::operator*=(const vec3 &v){
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	e[2] *= v.e[2];
	return *this;
}

inline vec3& vec3::operator/=(const vec3 &v){
	e[0] /= v.e[0];
	e[1] /= v.e[1];
	e[2] /= v.e[2];
	return *this;
}

inline vec3& vec3::operator*=(const float t) {
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
}

inline vec3& vec3::operator/=(const float t) {
    float k = 1.0/t;

	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}




inline vec3 unit_vector(vec3 v){
	return v/v.length();
} 



inline vec3 random_in_unit_sphere() {
	vec3 p;
	do{
		p = 2.0*vec3(float(rand() % 1000) / float(1000), float(rand() % 1000) / float(1000) , float(rand() % 1000) / float(1000)) - vec3(1,1,1);
	} while (p.square_length() >= 1.0);
	return p;
}


/* Understood to a degree how we can and should make use of classes and how other classes like numpy maybe implemented under the hood
also saw how references are used in such cases
And how diverse and useful a single class can be!
*/

