#
# In order to execute this "Makefile" just type "make"
#

OBJS 	= main.o ./dataset.o ./read_data.o ./assignment.o ./mymath.o ./cluster.o ./initialization.o ./hash_helper.o ./LSH.o ./NN.o ./edges.o ./hypercube.o ./update.o ./evaluation.o
OUT  	= cluster
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

assignment.o: ./assignment.cpp
	$(CC) $(FLAGS) ./assignment.cpp

mymath.o: ./mymath.cpp
	$(CC) $(FLAGS) ./mymath.cpp	

cluster.o: ./cluster.cpp
	$(CC) $(FLAGS) ./cluster.cpp	

initialization.o: ./initialization.cpp
	$(CC) $(FLAGS) ./initialization.cpp

hash_helper.o: ./hash_helper.cpp
	$(CC) $(FLAGS) ./hash_helper.cpp

LSH.o: ./LSH.cpp
	$(CC) $(FLAGS) ./LSH.cpp			

NN.o: ./NN.cpp
	$(CC) $(FLAGS) ./NN.cpp		

edges.o: ./edges.cpp
	$(CC) $(FLAGS) ./edges.cpp	

hypercube.o: ./hypercube.cpp
	$(CC) $(FLAGS) ./hypercube.cpp	

update.o: ./update.cpp
	$(CC) $(FLAGS) ./update.cpp	

evaluation.o: ./evaluation.cpp
	$(CC) $(FLAGS) ./evaluation.cpp	

# clean house
clean:
	rm -f $(OBJS) $(OUT)