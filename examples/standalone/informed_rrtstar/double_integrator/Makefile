include ../../../common.mk


#-----------------------------------------------------------------------------
# Program
#-----------------------------------------------------------------------------

SMP = $(SMP_BIN_PATH)/example_standalone_informed_rrtstar_double_integrator

SMP_OBJ_COMPILE = standalone_informed_rrtstar_double_integrator.o \
	$(SMP_SRC_PATH)/smp/external_libraries/kdtree/kdtree.o 

SMP_OBJ = standalone_informed_rrtstar_double_integrator.o \
	$(SMP_SRC_PATH)/smp/external_libraries/kdtree/kdtree.o 




#-----------------------------------------------------------------------------
# Make the program
#-----------------------------------------------------------------------------

all: 
	$(MAKE) targets

default: 
	$(MAKE) targets	

targets:  $(SMP) 


$(SMP): $(SMP_OBJ) 
	$(LDXX) $(SMP_OBJ_COMPILE) -o $(SMP) $(LDFLAGS) 




#-----------------------------------------------------------------------------
# Cleaning
#-----------------------------------------------------------------------------

clean:
	-find ./ -name \*.o -exec rm {} \;
	-find ./ -name \*.gch -exec rm {} \;
