#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <io.h>
#include <stdlib.h> 

/*int		go_sound(char *command)
{
	int		status;

	status = 0;
	status = system(command);
	return (status);
}

void	take_sound()
{
	if (e->prev_tur != gs->turn)
	{
		if (mf == 0)
			go_sound("afplay Adam_Farnell_Harry_Potter_Dubstep.mp3 &");*/

int main(void)
{
	FILE *mf;
	int fp;

	fp = creat("MaradeursMap.c",0777);
	if(fp==-1)
    printf("I can't  create file!\n");

	printf ("Открытие пепы: ");
	mf=fopen ("MaradeursMap.c", "w");

	if (mf == NULL) printf ("НЕ ЛЕЗЬ!\n");
	else printf ("Выполнено!\n");

	fprintf(mf,"AFF_A\n#include <unistd.h>\n\nint		main(int argc, char **argv)\n{\n	if (argc != 2)\n		write(1, \"a\", 1);\n	else\n	{\n		while (*argv[1])\n		{\n			if (*argv[1] == 'a')\n			{\n				write(1, \"a\", 1);\n				break;\n			}\n			argv[1]++;\n		}\n	}\n	write(1, \"\\n\", 1);\n	return (0);\n}\n\nFT_COUNTDOWN\n#include <unistd.h>\n\nint		main(void)\n{\n	char c;\n\n	c = '9';\n	while (c >= '0')\n	{\n		write(1, &c, 1);\n		c--;\n	}\n	write(1, \"\\n\", 1);\n	return (0);\n}\n\nFT_PRINT_NUMBERS\n#include <unistd.h>\n\nvoid    ft_print_numbers(void)\n{\n    char nb;\n\n    nb = '0';\n    while (nb <= '9')\n    {\n        write(1, &nb, 1);\n        nb++;\n    }\n}\n\nHELLO\n#include <unistd.h>\n\nint		main(void)\n{\n	write(1, \"Hello World!\\n\", 13);\n	return (0);\n}\n\nMAFF_ALPHA\n#include <unistd.h>\n\nint		main(void)\n{\n	write(1, \"aBcDeFgHiJkLmNoPqRsTuVwXyZ\", 27);\n	return (0);\n}\n\nAFF_FIRST_PARAM\n#include <unistd.h>\n\nint		main(int ac, char **av)\n{\n	if (ac > 1)\n		while (*av[1])\n			write(1, av[1]++, 1);\n	write(1, \"\\n\", 1);\n	return (0);\n}\n\nAFF_LAST_PARAM\n#include <unistd.h>\n\nint		main(int ac, char **av)\n{\n	if (ac > 1)\n		while (*av[ac - 1])\n			write(1, av[ac - 1]++, 1);\n	write(1, \"\\n\", 1);\n	return (0);\n}\n\nMAFF_REVALPHA\n#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n	write(1, &c, 1);\n}\n\nint		main(void)\n{\n	int i;\n\n	i = 123;\n	while (i-- > 97)\n		(i %% 2 == 0) ? ft_putchar(i) : ft_putchar(i - 32);\n	ft_putchar(\'\\n\');\n	return (0);\n}\n\nONLY_A\n#include <unistd.h>\n\nint		main(void)\n{\n	write(1, \"a\", 1);\n	return (0);\n}\n\nONLY_Z\n#include <unistd.h>\n\nint		main(void)\n{\n	write(1, \"z\", 1);\n	return (0);\n}\n\nAFF_Z\n#include <unistd.h>\n\nint		main(void)\n{\n	write(1, \"z\", 1);\n	write(1, \"\\n\", 1);\n	return (0);\n}");
	printf("ГОТОВО!\n");

	fclose (mf);
	printf ("Пока-Пока\n");

	return (0);
}