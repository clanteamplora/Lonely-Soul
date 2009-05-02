/*
 * Stage.cpp
 *
 *  Created on: 29-abr-2009
 *      Author: deka
 */

#include "Stage.h"

/**
* Constructor por defecto, crea un objeto Track únicamente
*/
Stage::Stage()
{
}

/**
 * Destructor. Libera la memoria usada por la superficie que alacena la imagen del circuito
 */
Stage::~Stage()
{
	SDL_FreeSurface(trackImage); //Libera la superficie que almacena la imagen del circuito
}

/**
 * Crea un objeto de tipo track y llama al método loadTrack para la carga del circuito
 * @param name Nombre de la carpeta que contiene los archivos que componen el circuito
 */
Stage::Stage(const char* tname): name(tname)
{
	loadTrack();
}


/**
 * Carga un circuito en memoria
 * @return true si ha cargado el circuito correctamente, false en caso contrario
 */
bool Stage::loadTrack()
{
	trackImage = SDL_DisplayFormat(IMG_Load(std::string(std::string("Stages/") + std::string("prueba/prueba.png")).c_str() ));

	if(trackImage == NULL) {
		 fprintf(stderr, "No se puede cargar la imagen: %s\n", SDL_GetError());
		 return false;
	}

	return true;
}


/**
 * Devuelve una porcion del circuito
 * @param clip Especifica la porción de la imagen del circuito que se devolverá
 * @return porción de la imagen del circuito
 */
SDL_Surface* Stage::getScreen(SDL_Rect &clip)
{
    SDL_Surface *tmpS = SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 600, 16, 0, 0, 0, 0); //Superficie resultante
    SDL_BlitSurface(trackImage, &clip, tmpS, NULL);

    return tmpS;
}

/**
 * Devuelve la imagen del circuito
 * @return imagen del circuito
 */
SDL_Surface* Stage::getTrackImage()
{
	return trackImage;
}
