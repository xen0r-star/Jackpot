#include <stdio.h>
#include <windows.h>

void Color(int couleurDuTexte,int couleurDeFond);

char *Picture(char *Emplacement) { 

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
    printf("    GGBBBGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGBBBGG         ");
    Color(7,0);
    printf("           Name :             \n");
    Color(14,0);
    printf("  GPPPPPPPPPPY   JJ      PPJJJJJP PYPPPPPPPPPPPG       \n");
    printf("  BBPPPPPPPPPY                     JPPPPPPPPPPBB       ");
    Color(7,0);
    printf("           Version :          \n");
    Color(14,0);
    printf("    BGPPPPPPPY                   PJPPPPPPPPPGB         \n");
    printf("      BPPPPPPY   PJYYYYYJJJJP   JPPPPPPPPPPB           ");
    Color(7,0);
    printf("           Emplacement :      \n");
    printf("%s", Emplacement);
    Color(14,0);
    printf("       BBPPPPPYYYPPPPPPPPJP    JPPPPPPPPPBB            \n");
    printf("         BGPPPPPPPPPPYJP      PPPPPPPPPGB              ");
    Color(7,0);
    printf("           ---------------- : \n");
    Color(14,0);
    printf("          BPPPPPPPJJ          JPPPPPPPPB               \n");
    printf("          BPPPPPPPP          JPPPPPPPPPB               ");
    Color(7,0);
    printf("           ---------------- : \n");
    Color(14,0);
    printf("          BPPPPPPP          PJPPPPPPPPPB               \n");
    printf("          BPPPPPPPPPPPPPPPPPPPPPPPPPPPPB               ");
    Color(7,0);
    printf("           ---------------- : \n");
    Color(14,0);
    printf("          BPPPPPBPPPPPXEN0RPPPPPPPPPPPPP               \n");
    printf("          BPPPPPPPPPGGBBGGBBGGPPPPPPPPPB               ");
    Color(7,0);
    printf("           ---------------- : \n");
    Color(14,0);
    printf("          BPPPPGBBGG          GGBBGPPPPB               \n");
    printf("          BBBB                      BBBB               \n");
    printf("                                                       \n");
    printf("                                                       \n");

    Color(15,0);
}



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