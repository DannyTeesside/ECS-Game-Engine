#pragma once
#include <HAPI_lib.h>
using namespace HAPISPACE;

class Rectangle
{
public:
	int left;
	int right;
	int top;
	int bottom;

	Rectangle()
	{

	}

	Rectangle(int l, int r, int t, int b) : left(l), right(r), top(t), bottom(b)
	{

	}

	int GetWidth() const
	{
		return right - left;
	}

	int GetHeight() const
	{
		return bottom - top;
	}

	int GetRectRight()
	{
		return right;
	}

	int GetRectLeft()
	{
		return left;
	}

	int GetRectTop()
	{
		return top;
	}

	int GetRectBottom()
	{
		return bottom;
	}

	void Translate(int x, int y)
	{
		left += x;
		right += x;
		top += y;
		bottom += y;
	}

	void ClipTo(const Rectangle& other)
	{
		if (left < other.left)
		{
			left = other.left;
		}
		if (right > other.right)
		{
			right = other.right;
		}
		if (top < other.top)
		{
			top = other.top;
		}
		if (bottom > other.bottom)
		{
			bottom = other.bottom;
		}
	}
};
