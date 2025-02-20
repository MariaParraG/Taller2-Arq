#include <stdio.h> 
#include <stdbool.h> 
#include <unistd.h> // Para la función sleep()

// Variable global que simula el estado del dispositivo de E/S
bool dispositivo_listo = false; 

// Función que simula el dispositivo de E/S, que se pone listo tras un retardo
void dispositivo_es() { 
    sleep(2); // Simula un retardo de 2 segundos
    dispositivo_listo = true; // Después del retardo, el dispositivo se pone listo
    printf("Dispositivo de E/S: listo para recibir datos.\n");
}

// Función que simula el controlador haciendo E/S programada con timeout
void controlador_programado(int data) { 
    int timeout = 5; // Número máximo de iteraciones (por ejemplo, 5 segundos)
    
    // Espera hasta que el dispositivo esté listo o se alcance el timeout
    while (!dispositivo_listo && timeout > 0) { 
        printf("Controlador: esperando que el dispositivo esté listo...\n");
        sleep(1); // Espera 1 segundo
        timeout--; // Decrementa el contador de timeout
        
        // Verifica si el dispositivo ya está listo
        if (dispositivo_listo) {
            break; // Si el dispositivo se pone listo, rompe el ciclo
        }
    }

    // Si se agotó el tiempo y el dispositivo no está listo, mostrar error
    if (!dispositivo_listo) {
        printf("Error: el dispositivo no se puso listo en el tiempo esperado.\n");
        return; // Sale de la función si no se pudo enviar el dato
    }

    // Una vez que el dispositivo está listo, se envía el dato
    printf("Controlador: enviando dato %d al dispositivo de E/S...\n", data);
}

int main() { 
    int dato_a_enviar = 55; // Dato a enviar al dispositivo de E/S

    // Primero se simula que el dispositivo se prepara y se pone listo
    printf("Simulando preparación del dispositivo...\n");
    dispositivo_es(); 

    // Luego el controlador verifica si el dispositivo está listo y envía el dato
    controlador_programado(dato_a_enviar); 

    return 0; 
}
