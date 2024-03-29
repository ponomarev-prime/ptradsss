#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // Include this for intptr_t

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid)
{
    // Cast tid back to int before printing
    printf("Привет мир! Тебя приветсвет поток № %d\n", (int)(intptr_t)tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;

    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("Это основная программа. Создание потока № %d\n", i);
        // Use intptr_t to cast i to void *
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *)(intptr_t)i);

        if (status != 0)
        {
            printf("Жаль, что функция pthread_create вернула код ошибки %d\n", status);
            exit(-1);
        }
    }
    exit(0);
}
