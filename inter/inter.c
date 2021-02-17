#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int index = 0;
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
		tmp[index] = '\0';
		for(i = 0; i < index; i++)
		{
			for(j = i + 1; j < index;)
			{
				if(tmp[i] == tmp[j])
				{
					for(int k = j; k < index; k++)
						tmp[k] = tmp[k + 1];
					index--;
				}
				else
					j++;
			}
		}
	}
	tmp[index] = '\0';
    i = 0;
	for(i = 0; i < index; i++)
        write(1, &tmp[i], 1);
}