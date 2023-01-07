#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int Text_Spin (SDL_Renderer *renderer, int Spin, TTF_Font *Sans,SDL_Color White) {

    struct Spin_struct {
        int n;
        int x;
        int y;
        int w;
        int h;
        char *c;
    };
    struct Spin_struct Spin_struct_2;
    Spin_struct_2.n = log10(Spin) + 1;
    Spin_struct_2.x = 531 - ((Spin_struct_2.n - 1) * 6);
    Spin_struct_2.y = 534;
    Spin_struct_2.w = 12 + ((Spin_struct_2.n - 1) * 12);
    Spin_struct_2.h = 35;
    Spin_struct_2.c = "10";

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, Spin_struct_2.c, White); // Text
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = Spin_struct_2.x;  // X
    Message_rect.y = Spin_struct_2.y; // Y
    Message_rect.w = Spin_struct_2.w; // Longeur
    Message_rect.h = Spin_struct_2.h; // Hauteur
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    printf("%d, %d, %d, %d, %d, \"%s\"", Spin_struct_2.n, Spin_struct_2.x, Spin_struct_2.y, Spin_struct_2.w, Spin_struct_2.h, Spin_struct_2.c);
}



int Text_S (SDL_Renderer *renderer, int S, TTF_Font *Sans,SDL_Color White) {

    struct Spin_struct {
        int n;
        int x;
        int y;
        int w;
        int h;
        char *c;
    };
    struct Spin_struct Spin_struct_2;
    Spin_struct_2.n = log10(S) + 1;
    Spin_struct_2.x = 410;
    Spin_struct_2.y = 410;

    Spin_struct_2.w = 15 + ((S - 1) * 14);
    if (Spin_struct_2.n >= 4 || Spin_struct_2.n <=6) {
        Spin_struct_2.w = Spin_struct_2.w + 7;
    }

    if (Spin_struct_2.n >= 7 || Spin_struct_2.n <= 9) {
        Spin_struct_2.w = Spin_struct_2.w + 14;
    }
    
    if (Spin_struct_2.n >= 10 || Spin_struct_2.n <= 12) {
        Spin_struct_2.w = Spin_struct_2.w + 21;

    if (Spin_struct_2.n > 12) {
        Spin_struct_2.w = 191;
    }
    

    Spin_struct_2.h = 35;
    Spin_struct_2.c = "10";

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, Spin_struct_2.c, White); // Text
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = Spin_struct_2.x;  // X
    Message_rect.y = Spin_struct_2.y; // Y
    Message_rect.w = Spin_struct_2.w; // Longeur
    Message_rect.h = Spin_struct_2.h; // Hauteur
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    printf("%d, %d, %d, %d, %d, \"%s\"", Spin_struct_2.n, Spin_struct_2.x, Spin_struct_2.y, Spin_struct_2.w, Spin_struct_2.h, Spin_struct_2.c);
}