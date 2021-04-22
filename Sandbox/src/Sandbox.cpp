#include <Rapture.h>

class Sandbox : public Rapture::Application
{
public: 
	Sandbox()
	{

	}

	~Sandbox() {

	}
};

Rapture::Application* Rapture::CreateApplication() {
	return new Sandbox();
}