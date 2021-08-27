#include "class_punisher.h"
using namespace std;

int main(){
	srand(time(NULL));

	for(double k = .87; k  <.885; k+=0.1){
		punPGG punOBJ(0.333333,0.333333,3.0, k,0.2,0.2);
		punOBJ.game(true);		
	}

	return 0;
}