#include "la_extended.h"

namespace LA {

    double Degrees(double rad) {
        return (double)(rad * 180 / PI);
    }

    double Radians(double deg) {
        return (double)(deg * PI / 180);
    }

    template<int N, typename T>
    double Mag(vec<N, T> v) {
        return Magnitude(v);
    }

    template<int N, typename T>
    double Magnitude(vec<N, T> v) {
        double total = 0;
        for (int i = 0; i < v.len(); i++) {
            total += v[i] * v[i];
        }
        return sqrt(total);
    }

    template<int N, typename T>
    vec<N, T> Norm(vec<N, T> v) {
        return Normalise(v);
    }

    template<int N, typename T>
    vec<N, T> Normalise(vec<N, T> v) {
        vec<N, T> n = vec<N, T>();
        double total = Magnitude(v);
        if (total == 0.0) {
            return n;
        }
        for (int i = 0; i < v.len(); i++) {
            n[i] = v[i] / total;
        }
        return n;
    }

    template<int N, typename T>
    double Dot(vec<N, T> a, vec<N, T> b) {
        double total = 0.0;
        for (int i = 0; i < a.len(); i++) {
            total += a[i] * b[i];
        }
        return total;
    }

    template<int N, typename T>
    T AngleBetween(vec<N, T> a, vec<N, T> b) {
        return acosf(Dot(a, b) / (Mag(a) * Mag(b)));
    }

    mat4 Translate(float x, float y, float z) {
        mat4 to_return = mat4();
        to_return[3][0] = x;
        to_return[3][1] = y;
        to_return[3][2] = z;
        return to_return;
    }
    mat4 Translate(vec3 v) {
        return Translate(v.x, v.y, v.z);
    }

    mat4 RotateX(float angle) {
        mat4 to_return = mat4();
        float radians = angle * PI / 180;
        to_return[1][1] = cos(radians);
        to_return[2][1] = sin(radians);
        to_return[1][2] = -sin(radians);
        to_return[2][2] = cos(radians);
        return to_return;
    }

    mat4 RotateY(float angle) {
        mat4 to_return = mat4();
        float radians = angle * PI / 180;
        to_return[0][0] = cos(radians);
        to_return[0][2] = sin(radians);
        to_return[2][0] = -sin(radians);
        to_return[2][2] = cos(radians);
        return to_return;
    }

    mat4 RotateZ(float angle) {
        mat4 to_return = mat4();
        float radians = angle * PI / 180;
        to_return[0][0] = cos(radians);
        to_return[0][1] = sin(radians);
        to_return[1][0] = -sin(radians);
        to_return[1][1] = cos(radians);
        return to_return;
    }

    mat4 Rotate(float x, float y, float z) {
        return RotateZ(z) * RotateY(y) * RotateX(x);
    }

    mat4 Rotate(vec3 v) {
        return Rotate(v.x, v.y, v.z);
    }

    mat4 Scale(float x, float y, float z) {
        mat4 to_return = mat4();
        to_return[0][0] = x;
        to_return[1][1] = y;
        to_return[2][2] = z;
        to_return[3][3] = 1.0f;
        return to_return;
    }

    mat4 Scale(vec3 v) {
        return Scale(v.x, v.y, v.z);
    }

    mat4 Transformation(vec3 position, vec3 rotation, vec3 scale) {
        mat4 pos = Translate(position);
        mat4 rot = Rotate(rotation);
        mat4 scl = Scale(scale);
        return pos * rot * scl;
    }

    // mat4 Frustrum(float left, float right, float bottom, float top, float near, float far) {
    //     float hDist = right - left;
    //     float vDist = top - bottom;
    //     float dDist = far - near;
    //     mat4 m = mat4(0.0f);

    //     m[0][0] = 2.0f * near / hDist;
    //     m[1][1] = 2.0f * near / vDist;
    //     m[2][0] = (right + left) / hDist;
    //     m[2][1] = (top + bottom) / vDist;
    //     m[2][2] = (-far - near) / vDist;
    //     m[2][3] = -1.0f;
    //     m[3][2] = (-2.0f * near * far) / vDist;
    //     return m;
    // }

    // mat4 Perspective(float fov, float aspect, float near, float far) {
    //     float rad = fov * PI / 180.0f;
    //     float ymax = near * tan(rad);
    //     float xmax = ymax * aspect;
    //     return Frustum(-xmax, xmax, -ymax, ymax, near, far);
    // }

    mat4 Perspective(float fov, float aspect, float near, float far) {
        mat4 to_return = mat4(0.0f);
        float rad = fov * (PI/180);
        float tan_half_angle = tan(rad / 2);
        to_return[0][0] = 1 / (aspect * tan_half_angle);
        to_return[1][1] = 1 / (tan_half_angle);
        to_return[2][2] = -(far + near) / (far - near);
        to_return[2][3] = -1;
        to_return[3][2] = -(2 * far * near) / (far - near);
        return to_return;
    }

    mat4 Orthographic(float l, float r, float b, float t, float n, float f) {
        mat4 m = mat4(0.0f);
        m[0] = 2 / (r - l);
        m[1][1] = 2 / (t - b);
        m[2][2] = 1.0f / (f - n);
        m[3][0] = (l + r) / (l - r);
        m[3][1] = (t + b) / (b - t);
        m[3][2] = n / (n - f);
        m[3][3] = 1.0f;
    }

    vec3 Cross(vec3 a, vec3 b) {
    return vec3({a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x
            });
    }

    mat4 LookAt (vec3 from, vec3 to, vec3 up) {
        mat4 to_return = mat4();
        to += from;
        vec3 z = Normalise(to);
		vec3 x = Normalise(Cross(up, z));
		vec3 y = Cross(z, x);
		return mat4({
			x.x,  x.y,  x.z, (float)-Dot(from, x),
			y.x,  y.y,  y.z, (float)-Dot(from, y),
			z.x,  z.y,  z.z, (float)-Dot(from, z),
			0.0f, 0.0f, 0.0f, 1.0f
        });
        return to_return;
    }

    vec4 Project(vec4 from, vec4 onto) {
        onto *= (float)Dot(from, onto) / (float)Dot(onto, onto);
        return onto;
    }

}