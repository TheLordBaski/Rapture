#pragma once

#ifdef  RP_PLATFORM_WINDOWS

extern Rapture::Application* Rapture::CreateApplication();

int main(int argc, char** argv) {
	auto app = Rapture::CreateApplication();
	app->Run();
	delete app;
}

#endif //  RP_PLATFORM_WINDOWS
