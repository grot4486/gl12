#include <stdio.h>
#include <pthread.h>

int count = 100000;

void* change()
{
    for (int i = 0; i < 10000; i++) {
        count = count -1;
    }
    return NULL;
}

int main()
{
    pthread_t threads[10];
    printf("Счетчик равен %d\n", count);
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, change, NULL);
    }
    void *result;
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], &result);
    }
    printf("Счетчик равен %d\n", count);
    return 0;
}
