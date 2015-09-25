#include <iostream>
#include <omp.h>

int main()
{
	omp_set_num_threads(8);
	#pragma omp parallel
	{
		std::cout << omp_get_thread_num() << " " << omp_get_num_threads() << " " << "Hello, World!" << std::endl;
	}
	return 0;
}
