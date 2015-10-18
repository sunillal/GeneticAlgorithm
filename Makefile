#Sunil Lal

CC = g++ 
TARGET = knapsack
SOURCE = driver.cpp GAEngine.cpp Chromosome.cpp
HEADERS = GAEngine.h Chromosome.h constants.h
OBJS   = $(SOURCE:.cpp=.o)

all:$(SOURCE) $(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CC) -c $< -o $@

$(OBJS):$(HEADERS)

clean:
	rm $(TARGET) $(OBJS)
