#include <stdio.h>

int main(void) {

	//Declare an unsigned integer using hexadecimal notation.
	// On this machine, unsigned int occupies 4 bytes or 32 bits
	
	unsigned int ui = 0xDEADD00D;

	// Open output.bin in binary read/write mode.
	// "w" creates or overwrites the file.
	// "b" specifies binary mode.
	// "+" allows reading and writing.
	FILE *fp = fopen("output.bin", "wb+");
	
	 // Only proceed if the file opened successfully.
	 if (fp != NULL) {
	
	//Write the raw bytes of ui to the file.
	//&ui gives the address of the variable.
	// sizeof(unsigned int) gives its size in bytes.
	// 1 means write one element.
	fwrite(&ui, sizeof(unsigned int), 1, fp);

	//Close the file.
	fclose(fp);

	 }

}
