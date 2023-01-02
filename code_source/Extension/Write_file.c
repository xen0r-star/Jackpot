#include <stdio.h>

    int write_file(const char* file_name, int value) {
        FILE* file = fopen(file_name, "w"); // Ouverture du fichier en écriture
        if (file == NULL) { // Vérification ouverture fichier
            return 1;
        }
        fprintf(file, "%d\n", value); // Écriture fichier
        fclose(file); // fermeture fichier
        return 0;
    }