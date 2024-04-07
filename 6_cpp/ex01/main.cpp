#include "Serializer.hpp"

#define LOG(x) std::cout << x << std::endl

// class Z
// {
// private:
// 	int	z;
// public:
// 	Z(int);
// 	~Z();
// 	int	getZ(){
// 		return (z);
// 	}
// };

// Z::Z(int a): z(a)
// {
// }

// Z::~Z()
// {
// }


int	main()
{
	Data	data;

	data.c = 'A';
	data.x = 42;

	// Serializer a;
	LOG(data.x);
	LOG((*(Serializer::deserialize(Serializer::serialize(&data)))).x);
	// Z a(129291);
	// LOG(a.getZ());
	// data.ptr = &a;
	// LOG(((Z)(*(Z*)(Serializer::deserialize(Serializer::serialize(&data))->ptr))).getZ());
}