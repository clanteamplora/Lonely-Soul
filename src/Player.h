/**
 * Clase encargada de la gestión de jugadores.
 * Carga de imágenes que componen los sprites, etc
 * @version 0.1, 29/04/09
 * @author Ibrahim Peraza Kelly
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "SDL/SDL_image.h"
#include <SDL/SDL.h>

/**
 * Clase encargada de la gestión de jugadores.
 * Carga de imágenes que componen los sprites, etc
 * @version 0.1, 29/04/09
 * @author Ibrahim Peraza Kelly
 */

class Player
{
public:
	/**
	 * Constructor por defecto, crea un objeto de tipo Car.
	 */
	Player();

	/**
	 * Crea un objeto del tipo Car y especifica el nombre del coche. Este nombre ha de ser igual a la carpeta que contiene los archivos del coche
	 */
	Player(const char* cname):name(cname){
		loadPlayerImage("player.png");
	};

	/**
	 * Fija el nombre del coche
	 * @param cname Nombre del coche
	 * */
	void setName(const char *cname){name = cname; };

	/**
	 * Carga una imagen del coche
	 * @param img Nombre de la imagen a cargar
	 * @return true si ha cargado la imagen correctamente, false en caso contrario
	 */
	bool loadPlayerImage(const char* img);

	/**
	 * Destructor por defecto
	 */
	virtual ~Player();

	/**
	 * Comprueba eventos y actualiza el estado del coche en el motor físico y gráfico.
	 */
	void update();


//private:
	std::string name; //Nombre del coche
	SDL_Surface *carImage; // Imagen del coche

};

#endif /* PLAYER_H_ */
