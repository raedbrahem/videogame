#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "functions.h"
#define GRAVITY 10


int main()
{
TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen;
screen=SDL_SetVideoMode(1000,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("personnage\t1",NULL);


Input I;
Personne p,q;

SDL_Event event;
SDL_Surface *back;

initperso(&q);
initperso(&p);
initinput(&I);

uint32_t t0,dt;
bool done=false;
back=IMG_Load("back.png");

while(!done)
{
t0=SDL_GetTicks();
while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			done=true;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT :
				I.left=1;
      			break;
      			case SDLK_RIGHT :
				I.right=1;
			break;
			case SDLK_UP :
				I.jump=1;

			break;
			}
		break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				I.right=0;
				p.direction=0;
				p.vitesse=0;
			break;
			case SDLK_LEFT :
				I.left=0;
				p.direction=3;
				p.vitesse=0;
      			break;
			case SDLK_UP :
				I.jump=0;

			break;

			}
		break;
		}
	}

 if (I.right==1)
{
	p.direction=2;
	p.acceleration+=0.05;
	p.vitesse=5;

}
else if (I.left==1 )
{
	p.direction=1;
	p.acceleration+=0.05;
	p.vitesse=5;


}
if (I.jump==1)
{

	saut(&p);
}
SDL_Delay(4);
dt=SDL_GetTicks()-t0;
deplacerperso(&p,dt);

p.acceleration-=0.02;

if (p.acceleration<=0)
{
	p.acceleration=0;
}
if (p.acceleration>=0.7)
{
	p.acceleration=0.7;
}

p.vitesse_V+=GRAVITY;
p.rect.y += p.vitesse_V;
 if(p.rect.y >= 300)
 	{
 		 p.rect.y= 300;
 		 p.vitesse_V = 0;
	}
	animerperso(&p);
	SDL_BlitSurface(back, NULL, screen, NULL);
	afficherperso (&p,screen);
	SDL_Flip(screen);
	SDL_Delay(70);
}
TTF_Quit();
}
