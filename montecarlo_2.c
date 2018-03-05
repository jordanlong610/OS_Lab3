/*
 * Lab 3: Synchronization - Part 2
 * Programmer: Jordan Long
 * Course: CMPE 320
 * Section 1
 * Instructor: S. Lee
 *
 */


#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

double pointsWithinCircle;
double totalPoints;
void *runner(void *param);
pthread_mutex_t mutex;


//Define the number of random numbers the program generates.
#define ITERATIONS 100000
#define THREADS 5

int main(int argc, char **argv)
{
	pthread_t threads[THREADS];
	pthread_attr_t attr;

	//Get default attributes
	pthread_attr_init(&attr);
	//Create default mutex lock
	pthread_mutex_init(&mutex, NULL);

	//Create Threads
	for(int i=0; i<THREADS;i++)
	{
		pthread_create(&threads[i], &attr, runner, argv[1]);

	}
	//Wait for the threads to exit

	for(int i=0; i<THREADS;i++)
	{
		pthread_join(threads[i], NULL);

	}

	//Calculate estimate of pi
	double pi = 4*(double)(pointsWithinCircle/totalPoints);


	printf("Pi Calculation Interval: %d\n", ITERATIONS);
	printf("Number of Threads Running: %d\n", THREADS);
	printf("Estimation of PI: %lf \n", pi);

	return 0;
}




/*
 * Generate random coordinates and for pi calculation.
 */
void *runner(void *param)
{

	pointsWithinCircle, totalPoints = 0;


	/*
	 * For n iterations, generate random coordinates and check if they are in the circle.
	 * If so, increment pointsWithinCircle.
	 */

	for(int i = 0; i< ITERATIONS; i++)
	{
		double x = (double)rand()/RAND_MAX;
		double y = (double)rand()/RAND_MAX;

		double d = sqrt((x*x)+(y*y));

		pthread_mutex_lock(&mutex);
		if(d<=1)
		{
			pointsWithinCircle++;
		}
		totalPoints++;
		pthread_mutex_unlock(&mutex);
	}


		pthread_exit(0);

}

