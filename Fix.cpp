#include "class_punisher.h"
using namespace std;

int main(){
	srand(time(NULL));
	double T[2] = {0,0.2};

	for(int k = 0; k < 2; k++){

		for(double i = 0; i <= 1.01; i += 0.1){
			for(double j = 0; j < 1.01 - i; j+= 0.1){
				punPGG punOBJ(i,j,3.0,0.7,T[k],0.7);
				punOBJ.game(true);
			}
		}
	}

	return 0;
}