#include <Blaze.hpp>

class Editor : public Blaze::Application
{
public:
	Editor()
	{

	}

	~Editor()
	{

	}
};

Blaze::Application* Blaze::CreateApplication()
{
	return new Editor();
}