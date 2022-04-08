#include "functions.h"
void initperso (Personne *p)
{
p->personnage=IMG_Load("spr.png");
p->rect.x=0;
p->rect.y=100;
p->direction=0;
p->rect.w=48;
p->rect.h=48;
p->vitesse_V=0;

p->pos_sprite.x=0;
p->pos_sprite.y=0;
p->pos_sprite.h=69;
p->pos_sprite.w=50;

p->vitesse=0;
p->acceleration=0;
}





void afficherperso (Personne *p,SDL_Surface *screen)
{
  SDL_BlitSurface(p->personnage,&p->pos_sprite,screen,&p->rect);
}





void animerperso (Personne *p){
if(p->pos_sprite.x>=150)
	p->pos_sprite.x=0;
else p->pos_sprite.x +=50;
	p->pos_sprite.y=p->direction*69;
}


void deplacerperso(Personne *p,Uint32 dt){
double dx;

dx=(1/2)*dt*dt*p->acceleration + dt*p->vitesse;
if ((p->direction==0) || (p->direction==2))
	p->rect.x += dx;
else
	p->rect.x -= dx ;
}

void saut (Personne *p)
{
  if(p->rect.y==300)
	p->vitesse_V = -60;
}

void initinput (Input *I)
{
I->left=0;
I->right=0;
I->jump=0;
}
