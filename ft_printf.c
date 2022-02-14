#include <unistd.h>
#include <stdarg.h>
//librerie essenziali
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int     ft_putnbr(unsigned int i, int base)
{
    char    *base_set;
    int     count;
    int     n;

	base_set = "0123456789abcdef";
	count = 0;
	// i % 10 per il caso dell'intero e i % 16 nel  caso dell'indirizzo
	n = i % base;
    if (i / base > 0)
        count += ft_putnbr(i / base, base);
		//funzione uguale a putnbr tipico
    count += ft_putchar(base_set[n]);
    return (count);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
		//assegna "(null)" in caso str fosse vuota, ritorna comunque la lunghezza di cio che stampa
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putint(int i)
{
	//funzione che controlla il segno del numero prima di passarlo a putnbr con una base di 10
	int	count;

	count = 0;
	if (i < 0)
	{
		count += ft_putchar('-');
		i *= -1;
	}
	count += ft_putnbr(i, 10);
	return (count);
}

int	ft_printf(char *string, ...)
{
	int			count;
	va_list		args;
	int			i;

	i = 0;
	count = 0;
	//count += prima di ogni richiamo di funzione che stampa caratteri
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			//ricorda di passare argomenti tramite va_arg(args,"needed_value")
			if (string[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			if (string[i] == 'd')
				count += ft_putint(va_arg(args, int));
			if (string[i] == 'x')
				//richiama putnbr passando una base di 16 per l'indirizzo
				count += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		else
			count += ft_putchar(string[i]);
		i++;
	}
	//ricorda "va_end(args);" prima del return
	va_end(args);
	return (count);
}