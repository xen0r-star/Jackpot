#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int Text_Spin (SDL_Renderer *renderer, int Spin, TTF_Font *Sans,SDL_Color White) {

    Spin = Spin > 999 ? 999 : Spin;

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
    Spin_struct_2.x = 531 - (Spin_struct_2.n <= 3 ? ((Spin_struct_2.n - 1) * 6) : 12);
    Spin_struct_2.y = 534;
    Spin_struct_2.w = 12 + (Spin_struct_2.n <= 3 ? ((Spin_struct_2.n - 1) * 12) : 24);
    Spin_struct_2.h = 35;
    // sprintf(Spin_struct_2.c, "%d", Spin);
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
    // printf("Spin : %d, %d, %d, %d, %d, \"%s\"\n", Spin_struct_2.n, Spin_struct_2.x, Spin_struct_2.y, Spin_struct_2.w, Spin_struct_2.h, Spin_struct_2.c);
}



int Text_S (SDL_Renderer *renderer, int S, TTF_Font *Sans,SDL_Color White) {

    S = S > 999999999999 ? 999999999999 : S;

    struct S_struct {
        int n;
        int x;
        int y;
        int w;
        int h;
        char *c;
    };
    struct S_struct S_struct_2;
    S_struct_2.n = log10(S) + 1;
    S_struct_2.x = 423 - (S_struct_2.n <= 12 ? ((S_struct_2.n - 1) * 14) : 0) - ((S_struct_2.n >= 4 && S_struct_2.n <= 6) ? 7 : 0) - ((S_struct_2.n >= 7 && S_struct_2.n <= 9) ? 14 : 0) - ((S_struct_2.n >= 10 && S_struct_2.n <= 12) ? 21 : 0) - (S_struct_2.n > 12 ? 175 : 0);
    S_struct_2.y = 410;
    S_struct_2.w = 15 + (S_struct_2.n <= 12 ? ((S_struct_2.n - 1) * 14) : 0) + ((S_struct_2.n >= 4 && S_struct_2.n <= 6) ? 7 : 0) + ((S_struct_2.n >= 7 && S_struct_2.n <= 9) ? 14 : 0) + ((S_struct_2.n >= 10 && S_struct_2.n <= 12) ? 21 : 0) + (S_struct_2.n > 12 ? 175 : 0);
    S_struct_2.h = 35;
    S_struct_2.c = "10";

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, S_struct_2.c, White); // Text
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = S_struct_2.x;  // X
    Message_rect.y = S_struct_2.y; // Y
    Message_rect.w = S_struct_2.w; // Longeur
    Message_rect.h = S_struct_2.h; // Hauteur
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    // printf("S : %d, %d, %d, %d, %d, \"%s\"\n", S_struct_2.n, S_struct_2.x, S_struct_2.y, S_struct_2.w, S_struct_2.h, S_struct_2.c);
}



int Text_MS (SDL_Renderer *renderer, int MS, TTF_Font *Sans,SDL_Color White) {

    MS = MS > 999999999999 ? 999999999999 : MS;

    struct MS_struct {
        int n;
        int x;
        int y;
        int w;
        int h;
        char *c;
    };
    struct MS_struct MS_struct_2;
    MS_struct_2.n = log10(MS) + 1;
    MS_struct_2.x = 423 - (MS_struct_2.n <= 12 ? ((MS_struct_2.n - 1) * 14) : 0) - ((MS_struct_2.n >= 4 && MS_struct_2.n <= 6) ? 7 : 0) - ((MS_struct_2.n >= 7 && MS_struct_2.n <= 9) ? 14 : 0) - ((MS_struct_2.n >= 10 && MS_struct_2.n <= 12) ? 21 : 0) - (MS_struct_2.n > 12 ? 175 : 0);
    MS_struct_2.y = 486;
    MS_struct_2.w = 15 + (MS_struct_2.n <= 12 ? ((MS_struct_2.n - 1) * 14) : 0) + ((MS_struct_2.n >= 4 && MS_struct_2.n <= 6) ? 7 : 0) + ((MS_struct_2.n >= 7 && MS_struct_2.n <= 9) ? 14 : 0) + ((MS_struct_2.n >= 10 && MS_struct_2.n <= 12) ? 21 : 0) + (MS_struct_2.n > 12 ? 175 : 0);
    MS_struct_2.h = 35;
    MS_struct_2.c = "10";

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, MS_struct_2.c, White); // Text
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = MS_struct_2.x;  // X
    Message_rect.y = MS_struct_2.y; // Y
    Message_rect.w = MS_struct_2.w; // Longeur
    Message_rect.h = MS_struct_2.h; // Hauteur
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    // printf("MS : %d, %d, %d, %d, %d, \"%s\"\n", MS_struct_2.n, MS_struct_2.x, MS_struct_2.y, MS_struct_2.w, MS_struct_2.h, MS_struct_2.c);
}