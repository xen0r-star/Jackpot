#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

void Draw_picture(SDL_Renderer *renderer, int x, int y, int w, int h, const char *filename) {
    SDL_Surface *image = IMG_Load(filename); // Chargement de l'image
    if (image == NULL)
        printf("Erreur de chargement de l image : %s\n", SDL_GetError());
    SDL_Texture *image_texture = SDL_CreateTextureFromSurface(renderer, image); // Création de la texture du bouton à partir de l'image
    SDL_FreeSurface(image);
    SDL_Rect image_rect; // Définition des dimensions de la texture du bouton
    image_rect.x = x;
    image_rect.y = y;
    image_rect.w = w;
    image_rect.h = h;
    SDL_RenderCopy(renderer, image_texture, NULL, &image_rect); // Dessin de la texture sur le renderer
}