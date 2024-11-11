#include <Blocker.h>

class Sandbox : public Blocker::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
private:

};

Blocker::Application* Blocker::CreateApplication()
{
	return new Sandbox();
}
