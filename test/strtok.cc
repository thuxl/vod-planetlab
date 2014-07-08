#include <stdio.h>
#include <string.h>

int main ()
{
	char str[] ="- This, a sample string.";
	char * pch;
	printf ("Splitting string \"%s\" into tokens:\n",str);
	pch = strtok (str," ,.-");
	while (pch != NULL)
	{
		printf ("pch=[%s], str=[%s]\n",pch,str);
		pch = strtok (NULL, " ,.-");
	}
	return 0;
}
