/*union é un programma che prese in input due stringhe stampa prima tutta 
la prima stringa e conseguentemente tutte le lettere della seconda
(sempre senza doppie) che non sono presenti nella prima
ex:ciao stronzo, ciaostrnz
ex:bellissima bellissima, belisma
ex:pollo tacchi, poltachi
*/

/**
	THIS SHOULD BE A BETTER IMPLEMENTATION IN MY OPINION
*/

#include <unistd.h>

#define USED used[(unsigned char)args[i][j]]

int main(int n, char **args) {
	int used[255] = {0};
	int i, j;
	if (n == 3) {
		i = 1;
		while(i < 3) {
			j = 0;
			while (args[i][j]) {
				if (!USED) {
					USED = 1;
					write(1, &args[i][j], 1);
				}
				j++;
			}
			i++;
		}

	}
	write(1, "\n", 1);
	return 0;
}
