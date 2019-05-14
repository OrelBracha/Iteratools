#pragma once
namespace itertools{
struct EmptyIterable {
			int* begin() const { return nullptr; }
			int* end() const { return nullptr; }
		};

<<<<<<< HEAD
template<typename T1> 
EmptyIterable powerset(T1 a) { return EmptyIterable{}; }
=======
	template<typename T1> class powerset {
		private:
			T1 first;
			//T2 second;
	
		public:
			
 	powerset<T1>(const T1 t1): first(t1) {}
       // powerset<T1,T2>(const T1 t1, const T2 t2) : first(t1) , second(t2) {}
			
				class iterator {

				};
		iterator begin() {
			return NULL;
		}
			
		iterator end() {
			return NULL;
		}
	};
>>>>>>> 089af2e75adf8eced852c16e5785e4d70f39708a
}
