#ifndef MXVARIABLESTATIC_H
#define MXVARIABLESTATIC_H

#include "mxvariable.h"

class VisibilityVariable : public MxVariable
{
public:
    inline VisibilityVariable()
    {
        this->m_key = "VISIBILITY";
    }
};

class CameraLocationVariable: public MxVariable
{
public:
    inline CameraLocationVariable()
    {
        this->m_key = "CAMERA_LOCATION";
    }
};

class CursorVariable: public MxVariable
{
public:
    inline CursorVariable()
    {
        this->m_key = "CURSOR";
    }
};

class WhoAmIVariable: public MxVariable
{
public:
    inline WhoAmIVariable()
    {
        this->m_key = "WHO_AM_I";
    }
};

#endif // MXVARIABLESTATIC_H