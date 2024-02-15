#include "Player.h"
#include "Graphics.h"


//void Player::CreatePlayer(Graphics& graphics)
//{
//	graphics.CreateSprite(texture, "Player");
//}
//
//void Player::DrawPlayer(Graphics& graphics)
//{
//	graphics.DrawSprite("Player", xPos, yPos);
//	if (xPos > (graphics.GetScreenWidth()/ 2) - 100 && xPos < (graphics.GetScreenWidth() / 2) + 100 && yPos >(graphics.GetScreenHeight() / 2) - 100 && yPos < (graphics.GetScreenHeight() / 2) + 100)
//	{
//		//HAPI.SetControllerRumble(0, 30000, 30000);
//	}
//	else
//	{
//		HAPI.SetControllerRumble(0, 0, 0);
//	}
//}

void Player::Movement(const HAPI_TKeyboardData& keyData)
{
	/*if (keyData.scanCode['W'] || keyData.scanCode[HK_UP])
	{
		gameObject->transform->position.y -= (1 * speed);
	}
	if (keyData.scanCode['S'] || keyData.scanCode[HK_DOWN])
	{
		gameObject->transform->position.y += (1 * speed);
	}
	if (keyData.scanCode['A'] || keyData.scanCode[HK_LEFT])
	{
		gameObject->transform->position.x -= (1 * speed);
	}
	if (keyData.scanCode['D'] || keyData.scanCode[HK_RIGHT])
	{
		gameObject->transform->position.x += (1 * speed);
	}*/


	//gameObject->transform->position.y += (1 * speed);
	
}

void Player::ControllerMovement(const HAPI_TControllerData& controllerData)
{
	if (controllerData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < -6000)
	{
		gameObject->transform->position.x -= (1 * speed);
	}
	if (controllerData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > 6000)
	{
		gameObject->transform->position.x += (1 * speed);
	}
	if (controllerData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] > 6000)
	{
		gameObject->transform->position.y -= (1 * speed);
	}
	if (controllerData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < -6000)
	{
		gameObject->transform->position.y += (1 * speed);
	}
}

void Player::Update(const HAPI_TKeyboardData& keyData, const HAPI_TControllerData& controllerData)
{
	//DrawPlayer(graphics);
	Movement(keyData);
	ControllerMovement(controllerData);

}
