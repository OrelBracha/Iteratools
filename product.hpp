#pragma once
namespace itertools
{

	template<typename T1, typename T2> class product {
		private:
			T1 first;
			T2 second;
	
		public:
			product<T1,T2>(const T1 t1, const T2 t2) : first(t1) , second(t2) {}
			
				class iterator {
private:
				typename T1::iterator it1Begin;
				typename T1::iterator it2End;
				typename T2::iterator sStart;
				typename T2::iterator it2Begin;
				typename T2::iterator sEnd;

			public:
				iterator(typename T1::iterator tIt, typename T1::iterator tIit2End, typename T2::iterator sIt, typename T2::iterator sIit2End):
					it1Begin(tIt), it2End(tIit2End),
					sStart(sIt), it2Begin(sIt), sEnd(sIit2End)
				 { }

				auto operator*() const {
					ostringstream stream;
					stream<<*it1Begin<<","<<*it2Begin;
					return stream.str();
				}

				iterator& operator++() {
					++it2Begin;
					if (it2Begin == sEnd){
						++it1Begin;
						if (it1Begin != it2End)
							it2Begin = sStart;
					}	
					return *this;
				}

				const iterator operator++(int) {
					iterator It(*this);
					operator++();
					return It;
				}

				bool operator==(const iterator& other) const {
					if (it1Begin == other.it1Begin)
						if(it2Begin == other.it2Begin)
							return true;
					return false;
				}

				bool operator!=(const iterator& other) const {
					if(*this==other)
						return false;
					return true;
				}
		};
		
		typename product<T1,T2>::iterator begin() {
			return product<T1,T2>::iterator(first.begin(), first.end(),second.begin(),second.end());
		}
			
		typename product<T1,T2>::iterator end() {
			return product<T1,T2>::iterator(first.end(), first.end(),second.end(),second.end());
		}

	}; 

}
