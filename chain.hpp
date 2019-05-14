
#include <iostream>
using namespace std;

		
namespace itertools{
	struct ChainIterable {
		int* begin() const { return nullptr; }
		int* end() const { return nullptr; }
	};
	
	template<typename T1, typename T2>
	ChainIterable chain(T1 a, T2 b) {
		return ChainIterable{}; 
	}
}
