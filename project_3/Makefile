#
# In order to execute this "Makefile" just type "make"
#

OBJS 	= main.o ./read_data.o ./sentiment_analysis.o ./tweets.o ./coins.o ./dataset.o ./preprocessing.o ./normalization.o ./assignment.o ./mymath.o ./cluster.o ./initialization.o ./hash_helper.o ./LSH.o ./NN.o ./edges.o ./hypercube.o ./update.o ./evaluation.o ./clustering_routine.o ./neighboor.o ./prediction.o ./read_analyzed_data.o ./twits_of_clusters.o
OUT  	= recommendation
CC	= g++
FLAGS   = -g -c -pedantic -ansi  -Wall -std=c++11
# -g option enables debugging mode 
# -c flag generates object code for separate files

$(OUT): $(OBJS)
	$(CC) -g $(OBJS) -o $@

# create/compile the individual files >>separately<< 

main.o: ./main.cpp
	$(CC) $(FLAGS) ./main.cpp

read_data.o: ./current_project/read_data.cpp
	$(CC) $(FLAGS) ./current_project/read_data.cpp

sentiment_analysis.o: ./current_project/sentiment_analysis.cpp
	$(CC) $(FLAGS) ./current_project/sentiment_analysis.cpp

tweets.o: ./current_project/tweets.cpp
	$(CC) $(FLAGS) ./current_project/tweets.cpp	

coins.o: ./current_project/coins.cpp
	$(CC) $(FLAGS) ./current_project/coins.cpp	

dataset.o: ./previous_projects/dataset.cpp
	$(CC) $(FLAGS) ./previous_projects/dataset.cpp

preprocessing.o: ./current_project/preprocessing.cpp
	$(CC) $(FLAGS) ./current_project/preprocessing.cpp

normalization.o: ./current_project/normalization.cpp
	$(CC) $(FLAGS) ./current_project/normalization.cpp

assignment.o: ./previous_projects/assignment.cpp
	$(CC) $(FLAGS) ./previous_projects/assignment.cpp

mymath.o: ./previous_projects/mymath.cpp
	$(CC) $(FLAGS) ./previous_projects/mymath.cpp	

cluster.o: ./previous_projects/cluster.cpp
	$(CC) $(FLAGS) ./previous_projects/cluster.cpp	

initialization.o: ./previous_projects/initialization.cpp
	$(CC) $(FLAGS) ./previous_projects/initialization.cpp

hash_helper.o: ./previous_projects/hash_helper.cpp
	$(CC) $(FLAGS) ./previous_projects/hash_helper.cpp

LSH.o: ./previous_projects/LSH.cpp
	$(CC) $(FLAGS) ./previous_projects/LSH.cpp			

NN.o: ./previous_projects/NN.cpp
	$(CC) $(FLAGS) ./previous_projects/NN.cpp		

edges.o: ./previous_projects/edges.cpp
	$(CC) $(FLAGS) ./previous_projects/edges.cpp	

hypercube.o: ./previous_projects/hypercube.cpp
	$(CC) $(FLAGS) ./previous_projects/hypercube.cpp	

update.o: ./previous_projects/update.cpp
	$(CC) $(FLAGS) ./previous_projects/update.cpp	

evaluation.o: ./previous_projects/evaluation.cpp
	$(CC) $(FLAGS) ./previous_projects/evaluation.cpp	
	
clustering_routine.o: ./current_project/clustering_routine.cpp
	$(CC) $(FLAGS) ./current_project/clustering_routine.cpp

neighboor.o: ./current_project/neighboor.cpp
	$(CC) $(FLAGS) ./current_project/neighboor.cpp

prediction.o: ./current_project/prediction.cpp
	$(CC) $(FLAGS) ./current_project/prediction.cpp

read_analyzed_data.o: ./previous_projects/read_analyzed_data.cpp
	$(CC) $(FLAGS) ./previous_projects/read_analyzed_data.cpp

twits_of_clusters.o: ./current_project/twits_of_clusters.cpp
	$(CC) $(FLAGS) ./current_project/twits_of_clusters.cpp

# clean house
clean:
	rm -f $(OBJS) $(OUT)