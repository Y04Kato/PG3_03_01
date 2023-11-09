#pragma once
#include "Object.h"
#define _USE_MATH_DEFINE_
#include <math.h>

float Distance(const Vector2& a, const Vector2& b);


bool CircleCollisinHit(const Vector2& a, const float aSize, const Vector2& b, const float bSize);


