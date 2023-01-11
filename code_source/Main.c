#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <stdbool.h>

// SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

// Fonction
#include "Extension/File.h"
#include "Extension/Draw.h"
#include "Extension/Text.h"
// #include "Extension/Picture.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 600;




void Color(int couleurDuTexte,int couleurDeFond);



void Color(int Couleur_texte,int Couleur_fond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,Couleur_fond*16+Couleur_texte);

        /* _______ COULEUR _______
            0 : Noir
            1 : Bleu foncé
            2 : Vert foncé
            3 : Turquoise
            4 : Rouge foncé
            5 : Violet
            6 : Vert caca d'oie
            7 : Gris clair
            8 : Gris foncé
            9 : Bleu fluo
            10 : Vert fluo
            11 : Turquoise
            12 : Rouge fluo
            13 : Violet 2
            14 : Jaune
            15 : Blanc
        */
}

















// Frame
void sleep_end_of_frame() {
    struct timespec sleep;
    sleep.tv_sec = 0;
    sleep.tv_nsec = 16 * 1000 * 1000;
    nanosleep(&sleep, NULL);
}

int main(int argc, char **argv) {
    SDL_Window *window = NULL;         // The window we'll be rendering to
    SDL_Surface *screenSurface = NULL; // The surface contained by the window
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) { // Initialize SDL
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Jackpot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0); // Create window

    renderer = SDL_CreateRenderer(window, -1, 0); // Create renderer
    if (renderer == NULL) {
        printf("SDL could not create renderer! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Alea
    srand(time(NULL)); // initialise alea
    int number_1, number_2, number_3;


    // Icon fenetre
    SDL_Surface *icon = IMG_Load("code_source\\Element\\Logo_2.png");
    if (icon == NULL)
        printf("Erreur lors du chargement de l icone : %s\n", SDL_GetError());
    SDL_SetWindowIcon(window, icon); // Définition de l'icône de la fenêtre

    // color
    SDL_SetRenderDrawColor(renderer, 11, 17, 35, 1);
    SDL_RenderClear(renderer);

    // Police de texte
    if (TTF_Init() == -1)
        printf("Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
    TTF_Font *Sans = TTF_OpenFont("code_source\\Element\\Humnst777_BlkCn_BT.ttf", 500);
    if (Sans == NULL)
        printf("Could not open font, error: %s\n", SDL_GetError());
    TTF_SetFontHinting(Sans, TTF_HINTING_NORMAL); // Activation de l'anti-aliasing
    SDL_Color White = {52, 58, 78}; // Couleur de la police

    // Image
    Draw_picture(renderer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, "code_source\\Element\\Jackpot.bmp");

    // Bouton
    Draw_picture(renderer, 475, 392, 123, 123, "code_source\\Element\\Bouton.bmp");
    SDL_Rect button_collision_rect; // Définition de la zone de collision du bouton
    button_collision_rect.x = 475;
    button_collision_rect.y = 392;
    button_collision_rect.w = 123;
    button_collision_rect.h = 123;

    // Fonction read_file
    int Spin, S, MS;

    bool Erreur_read_file_bool = Read_file("donne/S.save", &S);
    Erreur_read_file_bool = Read_file("donne/MS.save", &MS);
    Erreur_read_file_bool = Read_file("donne/Spin.save", &Spin);
    char *Erreur_read_file_char = Erreur_read_file_bool == true ? "Correcte" : "Mauvais";
    printf("Spin : %d, S : %d, MS : %d\n", Spin, S, MS);

    Text_Spin(renderer, Spin, Sans, White);
    Text_S(renderer, S, Sans, White);
    Text_MS(renderer, MS, Sans, White);

    // Dessin
    char *Emplacement = argv[0];
    // char *Picture(char *Emplacement);
    
    Color(14,0);

    printf("\n                        BB                             ");
    Color(12,0);
    printf("          _      _       ____   _  __  ____     ___    _____    \n");   
    Color(14,0);
    printf("                      BGPPGB                           ");
    Color(12,0);
    printf("         | |    / \\     / ___| | |/ / |  _ \\   / _ \\  |_   _|   \n");
    Color(14,0);
    printf("                     BPPPPPPB                          ");
    Color(12,0);
    printf("      _  | |   / _ \\   | |     | ' /  | |_) | | | | |   | |     \n");
    Color(14,0);
    printf("                   BGPPPPPPPPGB                        ");
    Color(12,0);
    printf("     | |_| |  / ___ \\  | |___  | . \\  |  __/  | |_| |   | |     \n");
    Color(14,0);
    printf("                  BPPPPPPPPPPPPB                       ");
    Color(12,0);
    printf("      \\___/  /_/   \\_\\  \\____| |_|\\_\\ |_|      \\___/    |_|     \n");
    Color(14,0);
    printf("                 BPPPPPPPPPPPPPPB                      \n");
    printf("           GGBBBGPPPPPPPPPPPPPPPPGBBBGG                \n");
    printf("    GGBBBGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGBBBGG         \n");
    printf("  GPPPPPPPPPPY   JJ      PPJJJJJP PYPPPPPPPPPPPG       \n");
    printf("  BBPPPPPPPPPY                     JPPPPPPPPPPBB       ");
    Color(8,0);
    printf("           Version :          ");
    Color(7,0);
    printf("V 2.5.3\n");
    Color(14,0);
    printf("    BGPPPPPPPY                   PJPPPPPPPPPGB         \n");
    printf("      BPPPPPPY   PJYYYYYJJJJP   JPPPPPPPPPPB           ");
    Color(8,0);
    printf("           Emplacement :      ");
    Color(7,0);
    printf("%s\n", Emplacement);
    Color(14,0);
    printf("       BBPPPPPYYYPPPPPPPPJP    JPPPPPPPPPBB            \n");
    printf("         BGPPPPPPPPPPYJP      PPPPPPPPPGB              ");

    Color(8,0);
    printf("           Donnee :           ");
    if (Erreur_read_file_bool == true) {
        Color(2,0);
    }
    else {
        Color(4,0);
    }
    printf("%s\n", Erreur_read_file_char);

    Color(14,0);
    printf("          BPPPPPPPJJ          JPPPPPPPPB               \n");
    printf("          BPPPPPPPP          JPPPPPPPPPB               ");
    Color(8,0);
    printf("           ---------------- : \n");
    Color(14,0);
    printf("          BPPPPPPP          PJPPPPPPPPPB               \n");
    printf("          BPPPPPPPPPPPPPPPPPPPPPPPPPPPPB               ");
    Color(8,0);
    printf("           ---------------- : \n");
    Color(14,0);
    printf("          BPPPPPBPPPPPXEN0RPPPPPPPPPPPPP               \n");
    printf("          BPPPPPPPPPGGBBGGBBGGPPPPPPPPPB               ");
    Color(8,0);
    printf("           ---------------- : \n");
    Color(14,0);
    printf("          BPPPPGBBGG          GGBBGPPPPB               \n");
    printf("          BBBB                      BBBB               \n");
    printf("                                                       \n");
    printf("                                                       \n");

    Color(15,0);
    

    // Fonction write_file
    // Write_file("donne/Spin.save", Spin);
    // Write_file("donne/S.save", S);
    // Write_file("donne/MS.save", MS);
 
    // Jeux
    SDL_Event event;
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;

            // Sourie
            int mouse_x = event.motion.x;
            int mouse_y = event.motion.y;
            if (SDL_PointInRect(&(SDL_Point){mouse_x, mouse_y}, &button_collision_rect) && (event.button.button == SDL_BUTTON_LEFT || event.button.button == SDL_BUTTON_RIGHT)) { // Vérifier si la souris se trouve dans le rectangle de collision du bouton
                printf("Clic de la souris dans la zone en (%d, %d)\n", event.button.x, event.button.y); // Bouton gauche

                Draw_picture(renderer, 475, 392, 123, 123, "code_source\\Element\\Bouton_2.bmp");

                number_1 = (rand() % 13) + 1;
                number_2 = (rand() % 13) + 1;
                number_3 = (rand() % 13) + 1;
                printf("number 1 : %d, number 2 : %d, number 3 : %d", number_1, number_2, number_3);

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