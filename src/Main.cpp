//============================================================================
// Name        : LonelySoul.cpp
// Author      : deka
// Version     :
// Copyright   : GPL
// Description : La unión del mundo
//============================================================================

#include <iostream>
#include "Engine.h"
#include "Stage.h"
#include "Player.h"
#include <string>


const Uint32 WIDTH = 1024;
const Uint32 HEIGHT = 768;

int main( int argc, char* argv[] )
{
	std::cout << "ENTRA A MAIN" << std::endl;
	Engine motor;
	motor.mainLoop();
	return 0;
}
