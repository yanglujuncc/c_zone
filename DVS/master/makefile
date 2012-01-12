
CXX=gcc

CXXFLAGS=-O2 -Wall


MASTER_SERVER_OBJ=obj/master_server.o 


#for client_test
MASTER_CLIENT_OBJ=obj/master_client.o 




master_server:$(MASTER_SERVER_OBJ)
	$(CXX) $(CXXFLAGS) -o master_server $(MASTER_SERVER_OBJ) 

obj/master_server.o:src/master_server.c  src/master_server.h include/services_list.h
	$(CXX) $(CXXFLAGS) -Iinclude -c -o obj/master_server.o src/master_server.c


#for test client 
client_test:$(MASTER_CLIENT_OBJ)
	$(CXX) $(CXXFLAGS) -o client_test $(MASTER_CLIENT_OBJ) 

obj/master_client.o:src/master_client.c  src/master_client.h include/services_list.h
	$(CXX) $(CXXFLAGS) -Iinclude -c -o obj/master_client.o src/master_client.c

