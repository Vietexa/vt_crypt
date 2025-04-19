# vt_crypt (for Linux and Unix-like systems)
## A simple CLI note-taking application that comes with built in encryption/obfuscation (so people can't read the things you write without having the key)

### Features:
- Lets you create different notes that are encryped with **different keys**.
- Each of the keys can be chosen by you.
- You can decrypt the encrypted notes as long as you know their keys.
- When choosing to decrypt a note, you can use the "**/files**" command to display the name of all the encrpyted notes that are in the directory of the application.

### How to build it:
First of all, you should know that if you don't want to build the application, you don't necessarily need to.
There is an already built executable in the "bin" directory, but if you want to build it yourself, then it's really simple to do so:

In order build the executable, you simply need to compile it using a C++ compiler (such as g++).

### How to build it using g++ (Linux distributions)
First make sure you have g++ (or the gcc and g++ package) installed. 
On a lot of Linux distributions gcc and g++ already come installed by default.

If g++ is installed, then you can run this command in the same directory whehere ```main.cpp``` is:

``g++ main.cpp -o <executable_name>``.

where ```<executable name>``` is the name that you want to give to the exectuable that will be built.


