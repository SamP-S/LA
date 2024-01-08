#pragma once

#include "la.hpp"

namespace LA {

    const float PI = 3.14159;

    using vec2 = vec<2, float>;
    using vec3 = vec<3, float>;
    using vec4 = vec<4, float>;
    using mat2 = mat<2, 2, float>;
    using mat3 = mat<3, 3, float>;
    using mat4 = mat<4, 4, float>;

    template<typename T>
    double RadToDeg(T rad);
    template<typename T>
    double DegToRad(T deg);

    template<int N, typename T>
    double Mag(vec<N, T> v);
    template<int N, typename T>
    double Magnitude(vec<N, T> v);

    template<int N, typename T>
    vec<N, T> Norm(vec<N, T> v);
    template<int N, typename T>
    vec<N, T> Normalise(vec<N, T> v);

    template<int N, typename T>
    double Dot(vec<N, T> a, vec<N, T> b);
    template<int N, typename T>
    T AngleBetween(vec<N, T> a, vec<N, T> b);

    mat4 Translate(float x, float y, float z) ;
    mat4 Translate(vec3 v);
    mat4 RotateX(float angle);
    mat4 RotateY(float angle);
    mat4 RotateZ(float angle) ;
    mat4 Rotate(float x, float y, float z);
    mat4 Rotate(vec3 v);
    mat4 Scale(float x, float y, float z);
    mat4 Scale(vec3 v);

    mat4 Transformation(vec3 position, vec3 rotation, vec3 scale);
    mat4 Perspective(float fov, float aspect, float near, float far);
    vec3 Cross(vec3 a, vec3 b);
    mat4 LookAt (vec3 from, vec3 to, vec3 up);
    vec4 Project(vec4 from, vec4 onto) ;

}
