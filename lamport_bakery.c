#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdbool.h>

int critical_section, n_threads;
int *enter, *numbers;

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
        while(enter[i]){
            //printf("one");
        }
        while(numbers[i] != 0 && (numbers[i] < numbers[thread_id]
        || (numbers[i] == numbers[thread_id] && i < thread_id))){
        //printf("%d:0 %d:1 %d:2 %d:3  %d ", numbers[0], numbers[1], numbers[2], numbers[3], i);
        }
        puts("done");
    }
}

void unlock(int thread_id){
    numbers[thread_id] = 0;
}

void *consumer(void *a){
    int id = *((int *) a);
    printf("%d", id);
    while(true){
        lock(id);
        if(critical_section > 0){
            critical_section--;
        }
        else{
            pthread_exit(0);
        }
        unlock(id);
    }
}

int main(int argc, char* argv[]){
    critical_section = atoi(argv[1]);
    n_threads = atoi(argv[2]);
    enter = calloc(n_threads, n_threads*sizeof(bool));
    numbers = calloc(n_threads, n_threads*sizeof(int));

    pthread_t my_threads[n_threads];

    int values[n_threads];

    for(int i = 0; i < n_threads; i++){
        values[i] = i;
        pthread_create(&my_threads[i], NULL, consumer, (void *)&values[i]);
    }

    for(int i = 0; i < n_threads; i++){
        pthread_join(my_threads[i], NULL);
    }

    //for(int j = 0; j < n_threads; j++) printf("%d ", enter[j]);

    free(enter);
    free(numbers);

    printf("%d", critical_section);
}

