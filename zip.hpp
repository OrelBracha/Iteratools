#pragma once
namespace itertools{

	template<typename T1, typename T2> class zip {
		private:
			T1 first;
			T2 second;
	
		public:
			zip<T1,T2>(const T1 t1, const T2 t2) : first(t1) , second(t2) {}
			
				class iterator {
	typename T1::iterator it1Begin;
				typename T1::iterator it1End;
				typename T2::iterator it2Begin;
				typename T2::iterator it2End;

			public:
				iterator(typename T1::iterator iter1Begin, typename T1::iterator iter1End, typename T2::iterator iter2Begin, typename T2::iterator iter2End):
					it1Begin(iter1Begin), it1End(iter1End),
					it2Begin(iter2Begin), it2End(iter2End)
				 { }

				auto operator*() const {
					ostringstream stream;
					stream<<*it1Begin<<","<<*it2Begin;
					return stream.str();
				}

				iterator& operator++() {
					++it1Begin;
					++it2Begin;
					return *this;
				}

				const iterator operator++(int) {
					iterator It(*this);
					operator++();
					return It;
				}

				bool operator==(const iterator& other) const {
					if(it1Begin == other.it1Begin)
						if(it2Begin == other.it2Begin)
							return  true;
					return false;
				}
				

				bool operator!=(const iterator& rhs) const {
					if(*this==rhs)
						return false;
					return true;
				}

		}; 
		
		typename zip<T1,T2>::iterator begin() {
			return zip<T1,T2>::iterator(first.begin(), first.end(), second.begin(), second.end());
		}
			
		typename zip<T1,T2>::iterator end() {
			return zip<T1,T2>::iterator(first.end(), first.end(), second.end(), second.end());
		}

	}; 

}
