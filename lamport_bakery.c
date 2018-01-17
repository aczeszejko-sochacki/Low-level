#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>

int critical_section, n_threads;
int *enter, *numbers;
pthread_mutex_t lock_mutex =
 PTHREAD_MUTEX_INITIALIZER;

int max_number(){
    int maks = 0;

    for(int i = 0; i < n_threads; i++){
        if(numbers[i] > maks) maks = numbers[i];
    }

    return ++maks;
}


void lock(int thread_id){
    enter[thread_id] = true;
    int maks = max_number();
    numbers[thread_id] = maks;
    enter[thread_id] = false;

    for(int i = 0; i < n_threads; i++){
        while(enter[i]){}
        while(numbers[i] != 0 &&
        (numbers[i] < numbers[thread_id]
         || (numbers[i] == numbers[thread_id]
         && i < thread_id))){}
    }
}

void unlock(int thread_id){
    numbers[thread_id] = 0;
}

void *bakery_consumer(void *a){
    int id = *((int *) a);
    while(true){
        lock(id);
        if(critical_section > 0){
            unlock(id);
            critical_section--;
        }
        else{
            unlock(id);
            pthread_exit(0);
        }
    }
}

void *mutex_consumer(void *a){
    pthread_mutex_lock(&lock_mutex);
    while(true){
        if(critical_section > 0){
            critical_section--;
            pthread_mutex_unlock(&lock_mutex);
        }
        else{
            pthread_mutex_unlock(&lock_mutex);
            pthread_exit(0);
        }
    }
}

void test(int local_critical_section, int n_threads){
    printf("critical section: %d  n threads: %d\n",
    local_critical_section, n_threads);

    pthread_t bakery_threads[n_threads],
    mutex_threads[n_threads];
    enter = calloc(n_threads, n_threads*sizeof(bool));
    numbers = calloc(n_threads, n_threads*sizeof(int));
    critical_section = local_critical_section;
    int values[n_threads];

    clock_t start = clock();
    for(int i = 0; i < n_threads; i++){
        values[i] = i;
        pthread_create(&bakery_threads[i], NULL,
         bakery_consumer, (void *)&values[i]);
    }

    for(int i = 0; i < n_threads; i++){
        pthread_join(bakery_threads[i], NULL);
    }

    free(enter);
    free(numbers);

    printf("Value: %d  Time: %lu\n",
     critical_section, clock() - start);
    critical_section = local_critical_section;

    clock_t start2 = clock();
    for(int i = 0; i < n_threads; i++){
        values[i] = i;
        pthread_create(&mutex_threads[i], NULL,
         mutex_consumer, NULL);
    }

    for(int i = 0; i < n_threads; i++){
        pthread_join(mutex_threads[i], NULL);
    }

    printf("Value: %d  Time: %lu\n",
     critical_section, clock() - start2);
}

int main(int argc, char* argv[]){
    int n_tests = atoi(argv[1]);

    for(int i = 0; i < n_tests; i++){
        test(atoi(argv[i+2]), atoi(argv[i+3]));
    }
}

