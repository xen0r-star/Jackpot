#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <unistd.h>
#include <windows.h>
#include <pthread.h>


void Color(int Couleur_texte,int Couleur_fond) { // fonction d'affichage de couleurs
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

char *Read_save(char *Fichier) { // Lecture de fichier 
    char *data;
    long size;
    FILE *File = fopen(Fichier, "rb");
    if (File == NULL) { // Vérifier si le fichier a pu être ouvert
        printf("Impossible d'ouvrir le fichier !\n");
    }
    fseek(File, 0, SEEK_END); // Obtenir la taille du fichier
    size = ftell(File);
    rewind(File);
    data = (char *) malloc(sizeof(char) * (size + 1)); // Allouer de la mémoire pour le donne  
    fread(data, 1, size, File); // Lire le contenu du fichier dans le donne
    data[size] = '\0'; // Ajouter un caractère de fin de chaîne
    printf("%s\n", data); // Afficher le contenu du fichier
    free(data); // Libérer la mémoire allouée pour le donne
    fclose(File); // Fermer le fichier
    return data;
}


void *Terminal() {
    bool SDL = true;
    bool Donne = true;
    bool Extension = true;
    start:

    Color(6,0); printf("\n                        BB                             ");
    Color(4,0); printf("          _      _       ____   _  __  ____     ___    _____    \n");   
    Color(6,0); printf("                      BGPPGB                           ");
    Color(4,0); printf("         | |    / \\     / ___| | |/ / |  _ \\   / _ \\  |_   _|   \n");
    Color(6,0); printf("                     BPPPPPPB                          ");
    Color(4,0); printf("      _  | |   / _ \\   | |     | ' /  | |_) | | | | |   | |     \n");
    Color(6,0); printf("                   BGPPPPPPPPGB                        ");
    Color(4,0); printf("     | |_| |  / ___ \\  | |___  | . \\  |  __/  | |_| |   | |     \n");
    Color(6,0); printf("                  BPPPPPPPPPPPPB                       ");
    Color(4,0); printf("      \\___/  /_/   \\_\\  \\____| |_|\\_\\ |_|      \\___/    |_|     \n");
    Color(6,0); printf("                 BPPPPPPPPPPPPPPB                      \n           GGBBBGPPPPPPPPPPPPPPPPGBBBGG                \n    GGBBBGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGBBBGG         \n  GPPPPPPPPPPY   JJ      PPJJJJJP PYPPPPPPPPPPPG       ");

        Color(8,0); printf("           Nom : ");
        Color(3,0); Read_save("Donne/Name.save");

    Color(6,0); printf("  BBPPPPPPPPPY                     JPPPPPPPPPPBB       \n    BGPPPPPPPY                   PJPPPPPPPPPGB         ");

        Color(8,0); printf("           Niveau : ");
        Color(7,0);

        // char *Niveau = Read_save("Donne/Level.save");
        char *Barre="#####....................";
        // Color(6,0);
        // printf("%s", Niveau);

        Color(7,0);
        printf(" [");
        Color(1,0);
        printf("%s", Barre);
        Color(7,0);
        printf("]");

    Color(6,0); printf("\n      BPPPPPPY   PJYYYYYJJJJP   JPPPPPPPPPPB           \n       BBPPPPPYYYPPPPPPPPJP    JPPPPPPPPPBB            ");

        Color(8,0); printf("           Version : ");
        Color(7,0); printf("V "); Read_save("Donne/Version.save");

    Color(6,0); printf("         BGPPPPPPPPPPYJP      PPPPPPPPPGB              \n          BPPPPPPPJJ          JPPPPPPPPB               ");

        Color(8,0); printf("           SDL : ");
        Color(7,0);
        
        if (SDL == true) {
            Color(2,0); printf("Trouvable\n");
        } else {
            Color(4,0); printf("Introuvable\n");
        }

    Color(6,0); printf("          BPPPPPPPP          JPPPPPPPPPB               \n          BPPPPPPP          PJPPPPPPPPPB               ");

        Color(8,0); printf("           Donne : ");
        Color(7,0);
        
        if (Donne == true) {
            Color(2,0); printf("Trouvable\n");
        } else {
            Color(4,0); printf("Introuvable\n");
        }

    Color(6,0); printf("          BPPPPPPPPPPPPPPPPPPPPPPPPPPPPB               \n          BPPPPPBPPPPPXEN0RPPPPPPPPPPPPP               ");

        Color(8,0); printf("           Extension : ");
        Color(7,0);
        
        if (Extension == true) {
            Color(2,0); printf("Trouvable\n");
        } else {
            Color(4,0); printf("Introuvable\n");
        }

    Color(6,0); printf("          BPPPPPPPPPGGBBGGBBGGPPPPPPPPPB               \n          BPPPPGBBGG          GGBBGPPPPB               ");

        Color(8,0); printf("           Jackpot by ");
        Color(4,0); printf("UwU\n");

    Color(6,0); printf("          BBBB                      BBBB               \n\n\n");
    Color(15,0);

    // Commande
        char *Commande[] = {
            "Help",/* Help - 1 */
            "Message -on -terminal", "Message -on -log", "Message -on -all", "Message -off",/* Message - 2 / 5 */
            "Location -jackpot", "Location -sdl", "Location -donne", "Location -extension", "Location -all",/* Location - 6 / 10 */
            "Name -set", "Name -view",/* Name - 11 / 12 */
            "Level -view", "Level -stat",/* Level - 13 / 14 */
            "Update",/* Update - 15 */ 
            "Language -french", "Language -english",/* Language - 16 / 17 */
            "Clear -log", "Clear -terminal",/* Clear - 18 / 19  */
            "Exit",/* Exit - 20*/
            "Reset"/* Reset - 21 */
       };

    int Loop_Commande = 0;
    char Input_Commande[250];
    while (Loop_Commande < 1) {
    int resulta = 0;
        printf("Jackpot\\Commande> ");
        scanf(" %[^\n]", Input_Commande);

        for(int i = 0; i < sizeof(Commande)/sizeof(*Commande); i++) {
            if(strcmp(Commande[i], Input_Commande) == 0) {
                switch(i+1) {
                case 1:
                    printf("\n     ___________________________________________________________________________\n    |                                                                           |\n    |                                ");
                    Color(6,0);  printf("COMMANDE");
                    Color(15,0); printf("                                   |\n    |___________________________________________________________________________|\n    |                                                                           |\n    |     ");
                    Color(5,0);  printf("Help");
                    Color(8,0);  printf(" : Liste toute les commandes disponibles");
                    Color(15,0); printf("                          |\n    |                                                                           |\n    |     ");
                    Color(5,0);  printf("Message");
                    Color(15,0); printf("                                                               |\n    |        |- ");
                    Color(13,0); printf("on");
                    Color(8,0);  printf(" : Activer les messages developer");
                    Color(15,0); printf("                             |\n    |        | |- ");
                    Color(13,0); printf("terminal");
                    Color(8,0);  printf(" : Message dans le terminal");
                    Color(15,0); printf("                           |\n    |        | |- ");
                    Color(13,0); printf("log");
                    Color(8,0);  printf(" : Message dans les log");
                    Color(15,0); printf("                                    |\n    |        | |- ");
                    Color(13,0); printf("all");
                    Color(8,0);  printf(" : Tout les messages");
                    Color(15,0); printf("                                       |\n    |        |                                                                  |\n    |        |- ");
                    Color(13,0); printf("off");
                    Color(8,0);  printf(" : Desactiver les messages developer");
                    Color(15,0); printf("                         |\n    |                                                                           |\n    |     ");
                    Color(5,0);  printf("Location");
                    Color(15,0); printf("                                                              |\n    |        |- ");
                    Color(13,0); printf("jackpot");
                    Color(8,0);  printf(" : Chemin d'acces vers le jeux");
                    Color(15,0); printf("                           |\n    |        |- ");
                    Color(13,0); printf("sdl");
                    Color(8,0);  printf(" : Chemin d'acces vers les fichiers SDL");
                    Color(15,0); printf("                      |\n    |        |- ");
                    Color(13,0); printf("donne");
                    Color(8,0);  printf(" : Chemin d'acces vers les donnees du jeux");
                    Color(15,0); printf("                 |\n    |        |- ");
                    Color(13,0); printf("extension");
                    Color(8,0);  printf(" : Chemin d'acces vers les extensions du code_source");
                    Color(15,0); printf("   |\n    |        |- ");
                    Color(13,0); printf("all");
                    Color(8,0);  printf(" : Tous les chemins d'acces");
                    Color(15,0); printf("                                  |\n    |                                                                           |\n    |     ");
                    Color(5,0);  printf("Name");
                    Color(15,0); printf("                                                                  |\n    |        |- ");
                    Color(13,0); printf("set");
                    Color(8,0);  printf(" : Modifier son nom");
                    Color(15,0); printf("                                          |\n    |        |- ");
                    Color(13,0); printf("view");
                    Color(8,0);  printf(" : Voir le nom enregistrer");
                    Color(15,0); printf("                                  |\n    |                                                                           |\n    |     ");
                    Color(5,0);  printf("Level");
                    Color(15,0); printf("                                                                 |\n    |        |- ");
                    Color(13,0); printf("view");
                    Color(8,0);  printf(" : Voir votre level actuelle");
                    Color(15,0); printf("                                |\n    |        |- ");
                    Color(13,0); printf("stat");
                    Color(8,0);  printf(" : ");
                    Color(15,0); printf("                                                         |\n    |                                                                           |\n    |     ");
                    Color(5,0);  printf("Update");
                    Color(8,0);  printf(" : Mettre a jour le terminal");
                    Color(15,0); printf("                                    |\n    |                                                                           |\n    |     ");
                    Color(5,0);  printf("Language");
                    Color(15,0); printf("                                                              |\n    |        |- ");
                    Color(13,0); printf("french");
                    Color(8,0);  printf(" : Mettre la langue du jeu en francais");
                    Color(15,0); printf("                    |\n    |        |- ");
                    Color(13,0); printf("english");
                    Color(8,0);  printf(" : Mettre la langue du jeu en anglais");
                    Color(15,0); printf("                    |\n    |                                                                           |\n    |     ");
                    Color(5,0);  printf("Clear");
                    Color(15,0); printf("                                                                 |\n    |        |- ");
                    Color(13,0); printf("log");
                    Color(8,0);  printf(" : Supprimer les logs des message developer");
                    Color(15,0); printf("                  |\n    |        |- ");
                    Color(13,0); printf("terminal");
                    Color(8,0);  printf(" : Supprimer les messages du terminal");
                    Color(15,0); printf("                   |\n    |                                                                           |\n    |     ");
                    Color(5,0);  printf("Reset");
                    Color(8,0);  printf(" : ! Reinitialiser le jeu a zero !");
                    Color(15,0); printf("                               |\n    |                                                                           |\n    |___________________________________________________________________________|\n\n");
                    break;
                case 2:
                    printf("La chaine est chaine2.\n");
                    break;
                case 3:
                    printf("La chaine est chaine3.\n");
                    break;
                case 4:
                    printf("La chaine est chaine4.\n");
                    break;
                case 5:
                    printf("La chaine est chaine5.\n");
                    break;
                case 6:
                    printf("La chaine est chaine6.\n");
                    break;
                case 7:
                    printf("La chaine est chaine7.\n");
                    break;
                case 8:
                    printf("La chaine est chaine8.\n");
                    break;
                case 9:
                    printf("La chaine est chaine9.\n");
                    break;
                case 10:
                    printf("La chaine est chaine10.\n");
                    break;
                case 11:
                    printf("La chaine est chaine11.\n");
                    break;
                case 12:
                    printf("Votre nom est ");
                    Color(3,0); Read_save("Donne/Name.save"); 
                    Color(15,0); 
                    break;
                case 13:
                    printf("La chaine est chaine13.\n");
                    break;
                case 14:
                    printf("La chaine est chaine14.\n");
                    break;
                case 15:
                    printf("Update ...\n");
                    system("cls");
                    goto start;
                    break;
                case 16:
                    printf("La chaine est chaine16.\n");
                    break;
                case 17:
                    printf("La chaine est chaine17.\n");
                    break;
                case 18:
                    printf("La chaine est chaine18.\n");
                    break;
                case 19:
                    printf("La chaine est chaine19.\n");
                    break;
                case 20:
                    printf("La chaine est chaine20.\n");
                    break;
                case 21:
                    printf("La chaine est chaine21.\n");
                    break;
                default:
                    printf("Aucune chaine correspondante trouvee.\n");
                    break;
                }
                i = (sizeof(Commande) / sizeof(*Commande)) + 1;
                resulta = 1;
            }
        }
        if (resulta == 0) {
            Color(12,0); printf("Aucune commande correspondante trouvee.\n");
            Color(15,0);
        }
    }

    pthread_exit(NULL);

    return 0;
}