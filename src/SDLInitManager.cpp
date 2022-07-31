#include "SDLInitManager.h"
#include "iostream"

using namespace std;

SDLInitManager::SDLInitManager() {
	SDL_Init(SDL_INIT_VIDEO);

	window = NULL;
	window = SDL_CreateWindow("Game", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (window == NULL){
		cout << "panic: Window failed to create at SDL_CreateWindow" << endl;
	}

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); 

	mainEvent = new SDL_Event();
}

SDLInitManager::~SDLInitManager(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

SDL_Renderer* SDLInitManager::GetRenderer(){
	return renderer;
}

SDL_Event* SDLInitManager::GetMainEvent(){
	return mainEvent;
}

void SDLInitManager::Begin(){
	SDL_PollEvent(mainEvent);
	SDL_RenderClear(renderer);
}

void SDLInitManager::End(){
	SDL_RenderPresent(renderer);

}

SDL_Window* SDLInitManager::GetWindow(){
	return window;
}