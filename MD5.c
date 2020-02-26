// Aaron Burns
// An Algorithm that calculates the MD5 hash digest of any input

#include <stdio.h>
#include <inttypes.h>

// Auxillary Functions used in the MD5 Algorithm
// Logical Operators ~ : NOT, ^ : XOR, & : AND, | : OR
uint32_t AuxF(uint32_t x, uint32_t y, uint32_t z){
    return ((x & y) | (~x & z))
}// F // Auxillary Function

uint32_t AuxG(uint32_t x, uint32_t y, uint32_t z){
    return ((x & z) | (y & ~z))
}// G // Auxillary Function

uint32_t AuxH(uint32_t x, uint32_t y, uint32_t z){
    return (x ^ y ^ z)
}// H // Auxillary Function

uint32_t AuxI(uint32_t x, uint32_t y, uint32_t z){
    return (y ^ (x | ~z))
}// I // Auxillary Function

main()
{

}// main
