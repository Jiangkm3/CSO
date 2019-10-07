#include <stdio.h>

// A function to help input a 1 or 0 as k, and determine if k is valid
// Argument i: the digit of the binary k, only used for printing messege
// Return value binary k: -1 if not valid and k if valid
int binary_input(int i) {
	int k;
	printf("Enter bit %d: ", i);
	scanf("%d", &k);
	// Determine if k is a valid binary number
	if ((k != 0) && (k != 1)) {
		printf("Invalid binary number\n");
		return -1;
	}
	return k;
}

// Output a long in binary form
// Argument b: the long to be output
// Argument n: the recursive step
// In order to print the exact binary as input, want to make sure all digits are printed even with the extra 0s at the beginning,
// So an extra variable "n" is implemented to ensure the output till the right digit
// The function uses recursion so the output digit is in the right order
int binary_output(long b, int n) {
	if (n == 0) return(0);
	binary_output(b >> 1, n - 1);
	if (b & 1) printf("1");
	else printf("0");
	return(0);
	
}

int main() {
	// Variable n: # of binary digits
	// Variable k: temporary int to store input binary digits
	// Variable i: for iteration use	
	int n, k, i;
	printf("Enter number between 1 and 64: ");
	scanf("%d", &n);	
	if ((n < 1) || (n > 64)) {
		printf("Number not in range\n");
		return 1;
	}
	
	// We store the input binary into a unsigned long u and a signed long l
	long scale = 1;
	unsigned long u = 0;
	long l = 0;
	
	// For the first (n - 1) input, we multiply it by the correct power of 2 and add it to u, we then make l the same to u
	for (i = 0; i < n - 1; i++) {
		k = binary_input(i);
		if (k == -1) return 1;
		u += k * scale;
		scale *= 2;

	}
	l = u;
	
	// The only difference is for the dominant digit d(n)
	// In a unsigned decimal, we add d(n) * 2^(n-1)
	// In a signed decimal, we subtract d(n) * 2^(n-1)
	k = binary_input(n - 1);
	if (k == -1) return 1;
	u += k * scale;
	l -= k * scale;
	
	// Outputs
	printf("binary: ");
	binary_output(u, n);

	printf("\n");
	printf("hexadecimal: 0x%lX\n", u);
	printf("decimal (signed): %ld\n", l);
	printf("decimal (unsigned): %lu\n", u);

}
