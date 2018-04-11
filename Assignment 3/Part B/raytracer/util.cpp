/***********************************************************

	Starter code for Assignment 3
	
	Implementations of util.h	

***********************************************************/

#include "util.h"


Point3D::Point3D() {
	m_data[0] = 0.0;
	m_data[1] = 0.0;
	m_data[2] = 0.0;
}

Point3D::Point3D(double x, double y, double z) { 
	m_data[0] = x;
	m_data[1] = y;
	m_data[2] = z;
}

Point3D::Point3D(const Point3D& other) {
	m_data[0] = other.m_data[0];
	m_data[1] = other.m_data[1];
	m_data[2] = other.m_data[2];
}

Point3D::Point3D(const Vector4D& other) {
	m_data[0] = other[0];
	m_data[1] = other[1];
	m_data[2] = other[2];
}


Point3D& Point3D::operator =(const Point3D& other) {
	m_data[0] = other.m_data[0];
	m_data[1] = other.m_data[1];
	m_data[2] = other.m_data[2];
	return *this;
}



double& Point3D::operator[](int i) {
	return m_data[i];
}

double Point3D::operator[](int i) const {
	return m_data[i];
}
	
Vector3D::Vector3D() {
	m_data[0] = 0.0;
	m_data[1] = 0.0;
	m_data[2] = 0.0;
}

Vector3D::Vector3D(double x, double y, double z) {
	m_data[0] = x;
	m_data[1] = y;
	m_data[2] = z;
}

Vector3D::Vector3D(const Vector3D& other) {
	m_data[0] = other.m_data[0];
	m_data[1] = other.m_data[1];
	m_data[2] = other.m_data[2];
}

Vector3D::Vector3D(const Point3D& other) {
	m_data[0] = other[0];
	m_data[1] = other[1];
	m_data[2] = other[2];
}


Vector3D& Vector3D::operator =(const Vector3D& other) {
	m_data[0] = other.m_data[0];
	m_data[1] = other.m_data[1];
	m_data[2] = other.m_data[2];
	return *this;
}

double& Vector3D::operator[](int i) {
	return m_data[i];
}
double Vector3D::operator[](int i) const {
	return m_data[i];
}

double Vector3D::length() const
{
	return sqrt(dot(*this));
}

double Vector3D::normalize() {
	double denom = 1.0;
	double x = (m_data[0] > 0.0) ? m_data[0] : -m_data[0];
	double y = (m_data[1] > 0.0) ? m_data[1] : -m_data[1];
	double z = (m_data[2] > 0.0) ? m_data[2] : -m_data[2];

	if(x > y) {
		if(x > z) {
			if(1.0 + x > 1.0) {
				y = y / x;
				z = z / x;
				denom = 1.0 / (x * sqrt(1.0 + y*y + z*z));
			}
		} else { /* z > x > y */ 
			if(1.0 + z > 1.0) {
				y = y / z;
				x = x / z;
				denom = 1.0 / (z * sqrt(1.0 + y*y + x*x));
			}
		}
	} else {
		if(y > z) {
			if(1.0 + y > 1.0) {
				z = z / y;
				x = x / y;
				denom = 1.0 / (y * sqrt(1.0 + z*z + x*x));
			}
		} else { /* x < y < z */
			if(1.0 + z > 1.0) {
				y = y / z;
				x = x / z;
				denom = 1.0 / (z * sqrt(1.0 + y*y + x*x));
			}
		}
	}

	if(1.0 + x + y + z > 1.0) {
		m_data[0] *= denom;
		m_data[1] *= denom;
		m_data[2] *= denom;
		return 1.0 / denom;
	}

	return 0.0;
}

double Vector3D::dot(const Vector3D& other) const
{
	return m_data[0]*other.m_data[0] + 
		m_data[1]*other.m_data[1] + 
		m_data[2]*other.m_data[2];
}

Vector3D Vector3D::cross(const Vector3D& other) const
{
	return Vector3D(
			m_data[1]*other[2] - m_data[2]*other[1],
			m_data[2]*other[0] - m_data[0]*other[2],
			m_data[0]*other[1] - m_data[1]*other[0]);
}

Vector3D operator *(double s, const Vector3D& v)
{
  return Vector3D(s*v[0], s*v[1], s*v[2]);
}

Vector3D operator +(const Vector3D& u, const Vector3D& v)
{
  return Vector3D(u[0]+v[0], u[1]+v[1], u[2]+v[2]);
}

Point3D operator +(const Point3D& u, const Vector3D& v)
{
  return Point3D(u[0]+v[0], u[1]+v[1], u[2]+v[2]);
}

Vector3D operator -(const Point3D& u, const Point3D& v)
{
  return Vector3D(u[0]-v[0], u[1]-v[1], u[2]-v[2]);
}

Vector3D operator -(const Vector3D& u, const Vector3D& v)
{
  return Vector3D(u[0]-v[0], u[1]-v[1], u[2]-v[2]);
}

Vector3D operator -(const Vector3D& u)
{
  return Vector3D(-u[0], -u[1], -u[2]);
}

Point3D operator -(const Point3D& u, const Vector3D& v)
{
  return Point3D(u[0]-v[0], u[1]-v[1], u[2]-v[2]);
}

Vector3D cross(const Vector3D& u, const Vector3D& v)
{
  return u.cross(v);
}

void to_euler(Vector3D u, const double angle, double (&euler_angles)[3]) {
    // using euler rotation sequence y, z, x
    u.normalize();
    double angle_rad = (M_PI / 180.0) * angle;
    double x = u[0];
    double y = u[1];
    double z = u[2];
    double s=sin(angle_rad);
    double c=cos(angle_rad);
    double t=1-c;

    if ((x*y*t + z*s) > 0.998) { // north pole singularity detected
        euler_angles[0] = 2*atan2(x*sin(angle/2), cos(angle/2)); // rotation about y
        euler_angles[1] = M_PI/2; // rotation about z
        euler_angles[2] = 0; // rotation about x
        return;
    }
    if ((x*y*t + z*s) < -0.998) { // south pole singularity detected
        euler_angles[0] = -2*atan2(x*sin(angle/2), cos(angle/2));
        euler_angles[1] = -M_PI/2;
        euler_angles[2] = 0;
        return;
    }
    double rad_to_deg = 180.0 / M_PI;
    euler_angles[0] = rad_to_deg * atan2(y * s - x * z * t, 1 - (y * y + z * z) * t);
    euler_angles[1] = rad_to_deg * asin(x * y * t + z * s);
    euler_angles[2] = rad_to_deg * atan2(x * s - y * z * t, 1 - (x * x + z * z) * t);
}

std::ostream& operator <<(const Point3D& p, std::ostream& s)
{
  return s << "p(" << p[0] << "," << p[1] << "," << p[2] << ")";
}

std::ostream& operator <<(std::ostream& s, const Vector3D& v)
{
  return s << "v(" << v[0] << "," << v[1] << "," << v[2] << ")";
}

Color::Color() {
	m_data[0] = 0.0;
	m_data[1] = 0.0;
	m_data[2] = 0.0;
}

Color::Color(double r, double g, double b) { 
	m_data[0] = r;
	m_data[1] = g;
	m_data[2] = b;
}

Color::Color(const Color& other) {
	m_data[0] = other.m_data[0];
	m_data[1] = other.m_data[1];
	m_data[2] = other.m_data[2];
}

Color& Color::operator =(const Color& other) {
	m_data[0] = other.m_data[0];
	m_data[1] = other.m_data[1];
	m_data[2] = other.m_data[2];
	return *this;
}

Color Color::operator *(const Color& other) {
	return Color(m_data[0]*other.m_data[0], 
		m_data[1]*other.m_data[1], 
		m_data[2]*other.m_data[2]);
}

double& Color::operator[](int i) {
	return m_data[i];
}
double Color::operator[](int i) const {
	return m_data[i];
}

void Color::clamp() {
	for (int i = 0; i < 3; i++) {
		if (m_data[i] > 1.0) m_data[i] = 1.0; 
		if (m_data[i] < 0.0) m_data[i] = 0.0; 
	}
}

Color operator *(double s, const Color& c)
{
  return Color(s*c[0], s*c[1], s*c[2]);
}

Color operator +(const Color& u, const Color& v)
{
  return Color(u[0]+v[0], u[1]+v[1], u[2]+v[2]);
}

std::ostream& operator <<(std::ostream& s, const Color& c)
{
  return s << "c(" << c[0] << "," << c[1] << "," << c[2] << ")";
}

Vector4D::Vector4D() {
	m_data[0] = 0.0;
	m_data[1] = 0.0;
	m_data[2] = 0.0;
	m_data[3] = 0.0;
}

Vector4D::Vector4D(double w, double x, double y, double z) { 
	m_data[0] = w;
	m_data[1] = x;
	m_data[2] = y;
	m_data[3] = z;
}

Vector4D::Vector4D(const Vector4D& other) {
	m_data[0] = other.m_data[0];
	m_data[1] = other.m_data[1];
	m_data[2] = other.m_data[2];
	m_data[3] = other.m_data[3];
}

Vector4D& Vector4D::operator =(const Vector4D& other) {
	m_data[0] = other.m_data[0];
	m_data[1] = other.m_data[1];
	m_data[2] = other.m_data[2];
	m_data[3] = other.m_data[3];
	return *this;
}

double& Vector4D::operator[](int i) {
	return m_data[i];
}
double Vector4D::operator[](int i) const {
	return m_data[i];
}

Matrix4x4::Matrix4x4() {
	for (int i = 0; i < 16; i++) 
		m_data[i] = 0.0; 
	m_data[0] = 1.0;
	m_data[5] = 1.0;
	m_data[10] = 1.0;
	m_data[15] = 1.0;
}

Matrix4x4::Matrix4x4(const Matrix4x4& other) {
	for (int i = 0; i < 16; i++) 
		m_data[i] = other.m_data[i]; 
}

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& other) {
	for (int i = 0; i < 16; i++) 
		m_data[i] = other.m_data[i]; 
	return *this;
}

Vector4D Matrix4x4::getRow(int row) const {
	return Vector4D(m_data[4*row], m_data[4*row+1], m_data[4*row+2], 
			m_data[4*row+3]);
}

double* Matrix4x4::getRow(int row) {
	return (double*)m_data + 4*row;
}

Vector4D Matrix4x4::getColumn(int col) const {
	return Vector4D(m_data[col], m_data[4+col], m_data[8+col], 
			m_data[12+col]);
}

Vector4D Matrix4x4::operator[](int row) const {
	return getRow(row);
}

double* Matrix4x4::operator[](int row) {
	return getRow(row);
}

Matrix4x4 Matrix4x4::transpose() const {
	Matrix4x4 M; 
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			M[i][j] = (*this)[j][i]; 
		}
	}
	return M; 
}
 
Matrix4x4 operator *(const Matrix4x4& a, const Matrix4x4& b) {
	Matrix4x4 ret;

	for(size_t i = 0; i < 4; ++i) {
		Vector4D row = a.getRow(i);

		for(size_t j = 0; j < 4; ++j) {
			ret[i][j] = row[0] * b[0][j] + row[1] * b[1][j] + 
				row[2] * b[2][j] + row[3] * b[3][j];
		}
	}

	return ret;
}

Vector3D operator *(const Matrix4x4& M, const Vector3D& v) {
	return Vector3D(
			v[0] * M[0][0] + v[1] * M[0][1] + v[2] * M[0][2],
			v[0] * M[1][0] + v[1] * M[1][1] + v[2] * M[1][2],
			v[0] * M[2][0] + v[1] * M[2][1] + v[2] * M[2][2]);
}

Point3D operator *(const Matrix4x4& M, const Point3D& p) {
	return Point3D(
			p[0] * M[0][0] + p[1] * M[0][1] + p[2] * M[0][2] + M[0][3],
			p[0] * M[1][0] + p[1] * M[1][1] + p[2] * M[1][2] + M[1][3],
			p[0] * M[2][0] + p[1] * M[2][1] + p[2] * M[2][2] + M[2][3]);
}


Vector3D transNorm(const Matrix4x4& M, const Vector3D& n) {
	return Vector3D(
			n[0] * M[0][0] + n[1] * M[1][0] + n[2] * M[2][0],
			n[0] * M[0][1] + n[1] * M[1][1] + n[2] * M[2][1],
			n[0] * M[0][2] + n[1] * M[1][2] + n[2] * M[2][2]);
}

std::ostream& operator <<(std::ostream& os, const Matrix4x4& M) {
	return os << "[" << M[0][0] << " " << M[0][1] << " " 
		<< M[0][2] << " " << M[0][3] << "]" << std::endl
		<< "[" << M[1][0] << " " << M[1][1] << " " 
		<< M[1][2] << " " << M[1][3] << "]" << std::endl
		<< "[" << M[2][0] << " " << M[2][1] << " " 
		<< M[2][2] << " " << M[2][3] << "]" << std::endl
		<< "[" << M[3][0] << " " << M[3][1] << " " 
		<< M[3][2] << " " << M[3][3] << "]";
}

void Texture::loadBitmap(const char * filename){
	bmp_read(filename, &x, &y, &rarray, &garray, &barray);
}


Color Texture::get_colour_at_uv(Point3D uv) {

	int i = int(uv[0] * repeats_x * x) % int(x);
	int j = int(uv[1] * repeats_y * y) % int(y);

	// we need to divide by 255 since the texture is stored as an int from 0 to 255
	Color col = Color (rarray[i *x + j]/255.0,garray[i *x + j]/255.0,barray[i* x + j]/255.0);
	col.clamp();
	return col;
}

Point3D CubeMap::direction_to_cube_map_uv(Vector3D direction, int* face) {

	// Used the wikipedia article for cube mapping as a guide
	// As well as the textbook
	// Use the convention from the wikipedia article since in the book, +z is the up-direction
	// In the cube mapping code I assume that positive y is the up-direction, as given in main.cpp

	double u; double v;
	double x = direction[0];
	double y = direction[1];
	double z = direction[2];

	double abs_x = fabs(x);
	double abs_y = fabs(y);
	double abs_z = fabs(z);

	// find the which face of the infinitely
	// large cube we will intersect with
	// by checking which component has biggest magnitude
    int isXPositive = x > 0 ? 1 : 0;
    int isYPositive = y > 0 ? 1 : 0;
    int isZPositive = z > 0 ? 1 : 0;

    double maxAxis, uc, vc;

	// then, use the appropriate formula
	// for that face to get (u,v) from the
	// ray's direction
    if (isXPositive && abs_x >= abs_y && abs_x >= abs_z) {
        // u (0 to 1) goes from +z to -z
        // v (0 to 1) goes from -y to +y
        maxAxis = abs_x;
        uc = -z;
        vc = y;
        *face = 0;
    }
    // NEGATIVE X
    if (!isXPositive && abs_x >= abs_y && abs_x >= abs_z) {
        // u (0 to 1) goes from -z to +z
        // v (0 to 1) goes from -y to +y
        maxAxis = abs_x;
        uc = z;
        vc = y;
        *face = 1;
    }
    // POSITIVE Y
    if (isYPositive && abs_y >= abs_x && abs_y >= abs_z) {
        // u (0 to 1) goes from -x to +x
        // v (0 to 1) goes from +z to -z
        maxAxis = abs_y;
        uc = x;
        vc = -z;
        *face = 2;
    }
    // NEGATIVE Y
    if (!isYPositive && abs_y >= abs_x && abs_y >= abs_z) {
        // u (0 to 1) goes from -x to +x
        // v (0 to 1) goes from -z to +z
        maxAxis = abs_y;
        uc = x;
        vc = z;
        *face = 3;
    }
    // POSITIVE Z
    if (isZPositive && abs_z >= abs_x && abs_z >= abs_y) {
        // u (0 to 1) goes from -x to +x
        // v (0 to 1) goes from -y to +y
        maxAxis = abs_z;
        uc = x;
        vc = y;
        *face = 4;
    }
    // NEGATIVE Z
    if (!isZPositive && abs_z >= abs_x && abs_z >= abs_y) {
        // u (0 to 1) goes from +x to -x
        // v (0 to 1) goes from -y to +y
        maxAxis = abs_z;
        uc = -x;
        vc = y;
        *face = 5;
    }

    // Convert range from -1 to 1 to 0 to 1
    u = 0.5f * (uc / maxAxis + 1.0f);
    v = 0.5f * (vc / maxAxis + 1.0f);
    return Point3D(v, u, 0);

}


void CubeMap::set_face_images() {
	// we store the cube map
	// as six square .bmp images

	face0 = new Texture(1,1);
	face0->loadBitmap("environments/nebula/pos_x.bmp"); // pos_x
	face1 = new Texture(1,1);
	face1->loadBitmap("environments/nebula/neg_x.bmp"); // neg_x
	face2 = new Texture(1,1);
	face2->loadBitmap("environments/nebula/pos_y.bmp"); // pos_y
	face3 = new Texture(1,1);
	face3->loadBitmap("environments/nebula/neg_y.bmp"); // neg_y
	face4 = new Texture(1,1);
	face4->loadBitmap("environments/nebula/pos_z.bmp"); // pos_z
	face5 = new Texture(1,1);
	face5->loadBitmap("environments/nebula/neg_z.bmp"); // neg_z
}

Color CubeMap::query_bmp_cube_map(Vector3D direction)
{
	int face = -1;
	Color col = Color(0, 0, 0);

	Point3D uv = direction_to_cube_map_uv(direction, &face);
	Texture* txt;
	switch (face)
	{
		case 0:
			txt = face0;
			break;
		case 1:
			txt = face1;
			break;
		case 2:
			txt = face2;
			break;
		case 3:
			txt = face3;
			break;
		case 4:
			txt = face4;
			break;
		case 5:
			txt = face5;
			break;
	}
	col = txt->get_colour_at_uv(uv);
	return col;
}
