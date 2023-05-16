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
			return "\n > ������: ������ �������� �� ��������� �������!";
		}
	};

	class ArrayIsNullPtr : public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			return "\n > ������: ������ �� ����������!";
		}
	};

	class ArraySizeInvalid : public std::exception
	{
	public:
		const char* what() const noexcept override
		{
			return "\n > ������: �������� ������ �������!";
		}
	};

	// ------------------------------------------------------------------ VECTOR CLASS

	template<class T>
	class vector final
	{
	public:
		// PUBLUC AREA

/*
at(int index) � ������ � �������� ���������� �� �������;
push_back(T value) � ������ ���������� ���������� �������, ��� ����� ��������� ����������� ���������� ������;
size () � ���������� ��������� � ����������;
capacity() � ���������� ���������, ������� ����� �������� ��������� �� ������ ��������� ������.
*/

		// public methods

		/*
		���������� i-�� ������� ������� ���� �� ����������
		���������� ���������� ���� ������� �� ��������� ���������
		*/
		T & at(const int & index)
		{
			if (index >= 0 && index < _size)
				return _array[index];
			else
				jinx::ArrayIndexOutOfBounds();
		}

		/*
		��������� ������� � ����� ������� � ��������� ������ ���� ����������
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

				// ���������� ������������ ���������

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
			���������� ���������� ������ �������
		*/
		int size()
		{
			return _size;
		}

		/*
			���������� ����������� ������ �������
		*/
		int capacity()
		{
			return _capacity;
		}

		/*
		�������� ���������� ������ �� ������� ���������� ������� ������
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
		vector(int size) ����� ������������
		���������� �������� �������� size > 0
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