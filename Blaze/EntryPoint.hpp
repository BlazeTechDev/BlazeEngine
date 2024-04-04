#pragma once

#ifdef BLZ_PLATFORM_WINDOWS

extern Blaze::Application* Blaze::CreateApplication();

int main(int argc, char** argv)
{
	Blaze::Log::Init();
	Blaze::Log::GetCoreLogger()->warn("Initiated Core Log!");
	Blaze::Log::GetClientLogger()->info("Initiated Client Log!");

	auto app = Blaze::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif