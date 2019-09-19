#
# In order to execute this "Makefile" just type "make"
#

OBJS = test_main.o test_mymath.o \
mymath.o dataset.o
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

# Files TO Test
mymath.o: ../mymath.cpp
	$(CC) $(FLAGS) ../mymath.cpp $(LIBS)

dataset.o: ../dataset.cpp
	$(CC) ${FLAGS} ../dataset.cpp $(LIBS)

# clean house
clean:
	rm -f $(OBJS) $(OUT)