#
# In order to execute this "Makefile" just type "make"
#

OBJS 	= main.o ./dataset.o ./read_data.o ./edges.o ./mymath.o ./hypercube.o ./NN.o ./LSH_part.o ./nearest_point.o ./bruteforce.o
OUT  	= hypercube
CC	= g++
FLAGS   = -g -c -pedantic -ansi  -Wall -std=c++11
# -g option enables debugging mode 
# -c flag generates object code for separate files

$(OUT): $(OBJS)
	$(CC) -g $(OBJS) -o $@

# create/compile the individual files >>separately<< 

dataset.o: ./dataset.cpp
	$(CC) $(FLAGS) ./dataset.cpp

read_data.o: ./read_data.cpp
	$(CC) $(FLAGS) ./read_data.cpp

edges.o: ./edges.cpp
	$(CC) $(FLAGS) ./edges.cpp

mymath.o: ./mymath.cpp
	$(CC) $(FLAGS) ./mymath.cpp	

hypercube.o: ./hypercube.cpp
	$(CC) $(FLAGS) ./hypercube.cpp	

NN.o: ./NN.cpp
	$(CC) $(FLAGS) ./NN.cpp	

LSH_part.o: ./LSH_part.cpp
	$(CC) $(FLAGS) ./LSH_part.cpp	

nearest_point.o: ./nearest_point.cpp
	$(CC) $(FLAGS) ./nearest_point.cpp	

bruteforce.o: ./bruteforce.cpp
	$(CC) $(FLAGS) ./bruteforce.cpp	

# clean house
clean:
	rm -f $(OBJS) $(OUT)