# Aaron Burns - G00346688
# Overview of the MD5 Hashing Algorithm Project

# Introduction
The Specification for this project was to create a c program what would calcuate the hash value of a input using the Message Digest 5 (MD5) algorithm. It required learning about how the algorithm processes the message before it can be hashed as well as generating the output hash value of that message. The research involved in this project was extentsive and essential to understanding and creating the hashing program. There was a large number of sources detailing the algorithm for MD5, however not so many detailing how the pre-processing or padding in this case was done. Sources would assume you knew or barely mention the padding and how it is done. Luckily The Secure Hashing Algorithm 256 (SHA256) shares the exact same padding process and their is a very detailed summation of how to build it and how it works. I will get into more detail on the algorithm and its components in later sections, but I felt it nesscessary to mention how researching one hashing algorithm can help with building another. The MD5 algorithm itself is documented in the *C* language, and so is this project programed in *C*. This made it very easy to interpret the code samples provided in the various sources found online(list of sources and what they were used for are in Research Section). 

When is comes to understanding the MD5 hashing algorithm, there are a number of things to keep in mind. The input for the hashing algorithm is called a *"message"*. It can hash practiaclly any input of any size. Theorectially there is a limit to the size of the input. But it is unrealistic that a message that large would be ever needed to be hashed. Regardless of the size of the input, the output which is known as the *"hash" or "digest"* will always be the same size. That size being 128-bits or 16-bytes. which if put into a string would have a lenght ofexample of what a hash input looks like is: *5d41402abc4b2a76b9719d911017c592*, this is hash output of the message "hello". One thing to take note of is one little change in the word "hello" will change the  32. An **digest(output) of the message(input)** completely, for example: *8b1a9953c4611296a827abf8c47804d7* is the hash output for "Hello". Just by changing the case of the first letter you get a completely different hash value as an output.

The other important thing to keep in mind when learning to create a hashing algorithm is why hashing is used to secure passwords or documents. A hash of any input will always be the same as long as the input doesn't change. It is a way of securing whatever the input may be, in a way that doesn't require the host that is saving the information to actually know what the unhashed digest is. Say the message is a password to a website. The website should not have to store the actually message itself. If the website is hacked then the password is there for people to steal. However if the website stores hashes of the password and the site is hacked all they will have are the hash values. This is more secure because it is next to impossible to recreate the original input from the hash value. That is what makes hashing algorithms very important for securing information. 

# Run

# Test

# Algorithm

# Complexity

# Research
