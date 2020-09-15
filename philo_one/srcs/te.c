
#include "stdio.h"

int			size_int(long int nb)
{
	int i;

   i = 0;
	while ((nb = nb / 10) > 0)
		i++;
	return (++i);
}


int      main(int argc, char **argv)
{
   long int   n = 145423;
   int 	i;
   int   j;
	char	str[size_int(n)];

	i = size_int(n);
	str[size_int(n)] = '\0';
   j = n;
	while (i-- >= 0)
	{
      str[i] = i != 0 ? ((j % 10) + '0') : j + '0';
      j = (j / 10);
	}
   printf("here we test -> |%s|\n", str);
   printf("here we test -> %c\n", str[0]);
	return (1);
}