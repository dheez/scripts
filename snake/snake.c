#include<SDL2/SDL.h>
#include<SDL2/SDL_video.h>
#include<SDL2/SDL_timer.h>
#include<SDL2/SDL_events.h>
#include<SDL2/SDL_image.h>
#include<stdio.h>
#include<stdlib.h>
int getrandom50(int rand);
typedef struct snake{		//struct of the snake (position, direction, pointer to next)
	SDL_Rect hitbox;
	int oldpos[2];
	int dir[2];
	struct snake *next;
}SNAKE;
	SDL_Rect foodhitbox;

void move(SNAKE* sn){          //function that moves the snake (dumb vector shit)
	
	if(sn->next != NULL){
		sn->next->dir[0] = sn->hitbox.x-sn->next->hitbox.x;
		sn->next->dir[1] = sn->hitbox.y-sn->next->hitbox.y;
	}
	sn->oldpos[0] = sn->hitbox.x;
	sn->oldpos[1] = sn->hitbox.y;
	sn->hitbox.x += sn->dir[0]; 
	sn->hitbox.y += sn->dir[1];
		if( sn->hitbox.x < 0){
			sn->hitbox.x = 1850;
		}
		if( sn->hitbox.x > 1850){
			sn->hitbox.x = 0;
		}
		if( sn->hitbox.y < 0){
			sn->hitbox.y = 1050;
		}
		if( sn->hitbox.y > 1050){
			sn->hitbox.y = 0;
		}
	if(sn->next != NULL){
		move(sn->next);
	}
	
}

int length(SNAKE *sn){
	if(sn->next != NULL){
		return 1 + length(sn->next);
	}
	else return 1;
}

SDL_bool collision(SNAKE *sn, SNAKE *n ){ //function which tests, if there is a collision with the snake
	
	SDL_bool b = SDL_FALSE;
	for(SNAKE* x = n; x != NULL; x = x -> next){
		b = b || SDL_HasIntersection(&sn->hitbox, &x->hitbox);	
	}	
	return b;
}

SNAKE* last(SNAKE *sn){			//last struct of the snake
	if(sn->next == NULL){
		return sn;
	}	
	else return last(sn->next); 
}

int grow(SNAKE *sn){	//when snake eats the food, a new node is added to the back
	SDL_Rect hit = sn->hitbox;
	if (SDL_HasIntersection(&hit, &foodhitbox)){
		foodhitbox.x = getrandom50(rand() % 1870);
		foodhitbox.y = getrandom50(rand() % 530);
		SNAKE* l = last(sn);
		SNAKE *tail = (SNAKE*)malloc(sizeof(SNAKE)); //important!! else segmentation fault.
		tail->hitbox.x = l->oldpos[0];
		tail->hitbox.y = l->oldpos[1];
		tail->dir[0] = l->hitbox.x-tail->hitbox.x; 
		tail->dir[1] = l->hitbox.y-tail->hitbox.y;
		tail->next = NULL;
		l->next = tail;
		return 1;
	}
	else return 0;
}
