#include <stdio.h>
#include <stdlib.h>

int main() {

// Spin
    char* buffer_Spin; // Déclaration de la variable pour stocker le contenu du fichier
    FILE* file_Spin = fopen("donne/Spin.save", "r"); // Ouverture du fichier en mode lecture
    if (file_Spin == NULL) { // Vérification de l'ouverture du fichier
        perror("Erreur ouverture fichier");
        return 1;
    }
    fseek(file_Spin, 0, SEEK_END); // Détermination de la taille du fichier
    long file_Spin_size = ftell(file_Spin);
    rewind(file_Spin);
    buffer_Spin = (char*)malloc((file_Spin_size + 1) * sizeof(char)); // Allocation de la mémoire pour le buffer_Spin
    if (buffer_Spin == NULL) { // Vérification de l'allocation de mémoire
        perror("Erreur mémoire");
        fclose(file_Spin);
        return 1;
    }
    size_t result_Spin = fread(buffer_Spin, 1, file_Spin_size, file_Spin); // Lecture du fichier dans le buffer_Spin
    if (result_Spin != file_Spin_size) { // Vérification de la lecture réussie
        perror("Erreur lecture fichier");
        fclose(file_Spin);
        free(buffer_Spin);
        return 1;
    }
    buffer_Spin[file_Spin_size] = '\0'; // Ajout d'un caractère de fin de chaîne à la fin du buffer_Spin
    fclose(file_Spin); // Fermeture du fichier
    int Spin = atoi(buffer_Spin);
    free(buffer_Spin); // Libération de la mémoire allouée pour le buffer_Spin

// MS
    char* buffer_MS;
    FILE* file_MS = fopen("donne/MS.save", "r");
    if (file_MS == NULL) {
        perror("Erreur ouverture fichier");
        return 1;
    }
    fseek(file_MS, 0, SEEK_END);
    long file_MS_size = ftell(file_MS);
    rewind(file_MS);
    buffer_MS = (char*)malloc((file_MS_size + 1) * sizeof(char));
    if (buffer_MS == NULL) {
        perror("Erreur memoire");
        fclose(file_MS);
        return 1;
    }
    size_t result_MS = fread(buffer_MS, 1, file_MS_size, file_MS);
    if (result_MS != file_MS_size) {
        perror("Erreur lecture fichier");
        fclose(file_MS);
        free(buffer_MS);
        return 1;
    }
    buffer_MS[file_MS_size] = '\0';
    fclose(file_MS);
    int MS = atoi(buffer_MS);
    free(buffer_MS);

// S
    char* buffer_S;
    FILE* file_s = fopen("donne/S.save", "r");
    if (file_s == NULL) {
        perror("Erreur ouverture fichier");
        return 1;
    }
    fseek(file_s, 0, SEEK_END);
    long file_s_size = ftell(file_s);
    rewind(file_s);
    buffer_S = (char*)malloc((file_s_size + 1) * sizeof(char));
    if (buffer_S == NULL) {
        perror("Erreur mémoire");
        fclose(file_s);
        return 1;
    }
    size_t result_S = fread(buffer_S, 1, file_s_size, file_s);
    if (result_S != file_s_size) {
        perror("Erreur lecture fichier");
        fclose(file_s);
        free(buffer_S);
        return 1;
    }
    buffer_S[file_s_size] = '\0';
    fclose(file_s);
    int S = atoi(buffer_S);
    free(buffer_S);

    printf("Spin : %d, MS : %d, S : %d",Spin,MS,S);

    return 0;
}