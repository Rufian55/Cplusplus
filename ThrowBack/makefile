#########################################################
# Author: Chris Kearns
# Date: 03/15/2016
# File: makefile
# Description: makefile for ThrowBack. 
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
SRC1 = Space.cpp
SRC2 = Blue.cpp
SRC3 = Yellow.cpp
SRC4 = Cyan.cpp
SRC5 = Green.cpp
SRC6 = Red.cpp
SRC7 = Magenta.cpp
SRC8 = White.cpp
SRC9 = GrandPrize.cpp
SRC10 = ThrowBack.cpp
SRC11 = Main.cpp

SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8} ${SRC9} ${SRC10} ${SRC11}

# HEADERS is a standard name for the header files (.hpp). 
# Edit as needed.
HEADER1 = Space.hpp
HEADER2 = Blue.hpp
HEADER3 = Yellow.hpp
HEADER4 = Cyan.hpp
HEADER5 = Green.hpp
HEADER6 = Red.hpp
HEADER7 = Magenta.hpp
HEADER8 = White.hpp
HEADER9 = GrandPrize.hpp
HEADER10 = ThrowBack.hpp

HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4} ${HEADER5} ${HEADER6} ${HEADER7} ${HEADERS8} ${HEADER9} ${HEADER10}

# Your executable files. 
# Edit as needed.
PROG1 = throwback
PROGS = ${PROG1}

# This is the name of your document(s). 
# Edit as needed.
#DOC = editMe.pdf

# This is the name of your tar/compressed file. 
# Edit name as needed. Keep the format.
TAR = editMe.tar.bz2

#####################
### BUILD SECTION ###
#####################

# MAKE
# Typing 'make' in terminal calls the first build available.
# In this case, default.
throwback: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}

# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}

# Typing 'make zip' in terminal creates a zip file of the project.
zip:
	zip throwBack.zip *.cpp *.hpp *.pdf makefile throwback

# TAR
# Typing 'make tar' in terminal calls this build.
# This creates a consolidated but not compressed file.
# Note: ${DOC} removed for this makefile.
# tar modifiers: c = create new archive, v = verbosely list each file as its compressed/extracted, j = read/write using the bzip2 compressor, f = use archive file ARCHIVE.
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} makefile MYEXECUTABLE...

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
