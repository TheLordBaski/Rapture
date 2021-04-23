#pragma once

#ifdef  RP_PLATFORM_WINDOWS

extern Rapture::Application* Rapture::CreateApplication();

int main(int argc, char** argv) {
	Rapture::Log::Init();
	RP_CORE_WARN("Rapture initilized");
	int a = 10;
	RP_INFO("Rapturator started {0}", a)

	auto app = Rapture::CreateApplication();
	app->Run();
	delete app;
}

#endif //  RP_PLATFORM_WINDOWS
