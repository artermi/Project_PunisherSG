#include "class_punisher.h"
using namespace std;

int main(){
	srand(time(NULL));

	for(int k = 0; k < 21; k++){
		for(int j = 0; j < 21; j++){
				double var_b = (double) k * 0.05;
				double var_g = (double) j * 0.05; 
				punPGG punOBJ(0.333333,0.333333,3.0,var_g,0.2,var_b);
				punOBJ.game(true);	}	
	}

	return 0;
}
