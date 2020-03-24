# TOA_Project

## Repository Layout

### Link to SHA256 repository
* This repo contains the code that was done from watching the video labs.  
[https://github.com/aaronBurns59/SHA-256-Algorithm](https://github.com/aaronBurns59/SHA-256-Algorithm)  

### MD5.c
* Contains the code for the MD5 hashing algorithm in c

### test.txt 
* A text file that can be read in by the MD5.c program to test if it hashes properly

## Message Digest 5 (MD5) Hash Algorithm

### How the MD5 hashing algorithm works


### Auxillary Functions
1. F(X,Y,Z) = (X **AND** Y) **OR** (**NOT** X **AND** Z)
2. G(X,Y,Z) = (X **AND** Z) **OR** (Y **AND NOT** Z)
3. H(X,Y,Z) = X **XOR** Y **XOR** Z
4. I(X,Y,Z) = Y **XOR** (X **OR NOT** Z))
### Constants
1. K: An array of 64 32-bit integers which are hardcoded and will be used in each individual operation in the hashing algorithm

2. S: A 2d array that will determine the number of bits shifted  in whichever operation it is called in.

### Padding

### Hash Operations

## How to Run

* git clone https://github.com/aaronBurns59/TOA_Project 

cd into the repository once it is cloned

1. gcc -o md5 MD5.c

2. ./md5 test.txt (or any file you want)

## Research

## References
[http://practicalcryptography.com/hashes/md5-hash/](http://practicalcryptography.com/hashes/md5-hash/)  
[https://datatracker.ietf.org/doc/rfc1321/?include_text=1](https://datatracker.ietf.org/doc/rfc1321/?include_text=1)  
[https://www.iusmentis.com/technology/hashfunctions/md5/](https://www.iusmentis.com/technology/hashfunctions/md5/)  
[https://cs.indstate.edu/~fsagar/doc/paper.pdf](https://cs.indstate.edu/~fsagar/doc/paper.pdf)  
[https://rosettacode.org/wiki/MD5#C](https://rosettacode.org/wiki/MD5#C)  
[https://dox.ipxe.org/md5_8c_source.html](https://dox.ipxe.org/md5_8c_source.html)  
[https://linux.die.net/man/3/htobe64](https://linux.die.net/man/3/htobe64)  

