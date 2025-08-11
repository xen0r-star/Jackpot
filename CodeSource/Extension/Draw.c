#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void Draw_picture(SDL_Renderer *renderer, int x, int y, int w, int h, const char *filename) {
    SDL_Surface *picture = IMG_Load(filename); // Chargement de l'image
    if (picture == NULL)
        printf("Image loading error : %s\n", SDL_GetError());
    SDL_Texture *picture_texture = SDL_CreateTextureFromSurface(renderer, picture); // Création de la texture du bouton à partir de l'image
    SDL_FreeSurface(picture);
    SDL_Rect picture_rect; // Définition des dimensions de la texture du bouton
    picture_rect.x = x;
    picture_rect.y = y;
    picture_rect.w = w;
    picture_rect.h = h;
    SDL_RenderCopy(renderer, picture_texture, NULL, &picture_rect); // Dessin de la texture sur le renderer
}