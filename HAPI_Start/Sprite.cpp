#include "Sprite.h"

bool Sprite::LoadSprite(const std::string& name)
{
	if (!HAPI.LoadTexture(name, &texture, width, height))
	{
		HAPI.UserMessage("Cannot load " + name, "Error");
		return false;
	}
	return true;
}

void Sprite::DrawSprite(BYTE* screen, Rectangle screenRect, int sx, int sy)
{

	Rectangle textureRect(0, width, 0, height);

	textureRect.Translate(sx, sy);

	textureRect.ClipTo(screenRect);

	textureRect.Translate(-sx, -sy);

	if (sx < 0)
	{
		sx = 0;
	}
	if (sy < 0)
	{
		sy = 0;
	}

	int screenOffset = (sy * screenRect.GetWidth() + sx) * 4;
	int textureOffset = (textureRect.top * width + textureRect.left) * 4;

	int endOfLineScreenOffset = (screenRect.GetWidth() - textureRect.GetWidth()) * 4;
	int endOfLineTextureOffset = (width - textureRect.GetWidth()) * 4;

	for (int y = 0; y < textureRect.GetHeight(); y++)
	{
		for (int x = 0; x < textureRect.GetWidth(); x++)
		{
			sr = screen[screenOffset];
			sg = screen[screenOffset + 1];
			sb = screen[screenOffset + 2];
			sa = screen[screenOffset + 3];

			tr = texture[textureOffset];
			tg = texture[textureOffset + 1];
			tb = texture[textureOffset + 2];
			ta = texture[textureOffset + 3];

			if (ta == 0)
			{

			}
			else if (ta == 255)
			{
				memcpy(screen + screenOffset, texture + textureOffset, 4);
			}
			else
			{
				alpha = ta / 255.0f;

				finalRed = alpha * tr + (1.0f - alpha) * sr;
				finalGreen = alpha * tg + (1.0f - alpha) * sg;
				finalBlue = alpha * tb + (1.0f - alpha) * sb;



				screen[screenOffset] = finalRed;
				screen[screenOffset + 1] = finalGreen;
				screen[screenOffset + 2] = finalBlue;
			}

			//memcpy(screen + screenOffset, texture + textureOffset, 4);

			textureOffset += 4;
			screenOffset += 4;

		}
		screenOffset += endOfLineScreenOffset;
		textureOffset += endOfLineTextureOffset;
	}

	left = textureRect.GetRectLeft();
	right = textureRect.GetRectRight();
	top = textureRect.GetRectTop();
	bottom = textureRect.GetRectBottom();

}
