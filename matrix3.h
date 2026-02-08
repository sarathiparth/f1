#pragma once
#include<cmath>
#include<vector.h>

class matrix3{
    public:
    float m[3][3];
    matrix3(){
        m[0][0] = 1 ;m[0][1] = 0 ;m[0][2] = 0 ;
        m[1][0] = 0 ;m[1][1] = 1 ;m[0][0] = 0 ;
        m[2][0] = 0 ;m[2][1] = 0 ;m[2][2] = 1 ;
    }

    static matrix3 rotx(float radian){
       float s = std::sin(radian);
       float c = std::cos(radian);
       matrix3 r3;
       r3.m[1][1]=c;r3.m[1][2]=-s;
       r3.m[2][1]=s;r3.m[2][2]=c;
       return r3;
    }
    static matrix3 roty(float radian){
        float s = std::sin(radian);
       float c = std::cos(radian);
       matrix3 r3;
       r3.m[0][0]=c;r3.m[2][0]=-s;
       r3.m[2][0]=-s;r3.m[2][2]=c;
       return r3;

    }
    static matrix3 rotz(float radian){
        float s = std::sin(radian);
       float c = std::cos(radian);
       matrix3 r3;
       r3.m[0][0]=c;r3.m[0][1]=-s;
       r3.m[1][0]=-s;r3.m[1][1]=c;
       return r3;
    }
    vector3 operator * (const vector3& v) const
    {
        return vector3(
            m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z,
            m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z,
            m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z
        );
}};
