Ben Mikailenko
Pi Approximation

files:
	piapprox.c: the main c code
	Makefile: the makefile
	README.txt: the readme

to configure:

	run "make"

to run:

	./piapprox

About this program:

	piapprox attempts to approximate the value of pi by integrating, 

	4/(1+ x^2) 

	through trapezoidal, Simpsons, Simpsons 3rd degree, and booles methods. The value of (pi - approximation) is printed in a table for each method appropriately for different values of n. 

