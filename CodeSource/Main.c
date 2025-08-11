#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <pthread.h>

// SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

// Fonction Extension
#include "Extension/Draw.h"
#include "Extension/Terminal.h"
#include "Extension/File.h"

#include "Extension/Text.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 600;


// Frame
void Frame() {
    struct timespec time;
    time.tv_sec = 0;
    time.tv_nsec = 16 * 1000 * 1000;
    nanosleep(&time, NULL);
}

int main(int argc, char **argv) {
    SDL_Window *window = NULL;         // Fenêtre de rendue
    SDL_Surface *screenSurface = NULL; // La surface de la Fenêtre 
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) { // Initialiser SDL
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Jackpot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0); // Create window

    renderer = SDL_CreateRenderer(window, -1, 0); // Création du moteur de rendu
    if (renderer == NULL) {
        printf("SDL could not create renderer! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Alea
    srand(time(NULL)); // initialise alea
    int random_1, random_2, random_3;

    // Icon fenetre
    SDL_Surface *icon = IMG_Load("CodeSource\\Element\\Logo_2.png");
    if (icon == NULL)
        printf("Erreur lors du chargement de l icone : %s\n", SDL_GetError());
    SDL_SetWindowIcon(window, icon); // Définition de l'icône de la fenêtre

    // Color
    SDL_SetRenderDrawColor(renderer, 11, 17, 35, 1);
    SDL_RenderClear(renderer);

    // Police de texte
    if (TTF_Init() == -1)
        printf("Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
    TTF_Font *Sans = TTF_OpenFont("CodeSource\\Element\\Humnst777_BlkCn_BT.ttf", 500); // Police du texte
    if (Sans == NULL)
        printf("Could not open font, error: %s\n", SDL_GetError());
    TTF_SetFontHinting(Sans, TTF_HINTING_NORMAL); // Activation de l'anti-aliasing
    SDL_Color White = {52, 58, 78}; // Couleur de la police

    // Image
    Draw_picture(renderer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, "CodeSource\\Element\\Jackpot.bmp");

    // Bouton
    Draw_picture(renderer, 475, 392, 123, 123, "CodeSource\\Element\\Bouton.bmp");
    SDL_Rect button_collision_rect; // Définition de la zone de collision du bouton
    button_collision_rect.x = 475;
    button_collision_rect.y = 392;
    button_collision_rect.w = 123;
    button_collision_rect.h = 123;

    // Fonction read_file
    int Spin, S, MS;

    S = Read_file_int("Score", "S");
    MS = Read_file_int("Score", "MS");
    Spin = Read_file_int("Score", "Spin");

    // Text_Spin(renderer, Spin, Sans, White);
    // Text_S(renderer, S, Sans, White);
    // Text_MS(renderer, MS, Sans, White);


    // Fonction write_file
    // Write_file("Donne/Spin.save", Spin);
    // Write_file("Donne/S.save", S);
    // Write_file("Donne/MS.save", MS);
 
    // Dessin
    pthread_t Thread_terminal;

    pthread_create(&Thread_terminal, NULL, Terminal, NULL);
    
    pthread_detach(Thread_terminal); // Détachement thread pour s'exécuter en parallèle du programme principale

    // Jeux
    SDL_Event event;
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;

            // Sourie
            int mouse_x = event.motion.x;
            int mouse_y = event.motion.y;
            // if (SDL_PointInRect(&(SDL_Point){mouse_x, mouse_y}, &button_collision_rect) && (event.button.button == SDL_BUTTON_LEFT || event.button.button == SDL_BUTTON_RIGHT)) { // Vérifier si la souris se trouve dans le rectangle de collision du bouton
            //     printf("Clic de la souris dans la zone en (%d, %d)\n", event.button.x, event.button.y); // Bouton gauche

            //     Draw_picture(renderer, 475, 392, 123, 123, "CodeSource\\Element\\Bouton_2.bmp");

            //     random_1 = (rand() % 13) + 1;
            //     random_2 = (rand() % 13) + 1;
            //     random_3 = (rand() % 13) + 1;
            //     printf("number 1 : %d, number 2 : %d, number 3 : %d", random_1, random_2, random_3);

            //     Draw_picture(renderer, 475, 392, 123, 123, "CodeSource\\Element\\Bouton.bmp");
            // }

        SDL_RenderPresent(renderer);
        Frame();
    }

    SDL_DestroyRenderer(renderer); // Détruire rendu
    SDL_DestroyWindow(window);     // Détruire Fenêtre
    SDL_Quit();                    // Quitter SDL

    return 0;
}