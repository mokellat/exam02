#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int index = 0;
	int in_tmp;
	char tmp[500];
	
	if(argc <= 2)
		write(1, "\n", 1);
	else
	{
		while(argv[1][i])
		{
			j = 0;
			while(argv[2][j])
			{
				if(argv[1][i] == argv[2][j])
				{
					tmp[index] = argv[1][i];
					index++;
					j++;
					break ;
				}
				else
					j++;
			}
			i++;
		}
		tmp[index + 1] = '\0';
		i = 0;
		j = 0;
		in_tmp = index;
		while(i < index)
		{
			j = i + 1;
			while(j < index)
			{
				if(tmp[i] == tmp[j])
				{
					for(int k = j; k < index - 1; k++)
					{
						tmp[k] = tmp[k + 1];
					}
					index--;
				}
				else
					j++;
			}
			i++;
		}
		tmp[index] = '\0';	
	}
	printf("%s\n", tmp);
}