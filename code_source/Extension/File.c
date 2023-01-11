#include <stdio.h>
#include <stdbool.h>

int Read_file(const char* file_name, int* value) {

    bool Erreur_read_file;
    
    FILE* file = fopen(file_name, "r"); // Ouverture du fichier en lecture
    if (file == NULL) { // Vérification de l'ouverture du fichier
        Erreur_read_file = false;
        return Erreur_read_file;
    }
    int nb_read = fscanf(file, "%d", value); // Lecture fichier
    if (feof(file)) { // Vérification fin du fichier
        fclose(file); // Fermeture fichier
        Erreur_read_file = true;
        return Erreur_read_file;
    } else {
        fclose(file); // Fermeture fichier
        Erreur_read_file = true;
        return Erreur_read_file;
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