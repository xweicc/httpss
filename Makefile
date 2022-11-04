
OBJS = ./source/main.o ./source/timer.o ./source/hosttoip.o
CFLAGS = -I include -Wall -g

ifeq ($(CC),cc)
	SSL_STATIC_LIB = ./source/libssl.a  ./source/libcrypto.a -ldl
else
	OPENSSL_PATH = /data/MT7621/user/jhl_tools/openssl-1.0.2o
	SSL_FLAGS = -I$(OPENSSL_PATH)/include -L$(OPENSSL_PATH) -lssl -lcrypto 
	CFLAGS += $(SSL_FLAGS)
endif

all:show httpss

show:
	@echo CC=$(CC)
	@echo OPENSSL_PATH=$(OPENSSL_PATH)
	@echo CFLAGS=$(CFLAGS)
	@echo SSL_FLAGS=$(SSL_FLAGS)
	@echo SSL_STATIC_LIB=$(SSL_STATIC_LIB)
	
httpss:$(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(SSL_STATIC_LIB)

clean:
	rm -f ./source/*.o httpss

