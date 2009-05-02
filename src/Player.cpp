/*
 * Player.cpp
 *
 *  Created on: 29-abr-2009
 *      Author: deka
 */

#include "Player.h"

/**
* Constructor por defecto, crea un objeto de tipo Player.
*/
Player::Player()
{
}

/**
 * Destructor por defecto
 */
Player::~Player()
{
}

/**
 * Carga una imagen del coche
 * @param img Nombre de la imagen a cargar
 * @return true si ha cargado la imagen correctamente, false en caso contrario
 */
bool Player::loadPlayerImage(const char* img)
{
	carImage = SDL_DisplayFormatAlpha(IMG_Load(std::string(std::string("Players/") + name + std::string("/player.png")).c_str() ));

	if(carImage == NULL) {
		 fprintf(stderr, "No se puede cargar la imagen: %s\n", SDL_GetError());
		 return false;
	}

	return true;
}

/**
 * Comprueba eventos y actualiza el estado del coche en el motor físico y gráfico.
 */
void Player::update()
{

}
