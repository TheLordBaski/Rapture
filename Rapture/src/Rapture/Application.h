#pragma once

#include "Core.h"
#include "Rapture\Window.h"

#include "Rapture/LayerStack.h"
#include "Events/Event.h"
#include "Rapture/Events/ApplicationEvent.h"
#include "Rapture/Events/KeyEvent.h"

namespace Rapture {

	class RAPTURE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnKeyPressed(KeyPressedEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};
	//To be defined in a client
	Application* CreateApplication();
}