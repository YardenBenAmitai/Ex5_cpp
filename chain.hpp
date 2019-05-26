#include <iostream>

namespace itertools{
	
	template<typename T1, typename T2>
	class chain{
		
		private:
		T1 container1;
		T2 container2;
		
		public:
		
		class const_iterator {
			
			private:
			typename T1::const_iterator current1;
			typename T1::const_iterator stop;
			typename T2::const_iterator current2;
			bool swap=false;
			
			public:
			
			const_iterator(const typename T1::const_iterator& begin1, const typename T1::const_iterator& end1, const typename T2::const_iterator& begin2):
				current1(begin1), stop(end1), current2(begin2) {
					if(current1==stop){
						swap=true;
					}
				}
			
			 const auto operator*() const {
				 if(swap){
					 return *current2;
				 } else {
					 return *current1;
				 }
			}
			
			bool operator==(const const_iterator& o) const {
				return (current1==o.current1 && current2==o.current2);
			}
			
			bool  operator!=(const const_iterator& o) const {
				return !(current1==o.current1 && current2==o.current2);
			}
			
			const_iterator&  operator++() {
				if(swap){
					++(current2);
				} else {
					++(current1);
					if(current1==stop){
						swap=true;
					}
				}
				return *this;
			}
			
			const_iterator& operator++(int){
				const_iterator t= *this;
				if(swap){
					(current2)++;
				} else {
					(current1)++;
					if(current1==stop){
						swap=true;
					}
				}
				return t;
			}
			
			ostream& operator<<(ostream& os){
				os<<*this;
				return os;
			}
		};
		
		
		chain(const T1 c1, const T2 c2): container1(c1), container2(c2){ }
		
		const_iterator begin() const{
			return chain::const_iterator(container1.begin(), container1.end(), container2.begin());
		}
		
		const_iterator end() const{
			return chain::const_iterator(container1.end(), container1.end(), container2.end());
		}
		
		
	};	
}