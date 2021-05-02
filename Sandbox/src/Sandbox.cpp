#include <Rapture.h>


class ExampleLayer : public Rapture::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		RP_INFO("ExampleLayer::Update");
	}

	void OnEvent(Rapture::Event& event) override
	{
		RP_TRACE("{0}", event);
	}

};

class Sandbox : public Rapture::Application
{
public: 
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

Rapture::Application* Rapture::CreateApplication() {
	return new Sandbox();
}