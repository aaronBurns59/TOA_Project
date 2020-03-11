// Aaron Burns
// An Algorithm that calculates the MD5 hash digest of any input

// standard c library
#include <stdio.h>
#include <stdint.h>
// used for specifying the exact size of the integers in terms of bits
#include <inttypes.h>

// Four "Words"(32-bit) initialized  in low order hexidecimal
// These are usd in each round of the MD5 operation
#define A 0x67452301
#define B 0xefcdab89
#define C 0x98badcfe
#define D 0x10325476

// MD5 Rotation Constants
// The values in K will be used in each step of the MD5 Algorithm

/***How to get the Constants in K[i]
    for (i = 0; i <= 64)
        K[i] = floor(2^32 * abs(sin(i+1)))
****/
const uint32_t K[64] ={    
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a,
        0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 0xf61e2562, 0xc040b340,
        0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8,
        0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 0x289b7ec6, 0xeaa127fa,
        0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92,
        0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

// Bit shift amounts for each round of operations
// The values of s will be used in every round
const int s[4][4]= {
    // Shift amounts for Round 1
    {7,12,17,22},
    // Shift amounts for Round 2
    {5,9,14,20},
    // Shift amounts for Round 3
    {4,11,16,23},
    // Shift amounts for Round 4
    {6,10,15,21}
};

union MessageBlock{
    uint32_t M[16];
};

// Auxillary Functions used in the MD5 Algorithm
// Logical Operators ~ : NOT, ^ : XOR, & : AND, | : OR
static uint32_t AuxF(uint32_t x, uint32_t y, uint32_t z){
    return ((x & y) | (~x & z));
}// F // Auxillary Function

static uint32_t AuxG(uint32_t x, uint32_t y, uint32_t z){
    return ((x & z) | (y & ~z));
}// G // Auxillary Function

static uint32_t AuxH(uint32_t x, uint32_t y, uint32_t z){
    return (x ^ y ^ z);
}// H // Auxillary Function

static uint32_t AuxI(uint32_t x, uint32_t y, uint32_t z){
    return (y ^ (x | ~z));
}// I // Auxillary Function

// Bit shifting function
// Takes in a word (w) and left rotate its bits by the amount given (s)
static uint32_t ROTL(uint32_t w, int s){
    return ((w << s) | (w >> (32-s)));
}
// What the params do:
// a,b,c,d are the 4 16 bit words
// x is somthing random I don't know need to find out
// si, sj are for accesing the elements of the s 2d array which are used in each round
// ^^ might be able to pass these easier it is only a 4*4 2d array
// k is the 64 constants declared above
static uint32_t F(uint32_t a, uint32_t b, uint32_t c, uint32_t d, int x, int si, uint32_t k){
    int shiftAmount;
    // getting the element of the 2d array of s
    // this is used in each round of operations 
    for(int i = 0; i <= si; i++)
    {
        shiftAmount = s[0][i];
        // printf("Accessing s elemetents: %d\n", shiftAmount);
    }// for
    printf("%d\n", shiftAmount);
    a += AuxF(b,c,d) + x + k;
    a = ROTL(a, shiftAmount);
    return a += b;
}// F // Round 1, first 16 operations

static uint32_t G(uint32_t a, uint32_t b, uint32_t c, uint32_t d, int x, int si, uint32_t k){
    int shiftAmount;
    for(int i = 0; i <= si; i++)
    {
        shiftAmount = s[1][si];
    }// for
    printf("%d\n", shiftAmount);
    a += AuxG(b,c,d) + x + k;
    a = ROTL(a, shiftAmount);
    a += b;
}// G // Round 2, second 16 operations

static uint32_t H(uint32_t a, uint32_t b, uint32_t c, uint32_t d, int x, int si, uint32_t k){
    int shiftAmount;
    for(int i = 0; i <= si; i++)
    {
        shiftAmount = s[2][si];
    }// for
    printf("%d\n", shiftAmount);
    a += AuxH(b,c,d) + x + k;
    a = ROTL(a, shiftAmount);
    a += b;
}// H // Round 3, third 16 operations

static uint32_t I(uint32_t a, uint32_t b, uint32_t c, uint32_t d, int x, int si, uint32_t k){
    int shiftAmount;
    for(int i = 0; i <= si; i++)
    {
        shiftAmount = s[3][si];
    }// for
    printf("%d\n", shiftAmount);
    a += AuxI(b,c,d) + x + k;
    a = ROTL(a, shiftAmount);
    a += b;
}// I // Round 4, fourth 16 operations

// numbits is the number of bits retrieved from the file read in 
// The final output of this function needs to be a multiple of 512 bits 
uint32_t NumberOf_0_Bytes(uint64_t numbits){
    // ULL: Unsigned Long Long Integer (it makes c save var as a 64 bit integer)
    uint64_t result = 512ULL - (numbits % 512ULL);
    // find out if there is enough room in the last block to do the padding or will a new block be needed
    if(result < 65)// 65 because it is the lenght of the integer and the 1
        result += 512;
    // get the number of 0 bytes needed to pad between the 1 and the 64 bit integer printed at the end
    result -= 72;
    return(result/8ULL);
}

int main(int argc, char *argv[]){
    // Check if the program has recieved any file as input
    if(argc != 2){
        printf("Error: Expecting single file name as an argument\n");
        return 1;
    }

    FILE *infile = fopen(argv[1], "rb");
    
    if(!infile){
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    int x=1;

    // Round 1 
    F(A,B,C,D,x,0,K[0]);// Operation 1

    // Round 2 
    G(A,B,C,D,x,0,K[0]);// Operation 17

    // Round 3
    H(A,B,C,D,x,0,K[0]);// Operation 33

    // Round 4
    I(A,B,C,D,x,0,K[0]);// Operation 49

    fclose(infile);

    return 0;
}// main
