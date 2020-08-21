#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h> 
#include <unistd.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define PURPLE  "\033[1;35m"
#define WHITE   "\033[1;37m"

/*int		go_sound(char *command)
{
	int		status;

	status = 0;
	status = system(command);
	return (status);
}

void	take_sound()
{
		if (mf == NULL)
			go_sound("afplay Adam_Farnell_Harry_Potter_Dubstep.mp3 &");
}        */  

int			ft_isspace(char c)
{
	return (c == '~');
}

int		count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			count++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str)
{
	char *word;
	int	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char **arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));

	int i = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			arr[i] = malloc_word(str);
			i++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

char* concat(char *s1, char *s2) {

        size_t len1 = strlen(s1);
        size_t len2 = strlen(s2);                      

        char *result = malloc(len1 + len2 + 1);

        if (!result) {
            fprintf(stderr, "malloc() failed: insufficient memory!\n");
            return NULL;
        }

        memcpy(result, s1, len1);
        memcpy(result + len1, s2, len2 + 1);    

        return result;
    }

/*int pusher (char * comment)
{
    if (comment[0] != '\0')
    {
        system("cd ~/rendu");
        system("git commit -a -m \" ");
    }
}*/

int opener(char *header, char *fill)
{
	FILE *mf;
    FILE *mh;
	int fp;
    char *HOME = getenv("HOME");
    char *rendu = "./rendu";
    chdir (HOME);
    chdir (rendu);
    char *dot_c = ".c";
    char *header_c = concat(header, dot_c);
    char * check1 = "ft_list_foreach";
    char * check2 = "ft_list_size";
    char * check3 = "ft_list_remove_if";
	if (mkdir(header, 0777) == 0)
    {
        printf("\n\n%sDirectory %s was successfully created!%s", GREEN, header, RESET);
        chdir (header);
        fp = creat(header_c, 0777);

	    if (fp == -1)
            printf("%sI can't create file!\n%s", RED, RESET);
        else
        {
	        printf ("%s\nCreating a Maradeur\'s  Map%s", YELLOW, RESET);
	        mf = fopen (header_c, "w");
            free (header_c);

	        if (mf == NULL) 
                printf ("%s\nWRONG!\n%s", RED, RESET);
	        else 
                printf ("%s...\n%s", YELLOW, RESET);


	        fprintf(mf,"%s", fill);
	        printf("%sSucces! Map is created!\n\n", GREEN);

            if (strcmp(header, check1) == 0 || strcmp(header, check2) == 0 || strcmp(header, check3) == 0)
            {
                fp = creat("ft_list.h", 0777);
                mh = fopen ("ft_list.h", "w");
                fprintf(mh, "#ifndef FT_LIST_H\n# define FT_LIST_H\n\ntypedef struct	s_list\n{\n	struct s_list	*next;\n	void			*data;\n}				t_list;\n\n#endif\n");
                fclose (mh);
            }

	        fclose (mf);
	        printf ("Mischief managed!\n\n%s", RESET);
        }
    }
    else
    {
        printf("\n\n%sI can't create a directory!\n%s", RED, RESET);
    }
    return (0);
}

int main (int argc, char   **argv)
{
    char *password = "mischief";
    int level;
    int  number_of_task = 0;
    char **headers;
    char **text_arr;
    char *text;
    int counter_of_tasks = 0;
    int counter_of_prints = -1;
    char *name;

    if (argc != 2 || strcmp(argv[1], password) != 0)
        printf("permission denied: %s\n", argv[0]);
    else
    {
        printf("%s\n\n\t              _            _.,----,\n", PURPLE);
        printf("\t   __  _.-._ / \'-.        -  ,._  \\)\n") ;
        printf("\t  |  `-)_   \'-.   \\       / < _ )/\" }\n");
        printf("\t  /__    \'-.   \\   \'-, ___(c-(6)=(6)%s                                                Messrs. %sStranger%s and %sShadow%s, purveyors of aids\n", RED, BLUE, RED, BLUE, RED);
        printf("%s\t   , `\'.    `._ \'.  _,\'   >\\    \"  )%s                                               to magical mischief-makers, are proud to present\n", PURPLE, RED);
        printf("%s\t   :;;,,\'-._   \'---\' (  ( \"/`. -=\'/%s       pizdec jmihnulo\n", PURPLE, YELLOW);
        printf("%s\t  ;:;;:;;,  \'..__    ,`-.`)\'- \'--\'\n", PURPLE);
        printf("\t  ;\';:;;;;;\'-._ /\'._|   Y/   _/\' \\%s                                                               THE MARADEUR\'S MAP!\n", RED);
        printf("%s\t        \'\'\'\"._ F    |  _/ _.\'._   `\\                                                         NEW EXAM 42 IS COMING SOON!\n", PURPLE);
        printf("\t               L    \\   \\/     '._  \\\n");
        printf("\t        .-,-,_ |     `.  `\'---,  \\_ _|\n");
        printf("\t        //    \'L    /  \\,   (\"--\',=`)7\n");
        printf("\t       | `._       : _,  \\ /\'`-._L,_\'-._\n");
        printf("\t       \'--\' \'-.\\__/ _L   .`'         \'.//\n");
        printf("\t                   [ (  /\n");
        printf("\t                    ) `{\n");
        printf("\t                    \\__)\n\n\n%s", RESET);
        printf("Please, input your current level of exam:\n\n %s0%s - for level 00\n %s1%s - for level 01\n %s2%s - for level 02\n %s3%s - for level 03\n %s4%s - for level 04\n %s5%s - for level 05\n\n\nAnd your input is ", YELLOW, RESET, YELLOW, RESET, YELLOW, RESET, YELLOW, RESET, YELLOW, RESET, YELLOW, RESET);
        scanf("%d", &level);
        printf("\n\n");

        if (level == 0)
        {           
            headers = ft_split("aff_a~ft_countdown~ft_print_numbers~hello~maff_alpha~aff_first_param~aff_last_param~maff_revalpha~only_a~only_z~aff_z");
            
            counter_of_tasks = 10;
            while (counter_of_prints++ != counter_of_tasks)
                printf("%s%d.%s %s\n", YELLOW, counter_of_prints + 1, RESET, headers[counter_of_prints]);
            printf("\n\nAnd your input is ");
            scanf("%d", &number_of_task);    
            text_arr = ft_split("~#include <unistd.h>\n\nint		main(int argc, char **argv)\n{\n	if (argc != 2)\n		write(1, \"a\", 1);\n	else\n	{\n		while (*argv[1])\n		{\n			if (*argv[1] == 'a')\n			{\n				write(1, \"a\", 1);\n				break;\n			}\n			argv[1]++;\n		}\n	}\n	write(1, \"\\n\", 1);\n	return (0);\n}\n\n~#include <unistd.h>\n\nint		main(void)\n{\n	char c;\n\n	c = '9';\n	while (c >= '0')\n	{\n		write(1, &c, 1);\n		c--;\n	}\n	write(1, \"\\n\", 1);\n	return (0);\n}\n\n~#include <unistd.h>\n\nvoid    ft_print_numbers(void)\n{\n    char nb;\n\n    nb = '0';\n    while (nb <= '9')\n    {\n        write(1, &nb, 1);\n        nb++;\n    }\n}\n\n~#include <unistd.h>\n\nint		main(void)\n{\n	write(1, \"Hello World!\\n\", 13);\n	return (0);\n}\n\n~#include <unistd.h>\n\nint		main(void)\n{\n	write(1, \"aBcDeFgHiJkLmNoPqRsTuVwXyZ\\n\", 27);\n	return (0);\n}\n\n~#include <unistd.h>\n\nint		main(int ac, char **av)\n{\n	if (ac > 1)\n		while (*av[1])\n			write(1, av[1]++, 1);\n	write(1, \"\\n\", 1);\n	return (0);\n}\n\n~#include <unistd.h>\n\nint		main(int ac, char **av)\n{\n	if (ac > 1)\n		while (*av[ac - 1])\n			write(1, av[ac - 1]++, 1);\n	write(1, \"\\n\", 1);\n	return (0);\n}\n\n~#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n	write(1, &c, 1);\n}\n\nint		main(void)\n{\n	int i;\n\n	i = 123;\n	while (i-- > 97)\n		(i \\% 2 == 0) ? ft_putchar(i) : ft_putchar(i - 32);\n	ft_putchar('\\n');;\n	return (0);\n}\n\n~#include <unistd.h>\n\nint		main(void)\n{\n	write(1, \"a\", 1);\n	return (0);\n}\n\n~#include <unistd.h>\n\nint		main(void)\n{\n	write(1, \"z\", 1);\n	return (0);\n}\n\n~#include <unistd.h>\n\nint		main(void)\n{\n	write(1, \"z\", 1);\n	write(1, \"\\n\", 1);\n	return (0);\n}");
            text = text_arr[number_of_task - 1];
            name = headers[number_of_task - 1];
            opener(name, text);
        }
        else if (level == 1)
        {
            headers = ft_split("ft_strcpy~ft_strlen~repeat_alpha~search_and_replace~ulstr~rot13~first_word~ft_putstr~ft_swap~rev_print~rotone");

            counter_of_tasks = 10;
            while (counter_of_prints++ != counter_of_tasks)
                printf("%s%d.%s %s\n", YELLOW, counter_of_prints + 1, RESET, headers[counter_of_prints]);
            printf("\n\nAnd your input is ");
            scanf("%d", &number_of_task);
            text_arr = ft_split("\nchar    *ft_strcpy(char *s1, char *s2)\n{\n	int i;\n\n	i = 0;\n	while (s2[i])\n	{\n		s1[i] = s2[i];\n		i++;\n	}\n	s1[i] = s2[i];\n	return (s1);\n}\n~int		ft_strlen(char *str)\n{\n	int i;\n\n	i = 0;\n	while(str[i])\n		i++;\n	return (i);\n}\n~#include <unistd.h>\n\nint		letter_count(char c)\n{\n	int	repeat;\n\n	if (c >= \'A\' && c <= \'Z\')\n		repeat = c - \'A\' + 1;\n	else if (c >= \'a\' && c <= \'z\')\n		repeat = c - \'a\' + 1;\n	else\n		repeat = 1;\n	return (repeat);\n}\n\nint		main(int ac, char **av)\n{\n	int	repeat;\n\n	if (ac == 2)\n	{\n		while (*av[1])\n		{\n			repeat = letter_count(*av[1]);\n			while (repeat--)\n				write(1, av[1], 1);\n			av[1]++;\n		}\n	}\n	ft_putchar(\'\\n\');\n}\n~#include <unistd.h>\n\nint main(int argc, char **argv) {\n	int i;\n\n\n	if (argc != 4) {\n		write(1, \"\\n\", 1);\n		return 0;\n	}\n\n	\n	if (argv[2][1] != \'\\0\' || argv[1] != \'\\0\') {\n		write(1, \"\\n\", 1);\n		return 0;\n	}\n\n	\n	i = 0;\n	while (argv[1][i] != \'\\0\') {\n		if (argv[1][i] == argv[2])\n			argv[1][i] = argv;\n		write(1, &argv[1][i], 1);\n		i++;\n	}\n\n	write(1, \"\\n\", 1);\n	return 0;\n}\n~#include <unistd.h>\n\nint		main(int ac, char **av)\n{\n	if (ac == 2)\n	{\n		while (*av[1])\n		{\n			if (*av[1] >= \'A\' && *av[1] <= \'Z\')\n			{\n				*av[1] += 32;\n				write(1, av[1], 1);\n			}\n			else if (*av[1] >= \'a\' && *av[1] <= \'z\')\n			{\n				*av[1] -= 32;\n				write(1, av[1], 1);\n			}\n			av[1]++;\n		}\n	}\n	write(1, \"\\n\", 1);\n	return (1);\n}\n~#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n	write(1, &c, 1);\n}\n\n\nint		rot_13(char c)\n{\n	if ((c >= \'A\' && c <= \'M\') || (c >= \'a\' && c <= \'m\'))\n		c += 13;\n	else if ((c >= \'N\' && c <= \'Z\') || (c >= \'n\' && c <= \'z\'))\n		c -= 13;\n	return (c);\n}\n\n\n\nint	main(int ac, char **av)\n{\n	if (ac == 2)\n		while (*av[1])\n			ft_putchar(rot_13(*av[1]++));\n	ft_putchar(\'\\n\');\n	return (0);\n}\n~#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n	write(1, &c, 1);\n}\n\nint		main(int ac, char **av)\n{\n	int i;\n\n	i = 0;\n	if (ac == 2)\n	{\n		while (av[1][i] && (av[1][i] == \' \' || av[1][i] == \'\\t\'))\n			i++;\n		while (av[1][i] && (av[1][i] != \' \' && av[1][i] != \'\\t\'))\n		{\n			ft_putchar(av[1][i]);\n			i++;\n		}\n	}\n	ft_putchar(\'\\n\');\n	return (0);\n}\n~#include <unistd.h>\n\nvoid	ft_putstr(char *str)\n{\n	while (*str)\n		write(1, str++, 1);\n}\n~void	ft_swap(int	*a, int *b)\n{\n	int temp;\n\n	temp = *a;\n	*a = *b;\n	*b = temp;\n}\n~#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n	write(1, &c, 1);\n}\n\n\nint		ft_strlen(char *s)\n{\n	int i;\n\n	i = 0;\n	while (s[i])\n		i++;\n	return (i);\n}\n\n\nint		main(int ac, char **av)\n{\n	int len;\n\n	if (ac == 2)\n	{\n		len = ft_strlen(av[1]);\n		while (len--)\n			write(1, &av[1][len], 1);\n	}\n	ft_putchar(\'\\n\');\n}\n~#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n	write(1, &c, 1);\n}\n\nvoid	rotone(char *s)\n{\n	while (*s)\n	{\n		if ((*s >= \'A\' && *s <= \'Y\') || (*s >= \'a\' && *s <= \'y\'))\n			ft_putchar(*s + 1);\n		else if (*s == \'Z\' || *s == \'z\')\n			ft_putchar(*s - 25);\n		else\n			ft_putchar(*s);\n		++s;\n	}\n}\n\nint		main(int ac, char **av)\n{\n	if (ac == 2)\n		rotone(av[1]);\n	ft_putchar(\'\\n\');\n	return (0);\n}");    
            text = text_arr[number_of_task - 1];
            name = headers[number_of_task - 1];
            opener(name, text);
        }
        else if (level == 2)
        {
            headers = ft_split("ft_atoi~ft_strdup~inter~last_word~reverse_bits~swap_bits~union~alpha_mirror~max~wdmatch~do_op~print_bits~ft_strcmp~ft_strrev~is_power_of_2");
            
            counter_of_tasks = 14;
            while (counter_of_prints++ != counter_of_tasks)
                printf("%s%d.%s %s\n", YELLOW, counter_of_prints + 1, RESET, headers[counter_of_prints]);
            printf("\n\nAnd your input is ");
            scanf("%d", &number_of_task);
            text_arr = ft_split("#include <stdio.h> \n\nint		ft_atoi(char *s)\n{\n	int		sign;\n	long	r;\n\n	r = 0;\n	sign = 1;\n	while (*s == 32 || (*s >= 9 && *s <= 13))\n		s++;\n	if (*s == \'-\' || *s == \'+\')\n	{\n		if (*s == \'-\')\n			sign = -1;\n		s++;\n	}\n	while (*s >= \'0\' && *s <= \'9\')\n	{\n		r = r * 10 + *s - \'0\';\n		s++;\n	}\n	return (sign * (int)r);\n}\n~#include <stdlib.h>\n\nchar	*ft_strdup(char *src)\n{\n	char	*s;\n	int		len;\n\n	while (src[len])\n		++len;\n	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))\n		return (NULL);\n	s[len] = \'\\0\';\n	while (len >= 0)\n	{\n		s[len] = src[len];\n		len--;\n	}\n	return (s);\n}\n~#include <unistd.h>\n\nvoid solve(char *str1, char *str2) {\n    int i;\n    int j;\n    int ascii[256] = {0};\n\n    i = 0;\n    while (str2[i])\n    {\n        if (ascii[(int)str2[i]] == 0)\n            ascii[(int)str2[i]] = 1;\n        i++;\n    }\n\n    i = 0;\n    j = 0;\n    while (str1[i])\n    {\n        if (ascii[(int)str1[i]] == 1)\n        {\n            ascii[(int)str1[i]] = 2;\n            write(1, &str1[i], 1);\n        }\n        i++;\n    }\n\n}\n\nint	main(int argc, char **argv) {\n	if (argc == 3)\n		solve(argv[1], argv[2]);\n	write(1, \"\\n\", 1);\n	return 0;\n}\n~#include <unistd.h>\n\nint		ft_isblank(char c)\n{\n	if (c == \' \' || c == \'\t\')\n		return (1);\n	return (0);\n}\n\nint		main(int ac, char **av)\n{\n	if (ac == 2)\n	{\n		while (*av[1])\n			av[1]++;\n		av[1]--;\n		while (ft_isblank(*av[1]))\n			av[1]--;\n		while (*av[1] && !ft_isblank(*av[1]))\n			av[1]--;\n		av[1]++;\n		while (*av[1] && !ft_isblank(*av[1]))\n			write(1, av[1]++, 1);\n	}\n	write(1, \"\\n\", 1);\n	return (0);\n}\n~#include <unistd.h>\n\nunsigned char reverse_bits(unsigned char b)\n{\n	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;\n	b = (b & 0xCC) >> 2 | (b & 0x33) << 2;\n	b = (b & 0xAA) >> 1 | (b & 0x55) << 1;\n	return b;\n}\n~#include <unistd.h>\n\nunsigned char	swap_bits(unsigned char octet)\n{\n	return ((octet >> 4) | (octet << 4));\n}\n~#include <unistd.h>\n\nint		not_seen_before(char *s, int max_pos, char c)\n{\n	int i;\n\n	i = -1;\n	while (++i < max_pos)\n		if (s[i] == c)\n			return (0);\n	return (1);\n}\n\nvoid	ft_union(char *s1, char *s2)\n{\n	int	i;\n	int j;\n\n	i = -1;\n	while (s1[++i])\n		if (not_seen_before(s1, i, s1[i]))\n			write(1, &s1[i], 1);\n	j = -1;\n	while (s2[++j])\n		if (not_seen_before(s1, i, s2[j]) && not_seen_before(s2, j, s2[j]))\n			write(1, &s2[j], 1);\n}\n\nint		main(int ac, char **av)\n{\n	if (ac == 3)\n		ft_union(av[1], av[2]);\n	write(1, \"\\n\", 1);\n	return (0);\n}\n~#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n	write(1, &c, 1);\n}\n\nint		ft_isalpha(char c)\n{\n	if ((c >= \'a\' && c <= \'z\') || (c >= \'A\' && c <= \'Z\'))\n		return (1);\n	return (0);\n}\n\nint		ft_alpha_mirror(int c)\n{\n	return (c = (c >= \'A\' && c <= \'Z\') ? \'Z\' - (c - \'A\') : \'z\' - (c - \'a\'));\n}\n\nint		main(int ac, char **av)\n{\n	if (ac == 2)\n	{\n		while (*av[1])\n		{\n			if (ft_isalpha(*av[1]))\n				ft_putchar(ft_alpha_mirror(*(av[1]++)));\n			else\n				write(1, av[1]++, 1);\n		}\n	}\n	write(1, \"\\n\", 1);\n	return (1);\n}\n~#include <stdio.h>\n#include <stdlib.h>\n\nint		max(int *tab, unsigned int len)\n{\n	int	max;\n\n	if (!len)\n		return (0);\n	max = tab[--len];\n	while (len--)\n		if (tab[len] > max)\n			max = tab[len];\n	return (max);\n}\n~#include <unistd.h>\n\nvoid	wdmatch(char *s1, char *s2)\n{\n	int len = 0;\n	int i = 0;\n\n	while (s1[len])\n		++len;\n	while (*s2 && i < len)\n		(*s2++ == s1[i]) ? ++i : 0;\n	if (i == len)\n		write(1, s1, len);\n}\n\nint		main(int ac, char **av)\n{\n	if (ac == 3)\n		wdmatch(av[1], av[2]);\n	write(1, \"\\n\", 1);\n	return (0);\n}\n~#include <stdio.h>\n#include <stdlib.h>\n\nint		main(int argc, char **argv)\n{\n	if  (argc == 4)\n	{\n		if (*argv[2] == \'+\')\n			printf(\"\%d\", atoi(argv[1]) + atoi(argv));\n		else if (*argv[2] == \'-\')\n			printf(\"\%d\", atoi(argv[1]) - atoi(argv));\n		else if (*argv[2] == \'*\')\n			printf(\"\%d\", atoi(argv[1]) * atoi(argv));\n		else if (*argv[2] == \'/\')\n			printf(\"\%d\", atoi(argv[1]) / atoi(argv));\n		else if (*argv[2] == \'\%\')\n			printf(\"\%d\", atoi(argv[1]) \% atoi(argv));\n	}\n	printf(\"\\n\");\n	return (0);\n}\n~void	print_bits(unsigned char octet)\n{\n	int	i;\n\n	i = 128;\n	while (octet >= 0 && i)\n	{\n		(octet / i) ? write(1, \"1\", 1) : write(1, \"0\", 1);\n		(octet / i) ? octet -= i : 0;\n		i /= 2;\n	}\n}\n~int	ft_strcmp(char *s1, char *s2)\n{\n	int i;\n\n	i = 0;\n	while (s1[i] == s2[i] && s1[i] != \'\\0\' && s2[i] != \'\\0\')\n		i++;\n	return (s1[i] - s2[i]);\n}\n~char	*ft_strrev(char *str)\n{\n	int		count;\n	int		i;\n	char	c;\n\n	count = 0;\n	while (str[count] != \'\\0\')\n		count++;\n	count = count - 1;\n	i = 0;\n	while (i < ((count + 1) / 2))\n	{\n		c = str[i];\n		str[i] = str[count - i];\n		str[count - i] = c;\n		i++;\n	}\n	return (str);\n}\n~int		is_power_of_2(unsigned int n)\n{\n	if (n == 0)\n		return (0);\n	while (n \% 2 == 0) \n		n /= 2;\n	return ((n == 1) ? 1 : 0);\n}\n");
            text = text_arr[number_of_task - 1];
            name = headers[number_of_task - 1];
            opener(name, text);
        }
        else if (level == 3)
        {
            headers = ft_split("add_prime_sum~epur_str~ft_list_size~ft_rrange~hidenp~pgcd~print_hex~rstr_capitalizer~expand_str~lcm~tab_mult~ft_atoi_base~ft_range~paramsum~str_capitalizer");
            
            counter_of_tasks = 14;
            while (counter_of_prints++ != counter_of_tasks)
                printf("%s%d.%s %s\n", YELLOW, counter_of_prints + 1, RESET, headers[counter_of_prints]);
            printf("\n\nAnd your input is ");
            scanf("%d", &number_of_task);
            text_arr = ft_split("#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n    	write(1, &c, 1);\n}\nvoid	ft_putposnbr(int n)\n{\n    	if (n > 9)\n		ft_putposnbr(n / 10);\n	ft_putchar(n \% 10 + \'0\');\n}\nint		ft_atoi_nc(char *s)\n{\n    	int		r;\n	r = 0;\n	while (*s >= \'0\' && *s <= \'9\')\n		r = r * 10 + *s++ - \'0\';\n	return (r);\n}\nint is_prime(int n)\n{\n    	int i;\n	i = 2;\n	while (i < n)\n		if (!(n \% i++))\n			return (0);\n	return (1);\n}\nvoid	add_prime_sum(int n)\n{\n    	int	i;\n	int	count;\n	count = 0;\n	if (n == 1)\n		count = 1;\n	i = 1;\n	while (++i <= n)\n		if (is_prime(i))\n			count += i;\n	ft_putposnbr(count);\n}\nint		main(int ac, char **av)\n{\n    	if (ac == 2 && ft_atoi_nc(av[1]) > 0)\n		add_prime_sum(ft_atoi_nc(av[1]));\n	else\n		write(1, \"0\", 1);\n	write(1, \"\\n\", 1);\n	return (1);\n}\n~#include <unistd.h>\n\nint		ft_strlen(char *s)\n{\n    	int i;\n	i = 0;\n	while (s[i])\n		i++;\n	return (i);\n}\nint		ft_isblank(char c)\n{\n    	if (c == \' \' || c == \'\\t\')\n		return (1);\n	if (c >= 9 && c <= 13)\n		return (1);\n	return (0);\n}\nvoid	epurstr(char *s)\n{\n    	int len = ft_strlen(s);\n	while (len && ft_isblank(s[len - 1]))\n		--len;\n	while (len && ft_isblank(*s) && *s++)\n		--len;\n	while (len--)\n	{\n    		if (!ft_isblank(*s) || (*(s + 1) && !ft_isblank(*(s + 1))))\n			write(1, s, 1);\n		s++;\n	}\n}\nint		main(int ac, char **av)\n{\n    	if (ac == 2 && *av[1])\n		epurstr(av[1]);\n	write(1, \"\\n\", 1);\n	return (0);\n}\n~#include \"ft_list.h\"\n\nint	ft_list_size(t_list *begin_list)\n{\n    	t_list	*list;\n	int		i;\n	i = 0;\n	list = begin_list;\n	while (list)\n	{\n    		i++;\n		list = list->next;\n	}\n	return (i);\n}\n~#include <stdlib.h>\n\nint     *ft_rrange(int start, int end)\n{\n    	int	*r;\n	int	len;\n	len = (end >= start) ? end - start + 1 : start - end + 1;\n	if (!(r = (int*)malloc(sizeof(int) * len)))\n		return (NULL);\n	 while (len--)\n		 r[len] = (end >= start) ? start++ : start--;\n	return (r);\n}\n~#include <unistd.h>\n\nvoid	hidenp(char *s1, char *s2)\n{\n    	while (*s2)\n		if (*s1 == *s2++)\n			s1++;\n	(*s1 == \'\\0\') ? write(1, \"1\", 1) : write(1, \"0\", 1);\n}\nint	main(int argc, char **argv)\n{\n    	if (argc == 3)\n		hidenp(argv[1], argv[2]);\n	write(1, \"\\n\", 1);\n	return (0);\n}\n~#include <stdio.h>\n#include <stdlib.h>\n\nint		pgcd(unsigned int nb, unsigned int nb2)\n{\n    	int i;\n	i = nb;\n	while (i > 0)\n	{\n    		if (nb \% i == 0 && nb2 \% i == 0)\n			return (i);\n		i--;\n	}\n	return (1);\n}\nint	main(int argc, char **argv)\n{\n    	if (argc == 3)\n		printf(\"\%d\", pgcd(atoi(argv[1]), atoi(argv[2])));\n	printf(\"\\n\");\n	return (0);\n}\n~#include <unistd.h>\n\nint		ft_atoi(char *s)\n{\n    	long	r;\n	int		sign;\n	while (*s == 32 || (*s >= 9 && *s <= 13))\n		s++;\n	sign = (*s == \'-\') ? -1 : 1;\n	(*s == \'-\' || *s == \'+\') ? s++ : s;\n	r = 0;\n	while (*s >= \'0\' && *s <= \'9\')\n		r = r * 10 + *s++ - \'0\';\n	return ((int)r * sign);\n}\nvoid	print_hex(int n)\n{\n    	if (n >= 16)\n		print_hex(n / 16);\n	n = n \% 16;\n	n += n < 10 ? \'0\' : \'a\' - 10;\n	write(1, &n, 1);\n}\nint		main(int ac, char **av)\n{\n    	if (ac == 2)\n		print_hex(ft_atoi(av[1]));\n	write(1, \"\\n\", 1);\n	return (1);\n}\n~#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n    	write(1, &c, 1);\n}\nvoid	rstr_capitalizer(int argc, char **argv)\n{\n    	int i;\n	int j;\n	i = 1;\n	j = 0;\n	while (i < argc)\n	{\n    		j = 0;\n		while (argv[i][j] != \'\\0\')\n		{\n    			if (argv[i][j] >= \'A\' && argv[i][j] <= \'Z\' )\n				argv[i][j] += 32;\n			if (argv[i][j + 1] == \' \' || argv[i][j + 1] == \'\\t\' || argv[i][j + 1] == \'\\0\')\n			{\n    				if (argv[i][j] >= \'a\' && argv[i][j] <= \'z\')\n					argv[i][j] -= 32;\n			}\n			ft_putchar(argv[i][j]);\n			j++;\n		}\n		ft_putchar(\'\\n\');\n		i++;\n	}\n}\nint		main(int argc, char **argv)\n{\n    	if (argc > 1)\n		rstr_capitalizer(argc, argv);\n	else\n		ft_putchar(\'\\n\');\n	return (0);\n}\n~#include <unistd.h>\n\nint		ft_isblank(char c)\n{\n    	return ((c == \' \' || c == \'\\t\') ? 1 : 0);\n}\nvoid	expand_str(char *s)\n{\n    	int	i = 0;\n	int	wc = 0;\n	while (s[i])\n		if (!ft_isblank(s[i++]) && (!wc || ft_isblank(s[i - 2])))\n			++wc;\n	i = 0;\n	while (s[i])\n	{\n    		if (!ft_isblank(s[i++]) && wc--)\n		{\n    			write (1, &s[i - 1], 1);\n			while (s[i] && !ft_isblank(s[i]) && write(1, &s[i++], 1));\n			(wc) ? write(1, \"   \", 3) : 0;\n		}\n	}\n}\nint		main(int ac, char **av)\n{\n    	if (ac == 2)\n		expand_str(av[1]);\n	write(1, \"\\n\", 1);\n}\n \n~unsigned int    lcm(unsigned int a, unsigned int b)\n{\n        unsigned int    d;\n    if (!a || !b)\n        return (0);\n    if (a > b)\n        d = (a / 2) + 1;\n    else\n        d = (b / 2) + 1;\n    while (!((a \% d) == 0 && (b \% d) == 0))\n        d--;\n    return (a * b / d);\n}\n~#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n    	write(1, &c, 1);\n}\nvoid	ft_putposnbr(int n)\n{\n    	if (n > 9)\n		ft_putposnbr(n / 10);\n	ft_putchar(n \% 10 + \'0\');\n}\nint		ft_atoi_osefvalid(char *s)\n{\n    	int		r;\n	r = 0;\n	while (*s >= \'0\' && *s <= \'9\')\n		r = r * 10 + *s++ - \'0\';\n	return (r);\n}\nvoid	tab_mult(int n)\n{\n    	int i = 1;\n	while (i < 10)\n	{\n    		ft_putposnbr(i);\n		write(1,\" x \", 3);\n		ft_putposnbr(n);\n		write(1, \" = \", 3);\n		ft_putposnbr(i++ * n);\n		write(1, \"\\n\", 1);\n	}\n}\nint		main(int ac, char **av)\n{\n    	if (ac == 2)\n		tab_mult(ft_atoi_osefvalid(av[1]));\n	else\n		write(1, \"\\n\", 1);\n	return (0);\n}\n~int isblank(char c)\n{\n    	if (c <= 32)\n		return (1);\n	return (0);\n}\nint		isvalid(char c, int base)\n{\n    	char digits[17] = \"0123456789abcdef\";\n	char digits2[17] = \"0123456789ABCDEF\";\n	while (base--)\n		if (digits[base] == c || digits2[base] == c)\n			return (1);\n	return (0);\n}\nint		value_of(char c)\n{\n    	if (c >= \'0\' && c <= \'9\')\n		return (c - \'0\');\n	else if (c >= \'a\' && c <= \'f\')\n		return (c - \'a\' + 10);\n	else if (c >= \'A\' && c <= \'F\')\n		return (c - \'A\' + 10);\n	return (0);\n}\nint		ft_atoi_base(const char *str, int str_base)\n{\n    	int result;\n	int sign;\n	result = 0;\n	while (isblank(*str))\n		str++;\n	sign = (*str == \'-\') ? -1 : 1;\n	(*str == \'-\' || *str == \'+\') ? ++str : 0;\n	while (isvalid(*str, str_base))\n		result = result * str_base + value_of(*str++);\n	return (result * sign);\n}\n~#include <stdlib.h>\n\nint		*ft_range(int min, int max)\n{\n    	int		n;\n	int		*s;\n	n = max >= min ? max - min : min - max;\n	if (!(s = (int *)malloc(sizeof(int) * (n))))\n		return (NULL);\n	while (max != min)\n		*s++ = max > min ? min++ : min--;\n	*s = min;\n	return (s - n);\n}\n~#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n    	write(1, &c, 1);\n}\nvoid	ft_putnbr(int n)\n{\n    	if (n > 9)\n		ft_putnbr(n / 10);\n	ft_putchar(n \% 10 +\'0\');\n}\nint		main(int ac, char **av)\n{\n    	av = 0;\n	ft_putnbr(ac - 1);\n	write(1, \"\\n\", 1);\n}\n~#include <unistd.h>\n\nvoid	ft_putchar(char c)\n{\n    	write(1, &c, 1);\n}\nint		ft_isspace(char c)\n{\n    	if (c == \' \' || c == \'\\t\')\n		return (1);\n	return (0);\n}\nint		tolower(char c)\n{\n    	return (c += (c >= \'A\' && c <= \'Z\') ? 32 : 0);\n}\nint		toupper(char c)\n{\n    	return (c -= (c >= \'a\' && c <= \'z\') ? 32 : 0);\n}\nvoid	str_capitaliser(char *s)\n{\n    	while (*s)\n	{\n    		while (ft_isspace(*s))\n			ft_putchar(*s++);\n		if (*s && !ft_isspace(*s))\n			ft_putchar(toupper(*s++));\n		while (*s && !ft_isspace(*s))\n			ft_putchar(tolower(*s++));\n	}\n}\nint		main(int ac, char **av)\n{\n    	if (ac > 1)\n	{\n    		++av;\n		while (*av)\n		{\n    			str_capitaliser(*av++);\n			write(1, \"\\n\", 1);\n		}\n	}\n	return (0);\n}");
            text = text_arr[number_of_task - 1];
            name = headers[number_of_task - 1];
            opener(name, text);
        }
        else if (level == 4)
        {
            headers = ft_split("ft_list_remove_if~sort_list~ft_itoa~ft_itoa_base~brainfuck~flood_fill~fprime~ft_list_foreach~ft_split~rev_wstr~rostring~sort_int_tab");
            
            counter_of_tasks = 11;
            while (counter_of_prints++ != counter_of_tasks)
                printf("%s%d.%s %s\n", YELLOW, counter_of_prints + 1, RESET, headers[counter_of_prints]);
            printf("\n\nAnd your input is ");
            scanf("%d", &number_of_task);
            text_arr = ft_split("#include <stdlib.h>\n#include \"ft_list.h\"\n\nvoid	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())\n{\n    	t_list	*curr;\n	t_list	*tmp;\n\n	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)\n	{\n    		curr = *begin_list;\n		*begin_list = (*begin_list)->next;\n		free(curr);\n	}\n	curr = *begin_list;\n	while (curr && curr->next)\n	{\n    		if (cmp(curr->next->data, data_ref) == 0)\n		{\n    			tmp = curr->next;\n			curr->next = tmp->next;\n			free(tmp);\n		}\n		curr = curr->next;\n	}\n}\n~#include <stdlib.h>\n#include <stdio.h>\n#include \"list.h\"\n\nvoid	swap(int *a, int *b)\n{\n    	int	tmp;\n\n	tmp = *a;\n	*a = *b;\n	*b = tmp;\n}\n\n\nint		ascending(int a, int b)\n{\n    		return (a <= b);\n}\n\nt_list		*sort_list(t_list* lst, int (*cmp)(int, int))\n{\n    	t_list	*begin;\n	t_list	*p;\n\n	begin = lst;\n	while (lst)\n	{\n    		p = lst->next;\n		while (p)\n		{\n    			if (!(*cmp)(lst->data, p->data))\n			{\n    				swap(&lst->data, &p->data);\n			}\n			p = p->next;\n		}\n		lst = lst->next;\n	}\n	return (begin);\n}\n~#include <stdlib.h>\n\nstatic int	ft_strlen(const char *s)\n{\n    	int i;\n\n	i = 0;\n	while (s[i])\n		i++;\n	return i;\n}\n\nstatic char	*ft_strrev(char *str)\n{\n    	int i;\n	int j;\n	int tmp;\n\n	i = 0;\n	j = ft_strlen(str);\n	while (j > i)\n	{\n    		j--;\n		tmp = str[i];\n		str[i] = str[j];\n		str[j] = tmp;\n		i++;\n	}\n	return str;\n}\n\nchar	*ft_itoa(int nbr)\n{\n    	int i;\n	int neg;\n	char *tmp;\n\n	i = 0;\n	neg = 0;\n	tmp = malloc(sizeof(char) * 12);\n	if (tmp == NULL || nbr == 0)\n		return ((nbr == 0) ? \"0\" : NULL);\n	if (nbr == -2147483648)\n		return (\"-2147483648\");\n	if (nbr < 0)\n	{\n    		neg = 1;\n		nbr *= -1;\n	}\n	while (nbr)\n	{\n    		tmp[i++] = (nbr \% 10) + \'0\';\n		nbr /= 10;\n	}\n	if (neg)\n		tmp[i] = \'-\';\n	return ft_strrev(tmp);\n}\n~#include <stdlib.h>\n\nchar	*ft_itoa_base(int value, int base)\n{\n    	char	*s;\n	long	n;\n	int		sign;\n	int		i;\n\n	n = (value < 0) ? -(long)value : value;\n	sign = (value < 0 && base == 10) ? -1 : 0;\n	i = (sign == -1) ? 2 : 1;\n	while ((n /= base) >= 1)\n		i++;\n	s = (char*)malloc(sizeof(char) * (i + 1));\n	s[i] = \'\\0\';\n	n = (value < 0) ? -(long)value : value;\n	while (i-- + sign)\n	{\n    		s[i] = (n \% base < 10) ? n \% base + \'0\' : n \% base + \'A\' - 10;\n		n /= base;\n	}\n	(i == 0) ? s[i] = \'-\' : 0;\n	return (s);\n}\n~#include <unistd.h>\n\nint		go_to_matching(char *operations, int curr)\n{\n    	int balance = 0;\n\n	if (operations[curr] == \'[\')\n	{\n    		curr++;\n		while (!(operations[curr] == \']\' && balance == 0))\n		{\n    			if (operations[curr] == \'[\')\n				balance++;\n			else if (operations[curr] == \']\')\n				balance--;\n			curr++;\n		}\n		curr--;\n	}\n	else if (operations[curr] == \']\')\n	{\n    		curr--;\n		while (!(operations[curr] == \'[\' && balance == 0))\n		{\n    			if (operations[curr] == \']\')\n				balance++;\n			else if (operations[curr] == \'[\')\n				balance--;\n			curr--;\n		}\n		curr--;\n	}\n	return (curr);\n}\n\nvoid	fuck_brain(char *operations)\n{\n    	int curr = 0;\n	int pointer = 0;\n	char bytes[2048];\n\n	while (curr < 2048)\n		bytes[curr++] = 0;\n\n	curr = 0;\n	while (operations[curr])\n	{\n    		if (operations[curr] == \'>\')\n			pointer++;\n		else if (operations[curr] == \'<\')\n			pointer--;\n		else if (operations[curr] == \'+\')\n			bytes[pointer]++;\n		else if (operations[curr] == \'-\')\n			bytes[pointer]--;\n		else if (operations[curr] == \'.\')\n			write(1, &bytes[pointer], 1);\n		else if (operations[curr] == \'[\')\n		{\n    			if (bytes[pointer] == 0)\n				curr = go_to_matching(operations, curr);\n		}\n		else if (operations[curr] == \']\')\n		{\n    			if (bytes[pointer] != 0)\n				curr = go_to_matching(operations, curr);\n		}\n		curr++;\n	}\n}\n\nint		main(int ac, char **av)\n{\n    	if (ac == 2)\n		fuck_brain(av[1]);\n	else\n		write(1, \"\\n\", 1);\n	return (0);\n}\n~typedef struct	s_point\n{\n    	int			x;\n	int			y;\n}				t_point;\n\nvoid flood_fill(char **tab, t_point size, t_point begin)\n{\n    	char	c;\n\n	c = tab[begin.y][begin.x];\n	tab[begin.y][begin.x] = \'F\';\n	if ((begin.x + 1 < size.x) && (tab[begin.y][begin.x + 1] == c))\n		flood_fill(tab, size, (t_point){begin.x + 1, begin.y});\n	if (begin.x > 0 && (tab[begin.y][begin.x - 1] == c))\n		flood_fill(tab, size, (t_point){begin.x - 1, begin.y});\n	if ((begin.y + 1 < size.y) && (tab[begin.y + 1][begin.x] == c))\n		flood_fill(tab, size, (t_point){begin.x, begin.y + 1});\n	if (begin.y > 0 && (tab[begin.y - 1][begin.x] == c))\n		flood_fill(tab, size, (t_point){begin.x, begin.y - 1});\n}\n~#include <stdlib.h>\n#include <stdio.h>\n\nvoid	fprime(unsigned int nb)\n{\n    	unsigned int	prime;\n\n	if (nb == 1)\n		printf(\"1\");\n	else\n	{\n    		prime = 2;\n		while (nb > 1)\n		{\n    			if (nb \% prime == 0)\n			{\n    				printf(\"\%d\", prime);\n				nb /= prime;\n				if (nb > 1)\n					printf(\"*\");\n				prime--;\n			}\n			prime++;\n		}\n	}\n}\n\nint		main(int ac, char **av)\n{\n    	if (ac == 2 && *av[1])\n		fprime(atoi(av[1]));\n	printf(\"\\n\");\n	return (0);\n}\n~#include \"ft_list.h\"\n\nvoid	ft_list_foreach(t_list *begin_list, void (*f)(void *))\n{\n    	t_list	*curr;\n\n	curr = begin_list;\n	while (curr)\n	{\n    		(*f)(curr->data);\n		curr = curr->next;\n	}\n}\n~#include <stdlib.h>\n\nint			ft_isspace(char c)\n{\n    	return (c == \' \' || c == \'\\n\' || c == \'\\t\');\n}\n\nint		count_words(char *str)\n{\n    	int	count;\n\n	count = 0;\n	while (*str)\n	{\n    		while (*str && ft_isspace(*str))\n			str++;\n		if (*str && !ft_isspace(*str))\n		{\n    			count++;\n			while (*str && !ft_isspace(*str))\n				str++;\n		}\n	}\n	return (count);\n}\n\nchar	*malloc_word(char *str)\n{\n    	char *word;\n	int	i;\n\n	i = 0;\n	while (str[i] && !ft_isspace(str[i]))\n		i++;\n	word = (char *)malloc(sizeof(char) * (i + 1));\n	i = 0;\n	while (str[i] && !ft_isspace(str[i]))\n	{\n    		word[i] = str[i];\n		i++;\n	}\n	word[i] = \'\\0\';\n	return (word);\n}\n\nchar	**ft_split(char *str)\n{\n    	char **arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));\n	int i = 0;\n	while (*str)\n	{\n    		while (*str && ft_isspace(*str))\n			str++;\n		if (*str && !ft_isspace(*str))\n		{\n    			arr[i] = malloc_word(str);\n			i++;\n			while (*str && !ft_isspace(*str))\n				str++;\n		}\n	}\n	arr[i] = NULL;\n	return (arr);\n}\n~#include <unistd.h>\n\nint		str_length(char *str)\n{\n    	int	len = 0;\n\n	while (*str)\n	{\n    		str++;\n		len++;\n	}\n	return (len);\n}\n\nint		iswhitespace(char chr)\n{\n    	return (chr == \' \' || chr == \'\\t\');\n}\n\nvoid	print_reverse(char *str)\n{\n    	int fast;\n	int slow;\n	int curr;\n\n	fast = str_length(str) - 1;\n	slow = fast;\n	curr = fast;\n\n	while (fast >= 0)\n	{\n    		slow = fast;\n		curr = fast;\n		while (fast >= 0 && !iswhitespace(str[fast]))\n			fast--;\n		fast++;\n		curr = fast;\n		while (curr <= slow)\n		{\n    			write(1, &str[curr], 1);\n			curr++;\n		}\n		if (fast > 0)\n			write(1, \" \", 1);\n		fast--;\n		fast--;\n}\n}\nint		main(int ac, char **av)\n{\n    	if (ac == 2)\n		print_reverse(av[1]);\n	write(1, \"\\n\", 1);\n	return (1);\n}\n~#include <unistd.h>\n\nint		ft_isblank(char c)\n{\n    	return (c == \' \' || c == \'\\t\');\n}\n\nvoid	rostring(char *s)\n{\n    	int		i = 0;\n	int		first_word_length = 0;\n\n	while (s[i])\n	{\n    		while (ft_isblank(s[i]))\n			i++;\n		if (s[i] && !ft_isblank(s[i]))\n		{\n    			if (first_word_length == 0)\n				while (s[i] && !ft_isblank(s[i++]))\n					first_word_length++;\n			else\n			{\n    				while (s[i] && !ft_isblank(s[i]) && write(1, &s[i++], 1));\n				write(1, \" \", 1);\n			}\n		}\n	}\n\n	i = 0;\n	while (ft_isblank(s[i]))\n		i++;\n	while (first_word_length--)\n		write(1, &s[i++], 1);\n}\n\nint		main(int ac, char **av)\n{\n    	if (ac > 1 && *av[1])\n		rostring(av[1]);\n	write(1, \"\\n\", 1);\n	return (0);\n}\n~void	swap_elements(int *tab, unsigned int p1, unsigned int p2)\n{\n    	int tmp = tab[p1];\n	tab[p1] = tab[p2];\n	tab[p2] = tmp;\n}\n\nvoid	bubble_sort(int *tab, unsigned int size)\n{\n    	unsigned int i = 0;\n	unsigned int j = 0;\n\n	while (i < size)\n	{\n    		j = 0;\n		while (j < size - 1)\n		{\n    			if (tab[j] > tab[j + 1])\n				swap_elements(tab, j, j + 1);\n			j++;\n		}\n		i++;\n	}\n}\n\nvoid	sort_int_tab(int *tab, unsigned int size)\n{\n    	if (size <= 1)\n		return ;\n	bubble_sort(tab, size);\n}\n");
            name = headers[number_of_task - 1];
            text = text_arr[number_of_task - 1];
            opener(name, text);
        }
        else if (level == 5)
        {
            headers = ft_split("check_mate~print_memory~brackets~rpn_calc~options~cycle_detector~biggest_pal");
            printf("\n\nAttention! Some of tasks can be failed, please check it rigorously\nCompile it with main.c before pushing\n");
            printf("Peak %sprint_memory%s, %srpn_calc%s, %soptions%s or %scycle-detector%s - this tasks won't be failed 100\n\n", RED, RESET, RED, RESET, RED, RESET, RED, RESET);
            
            counter_of_tasks = 6;
            while (counter_of_prints++ != counter_of_tasks)
                printf("%s%d.%s %s\n", YELLOW, counter_of_prints + 1, RESET, headers[counter_of_prints]);
            printf("\n\nAnd your input is ");
            scanf("%d", &number_of_task);
            text_arr = ft_split("#include <stdlib.h>\n#include <unistd.h>\n\nint		checkmate(int ac, char **av)\n{\n	int		y = 0;\n	int		x = 0;\n	int		len = 0;\n	int		b = 0;\n	int		a = 0;\n	char	**m;\n\n	while (ac-- > 1)\n		len++;\n	if (!(m = (char **)malloc(sizeof(char *) * len * (len + 1))))\n		return (0);\n	y = 0;\n	while (y < len)\n	{\n		if (!(m[y] = (char *)malloc(sizeof(char) * (len + 1))))\n			return (0);\n		x = 0;\n		while (av[y + 1][x])\n		{\n			m[y][x] = av[y + 1][x];\n			if (m[y][x] == \'K\')\n			{\n				a = x;\n				b = y;\n			}\n			++x;\n		}\n		m[y][x] = 0;\n		++y;\n	}\n\n	if (m[b + 1][a + 1] == \'P\' || m[b + 1][a - 1] == \'P\')\n		return (0);\n\n	int		i = 0;\n	while (i < len)\n	{\n		if (m[b][i] == \'Q\' || m[i][a] == \'Q\' || m[b][i] == \'R\' || m[i][a] == \'R\')\n			return (0);\n		if (i < b)\n		{\n			if (i < a && (m[b - i - 1][a - i - 1] == \'B\' || m[b - i - 1][a - i - 1] == \'Q\') )\n				return (0);\n			if (a + i < len && (m[b - i - 1][a + i + 1] == \'B\' || m[b - i - 1][a + i + 1] == \'Q\'))\n				return (0);\n		}\n		if (b + i < len)\n		{\n			if (i < a && (m[b + i + 1] [a - i - 1] == \'B\' || m[b + i + 1] [a - i - 1] == \'Q\'))\n				return (0);\n			if (a + i < len && (m[b + i + 1] [a + i + 1] == \'B\' || m[b + i + 1] [a + i + 1] == \'Q\' ))\n				return (0);\n		}\n		i++;\n	}\n	return (1);\n}\n\n\nvoid	print(int ac, char **av)\n{	\n	int		len;\n	int		x;\n	int		y;\n	char	**m;\n\n	while (ac-- > 1)\n		len++;\n	if (!(m = (char **)malloc(sizeof(char *) * len * (len + 1))))\n		return ;\n	y = 0;\n	while (y < len)\n	{\n		if (!(m[y] = (char *)malloc(sizeof(char) * (len + 1))))\n			return ;\n		x = 0;\n		while (av[y + 1][x])\n		{\n			m[y][x] = av[y + 1][x];\n			++x;\n		}\n		m[y][x] = 0;\n		++y;\n	}\n	y = 0;\n	while (y < len)\n	{\n		write(1, m[y++], len);\n		write(1, \"\\n\", 1);\n	}\n}\n\n\nint		main(int ac, char **av)\n{\n	if (ac > 1 && checkmate(ac, av))\n		write(1, \"Success\\n\", 8);\n	else\n		write(1, \"Fail\\n\", 5);\n	print(ac, av);\n	return (0);\n}\n91939~#include <unistd.h>\n#include <stdio.h>\n\nvoid\tft_putchar(char c)\n{\n\twrite(1, &c, 1);\n}\n\nvoid\tft_putasci(unsigned char c)  \n{\n\tif (c >= 32 && c < 127)\n\t\tft_putchar(c);\n\telse\n\t\tft_putchar(\'.\');\n}\n\nvoid \tft_puthex(unsigned char c)  \n{\n\tchar tab[16] = \"0123456789abcdef\";\n\n\tft_putchar(tab[c / 16]);\n\tft_putchar(tab[c \% 16]);\n}\n\nvoid\tft_printline(unsigned char *temp, size_t start, size_t max) \n{\n\tsize_t\ti;\n\n\ti = start;\n\twhile (i < (start + 16) && i < max)  \n\t{\n\t\tft_puthex(temp[i]);\n\t\tif (i \% 2 != 0)\n\t\t\tft_putchar(\' \');\n\t\ti++;\n\t}\n\twhile (i < (start + 16))\n\t{\n\t\tft_putchar(\' \');\n\t\tft_putchar(\' \');\n\t\tif (i \% 2 != 0)\n\t\t\tft_putchar(\' \');\n\t\ti++;\n\t}\n\ti = start;\n\twhile (i < (start + 16) && i < max)  \n\t{\n\t\tft_putasci(temp[i]);\n\t\ti++;\n\t}\n\tft_putchar(\'\\n\');\n}\n\nvoid\tprint_memory(const void *addr, size_t size)\n{\n\tunsigned char  *temp;\n\tsize_t\t\t\ti;\n\n\ttemp = (unsigned char *)addr;\n\ti = 0;\n\twhile (i < size)\n\t{\n\t\tft_printline(temp, i, size);\n\t\ti = i + 16;\n\t}\n}~91939#include <unistd.h>\n\nint	braclose(char *str, char c, int i, int b)\n{\n	while (b && *(++str) && (i++))\n		if (*str == c || *str == c + c \% 2 + 1)\n			*str == c ? ++b : --b;\n	return (i);\n}\n\nint	brackets(char *str, char c)\n{\n	if (*str == c)\n		return (1);\n	else if (!*str || *str == \')\' || *str == \'}\' || *str == \']\')\n		return (0);\n	else if (*str == \'(\' || *str == \'{\' || *str == \'[\')\n		return (brackets(str + 1, *str + *str \% 2 + 1)\n			* brackets(str + braclose(str, *str, 1, 1), c));\n	else\n		return (brackets(str + 1, c));\n}\n\nint	main(int ac, char **av)\n{\n	int	i;\n\n	i = 0;\n	if (ac > 1)\n		while (++i < ac)\n			brackets(av[i], 0) ? write(1, \"OK\\n\", 3) : write(1, \"Error\\n\", 6);\n	else\n		write(1, \"\\n\", 1);\n	return (0);\n}\n~#include <stdio.h>\n#include <stdlib.h>\n#include <limits.h>\n\nint		ft_strlen(char *str)\n{\n	int		i;\n\n	i = 0;\n	while (str[i] != \'\\0\')\n		i++;\n	return (i);\n}\n\nint		ft_isdigit(char c)\n{\n	if (c >= \'0\' && c <= \'9\')\n		return (1);\n	return (0);\n}\n\nint		is_operateur(char *str)\n{\n	int		i;\n\n	i = 0;\n	if (str[i] == \'*\' || str[i] == \'+\' || str[i] == \'-\' || str[i] == \'\%\' || str[i] == \'/\')\n	{\n		if (ft_isdigit(str[i + 1]) == 0)\n			return (1);\n	}\n	return (0);\n}\n\nlong		*rpn_calc(char *str)\n{\n	long	*tab;\n	int		i;\n	int		j;\n		\n	i = 0;\n	j = 0;\n	if (!(tab = (long*)malloc(sizeof(long) * ft_strlen(str))))\n		return (NULL);\n	while (str[i] != \'\\0\')\n	{\n		while (is_operateur(str + i) == 0)\n		{\n			tab[j] = atoi(str + i);\n			j++;\n			while (str[i] != \'\\0\' && str[i] != \' \')\n				i++;\n			if (str[i] == \'\\0\')\n			{\n				printf(\"Error\\n\");\n				return (NULL);\n			}\n			while (str[i] == \' \')\n				i++;\n		}\n		if (j < 2)\n		{\n			printf(\"Error\\n\");\n			return (NULL);\n		}\n		if (str[i] == \'/\')\n		{\n			if (tab[j - 1] == 0)\n			{\n				printf(\"Error\\n\");\n				return (NULL);\n			}\n			tab[j - 2] = tab[j - 2] / tab[j - 1];\n		}\n		else if (str[i] == \'-\')\n			tab[j - 2] = tab[j - 2] - tab[j - 1];\n		else if (str[i] == \'+\')\n			tab[j - 2] = tab[j - 2] + tab[j - 1];\n		else if (str[i] == \'*\')\n			tab[j - 2] = tab[j - 2] * tab[j - 1];\n		else if (str[i] == \'\%\')\n		{\n			if (tab[j - 1] == 0)\n			{\n				printf(\"Error\\n\");\n				return (NULL);\n			}\n			tab[j - 2] = tab[j - 2] \% tab[j - 1];\n		}\n		j--;\n		i++;\n		while (str[i] == \' \')\n			i++;\n	}\n	if (j > 1)\n	{\n		printf(\"Error\\n\");\n		return (NULL);\n	}\n	return (tab);\n}\n\nint		main(int argc, char **argv)\n{\n	long	*tab;\n\n	if (argc == 2 && argv[1] != \'\\0\')\n	{\n		tab = rpn_calc(argv[1]);\n		if (tab != NULL)\n			printf(\"\%ld\\n\", *tab);\n		return (0);\n	}\n	printf(\"Error\\n\");\n	return (0);\n}\n~#include <unistd.h>\n\nint main(int ac, char **av)\n{\n	int i = 1;\n	int  t[32] = {0}; \n	int j ;\n\n	if(ac == 1)\n	{\n		write(1,\"options: abcdefghijklmnopqrstuvwxyz\\n\",36);\n		return 0;\n	}\n	i = 1;\n	while (i < ac)\n	{\n		j = 1;\n		if(*av[i] == \'-\')\n		{\n			while(av[i][j] && av[i][j] >= \'a\'  && av[i][j] <= \'z\')\n			{\n				if(av[i][j] == \'h\')\n				{\n					write(1,\"options: abcdefghijklmnopqrstuvwxyz\\n\",36);\n					return 0;\n				}\n\n				t[\'z\' - av[i][j] + 6] = 1;\n				j++;\n			}\n\n			if (av[i][j])\n			{\n				write(1,\"Invalid Option\\n\",15);\n				return 0;\n			}\n			j++;\n		}\n		i++;\n	}\n	i = 0;\n		while (i < 32)\n		{\n		t[i] = \'0\' + t[i];\n		write(1,&t[i++],1);\n			if(i == 32)\n				write(1,\"\\n\",1);\n			else if(i \% 8 == 0)\n				write(1,\" \",1);\n\n		}\n\n	return 0;\n}\n~#include \"list.h\"\n\nint        cycle_detector(const t_list *list)\n{\n	const t_list	*slow;\n	const t_list	*fast;\n\n	slow = list;\n	fast = list;\n	if (!list)\n		return (0);\n	while (fast && fast->next)\n	{\n		slow = slow->next;\n		fast = fast->next->next;\n		if (fast == slow)\n			return (1);\n	}\n	return (0);\n}\n~#include <unistd.h>\n\nvoid print_pal(char* str, int low, int high)\n{\n	while (low <= high)\n		write(1, &str[low++], 1);\n}\n\nvoid biggest_pal(char *str)\n{\n	int	i;\n	int len;\n	int low;\n	int high;\n	int max_len;\n	int start;\n\n	len = 0;\n	while (str[len])\n		len++;\n	i = 1;\n	max_len = 1;\n	while (++i < len)\n	{ \n		low = i - 1;\n		high = i;\n		while (low >= 0 && high < len && str[low] == str[high])\n		{\n			if (high - low + 1 > max_len)\n			{\n				start = low;\n				max_len = high - low + 1;\n			}\n			--low;\n			++high;\n		}\n		low = i - 1;\n		high = i + 1;\n		while (low >= 0 && high < len && str[low] == str[high])\n		{\n			if (high - low + 1 > max_len)\n			{\n				start = low;\n				max_len = high - low + 1;\n			}\n			--low;\n			++high;\n		}\n	}\n	print_pal(str, start, start + max_len - 1);\n}\n\nint main(int argc, char **argv)\n{\n	if (argc == 2)\n		biggest_pal(argv[1]);\n	write(1, \"\\n\", 1);\n	return 0;\n}");
            name = headers[number_of_task - 1];
            text = text_arr[number_of_task - 1];
            opener(name, text);
        }
    } 
    return 0;
}