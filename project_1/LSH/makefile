#
# In order to execute this "Makefile" just type "make"
#

OBJS 	= main.o ./dataset.o ./read_data.o ./LSH.o ./mymath.o ./hash_helper.o ./NN.o ./nearest_point.o ./bruteforce.o
OUT  	= LSH_routine
CC	= g++
FLAGS   = -g -c -pedantic -ansi  -Wall -std=c++11
# -g option enables debugging mode 
# -c flag generates object code for separate files

$(OUT): $(OBJS)
	$(CC) -g $(OBJS) -o $@

# create/compile the individual files >>separately<< 

main.o: ./main.cpp
	$(CC) $(FLAGS) ./main.cpp

dataset.o: ./dataset.cpp
	$(CC) $(FLAGS) ./dataset.cpp

read_data.o: ./read_data.cpp
	$(CC) $(FLAGS) ./read_data.cpp

LSH.o: ./LSH.cpp
	$(CC) $(FLAGS) ./LSH.cpp

mymath.o: ./mymath.cpp
	$(CC) $(FLAGS) ./mymath.cpp	

hash_helper.o: ./hash_helper.cpp
	$(CC) $(FLAGS) ./hash_helper.cpp	

NN.o: ./NN.cpp
	$(CC) $(FLAGS) ./NN.cpp	

nearest_point.o: ./nearest_point.cpp
	$(CC) $(FLAGS) ./nearest_point.cpp	

bruteforce.o: ./bruteforce.cpp
	$(CC) $(FLAGS) ./bruteforce.cpp	
# clean house
clean:
	rm -f $(OBJS) $(OUT)