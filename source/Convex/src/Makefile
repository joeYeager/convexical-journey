JCC = javac
JFLAGS = -g

default: Quickhull.class Bruteforce.class Algorithm.class Panel.class Main.class 

Quickhull.class: Quickhull.java
	$(JCC) $(JFLAGS) Quickhull.java
Bruteforce.class: Bruteforce.java
	$(JCC) $(JFLAGS) Bruteforce.java
Algorithm.class: Algorithm.java
	$(JCC) $(JFLAGS) Algorithm.java
Panel.class: Panel.java
	$(JCC) $(JFLAGS) Panel.java
Main.class: Main.java
	$(JCC) $(JFLAGS) Main.java

clean:
	$(RM) *.class
