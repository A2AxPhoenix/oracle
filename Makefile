a.out: decision.o college.o picker.o
	g++ decision.o college.o picker.o

picker.o: picker.cc decision.h college.h
	g++ -c picker.cc

decision.o: decision.cc decision.h college.h
	g++ -c decision.cc

college.o: college.h college.cc
	g++ -c college.cc

clean:
	rm -f *.o a.out
