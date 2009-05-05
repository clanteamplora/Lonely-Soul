/**
 * Clase encargada de toda la gestión de los sprites.
 * @version 0.1, 03/05/09
 * @author Ibrahim Peraza Kelly
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>


class Sprite {
public:
	/**
	 * Crea un objeto de tipo Sprite
	 */
	Sprite();

	/**
	 * Carga la imagen que contiene las animaciones del sprite y el tamaño de cada animación
	 * @param img Nombre y directorio de la imagen a cargar que contiene la rejilla de imágenes
	 * @param heightF Alto de cada frame
	 * @param widthF Ancho de cada frame
	 * @param sname Nombre del sprite
	 */
	Sprite(std::string img, int heightF, int widthF, std::string sname);

	/**
	 * Destructor. Libera la memoria usada por la superficie que contiene las animaciones del sprite
	 */
	virtual ~Sprite();

	/**
	 * Carga una animación. Debemos indicar el nombre de la acción y las secuencias de imágenes que la componen
	 * @param aname Nombre de la acción
	 * @param secuencia Números de imágenes que componen la animación
	 */
	void loadAction(std::string aname, std::vector<unsigned int> secuencia);

	/**
	 * Ejecuta una de las acciones (secuencias) del sprite
	 * @param action Nombre de la secuencia a ejecutar
	 */
	void execute(std::string action);

	/**
	 * Reinicia el contador de frames de una secuencia
	 * @param action Nombre de la secuencia a reiniciar
	 */
	void reset(std::string action);

	/**
	 * Dibuja el último frame de la última secuencia ejecutada
	 * @param pantalla Superficie sobre la que se dibujará el sprite
	 * @x Posición en el eje X en la cual se dibujará el sprite
	 * @y Posición en el eje Y en la cual se dibujará el sprite
	 */
	void paint(SDL_Surface *pantalla, int x, int y);


	/**
	 * Carga la definción de un sprite a partir de un archivo
	 * @param fname Nombre del fichero que contiene la definición del sprite
	 */
	void loadSpriteFile(std::string fname);

protected:
	/**
	 * Carga la imagen el sprite
	 * @param img Imagen a cargar
	 */
	void loadImage(std::string img);

private:
	SDL_Surface *imagen; // Imagen que contiene el sprite
	int width, height; // Ancho y alto de cada animación
	int x, y; // Posición del sprite
	int rows, cols; // Número de filas y columnas que contine la imagen del sprite
	std::string name; // Nombre del sprite
	std::map<std::string, std::vector<unsigned int> > secuencias; // Par de <nombre - secuencia de frames> que componen cada imagen
	std::map<std::string, int > indice_sec; // Par de <nombre - indice> que se encarga de llevar la cuenta del frame en que se encuentra la animación.
	std::string lastAction;
};

#endif /* SPRITE_H_ */
