#include "Graphics.h"
#include "Sprite.h"

Graphics::~Graphics()
{
	for (auto& p : spriteMap)
	{
		delete p.second;
	}
}


bool Graphics::CreateSprite(const std::string& textureFile, const std::string& name)
{
	if (spriteMap.find(name) == spriteMap.end())
	{
		Sprite* sprite = new Sprite;

		if (!sprite->LoadSprite(textureFile))
		{
			return false;
		}

		spriteMap[name] = sprite;
		return true;
		
	}
	
	//spriteMap[name] = sprite;

	return true;
}

int Graphics::GetSpriteWidth(const std::string& name) const
{
	return spriteMap.at(name)->GetWidth();
}
int Graphics::GetSpriteHeight(const std::string& name) const
{
	return spriteMap.at(name)->GetHeight();
}



void Graphics::DrawSprite(const std::string& name, int sx, int sy)
{
	spriteMap[name]->DrawSprite(screen, screenRect, sx, sy);
	rectLeft = spriteMap[name]->GetRectLeft();
	rectRight = spriteMap[name]->GetRectRight();
	rectTop = spriteMap[name]->GetRectTop();
	rectBottom = spriteMap[name]->GetRectBottom();
}

void Graphics::ClearScreen()
{
	memset(screen, 170, width * height * 4);
}

int Graphics::GetScreenWidth()
{
	return width;
}

int Graphics::GetScreenHeight()
{
	return height;
}


