#pragma once
#include <HAPI_lib.h>
#include "Rectangle.h"
using namespace HAPISPACE;

class Sprite
{
private:
	int width;
	int height;
	int left;
	int right;
	int top;
	int bottom;
	BYTE* texture{ nullptr };

	BYTE sr;
	BYTE sg;
	BYTE sb;
	BYTE sa;

	BYTE tr;
	BYTE tg;
	BYTE tb;
	BYTE ta;

	float alpha;

	BYTE finalRed;
	BYTE finalGreen;
	BYTE finalBlue;


public:
	bool LoadSprite(const std::string& name);
	void DrawSprite(BYTE* screen, Rectangle screenRect, int sx, int sy);
	int GetWidth() const
	{
		return width;
	}
	int GetHeight() const
	{
		return height;
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

	~Sprite()
	{
		delete[]texture;
	}
};

