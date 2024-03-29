#include "class_punisher.h"
using namespace std;

punPGG::punPGG(const double pr,const double dr, const double rate, const double gp,
	 const double t,const double Beta){
	r = rate;
	Pr = pr;
	Dr = dr;
	Gp = gp;
	T = t;
	beta = Beta;
	Strategy = new int[LL];
	Neighbour = new int*[LL];
	for(int i = 0; i < LL; i++)
		Neighbour[i] = new int[4];
	strcpy(dir_name,"Fixed");

	for(int i = 0; i < LL; i++){
		Neighbour[i][0] = (i - L + LL ) % LL; //North
		Neighbour[i][1] = (i + L) % LL;
		Neighbour[i][2] = (i + 1) % LL;
		Neighbour[i][3] = (i - 1 + LL) % LL;
	}//initialise the neighbour

	for(int i = 0; i < LL; i++){
		double rdnum = (double)rand()/(double)RAND_MAX;
		if(rdnum < dr)
			Strategy[i] = 0;
		else if (rdnum < pr + dr)
			Strategy[i] = 2;
		else
			Strategy[i] = 1;

		//MST_N[i] = -1;
		//Next_MST_N[i] = -1; 
	}
}

double punPGG::unit_game(const int cent,const int to){
	/*
	if(curr[cent] < rnd){
		MST_N[cent] = Next_MST_N[cent];
		curr[cent] = rnd;
	}
	for(int i = 0; i < 4; i ++){
		int person = Neighbour[cent][i];
		if(curr[person] < rnd){
			curr[person] = rnd;
		}
	}
	*/
	// Update each one's current round

	double set_strat[3] = {0.0,0.0,0.0}; //0 Nd, 1 Nc, 2 Np; Only neighbours
	set_strat[Strategy[cent]] += 1.0;
	for(int i = 0; i < 4; i++)
		set_strat[Strategy[Neighbour[cent][i]]] += 1.0; 

	if(Strategy[to] == 0)
		return (r * set_strat[1]) / 5.0 - beta * set_strat[2] - T;
	if(Strategy[to] == 1)
		return (r * set_strat[1]) / 5.0 - 1.0 - T;

	return (r * set_strat[1]) / 5.0 - Gp + (5.0 * T)/(set_strat[2]) - T;
}

double punPGG::centre_game(const int cent, const int isX){
	double profit = unit_game(cent,cent);
	double earn[4] = {0.0,0.0,0.0,0.0};
	for(int i = 0; i < 4; i++){
		earn[i] = unit_game(Neighbour[cent][i],cent);
		profit += earn[i];
	}

	/*
	if(isX)
		return profit;

	double mst_amount = *max_element(earn,earn+4);
	int maxNes[4] = {-1,-1,-1,-1};
	int max_amount = 0;

	for(int i = 0; i < 4; i ++){
		if(earn[i] + 0.0000001 >= mst_amount){
			maxNes[max_amount] = Neighbour[cent][i];
			max_amount ++;
		}
	}

	Next_MST_N[cent] = maxNes[rand() % max_amount];
	*/

	return profit;
}


int punPGG::game(bool ptf){
	FILE *file;
	if(ptf){
		char path[100];
		sprintf(path,"G(%04d).dat", (int)(Gp * 1000 + 0.000001) );
		printf("Now file:%s\n",path);
		file = fopen(path,"a+");
	}

	double rate[3] = {0.0,0.0,0.0};

	int Xrnd = 10001;
	for(int i = 0; i < Xrnd; i++){
		if(i % 500 == 0){
			double total[3] = {0.0,0.0,0.0};
			for(int j = 0; j < LL; j++)
				total[Strategy[j]] += 1.0;

			for (int j = 0; j < 3; j++)
				rate[j] = double (total[j]/double(LL));
			if(ptf && i == Xrnd - 1)
				fprintf(file, "%06d %.3f %3f %3f\n",i,rate[0],rate[1],rate[2]);
			printf("%d %.3f %3f %3f\n",i,rate[0],rate[1],rate[2]);

		}
		if(i == 10000)
			continue;
		bool STOP_RUN = false;
		for(int j = 0; j <3; j++)
			if(rate[j] + 0.000001 >= 1)
				STOP_RUN = true;
		if(STOP_RUN)
			continue;
		

		for(int j = 0; j < LL; j++){
			int x = rand() % LL;
			int y = Neighbour[x][rand() % 4 ];
			rnd++;
			if (Strategy[x] == Strategy[y])
				continue;
//			cout << x << ',' << y <<endl;
			double x_earn = centre_game(x,1);
			double y_earn = centre_game(y,0);

			if ((double)rand()/(double)RAND_MAX < 1.0/( 1.0 + exp((y_earn - x_earn)/K) ) )
				Strategy[y] = Strategy[x];
		}
	}
	if(ptf)
		fclose(file);

	return 0;
}

/*
int main(){
	srand(time(NULL));
	for(double i = 0; i <= 1.01; i += 0.1){
		for(double j = 0; j < 1.01 - i; j+= 0.1){
			punPGG punOBJ(i,j,3.0,0.7,0.0,0.7);
			punOBJ.game(true);
		}
	}
}
*/
