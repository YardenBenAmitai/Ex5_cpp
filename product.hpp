
namespace itertools{
	struct ProductIterable {
		int* begin() const { return nullptr; }
		int* end() const { return nullptr; }
	};
	
	template<typename T1, typename T2>
	ProductIterable product(T1 a, T2 b) {
		return ProductIterable{}; 
	}
}