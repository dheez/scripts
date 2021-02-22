#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<SDL2/SDL_ttf.h>
#include "snake.c"
int getrandom50(int rand);
int main() 
{ 
	//char* sc;
	srand(time(NULL)); //initializing random seed every second
	SNAKE *sn = (SNAKE*)malloc(sizeof(SNAKE)); //declaring snake
	sn->hitbox.x = getrandom50(rand() % 1870); //random position of snake at first
	sn->hitbox.y = getrandom50(rand() % 1030);
	sn->dir[0] = 0;
	sn->dir[1] = 0;
	sn->next = NULL;
	foodhitbox.x = getrandom50(rand() % 1870);//random food pos
	foodhitbox.y = getrandom50(rand() % 1030);
    // returns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {			//init SDL 
        printf("error initializing SDL: %s\n", SDL_GetError()); 
	SDL_Quit();
	return 1;
    } 
    SDL_Window* win = SDL_CreateWindow("SNAKE",				//init Window 
                                       SDL_WINDOWPOS_CENTERED, 
                                       SDL_WINDOWPOS_CENTERED, 
                                       1920, 1080, 0); 
    if (win == NULL) {
	printf("error");
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 1;
   }

	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC; //init renderer
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
	if(!rend){
		printf("error with renderer");
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}
	
	    SDL_Surface *snak = IMG_Load("snake.png"); //load pictures to surfaces 
	    SDL_Surface *f = IMG_Load("food.png"); 
	if(!snak && !f){
		printf("error with creating surfaces");
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(rend);
		SDL_Quit();
		return 1;
	}
	//SDL_Color green = {0,255,0};
	//TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
	//sprintf(sc, "%d", score);
	//SDL_Surface* scoretext = TTF_RenderText_Solid(Sans, sc, green);
	//SDL_Texture* scoretex = SDL_CreateTextureFromSurface(rend, scoretext); 
	//SDL_FreeSurface(scoretext);
	//SDL_Rect scorebox = (SDL_Rect){.x = 1870, .y = 1030};
	//SDL_QueryTexture(scoretex, NULL, NULL, &scorebox.w, &scorebox.h);


	    SDL_Texture* stex = SDL_CreateTextureFromSurface(rend, snak); //make textures
	    SDL_Texture* ftex = SDL_CreateTextureFromSurface(rend, f);
	if(!stex && !ftex){
		printf("error with creating textures");
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(rend);
		SDL_Quit();
		return 1;
	}
	    SDL_FreeSurface(snak); 			//surfaces not needed anymore: free them
	    SDL_FreeSurface(f);
            //Update the surface
		SDL_SetRenderDrawColor(rend,0,0,0,255);
		SDL_RenderClear(rend);	
		SDL_RenderPresent(rend);

		SDL_QueryTexture(stex, NULL, NULL, &sn->hitbox.w, &sn->hitbox.h);
		SDL_QueryTexture(ftex, NULL, NULL, &foodhitbox.w, &foodhitbox.h);
		
   SDL_Event e;				//event to capture input like keyboard
/**
	while(SDL_PollEvent(&e)){//randomly generate start direction
		switch(e.type){
			case SDL_KEYDOWN:
			sn->dir[0] = rand() % 50;
			if (sn->dir[0] != 0){
				sn->dir[1] = 0;
			}
			else{
				sn->dir[1] = rand() % 50;
				if(sn->dir[1] == 0){
					sn->dir[1] += 1;
				}	
			}
			break;
		}
	}
**/
   int quit = 0;
   while(!quit && !collision(sn, sn->next)){//main loop 
		SDL_RenderClear(rend);
	   while(SDL_PollEvent(&e)){//event handling
		switch(e.type){
			case SDL_QUIT:
				quit = 1;
				break;

			case SDL_KEYDOWN:
				switch (e.key.keysym.scancode){//key handling
					case SDL_SCANCODE_W:
						sn->dir[1] = -50;
						sn->dir[0] = 0;
						break;
					case SDL_SCANCODE_S:
						sn->dir[1] = 50;
						sn->dir[0] = 0;
						break;
					case SDL_SCANCODE_A:
						sn->dir[0] = -50;
						sn->dir[1] = 0;
						break;
					case SDL_SCANCODE_D:
						sn->dir[0] = 50;
						sn->dir[1] = 0;
						break;
				}
		} 

	   }
	move(sn);
	for(SNAKE* s = sn; s != NULL; s = s->next){
		SDL_RenderCopy(rend,stex,NULL,&s->hitbox);
	}
	grow(sn);
	for(SNAKE* s = sn; s != NULL; s = s -> next){
		SDL_QueryTexture(stex, NULL, NULL, &s->hitbox.w, &s->hitbox.h);
	}
	//sprintf(sc, "%d", score);
	//SDL_QueryTexture(scoretex, NULL, NULL, &scorebox.w, &scorebox.h);
	//SDL_RenderCopy(rend, scoretex, NULL, &scorebox);
	SDL_RenderCopy(rend, ftex, NULL, &foodhitbox);
	SDL_RenderPresent(rend);
	SDL_Delay(8000/60);
   }
	if(collision(sn, sn->next)){
		printf("GAME OVER\n");
		printf("Score :%d\n", length(sn));
	}
   SDL_DestroyWindow(win);
   SDL_Quit();
   return 0;
} 

int getrandom50(int rand){
	int rest = rand % 50;
	return rand - rest;
}
