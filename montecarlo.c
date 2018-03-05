/*
 * Lab 3: Synchronization
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

//Define the number of random numbers the program generates.
#define ITERATIONS 100000

int main(int argc, char **argv)
{
	pthread_t tid;
	pthread_attr_t attr;

	//Get default attributes
	pthread_attr_init(&attr);
	//Create Thread
	pthread_create(&tid, &attr, runner, argv[1]);
	//Wait for the thread to exit
	pthread_join(tid, NULL);

	//Calculate estimate of pi
	double pi = 4*(double)(pointsWithinCircle/totalPoints);


	printf("Pi Calculation Interval: %d\n", ITERATIONS);
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

		if(d<=1)
		{
			pointsWithinCircle++;
		}
		totalPoints++;
	}
		pthread_exit(0);
}

