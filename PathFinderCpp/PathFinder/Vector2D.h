#ifndef VECTOR_2D
#define VECTOR_2D
#include <cmath>

class Vector2D{
public:
	double x;
	double y;
	Vector2D() :x(0.0), y(0.0){}
	Vector2D(double a, double b) :x(a), y(b){}
	void setZero(){ x = 0.0; y = 0.0; }
	bool isZero()const{ return x == 0 && y == 0; }
	inline double Length()const;
	inline double LengthSquared()const;
	inline void Normalize();
	inline double Dot(const Vector2D& otherVector)const;
	inline double Distance(const Vector2D &otherVector)const;
	inline double DistanceSq(const Vector2D &otherVector)const;

	const Vector2D& operator+=(const Vector2D &otherVector){
		x += otherVector.x;
		y += otherVector.y;
		return *this;
	}

	const Vector2D& operator-=(const Vector2D &otherVector){
		x -= otherVector.x;
		y -= otherVector.y;
		return *this;
	}

	const Vector2D& operator*=(const double& multiplier){
		x *= multiplier;
		y *= multiplier;
		return *this;
	}

	const Vector2D& operator/=(const double& dividend){
		x /= dividend;
		y /= dividend;
		return *this;
	}

	bool operator==(const Vector2D& otherVector)const{
		return (x==otherVector.x && y==otherVector.y);
	}

	bool operator!=(const Vector2D& otherVector)const{
		return (x != otherVector.x) || (y != otherVector.y);
	}
};

inline double Vector2D::Length()const{
	return sqrt(x*x + y*y);
}

inline double Vector2D::LengthSquared()const{
	return x*x + y*y;
}

inline void Vector2D::Normalize(){
	double length = this->Length();
	this->x /= length;
	this->y /= length;
}

inline double Vector2D::Dot(const Vector2D& otherVector)const{
	return x*otherVector.x + y*otherVector.y;
}

inline double Vector2D::Distance(const Vector2D &otherVector)const{
	double xDistance = otherVector.x - x;
	double yDistance = otherVector.y - y;
	return sqrt(xDistance*xDistance + yDistance*yDistance);
}

inline double Vector2D::DistanceSq(const Vector2D &otherVector)const{
	double xDistance = otherVector.x - x;
	double yDistance = otherVector.y - y;
	return xDistance*xDistance + yDistance*yDistance;
}

#endif 