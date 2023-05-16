// vector analogue

#pragma once

#include <iostream>

namespace jinx
{
	// ------------------------------------------------------------------ EXCEPTIONS

	class ArrayIndexOutOfBounds : public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			return "\n > ОШИБКА: индекс элемента за пределами массива!";
		}
	};

	class ArrayIsNullPtr : public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			return "\n > ОШИБКА: массив не существует!";
		}
	};

	class ArraySizeInvalid : public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			return "\n > ОШИБКА: неверный размер массива!";
		}
	};

	// ------------------------------------------------------------------ VECTOR CLASS

	template<class T>
	class vector final
	{
	public:
		// PUBLUC AREA

/*
at(int index) — доступ к элементу контейнера по индексу;
push_back(T value) — размер контейнера неизвестен заранее, вам нужно правильно увеличивать выделенную память;
size () — количество элементов в контейнере;
capacity() — количество элементов, которое может вместить контейнер до нового выделения памяти.
*/

		// public methods

		/*
		Возвращает i-ый элемент вектора если он существует
		Возвращает исключение если элемент за пределами диапазона
		*/
		T & at(const int & index)
		{
			if (index >= 0 && index < _size)
				return _array[index];
			else
				jinx::ArrayIndexOutOfBounds();
		}

		/*
		Вставляет элемент в конец вектора и расширяет память если необходимо
		*/
		void push_back(const T & value)
		{

			if (_size == _capacity)
			{
				T * _tmp = new T[_capacity];

				for (int i = 0; i < _size; ++i)
				{
					_tmp[i] = _array[i];
				}

				delete [] _array;

				// Количество докидываемых элементов

				if (_capacity < 50)
				{
					_capacity *= 2;
				}
				if (_capacity >= 50 && _capacity < 100)
				{
					_capacity += 10;
				}
				if (_capacity >= 100)
				{
					_capacity += (_capacity / 100 * 20); // +20% past 100 elements
				}

				_array = new T[_capacity];

				for (int i = 0; i < _size; ++i)
				{
					_array[i] = _tmp[i];
				}

				delete[] _tmp;
				_tmp = nullptr;
			}

			_array[_size] = value;
			_size += 1;
		}

		/*
			Возвращает логический размер массива
		*/
		int size()
		{
			return _size;
		}

		/*
			Возвращает фактический размер массива
		*/
		int capacity()
		{
			return _capacity;
		}

		/*
		Обрезает выделенную память до размера фактически занятой памяти
		*/
		void shrink_to_fit()
		{
			if (_size < _capacity)
			{
				T* _tmp = new T[_capacity];

				for (int i = 0; i < _size; ++i)
				{
					_tmp[i] = _array[i];
				}

				delete[] _array;

				_capacity = _size;

				_array = new T[_capacity];

				for (int i = 0; i < _size; ++i)
				{
					_array[i] = _tmp[i];
				}

				delete[] _tmp;
				_tmp = nullptr;
			}
		}

		// iterators

		class iterator
		{
		public:
			iterator(T* ptr) : ptr(ptr) {}
			iterator operator++() { ++ptr; return *this; }
			bool operator!=(const iterator& other) const { return ptr != other.ptr; }
			const T& operator*() const { return *ptr; }
		private:
			T * ptr;
		};

		iterator begin() const { return iterator(_array); }
		iterator end() const { return iterator(_array + _size); }

		// overloads

		const T& operator [] (int index) const
		{
			if (index >= 0 && index < _size)
				return _array[index];
		}

		T& operator [] (int index)
		{
			if (index >= 0 && index < _size)
				return _array[index];
		}

		vector & operator=(vector & other_arr)
		{
			if (this != &other_arr)
			{

				if (this->size() < other_arr.size())
				{
					delete[] this->_array;
					this->_capacity = other_arr._capacity;
					this->_size = other_arr._size;
					_array = new T[_capacity] {0};

					for (int i = 0; i < _size; ++i)
					{
						this->_array[i] = other_arr[i];
					}
				}
				else if (this->size() > other_arr.size())
				{
					for (int i = 0; i < other_arr.size(); ++i)
					{
						this->_array[i] = other_arr[i];
					}
				}

			} // END OF if this != &other_arr

			return *this;
		}

		// constructors

		vector() = delete;

		/*
		vector(int size) вызов конструктора
		Необходимо передать значение size > 0
		*/
		vector(int size)
		{

			if (size > 0)
			{

				_size = 0;
				_capacity = size;
				_array = new T[_capacity];

			}
			else
			{
				throw jinx::ArraySizeInvalid();
			}
		}

		// destructor

		~vector()
		{			
			delete[] _array;
			_size = -1;
			_capacity = -1;
			_array = nullptr;
		}

	protected:
		// PROTECTED AREA

	private:
		// PRIVATE AREA
		
		T *	_array = nullptr;
		int _size = -1;
		int _capacity = -1;

	}; // END OF class vector

} // END OF jinx NAMESPACE