#pragma once
#import "range.hpp"

namespace itertools
{
	
	template<typename T1, typename T2>
	class chain
{

	private:
		T1 first;
		T2 second;
		
	public:
		chain<T1,T2>( T1 iter1,  T2 iter2)
			: first(iter1),
			second(iter2) {}

		class iterator {

			private:
				typename T1::iterator it1Begin;
				typename T1::iterator it1End;
				typename T2::iterator it2Begin;
<<<<<<< HEAD
				typename T2::iterator it2End;

			public: 
				 iterator(typename T1::iterator iter1Begin, typename T1::iterator iter1End, typename T2::iterator iter2Begin, typename T2::iterator iter2End):
					it1Begin(iter1Begin), it1End(iter1End),
					it2Begin(iter2Begin),it2End(iter2End) { }
=======
                                typename T2::iterator it2End;


			public: 
				 iterator(typename T1::iterator iter1Begin, typename T1::iterator iter1End, typename T2::iterator iter2Begin,typename T2::iterator iter2End ):
					it1Begin(iter1Begin), it1End(iter1End),

					it2Begin(iter2Begin), it2End(iter2End) { }
>>>>>>> 089af2e75adf8eced852c16e5785e4d70f39708a

				auto operator*() const {
					if (it1Begin != it1End)
						return *it1Begin;
					else return *it2Begin;
				}

				iterator& operator++(){
					if(it1Begin != it1End)
						++it1Begin;
					else
						++it2Begin;
					return *this;	
				}

				const iterator operator++(int){
					iterator It(*this);
					operator++();
					return It;
				}

				bool operator==(const iterator& other) const {
					if(it1Begin == other.it1Begin) 
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
<<<<<<< HEAD
		
		typename chain<T1,T2>::iterator begin() {
			return chain<T1,T2>::iterator(first.begin(), first.end(), second.begin(), second.end());
		}
			
		typename chain<T1,T2>::iterator end() {
			return chain<T1,T2>::iterator(first.end(), first.end(), second.end(), second.end());
=======




            typename chain<T1,T2>::  iterator begin() {
			return chain<T1,T2>::iterator( first.begin(), first.end(), second.begin());
		}
			
		typename chain<T1,T2>::  iterator end() {
			return chain<T1,T2>::iterator(first.end(), first.end(), second.end());
>>>>>>> 089af2e75adf8eced852c16e5785e4d70f39708a
		}

	};

<<<<<<< HEAD
=======

>>>>>>> 089af2e75adf8eced852c16e5785e4d70f39708a
}
