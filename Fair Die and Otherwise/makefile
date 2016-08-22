#########################################################
# Author: Chris Kearns (kearnsc)
# Date: 01/24/2016
# File: Makefile
# Description: makefile for Lab3 CS162-400-W16. 
# Edit the variables under "USER SECTION" as needed.
# To execute the makefile on unix-y systems, type 'make'.
# If that doesn't work, try 'make -f makefile'.
#########################################################

# #'s are line-comments 

# CXX is a standard variable name used for the compiler. 
CXX = g++

# CXXFLAGS is a standard variable name for compile flags.
# -std=c++0x specifies to use the latest language version.
CXXFLAGS = -std=c++0x

# -Wall turns on all warnings
CXXFLAGS += -Wall

# -pedantic-errors strictly enforces the standard
CXXFLAGS += -pedantic-errors

# -g turns on debug information 
CXXFLAGS += -g

####################
### USER SECTION ###
####################

# SRCS is a standard name for the source files (.cpp). 
# Edit as needed.
#SRC1 = Main.cpp
SRC2 = Die.cpp
SRC3 = LoadedDie.cpp
SRC4 = Player.cpp
SRC5 = Game.cpp
#SRC6 = 
#SRC7 = 
#SRC8 = 
SRCS = ${SRC2} ${SRC3} ${SRC4} ${SRC5}

# HEADERS is a standard name for the header files (.hpp). 
# Edit as needed.
HEADER1 = Die.hpp
HEADER2 = LoadedDie.hpp
HEADER3 = Player.hpp
HEADER4 = Game.hpp
#HEADER5 = 
#HEADER6 = 
#HEADER7 =
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4}

# Your executable files. 
# Edit as needed.
PROG1 = rollem
# PROG2 = 
# PROG3 = 
PROGS = ${PROG1}

# This is the name of your document(s). 
# Edit as needed.
# DOC = my_writeup.pdf

# This is the name of your tar/compressed file. 
# Edit name as needed. Keep the format.
TAR = cs162_xxxxxx_kearnsc.tar.bz2

#####################
### BUILD SECTION ###
#####################

# MAKE
# Typing 'make' in terminal calls the first build available.
# In this case, default.
default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}

# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}

# TAR
# Typing 'make tar' in terminal calls this build.
# This creates a consolidated but not compressed file.
# Note: ${DOC} removed for this makefile.
# tar modifiers: c = create new archive, v = verbosely list each file as its compressed/extracted, j = read/write using the bzip2 compressor, f = use archive file ARCHIVE.
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} makefile

# CLEAN
# Typing 'make clean' calls this build.
# It's designed to clean up the folder.
# Be careful with this, edit as needed.
# rm means remove file.
# -f means --force or you don't need access privelege to the file, only the parent directory and no "confirm remove" is offered.
# ${PROGS} means remove the executable file(s) specified above.
# *.o means remove the object files created by the compile process for linking.
# *~ means remove temp files. 
clean:
	rm -f ${PROGS} *.o *~