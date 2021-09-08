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
	game(true);
	double sum_all = 0;
	for(int i = 0; i < LL; i++)
		sum_all += centre_game(i,0);

	printf("%f\n", sum_all/ (double) LL);

	FILE *file;

	if(ptf){
		char path[100];
		sprintf(path,"avg_G(%04d).dat", (int)(Gp * 1000 + 0.000001) );
		printf("Now file:%s\n",path);
		file = fopen(path,"a+");
		fprintf(file, "%f",sum_all/ (double) LL);
		fclose(file);
	}

	return 0;
}

int main(){
	srand(time(NULL));

	for(double k = 0.48; k < 0.5305; k+= 0.005){
		for(int j = 0; j < 10; j++){
			printf("G_p:%f,itr:%d\n",k,j);
			wFinal punOBJ(0.333333,0.333333,3.0, k ,0,0.4);
			punOBJ.final_game(true);
		}		
	}

	return 0;
}
