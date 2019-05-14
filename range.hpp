#include <iostream>


using namespace std;

namespace itertools{
	
	
	
	template <typename T> class range{
		
		class Iterator {
			public:
			T itr_;
			Iterator(){}
			Iterator(T i){itr_=i; }
			
			auto operator*() const { return itr_;}
			
			bool operator==(const Iterator& o) const { return (this->itr_ == o.itr_); }
			
			bool  operator!=(const Iterator& o) const { return !(this->itr_ == o.itr_); }
			
			Iterator&  operator++() {
				++(itr_);
				return *this;
			}
			/**
			Itr* clone() const {
				Itr<T> n;
				n.itr_=this->itr_;
				return n;
			}
			**/
			Iterator& operator=(const Iterator& o) {
				this->itr_ = o.itr_;
				return *this;
			}
		};
	
		protected:
		T first;
		T last;
		
		public:
		range(){}
		
		range(T b, T e){
			this->first=b;
			this->last=e;
		}
		
		range(const range& r){
			this->first= *r.begin();
			this->last= *r.end();
		}
		
		Iterator begin() const{
			//cout<<"range begin "<<first<<"  "<<last<<endl;
			Iterator i(first);
			return i;
		}
		
		Iterator end() const{
			//cout<<"range end "<<first<<endl;
			Iterator i(last);
			return i;
		}
	};
}