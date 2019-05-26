#include <iostream>


using namespace std;

namespace itertools{
	
	template <typename T> 
	class range{
		
		private:
		T first;
		T last;
		
		public:
		
		class const_iterator {
			
			private:
			T iterator;
			
			public:
			const_iterator(T i): iterator(i) { }
			
			const T operator*() const { return iterator;}
			
			bool operator==(const const_iterator& o) const { return (iterator == o.iterator); }
			
			bool  operator!=(const const_iterator& o) const { return !(iterator == o.iterator); }
			
			const_iterator&  operator++() {
				++(iterator);
				return *this;
			}
			
			const_iterator& operator++(int){
				const_iterator t= *this;
				(iterator)++;
				return t;
			}
			
			ostream& operator<<(ostream& os){
				os<<iterator;
				return os;
			}
		};
		
		
		range(T b, T e): first(b), last(e){ }
		
		range(const range& r): first(r.first), last(r.last) { }
		
		const_iterator begin() const{
			return range::const_iterator(first);
		}
		
		const_iterator end() const{
			return range::const_iterator(last);
		}
	};
}