#pragma once
#ifdef BLCKR_PLATFORM_WINDOWS

extern Blocker::Application* Blocker::CreateApplication();

int main(int argc, char** argv)
{
	Blocker::Log::Init();
	BLCKR_CORE_WARN("STARTED");

	int a = 6;
	BLCKR_INFO("Var a = {0}", a);

	auto app = Blocker::CreateApplication();
	app->Run();
	delete app;
}

#endif
