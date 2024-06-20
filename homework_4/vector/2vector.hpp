#include <iostream>
#include <cstdlib>

template <typename T, typename Allocator = std::allocator<T>>
class Vector
{
public:
	Vector() noexcept
		: _allocator(Allocator()), _size(0), _capacity(0), _data(nullptr) {}

	explicit Vector(const Allocator &alloc) noexcept
		: _allocator(alloc), _size(0), _capacity(0), _data(nullptr) {}

	explicit vector(size_type count, const T &value = T(), const Allocator &alloc = Allocator())
		: _allocator(alloc)
	{
		_start = _allocator.allocate(count);
		_end = _start;
		_end_of_capacity = _start + count;
		for (size_type i = 0; i < count; ++i)
		{
			_allocator.construct(_end++, value);
		}
	}

	// for standard allocators
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
			_allocator.deallocate(_data, _capacity);

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

private:
	Allocator _allocator;
	size_type _size;
	size_type _capacity;
	pointer _data;
};