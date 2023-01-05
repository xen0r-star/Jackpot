#include <stdio.h>
#include <time.h>
#include <windows.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Extension/Read_file.h"
// #include "Extension/Write_file.h"
// #include "Extension/Draw_picture.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 600;

// Frame
void sleep_end_of_frame()
{
    struct timespec sleep;
    sleep.tv_sec = 0;
    sleep.tv_nsec = 16 * 1000 * 1000;
    nanosleep(&sleep, NULL);
}

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

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;         // The window we'll be rendering to
    SDL_Surface *screenSurface = NULL; // The surface contained by the window
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    { // Initialize SDL
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Jackpot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0); // Create window

    renderer = SDL_CreateRenderer(window, -1, 0); // Create renderer
    if (renderer == NULL)
    {
        printf("SDL could not create renderer! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Icon fenetre
    SDL_Surface *icon = IMG_Load("code_source\\Element\\Logo_2.png");
    if (icon == NULL)
    {
        printf("Erreur lors du chargement de l icone : %s\n", SDL_GetError());
    }
    SDL_SetWindowIcon(window, icon); // Définition de l'icône de la fenêtre

    // color
    SDL_SetRenderDrawColor(renderer, 11, 17, 35, 1);
    SDL_RenderClear(renderer);

    // Police de texte
    if (TTF_Init() == -1)
        printf("Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
    TTF_Font *Sans = TTF_OpenFont("code_source\\Element\\Humnst777_BlkCn_BT.ttf", 24);
    if (Sans == NULL)
        printf("Could not open font, error: %s\n", SDL_GetError());

    // Image
    Draw_picture(renderer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, "code_source\\Element\\Jackpot.bmp");

    // Bouton
    // Draw_picture(renderer, 475, 392, 123, 123, "code_source\\Element\\Bouton.bmp");
    SDL_Rect button_collision_rect; // Définition de la zone de collision du bouton
    button_collision_rect.x = 475;
    button_collision_rect.y = 392;
    button_collision_rect.w = 123;
    button_collision_rect.h = 123;

    // Jeux
    SDL_Event event;
    while (1)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;

            // Sourie
            int mouse_x = event.motion.x;
            int mouse_y = event.motion.y;
            if (SDL_PointInRect(&(SDL_Point){mouse_x, mouse_y}, &button_collision_rect) && (event.button.button == SDL_BUTTON_LEFT || event.button.button == SDL_BUTTON_RIGHT)) { // Vérifier si la souris se trouve dans le rectangle de collision du bouton
                printf("Clic de la souris dans la zone en (%d, %d)\n", event.button.x, event.button.y); // Bouton gauche
                Draw_picture(renderer, 475, 392, 123, 123, "code_source\\Element\\Bouton_2.bmp");
                int temps = 0;
                while (temps < 100000) {
                    temps++;
                    printf ("%d\n", temps);
                }
                Draw_picture(renderer, 475, 392, 123, 123, "code_source\\Element\\Bouton.bmp");
            }

        SDL_RenderPresent(renderer);
        sleep_end_of_frame();
    }

    SDL_DestroyRenderer(renderer); // Destroy renderer
    SDL_DestroyWindow(window);     // Destroy window
    SDL_Quit();                    // Quit SDL subsystems
    // SDL_DestroyTexture(icon_texture); // Destroy icon

    return 0;
}