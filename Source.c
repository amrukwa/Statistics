#include <stdio.h>
int main()
{
	FILE* fptr;
	FILE* pointer;
	fopen_s( &fptr, "try.txt", "r");
	fopen_s(&pointer, "result.txt", "w");
	int getc(FILE * fptr);
	int c = getc(fptr);
	int long words = 1, ss = 0, nrs = 0, sl = 0, cals = 0, sp = 0;

	if (fptr == NULL || pointer==NULL)
		perror("Error opening file");
	else
	{
		while (c != EOF)
		{

			c = getc(fptr);
			if (c >= 48 && c <= 57)
			{
				nrs++;
			}
			else if (c >= 65 && c <= 90)
			{
				cals++;
			}
			else if (c >= 97 && c <= 122)
			{
				sl++;
			}
			else if (c == 32)
			{
				words++;
			}
			else if (c == 46)
			{
				ss++;
			}
			else if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
			{
				sp++;
			}
		}
		fprintf(pointer, "Number of:\n special characters %ld\n numbers %ld\n capital letters %ld\n small letters %ld\n words %ld\n sentences %ld\n",
			sp, nrs, cals, sl, words, ss);
		fclose(fptr);
		fclose(pointer);
	}
	return 0;

}