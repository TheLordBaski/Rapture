#include "Application.h"

#include "Rapture/Events/ApplicationEvent.h"
#include "Rapture/Log.h"

namespace Rapture {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			RP_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			RP_TRACE(e);
		}

		while (true);
	}
}