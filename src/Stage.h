/*
 * Stage.h
 *
 *  Created on: 29-abr-2009
 *      Author: deka
 */

#ifndef STAGE_H_
#define STAGE_H_

#include <string>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include <iostream>

/**
 * Clase encargada de toda la gesti�n de los circuitos del juego.
 * @version 0.1, 11/11/08
 * @author Ibrahim Peraza Kelly
 */
class Stage
{
public:
	/**
	 * Constructor por defecto, crea un objeto Track �nicamente
	 */
	Stage();

	/**
	 * Crea un objeto de tipo track y llama al m�todo loadTrack para la carga del circuito
	 * @param tname Nombre de la carpeta que contiene los archivos que componen el circuito
	 */
	Stage(const char* tname);

	/**
	 * Fija el nombre del circuito
	 * @param tname Nombre del circuito
	 * */
	void setName(const char *tname){name = tname; };

	/**
	 * Carga un circuito en memoria
	 * @return true si ha cargado el circuito correctamente, false en caso contrario
	 */
	bool loadTrack();

	/**
	 * Devuelve una porcion del circuito
	 * @param clip Especifica la porci�n de la imagen del circuito que se devolver�
	 * @return porci�n de la imagen del circuito
	 */
	SDL_Surface* getScreen(SDL_Rect &clip);

	/**
	 * Devuelve la imagen del circuito
	 * @return imagen del circuito
	 */
	SDL_Surface* getTrackImage();

	/**
	 * Destructor. Libera la memoria usada por la superficie que alacena la imagen del circuito
	 */
	virtual ~Stage();

private:

	SDL_Surface *trackImage; // Superficie que almacena la imagen del circuito
	std::string name; // Nombre del circuito
};

#endif /* STAGE_H_ */
