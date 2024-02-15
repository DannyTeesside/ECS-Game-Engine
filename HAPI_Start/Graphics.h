#pragma once
#include <unordered_map>
#include <HAPI_lib.h>
#include "Rectangle.h"
using namespace HAPISPACE;



class Sprite;

class Graphics
{
	private:
		int width{ 1024 };
		int height{ 768 };

		int rectLeft;
		int rectRight;
		int rectTop;
		int rectBottom;
		std::string title = "Daniel Watson - D3361320";
		BYTE* screen;

		std::unordered_map<std::string, Sprite*> spriteMap;

		Rectangle screenRect;


	public:
		Graphics()
		{
			

		}

		void Initialise()
		{
			if (!HAPI.Initialise(width, height, title))
				return;

			screen = HAPI.GetScreenPointer();
			HAPI.LimitFrameRate(60);
			HAPI.SetShowFPS(true);

			screenRect = Rectangle(0, width, 0, height);
		}

		~Graphics();

		bool CreateSprite(const std::string& textureFile, const std::string& name);

		void DrawSprite(const std::string& name, int sx, int sy);

		int GetSpriteWidth(const std::string& name) const;
		int GetSpriteHeight(const std::string& name) const;

		int GetRectRight()
		{
			return rectRight;
		}

		int GetRectLeft()
		{
			return rectLeft;
		}

		int GetRectTop()
		{
			return rectTop;
		}

		int GetRectBottom()
		{
			return rectBottom;
		}

		void ClearScreen();

		int GetScreenWidth();
		int GetScreenHeight();

};

