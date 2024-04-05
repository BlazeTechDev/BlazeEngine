#pragma once

#ifdef BLZ_PLATFORM_WINDOWS

extern Blaze::Application* Blaze::CreateApplication();

int main(int argc, char** argv)
{
	Blaze::Log::Init();
	BLZ_CORE_INFO("initialized core logger");
	BLZ_CLIENT_INFO("initialized client logger");

	auto app = Blaze::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif