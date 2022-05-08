/*union é un programma che prese in input due stringhe stampa prima tutta 
la prima stringa e conseguentemente tutte le lettere della seconda
(sempre senza doppie) che non sono presenti nella prima
ex:ciao stronzo, ciaostrnz
ex:bellissima bellissima, belisma
ex:pollo tacchi, poltachi
*/

#include <unistd.h>

int
	main(int argc, char **argv)
{
	int	used[255];
	int	i, j;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!used[(unsigned char)argv[i][j]])
				{
					used[(unsigned char)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
