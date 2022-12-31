#include <stdio.h>
#include <stdlib.h>

int reading_file(const char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Erreur ouverture du fichier %s", file_name);
        return 1;
    }
    unsigned char buffer[4];
    fread(buffer, 1, 4, file); // on lit 4 octets du fichier dans le tableau `buffer``
    union { // un int c'est 4 octets donc on dit qu'on va le mettre octet par octet (unsigned char = octet)
        unsigned char b[4];
        int i;
    } u;
    u.b[0] = buffer[0]; // Premier octet dans l'init
    u.b[1] = buffer[1]; // Deuxieme octet dans l'init
    u.b[2] = buffer[2]; // Troisieme octet dans l'init
    u.b[3] = buffer[3]; // Quatrieme octet dans l'init
    return u.i;
}

int write_file(const char* file_name, int value) {
    unsigned char *value_2 = (unsigned char *) &value;
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier !\n");
        return 1;
    }
    fprintf(file, "%c%c%c%c", value_2[0], value_2[1], value_2[2], value_2[3]);
    fclose(file);
}

int main() {
    int value_Spin;
    int value_MS;
    int value_S;
    
    int Spin = reading_file("donne/Spin.save");
    int MS = reading_file("donne/MS.save");
    int S = reading_file("donne/S.save");
    printf("Spin : %d, MS : %d, S : %d", Spin, MS, S);


    scanf("Valeur Spin : %d", &value_Spin);
    scanf("Valeur MS : %d", &value_MS);
    scanf("Valeur S : %d", &value_S);

    write_file("donne/Spin.save", value_Spin);
    write_file("donne/S.save", value_S);
    write_file("donne/MS.save", value_MS);

    return 0;
}