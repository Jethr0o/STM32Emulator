// SDL and LVGL libraries for rendering UI of Riverdi's display
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "lvgl"

#include <stdlib.h>

#include "headers/utils.h"

int main(){
	
	if(_initAll_() == 0)
		imageLoop();
	else
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}


static uint8_t _initAll_(){

	return EXIT_SUCCESS
}

void imageLoop(){

	for(;;){

	}

}
