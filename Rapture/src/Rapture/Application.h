#pragma once

#include "Core.h"
#include "Rapture\Window.h"

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
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnKeyPressed(KeyPressedEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	//To be defined in a client
	Application* CreateApplication();
}