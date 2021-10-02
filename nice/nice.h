#ifndef NICE_H

#include <memory>

namespace nice
{
	class Nice
	{
	private:
		int counter = 0;
		std::unique_ptr<Nice> other;

	public:
		Nice(int c);
		~Nice();

		void sayHello();
	};
}

#endif // !NICE_H