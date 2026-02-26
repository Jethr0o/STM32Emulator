// SDL and LVGL libraries for rendering UI of Riverdi's display
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <stdlib.h>

#include "headers/utils.h"
#include "lv_conf.h"
#include "lvgl.h"



int main(){
	_initAll_();	
	//if(_initAll_() == 0){
		//imageLoop();
	lv_example_style_7();
	//}else{
	//	return EXIT_FAILURE;
	//}
	return EXIT_SUCCESS;
}


static uint8_t _initAll_(){
	lv_init();
	lv_display_t * lvRiverdiDisp = lv_sdl_window_create(RIVERDI_SCREEN_WIDTH, RIVERDI_SCREEN_HEIGHT);
	return EXIT_SUCCESS;
}

void imageLoop(){

	for(;;){

	}

}


#include "lvgl/examples/lv_examples.h"
#if LV_BUILD_EXAMPLES && LV_USE_ARC

/**
 * Using the Arc style properties
 */
void lv_example_style_7(void)
{
    static lv_style_t style;
    lv_style_init(&style);

    lv_style_set_arc_color(&style, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_arc_width(&style, 4);

    /*Create an object with the new style*/
    lv_obj_t * obj = lv_arc_create(lv_screen_active());
    lv_obj_add_style(obj, &style, 0);
    lv_obj_center(obj);
}
#endif
