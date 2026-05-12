// application looks at the different efficiencies of:

// 1. pass by const Type& name
// 2. copy/pass-by-value

// a benchmarking application

// running the program (with optimization level-2):

// $ g++ -std=c++20 -O2 main.cpp -o benchmark
// $ ./benchmark

#include <iostream>
#include <vector>
#include <numeric> // accumulate
#include <chrono> // for timing

// pass-by-value: copies the entire vector
double processByValue(std::vector<double> values) {

	return std::accumulate(values.begin(), values.end(), 0.0); // accumulate/add up all values: 1 + 1 + 1 + ... + 1 = 1e7
}

// pass-by-const-reference
double processByConstReference(const std::vector<double>& values) {

	return std::accumulate(values.begin(), values.end(), 0.0); // accumulate/add up all values: 1 + 1 + 1 + ... + 1 = 1e7
}

int main() {

	// size of vector
	constexpr std::size_t vectorSize {10'000'000};
	constexpr int repetitions {20};

	std::vector<double> data(vectorSize, 1.0); // vector to work with

	volatile double result {0.0}; // prevents optimiser from removing work

	// start timing for pass-by-value
	auto startValue {std::chrono::high_resolution_clock::now()};

	// pass-by-value
	for (int i {0}; i < repetitions; ++i) {

		result = processByValue(data);
	}

	// end timing for pass-by-value pattern
	auto endValue {std::chrono::high_resolution_clock::now()};

	// start timing for pass-by-const-ref pattern
	auto startRef {std::chrono::high_resolution_clock::now()};

	// pass-by-const-ref pattern
	for (int i {0}; i < repetitions; ++i) {

		result = processByConstReference(data);
	}

	// end timing for pass-by-const-ref pattern
	auto endRef {std::chrono::high_resolution_clock::now()};

	// time elapsed for pass-by-value pattern
	auto valueTime {std::chrono::duration<double>(endValue - startValue).count()};

	// time elapsed for pass-by-const-ref pattern
	auto valueRef {std::chrono::duration<double>(endRef - startRef).count()};

	// -- display results

	std::cout<<"Vector size: "<<vectorSize<<"\n";
	std::cout<<"Number of iterations: "<<repetitions<<"\n";

	std::cout<<"Pass-By-Value Pattern Time: "<<valueTime<<"s\n";
	std::cout<<"Pass-By-Const-Reference Pattern Time: "<<valueRef<<"s\n";

	double speed_diff {valueTime/valueRef};

	std::cout<<"Passing a Vector by const-ref is "<<speed_diff<<" times faster than by-value\n";

	std::cout<<"Final Result: "<<result<<"\n";
}
