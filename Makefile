check_cuda: check_cuda.cpp
	nvcc -o $@ $^
