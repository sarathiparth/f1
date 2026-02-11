#pragma once
#include<cmath>
#include"vector2d.h"

class matrix2{
    public:
    float m00,m01;
    float m10,m11;

    matrix2(){
        m00 = 1.0; m01 = 0.0;
        m10 = 0.0; m11 = 1.0;
    }
    matrix2(float a , float b , float c , float d){
        m00 = a;
        m01 = b;
        m10 = c;
        m11 = d;
    }

    static matrix2 rotation(float radian){
        float c = std::cos(radian);
        float s = std::sin(radian);
        return matrix2(c,-s,s,c);
    }
    Vector2 operator *(const Vector2&v)const{
       return Vector2( m00*v.x + m01*v.y,
                       m10*v.x + m11*v.y);
    } 
    matrix2 operator * (const matrix2& o) const
    {
        return matrix2(
            m00 * o.m00 + m01 * o.m10,
            m00 * o.m01 + m01 * o.m11,

            m10 * o.m00 + m11 * o.m10,
            m10 * o.m01 + m11 * o.m11
        );
}};