src=$(shell find ./ -name "*.cpp")
obj=$(src:%.cpp=%.o)
target=tic-tac-toe
cc=g++ -std=c++11
cflags=-g
$(target):$(obj)
	$(cc) -o $@ $^  $(cflags)
%.o:%.cpp
	$(cc) -c $< -o $@ $(cflags)
clean:
	rm -rf $(obj) $(target) core
