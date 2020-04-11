#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <assert.h>
#include <memory>

namespace numeth {

	template<typename T>
	class vector {

	public:

		vector(const int& size) {
			assert(size >= 0);
			this->size = size;
			this->data = std::make_unique <T[]>(size);
		}

		~vector() {
			this->data.reset();
		}

		vector<T>& operator=(const vector<T>& rhs) {
			size = rhs.getSize();
			this->data = std::make_unique <T[]>(rhs.getSize());

			copy(rhs);

			return *this;
		}

		vector(const vector<T>& source) {
			size = source.getSize();
			data = make_unique<T[]>(size);

			copy(source);
		}

		void copy(const vector<T>& source) {
			for (int i = 0; i < size; i++) {
				data.get()[i] = source.data.get()[i];
			}

			return;
		}

		int getSize() const {
			return this->size;
		}

		T at(const int& index) const {
			return this->data[index]
		}

		T& at(const int& index) {
			return this->data[index];
		}

		void clear() {
			this->data.reset();
			this->data = std::make_unique<T[]>(this->size);
		}

		T& operator[](int index) {
			return data.get()[index];
		}

		T operator[](int index) const {
			return data.get()[index];
		}

	private:
		std::unique_ptr<T[]> data;
		int size;
	};
}

#endif