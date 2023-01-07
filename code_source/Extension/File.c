#include <stdio.h>

int Read_file(const char* file_name, int* value) {
    
    FILE* file = fopen(file_name, "r"); // Ouverture du fichier en lecture
    if (file == NULL) { // Vérification de l'ouverture du fichier
        return 1;
    }
    int nb_read = fscanf(file, "%d", value); // Lecture fichier
    if (feof(file)) { // Vérification fin du fichier
        fclose(file); // Fermeture fichier
        return 0;
    } else {
        fclose(file); // Fermeture fichier
        return 1;
    }
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