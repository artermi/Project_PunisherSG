#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>


#define K 0.5
#define L 800
#define LL (L * L)

class punPGG{
public:
	long long rnd;
	double r;
	double beta;
	double Dr; //Defactor's rate
	double Pr; //Punisher rate
	double T;
	double Gp;
	char dir_name[100];

	int* Strategy; // 0 for Defactor, 1 for Cooperator, 2 for Punisher
	int** Neighbour;
	//int MST_N[LL];
	//int Next_MST_N[LL];
	//double probs[LL];
	//long long curr[LL];

	punPGG(const double pr,const double dr, const double rate, const double gp,
	 const double t,const double Beta); // rate of Pubisher, rate of Defactor, r,
	double unit_game(const int cent,const int to);
	double centre_game(const int cent, const int isX);
	int game(bool ptf);
};