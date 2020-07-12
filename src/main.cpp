//
// Created by cjohnson on 7/12/20.
//

#include "window/GameWindow.h"

int main()
{
	linfo << "Test!" << en;

	cccgame::GameWindow gameWindow = cccgame::GameWindow();
	if(!gameWindow.ConstructWindowElements())
		return -1;

	gameWindow.WindowLoop();

	return gameWindow.CleanupWindowElements();
}