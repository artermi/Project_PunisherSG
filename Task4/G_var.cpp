#include "class_punisher.h"
using namespace std;

int main(){
	srand(time(NULL));

	for(double k = 0.47; k < 0.505; k+=0.01){
		punPGG punOBJ(0.333333,0.333333,3.0,k,0,0.4);
		punOBJ.game(true);		
	}

	return 0;
}
