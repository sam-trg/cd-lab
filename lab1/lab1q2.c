// Write a C program to reverse the contents of a file and store in another file.
// Also display the size of file using file handling function.

#include <stdio.h>

int	main(void)
{
	FILE *fp1 = fopen("lab1q3.c", "rb");
	FILE *fp2 = fopen("new.txt", "wb");

	// seek to end
	// tell for size
	fseek(fp1, 0, SEEK_END);
	long int file_size = ftell(fp1);

	printf("Size of the file is %ld bytes\n", file_size);

	// write to another file, rev loop
	for (long int i = file_size - 1; i >= 0; i--)
	{
		fseek(fp1, i, SEEK_SET);
		int ch = getc(fp1);
		putc(ch, fp2);
	}

	fclose(fp1);
	fclose(fp2);
	return (0);
}