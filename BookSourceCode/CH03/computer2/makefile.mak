TARGETS = test_Computer
CC = cl
CPPFLAGS = /Zi /EHsc /GR

all: $(TARGETS)

test_Computer:	test_Computer.obj Computer.obj Lap_Top.obj
	$(CC) $(CPPFLAGS) /Fe$@ $**

test_Computer.obj:	test_Computer.cpp Computer.h Lap_Top.h
	$(CC) $(CPPFLAGS) /c test_Computer.cpp

Computer.obj:	Computer.cpp Computer.h
	$(CC) $(CPPFLAGS) /c Computer.cpp

Lap_Top.obj:	Lap_Top.cpp Lap_Top.h Computer.h
	$(CC) $(CPPFLAGS) /c Lap_Top.cpp
 
clean:
	del *.obj
	del *.exe
	del *.pdb
	del *.ilk

