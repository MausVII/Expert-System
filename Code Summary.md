# Expert-System
# The knowledge base uses mostly enums as an interface so it's easier to modify and read the code. 
# The constructor of the knowledge base asks two groups of questions, the first group of questions decides the class
# of attack; you can see three main branches in the decision tree. And, the second question finds the specific type of attack
# The questions are asked using InputManager which is nothing more than a simple function that takes a string - the question
# you're asking - and returning true if the input is "yes" or false if "no". The function converts the input to lower case and asks
# you to repeat the input if you type in anything other than yes/no.
# The variables are stored in three structs, each one related to each class of attack: Malware, DDoS and Phishing. It makes working with
# those variables and printing them a lot cleaner since there are so many variables/rules. Since all the malware and phishing
# variables are bools, there is a single function in variable.h to get/set them using an index.
# The backwards and forward chain run their own knowledge base - forward chaining integrated it into its own cpp -, and they in return are
# called in the main.cpp when they are created using their constructors.
