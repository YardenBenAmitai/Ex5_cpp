#include <iostream>
#include <string>
using namespace std;


namespace itertools{
	
	string toString(const int t) {
		return to_string(t);
	}
	string toString(const double t) {
		return to_string(t);
	}
	string toString(const char t){
		string s(1,t);
		return s;
	}
	string toString(const string t){
		return t;
	}
		
	template <typename P1, typename P2>
	string toString (const pair<P1,P2> &p) {
		string result=toString(p.first);
		result.append(",");
		result.append(toString(p.second));
		return result;
	}
	
	
	template <class F, class S>
	ostream& operator<< (ostream& os, const pair<F, S> &p){
		os<<toString(p.first)<<","<<toString(p.second);
		return os;
	}
	
	
	template<typename T1, typename T2>
	class zip{
		
		private:
		T1 container1;
		T2 container2;
		
		public:
		
		class const_iterator {
			
			private:
			typename T1::const_iterator current1;
			typename T2::const_iterator current2;
			
			public:
			
			const_iterator(const typename T1::const_iterator& begin1, const typename T2::const_iterator& begin2):
				current1(begin1), current2(begin2) {}
			
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
				++(current1);
				++(current2);
				return *this;
			}
			
			const_iterator& operator++(int){
				const_iterator t= *this;
				(current1)++;
				(current2)++;
				return t;
			}
			
			
			ostream& operator<<(ostream& os){
				os<<*current1<<","<<*current2;
				return os;
			}
			
			
			string toString( const const_iterator& o){
				return toString(*o);
			}
			
		};
		
		
		
		zip(const T1 c1, const T2 c2): container1(c1), container2(c2){ }
		
		const_iterator begin() const{
			return zip::const_iterator(container1.begin(), container2.begin());
		}
		
		const_iterator end() const{
			return zip::const_iterator(container1.end(), container2.end());
		}
		
	};
	
	
}