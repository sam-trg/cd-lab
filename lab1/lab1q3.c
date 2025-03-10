// WAP to merge alternate lines and store in third file

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	FILE *fp1, *fp2, *fp3;
	fp1 = fopen("lab1q1.c", "r");
	if (!fp1)
	{
		EXIT_FAILURE;
	}
	fp2 = fopen("lab1q2.c", "r");
	if (!fp2)
	{
		fclose(fp1);
		EXIT_FAILURE;
	}
	fp3 = fopen("result.txt", "w");
	if (!fp3)
	{
		fclose(fp1);
		fclose(fp2);
		EXIT_FAILURE;
	}
	char c, c1, c2;
	while (c1 != EOF && c2 != EOF)
	{
		c1 = fgetc(fp1);
		fputc(c1, fp3);
		while (c1 != '\n' && c1 != EOF && c2 != EOF)
		{
			c1 = fgetc(fp1);
			fputc(c1, fp3);
		}
		c2 = fgetc(fp2);
		fputc(c2, fp3);
		while (c2 != '\n' && c2 != EOF && c1 != EOF)
		{
			c2 = fgetc(fp2);
			fputc(c2, fp3);
		}
	}
	printf("Merged successfully.\n");
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return (0);
}
