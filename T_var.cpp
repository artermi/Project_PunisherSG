#include "class_punisher.h"
using namespace std;

int main(){
	srand(time(NULL));
	double T[21] = {0,.01,.02,.03,.04,.05,.06,.07,.08,.09,.1,
		              .11,.12,.13,.14,.15,.16,.17,.18,.19,.2};

	for(int k = 0; k < 21; k++){
		punPGG punOBJ(0.333333,0.333333,3.0,0.7,T[k],0.7);
		punOBJ.game(true);		
	}

	return 0;
}