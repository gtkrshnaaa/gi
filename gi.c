#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VARS 100

// Structure to store variables
typedef struct {
    char name[50];
    char value[256];
} Variable;

Variable variables[MAX_VARS]; // Array for storing variables
int varCount = 0; // Number of stored variables

// Function to find a variable
char *getVariable(char *name) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }
    return NULL; // Return NULL if not found
}

// Function to add or update a variable
void setVariable(char *name, char *value) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            strcpy(variables[i].value, value);
            return;
        }
    }
    // Add new variable if it doesn't exist
    if (varCount < MAX_VARS) {
        strcpy(variables[varCount].name, name);
        strcpy(variables[varCount].value, value);
        varCount++;
    }
}

// Function to execute println statement
void runPrintln(char *input) {
    // Print string directly
    if (strncmp(input, "println(\"", 9) == 0 && strcmp(input + strlen(input) - 3, "\");") == 0) {
        char output[256];
        strncpy(output, input + 9, strlen(input) - 12);
        output[strlen(input) - 12] = '\0';
        printf("%s\n", output);
        return;
    }

    // Print variable (println($variable);)
    if (strncmp(input, "println($", 9) == 0 && strcmp(input + strlen(input) - 2, ");") == 0) {
        char varName[50];
        strncpy(varName, input + 9, strlen(input) - 11);
        varName[strlen(input) - 11] = '\0';

        char *value = getVariable(varName);
        if (value) {
            printf("%s\n", value);
        } else {
            printf("Undefined variable: %s\n", varName);
        }
        return;
    }

    printf("Syntax Error!\n");
}

// Function to execute variable assignment
void runAssignment(char *input) {
    if (strncmp(input, "$", 1) != 0) {
        printf("Syntax Error!\n");
        return;
    }

    char name[50], value[256];
    if (sscanf(input, "$%s = \"%[^\"]\";", name, value) == 2) {
        setVariable(name, value);
    } else {
        printf("Syntax Error!\n");
    }
}

// Function to read and execute a script file
void runFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File not found: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0; // Remove newline character

        if (strncmp(line, "println", 7) == 0) {
            runPrintln(line);
        } else if (strncmp(line, "$", 1) == 0) {
            runAssignment(line);
        } else {
            printf("Syntax Error!\n");
        }
    }

    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file.gi>\n", argv[0]);
        return 1;
    }

    runFile(argv[1]);
    return 0;
}
