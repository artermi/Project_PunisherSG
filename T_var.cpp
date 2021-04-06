#include "class_punisher.h"
using namespace std;

int main(){
	srand(time(NULL));
	double T[11] = {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1};

	for(int k = 0; k < 11; k++){
		punPGG punOBJ(0.333333,0.333333,3.0,0.7,T[k],0.7);
		punOBJ.game(true);		
	}

	return 0;
}