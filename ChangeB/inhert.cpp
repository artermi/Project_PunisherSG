#include "class_punisher.h"
using namespace std;

class Inherent: public punPGG
{
public:
	double later_beta;
	Inherent(const double pr,const double dr, const double rate, const double gp, 
		const double t,const double Beta): punPGG( pr, dr,  rate,  gp, t, 0.48){
		later_beta = Beta;
	};
	int game(bool ptf);
};

int Inherent::game(bool ptf){
		FILE *file;
	if(ptf){
		char path[100];
		sprintf(path,"B(%03d).dat", (int)(later_beta * 100) );
		printf("Now file:%s\n",path);
		file = fopen(path,"w+");
	}

	double rate[3] = {0.0,0.0,0.0};

	for(int i = 0;; i++){
		if(i % 200000 == 0){
			beta = beta - 0.01 ;
			printf("%f\n", beta);
		}

		if(beta < later_beta - 0.00001)
			break;

		if(i % 1000 == 0){
			double total[3] = {0.0,0.0,0.0};
			for(int j = 0; j < LL; j++)
				total[Strategy[j]] += 1.0;

			for (int j = 0; j < 3; j++)
				rate[j] = double (total[j]/double(LL));
			if(ptf)
				fprintf(file, "%06d %.3f %.3f %.3f\n",i,rate[0],rate[1],rate[2]);
			printf("%d %.3f %.3f %.3f\n",i,rate[0],rate[1],rate[2]);

		}
		bool no_need = false;
		for(int j = 0; j <3; j++)
			if(rate[j] + 0.000001 >= 1)
				no_need = true;
		if(no_need)
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


int main(){
	srand(time(NULL));
	double B[11] = {0,.1,.2,.3,.4,.5,.6,.7,.8,.9,1};

	for(int k = 0; k < 1; k++){
		Inherent punOBJ(0.333333,0.333333,3.0,0.7,0.05, 0.43); //rate G_p T B
		punOBJ.game(true);		
	}

	return 0;
}