#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

int myevent(SDL_Event* e);
int rendertext(TTF_Font* font,char* str,SDL_Renderer* rend);
TTF_Font* font=NULL;
SDL_Renderer* myrender;

int main(int argc,char** argv)
{
  if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
    return 1;
  
  if(TTF_Init()==-1)
    {
      printf("ttf_init error\n");
      printf(TTF_GetError());
      return 0;
    }
  SDL_Window* mywin=SDL_CreateWindow("hello",0, 0,1366, 768, SDL_WINDOW_SHOWN);
  myrender=SDL_CreateRenderer(mywin,-1,SDL_RENDERER_ACCELERATED);
  SDL_ShowWindow(mywin);


  // SDL_Texture* mytex=IMG_LoadTexture(myrender,"/home/liyou/Picture/s1.png");
  // SDL_RenderCopy(myrender,mytex,NULL,NULL);
  // mytex=IMG_LoadTexture(myrender,"/home/liyou/Picture/2.png");
  // SDL_Rect myrec;
  // SDL_QueryTexture(mytex,NULL,NULL,&myrec.w,&myrec.h);
  // myrec.x=100;
  // myrec.y=100;
  // SDL_RenderCopy(myrender,mytex,NULL,NULL);
  // SDL_RenderPresent(myrender);

  
  font=TTF_OpenFont("./FreeSans.ttf",30);
  if(font==NULL)
    {
      printf("font is %d\n",font);
      printf(TTF_GetError());
      return 0;
    }

  SDL_Event e;
  
  while(1)
    {
      SDL_PollEvent(&e);
      if(myevent(&e)==0)
	break;
    }
  SDL_Quit();
 
  return 0;
}

int myevent(SDL_Event* e)
{
  char str[100];
  if(e->type==SDL_KEYDOWN)
    {
      sprintf(str,"%c is pressed\n",e->key.keysym.sym);
      switch(e->key.keysym.sym)
	{
	case SDLK_q:
	  return 0;
	  break;
	case SDLK_a:

	  rendertext(font,str,myrender);
	  break;
	
	case SDLK_b:
	  rendertext(font,str,myrender);
	  break;
	
	default:
	  rendertext(font,str,myrender);
	  break;
	
	}
    }
  return 1;
}

int rendertext(TTF_Font* font,char* str,SDL_Renderer* rend)
{
  SDL_Color col;
  col.r=col.g=col.b=255;
  
  SDL_Surface* surf=TTF_RenderText_Blended(font,str,col);
  SDL_Texture* tex=SDL_CreateTextureFromSurface(rend,surf);
  SDL_RenderClear(rend);
  SDL_RenderCopy(rend,tex,NULL,NULL);
  SDL_FreeSurface(surf);
  SDL_DestroyTexture(tex);
  SDL_RenderPresent(rend);

  return 0;
}




















