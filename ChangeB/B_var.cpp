#include "class_punisher.h"
using namespace std;

int main(){
	srand(time(NULL));
	double B[11] = {0,.1,.2,.3,.4,.5,.6,.7,.8,.9,1};

	for(int k = 0; k < 50; k++){
		punPGG punOBJ(0.333333,0.333333,3.0,0.7,0.1,  0.02 * (double)k ); //rate G_p T B
		punOBJ.game(true);		
	}

	return 0;
}