#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct perso
{
double vitesse,acceleration;
SDL_Surface *personnage;
SDL_Rect rect;
SDL_Rect pos_sprite;
float vitesse_V;
int direction ; 
}Personne;


typedef struct Input
{
int left;
int right;
int jump;
}Input;


void initperso (Personne *p);
void afficherperso (Personne *p,SDL_Surface *screen);
void animerperso (Personne *p);
void deplacerperso(Personne *p,Uint32 dt);
void initinput (Input *I);
void saut(Personne *p);
#endif

