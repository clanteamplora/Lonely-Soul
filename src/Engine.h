/**
 * Clase encargada del motor gráfico.
 * @version 0.1, 29-abr-2009
 * @author Ibrahim Peraza Kelly
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include <SDL/SDL.h>
#include <iostream>
#include <string>
#include "Stage.h"
#include "SDL/SDL_ttf.h"
#include <sstream>
#include "Player.h"
#include "Sprite.h"
#include <vector>

class Engine
{
public:
	/**
	 * Constructor por defecto, crea un objeto Engine e inicializa la librería SDL.
	 */
	Engine();

	/**
	 * Destructor. Libera la memoria usada por el objeto instanciado.
	 */
	virtual ~Engine();

	/**
	 * Bucle principal donde se desarrollan todas las acciones entre frame y frame de la carrera.
	 */
	int mainLoop();

private:

	/**
	 * Inicializa la libreria SDL, resolucion de la pantalla, sistema de sonido, etc.
	 * @return true si se ha inicializado las librerías correctamente, false en caso contrario.
	 */
	bool sdlInit();

	SDL_Surface *screen; // Superficie que se dibujará en pantalla
	Stage stage; // Circuito sobre el cual se desarrolla la carrera
};

#endif /*ENGINE_H_*/
