#
# Makefile for fiml-px
#

CXX	=	g++
CXXFLAGS =	-std=c++11

STRPP	=	../strpp

COPT	=	-DHAVE_PTHREADS # -DPEG_TRACE

DEBUG	=	-O2 $(COPT)
# DEBUG	=	-g $(COPT) -DUTF8_ASSERT
# DEBUG	=	-O2 $(COPT) -lprofiler
# DEBUG	=	-g -DTRACK_RESULTS $(COPT)

HDRS	=	\

SRCS	=	\
		fiml.cpp

OBJS	=	$(patsubst %,%,$(SRCS:.cpp=.o))

LIBS	=	-L$(STRPP) -lstrpp

vpath	%.h	.:$(STRPP)/include
vpath	%.a	$(STRPP)

fiml:	Makefile peg_ast.h $(HDRS) $(SRCS) fiml_parser.cpp
	$(CXX) $(DEBUG) $(CXXFLAGS) -I. -I$(STRPP)/include -I$(STRPP)/test -o $@ $(SRCS) $(STRPP)/test/memory_monitor.cpp $(LIBS)

# Regenerate fiml_parser from fiml.px:
fiml_parser.cpp: fiml.px
	../px/px fiml.px >fiml_parser.cpp

# make grammar documentation:
doc:	fiml-rr.html
fiml-rr.html: fiml.px
	../px/px -r fiml.px > fiml-rr.html

# make all
all: fiml doc
