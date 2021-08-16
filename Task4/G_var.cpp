#include "class_punisher.h"
using namespace std;

int main(){
	srand(time(NULL));

	for(int k = 0; k < 51; k++){
		punPGG punOBJ(0.333333,0.333333,3.0, 0.02 * double(k) ,0.1,0.7);
		punOBJ.game(true);		
	}

	return 0;
}