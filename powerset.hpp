
namespace itertools{
	
	struct PowersetIterable {
		int* begin() const { return nullptr; }
		int* end() const { return nullptr; }
	};
	
	template<typename T1>
	PowersetIterable powerset(T1 a) {
		return PowersetIterable{}; 
	}
	
}