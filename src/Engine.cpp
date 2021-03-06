/*
 * Engine.cpp
 *
 *  Created on: 29-abr-2009
 *      Author: deka
 */

#include "Engine.h"

/**
* Constructor por defecto, crea un objeto Engine e inicializa la librer�a SDL.
*/
Engine::Engine()
{
	//Inicializamos el sistema SDL
	sdlInit();
	stage.setName("prueba");
	stage.loadTrack();
}

/**
* Destructor. Libera la memoria usada por el objeto instanciado.
*/
Engine::~Engine()
{
}

/**
* Bucle principal donde se desarrollan todas las acciones entre frame y frame de la carrera.
*/
int Engine::mainLoop()
{
	SDL_Event evento; // Variable de eventos
	Uint8 *teclado; // Vector vector de almacenamiento del estado del teclado

	/*TTF_Init();
	Uint32 time = SDL_GetTicks(); //Tiempo transcurrido
	SDL_Color textColor = { 0xF0, 0xFF, 0xF0 };
	TTF_Font *font = TTF_OpenFont( "lazy.ttf", 14 );*/

    SDL_Rect cTrack = {0, 0, 800, 600}; //Coordenadas y tama�o de la imagen del circuito que se mostrar� en el frame actual
	// Posici�n del coche
	SDL_Rect pos_pj;
	pos_pj.x = 300;
	pos_pj.y = 300;

	// Creamos el jugador
	Sprite pj1;
	//Sprite pj1("Sprites/player.png", 140, 92, "player1");
	pj1.loadSpriteFile("Sprites/player.txt");
	/*std::vector<unsigned int> secuencia;
	for (unsigned int i = 11; i < 19; i++)
		secuencia.push_back(i);
	pj1.loadAction("walk", secuencia);

	std::vector<unsigned int> stand;
	stand.push_back(1);
	pj1.loadAction("stand", stand);*/


    for(;;)
    {
    	// Consultamos los eventos
    	while(SDL_PollEvent(&evento))
    	{
    		if(evento.type == SDL_QUIT) // Si es de salida
    		{
    			SDL_Quit(); //Cerramos el sistema SDL
    			return 0;
    		}
    	}

    	// Capturamos el estado del teclado
    	SDL_PumpEvents();
    	teclado = SDL_GetKeyState(NULL);

    	//Actualizamos posici�n del pj
    	/*pos_pj.x -= teclado[SDLK_LEFT] ? 10 : 0;
    	pos_pj.x += teclado[SDLK_RIGHT] ? 10 : 0;*/

    	//Actualizamos posici�n del pj
    	cTrack.x -= teclado[SDLK_LEFT] ? 10 : 0;
    	cTrack.x += teclado[SDLK_RIGHT] ? 10 : 0;

    	//Actualizamos el scroll
    	stage.paint(screen, cTrack.x, cTrack.y);
    	//SDL_BlitSurface(stage.getScreen(cTrack), &cTrack, screen, &dRect);

    	//Dibujamos el pj
    	if (teclado[SDLK_LEFT] || teclado[SDLK_RIGHT])
    		pj1.execute("walk");
    	else
    	{
    		pj1.execute("stand");
    		pj1.reset("walk");
    	}
    	pj1.paint(screen, 300, 300);

    	//Muestra contador de tiempo
    	//std::stringstream text;
    	//text << "TIEMPO: " << SDL_GetTicks() - time;

    	//SDL_Surface* mierda = TTF_RenderText_Solid(font, text.str().c_str(), textColor);
    	//SDL_BlitSurface( mierda, NULL, screen, NULL);
    	//SDL_FreeSurface( mierda );
    	//text.flush();

    	SDL_Flip(screen); //Actualizamos pantalla
    	SDL_Delay(100); //ChAPUZA, esperamos 1 decima de segundo
    }
	return 0;
}

/**
 * Inicializa la libreria SDL, resolucion de la pantalla, sistema de sonido, etc.
 */
bool Engine::sdlInit()
{
    // Inicializamos SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {	// En caso de  error
    	std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
    	exit(1);
    }

    screen = SDL_SetVideoMode(800, 600, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);

    if(screen == NULL)
    {// Si no hemos podido inicializar la superficie
    	std::cerr << "Error al crear la superficie: " << SDL_GetError() << std::endl;
    	SDL_Quit();
    	exit(1);
    }

    // Personalizamos el titulo de la ventana
    SDL_WM_SetCaption("Lonely Soul", NULL);

    return 0;
}

