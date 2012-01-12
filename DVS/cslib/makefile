
CXX=gcc

CXXFLAGS=-O2 -Wall


WORKER_SERVER_OBJ = obj/worker_server.o

WORKER_CLIENT_OBJ = libclient/worker_client.o

MYSTDLIB_OBJ =  libmystd/list.o \ 
		libmystd/queue.o \
		libmystd/threadpool.o

clean:
	rm -f obj/*.o lib/*.o client_test worker_server

all:worker_server client_test
	
worker_server:$(WORKER_SERVER_OBJ)
	$(CXX) $(CXXFLAGS) -o worker_server $(WORKER_SERVER_OBJ) 

obj/worker_server-	.o:src/worker_server.c src/worker_server.h include/services_list.h 
	$(CXX) $(CXXFLAGS) -Iinclude -c -o obj/worker_server.o src/worker_server.c 


client_test:$(WORKER_CLIENT_OBJ) test/test_client.c
	$(CXX) $(CXXFLAGS) -Iinclude -o client_test $(WORKER_CLIENT_OBJ) test/test_client.c

libclient/worker_client.o:libclient/worker_client.c include/worker_client.h include/services_list.h 
	$(CXX) $(CXXFLAGS) -Iinclude -c -o libclient/worker_client.o libclient/worker_client.c 


#libmystd 
#..........................................




libmystd/list.o:libmystd/list.h libmystd/list.c 
	$(CXX) $(CXXFLAGS) -Ilibmystd -c -o libmystd/list.o libmystd/list.c

libmystd/queue.o:libmystd/queue.h libmystd/queue.c 
	$(CXX) $(CXXFLAGS) -Ilibmystd -c -o libmystd/queue.o libmystd/queue.c

libmystd/threadpool.o:libmystd/threadpool.h libmystd/threadpool.c 
	$(CXX) $(CXXFLAGS) -Ilibmystd -c -o libmystd/threadpool.o libmystd/threadpool.c



