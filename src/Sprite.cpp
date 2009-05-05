/*
 * Sprite.cpp
 *
 *  Created on: 03-may-2009
 *      Author: deka
 */

#include "Sprite.h"

/**
* Crea un objeto de tipo Sprite
*/
Sprite::Sprite(){}

/**
 * Carga la imagen que contiene las animaciones del sprite y el tamaño de cada animación
 * @param img Nombre y directorio de la imagen a cargar
 */
Sprite::Sprite(std::string img, int heightF, int widthF, std::string sname) {
	x = 0;
	y = 0;
	width = widthF;
	height = heightF;
	name = sname;

	loadImage(img);
}

/**
 * Carga la imagen el sprite
 * @param img Imagen a cargar
 */
void Sprite::loadImage(std::string img)
{
	imagen = SDL_DisplayFormatAlpha(IMG_Load(img.c_str()));

	if(imagen == NULL)
		fprintf(stderr, "No se puede cargar la imagen: %s\n", SDL_GetError());
	else
	{
		// Calculamos el número de filas y columnas que contiene la imagen que incluye las animaciones del sprite
		cols = imagen->w / width;
		rows = imagen->h / height;
	}
}

/**
 * Destructor. Libera la memoria usada por la superficie que contiene las animaciones del sprite
 */
Sprite::~Sprite() {
	SDL_FreeSurface(imagen);
}


/**
 * Carga una animación. Debemos indicar el nombre de la acción y las secuencias de imágenes que la componen
 * @param aname Nombre de la acción
 * @param secuencia Números de imágenes que componen la animación
 */
void Sprite::loadAction(std::string aname, std::vector<unsigned int> secuencia)
{
	secuencias.insert(std::pair<std::string, std::vector<unsigned int> >(aname, secuencia));
	indice_sec.insert(std::pair<std::string, int >(aname, -1)); // Ponemos el contador de frames de la secuencia a 0
}


/**
 * Ejecuta una de las acciones (secuencias) del sprite
 * @param action Nombre de la secuencia a ejecutar
 */
void Sprite::execute(std::string action)
{
	if ((unsigned int)indice_sec[action] < (secuencias[action].size() - 1)) //Si no hemos llegado al final de la animación avanzamos
		indice_sec[action]++;
	else // En caso contrario la reiniciamos
		indice_sec[action] = 0;
	lastAction = action; // Almacenamos la acción ejecutada para que a la hora de dibujar sepamos en qué secuencia nos encontramos
}

/**
 * Dibuja el último frame de la última secuencia ejecutada
 * @param pantalla Superficie sobre la que se dibujará el sprite
 * @x Posición en el eje X en la cual se dibujará el sprite
 * @y Posición en el eje Y en la cual se dibujará el sprite
 */
void Sprite::paint(SDL_Surface *pantalla, int x, int y)
{
	SDL_Rect origen, destino;

	destino.x = x;
	destino.y = y;

	destino.w = 0;
	destino.h = 0;

	unsigned int frameActual = secuencias[lastAction].at(indice_sec[lastAction]);

	// Calculamos las coordenadas de la esquina superior izquierda de la imagen a mostrar
	origen.x = ((frameActual % cols) * width);
	origen.y = ((frameActual / cols) * height);


	origen.w = width;
	origen.h = height;

	SDL_BlitSurface(imagen, &origen, pantalla, &destino);

}


/**
 * Reinicia el contador de frames de una secuencia
 * @param action Nombre de la secuencia a reiniciar
 */
void Sprite::reset(std::string action)
{
	indice_sec[action] = -1;
}

/**
 * Carga la definción de un sprite a partir de un archivo
 * @param fname Nombre del fichero que contiene la definición del sprite
 */
void Sprite::loadSpriteFile(std::string fname)
{
	std::ifstream fin(fname.c_str());
	std::string img;

	fin >> img;
	fin >> width;
	fin >> height;

	loadImage(std::string("Sprites/" + img));

	std::string tmp, accion;
	std::stringstream line;
	std::vector<unsigned int> secuencia;
	int frame;
	std::getline(fin, tmp);
	while (!fin.eof())
	{
		std::getline(fin, tmp);
		//fin.getline(tmp);

		line.str(tmp);
		line >> accion;
		std::cout << "Accion= " << accion;
		while (!line.eof())
		{
			line >> frame;
			std::cout << " " << frame;
			secuencia.push_back(frame);
		}
		std::cout << std::endl;
		line.clear();
		loadAction(accion, secuencia);
		secuencia.clear();
	}
	fin.close();
}
