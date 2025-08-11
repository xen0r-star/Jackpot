#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const char *File_name = "Save.save";
const char *Start = "{";
const char *End = "}";
const char *Section_int = "=";
const char *Section_char = ":";
const char *Section_bool = "-";


char *delete_space (char *value) {
    int a = 0, found_spaces = 0;
    while (value[a] != 0)
    {
        if (value[a] == ' ')
            found_spaces++;
        else
            value[a - found_spaces] = value[a];
        a++;
    }
    value[a - found_spaces] = 0;
    return value;
}

int main() {
    char Section[100] = "User";
    char Element[100] = "Name";
    char *Tag = "char"; // char | int | bool

    if (strcmp(Tag, "char") == 0) {
        Tag = Section_char;
    } else if (strcmp(Tag, "int") == 0) {
        Tag = Section_int;
    } else if (strcmp(Tag, "bool") == 0) {
        Tag = Section_bool;
    } else {
        printf("Error tag\n");
        // return 0;
    }
    
    char *Section_start = strcat(Section, Start);
    char *Element_tag = strcat(Element, Tag);
    int Size_element = strlen(Element_tag);
    
    FILE* file = fopen(File_name, "r"); // Ouverture fichier en lecture
    if (file == NULL) {
        printf("Error open file");
        // return 0 ;
    }

    char Tableau_section[50], Tableau_element[50];
    char *Name_element;
    int Line = 0, octets = 0, loop_stop = 0;

    while (fgets(Tableau_section, sizeof(Tableau_section), file) != NULL) {
        char *Name_section = strtok(Tableau_section, "\t\n");
        Name_section = delete_space(Name_section);
        Line = ftell(file);

        if (strcmp(Name_section, Section_start) == 0) {
            printf("Section found\n");
            break;
        }
    }

    if (fseek(file, 0, SEEK_END) == 0 && (octets = ftell(file)) == Line) {
        printf("No section\n");
        // return 0;
    }

    fseek(file, Line, SEEK_SET);
    while (loop_stop < 1) {
        if (fgets(Tableau_element, sizeof(Tableau_element), file) && strcmp(strtok(Tableau_element, "\t\n"), "}") != 0) {
            Line = ftell(file);
            Name_element = strtok(Tableau_element, "\t\n");
            Name_element = delete_space(Name_element);
            
            char *first_element = malloc(Size_element + 1); // allouer de la mémoire pour la nouvelle chaîne
            strncpy(first_element, Name_element, Size_element);
            first_element[Size_element] = '\0'; // ajouter le caractère nul de fin de chaîne

            if (strcmp(first_element, Element_tag) == 0) {
                printf("Element found\n");

                if (strcmp(Tag, ":") == 0) {
                    Name_element = Name_element + Size_element;
                    char *resulta = Name_element;
                } else if (strcmp(Tag, "=") == 0) {
                    Name_element = Name_element + Size_element;
                    int resulta = atoi(Name_element);
                } else if (strcmp(Tag, "-") == 0) {
                    Name_element = Name_element + Size_element;
                    bool resulta;
                    if (strcmp(Name_element, "true") == 0) {
                        resulta = true;
                    } else {
                        resulta = false;
                    }                   
                } else {
                    printf("Error tag\n");
                    // return 0;
                }

                loop_stop++;
            }
            free(first_element);
        }
        else {
            printf("No element\n");
            loop_stop++;
            // return 0;
        }
    }
    fclose(file); // fermeture ficher

    printf("le contenue est \"%s\"", Name_element);

    int temps;
    scanf("%d", &temps);

    return 0;
}











// int Write_file(const char* file_name, int value) {

//     FILE* file = fopen(file_name, "w"); // Ouverture du fichier en écriture
//     if (file == NULL) { // Vérification ouverture fichier
//         return 1;
//     }
//     fprintf(file, "%d\n", value); // Écriture fichier
//     fclose(file); // fermeture fichier
//     return 0;
// }