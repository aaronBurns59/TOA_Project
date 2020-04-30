# TOA_Project

## Repository Layout

### Link to SHA256 repository
* This repo contains the code that was done from watching the video labs.  
[https://github.com/aaronBurns59/SHA-256-Algorithm](https://github.com/aaronBurns59/SHA-256-Algorithm)  

### MD5.c
* Contains the code for the MD5 hashing algorithm in c

### test.txt 
* A text file that can be read in by the MD5.c program to test if it hashes properly

### overview.md
* A markdown file that takes in more depth about the MD5 Algorithm as a whole and how the project was approached and built. 

### Images
* A folder containing images used in the overview.md
## Message Digest 5 (MD5) Hash Algorithm

### Input
* The input for the MD5 algorithm can me a message of any length. The output will always be the same size, 128-bits. The input can't be read in its current form, it has to be manipulated in a way that it is equal to 448 % 512. This manipulation is called padding and it is explained later on.

* The input for the MD5 algorithm is refered to as a message. The message is broken up into 16 32-bits blocks, these blocks are called **Words** called A, B, C and D.

### Padding
* The padding for MD5 is the same padding used in the Secure Hashing Algorithm 256 algorithm. Padding needs to be done on the input message so that it can be operated on. As mentioned earlier the input message must be eqaul to 448 % 512. This means that each block of input is 64-bits short of a byte.
1. Suppose the length of the input message "M" is 'l'-bits.
2. 1-bit is appended to the end of the message.
3. Then 'n' 0-bits, n is the smallest non-negitive solution to the equation.
    * __l + 1 + n = 448 % 512__
4. Then add the 128-bit block that is equal to the number 'l' in binary.

#### Example: *8-bit ASCII Message "abc"*
1. This message has a lenght 'l' of 24-bits because each ASCII character is 8-bit and there is three of them.
2. This message in bits has the 1 bit appended to it, then 'n' number of 0-bits adn finallythe length of the original message is appended.
3. The amount of 0-bits needed for this padding is 448 - (l(24) + 1) = 423.

    Algorithm: 'a' + 'b' + 'c' + '1' + 'n' + 'l'  
    Binary: 01100001 + 01100010 + 01100010 + 1 + 00...00 + 00...01100  
    Bits: 8 + 8 + 8 + 1 + 423 + 64

* l: is the length of the message and is appended to an otherwise empty 64-bits.

### Hash Operations
* The hashing operation for MD5 is a series of 64 operations split into 4 rounds,
1. Each operation uses the initial hash values A, B, C and D, the message input, the shift amounts in 's' and the constant values in k.
2. The operations are split into 4 rounds, each round uses a different Auxillary function. Round 1 uses F, Round 2 uses G, Round 3 uses H and Round 4 uses I.
3. The auxillary functions are defined as follows:
    * F(X,Y,Z): (X **AND** Y) **OR** (**NOT** X **AND** Z)
    * G(X,Y,Z): (X **AND** Z) **OR** (Y **AND NOT** Z)
    * H(X,Y,Z): X **XOR** Y **XOR** Z
    * I(X,Y,Z): Y **XOR** (Y **XOR** (X **OR NOT** Z))
4. Before the hashing operation begins, the initial hash values define as constants are assigned to some local variables. These local variables are passed into the functions used in each operation. 
5. The local variables that are passed into the auxillary functions in each operation during the 4 rounds, they are manipulated in each of these operations.
6. Once the 4 local variables have been processed by the 64 operations they are returned from the hashing function and into an array which is used to display the hashed output of the intial input.

## How to Run

* git clone https://github.com/aaronBurns59/TOA_Project 

cd into the repository once it is cloned

1. gcc -o md5 MD5.c

2. ./md5 test.txt(or any file you want)

## Research
* **Research is laid out in more detail in the overview.md file**.

## References
[http://practicalcryptography.com/hashes/md5-hash/](http://practicalcryptography.com/hashes/md5-hash/)  
[https://datatracker.ietf.org/doc/rfc1321/?include_text=1](https://datatracker.ietf.org/doc/rfc1321/?include_text=1)  
[https://www.iusmentis.com/technology/hashfunctions/md5/](https://www.iusmentis.com/technology/hashfunctions/md5/)  
[https://cs.indstate.edu/~fsagar/doc/paper.pdf](https://cs.indstate.edu/~fsagar/doc/paper.pdf)  
[https://rosettacode.org/wiki/MD5#C](https://rosettacode.org/wiki/MD5#C)  
[https://dox.ipxe.org/md5_8c_source.html](https://dox.ipxe.org/md5_8c_source.html)  
[https://linux.die.net/man/3/htobe64](https://linux.die.net/man/3/htobe64)  
[https://tools.ietf.org/html/rfc1321](https://tools.ietf.org/html/rfc1321)  
[https://en.wikipedia.org/wiki/MD5](https://en.wikipedia.org/wiki/MD5)  
[http://www.cs.haifa.ac.il/~orrd/HashFuncSeminar/Lecture2.pdf](http://www.cs.haifa.ac.il/~orrd/HashFuncSeminar/Lecture2.pdf)  
[https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf)
