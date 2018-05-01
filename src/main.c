//BEGIN HEAD
//BEGIN DESCRIPTION

/* This is a light SDL2 template
 *
 */

/* DEFINED PROGRESS GOALS
 * 
 * None atm
 * 
 */
//END   DESCRIPTION

//BEGIN INCLUDES
//system headers
#include <math.h>
//local headers
#include "helper.h"
//END   INCLUDES

//BEGIN CPP DEFINITIONS
#define WHITE 255,255,255,255
#define BLACK 0,0,0,255
#define RED   255,0,0,255
#define WW 550
#define WH (WW/16)*12
//END   CPP DEFINITIONS

//BEGIN DATASTRUCTURES
//END	DATASTRUCTURES

//BEGIN GLOBALS
int ww=WW;
int wh=WH;

//BEGIN VISIBLES
SDL_Surface    *temp_surface	= NULL;

SDL_Texture    *icon		= NULL;
SDL_Rect 	icon_dst;

SDL_Texture    *exit_b		= NULL;
SDL_Rect 	exit_b_dst;

SDL_Rect 	bar_dst;

SDL_Texture    *buttons		= NULL;
SDL_Rect 	b1_dst;
SDL_Rect 	b1_src;

SDL_Rect 	b2_dst;
SDL_Rect 	b2_src;

SDL_Texture    *logo		= NULL;
SDL_Rect 	logo_dst;
//END 	VISIBLES

SDL_Point	mouse;

//END   GLOBALS

//BEGIN FUNCTION PROTOTYPES
void assets_in	(void);
void assets_out	(void);
void draw	(void);
SDL_bool PointInCircle(SDL_Point *, SDL_Rect *);
//END	FUNCTION PROTOTYPES

//END 	HEAD

//BEGIN MAIN FUNCTION
int main(int argc, char *argv[])
{

(void)argc;
(void)argv;

//BEGIN INIT
init();
assets_in();

//BEGIN WINDOW
SDL_SetWindowPosition(Window,0,0);
SDL_SetWindowSize(Window,ww,wh);
SDL_SetWindowTitle(Window, "SDL2 Template");
SDL_ShowWindow(Window);
//END WINDOW

SDL_Event event;
int running = 1;
//END   INIT

//BEGIN MAIN LOOP
while(running){
	SDL_GetMouseState(&mouse.x,&mouse.y);
	//BEGIN EVENT LOOP
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running =0;
		}
		if(event.type == SDL_MOUSEMOTION){
			;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_RIGHT){
				;
			}
			if(event.button.button == SDL_BUTTON_MIDDLE){
				;
			}
			if(event.button.button==SDL_BUTTON_LEFT && PointInCircle(&mouse,&b1_dst)){
				SDL_MinimizeWindow(Window);
			}
			if(event.button.button==SDL_BUTTON_LEFT && PointInCircle(&mouse,&exit_b_dst)){
				running=0;
			}
		}
		if(event.type == SDL_KEYDOWN ){
			switch(event.key.keysym.sym ){
				case SDLK_ESCAPE:
					running =0;
					break;

				case SDLK_r:
				case SDLK_BACKSPACE:
					break;

				case SDLK_p:	
				case SDLK_SPACE:
					break;
					
				default:
					break;
			}
		}
	}
	//END   EVENT LOOP
	//BEGIN RENDERING
	SDL_SetRenderDrawColor(Renderer, WHITE);
	SDL_RenderClear(Renderer);

	draw();
	SDL_Delay(16);
	SDL_RenderPresent(Renderer);
	//END   RENDERING
}
//END   MAIN LOOP

assets_out();
exit_();
return EXIT_SUCCESS;

}
//END   MAIN FUNCTION

//BEGIN FUNCTIONS
void assets_in(void)
{

	//BEGIN ICON
	temp_surface=IMG_Load("./assets/gfx/icon.png");
	SDL_SetWindowIcon(Window, temp_surface);
	icon=SDL_CreateTextureFromSurface(Renderer, temp_surface);
	SDL_QueryTexture(icon, NULL, NULL, &icon_dst.w, &icon_dst.h);
	icon_dst.w*=.75;
	icon_dst.h*=.75;
	icon_dst.x=0;
	icon_dst.y=0;
	//END 	ICON
	
	//BEGIN BAR
	bar_dst.w=ww;
	bar_dst.h=icon_dst.h;
	bar_dst.x=0;
	bar_dst.y=0;
	//END 	BAR
	
	//BEGIN B1
	temp_surface=IMG_Load("./assets/gfx/buttons.png");
	buttons=SDL_CreateTextureFromSurface(Renderer, temp_surface);

	b1_dst.w=icon_dst.h;
	b1_dst.h=icon_dst.h;
	b1_dst.x=ww-b1_dst.w;
	b1_dst.y=0;
	
	b1_src.w=48;
	b1_src.h=48;
	b1_src.x=52;
	b1_src.y=0;
	//END 	B1
	
	//BEGIN B2
	b2_dst.w=icon_dst.h;
	b2_dst.h=icon_dst.h;
	b2_dst.x=ww-(b2_dst.w*2)-3;
	b2_dst.y=0;
	
	b2_src.w=48;
	b2_src.h=48;
	b2_src.x=0;
	b2_src.y=0;
	//BEGIN B2
	
	//BEGIN LOGO
	temp_surface = IMG_Load("./assets/gfx/logo.png");
	logo = SDL_CreateTextureFromSurface(Renderer, temp_surface);
	SDL_QueryTexture(logo, NULL, NULL, &logo_dst.w, &logo_dst.h);
	logo_dst.x=(ww/2)-(logo_dst.w/2);
	logo_dst.y=(wh/2)-(logo_dst.h/2);
	//END 	LOGO
	
	//BEGIN EXIT
	temp_surface = IMG_Load("./assets/gfx/exit.png");
	exit_b = SDL_CreateTextureFromSurface(Renderer, temp_surface);
	SDL_QueryTexture(exit_b, NULL, NULL, &exit_b_dst.w, &exit_b_dst.h);
	exit_b_dst.x=ww-(exit_b_dst.w*2);
	exit_b_dst.y=wh-(exit_b_dst.h*2);
	//END 	EXIT

}

void assets_out(void)
{
	SDL_DestroyTexture(buttons);
	SDL_DestroyTexture(exit_b);
	SDL_DestroyTexture(logo);
	SDL_DestroyTexture(icon);
}

void draw(void)
{
	SDL_SetRenderDrawColor(Renderer, 80, 80, 80, 150);
	SDL_RenderFillRect(Renderer, &bar_dst);
	SDL_RenderCopy(Renderer, icon, NULL, &icon_dst);
	SDL_RenderCopy(Renderer, buttons, &b1_src, &b1_dst);
	SDL_RenderCopy(Renderer, buttons, &b2_src, &b2_dst);
	SDL_RenderCopy(Renderer, logo, NULL, &logo_dst);
	SDL_RenderCopy(Renderer, exit_b, NULL, &exit_b_dst);

}
SDL_bool PointInCircle(SDL_Point *point, SDL_Rect *square)
{
	float x=square->x+square->w/2;
	float y=square->y+square->h/2;;
	float r=square->h/2;
	
	float dx=x-point->x;
	float dy=y-point->y;
	
	float distance=sqrtf(dx * dx + dy * dy);
	
	if (distance < r + 1)
		return SDL_TRUE;
	return SDL_FALSE;
}
//END   FUNCTIONS
