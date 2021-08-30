#include "class_punisher.h"
using namespace std;

class wFinal: public punPGG
{
public:
	wFinal(const double pr,const double dr, const double rate, const double gp,
	 const double t,const double Beta):punPGG( pr, dr,  rate, gp, t, Beta){};
	int final_game(bool ptf);
};

int wFinal::final_game(bool ptf){
	game(false);
	double sum_all = 0;
	for(int i = 0; i < LL; i++)
		sum_all += centre_game(i,0);

	printf("%f\n", sum_all/ (double) LL);

	FILE *file;

	if(ptf){
		char path[100];
		sprintf(path,"avg_G(%03d).dat", (int)(Gp * 100 + 0.000001) );
		printf("Now file:%s\n",path);
		file = fopen(path,"w+");
		fprintf(file, "%f",sum_all/ (double) LL);
		fclose(file);
	}

	return 0;
}

int main(){
	srand(time(NULL));

	for(double k = 0.20; k < 0.705; k+= 0.01){
		wFinal punOBJ(0.333333,0.333333,3.0, k ,0,0.4);
		punOBJ.final_game(true);		
	}

	return 0;
}
