// Aaron Burns
// An Algorithm that calculates the MD5 hash digest of any input

// standard c library
#include <stdio.h>
// used for specifying the exact size of the integers in terms of bits
#include <inttypes.h>

// MD5 Rotation Constants
// The values in K will be used in each step of the MD5 Algorithm
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
const int s[4][4]= {
    {7,12,17,22},
    {5,9,14,20},
    {4,11,16,23},
    {6,10,15,21}
};

// Auxillary Functions used in the MD5 Algorithm
// Logical Operators ~ : NOT, ^ : XOR, & : AND, | : OR
uint32_t AuxF(uint32_t x, uint32_t y, uint32_t z){
    return ((x & y) | (~x & z));
}// F // Auxillary Function

uint32_t AuxG(uint32_t x, uint32_t y, uint32_t z){
    return ((x & z) | (y & ~z));
}// G // Auxillary Function

uint32_t AuxH(uint32_t x, uint32_t y, uint32_t z){
    return (x ^ y ^ z);
}// H // Auxillary Function

uint32_t AuxI(uint32_t x, uint32_t y, uint32_t z){
    return (y ^ (x | ~z));
}// I // Auxillary Function

int main(int argc, char *argv)
{
    return 0;
}// main
