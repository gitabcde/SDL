#include <stdio.h>
#include <SDL2/SDL.h>
int myevent(SDL_Event* e);
int main()
{
  if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
    {
      printf("error occur:%s\n",SDL_GetError());
      return 0;
    }
  SDL_Window* mywin=SDL_CreateWindow("SDL_WINDOW",0,0,600,400,SDL_WINDOW_SHOWN);
  SDL_Renderer* myrender=SDL_CreateRenderer(mywin,-1,SDL_RENDERER_ACCELERATED);
  SDL_Event e;
  memset(&e,0,sizeof(e));
  while(1)
    {
      SDL_WaitEvent(&e);
      if(!myevent(&e))
	break;

    }

  return 0;
}

int myevent(SDL_Event* e)
{
  if(e->type==SDL_KEYDOWN)
    {

      switch(e->key.keysym.sym)
      	{
      	case SDLK_a:
      	  printf("case a key is %c\n",e->key.keysym.sym);
      	  break;
      	case SDLK_b:
      	  printf("case b key is %c\n",e->key.keysym.sym);
      	  break;
      	case SDLK_q:
      	  return 0;
      	  break;
      	default:
      	  return 0;
      	  printf("case defalut key is %c\n",e->key.keysym.sym);
      	  break;
      	}
      return 1;
    }
}




















