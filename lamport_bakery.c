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

    return maks;
}


void lock(int thread_id){
    enter[thread_id] = true;
    numbers[thread_id] = 1 + max_number();
    enter[thread_id] = false;

    for(int i = 0; i < n_threads; i++){
        while(enter[i]){}
    }
}

void unlock(int thread_id){
    numbers[thread_id] = 0;
}

void *consumer(void *a, int id){
    while(true){
        lock(id);
        if(critical_section > 0) critical_section--;
        else pthread_exit(0);
        unlock(id);
    }
}

int main(int argc, char* argv[]){
    critical_section = atoi(argv[1]);
    n_threads = atoi(argv[2]);
    enter = calloc(false, n_threads*sizeof(bool));
    numbers = calloc(0, n_threads*sizeof(int));
}
