#include <iostream>
#include <string>
#include <bits/stdc++.h> 

using namespace std;

namespace itertools{
	
	template <typename V>
	string toString (const vector<V> &v) {
		string result="{";
		bool appended=false;
		for (auto i: v){
			result.append(toString(*i));
			result.append(",");
			appended=true;
		}
		
		if(appended){
			result=result.substr(0, result.size()-1);
		}
		result.append("}");
		return result;
	}
	
	template <typename V>
	ostream& operator<< (ostream& os, const vector<V> &v){
		os<<toString(v);
		return os;
	}
	
	
	template<typename T>
	class powerset{
		
		private:
		T container;
		
		public:
		
		class const_iterator {
			
			private:
			typename T::const_iterator current;
			typename T::const_iterator start;
			typename T::const_iterator stop;
			vector<typename T::const_iterator> subset;
			int binary_counter=0;
			
			
			public:
			
			const_iterator(const typename T::const_iterator& begin, const typename T::const_iterator& end):
				current(begin), start(begin), stop(end) {}
			
			
			
			bool operator==(const const_iterator& o) const {
				return (current==o.current&& pow(2, subset.size())<=binary_counter);
			}
			
			bool  operator!=(const const_iterator& o) const {
				return !(current==o.current&& pow(2, subset.size())<=binary_counter);
			}
			
			const_iterator&  operator++() {
				++(binary_counter);
				if(pow(2, subset.size()) == binary_counter && current != stop){
					subset.insert(subset.end(), current);
					++(current);
				}
				return *this;
			}
			/**
			const_iterator& operator++(int){
				cout<<"inside++"<<endl;
				const_iterator t= *this;
				(binary_counter)++;
				//cout<<"counter="<<binary_counter<<" subset.size="<<subset.size()<<endl;
				if(pow(2,subset.size())==binary_counter || subset.size()==0){
					(current)++;
					subset.insert(subset.end(), current);
					//cout<<"subset inserted"<<endl;
				}
				return t;
			}
			**/
			auto operator*() const {
				vector<typename T::const_iterator> result;
				bitset<6> bset(binary_counter);
				int i=0;
				
				while (!bset.none()){
					if(bset[i]==1){
						result.insert(result.end(), subset.at(i));
						bset.set(i,0);
					}
					++i;
				}
				return result;
			}
		};
		
		
		
		powerset(const T c): container(c){ }
		
		const_iterator begin() const{
			return powerset::const_iterator(container.begin(), container.end());
		}
		
		const_iterator end() const{
			return powerset::const_iterator(container.end(), container.end());
		}
		
	};
	
	
}