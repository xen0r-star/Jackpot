// #include <stdio.h>
// #include <stdlib.h>

// int main() {

//     int Spin;
//     int S;
//     int MS;

// // // utilisation de la fonction write_file
// //     write_file("donne/Spin.save", Spin);
// //     write_file("donne/S.save", S);
// //     write_file("donne/MS.save", MS);

// // utilisation de la fonction read_file
//     read_file("donne/Spin.save", &Spin);
//     read_file("donne/S.save", &S);
//     read_file("donne/MS.save", &MS);
//     printf("Spin : %d, S : %d, MS : %d\n", Spin, S, MS);

//     return 0;
// }





#include <stdio.h>
#include <stdlib.h>

int read_file(const char *file_name, int *value)
{
    FILE *file = fopen(file_name, "r"); // Ouverture du fichier en lecture
    if (file == NULL)
    { // Vérification de l'ouverture du fichier
        return 1;
    }
    int nb_read = fscanf(file, "%d", value); // Lecture fichier
    if (feof(file))
    {                 // Vérification fin du fichier
        fclose(file); // Fermeture fichier
        return 0;
    }
    else
    {
        fclose(file); // Fermeture fichier
        return 1;
    }
}

int main(int argc, char **argv)
{
    printf("Hello world");
    return 0;
}