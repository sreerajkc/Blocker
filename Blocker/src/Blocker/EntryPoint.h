#pragma once
#ifdef BLCKR_PLATFORM_WINDOWS

extern Blocker::Application* Blocker::CreateApplication();

int main(int argc, char** argv)
{
	Blocker::Log::Init();
	BLCKR_CORE_INFO("STARTED");

	int a = 5;
	BLCKR_INFO("Var a = {0}", a);

	auto app = Blocker::CreateApplication();
	app->Run();
	delete app;
}

#endif
