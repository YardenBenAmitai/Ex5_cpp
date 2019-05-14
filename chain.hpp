
#include <iostream>
using namespace std;

namespace itertools{
	
	template <typename T1, typename T2> class ContainerItr{
		
		public:
		T1 itr_;
		T1 stop;
		T2 start;
		bool replaced=false;
		
		ContainerItr(){ }
		
		ContainerItr(T1 a, T2 b){
			this->stop=a;
			this->start=b;
			this->itr_=a;
		}
		//~Itr() {delete itr_;}
		
		auto getItr() const{
			if(replaced)
				return (decltype(this->itr_.itr_)) *(this->start);
			return *(this->itr_);
		}
		
		auto operator*() const{
			return this->getItr();
		}
		
		bool operator==(const ContainerItr& o) const {
			return (this->getItr() == o.getItr());
		}
		
		bool  operator!=(const ContainerItr& o) const { return !(*this == o); }
		
		ContainerItr&  operator++() {
			if(replaced)
				++(start);
			else{
				++(itr_);
				if(*this->itr_== *this->stop)
					replaced=true;
			}
			return *this;
		}
		
		ContainerItr* clone() const {
			ContainerItr<T1, T2> n(this->stop, this->start);
			n.itr_=this->itr_;
			return n;
		}
		
		ContainerItr& operator=(const ContainerItr& o) {
			//delete itr_;
			this->getItr().ite_= (o.getItr().itr_)->clone();
			return *this;
		}
	};
	
	
	template <typename Container1, typename Container2> class chain{
		protected:
		Container1* start1;
		Container2* start2;
		
		public:
		chain(Container1 f, Container2 s){
			this->start1=&f;
			this->start2=&s;
		}
		
		auto begin(){
			ContainerItr it (this->start1->end() , this->start2->begin());
			it.itr_=this->start1->begin();
			return it;
		}
		
		auto end(){
			ContainerItr it (this->start1->end() , this->start2->begin());
			it.replaced=true;
			it.start=this->start2->end();
			return it;
		}
	};
}