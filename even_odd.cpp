// even_odd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <pthread.h>
using namespace std;
int NUMBER = 0;
const int LIMIT = 100;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* printEven(void* ignore) {
	while(NUMBER < LIMIT){
		pthread_mutex_lock(&mut);
		while(NUMBER%2 != 0){
			cout << "Before Waiting in even: " << NUMBER << endl;
			pthread_cond_wait(&cond, &mut);
			cout << "After Waiting in even: " << NUMBER << endl;
		}
		cout << NUMBER++ << endl;
		pthread_mutex_unlock(&mut);
		pthread_cond_signal(&cond);
	}
}

void* printOdd(void* ignore) {
	while(NUMBER < LIMIT){
		pthread_mutex_lock(&mut);
		while(NUMBER%2 != 1){
			cout << "Before Waiting in odd: " << NUMBER << endl;
			pthread_cond_wait(&cond, &mut);
			cout << "After Waiting in odd: " << NUMBER << endl;
		}
		cout << NUMBER++ << endl;
		pthread_mutex_unlock(&mut);
		pthread_cond_signal(&cond);
	}
 }

int main()
{
    cout << "Hello World!\n";

    pthread_t t1, t2;
    int num = 1;
    pthread_create(&t1, 0, &printEven, NULL);
    pthread_create(&t1, 0, &printOdd, NULL);
    pthread_join(t1, 0);
	pthread_join(t2, 0);
}

