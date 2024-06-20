#ifndef VEC_HPP
# define VEC_HPP

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stdexcept>


template <typename T, typename Allocator = std::allocator<T>>
class Vector
{
public:
	Vector() noexcept
		: _allocator(Allocator()), _size(0), _capacity(0), _data(nullptr) {}

	explicit Vector(const Allocator &alloc) noexcept
		: _allocator(alloc), _size(0), _capacity(0), _data(nullptr) {}

	explicit Vector(std::size_t count, const T &value = T(), const Allocator &alloc = Allocator())
		: _allocator(alloc), _size(count), _capacity(count)
	{
		_data = _allocator.allocate(_capacity);
		std::uninitialized_fill_n(_data, _size, value);
	}

	// CC for standard allocators
	Vector(const Vector &other)
		: _allocator(other._allocator), _size(other._size), _capacity(other._capacity)
	{
		_data = _allocator.allocate(_capacity);
		std::uninitialized_copy(other._data, other._data + _size, _data);
	}

	// for all types of allocators copies the specific allocator that other has, if it has custom implementation, it is being called
	// std::allocator_traits is a template class
	// initializes the _allocator of the new Vector by calling ***select_on_container_copy_construction*** with the allocator of the other vector.

	// Vector(const Vector &other)
	// 	: _allocator(std::allocator_traits<Allocator>::select_on_container_copy_construction(other._allocator)),
	// 	  _size(other._size), _capacity(other._capacity)
	// {
	// 	_data = _allocate(_capacity);
	// 	std::uninitialized_copy(other._data, other._data + _size, _data);
	// }

	// Move constructor
	Vector(Vector &&other) noexcept
		: _allocator(std::move(other._allocator)), _size(other._size), _capacity(other._capacity), _data(other._data)
	{
		other._size = 0;
		other._capacity = 0;
		other._data = nullptr;
	}

	// Destructor
	~Vector()
	{
		_clear();
		_allocator.deallocate(_data, _capacity);
	}

	Vector &operator=(const Vector &other)
	{
		if (this != &other)
		{
			_clear();
			_allocator.deallocate(_data, _capacity);

			_allocator = other._allocator;
			_size = other._size;
			_capacity = other._capacity;
			_data = _allocator.allocate(_capacity);
			std::uninitialized_copy(other._data, other._data + _size, _data);
		}
		return *this;
	}

	Vector &operator=(Vector &&other) noexcept
	{
		if (this != &other)
		{
			_clear();
			_deallocate(_data, _capacity);

			_allocator = std::move(other._allocator);
			_size = other._size;
			_capacity = other._capacity;
			_data = other._data;

			other._size = 0;
			other._capacity = 0;
			other._data = nullptr;
		}
		return *this;
	}

	// Operators for accessing vector's elements, for const-correctness I wrote 2 versions
	T &operator[](std::size_t pos)
	{
		return _data[pos];
	}
	const T &operator[](std::size_t pos) const
	{
		return _data[pos];
	}

	// to get the value of the current position pos
	T &at(std::size_t pos)
	{
		if (pos >= _size)
			throw std::out_of_range("Vector::at throws out of range");
		return _data[pos];
	}
	const T &at(std::size_t pos) const
	{
		if (pos >= _size)
			throw std::out_of_range("Vector::at that returns const ref throws out of range");
		return _data[pos];
	}

	// to get the first value
	T &front()
	{
		return _data[0];
	}
	const T &front() const
	{
		return _data[0];
	}

	// last one
	T &back()
	{
		return _data[_size - 1];
	}
	const T &back() const
	{
		return _data[_size - 1];
	}

	// Iterators
	T *begin() noexcept
	{
		return _data;
	}
	const T *begin() const noexcept
	{
		return _data;
	}
	T *end() noexcept
	{
		return _data + _size;
	}
	const T *end() const noexcept
	{
		return _data + _size;
	}

	// Capacity, size getters
	bool empty() const noexcept
	{
		return _size == 0;
	}
	std::size_t size() const noexcept
	{
		return _size;
	}
	std::size_t capacity() const noexcept
	{
		return _capacity;
	}

	void reserve(std::size_t new_cap)
	{
		if (new_cap > _capacity)
		{
			T *new_data = _allocate(new_cap);
			std::uninitialized_move(_data, _data + _size, new_data);
			_clear();
			_deallocate(_data, _capacity);
			_data = new_data;
			_capacity = new_cap;
		}
	}
	void resize(std::size_t count, T value = T())
	{
		if (count > _size)
		{
			reserve(count);
			std::uninitialized_fill_n(_data + _size, count - _size, value);
		}
		else
		{
			std::destroy(_data + count, _data + _size);
		}
		_size = count;
	}

	void push_back(const T &value)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 1 : 2 * _capacity);
		}
		std::allocator_traits<Allocator>::construct(_allocator, _data + _size, value);
		++_size;
	}
	void pop_back()
	{
		if (_size > 0)
		{
			--_size;
			std::allocator_traits<Allocator>::destroy(_allocator, _data + _size);
		}
	}
	void clear() noexcept
	{
		_clear();
	}

private:
	Allocator _allocator;
	std::size_t _size;
	std::size_t _capacity;
	T *_data;

	T *_allocate(std::size_t n)
	{
		return n != 0 ? std::allocator_traits<Allocator>::allocate(_allocator, n) : nullptr;
	}

	void _deallocate(T *p, std::size_t n)
	{
		if (p != nullptr)
		{
			std::allocator_traits<Allocator>::deallocate(_allocator, p, n);
		}
	}

	void _clear()
	{
		if (_data != nullptr)
		{
			std::destroy(_data, _data + _size);
			_size = 0;
		}
	}
};


#endif