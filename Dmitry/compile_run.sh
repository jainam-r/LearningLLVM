clang++ -o LearningLLVM `llvm-config --cxxflags --ldflags --system-libs --libs core` evallvm.cpp
./eva-llvm

lli ./out.ll
