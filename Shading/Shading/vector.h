#include <iostream>
using namespace std;
class vector3D
{
public:
	float length(void)
	{
		return sqrt(x*x + y*y + z*z);
	}
	vector3D normal(void)
	{
		vector3D ans(x, y, z);
		if (length() < 1e-9)
		{
			return ans;
		}
		return ans / length();
	}
	vector3D(float a = 0, float b = 0, float c = 0)
	{
		x = a;
		y = b;
		z = c;
	}
	vector3D(const vector3D &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}
	float* tofloat()
	{
		return var;
	}
	vector3D& operator=(const vector3D& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}
	friend istream& operator >>(istream& cin, vector3D& v)
	{
		return cin >> v.x >> v.y >> v.z;
	}
	friend vector3D operator /(vector3D v, const float &a)
	{
		v.x /= a;
		v.y /= a;
		v.z /= a;
		return v;
	}
	friend vector3D operator-(const vector3D& v1, const vector3D& v2)
	{
		return vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	}
	friend vector3D operator+(const vector3D& v1, const vector3D& v2)
	{
		return vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}
	friend vector3D operator+=(vector3D& v1, const vector3D& v2)
	{
		v1 = v1 + v2;
		return v1;
	}
	
	float dot(vector3D another)
	{
		return x*another.x + y*another.y + z*another.z;
	}
	vector3D cross_normal(const vector3D &another)
	{
		vector3D ans(y*another.z - another.y*z, z*another.x - another.z*x, x*another.y - another.x*y);
		if (ans.length() < 1e-20)
		{
			return ans;
		}
		return ans / ans.length();
	}
private:
	float var[3];
	float &x = var[0], &y = var[1], &z = var[2];
};
