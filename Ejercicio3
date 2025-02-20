#include <stdio.h> 
#include <stdbool.h> 
#include <unistd.h> // Para la función sleep(), para simular tiempo de espera

// Simulación de registros de estado del dispositivo de E/S
bool dispositivo_listo = false; // Indica si el dispositivo de E/S está listo

// Función que simula el controlador verificando el estado del dispositivo
void controlador_programado(int data) { 
    // Bucle de espera activa ("polling") hasta que el dispositivo esté listo
    while (!dispositivo_listo) { 
        printf("Controlador: Esperando que el dispositivo esté listo...\n"); 
        sleep(1); // Simula el tiempo de espera, evitando un bucle de consumo alto de CPU
    }

    // Una vez listo, se envía el dato
    printf("Controlador: Enviando dato %d al dispositivo de E/S...\n", data);
    // Se podría aquí escribir en el "registro de datos del dispositivo"
}

// Función que simula el dispositivo de E/S
void dispositivo_es() { 
    // Simula que después de un tiempo, el dispositivo está listo para recibir el dato
    sleep(2); // Simula el tiempo que tarda el dispositivo en estar listo
    printf("Dispositivo de E/S: Listo para recibir datos.\n"); 
    dispositivo_listo = true; // El dispositivo se pone listo para recibir datos
}

int main() { 
    int dato_a_enviar = 55; // Dato que se va a enviar al dispositivo de E/S

    // Simulación de la E/S programada
    printf("Iniciando la simulación de E/S programada...\n"); 
    dispositivo_es(); // El dispositivo de E/S se pone listo en algún punto 
    controlador_programado(dato_a_enviar); // El controlador verifica y envía el dato

    printf("E/S programada completada.\n"); 
    return 0; 
}
