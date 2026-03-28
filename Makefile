#
# Makefile for film.px
#

# make grammar documentation:
doc:	fiml-rr.html
fiml-rr.html: fiml.px
	../px/px -r fiml.px > fiml-rr.html
