#include <stdarg.h>
#include <stdio.h>
#include "../libft.h"
// void	ft_test(int i, ...)
// {
// 	va_list ap;
// 	int x;
// 	char *str;

// 	x = 0;
// 	va_start(ap, i);
// 	while (x < i)
// 	{
// 		str = va_arg(ap, char*);
// 		printf("%s\n", str);
// 		x++;
// 	}
// 	va_end(ap);
// }

int		main(void)
{
	int nb = 255;
	printf("%-d", nb);
	// ft_test(i, argv[1], argv[2], argv[3]);
	return(0);
}
