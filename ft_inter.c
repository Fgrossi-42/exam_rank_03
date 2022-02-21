#include <unistd.h>
/*inter é un programma che presi in input due stringhe stampa (senza doppie)
tutte le lettere della prima stringa presenti nella seconda
ex:tumid fleck, null
ex:bellissima bellissima, belisma
ex:armadio ardella, ard
*/
int check(char *argv, char c, int i)
{
	//controllo a ritroso di eventuali doppie di 'c' presenti in argv, a partire da index 'i'
	while (i-- >= 1)
	{
		if (c == argv[i])
			return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int	i;
	int	j;
	
	if (argc == 3)
	{
		i = -1;
		while (argv[1][++i] != '\0')
		{
			j = -1;
			while (argv[2][++j] != '\0')
			{
				if ((argv[1][i] == argv[2][j]) && !(check(argv[1], argv[1][i], i)))
				{
					write(1, &argv[1][i], 1);
					break;
				}
			}
		}
	}
	write(1, "\n", 1);
}
