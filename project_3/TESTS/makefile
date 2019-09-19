#
# In order to execute this "Makefile" just type "make"
#

OBJS = test_main.o test_mymath.o test_sentiment_analysis.o \
mymath.o dataset.o sentiment_analysis.o tweets.o
OUT	= tests
CC = g++ -g
FLAGS = -c -Wall -std=c++11 -pthread
LIBS = -lgtest_main -lgtest -lpthread
# -g option enables debugging mode 
# -c flag generates object code for separate files

$(OUT): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $@

# Test Files
test_main.o: test_main.cpp
	$(CC) $(FLAGS) test_main.cpp $(LIBS)

test_mymath.o: test_mymath.cpp
	$(CC) $(FLAGS) test_mymath.cpp $(LIBS)

test_sentiment_analysis.o: test_sentiment_analysis.cpp
	$(CC) $(FLAGS) test_sentiment_analysis.cpp $(LIBS)

# Files TO Test
mymath.o: ../previous_projects/mymath.cpp
	$(CC) $(FLAGS) ../previous_projects/mymath.cpp $(LIBS)

dataset.o: ../previous_projects/dataset.cpp
	$(CC) ${FLAGS} ../previous_projects/dataset.cpp $(LIBS)

sentiment_analysis.o: ../current_project/sentiment_analysis.cpp
	$(CC) ${FLAGS} ../current_project/sentiment_analysis.cpp $(LIBS)
	
tweets.o: ../current_project/tweets.cpp
	$(CC) ${FLAGS} ../current_project/tweets.cpp $(LIBS)

# clean house
clean:
	rm -f $(OBJS) $(OUT)