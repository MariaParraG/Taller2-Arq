#include <stdio.h> 
#include <stdbool.h> 
#include <unistd.h> // Para la función sleep()
#include <pthread.h> // Para trabajar con hilos

// Variable global que simula el estado del dispositivo de E/S
volatile bool dispositivo_listo = false; // 'volatile' indica que esta variable puede cambiar en otro hilo

// Función que simula el dispositivo de E/S (se ejecuta en un hilo separado)
void* simular_dispositivo(void *arg) { 
    sleep(2); // Simula un retardo de 2 segundos antes de que el dispositivo esté listo
    dispositivo_listo = true; // Marca el dispositivo como listo
    printf("Dispositivo de E/S: Listo para recibir datos.\n");
    return NULL; // El hilo no necesita devolver nada
}

// Función que simula el controlador con E/S programada (espera activa o polling)
void controlador_programado(int data) { 
    int timeout = 5; // Número máximo de intentos (timeout de 5 segundos)

    // Verifica si el dispositivo está listo dentro del límite de tiempo
    while (!dispositivo_listo && timeout > 0) { 
        printf("Controlador: Esperando que el dispositivo esté listo...\n");
        sleep(1); // Espera 1 segundo antes de volver a verificar
        timeout--; // Decrementa el contador de timeout
    }

    // Si no se consiguió que el dispositivo estuviera listo, muestra un error
    if (!dispositivo_listo) { 
        printf("Error: El dispositivo no se puso listo en el tiempo esperado.\n");
        return; // Sale de la función si no se pudo enviar el dato
    }

    // Si el dispositivo está listo, envía el dato
    printf("Controlador: Enviando dato %d al dispositivo de E/S...\n", data);
}

int main() { 
    int dato_a_enviar = 55; // Dato a enviar al dispositivo de E/S

    // Variable para el hilo que simula el dispositivo
    pthread_t hilo_dispositivo; 

    // Crear un hilo para simular el comportamiento asincrónico del dispositivo
    pthread_create(&hilo_dispositivo, NULL, simular_dispositivo, NULL); 

    // El controlador realiza la espera activa (polling) y envía el dato
    controlador_programado(dato_a_enviar); 

    // Se espera a que el hilo del dispositivo finalice
    pthread_join(hilo_dispositivo, NULL); 

    return 0; 
}
