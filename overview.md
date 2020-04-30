# Aaron Burns - G00346688
## Overview of the MD5 Hashing Algorithm Project

# Introduction
The requirement for this project was to create a *C* program that would calculate the hash value of a input using the Message Digest 5 (MD5) algorithm. It required learning about how the algorithm processes the message before it can be hashed as well as generating the output hash value of that message. The research involved in this project was extensive and essential to understanding and creating the hashing program. There was a large number of sources detailing the algorithm for MD5, however not so many detailing how the preprocessing, or padding in this case was done. Sources would assume you knew or barely mention the padding and how it is done. Luckily The Secure Hashing Algorithm 256 (SHA256) shares the exact same padding process and their is a very detailed summation of how to implement it and how it works. I will get into more detail on the algorithm and its components in later sections, but I felt it nesscessary to mention how researching one hashing algorithm can help with building another. The MD5 algorithm itself is documented in the *C* language, this made it very easy to interpret the code samples provided in the various sources found online(list of sources and what they were used for are in the Research Section). 

When is comes to understanding the MD5 hashing algorithm, there are a number of things to keep in mind. The input for the hashing algorithm is called a *"message"*. MD5 can hash practically any input of any size. Theoretically there is a limit to the size of the input. But it is unrealistic that a message that large would be ever need to be hashed. Regardless of the size of the input, the output which is known as the *"hash" or "digest"* will always be the same size. That size being 128-bits or 16-bytes, which if put into a string would have a lenght of 32. An example of what a hash value looks like is: *5d41402abc4b2a76b9719d911017c592*, this is the hash output of the message "hello". It is important to know that one little change in the word "hello" will change the **digest(output) of the message(input)** completely, for example: *8b1a9953c4611296a827abf8c47804d7* is the hash output for "Hello". Just by changing the case of the first letter you get a completely different hash value as an output.

The other important thing to keep in mind when learning to build a hashing algorithm is why hashing is used to secure passwords, or documents. A hash of any input will always be the same as long as the input doesn't change. It is a way of securing whatever the input may be in a way that doesn't require the host that is saving the information to actually know what the unhashed digest is. Lets say the message is a password to a website. The website should not store the actually message itself. If the website is hacked then the password is there for people to steal. However if the website stores hash values of the passwords and the site is hacked all they will have are the hash values. This is more secure because it is next to impossible to recreate the original input from the hash value. That is what makes hashing algorithms very useful and important when securing information. 

# Run

## On Windows(10)

### How to set up

Go to [MSYS2 Website](https://www.msys2.org/), and click the download which is recommended for your system. (The website will tell you which one is recommended).

Onces it's downloaded, follow the Windows installer process until it is finished. It will open a cmd window similar to the windows CMD console.

Then update pacman(A package managing enviroment) using the following line in the CMD. Pacman makes it very easy to manage the installation of packages including the gcc
* pacman -Syu

Then install the gcc package by using the following line in the CMD
* pacman -S base-deve1 gcc vim cmake

In order to use the *C compiler* in the standard windows console, you need to add the the following enviroment variables(Search this term in the windows search bar) to the PATh in windows 10.
* C:\msys64\mingw64\bin
* C:\msys64\usr\bin

### CMD to Compile and Run

- gcc -o md5 MD5.c

- md5

## On Linux(Project built on)

### How to set up

Linux has embedded tools to compile *C* code and run *C* programs, use the following cmd line to install gcc 
- sudo apt install build-essential

This line is to verify if gcc is install, it will also tell you the version.
- gcc --version

### CMD to Compile and Run

- gcc -o md5 MD5.c

- ./md5 test.txt

# Test

# Algorithm
The MD5 algorithm itself is very complex and challeneging to get an understanding of. However there exist many resources online which can be used to better your understanding. From summaries of the algorithm along with Pseudo code ([Summary and Pseudo Code](http://practicalcryptography.com/hashes/md5-hash/)), to the offcial algorithm itself ([RFC-1321](https://datatracker.ietf.org/doc/rfc1321/?include_text=1)). The MD5 algorithm has many components that are used not only in the hashing process itself but in the padding process, there are also a number of constants that are used thoughout the program as well as other data types for storing the input. Every component of this program is used in either the padding process or the hashing process. Most of these components that are used in the hashing process which takes place **hashMD5** function such as the constants K and S (more on these later). However the input message itself is not stored as a static variable. It is store in a Union. The reason for this is because throughout the program the message needs to be read in different sizes of ints. And using a Union allows us to store the exact same data in different data types. I will go into more detail about how Unions are used in this project later.

## Constants and Other Data Types

### K 
* K is a constant 32-bit integer array of size 64, each one of these ints is used in one of the 64 operations in the MD5 Algorithm. i.e. the first opertion uses the int at index 0 etc.
![K Constants](Images/K.png "List of Constants K")

*

## Auxillary Functions
* There are 4 Auxillary functions used in (image here)

## Padding

## Hashing

# Complexity

# Research

* [gcc for Windows](https://youtu.be/0Z4Xga_7gp0) Video used for installing *C Compiler* for Windows 

* [Practical Cryptography](http://practicalcryptography.com/hashes/md5-hash/) Practical Cryptography website used for learning about the broad aspects of MD5 algorithm and used its built in MD5 calculator for verification of hash outputs.