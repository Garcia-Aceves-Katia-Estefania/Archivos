#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMEROS 100

void convertirTelefono(const char *telefono, char **nuevoTelefono) {

    *nuevoTelefono = (char *)malloc(sizeof(char) * (strlen(telefono) + 8));

    strncpy(*nuevoTelefono, "(", 2);
    strncat(*nuevoTelefono, telefono, 2);
    strncat(*nuevoTelefono, ")-", 3);


    strncat(*nuevoTelefono, telefono + 2, 1);
    strncat(*nuevoTelefono, "-", 2);

    strncat(*nuevoTelefono, telefono + 3, strlen(telefono) - 3);
}

int main() {
    char numerosTelefonicos[MAX_NUMEROS][15];
    char *nuevosNumeros[MAX_NUMEROS];
    int numNumeros;

    printf("Ingrese la cantidad de números telefónicos: ");
    scanf("%d", &numNumeros);

    printf("Ingrese los números telefónicos:\n");
    for (int i = 0; i < numNumeros; i++) {
        scanf("%s", numerosTelefonicos[i]);
    }

    for (int i = 0; i < numNumeros; i++) {
        convertirTelefono(numerosTelefonicos[i], &nuevosNumeros[i]);
    }

    FILE *archivo = fopen("numeros.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        return 1;
    }

    for (int i = 0; i < numNumeros; i++) {
        fprintf(archivo, "Número telefónico: %s\n", numerosTelefonicos[i]);
        fprintf(archivo, "Nueva cadena: %s\n\n", nuevosNumeros[i]);

        free(nuevosNumeros[i]);
    }

    fclose(archivo);
    printf("Los números telefónicos se han guardado en el archivo 'numeros.txt'.\n");

    return 0;
}
