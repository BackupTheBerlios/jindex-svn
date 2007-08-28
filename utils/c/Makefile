CC = gcc
JAVA_HOME=/opt/sun-jdk-1.6.0.02
JAVA_INCLUDE=$(JAVA_HOME)/include
JAVA_INCLUDE_ARCH=$(JAVA_INCLUDE)/linux
CFLAGS=-fPIC -Wall -O2 `pkg-config --cflags gtk+-2.0 gnome-vfs-2.0 gnome-vfs-module-2.0 libinotify` -I$(JAVA_INCLUDE) -I$(JAVA_INCLUDE_ARCH)
LDFLAGS=`pkg-config --libs gtk+-2.0 gnome-vfs-2.0 gnome-vfs-module-2.0 libinotify` --shared

libInotify: libInotify.c
libJIndex: libJIndex.c
all: libJIndex libInotify

clean:
	rm  libJIndex libInotify *.class
	
install:
	cp libJIndex ../../libs/native/i386/libJIndex.so
	

