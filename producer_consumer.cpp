// producer_consumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <pthread.h>
using namespace std;
int num = 0;
const int LIMIT = 100;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* producer(void* ignore) {
	for(;;){
		pthread_mutex_lock(&mut);
		while(num >= LIMIT){
			pthread_cond_wait(&cond, &mut);
		}
		cout << num++ << " ";
		pthread_mutex_unlock(&mut);
		pthread_cond_signal(&cond);
	}
}

void* consumer(void* ignore) {
	for(;;){
		pthread_mutex_lock(&mut);
		while(num <= 0){
			pthread_cond_wait(&cond, &mut);
		}
		cout << num-- << " ";
		pthread_mutex_unlock(&mut);
		pthread_cond_signal(&cond);
	}
 }

int main()
{
    pthread_t t1, t2;
    int num = 1;
    pthread_create(&t1, 0, &producer, NULL);
    pthread_create(&t1, 0, &consumer, NULL);
    pthread_join(t1, 0);
	pthread_join(t2, 0);
}

