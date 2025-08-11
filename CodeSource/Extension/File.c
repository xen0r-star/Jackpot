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

char *delete_space(char *value) {
    int a = 0, found_spaces = 0;
    while (value[a] != 0) {
        if (value[a] == ' ')
            found_spaces++;
        else
            value[a - found_spaces] = value[a];
        a++;
    }
    value[a - found_spaces] = 0;
    return value;
}



int Read_file_int(char Section[0], char Element[0]) {
    // Section > Element > Tag > Valeur
    // Tag -> int

    char *Section_start = strcat(Section, Start);
    char *Element_tag = strcat(Element, Section_int);
    int Size_element = strlen(Element_tag);

    FILE *file = fopen(File_name, "r"); // Ouverture fichier en lecture
    if (file == NULL) {
        // printf("Error open file");
        fclose(file); // fermeture ficher
        return 0;
    }

    char Tableau_section[50], Tableau_element[50];
    char *Name_element;
    int Line = 0, octets = 0, loop_stop = 0;

    while (fgets(Tableau_section, sizeof(Tableau_section), file) != NULL) {
        char *Name_section = strtok(Tableau_section, "\t\n");
        Name_section = delete_space(Name_section);
        Line = ftell(file);

        if (strcmp(Name_section, Section_start) == 0) {
            // printf("Section found\n");
            break;
        }
    }

    if (fseek(file, 0, SEEK_END) == 0 && (octets = ftell(file)) == Line) {
        // printf("No section\n");
        fclose(file); // fermeture ficher
        return 0;
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
                    // printf("Element found\n");
                    Name_element = Name_element + Size_element;
                    int valeur_entiere = atoi(Name_element);
                    fclose(file); // fermeture ficher
                    return valeur_entiere;

                loop_stop++;
            }
            free(first_element);
        }
        else {
            // printf("No element\n");
            loop_stop++;
            fclose(file); // fermeture ficher
            return 0;
        }
    }
}

bool Read_file_bool(char Section[0], char Element[0]) {
    // Section > Element > Tag > Valeur
    // Tag -> bool

    char *Section_start = strcat(Section, Start);
    char *Element_tag = strcat(Element, Section_bool);
    int Size_element = strlen(Element_tag);

    FILE *file = fopen(File_name, "r"); // Ouverture fichier en lecture
    if (file == NULL) {
        // printf("Error open file");
        fclose(file); // fermeture ficher
        return 0;
    }

    char Tableau_section[50], Tableau_element[50];
    char *Name_element;
    int Line = 0, octets = 0, loop_stop = 0;

    while (fgets(Tableau_section, sizeof(Tableau_section), file) != NULL) {
        char *Name_section = strtok(Tableau_section, "\t\n");
        Name_section = delete_space(Name_section);
        Line = ftell(file);

        if (strcmp(Name_section, Section_start) == 0) {
            // printf("Section found\n");
            break;
        }
    }

    if (fseek(file, 0, SEEK_END) == 0 && (octets = ftell(file)) == Line) {
        // printf("No section\n");
        fclose(file); // fermeture ficher
        return 0;
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
                    // printf("Element found\n");
                    Name_element = Name_element + Size_element;
                    bool valeur_booleenne;
                    if (strcmp(Name_element, "true") == 0) {
                       valeur_booleenne = true;
                    } 
                    else {
                       valeur_booleenne = false;
                    }
                    fclose(file); // fermeture ficher
                    return valeur_booleenne;

                loop_stop++;
            }
            free(first_element);
        }
        else {
            // printf("No element\n");
            loop_stop++;
            fclose(file); // fermeture ficher
            return 0;
        }
    }
}

char *Read_file_char(char Section[0], char Element[0]) {
    // Section > Element > Tag > Valeur
    // Tag -> char

    char *Section_start = strcat(Section, Start);
    char *Element_tag = strcat(Element, Section_char);
    int Size_element = strlen(Element_tag);

    FILE *file = fopen(File_name, "r"); // Ouverture fichier en lecture
    if (file == NULL) {
        // printf("Error open file");
        fclose(file); // fermeture ficher
        return 0;
    }

    char Tableau_section[50], Tableau_element[50];
    char *Name_element;
    int Line = 0, octets = 0, loop_stop = 0;

    while (fgets(Tableau_section, sizeof(Tableau_section), file) != NULL) {
        char *Name_section = strtok(Tableau_section, "\t\n");
        Name_section = delete_space(Name_section);
        Line = ftell(file);

        if (strcmp(Name_section, Section_start) == 0) {
            // printf("Section found\n");
            break;
        }
    }

    if (fseek(file, 0, SEEK_END) == 0 && (octets = ftell(file)) == Line) {
        // printf("No section\n");
        fclose(file); // fermeture ficher
        return 0;
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
                    // printf("Element found\n");
                    char *valeur_char = Name_element + Size_element;
                    fclose(file); // fermeture ficher
                    return valeur_char;

                loop_stop++;
            }
            free(first_element);
        }
        else {
            // printf("No element\n");
            loop_stop++;
            fclose(file); // fermeture ficher
            return 0;
        }
    }
}



int Write_file(const char *file_name, int value) {

    FILE *file = fopen(file_name, "w"); // Ouverture du fichier en écriture
    if (file == NULL) { // Vérification ouverture fichier
        return 1;
    }
    fprintf(file, "%d\n", value); // Écriture fichier
    fclose(file);                 // fermeture fichier
    return 0;
}