src=$(shell find ./ -name "*.cpp")
obj=$(src:%.cpp=%.o)
target=tic-tac-toe
cc=g++ -std=c++11
$(target):$(obj)
	$(cc) -o $@ $^
%.o:%.cpp
	$(cc) -c $< -o $@
clean:
	rm -rf $(obj) $(target)
