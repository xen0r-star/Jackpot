#include <stdio.h>
#include <stdbool.h>

#define File_name               "donne/Save.save"
#define Start                   "{"
#define End                     "}"
#define Section_int             "="
#define Section_char            ":"
#define Section_bool            "-"

#define Section_Score           "Score"
    #define Tag_Spin               "Spin"
    #define Tag_S                  "S"
    #define Tag_MS                 "MS"

#define Section_Level           "Level"
    #define Tag_Level              "Level"
    #define Tag_Xp                 "Xp"

#define Section_User            "User"
    #define Tag_Name               "Name"
    #define Tag_Language           "Language"

#define Section_Log             "Log"
    #define Tag_Version            "Version"
    #define Tag_MessageTerminal    "MessageTerminal"
    #define Tag_MessageLog         "MessageLog"



int Read_file(int* value) {
    
    FILE* file = fopen(File_name, "r"); // Ouverture du fichier en lecture
    if (file == NULL) { // Vérification de l'ouverture du fichier
        printf("Error open file");
    }

    char Tableau_line[512];
    int Number_line = 0;

    while(fgets(Tableau_line, 512, file) != NULL){
        nb_lignes++;
    }



    if (feof(file)) { // Vérification fin du fichier
        fclose(file); // Fermeture fichier
    } else {
        fclose(file); // Fermeture fichier
    }

    return content;
}



int Write_file(const char* file_name, int value) {

    FILE* file = fopen(file_name, "w"); // Ouverture du fichier en écriture
    if (file == NULL) { // Vérification ouverture fichier
        return 1;
    }
    fprintf(file, "%d\n", value); // Écriture fichier
    fclose(file); // fermeture fichier
    return 0;
}