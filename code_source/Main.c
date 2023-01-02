#include <stdio.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

// #include "Extension/Read_file.c"
// #include "Extension/Write_file.c"


const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 600;

// Frame
void sleep_end_of_frame() {
    struct timespec sleep;
    sleep.tv_sec = 0;
    sleep.tv_nsec = 16 * 1000 * 1000;
    nanosleep(&sleep, NULL);
}

// // Image
// void afficher_image(SDL_Renderer *renderer, const char *nom_fichier)
// {
//     SDL_Surface *image = IMG_Load(nom_fichier); // Charger l'image à afficher
//     if(!image) {
//         printf("Erreur de chargement de l'image : %s",SDL_GetError());
//     }
//     SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image); // Créer une texture à partir de l'image chargée
//     SDL_RenderCopy(renderer, texture, NULL, NULL); // Afficher l'image dans la fenêtre
//     SDL_RenderPresent(renderer);
//     SDL_DestroyTexture(texture); // Nettoyer les ressources SDL
//     SDL_FreeSurface(image);
// }

int main(int argc, char** argv)
{
    SDL_Window* window = NULL; // The window we'll be rendering to
    SDL_Surface* screenSurface = NULL; // The surface contained by the window
    SDL_Renderer* renderer = NULL;

    if(SDL_Init(SDL_INIT_VIDEO ) < 0) { // Initialize SDL
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Point", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0); // Create window

    renderer = SDL_CreateRenderer(window, -1, 0); // Create renderer
    if (renderer == NULL) {
        printf("SDL could not create renderer! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // color 
        SDL_SetRenderDrawColor(renderer, 11, 17, 35, 1);
        SDL_RenderClear(renderer);

    // Police de texte
        TTF_Font* Sans = TTF_OpenFont("Element/Humnst777_BlkCn_BT.ttf", 24);
        if (Sans == NULL) {
            printf("Could not open font, error: %s\n", SDL_GetError());
            return 1;
        }

    // utilisation de la fonction de read_file.c
        int Spin;
        int S;
        int MS;

        read_file("donne/Spin.save", &Spin);
        read_file("donne/S.save", &S);
        read_file("donne/MS.save", &MS);
        printf("Spin : %d, S : %d, MS : %d\n", Spin, S, MS);

    //Jeux
        SDL_Event event;
        while (1) {
            if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
                break;

                // Afficher l'image dans la fenêtre
                // // afficher_image(renderer, "Element/Jackpot.bmp");

            SDL_RenderPresent(renderer);
            sleep_end_of_frame();
        }

    SDL_DestroyRenderer(renderer); // Destroy renderer
    SDL_DestroyWindow(window); // Destroy window
    SDL_Quit(); // Quit SDL subsystems

    return 0;
}