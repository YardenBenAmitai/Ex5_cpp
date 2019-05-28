
namespace itertools{
	
	template<typename T1, typename T2>
	class product{
		
		private:
		T1 container1;
		T2 container2;
		
		public:
		
		class const_iterator {
			
			private:
			typename T1::const_iterator current1;
			typename T1::const_iterator stop1;
			
			typename T2::const_iterator current2;
			typename T2::const_iterator start2;
			typename T2::const_iterator stop2;
			
			public:
			
			const_iterator(const typename T1::const_iterator& begin1, const typename T1::const_iterator& end1, const typename T2::const_iterator& begin2, const typename T2::const_iterator& end2):
				current1(begin1), stop1(end1), current2(begin2), start2(begin2), stop2(end2) {
				if(stop2==start2 || current1==stop1){
					current1=stop1;
					current2=stop2;
				}
			}
			
			auto operator*() const {
				 return pair(*current1, *current2);
			}
			
			bool operator==(const const_iterator& o) const {
				return (current1==o.current1 && current2==o.current2);
			}
			
			bool  operator!=(const const_iterator& o) const {
				return !(current1==o.current1 && current2==o.current2);
			}
			
			const_iterator&  operator++() {
				++(current2);
				if(current2==stop2){
					current2=start2;
					++(current1);
				}
				return *this;
			}
			
			const_iterator& operator++(int){
				const_iterator t= *this;
				(current2)++;
				if(current2==stop2){
					current2=start2;
					(current1)++;
				}
				return t;
			}
			
			
			ostream& operator<<(ostream& os){
				os<<*current1<<","<<*current2;
				return os;
			}
			
		};
		
		
		
		product(const T1 c1, const T2 c2): container1(c1), container2(c2){ }
		
		const_iterator begin() const{
			return product::const_iterator(container1.begin(), container1.end(), container2.begin(), container2.end());
		}
		
		const_iterator end() const{
			return product::const_iterator(container1.end(), container1.end(), container2.begin(), container2.end());
		}
		
	};
	
	
}
