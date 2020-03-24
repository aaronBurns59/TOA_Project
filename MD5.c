// Aaron Burns
// An Algorithm that calculates the MD5 hash digest of any input

// standard c library
#include <stdio.h>
#include <stdint.h>
// used for specifying the exact size of the integers in terms of bits
#include <inttypes.h>
// used for handling the endian of the bytes
#include <endian.h>

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
const int S[4][4]= {
    // Shift amounts for Round 1
    {7,12,17,22},
    // Shift amounts for Round 2
    {5,9,14,20},
    // Shift amounts for Round 3
    {4,11,16,23},
    // Shift amounts for Round 4
    {6,10,15,21}
};

// 64 bytes of memeory that can be accessed in different types:
// 64 8-bit blocks
// 8 64-bit blocks
// 16 32-bit blocks
typedef union{
    // For accessing each bit in memory // Assigning the 1-bit and 0-bits for padding
    uint8_t eight[64];
    // For accessing the memory in 8-bit (1-byte) blocks // Assigning the last byte to the number of bits read in
    uint64_t sixFour[8];
    // Input for MD5 is 512-bits (64-bytes) broken into 16 32-bit blocks
    uint32_t threeTwo[16];
}BLOCK;

typedef enum{ 
    READ,
    PAD0,
    FINISH
}PADDING;

struct{
    uint32_t result[4];
}OUTPUT;



#define AuxF(x,y,z) ((x & y) | (~x & z))
#define AuxG(x,y,z) ((x & z) | (y & ~z))
#define AuxH(x,y,z) (x ^ y ^ z)
#define AuxI(x,y,z) (y ^ (x | ~z))

#define ROTL(w, s) ((w << s) | (w >> (32-s)))

// What the params do:
// 1. a,b,c,d are the 4 16 bit words
// x is somthing random I don't know need to find out
// si is for accessing the elements of the s 2d array which are used in each round
// k is the 64 constants declared above
#define F(a,b,c,d,m,si,k){a+=AuxF(b,c,d)+m+k; a=b+ROTL(a,S[0][si]);}
#define G(a,b,c,d,m,si,k){a+=AuxG(b,c,d)+m+k; a=b+ROTL(a,S[1][si]);}
#define H(a,b,c,d,m,si,k){a+=AuxH(b,c,d)+m+k; a=b+ROTL(a,S[2][si]);}
#define I(a,b,c,d,m,si,k){a+=AuxI(b,c,d)+m+k; a=b+ROTL(a,S[3][si]);}


/*
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
}// Rotate bits left

static uint32_t F(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t m, int si, uint32_t k){
    a += AuxF(b,c,d) + m + k;
    a = ROTL(a, s[0][si]);
    return (a += b);
}// F // Round 1, first 16 operations

static uint32_t G(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t m, int si, uint32_t k){
    a += AuxG(b,c,d) + m + k;
    a = ROTL(a, s[1][si]);
    return (a += b);
}// G // Round 2, second 16 operations

static uint32_t H(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t m, int si, uint32_t k){
    a += AuxH(b,c,d) + m + k;
    a = ROTL(a, s[2][si]);
    return (a += b);
}// H // Round 3, third 16 operations

static uint32_t I(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t m, int si, uint32_t k){
    a += AuxI(b,c,d) + m + k;
    a = ROTL(a, s[3][si]);
    return (a += b);
}// I // Round 4, fourth 16 operations
*/

// This function is taken from the SHA256 algorithm as it and MD5 share the exact same padding method
// Section 5.1.1 in the Secure Hash Algorithm Standard
// What the parameters do:
// *M is the 32 bit block of the message input
// *infile: the file that will be padded into message
// the number of bits in a message so the padding knows what to add
// enum element to show the status of padding
// This funciton will process the input into the padded messages of the right size
int padding(BLOCK *M, FILE *infile, uint64_t *numbits, PADDING *status){

    int i;    
    int numBytesRead;

    // using a switch with the status in PADDING to decide the phase of padding needed
    switch(*status)
    {
        case FINISH:
            // if no padding needs to be done
            return 0;
        case PAD0:
            // i + 1 < 56 because the first byte is for the 1-bit and 
            // the last 8-bytes of the 64-bytes of memory in M is needed for the message
            for(i = 1; i < 56; i++)
            // this is the 0 padding from 
                M->eight[i] = 0x00;
            // the last 8-bytes are equal ot the number of bits read in from the file
            // see the union for layout of the allocated memory
            M->sixFour[7] = htobe64(*numbits); // converts byte order to the order of the current machine
            // one the 1-bit, 0-bits and number of bits have been added to the Union memory allocation, padding is done
            *status = FINISH;
        break;
        default:
            // Read 64 bytes from the file
            numBytesRead = fread(M->eight, 1, 64, infile);
            // Dereferencing numbits to be equal to what is just read in
            *numbits += (8ULL * ((uint64_t) numBytesRead));
            // Check if padding needs to be done to a message
            if(numBytesRead < 56)
            {
                // Do all the padding if the number of bytes is less then 56
                M->eight[numBytesRead] = 0x80;
                for(i = numBytesRead + 1; i < 56; i++)
                    M->eight[i] = 0x00;
                M->sixFour[7] = htobe64(*numbits);
                *status = FINISH;
            }// if
            else if(numBytesRead < 64)
            {
                // if the number of bytes read in is greater then 64 then need to read in anyway between 56 and 64
                // in order to maintain the Message digest size of 448 % 512 for MD5
                // append the 1-bit to the front of the new block
                M->eight[numBytesRead] = 0x80;
                // from the new block plus the 1-bit up to the limit of the new block
                for(i = numBytesRead + 1; i< 64; i++)
                    M->eight[i] = 0x00;
                // indicate that the new block needs to be padded
                *status = PAD0;
            }// else if
    }// switch

    // Convert to host machine endian order
    for(i = 0; i < 16; i++)
        M->threeTwo[i] = be32toh(M->threeTwo[i]);
    
    return 1;
}

uint32_t words[4];

// This function will preform the MD5 hashing on the message
void hashMD5(BLOCK *M){

    // Each round consists of 16 operations, there are 4 rounds and each round uses a different auxillary funciton
    // Each operation uses a unique element of the K[i] constant, A,B,C,D are also costants that change their order 
    // as parameters between each operation, M is the message that is going to be hashed. and the static values between
    // M and K is the select the shift amounts from the s[i][j] 2d array constant, see the method F,G,H or I to see how 
    // that works

    uint32_t a = A, b = B, c = C, d = D;

    // =====Round 1===================Operation
    F(a,b,c,d,M->threeTwo[0],0,K[0]);   //  1
    F(d,a,b,c,M->threeTwo[1],1,K[1]);   //  2
    F(c,d,a,b,M->threeTwo[2],2,K[2]);   //  3
    F(b,c,d,a,M->threeTwo[3],3,K[3]);   //  4
    F(a,b,c,d,M->threeTwo[4],0,K[4]);   //  5
    F(d,a,b,c,M->threeTwo[5],1,K[5]);   //  6
    F(c,d,a,b,M->threeTwo[6],2,K[6]);   //  7
    F(b,c,d,a,M->threeTwo[7],3,K[7]);   //  8
    F(a,b,c,d,M->threeTwo[8],0,K[8]);   //  9
    F(d,a,b,c,M->threeTwo[9],1,K[9]);   // 10
    F(c,d,a,b,M->threeTwo[10],2,K[10]); // 11
    F(b,c,d,a,M->threeTwo[11],3,K[11]); // 12
    F(a,b,c,d,M->threeTwo[12],0,K[12]); // 13
    F(d,a,b,c,M->threeTwo[13],1,K[13]); // 14
    F(c,d,a,b,M->threeTwo[14],2,K[14]); // 15
    F(b,c,d,a,M->threeTwo[15],3,K[15]); // 16
    // =====Round 2===================Operation
    G(a,b,c,d,M->threeTwo[1],0,K[16]);  // 17
    G(d,a,b,c,M->threeTwo[6],1,K[17]);  // 18
    G(c,d,a,b,M->threeTwo[11],2,K[18]); // 19
    G(b,c,d,a,M->threeTwo[0],3,K[19]);  // 20
    G(a,b,c,d,M->threeTwo[5],0,K[20]);  // 21
    G(d,a,b,c,M->threeTwo[10],1,K[21]); // 22
    G(c,d,a,b,M->threeTwo[15],2,K[22]); // 23
    G(b,c,d,a,M->threeTwo[4],3,K[23]);  // 24
    G(a,b,c,d,M->threeTwo[9],0,K[24]);  // 25
    G(d,a,b,c,M->threeTwo[14],1,K[25]); // 26
    G(c,d,a,b,M->threeTwo[3],2,K[26]);  // 27
    G(b,c,d,a,M->threeTwo[8],3,K[27]);  // 28
    G(a,b,c,d,M->threeTwo[13],0,K[28]); // 29
    G(d,a,b,c,M->threeTwo[2],1,K[29]);  // 30
    G(c,d,a,b,M->threeTwo[7],2,K[30]);  // 31
    G(b,c,d,a,M->threeTwo[12],3,K[31]); // 32
    // =====Round 3===================Operation
    H(a,b,c,d,M->threeTwo[5],0,K[32]);  // 33
    H(d,a,b,c,M->threeTwo[8],1,K[33]);  // 34
    H(c,d,a,b,M->threeTwo[11],2,K[34]); // 35
    H(b,c,d,a,M->threeTwo[14],3,K[35]); // 36
    H(a,b,c,d,M->threeTwo[1],0,K[36]);  // 37
    H(d,a,b,c,M->threeTwo[4],1,K[37]);  // 38
    H(c,d,a,b,M->threeTwo[7],2,K[38]);  // 39
    H(b,c,d,a,M->threeTwo[10],3,K[39]); // 40
    H(a,b,c,d,M->threeTwo[13],0,K[40]); // 41
    H(d,a,b,c,M->threeTwo[0],1,K[41]);  // 42
    H(c,d,a,b,M->threeTwo[3],2,K[42]);  // 43
    H(b,c,d,a,M->threeTwo[6],3,K[43]);  // 44
    H(a,b,c,d,M->threeTwo[9],0,K[44]);  // 45
    H(d,a,b,c,M->threeTwo[12],1,K[45]); // 46
    H(c,d,a,b,M->threeTwo[15],2,K[46]); // 47
    H(b,c,d,a,M->threeTwo[2],3,K[47]);  // 48
    // =====Round 4===================Operation
    I(a,b,c,d,M->threeTwo[0],0,K[48]);  // 49
    I(d,a,b,c,M->threeTwo[7],1,K[49]);  // 50
    I(c,d,a,b,M->threeTwo[14],2,K[50]); // 51
    I(b,c,d,a,M->threeTwo[5],3,K[51]);  // 52
    I(a,b,c,d,M->threeTwo[12],0,K[52]); // 53
    I(d,a,b,c,M->threeTwo[3],1,K[53]);  // 54
    I(c,d,a,b,M->threeTwo[10],2,K[54]); // 55
    I(b,c,d,a,M->threeTwo[1],3,K[55]);  // 56
    I(a,b,c,d,M->threeTwo[8],0,K[56]);  // 57
    I(d,a,b,c,M->threeTwo[15],1,K[57]); // 58
    I(c,d,a,b,M->threeTwo[6],2,K[58]);  // 59
    I(b,c,d,a,M->threeTwo[13],3,K[59]); // 60
    I(a,b,c,d,M->threeTwo[4],0,K[60]);  // 61
    I(d,a,b,c,M->threeTwo[11],1,K[61]); // 62
    I(c,d,a,b,M->threeTwo[2],2,K[62]);  // 63
    I(b,c,d,a,M->threeTwo[9],3,K[63]);  // 64

    words[0]+=a;
    words[1]+=b;
    words[2]+=c;
    words[3]+=d;
}   

int main(int argc, char *argv[]){
    // Check if the program has recieved any file as input
    if(argc != 2){
        printf("Error: Expecting single file name as an argument\n");
        return 1;
    }// if

    // Opening file
    FILE *infile = fopen(argv[1], "rb");
    
    // Check if the program has read in a file
    if(!infile){
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }// if

    // Current padded message block
    BLOCK M;
    uint64_t numbits = 0;
    PADDING status = READ;

    // this while loop pads the messages based on the input
    // it continues until there is nothing left to pad
    while( padding(&M, infile, &numbits, &status))
    {
        hashMD5(&M);
    }// while

    for(int i=0;i<4;i++)
        printf("%02x", words[i]);
    
    printf("\n");
    // Closing file
    fclose(infile);

    return 0;
}// main
