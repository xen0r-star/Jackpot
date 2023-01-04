#include <stdio.h>
#include <time.h>
#include <windows.h>

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


int main(int argc, char** argv)
{
    SDL_Window* window = NULL; // The window we'll be rendering to
    SDL_Surface* screenSurface = NULL; // The surface contained by the window
    SDL_Renderer* renderer = NULL;

    if(SDL_Init(SDL_INIT_VIDEO ) < 0) { // Initialize SDL
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Jackpot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0); // Create window

    renderer = SDL_CreateRenderer(window, -1, 0); // Create renderer
    if (renderer == NULL) {
        printf("SDL could not create renderer! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // // Bordure
    //     HWND hwnd = GetActiveWindow();
    //     COLORREF color = RGB(255, 0, 0); // Rouge
    //     SetSysColors(1, &COLOR_WINDOWFRAME, &color);

    // Icon fenetre
        SDL_Surface* icon = IMG_Load("code_source\\Element\\Logo_2.bmp");
        if (icon == NULL) {
            printf("Erreur lors du chargement de l icone : %s\n", SDL_GetError());
        }
        SDL_FreeSurface(icon);
        SDL_SetWindowIcon(window, icon); // Définition de l'icône de la fenêtre

    // color 
        SDL_SetRenderDrawColor(renderer, 11, 17, 35, 1);
        SDL_RenderClear(renderer);

    // Police de texte
        if (TTF_Init() == -1) {
        printf("Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
        }
        TTF_Font* Sans = TTF_OpenFont("code_source\\Element\\Humnst777_BlkCn_BT.ttf", 24);
        if (Sans == NULL) {
            printf("Could not open font, error: %s\n", SDL_GetError());
        }

    // Image
        SDL_Surface* image = SDL_LoadBMP("code_source\\Element\\Jackpot.bmp"); // Charger l'image à afficher
        if(image == NULL) {
            printf("Erreur de chargement de l image : %s\n",SDL_GetError());
        }
            
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image); // Création de la texture à partir de l'image
        SDL_FreeSurface(image);

        SDL_Rect texture_rect; // Définition des dimensions de la texture
        texture_rect.x = 0;
        texture_rect.y = 0;
        texture_rect.w = WINDOW_WIDTH;
        texture_rect.h = WINDOW_WIDTH;
        SDL_RenderCopy(renderer, texture, NULL, NULL);
    

    //Jeux
        SDL_Event event;
        while (1) {
            if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
                break;

                SDL_RenderClear(renderer);

                // Afficher l'image dans la fenêtre
                // // afficher_image(renderer, "Element/Jackpot.bmp");

            SDL_RenderPresent(renderer);
            sleep_end_of_frame();
        }

    SDL_DestroyRenderer(renderer); // Destroy renderer
    SDL_DestroyWindow(window); // Destroy window
    SDL_Quit(); // Quit SDL subsystems
    // SDL_DestroyTexture(icon_texture); // Destroy icon

    return 0;
}